//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Progress.h"
#include "MatrixFunctions.h"
#include "DArrayTypes.h"
#include "Sets.h"
#include "Maps.h"
#include "MatrixFunctions.h"
#include "Classification.h"
//---------------------------------------------------------------------------
// alpha - см. isUnion(...)
// betta - см. UnionPoints(...)
// gamma - см. этап 6 в Classification(...)
// delta - см. выбор классов на этапе 2+3 в Classification(...)
// phi   - см. этап 8 в Classification(...)
// theta - см. Assim(...)
double alpha = 1.3, betta = 1, gamma = 0.2, delta = 1.1, phi = 0.5,
       theta = 1.75, psi = 1.5, c_alpha = 2;
//---------------------------------------------------------------------------
// ќбозначени€ массивов в параметрах функций:
// A  - исходна€ матрица NxMxd
// R  - матрица взаимных рассто€ний NxNxd
// R1 - массив расто€ний до первого соседа Nxd
// S  - матрица номеров ближайших соседей Nxkxd
// C  - массив значений центристостей Nxd
// K  - множество номеров точек класса (текущего)
// IK - индекс покрытости (скольким классам принадлежит)
// M1, M2 - множества согласно алгоритма
//---------------------------------------------------------------------------
T2DoubleArray GetSubArray(T2DoubleArray &A, TIntSet &I);
void CalcCentrist(T2DoubleArray &R, T2IntArray &S, TDoubleArray &C, TDoubleArray &R1, int k);
void MakeM1M2(TDoubleArray &C, TDoubleArray &R1, TIntSet &M1, TIntSet &M2);
void MakeCj(TDoubleArray &C, T2IntArray &S, TIntSet &K, TIntSet &M1, TIntSet &M2, int k, int j);
double Assim(T2DoubleArray &A, TIntSet &K, int count_vars = -1);
double Intersect(TIntSet &K1, TIntSet &K2);
void Prosein(T2DoubleArray &A, TIntSet &K, TIntArray &IK, TIntSet &Mdel, int count_vars = -1);
bool isUnion(T2DoubleArray &A, TIntSet &K1, TIntSet &K2, int count_vars = -1);
void UnionPoints(T2DoubleArray &A, TintIntSetMap &Classes, TIntArray &IK, TIntSet &M, int count_vars = -1);
void CalcClassCenter(T2DoubleArray &A, TIntSet &K, TDoubleArray &m, int count_vars = -1);
void CalcClassesCenters(T2DoubleArray &A, TintIntSetMap &Classes, T2DoubleArray &Centers, int count_vars = -1);
//---------------------------------------------------------------------------
double metrica(TDoubleArray &X, TDoubleArray &Y, bool isMayBeNull)
{
  int i, N = min(X.Length, Y.Length);
  double max = -1, s = 0;

  for (i = 0; i < N; i++) {
    s += fabs(X[i] - Y[i]);
    if (fabs(X[i] - Y[i]) > max) max = fabs(X[i] - Y[i]);
  }
//  s = sqrt(s);

  if (!isMayBeNull && s * max == 0)
    return MAXDOUBLE;
  else
    return s * max;
}
//---------------------------------------------------------------------------
T2DoubleArray GetSubArray(T2DoubleArray &A, TIntSet &I)
{
  T2DoubleArray SubA;
  TIntSetIterator p;
  int i, j, NVars;

  SubA.Length = 0;
  if (I.size() == 0 || A.Length == 0) return SubA;

  NVars = A[0].Length;

  SubA.Length = I.size();
  for(j = 0; j < SubA.Length; j++)
    SubA[j].Length = NVars;

  for(i = 0, p = I.begin(); p != I.end(); i++, p++)
    for(j = 0; j < NVars; j++)
      SubA[i][j] = A[*p][j];

  return SubA;
}
//---------------------------------------------------------------------------
void CalcCentrist(T2DoubleArray &R, T2IntArray &S, TDoubleArray &C, TDoubleArray &R1, int k)
{
  TDoubleArray tR, tI;
  int i, j, t, N = R.Length;

// «аполн€ем матрицу k ближайших соседей
// и рассчитываем центристости
  S.Length  = N;
  C.Length  = N;
  R1.Length = N;
  VectorSet(C, 0);
  for (i = 0; i < N; i++) {
    tR = R[i].Copy();
    tI.Length = N;
    for (j = 0; j < N; j++) tI[j] = j;
    VectorDualSort(tR, tI, SORT_ASCENDING);
    S[i].Length = k;
    for (j = 0; j < k; j++) {
      S[i][j] = tI[j];
      C[tI[j]] += k - j;
    }
    R1[i] = tR[0];
  }
}
//---------------------------------------------------------------------------
void CalcDistances(T2DoubleArray &A, T2DoubleArray &R, int count_vars)
{
  TDoubleArray X, Y;
  int i, j, c = count_vars, N = A.Length;

  if (c == -1) c = A[0].Length;

  R.Length = N;
  for (i = 0; i < N; i++)
    R[i].Length = N;
  for (i = 0; i < N; i++) {
    R[i][i] = MAXDOUBLE;
    X = A[i];
    X.Length = c;
    for (j = i + 1; j < N; j++) {
      Y = A[j];
      Y.Length = c;
      R[i][j] = metrica(X, Y);
      R[j][i] = R[i][j];
    }
  }
}
//---------------------------------------------------------------------------
void MakeM1M2(TDoubleArray &C, TDoubleArray &R1, TIntSet &M1, TIntSet &M2)
{
  TdoubleIntMap LC;
  TdoubleIntMapIterator ILC;
  TIntSet MC1, MC2, MR1, MR2;
  TDoubleArray IC, IR1, RC, RR1, tC, ttC, tR1 = R1.Copy(), tRR1;
  int i, j, c, i1, i2, j1, j2, N = C.Length;
  double max1, max2;

  M1.clear();
  M2.clear();
  MC1.clear();
  MC2.clear();
  MR1.clear();
  MR2.clear();

  IR1.Length = N;
  for (i = 0; i < N; i++) IR1[i] = i;

  for (i = 0; i < N; i++)
    LC[C[i]]++;
  WriteMap(LC, "out\\LC.txt");

  ILC = LC.end();
  ILC--;
  tC.Length = (*ILC).first + 1;
  for (i = 0; i < tC.Length; i++)
    tC[i] = LC[i];
  VectorSort(tC, SORT_ASCENDING);

  ttC.Length = tC.Length;
  VectorSet(ttC, 0);
  for (i = 4; i < tC.Length - 4; i++)
    ttC[i] = (tC[i + 3] + tC[i + 2] + tC[i + 1] + tC[i]) /
             (tC[i - 4] + tC[i - 3] + tC[i - 2] + tC[i - 1] + 1);
  WriteArray(ttC, "out\\ttC.txt");
  for(i2 = 0; i2 < ttC.Length - 1; i2++)
    if (ttC[i2] > ttC[i2 + 1]) break;
  for(i1 = i2; i1 < ttC.Length - 1; i1++)
    if (ttC[i1] < ttC[i1 + 1]) break;
  for(;i1 < ttC.Length - 1; i1++)
    if (ttC[i1] > ttC[i1 + 1]) break;

  for (i = 0; i < N; i++)
    if (C[i] <= i2 / c_alpha) MC2.insert(i);
    else if (C[i] <= i1 / c_alpha) MC1.insert(i);
  WriteSet(MC1, "out\\MC1.txt");
  WriteSet(MC2, "out\\MC2.txt");

  VectorDualSort(tR1, IR1, SORT_DESCENDING);
  RR1.Length = N;
  VectorSet(RR1, 0);
  for (i = 4; i < N - 4; i++)
    RR1[i] = 1 / ((tR1[i + 3] + tR1[i + 2] + tR1[i + 1] + tR1[i]) /
                  (tR1[i - 4] + tR1[i - 3] + tR1[i - 2] + tR1[i - 1]));

  tRR1 = RR1.Copy();
  VectorSort(tRR1, SORT_ASCENDING);
  max1 = tRR1[tRR1.Length * 0.90];
  max2 = tRR1[tRR1.Length * 0.95];
  for (i1 = RR1.Length * 0.4; i1 >= 10; i1--) {
    for (c = j = 0; j < 10; j++)
      if (RR1[i1 - j] >= max1) c++;
    if (c >= 5) break;
  }

  for (i2 = i1; i2 >= 10; i2--) {
    for (c = j = 0; j < 10; j++)
      if (RR1[i2 - j] >= max2) c++;
    if (c >= 5) break;
  }

  for (i = 0; i < i2; i++)
    MR1.insert(IR1[i]);
  for (i = i2; i < i1; i++)
    MR2.insert(IR1[i]);
  WriteSet(MR1, "out\\MR1.txt");
  WriteSet(MR2, "out\\MR2.txt");

  union(MR1, MC1, M1);
  union(MR2, MC2, M2);
  M1 = M1 - M2;
}
//---------------------------------------------------------------------------
void MakeCj(TDoubleArray &C, T2IntArray &S, TIntSet &K, TIntSet &M1, TIntSet &M2, int k, int j)
{
  TIntSet r, t, Knew, M = M1 + M2;
  TIntSetIterator p;
  int i, c, porog = k / 2 + (k != 2);

  r.clear();
  r.insert(j);
  for (i = 0; i < k; i++)
    r.insert(S[j][i]);
  r = r - M;

  Knew = r;
  while (true) {
    t.clear();
    for (p = Knew.begin(); p != Knew.end(); p++) {
      for (c = 0, i = 0; i < k; i++)
        if (r.count(S[*p][i])) c++;
      if (c >= porog)
        for (i = 0; i < k; i++)
          t.insert(S[*p][i]);
    }
    WriteSet(t, "out\\t.txt");
    WriteSet(r, "out\\r_1.txt");
    difference(t, r, Knew);
    Knew = Knew - M;
    WriteSet(Knew, "out\\Knew.txt");
    if (Knew.size() == 0) break;
    union(r, Knew, r);
    WriteSet(r, "out\\r_2.txt");
  }

  K = r;
}
//---------------------------------------------------------------------------
double Assim(T2DoubleArray &A, TIntSet &K, int count_vars)
{
  TDoubleArray X, m, tR;
  TIntSetIterator p;
  double r_m, r_s;
  int i, j;
  int c = count_vars, M = K.size();

  if (c == -1) c = A[0].Length;

  m.Length = c;
  VectorSet(m, 0);
  for (p = K.begin(); p != K.end(); p++)
    for (i = 0; i < c; i++)
      m[i] += A[*p][i];
  for (i = 0; i < c; i++)
    m[i] /= M;

  tR.Length = M;
  for (i = 0, p = K.begin(); p != K.end(); i++, p++)
    tR[i] = metrica(m, A[*p]);

  for (r_m = i = 0; i < M; i++)
    r_m += tR[i];
  r_m /= M;

  for (r_s = i = 0; i < M; i++)
    r_s += (tR[i] - r_m) * (tR[i] - r_m);
  r_s = sqrt(r_s / (M - 1));

  for (j = i = 0; i < M; i++)
    if (tR[i] >= r_m + theta * r_s) j++;

  return double(j) / M;
}
//---------------------------------------------------------------------------
double Intersect(TIntSet &K1, TIntSet &K2)
{
  TIntSet i;
  intersection(K1, K2, i);

  return double(i.size()) / K1.size();
}
//---------------------------------------------------------------------------
void Prosein(T2DoubleArray &A, TIntSet &K, TIntArray &IK, TIntSet &Mdel, int count_vars)
{
  TDoubleArray X, m, tR;
  TIntSet t;
  TIntSetIterator p;
  double r_m, r_s;
  int i;
  int c = count_vars, M = K.size();

  if (K.size() <= 3) return;

  if (c == -1) c = A[0].Length;

  m.Length = c;
  VectorSet(m, 0);
  for (p = K.begin(); p != K.end(); p++)
    for (i = 0; i < c; i++)
      m[i] += A[*p][i];
  for (i = 0; i < c; i++)
    m[i] /= M;

  tR.Length = M;
  for (i = 0, p = K.begin(); p != K.end(); i++, p++)
    tR[i] = metrica(m, A[*p]);

  for (r_m = i = 0; i < M; i++)
    r_m += tR[i];
  r_m /= M;

  for (r_s = i = 0; i < M; i++)
    r_s += (tR[i] - r_m) * (tR[i] - r_m);
  r_s = sqrt(r_s / (M - 1));

  t.clear();
  for (i = 0, p = K.begin(); p != K.end(); i++, p++)
    if (tR[i] >= r_m + theta * r_s) {
      IK[*p]--;
      if (IK[*p] == 0) Mdel.insert(*p);
      t.insert(*p);
    }
  K = K - t;
}
//---------------------------------------------------------------------------
bool isUnion(T2DoubleArray &A, TIntSet &K1, TIntSet &K2, int count_vars)
{
  T2DoubleArray A1, A2;
  TDoubleArray m1, m2;
  int j = 0, k = 0;
  int n, c = count_vars;

  if (K1.size() < 2 || K2.size() < 2) return false;

  double s_r1, s_r2, s_r;
  TDoubleArray s;

  A1 = GetSubArray(A, K1);
  A2 = GetSubArray(A, K2);

  if (c == -1) c = A[0].Length;

  if (A1.Length == 0 || A2.Length == 0) return false;

  m1.Length = c;
  m2.Length = c;
  VectorSet(m1, 0);
  VectorSet(m2, 0);
  for (k = 0; k < c; k++) {
    for (j = 0; j < A1.Length; j++)
      m1[k] += A1[j][k];
    for (j = 0; j < A2.Length; j++)
      m2[k] += A2[j][k];
    m1[k] /= A1.Length;
    m2[k] /= A2.Length;
  }

  s.Length = c;
  for (k = 0; k < c; k++) {
    s[k] = 0;
    for (j = 0; j < A1.Length; j++)
      s[k] += A1[j][k];
    for (j = 0; j < A2.Length; j++)
      s[k] += A2[j][k];
    s[k] /= A1.Length + A2.Length;
  }

  s_r = s_r1 = s_r2 = 0;
  for (j = 0; j < A1.Length; j++) {
    s_r1 += metrica(A1[j], m1);
    s_r  += metrica(A1[j], s);
  }
  for (j = 0; j < A2.Length; j++) {
    s_r2 += metrica(A2[j], m2);
    s_r  += metrica(A2[j], s);
  }
  s_r1 /= A1.Length;
  s_r2 /= A2.Length;
  s_r  /= A1.Length + A2.Length;

  if (s_r > alpha * max(s_r1, s_r2)) return false;

  return true;
}
//---------------------------------------------------------------------------
void UnionPoints(T2DoubleArray &A, TintIntSetMap &Classes, TIntArray &IK, TIntSet &M, int count_vars)
{
  T2DoubleArray X;
  TDoubleArray sum;
  TIntSetIterator p;
  TintIntSetMapIterator mp;
  TIntSet tM;
  int i, j, v, c;
  int m = count_vars;
  double d1, d2, m1, m2, D1, D2;

  if (m == -1) m = X[0].Length;

  sum.Length  = m;
  for (mp = Classes.begin(); mp != Classes.end(); mp++) {
    X = GetSubArray(A, (*mp).second);
    if (X.Length < 2) continue;

    for (v = 0; v < m; v++) {
      sum[v] = 0;
      for (c = 0; c < X.Length; c++)
        sum[v] += X[c][v];
    }

    tM.clear();
    for (p = M.begin(); p != M.end(); p++) {
      D1 = D2 = 0;
      for (v = 0; v < m; v++) {
        m1 = sum[v] / X.Length;
        m2 = (sum[v] + A[*p][v]) / (X.Length + 1);
        d1 = d2 = 0;
        for(c = 0; c < X.Length; c++) {
          d1 += (X[c][v] - m1) * (X[c][v] - m1);
          d2 += (X[c][v] - m2) * (X[c][v] - m2);
        }
        d2 += (A[*p][v] - m2) * (A[*p][v] - m2);
        D1 += d1 / (X.Length - 1);
        D2 += d2 /  X.Length;
      }
      if (D2 <= betta * D1) {
        (*mp).second.insert(*p);
        IK[*p]++;
        tM.insert(*p);
      }
    }

    M = M - tM;
  }
}
//---------------------------------------------------------------------------
void CalcClassCenter(T2DoubleArray &A, TIntSet &K, TDoubleArray &m, int count_vars)
{
  T2DoubleArray A1;
  int i, j, N = K.size(), c = count_vars;

  if (K.size() == 0) return;
  if (c == -1) c = A[0].Length;
  m.Length = c;

  A1 = GetSubArray(A, K);
  for (i = 0; i < c; i++) {
    for (m[i] = j = 0; j < N; j++)
      m[i] += A1[j][i];
    m[i] /= N;
  }
}
//---------------------------------------------------------------------------
void CalcClassesCenters(T2DoubleArray &A, TintIntSetMap &Classes, T2DoubleArray &Centers, int count_vars)
{
  TDoubleArray m;
  TintIntSetMapIterator mp;
  int i;

  Centers.Length = Classes.size();
  for (i = 0, mp = Classes.begin(); mp != Classes.end(); i++, mp++) {
    CalcClassCenter(A, (*mp).second, m, count_vars);
    Centers[i] = m.Copy();
  }
}
//---------------------------------------------------------------------------
void Classification(T2DoubleArray &A, TintIntSetMap &Classes, TIntArray &IK, int k, int count_vars)
{
  T2DoubleArray R, P, Centers;
  TDoubleArray C, R1, tC, IC;
  T2IntArray S;
  TIntSet tK, K, M, M1, M2, Mdel, O, tmp;
  TIntSetIterator p;
  TintIntSetMap Classes1;
  TintIntSetMapIterator mp, mp1;
  int imin, imax;
  int i, j, d;
  int N = A.Length, Ncl = 0;

  ProgressCaption(" лассификаци€...");
  ProgressShow();
  ProgressSet(0);

  Classes.clear();

  IK.Length = N;
  VectorSet(IK, 0);

// 1.
  CalcDistances(A, R, count_vars);
  CalcCentrist(R, S, C, R1, k);
  MakeM1M2(C, R1, M1, M2);
  for (p = M2.begin(); p != M2.end(); p++) {
    Classes[Ncl++].insert(*p);
    IK[*p] = 1;
  }
  ProgressSet(10);
  WriteArray(C, "out\\C.txt");
  WriteArray(R1, "out\\R1.txt");
  WriteArray(S, "out\\S.txt");
  WriteMap(Classes, "out\\Classes_1.txt");
  WriteSet(M1, "out\\M1.txt");
  WriteSet(M2, "out\\M2.txt");

// 2.+3.
  tC = C.Copy();
  IC.Length = N;
  for (i = 0; i < N; i++) IC[i] = i;
  VectorDualSort(tC,  IC,  SORT_DESCENDING);

  for (i = 0; i < N; i++)
    if (!M1.count(IC[i]) && IK[IC[i]] == 0) {
      MakeCj(C, S, K, M1, M2, 2, IC[i]);
      for (j = 3; j <= k; j++) {
        MakeCj(C, S, tK, M1, M2, j, IC[i]);
        if (tK.size() < K.size() + j ||
                     Assim(A, tK, count_vars) < delta * Assim(A, K, count_vars))
          K = tK;
        else break;
      }
      Classes[Ncl++].insert(K.begin(), K.end());
      for (p = K.begin(); p != K.end(); p++)
        IK[*p]++;
    }
  ProgressSet(20);
  WriteMap(Classes, "out\\Classes_23.txt");

// 5.
  P.Length = Ncl;
  for (i = 0; i < Ncl; i++)
    P[i].Length = Ncl;
  for (i = 0; i < Ncl; i++) {
    P[i][i] = 0;
    for (j = i + 1; j < Ncl; j++) {
      P[i][j] = Intersect(Classes[i], Classes[j]);
      P[j][i] = Intersect(Classes[j], Classes[i]);
    }
  }
  ProgressSet(30);
  WriteArray(P, "out\\P.txt");

// 6.
  for (i = 0; i < Ncl; i++)
    for (j = i + 1; j < Ncl; j++)
      if (P[i][j] >= gamma || P[j][i] >= gamma)
        if (isUnion(A, Classes[i], Classes[j], count_vars)) {
          tmp.clear();
          intersection(Classes[i], Classes[j], tmp);
          union(Classes[i], Classes[j], Classes[i]);
          for (p = tmp.begin(); p != tmp.end(); p++)
            IK[*p]--;
          Classes.erase(j);
        }
  ProgressSet(40);
  WriteMap(Classes, "out\\Classes_6.txt");
  WriteArray(IK, "out\\IK_6.txt");

// 4.
  Mdel.clear();
  for (mp = Classes.begin(); mp != Classes.end(); mp++)
    Prosein(A, (*mp).second, IK, Mdel, count_vars);
  union(Mdel, M1, M);
  ProgressSet(50);
  WriteSet(Mdel, "out\\Mdel.txt");
  WriteMap(Classes, "out\\Classes_4.txt");
  WriteSet(M, "out\\M_4.txt");

// 7.
  UnionPoints(A, Classes, IK, M, count_vars);
  ProgressSet(60);
  WriteMap(Classes, "out\\Classes_7.txt");
  WriteSet(M, "out\\M_7.txt");
  WriteArray(IK, "out\\IK_7.txt");

// ѕеренумераци€ классов
  Classes1.clear();
  for (Ncl = 0, mp = Classes.begin(); mp != Classes.end(); mp++)
    if  (!(*mp).second.empty())
      Classes1[Ncl++] = (*mp).second;
  Classes = Classes1;
  Classes1.clear();
  ProgressSet(70);
  WriteMap(Classes, "out\\Classes_7new.txt");

// 8.
  N = M.size();
  tC.Length = N;
  IC.Length = N;
  for (i = 0, p = M.begin(); p != M.end(); i++, p++) {
    tC[i] = C[*p];
    IC[i] = *p;
  }
  VectorDualSort(tC,  IC,  SORT_DESCENDING);

  O.clear();
  for (i = 0; i < A.Length; i++)
    if (IK[i]) O.insert(i);

  for (i = 0; i < N; i++) {
    if (IK[IC[i]] != 0) continue;
    MakeCj(C, S, K, M2, M2, 1, IC[i]);
    for (j = 2; j <= k; j++) {
      MakeCj(C, S, tK, M2, M2, j, IC[i]);
      if ((tK * (O - M)).size() / tK.size() < phi)
        K = tK;
      else break;
    }
    K = K - O;
    Classes[Ncl++].insert(K.begin(), K.end());
    tmp.clear();
    for (p = K.begin(); p != K.end(); p++) {
      IK[*p]++;
      tmp.insert(*p);
    }
    M = M - tmp;
  }
  ProgressSet(85);
  WriteSet(M, "out\\M_8.txt");
  WriteMap(Classes, "out\\Classes_8.txt");

// ƒобавл€ем остатки
  if (!M.empty())
    for (p = M.begin(); p != M.end(); p++) {
      Classes[Ncl++].insert(*p);
      IK[*p] = 1;
    }
  WriteArray(IK, "out\\IK_res1.txt");
  WriteMap(Classes, "out\\Classes_res1.txt");

// 9.
  bool flag;

  do {
    flag = false;
    CalcClassesCenters(A, Classes, Centers, count_vars);
    for (i = 0; i < IK.Length; i++)
      if (IK[i] > 1) {
        TintDoubleMap tR;
        TintDoubleMapIterator pR;
        tmp.clear();
        for (j = 0, mp = Classes.begin(); mp != Classes.end() && j < IK[i]; mp++)
          if ((*mp).second.count(i)) {
            tmp.insert((*mp).first);
            j++;
          }
        for (p = tmp.begin(); p != tmp.end(); p++)
          tR[*p] = metrica(A[i], Centers[*p]);
        for (pR = tR.begin(), imin = imax = (*pR).first; pR != tR.end(); pR++) {
          if (tR[imin] > (*pR).first) imin = (*pR).first;
          if (tR[imax] < (*pR).first) imax = (*pR).first;
        }
        if (tR[imax] >= psi * tR[imin]) {
          Classes[imax].erase(i);
          IK[i]--;
          flag = true;
        }
      }
  } while (flag);
  WriteArray(IK, "out\\IK_res.txt");
  WriteMap(Classes, "out\\Classes_res.txt");

// sort
  for (mp = Classes.begin(); mp != Classes.end(); mp++)
    for (mp1 = mp, mp1++; mp1 != Classes.end(); mp1++)
      if ((*mp).second.size() > (*mp1).second.size()) {
        tmp = (*mp).second;
        (*mp).second = (*mp1).second;
        (*mp1).second = tmp;
      }

  ProgressSet(100);
  ProgressHide();
}
//---------------------------------------------------------------------------
#pragma package(smart_init)

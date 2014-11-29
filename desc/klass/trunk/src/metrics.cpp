//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <set>
#include <stdio>
#include <values>
#include <math>
#include "DArrayTypes.h"
#include "MatrixFunctions.h"
//---------------------------------------------------------------------------
#define alpha   2
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
void ReadFile(FILE *f, T2DoubleArray &A, int N, int M);
void WriteFile(char *name, T2DoubleArray &A);
void WriteFile(char *name, T2IntArray &A);
double metrica(TDoubleArray &X, TDoubleArray &Y);
bool Find(T2DoubleArray *K, T2IntArray *IA, int N0, int nom, int nklass);
//---------------------------------------------------------------------------
set<int, less<int> > NSet;
//---------------------------------------------------------------------------
#pragma argsused
void main(int argc, char* argv[])
{
  T2DoubleArray A1, R, K;
  T2IntArray IA1;
  TDoubleArray tmpR, NN;
  double min, min2, max;
  int i, j, N1, M, n = 1, p;
  FILE *f1, *f2, *out, *kl;

  f1 = fopen(argv[1], "r");
  out = fopen("_out.txt", "w");
  kl = fopen("_klass.txt", "w");

  fscanf(f1, "%d %d\n", &N1, &M);

  ReadFile(f1, A1, N1, M);

  K.Length = N1;
  for (i = 0; i < N1; i++) {
    K[i].Length = 2;
    K[i][0] = i;
    K[i][1] = 0;
  }

  R.Length = N1;
  for (i = 0; i < N1; i++) {
    R[i].Length = N1;
    for (j = 0; j < N1; j++)
      R[i][j] = metrica(A1[i], A1[j]);
  }

  IA1.Length = N1;
  for (i = 0; i < N1; i++) {
    IA1[i].Length = 2;
    min = min2 = MAXDOUBLE;
    for (j = 0; j < N1; j++)
      if (min > R[i][j]) {
        min = R[i][j];
        IA1[i][0] = j;
      }

    for (j = 0; j < N1; j++)
      if (min2 > R[i][j] && j != IA1[i][0]) {
        min2 = R[i][j];
        IA1[i][1] = j;
      }
  }

  WriteFile("_metrica.txt", R);
  WriteFile("_IA1.txt", IA1);

  for (i = 0; i < N1; i++) {
    if (i == IA1[IA1[i][0]][0] && i < IA1[i][0]) {
      fprintf(out, "%3d%3d\t4\t%6.4lf\n", i + 1, IA1[i][0] + 1, R[i][IA1[i][0]]);
      continue;
    }
    if (i == IA1[IA1[i][0]][1] && i < IA1[i][0]) {
      fprintf(out, "%3d%3d\t3\t%6.4lf\n", i + 1, IA1[i][0] + 1, R[i][IA1[i][0]]);
      continue;
    }
    if (i == IA1[IA1[i][1]][0] && i < IA1[i][1]) {
      fprintf(out, "%3d%3d\t2\t%6.4lf\n", i + 1, IA1[i][1] + 1, R[i][IA1[i][1]]);
      continue;
    }
    if (i == IA1[IA1[i][1]][1] && i < IA1[i][1]) {
      fprintf(out, "%3d%3d\t1\t%6.4lf\n", i + 1, IA1[i][1] + 1, R[i][IA1[i][1]]);
      continue;
    }
  }

  tmpR.Length = N1;
  NN.Length = N1;
  for (i = 0; i < N1; i++) {
    NN[i] = i;
    tmpR[i] = R[i][IA1[i][0]];
  }

  VectorDualSort(tmpR, NN, SORT_DESCENDING);

  { TDoubleArray t;
    t.Length = N1;
    VectorSet(t, 0);
    for (i = 4; i < N1 - 4; i++)
      t[i] = (tmpR[i + 3] + tmpR[i + 2] + tmpR[i + 1] + tmpR[i]    ) /
             (tmpR[i - 4] + tmpR[i - 3] + tmpR[i - 2] + tmpR[i - 1]);
    for (p = 1; p < N1; p++)
      if (t[p] < t[p - 1]) break;
  }

  p -= 4;
  if (p < 0) p = 0;

  for (i = 0; i < p; i++) {
    K[NN[i]][1] = n;
    n++;
  }

  for (i = p; i < N1; i++)
    if (NN[i] == IA1[IA1[NN[i]][0]][0] && NN[i] < IA1[NN[i]][0]) {
      K[NN[i]][1] = n;
      K[IA1[NN[i]][0]][1] = n;
      n++;
    }

  for (i = p; i < N1; i++) {
    NSet.erase(NSet.begin(), NSet.end());
    if (Find(&K, &IA1, NN[i], IA1[NN[i]][0], n)) {
      K[NN[i]][1] = n;
      n++;
      continue;
    }
    NSet.erase(NSet.begin(), NSet.end());
    if (Find(&K, &IA1, NN[i], IA1[NN[i]][1], n)) {
      K[NN[i]][1] = n;
      n++;
    }
  }
/*
  for (i = 0; i < N1; i++)
    fprintf(kl, "%3.0f\t%6.4f\n", NN[i], tmpR[i]);

  fprintf(kl, "---------------------------------\n");
*/
  for (i = 0; i < N1; i++)
    fprintf(kl, "%3.0f\t%3.0f\n", K[i][0], K[i][1]);

  fclose(kl);
  fclose(out);
  fclose(f1);
}
//---------------------------------------------------------------------------
void ReadFile(FILE *f, T2DoubleArray &A, int N, int M)
{
  int i, j;
  double d;
  
  A.Length = N;
  for (i = 0; i < N; i++) {
    A[i].Length = M;
    for (j = 0; j < M; j++) {
      fscanf(f, "%lf", &d);
      A[i][j] = d;
    }
    fscanf(f, "\n");
  }
}
//---------------------------------------------------------------------------
void WriteFile(char *name, T2DoubleArray &A)
{
  int i, j;
  FILE *f;

  f = fopen(name, "w");

  fprintf(f, "\t");
  for (j = 0; j < A[0].Length; j++)
    fprintf(f, "%d\t", j + 1);
  fprintf(f, "\n");

  for (i = 0; i < A.Length; i++) {
    fprintf(f, "%d\t", i + 1);
    for (j = 0; j < A[i].Length; j++)
      fprintf(f, "%6.4lf\t", A[i][j]);
    fprintf(f, "\n");
  }

  fclose(f);
}
//---------------------------------------------------------------------------
void WriteFile(char *name, T2IntArray &A)
{
  int i, j;
  FILE *f;

  f = fopen(name, "w");

  fprintf(f, "\t");
  for (j = 0; j < A[0].Length; j++)
    fprintf(f, "%d\t", j + 1);
  fprintf(f, "\n");

  for (i = 0; i < A.Length; i++) {
    fprintf(f, "%d\t", i + 1);
    for (j = 0; j < A[i].Length; j++)
      fprintf(f, "%3d\t", A[i][j]);
    fprintf(f, "\n");
  }

  fclose(f);
}
//---------------------------------------------------------------------------
double metrica(TDoubleArray &X, TDoubleArray &Y)
{
  int i;
  double max = -1, s = 0;

  for (i = 0; i < X.Length; i++) {
    s += (X[i] - Y[i]) * (X[i] - Y[i]);
    if (fabs(X[i] - Y[i]) > max) max = fabs(X[i] - Y[i]);
  }
  s = sqrt(s);

  if (s * max == 0)
    return MAXDOUBLE;
  else
    return s * max;
}
//---------------------------------------------------------------------------
bool Find(T2DoubleArray *K, T2IntArray *IA, int N0, int nom, int nklass)
{
  bool b;

  if ((*K)[nom][1] != 0 || NSet.count(nom)) return false;

  if (nom == N0) return true;

  NSet.insert(nom);

  b = Find(K, IA, N0, (*IA)[nom][0], nklass);
  if (!b) b = Find(K, IA, N0, (*IA)[nom][1], nklass);

  if (b) {
    (*K)[nom][1] = nklass;
    return true;
  }
  else return false;
}
//---------------------------------------------------------------------------



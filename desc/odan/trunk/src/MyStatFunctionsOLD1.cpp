//---------------------------------------------------------------------------
// � � � � � � � � � �: �� ���� (?) ���������� �� ����������� ����!
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <stdlib.h>
#include "MyStatFunctions.h"
#include "Progress.h"
#include "MatrixDisplay.h"
#include "Utils.h"
#include "Config.h"
//---------------------------------------------------------------------------
#define step_size       5//%
//---------------------------------------------------------------------------
double Rmin[5][5];
double mm1[5], ss1[5], mm2[5], ss2[5];
double Report[70];
extern int weigh_num;
//---------------------------------------------------------------------------
//������������ � ������� � ������ b ������������ ������� � ��� ��� ������ �� XX ������� �
//Nbeg � � ���������� NN ����
//(��� ����������� ����� � ����������� ���������� ��������� �������)
void R (TDoubleArray &XX, TDoubleArray &W, long Nbeg, long NN, double *b)
{
  TDoubleArray workX, workY, workW;
  int i;

  workX = XX.CopyRange(Nbeg, NN);
  workW = W.CopyRange(Nbeg, NN);
  VectorDualSort(workX, workW, SORT_ASCENDING);
  workY = workX.Copy();
  VectorRank (workY, SORT_ASCENDING, RANK_MEAN);
  for (i = 0; i < NN; i++)
    workY[i] = vNormal((3 * workY[i] - 1) / (3 * NN + 1), 0, 1);

  LineApprox(workX, workY, workW, b);

  b[0] /= -b[1];
  b[1] = 1 / b[1];
}
//---------------------------------------------------------------------------
//���������� ������ ���� ��� ������� �������������
int SizeJadr (long N)
{
   if (N < 10) return 1;
   else if (N >= 80) return 10;
        else return 3;
}
//---------------------------------------------------------------------------
void JadrParameters (TDoubleArray &X, TDoubleArray &W, TDoubleArray &W1,
                     TDoubleArray &X1, TDoubleArray &FF,
                     TDoubleArray &f, double &eps, bool isQuantiles)
{
  TDoubleArray BB, Dx;
  long N = X.Length, c = 2 * N;
  double a, b, a_, b_, d, eps1, S, t;
  int k, i, ii, jj;

  progress_step = 30. / c;

  X1.Length = c;
  W1.Length = c;
  FF.Length = c;
  f.Length  = c;
  BB.Length = c;
  Dx.Length = c;

  a = X[0];
  b = a;
  for (i = 0; i < N; i++) {
    if (X[i] < a) a = X[i];
    if (X[i] > b) b = X[i];
  }

  k = SizeJadr(N);
  d = (b - a) / k;

  for (i = 0; i < N; i++) {
    X1[2 * i    ] = X[i] - d / 2;
    X1[2 * i + 1] = X[i] + d / 2;
    W1[2 * i    ] = W[i];
    W1[2 * i + 1] = W[i];
  }

  VectorDualSort(X1, W1, SORT_ASCENDING);
  VectorDualSort(X, W, SORT_ASCENDING);

  for (i = 0; i < c - 1; i++)
    Dx[i] = X1[i + 1] - X1[i];

  eps1 = X1[c - 1];
  for (i = 0; i < c - 1; i++)
    if (0 < Dx[i] && Dx[i] < eps1) eps1 = Dx[i];
  eps1 /= 2;
  eps = eps1;

  ProgressSet(10);

  ii = 0;
  jj = 0;
  for (i = 0; i < c; i++) {
    BB[i] = 0;
    a_ = X1[i] - d / 2 + eps;
    b_ = a_ + d; //X1[i] + d / 2 + eps

  l1:
    if (a_ >= X[ii]) {
      ii++;
      if (ii >= N) break;
      goto l1;
    }

    if (ii > jj) jj = ii;

    if (jj < N) {
      while (X[jj] <= b_) {
        jj++;
        if (jj >= N) {
          jj = N;
          break;
        }
      }
    }

    BB[i] = jj - ii;
    
    ProgressInc();
  }

  f[0] = 0;
  for (i = 0; i < c - 1; i++) {
    f[i] = (2 * k - 1) / (2 * k * (N + 1) * (b - a)) + BB[i] / ((N + 1) * d);
    ProgressInc();
  }
  f[c - 1] = 0;
/*////
  for (i = 0; i < c; i++)
    f[i] *= fabs(X1[i] - X1[0]);

  for (S = 0, i = 0; i < c - 1; i++)
    S += (f[i] + f[i + 1]) * (X1[i + 1] - X1[i]) / 2;

  for (i = 0; i < c; i++)
    f[i] /= S;

//  for (S = 0, i = 0; i < c - 1; i++)
//    S += (f[i] + f[i + 1]) * (X1[i + 1] - X1[i]) / 2;
/*////
  FF[0] = 0;
  S = 0;
  for (i = 0; i < c - 1; i++) {
    S += (X1[i + 1] - X1[i]) * f[i];
    FF[i] = S;
    ProgressInc();
  }
  FF[c - 1] = 1;

  if (isQuantiles == TRUE) {
    jj = 0;
    while (0.01 >= FF[jj]) jj++;
    Report[16] = X1[jj];
    for (i = 1; i < 20; i++) {
      t = i * 0.05;

      while (t >= FF[jj]) jj++;

      Report[i + 16] = X1[jj];
    }
    while (0.99 >= FF[jj]) jj++;
    Report[36] = X1[jj];
    Report[8 ] = Report[26];
  }
  ProgressSet(100);
}
//---------------------------------------------------------------------------
double D_2 (TDoubleArray &X1, TDoubleArray &FF, double m, double s)
{
  double D, j;
  long N = X1.Length;

  D = 0;
  j  = 0;
  for (int i = 0; i < N; i++){
    j = fabs(iNormal(X1[i], m, s) - FF[i]);
    if (j > D) D = j;
  }

  return D;
}
//---------------------------------------------------------------------------
double Smesi_D_2 (TDoubleArray &X1, TDoubleArray &FF,
                  double m1, double s1, double m2, double s2, double q1)
{
  double D, j;
  long N = X1.Length;
  bool isNormal1, isNormal2;

//  if (ConfigForm->rbNormal->Checked)
    isNormal1 = isNormal2 = true;
//  else
//    isNormal1 = !(isNormal2 = q1 >= 0.5);

  D = 0;
  j  = 0;
  for (int i = 0; i < N; i++){
    j = fabs(iSmes(X1[i], m1, s1, m2, s2, q1, isNormal1, isNormal2) - FF[i]);
    if (j > D) D = j;
  }

  return D;
}
//---------------------------------------------------------------------------
double Kn (double lambda)
{
  double sKn, j;
  int znak, kk;

  if (lambda < 0) return 0;
  else {
    sKn = 1;
    znak = 1;
    kk = 1;
    while (1) {
      j = 2 * exp(- 2 * kk * kk * lambda * lambda);
      if (j < 0.0001) break;

      sKn += - znak * j;
      kk++;
      znak = -znak;
    }
  }

  return sKn;
}
//---------------------------------------------------------------------------
bool Hipoteza (TDoubleArray &X1, TDoubleArray &FF, int Stepen, int i_H,
               double m, double s, double *res)
{
  long N = X1.Length;
  double alpha;

  switch (Stepen) {
    case IDSLABAJA :
      switch (i_H) {
        case 1 : alpha = 0.1; break;
        case 2 : alpha = 0.05; break;
        default: alpha = 0.01; break;
      }
      break;
    case IDSILNAJA :
      switch (i_H) {
        case 1 : alpha = 0.2; break;
        case 2 : alpha = 0.1; break;
        default: alpha = 0.05; break;
      }
      break;
  }

  double dd_2 = D_2(X1, FF, m, s);
  if (N <= 30) dd_2 *= (sqrt(N/2) + 0.12 + 0.11 / sqrt(N/2));
  double add_2 = 1 - Kn(dd_2 * sqrt(N/2));
  res[0] = alpha;
  res[1] = add_2;
  if (alpha > add_2) return FALSE;
  else return TRUE;
}
//---------------------------------------------------------------------------
bool Smesi_Hipoteza (TDoubleArray &X1, TDoubleArray &FF, int Stepen,int Propusk,
                     double m1, double s1, double m2, double s2, double q1, double *res)
{
  long N = X1.Length;
  double alpha;

  switch (Stepen) {
    case IDSLABAJA :
      switch (Propusk) {
        case 1 : alpha = 0.1; break;
        case 2 : alpha = 0.05; break;
        default: alpha = 0.01; break;
      }
      break;
    case IDSILNAJA :
      switch (Propusk) {
        case 1 : alpha = 0.2; break;
        case 2 : alpha = 0.1; break;
        default: alpha = 0.05; break;
      }
      break;
  }

  alpha = 0.001; ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  double dd_2 = Smesi_D_2(X1, FF, m1, s1, m2, s2, q1);
  if (N <= 30) dd_2 *= (sqrt(N/2) + 0.12 + 0.11 / sqrt(N/2));
  double add_2 = 1 - Kn(dd_2 * sqrt(N/2));
  res[0] = alpha;
  res[1] = add_2;
  if (alpha > add_2) return FALSE;
  else return TRUE;
}
//---------------------------------------------------------------------------
void Norm (TDoubleArray &XX, double eps)
{
  TDoubleArray XX1 = XX.Copy();
  long N;

  ArchArray(XX1);
  N = XX1.Length;
  VectorSort(XX1, SORT_ASCENDING);

  long cnt = (long)floor(N * 0.025);

  for (long j = 0; j < XX.Length; j++)
    if (XX[j] != MISSING_DATA)
      XX[j] = (XX[j] - XX1[0] + eps) / (XX1[N - 1 - cnt] - XX1[0] + eps); // 0 <-> cnt
}
//---------------------------------------------------------------------------
void NormBC (TDoubleArray &XX, double lam, double eps)
{
  TDoubleArray XX1 = XX.Copy();
  long N = XX.Length;

  VectorSort(XX1, SORT_ASCENDING);

  long cnt = (long)floor(N * 0.025);

  for (long j = 0; j < N; j++) {
    if (fabs(lam) <= delta) XX[j] = log(XX[j]);
    else
      XX[j] = (exp(lam * log(fabs(XX[j]))) - 1) / lam; // <---------------- ������?
    XX[j] = (XX[j] - XX1[0] + eps) / (XX1[N - 1 - cnt] - XX1[0] + eps); // 0 <-> cnt
  }
}
//---------------------------------------------------------------------------
//�������������� �� �����-�����
void BCTransform (TDoubleArray &X, double lam)
{
  for (long i = 0; i < X.Length; i++)
    if (fabs(lam) <= delta) X[i] = log(X[i]);
    else
      X[i] = (exp(lam * log(fabs(X[i]))) - 1) / lam; // <---------------- ������?
}
//---------------------------------------------------------------------------
//�������� ��� ������� �������������� �� �����-�����
double R_BC (TDoubleArray &X, TDoubleArray &W, double lam)
{
  TDoubleArray workX, workY, workW;
  long NN = X.Length;
  int i;
  double b[2];

  workX = X.Copy();
  BCTransform (workX, lam);
  workW = W.Copy();
  VectorDualSort(workX, workW, SORT_ASCENDING);
  workY = workX.Copy();
  VectorRank (workY, SORT_ASCENDING, RANK_MEAN);
  for (i = 0; i < NN; i++)
    workY[i] = vNormal((3 * workY[i] - 1) / (3 * NN + 1), 0, 1);
/*
  double Xsr, Ysr, XYsr, XXsr;
  Xsr = Ysr = XYsr = XXsr = 0;
  for (i = 0; i < NN; i++) {
    Xsr = Xsr + workX[i];
    Ysr = Ysr + workY[i];
  }
  Xsr /= NN;
  Ysr /= NN;
  for (i = 0; i < NN; i++) {
    XYsr += (workX[i] - Xsr) *  workY[i];
    XXsr += (workX[i] - Xsr) * (workX[i] - Xsr);
  }
  double b1 = XYsr / XXsr,
         b2 = Ysr - b1 * Xsr,
         r_bc = 0;
*/
  double r_bc = 0;
  
  LineApprox(workX, workY, workW, b);
/*
  b[0] /= b[1];
  b[1] = 1 / b[1];
*/
  for (i = 0; i < NN; i++)
    r_bc += pow(workY[i] - b[0] - b[1] * workX[i], 2);

  return r_bc;
}
//---------------------------------------------------------------------------
//���������� ���������� ��������� � ����������� �� ������� �������
int CountQuantiles (long NN)
{
   if (NN < 10) return NN;
   else if (NN > 20) return 20;
        else return 10;
}
//---------------------------------------------------------------------------
//���������� ������� ����. ������ �� ���. ������ ��� ����� �� XX ������� � Nbegin �
//���������� Nend
double GetA (TDoubleArray &X, TDoubleArray &W, long Nbegin, long Nend)
{
  TDoubleArray workX, workY, workW;
  long NN = Nend - Nbegin + 1;
  int i;
  double b[2];

  workX = X.CopyRange(Nbegin, NN);
  workW = W.CopyRange(Nbegin, NN);
  VectorDualSort(workX, workW, SORT_ASCENDING);
  workY = workX.Copy();
  VectorRank (workY, SORT_ASCENDING, RANK_MEAN);
  for (i = 0; i < NN; i++)
    workY[i] = vNormal((3 * workY[i] - 1) / (3 * NN + 1), 0, 1);
/*
  double Xsr, Ysr, XYsr, XXsr;
  Xsr = Ysr = XYsr = XXsr = 0;
  for (i = 0; i < NN; i++) {
    Xsr = Xsr + workX[i];
    Ysr = Ysr + workY[i];
  }
  Xsr /= NN;
  Ysr /= NN;
  for (i = 0; i < NN; i++) {
    XYsr += (workX[i] - Xsr) *  workY[i];
    XXsr += (workX[i] - Xsr) * (workX[i] - Xsr);
  }

  return XYsr / XXsr;
*/
  LineApprox(workX, workY, workW, b);

  return b[1];
}
//---------------------------------------------------------------------------
//���������� "��������" ���������� ������������ ������������ ������� ������������� ��
//������������� ��� ����� ���� ���������� � ����������� m1, s1 � m2, s2 � ������ q1, 1-q1
//(��� ����������� �����)
double RKrit (TDoubleArray &X1, TDoubleArray &FF,
              double m1, double s1, double m2, double s2, double q1)
{
  TDoubleArray FF_;
  long NN = X1.Length;
  int i;
  bool isNormal1, isNormal2;

//  if (ConfigForm->rbNormal->Checked)
    isNormal1 = isNormal2 = true;
//  else
//    isNormal1 = !(isNormal2 = q1 >= 0.5);

  FF_.Length = NN;

  for (i = 0; i < NN; i++)
    FF_[i] = iSmes(X1[i], m1, s1, m2, s2, q1, isNormal1, isNormal2);
//    FF_[i] = (q1 * iNormal(X1[i], m1, s1) + (1 - q1) * iNormal(X1[i], m2, s2));

  double rkrit = 0;
  for (i = 0; i < NN; i++)
    rkrit += fabs(FF_[i] - FF[i]);

  return rkrit;
}
//---------------------------------------------------------------------------
void SmesiQuantiles (TDoubleArray &X1, TDoubleArray &FF, double *Q,
                     double m1, double s1, double m2, double s2, double q1)
{
  long N = X1.Length, ci;
  int i;
  double t;

  for (i = 0; i < 21; i++) {
    if (i == 0) t = 0.01;
    else if (i == 20) t = 0.99;
         else t = i * 0.05;

    ci = 1;
    while (t >= FF[ci]) ci++;

    if (t >= q1 * iNormal(X1[ci], m1, s1) + (1 - q1) * iNormal(X1[ci], m2, s2))
      while (t >= q1 * iNormal(X1[ci], m1, s1) +
                   (1 - q1) * iNormal(X1[ci], m2, s2) && ci < N - 1) ci++;
    else
      while (t < q1 * iNormal(X1[ci], m1, s1) +
                  (1 - q1) * iNormal(X1[ci], m2, s2) && ci > 0) ci--;

    if (Q) Report[i + 45] = Q[i] = X1[ci];
    else Report[i + 45] = X1[ci];
  }
  Report[39] = Report[55];
}
//---------------------------------------------------------------------------
void Quantiles (double *Q, double m, double s)
{
  for (int i = 1; i < 20; i++)
    if (Q) Report[i + 45] = Q[i] = vNormal(i * 0.05, m, s);
    else Report[i + 45] = vNormal(i * 0.05, m, s);
  if (Q) {
    Report[45] = Q[0] = vNormal(0.01, m, s);
    Report[65] = Q[20] = vNormal(0.99, m, s);
  }
  else {
    Report[45] = vNormal(0.01, m, s);
    Report[65] = vNormal(0.99, m, s);
  }
  Report[39] = Report[55];
}
//---------------------------------------------------------------------------
void LineApprox(TDoubleArray &X, TDoubleArray &Y, TDoubleArray &W, double *b)
{
  double Xsr, Ysr, XYsr, XXsr;
  long N = X.Length, i;

  Xsr = Ysr = XYsr = XXsr = 0;
  for (i = 0; i < N; i++) {
    Xsr = Xsr + X[i];
    Ysr = Ysr + Y[i];
  }
  Xsr /= N;
  Ysr /= N;
  for (i = 0; i < N; i++) {
    if (weigh_num) {
      XYsr += W[i] * (X[i] - Xsr) *  Y[i];
      XXsr += W[i] * (X[i] - Xsr) * (X[i] - Xsr);
    }
    else {
      XYsr += (X[i] - Xsr) *  Y[i];
      XXsr += (X[i] - Xsr) * (X[i] - Xsr);
    }
  }

  b[1] = XYsr / XXsr;
  b[0] = Ysr - b[1] * Xsr;
}
//---------------------------------------------------------------------------
void LineApprox(TDoubleArray &X, TDoubleArray &Y, TDoubleArray &W,
                long Nbegin, long Nend, double *b)
{
  double Xsr, Ysr, XYsr, XXsr;
  long N = Nend - Nbegin + 1, i;

  Xsr = Ysr = XYsr = XXsr = 0;
  for (i = Nbegin; i <= Nend; i++) {
    Xsr = Xsr + X[i];
    Ysr = Ysr + Y[i];
  }
  Xsr /= N;
  Ysr /= N;
  for (i = Nbegin; i < Nend; i++) {
    if (weigh_num) {
      XYsr += W[i] * (X[i] - Xsr) *  Y[i];
      XXsr += W[i] * (X[i] - Xsr) * (X[i] - Xsr);
    }
    else {
      XYsr += (X[i] - Xsr) *  Y[i];
      XXsr += (X[i] - Xsr) * (X[i] - Xsr);
    }
  }

  if (XXsr)
    b[1] = XYsr / XXsr;
  else
    b[1] = -1;
  b[0] = Ysr - b[1] * Xsr;
}
//---------------------------------------------------------------------------
void ArchArray(TDoubleArray &X)
{
  TDoubleArray X1;
  long i, j;

  X1.Length = X.Length;
  j = 0;
  for (i = 0; i < X.Length; i++)
    if (X[i] != MISSING_DATA) X1[j++] = X[i];

  X1.Length = j;
  X = X1.Copy();
}
//---------------------------------------------------------------------------
double Correlation(TDoubleArray &X, TDoubleArray &Y)
{
  long N = min(X.Length, Y.Length);
  long i, j = 0;
  double Xsr, Ysr, XYsr, XXsr, YYsr;

  Xsr = Ysr = XYsr = XXsr = YYsr = 0;
  for (i = 0; i < N; i++)
    if (X[i] != MISSING_DATA && Y[i] != MISSING_DATA) {
      Xsr = Xsr + X[i];
      Ysr = Ysr + Y[i];
      j++;
    }

  Xsr /= j;
  Ysr /= j;
  for (i = 0; i < N; i++) 
    if (X[i] != MISSING_DATA && Y[i] != MISSING_DATA) {
      XYsr += (X[i] - Xsr) * (Y[i] - Ysr);
      YYsr += pow(Y[i] - Ysr, 2);
      XXsr += pow(X[i] - Xsr, 2);
    }

  return XYsr / sqrt(XXsr * YYsr);
}
//---------------------------------------------------------------------------
//double RR[3][3][3][3];
double _m1[3], _s1[3], _m2[3], _s2[3];
double _mm, _ss, mm_, ss_;
bool p1, p2;
//---------------------------------------------------------------------------
double SubAllVariate(TDoubleArray &XX1, TDoubleArray &FF1,
                     int im1, int is1, int im2, int is2, double q1)
{
  double step;
  double r, Rmin;

  if (_m1[1 + im1] == MISSING_DATA) {
    step = _s1[1] * step_size / 100;
    if (step < 1) step = _s1[1] / M_PI_2;
    switch (im1) {
      case -1 : {
                  Rmin = RKrit(XX1, FF1, _m1[1], _s1[1], _m2[1], _s2[1], q1);
                  _m1[0] = _m1[1];
                  if (!p1) while (_m1[0] - step < 1e-10) step /= 2;
                  while (true) {
                    r = RKrit(XX1, FF1, _m1[0] - step, _s1[1], _m2[1], _s2[1], q1);
                    if (r < Rmin - 1e-4) {
                      Rmin = r;
                      _m1[0] -= step;
                      if (_m1[0] - step > 1e-10)
                        continue;
                      else
                        break;
                    }
                    else step /= 2;
                    if (step < _s1[1] * step_size / 1e5) break;
                  }
                  break;
                }
      case  1 : {
                  Rmin = RKrit(XX1, FF1, _m1[1], _s1[1], _m2[1], _s2[1], q1);
                  _m1[2] = _m1[1];
                  while (true) {
                    r = RKrit(XX1, FF1, _m1[2] + step, _s1[1], _m2[1], _s2[1], q1);
                    if (r < Rmin - 1e-4) {
                      Rmin = r;
                      _m1[2] += step;
                      continue;
                    }
                    else step /= 2;
                    if (step < _s1[1] * step_size / 1e5) break;
                  }
                  break;
                }
    }
    ProgressInc();
  } // m1

  if (_s1[1 + is1] == MISSING_DATA) {
    step = _s1[1] * step_size / 100;
    if (step < 1) step = _s1[1] / M_PI_2;
    switch (is1) {
      case -1 : {
                  Rmin = RKrit(XX1, FF1, _m1[1 + im1], _s1[1], _m2[1], _s2[1], q1);
                  _s1[0] = _s1[1];
                  while (true) {
                    r = RKrit(XX1, FF1, _m1[1 + im1], _s1[0] - step, _m2[1], _s2[1], q1);
                    if (r < Rmin - 1e-4 && _s1[0] > 1e-2) {
                      Rmin = r;
                      _s1[0] -= step;
                      if (_s1[0] - step > 1e-10)
                        continue;
                      else
                        break;
                    }
                    else step /= 2;
                    if (step < _s1[1] * step_size / 1e5) break;
                  }
                  break;
                }
      case  1 : {
                  Rmin = RKrit(XX1, FF1, _m1[1 + im1], _s1[1], _m2[1], _s2[1], q1);
                  _s1[2] = _s1[1];
                  while (true) {
                    r = RKrit(XX1, FF1, _m1[1 + im1], _s1[2] + step, _m2[1], _s2[1], q1);
                    if (r < Rmin - 1e-4) {
                      Rmin = r;
                      _s1[2] += step;
                      if (_s1[2] >= 2 * _s1[1])
                        continue;
                      else
                        break;
                    }
                    else step /= 2;
                    if (step < _s1[1] * step_size / 1e5) break;
                  }
                  break;
                }
    }
    ProgressInc();
  } // s1

  if (_m2[1 + im2] == MISSING_DATA) {
    step = _s2[1] * step_size / 100;
    if (step < 1) step = _s2[1] / M_PI_2;
    switch (im2) {
      case -1 : {
                  Rmin = RKrit(XX1, FF1, _m1[1 + im1], _s1[1 + is1], _m2[1], _s2[1], q1);
                  _m2[0] = _m2[1];
                  if (!p2) while (_m2[0] - step < 1e-10) step /= 2;
                  while (true) {
                    r = RKrit(XX1, FF1, _m1[1 + im1], _s1[1 + is1], _m2[0] - step, _s2[1], q1);
                    if (r < Rmin - 1e-4) {
                      Rmin = r;
                      _m2[0] -= step;
                      if (_m2[0] - step > 1e-10)
                        continue;
                      else
                        break;
                    }
                    else step /= 2;
                    if (step < _s2[1] * step_size / 1e5) break;
                  }
                  break;
                }
      case  1 : {
                  Rmin = RKrit(XX1, FF1, _m1[1 + im1], _s1[1 + is1], _m2[1], _s2[1], q1);
                  _m2[2] = _m2[1];
                  while (true) {
                    r = RKrit(XX1, FF1, _m1[1 + im1], _s1[1 + is1], _m2[2] + step, _s2[1], q1);
                    if (r < Rmin - 1e-4) {
                      Rmin = r;
                      _m2[2] += step;
                      continue;
                    }
                    else step /= 2;
                    if (step < _s2[1] * step_size / 1e5) break;
                  }
                  break;
                }
    }
    ProgressInc();
  } // m2

  if (_s2[1 + is2] == MISSING_DATA) {
    step = _s2[1] * step_size / 100;
    if (step < 1) step = _s2[1] / M_PI_2;
    switch (is2) {
      case -1 : {
                  Rmin = RKrit(XX1, FF1, _m1[1 + im1], _s1[1 + is1], _m2[1 + im2], _s2[1], q1);
                  _s2[0] = _s2[1];
                  while (true) {
                    r = RKrit(XX1, FF1, _m1[1 + im1], _s1[1 + is1], _m2[1 + im2], _s2[0] - step, q1);
                    if (r < Rmin - 1e-4 && _s2[0] > 1e-2) {
                      Rmin = r;
                      _s2[0] -= step;
                      if (_s2[0] - step > 1e-10)
                        continue;
                      else
                        break;
                    }
                    else step /= 2;
                    if (step < _s2[1] * step_size / 1e5) break;
                  }
                  break;
                }
      case  1 : {
                  Rmin = RKrit(XX1, FF1, _m1[1 + im1], _s1[1 + is1], _m2[1 + im2], _s2[1], q1);
                  _s2[2] = _s2[1];
                  while (true) {
                    r = RKrit(XX1, FF1, _m1[1 + im1], _s1[1 + is1], _m2[1 + im2], _s2[2] + step, q1);
                    if (r < Rmin - 1e-4) {
                      Rmin = r;
                      _s2[2] += step;
                      if (_s2[2] >= 2 * _s2[1])
                        continue;
                      else
                        break;
                    }
                    else step /= 2;
                    if (step < _s2[1] * step_size / 1e5) break;
                  }
                  break;
                }
    }
    ProgressInc();
  } // s2

  ProgressInc();
  return RKrit(XX1, FF1, _m1[1 + im1], _s1[1 + is1], _m2[1 + im2], _s2[1 + is2], q1);
}
//---------------------------------------------------------------------------
double AllVariate(TDoubleArray &XX1, TDoubleArray &FF1,
                  double &m1, double &s1, double &m2, double &s2, double q1)
{
  int i1, i2, i3, i4;
  int i1_best, i2_best, i3_best, i4_best;
  double r, Rmin = MAXDOUBLE;

  for (i1 = -1; i1 <= 1; i1++)
    for (i2 = -1; i2 <= 1; i2++)
      for (i3 = -1; i3 <= 1; i3++)
        for (i4 = -1; i4 <= 1; i4++) {
          r = SubAllVariate(XX1, FF1, i1, i2, i3, i4, q1);

          if (r < Rmin) {
            i1_best = i1;
            i2_best = i2;
            i3_best = i3;
            i4_best = i4;
            Rmin = r;
          }
        }

  m1 = _m1[1 + i1_best];
  s1 = _s1[1 + i2_best];
  m2 = _m2[1 + i3_best];
  s2 = _s2[1 + i4_best];

  return Rmin;
}
//---------------------------------------------------------------------------
double QVariate(TDoubleArray &XX1, TDoubleArray &FF1,
                double &m1, double &s1, double &m2, double &s2, double &q1)
{
  int i, NOfTries = 1;;
  double r, m1_tmp, s1_tmp, m2_tmp, s2_tmp, Rmin_tmp;
  double Rmin = MAXDOUBLE, m1_best, s1_best, m2_best, s2_best, q1_best;

  do {
    ProgressCaption(SFormat("����������� �����. ��������: %d (Rmin=%.3e)", NOfTries++, Rmin));
    ProgressSet(0);
    ProgressShow();
    progress_step = 100. / (9 * (81 + 8));
    
    Rmin_tmp = Rmin;
    for (i = 1; i <= 9; i++) {
//      if (exp(m1 + s1 * s1 / 2) < exp(m2 + s2 * s2 / 2)) {
        m1_tmp = m1;
        s1_tmp = s1;
        m2_tmp = m2;
        s2_tmp = s2;
/*      }
      else {
        m1_tmp = m2;
        s1_tmp = s2;
        m2_tmp = m1;
        s2_tmp = s1;
      }*/
//      if (!ConfigForm->rbNormal->Checked && i >= 5 && m1_tmp < 0) m1_tmp = fabs(m2_tmp / 2);
//      if (!ConfigForm->rbNormal->Checked && i <  5 && m2_tmp < 0) m2_tmp = fabs(m1_tmp / 2);

      _m1[0] = _s1[0] = _m2[0] = _s2[0] = MISSING_DATA;
      _m1[1] = m1_tmp;
      _s1[1] = s1_tmp;
      _m2[1] = m2_tmp;
      _s2[1] = s2_tmp;
      _m1[2] = _s1[2] = _m2[2] = _s2[2] = MISSING_DATA;

//      if (ConfigForm->rbNormal->Checked)
        p1 = p2 = true;
//      else
//        p1 = !(p2 = i / 10. >= 0.5);
      r = AllVariate(XX1, FF1, m1_tmp, s1_tmp, m2_tmp, s2_tmp, i / 10.);

      if (r < Rmin || (r == Rmin && i > 3 && i < 7)) {
        m1_best = m1_tmp;
        s1_best = s1_tmp;
        m2_best = m2_tmp;
        s2_best = s2_tmp;
        q1_best = i / 10.;
        Rmin = r;
      }
    }

    m1 = m1_best;
    s1 = s1_best;
    m2 = m2_best;
    s2 = s2_best;
    q1 = q1_best;

    ProgressSet(100);
  }
  while (fabs(Rmin_tmp - Rmin) > fabs(Rmin / 1e3));

  ProgressHide();

  return Rmin;
}
//---------------------------------------------------------------------------
void NewQuantiles (bool isNormal1, double *Q, double m1, double s1,
                   double m2, double s2, double q1, bool isNormal2)
{
  int i;

  if (s2 <= 0 || q1 == 0 || q1 == 1) {
    for (i = 1; i < 20; i++)
      if (Q) Report[i + 45] = Q[i] = vNormal(i * 0.05, m1, s1);
      else Report[i + 45] = vNormal(i * 0.05, m1, s1);
    if (Q) {
      Report[45] = Q[0] = vNormal(0.01, m1, s1);
      Report[65] = Q[20] = vNormal(0.99, m1, s1);
    }
    else {
      Report[45] = vNormal(0.01, m1, s1);
      Report[65] = vNormal(0.99, m1, s1);
    }

    if (!isNormal1)
      for (i = 0; i <= 20; i++)
        if (Q)
          Report[45 + i] = Q[i] = exp(Q[i]);
        else
          Report[45 + i] = exp(Report[45 + i]);

    Report[39] = Report[55];
  }
  else {
    if (!isNormal1) {
      m1 = exp(m1 + s1 * s1 / 2);
      s1 = sqrt(m1 * m1 * (exp(s1 * s1) - 1));
    }
    if (!isNormal1) {
      m2 = exp(m2 + s2 * s2 / 2);
      s2 = sqrt(m2 * m2 * (exp(s2 * s2) - 1));
    }
    for (i = 1; i < 20; i++)
      if (Q) Report[i + 45] = Q[i] = vSmes(i * 0.05, m1, s1, m2, s2, q1, isNormal1, isNormal2);
      else Report[i + 45] = vSmes(i * 0.05, m1, s1, m2, s2, q1, isNormal1, isNormal2);
    if (Q) {
      Report[45] = Q[0] = vSmes(0.01, m1, s1, m2, s2, q1, isNormal1, isNormal2);
      Report[65] = Q[20] = vSmes(0.99, m1, s1, m2, s2, q1, isNormal1, isNormal2);
    }
    else {
      Report[45] = vSmes(0.01, m1, s1, m2, s2, q1, isNormal1, isNormal2);
      Report[65] = vSmes(0.99, m1, s1, m2, s2, q1, isNormal1, isNormal2);
    }

    Report[39] = Report[55];
  }
}
//---------------------------------------------------------------------------
#pragma package(smart_init)

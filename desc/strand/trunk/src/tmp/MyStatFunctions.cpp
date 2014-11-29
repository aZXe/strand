//---------------------------------------------------------------------------
// П Р И М Е Ч А Н И Е: Во всех процедурах не учитываются веса!
//---------------------------------------------------------------------------
/* TODO : Сделать учет весов */
#include <vcl.h>
#pragma hdrstop

#include <stdlib.h>
#include "Progress.h"
#include "MyStatFunctions.h"
//#include "MatrixDisplay.h"
//namespace std {
//---------------------------------------------------------------------------
#define step_size       5//%
//---------------------------------------------------------------------------
double Rmin[5][5];
double mm1[5], ss1[5], mm2[5], ss2[5];
double Report[70];
//---------------------------------------------------------------------------
//Подсчитывает и заносит в массив b эмпирические среднее и СКО для данных из XX начиная с
//Nbeg и в количестве NN штук
//(для расщепления смеси и определения параметров усеченной выборки)
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
         b2 = Ysr - b1 * Xsr;

  b[0] = - b2 / b1;
  b[1] = 1 / b1;
*/

  LineApprox(workX, workY, b);

  b[0] /= -b[1];
  b[1] = 1 / b[1];
}
//---------------------------------------------------------------------------
//Возвращает размер ядра для ядерной аппроксимации
int SizeJadr (long N)
{
   if (N < 10) return 1;
   else if (N >= 80) return 10;
        else return 3;
}
//---------------------------------------------------------------------------
void JadrParameters (TDoubleArray &X, TDoubleArray &X1, TDoubleArray &FF,
                     TDoubleArray &f, double &eps, bool isQuantiles)
{
  TDoubleArray BB, Dx;
  long N = X.Length, c = 2 * N;
  double a, b, a_, b_, d, eps1, S, t;
  int k, i, ii, jj;

  progress_step = 30. / c;

  X1.Length = c;
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
  }

  VectorSort(X1, SORT_ASCENDING);
  VectorSort(X,  SORT_ASCENDING);

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

  FF[0] = 0;
  S = 0;
  for (i = 0; i < c - 1; i++) {
    S = S + (X1[i + 1] - X1[i]) * f[i];
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

  D = 0;
  j  = 0;
  for (int i = 0; i < N; i++){
    j = fabs(q1 * iNormal(X1[i], m1, s1) + (1 - q1) * iNormal(X1[i], m2, s2) - FF[i]);
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
               double m, double s)
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
  if (N <= 30) dd_2 *= (sqrt(N/2.) + 0.12 + 0.11 / sqrt(N/2.));
  double add_2 = 1 - Kn(dd_2 * sqrt(N/2.));
  if (alpha > add_2) return FALSE;
  else return TRUE;
}
//---------------------------------------------------------------------------
bool Smesi_Hipoteza (TDoubleArray &X1, TDoubleArray &FF, int Stepen,int Propusk,
                     double m1, double s1, double m2, double s2, double q1)
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

  double dd_2 = Smesi_D_2(X1, FF, m1, s1, m2, s1, q1);
  if (N <= 30) dd_2 *= (sqrt(N/2.) + 0.12 + 0.11 / sqrt(N/2.));
  double add_2 = 1 - Kn(dd_2 * sqrt(N/2.));
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
      XX[j] = (exp(lam * log(fabs(XX[j]))) - 1) / lam; // <---------------- Модуль?
    XX[j] = (XX[j] - XX1[0] + eps) / (XX1[N - 1 - cnt] - XX1[0] + eps); // 0 <-> cnt
  }
}
//---------------------------------------------------------------------------
//Преобразование по Боксу-Коксу
void BCTransform (TDoubleArray &X, double lam)
{
  for (long i = 0; i < X.Length; i++)
   if (fabs(lam) <= delta) X[i] = log(X[i]);
   else
    X[i] = (exp(lam * log(fabs(X[i]))) - 1) / lam; // <---------------- Модуль?
}
//---------------------------------------------------------------------------
//Критерий для подбора преобразования по Боксу-Коксу
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
  
  LineApprox(workX, workY, b);
/*
  b[0] /= b[1];
  b[1] = 1 / b[1];
*/
  for (i = 0; i < NN; i++)
    r_bc += pow(workY[i] - b[0] - b[1] * workX[i], 2);

  return r_bc;
}
//---------------------------------------------------------------------------
//Возвращает количество квантилей в зависимости от размера выборки
int CountQuantiles (long NN)
{
   if (NN < 10) return NN;
   else if (NN > 20) return 20;
        else return 10;
}
//---------------------------------------------------------------------------
//Возвращает угловой коэф. прямой на вер. бумаге для точек из XX начиная с Nbegin и
//заканчивая Nend
double GetA (TDoubleArray &X, long Nbegin, long Nend)
{
  TDoubleArray workX, workY, workW;
  long NN = Nend - Nbegin + 1;
  int i;
  double b[2];

  workX = X.CopyRange(Nbegin, NN);
  VectorSort(workX, SORT_ASCENDING);
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
  LineApprox(workX, workY, b);

  return b[1];
}
//---------------------------------------------------------------------------
//Возвращает "интеграл" отклонений эмпирической интегральной функции распределения от
//теоретической ИФР смеси двух нормальных с параметрами m1, s1 и m2, s2 и весами q1, 1-q1
//(для расщепления смеси)
double RKrit (TDoubleArray &X1, TDoubleArray &FF,
              double m1, double s1, double m2, double s2, double q1)
{
  TDoubleArray FF_;
  long NN = X1.Length;
  int i;

  FF_.Length = NN;

  for (i = 0; i < NN; i++)
    FF_[i] = q1 * iNormal(X1[i], m1, s1) + (1 - q1) * iNormal(X1[i], m2, s2);

  double rkrit = 0;
  for (i = 0; i < NN; i++)
    rkrit += fabs(FF_[i] - FF[i]);

  return rkrit;
}

//---------------------------------------------------------------------------
//Производит вариацию s1 при заданных остальных параметрах смеси с занесением получаемых
//параметров в массивы mm1, ss1, mm2, ss2, а отклонений от эмпирич. ИФР в Rmin, при этом
//вариация осуществляется при условии уменьшения RKrit, начиная с уровня _Rmin_
//(для расщепления смеси)
void SVariate1 (TDoubleArray &X1, TDoubleArray &FF,
                double m1, double s1, double m2, double s2, double q1,
                double _Rmin_, int ind, int ind1)
{
  double sstep = s1 * step_size / 100;

  double _Rmin = _Rmin_,
         _ss = s1,
         _dj = 0, _Rm;
Again1SV1:
  _Rm = RKrit(X1, FF, m1, s1 - _dj * sstep, m2, s2, q1);
  if (_Rm <= _Rmin) {
    _Rmin = _Rm;
    _ss = s1 - _dj * sstep;
    _dj = _dj + 1;
    if (s1 - _dj * sstep > 0) goto Again1SV1;
  }
  ProgressInc();
  
  double Rmin_ = _Rmin_,
         ss_ = s1,
         dj_ = 0, Rm_;
Again2SV1:
  Rm_ = RKrit(X1, FF, m1, s1 + dj_ * sstep, m2, s2, q1);
  if (Rm_ <= Rmin_) {
    Rmin_ = Rm_;
    ss_ = s1 + dj_ * sstep;
    dj_ = dj_ + 1;
    if (s1 + dj_ * sstep > 0) goto Again2SV1;
  }
  ProgressInc();

  Rmin[ind1][ind]     = _Rmin;
  Rmin[ind1 + 1][ind] = Rmin_;

  ss1[ind1]     = _ss;
  ss1[ind1 + 1] = ss_;
}
//---------------------------------------------------------------------------
//Производит вариацию m1 при заданных остальных параметрах смеси с занесением получаемых
//параметров в массивы mm1, ss1, mm2, ss2, а отклонений от эмпирич. ИФР в Rmin, при этом
//вариация осуществляется при условии уменьшения RKrit. После нахождения наилучших
//значений по обе стороны от начального, в них производится вариация s1.
//(для расщепления смеси)
void MVariate1 (TDoubleArray &X1, TDoubleArray &FF,
                double m1, double s1, double m2, double s2, double q1, int ind)
{
  long NN = X1.Length;
  int i, j;

  j = 0;
  for (i = 1; i < NN; i++)
    if (X1[i] > m1) {
      j = i - 1;
      break;
    }

  double Rmin0 = RKrit(X1, FF, m1, s1, m2, s2, q1);
  double _Rmin = Rmin0,
         _mm = m1,
         _dj = 0, _Rm;
Again1MV1:
  _Rm = RKrit(X1, FF, X1[j - _dj], s1, m2, s2, q1);
  if (_Rm <= _Rmin) {
    _Rmin = _Rm;
    _mm = X1[j - _dj];
    _dj = _dj + 1;
    if (j - _dj >= 0) goto Again1MV1;
  }
  ProgressInc();

  double Rmin_ = Rmin0,
         mm_ = m1,
         dj_ = 0, Rm_;
Again2MV1:
  Rm_ = RKrit(X1, FF, X1[j + dj_ + 1], s1, m2, s2, q1);
  if (Rm_ <= Rmin_) {
    Rmin_ = Rm_;
    mm_ = X1[j + dj_ + 1];
    dj_ = dj_ + 1;
    if (j + dj_ + 1 < NN) goto Again2MV1;
  }
  ProgressInc();

  mm1[0] = m1;
  ss1[0] = s1;
  Rmin[0][ind] = Rmin0;

  mm1[1] = _mm;
  mm1[2] = _mm;
  mm1[3] = mm_;
  mm1[4] = mm_;

  SVariate1( X1, FF, _mm, s1, m2, s2, q1, _Rmin, ind, 1);
  SVariate1( X1, FF, mm_, s1, m2, s2, q1, Rmin_, ind, 3);
}
//---------------------------------------------------------------------------
//Производит вариацию s2 при заданных остальных параметрах смеси с занесением получаемых
//параметров в массивы mm1, ss1, mm2, ss2, а отклонений от эмпирич. ИФР в Rmin, при этом
//вариация осуществляется при условии уменьшения RKrit, начиная с уровня _Rmin_
//(для расщепления смеси)
void SVariate2 (TDoubleArray &X1, TDoubleArray &FF,
                double m1, double s1, double m2, double s2, double q1,
                double _Rmin_, int ind, int ind1)
{
  double sstep = s2 * step_size / 100;

  double _Rmin = _Rmin_,
         _ss = s2,
         _dj = 0, _Rm;
Again1SV2:
  _Rm = RKrit(X1, FF, m1, s1, m2, s2 - _dj * sstep, q1);
  if (_Rm <= _Rmin) {
    _Rmin = _Rm;
    _ss = s2 - _dj * sstep;
    _dj = _dj + 1;
    if (s2 - _dj * sstep > 0) goto Again1SV2;
  }
  ProgressInc();

  double Rmin_ = _Rmin_,
         ss_ = s2,
         dj_ = 0, Rm_;
Again2SV2:
  Rm_ = RKrit(X1, FF, m1, s1, m2, s2 + dj_ * sstep, q1);
  if (Rm_ <= Rmin_) {
    Rmin_ = Rm_;
    ss_ = s2 + dj_ * sstep;
    dj_ = dj_ + 1;
    if (s2 + dj_ * sstep > 0) goto Again2SV2;
  }
  ProgressInc();

  Rmin[ind][ind1]     = _Rmin;
  Rmin[ind][ind1 + 1] = Rmin_;

  ss2[ind1]     = _ss;
  ss2[ind1 + 1] = ss_;
}
//---------------------------------------------------------------------------
//Производит вариацию m2 при заданных остальных параметрах смеси с занесением получаемых
//параметров в массивы mm1, ss1, mm2, ss2, а отклонений от эмпирич. ИФР в Rmin, при этом
//вариация осуществляется при условии уменьшения RKrit. После нахождения наилучших
//значений по обе стороны от начального, в них производится вариация s2.
//(для расщепления смеси)
void MVariate2 (TDoubleArray &X1, TDoubleArray &FF,
                double m1, double s1, double m2, double s2, double q1, int ind)
{
  long NN = X1.Length;
  int i, j;

  j = 0;
  for (i = 1; i < NN; i++)
    if (X1[i] > m2) {
      j = i - 1;
      break;
    }

  double Rmin0 = RKrit(X1, FF, m1, s1, m2, s2, q1);
  double _Rmin = Rmin0,
         _mm = m2,
         _dj = 0, _Rm;
Again1MV2:
  _Rm = RKrit(X1, FF, m1, s1, X1[j - _dj], s2, q1);
  if (_Rm <= _Rmin) {
    _Rmin = _Rm;
    _mm = X1[j - _dj];
    _dj = _dj + 1;
    if (j - _dj >= 0) goto Again1MV2;
  }
  ProgressInc();

  double Rmin_ = Rmin0,
         mm_ = m2,
         dj_ = 0, Rm_;
Again2MV2:
  Rm_ = RKrit(X1, FF, m1, s1, X1[j + dj_ + 1], s2, q1);
  if (Rm_ <= Rmin_) {
    Rmin_ = Rm_;
    mm_ = X1[j + dj_ + 1];
    dj_ = dj_ + 1;
    if (j + dj_ + 1 < NN) goto Again2MV2;
  }
  ProgressInc();

  mm2[0] = m2;
  ss2[0] = s2;
  Rmin[ind][0] = Rmin0;

  mm2[1] = _mm;
  mm2[2] = _mm;
  mm2[3] = mm_;
  mm2[4] = mm_;

  SVariate2(X1, FF, m1, s1, _mm, s2, q1, _Rmin, ind, 1);
  SVariate2(X1, FF, m2, s1, mm_, s2, q1, Rmin_, ind, 3);
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
void LineApprox(TDoubleArray &X, TDoubleArray &Y, double *b)
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
    XYsr += (X[i] - Xsr) *  Y[i];
    XXsr += (X[i] - Xsr) * (X[i] - Xsr);
  }

  b[1] = XYsr / XXsr;
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
//} //namespace
#pragma package(smart_init)


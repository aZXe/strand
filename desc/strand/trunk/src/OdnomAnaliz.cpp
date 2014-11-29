//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <Grids.hpp>
#include <stdlib.h>
#include <values.h>
#include "GridArray.h"
#include "MyStatFunctions.h"
#include "MatrixFunctions.h"
//#include "MatrixDisplay.h"
#include "Graphing.h"
#include "Distributions.h"
#include "Progress.h"
#include "OdnomAnaliz.h"
//---------------------------------------------------------------------------
#define rnd     (double(rand()) / RAND_MAX)
#define N_MC    100
//---------------------------------------------------------------------------
TArray *AllReport;
int _plot, npplot;
//---------------------------------------------------------------------------
extern TArray *Array;
extern TStringGrid *_RGrid;
extern double Rmin[5][5];
extern double mm1[5], ss1[5], mm2[5], ss2[5];
extern double Report[70];
//---------------------------------------------------------------------------
void EmpiricParameters (TDoubleArray &X, TDoubleArray &W);
bool Normal (TDoubleArray &X, TDoubleArray &W, TDoubleArray &X1,
             TDoubleArray &FF, TDoubleArray &f, double *e);
bool LogNormal (TDoubleArray &X, TDoubleArray &W, double *e);
void JadrApprox (int nomer, TDoubleArray &X,  TDoubleArray &W, TDoubleArray &X1,
                 TDoubleArray &FF, TDoubleArray &f, double *e);
bool isSmes1 (TDoubleArray &X,  TDoubleArray &W, TDoubleArray &X1, TDoubleArray &FF,
              TDoubleArray &Q, TDoubleArray &QA, double &vpadina, int cq);
bool Rascheplen1 (int nomer, TDoubleArray &X, TDoubleArray &W, TDoubleArray &X1,
                  TDoubleArray &FF, double vpadina, double *result);
bool isSmes2 (TDoubleArray &QA, int &jmax, int &j1max, int &jmax2, int cq);
bool Rascheplen2 (int nomer, TDoubleArray &X1, TDoubleArray &FF, TDoubleArray &Q,
                  int j1max, int jmax2, int cq, double *result);
bool BoxCox (int nomer, TDoubleArray &X, TDoubleArray &W, double &lam);
//---------------------------------------------------------------------------
void OdnomAnaliz (int nomer, TDoubleArray &X, TDoubleArray &W)
{
  TDoubleArray X1, FF, f, Q, QA;
  double e[2] = {0, 1}, vpadina, result[6];
  double lam;
  int jmax, j1max, jmax2;
  int cq = CountQuantiles(X.Length);
  long i, n;
  int plot1;
  char buf[30];

  for (i = 2; i < 70; i++) Report[i] = MISSING_DATA;
  Report[0] = nomer;
  Report[1] = X.Length;

  EmpiricParameters(X, W);

  ProgressSet(0);
  ProgressCaption((AnsiString)itoa(nomer, buf, 10) + " - Ядерная аппроксимация");
  ProgressShow();
  JadrApprox(nomer, X, W, X1, FF, f, e);
  plot1 = _plot;
  ProgressSet(0);
  ProgressCaption((AnsiString)itoa(nomer, buf, 10) + " - Проверка на нормальность");
  if (Normal(X, W, X1, FF, f, e) == TRUE) {
    ProgressSet(0);
    ProgressCaption((AnsiString)itoa(nomer, buf, 10) + " - Ядерная аппроксимация");
    JadrApprox(nomer, X, W, X1, FF, f, e);
    ProgressHide();
  }
  else {
    ProgressSet(0);
    ProgressCaption((AnsiString)itoa(nomer, buf, 10) + " - Проверка на логнормальность");
    if (LogNormal(X, W, e) == TRUE) {
      ProgressSet(0);
      ProgressCaption((AnsiString)itoa(nomer, buf, 10) + " - Ядерная аппроксимация");
      JadrApprox(nomer, X, W, X1, FF, f, e);
      ProgressHide();
    }
    else {
      if (isSmes1(X, W, X1, FF, Q, QA, vpadina, cq) == TRUE) {
        ProgressSet(0);
        ProgressCaption((AnsiString)itoa(nomer, buf, 10) + " - Ядерная аппроксимация");
        JadrApprox(nomer, X, W, X1, FF, f, e);
        ProgressSet(0);
        ProgressCaption((AnsiString)itoa(nomer, buf, 10) + " - Расщепление разнесенной смеси");
        if (Rascheplen1(nomer, X, W, X1, FF, vpadina, result) == TRUE) goto NextVar;
        ProgressHide();
      }
      if (isSmes2(QA, jmax, j1max, jmax2, cq) == TRUE) {
        ProgressSet(0);
        ProgressCaption((AnsiString)itoa(nomer, buf, 10) + " - Ядерная аппроксимация");
        JadrApprox(nomer, X, W, X1, FF, f, e);
        ProgressSet(0);
        ProgressCaption((AnsiString)itoa(nomer, buf, 10) + " - Расщепление неразнесенной смеси");
        if (Rascheplen2(nomer, X1, FF, Q, j1max, jmax2, cq, result) == TRUE) goto NextVar;
        ProgressHide();
      }
      ProgressSet(0);
      ProgressCaption((AnsiString)itoa(nomer, buf, 10) + " - Подбор преобразования");
      BoxCox(nomer, X, W, lam);
    }
  }

NextVar :

  ProgressHide();
//  SaveGraph(plot1, "graph\\" + IntToStr(nomer) + "_0.bmp");
  DeleteGraph(plot1);
  n = AllReport->NCases;
  for (i = 1; i <= AllReport->NVars; i++)
    AllReport->Cell[i][n] = Report[i - 1];
  AllReport->NCases = AllReport->NCases + 1;

}
//---------------------------------------------------------------------------
void InitOdnomAnaliz (void)
{
  InitGraph();
  for (int i = 0; i < 70; i++) Report[i] = MISSING_DATA;
  randomize();

  AllReport = new TArray(_RGrid, 70, 1);

  AllReport->VarName[1] = "NOMER";
  AllReport->VarName[2] = "COUNT";
  AllReport->VarName[3] = "COUNTMOD";
  AllReport->VarName[4] = "Q1";
  AllReport->VarName[5] = "Q2";
  AllReport->VarName[6] = "LAMBDA";
  AllReport->VarName[7] = "SRARIFM";
  AllReport->VarName[8] = "SRKVOTKL";
  AllReport->VarName[9] = "E_MED";
  AllReport->VarName[10] = "E_SRGEOM";
  AllReport->VarName[11] = "E_SGOTKL";
  AllReport->VarName[12] = "E_VARIAC";
  AllReport->VarName[13] = "E_ASIMM";
  AllReport->VarName[14] = "E_EKSC";
  AllReport->VarName[15] = "MIN";
  AllReport->VarName[16] = "MAX";
  AllReport->VarName[17] = "E_Q01";
  AllReport->VarName[18] = "E_Q05";
  AllReport->VarName[19] = "E_Q10";
  AllReport->VarName[20] = "E_Q15";
  AllReport->VarName[21] = "E_Q20";
  AllReport->VarName[22] = "E_Q25";
  AllReport->VarName[23] = "E_Q30";
  AllReport->VarName[24] = "E_Q35";
  AllReport->VarName[25] = "E_Q40";
  AllReport->VarName[26] = "E_Q45";
  AllReport->VarName[27] = "E_Q50";
  AllReport->VarName[28] = "E_Q55";
  AllReport->VarName[29] = "E_Q60";
  AllReport->VarName[30] = "E_Q65";
  AllReport->VarName[31] = "E_Q70";
  AllReport->VarName[32] = "E_Q75";
  AllReport->VarName[33] = "E_Q80";
  AllReport->VarName[34] = "E_Q85";
  AllReport->VarName[35] = "E_Q90";
  AllReport->VarName[36] = "E_Q95";
  AllReport->VarName[37] = "E_Q99";
  AllReport->VarName[38] = "T_MO";
  AllReport->VarName[39] = "T_SKO";
  AllReport->VarName[40] = "T_MED";
  AllReport->VarName[41] = "T_SRGEOM";
  AllReport->VarName[42] = "T_SGOTKL";
  AllReport->VarName[43] = "T_VARIAC";
  AllReport->VarName[44] = "T_ASIMM";
  AllReport->VarName[45] = "T_EKSC";
  AllReport->VarName[46] = "T_Q01";
  AllReport->VarName[47] = "T_Q05";
  AllReport->VarName[48] = "T_Q10";
  AllReport->VarName[49] = "T_Q15";
  AllReport->VarName[50] = "T_Q20";
  AllReport->VarName[51] = "T_Q25";
  AllReport->VarName[52] = "T_Q30";
  AllReport->VarName[53] = "T_Q35";
  AllReport->VarName[54] = "T_Q40";
  AllReport->VarName[55] = "T_Q45";
  AllReport->VarName[56] = "T_Q50";
  AllReport->VarName[57] = "T_Q55";
  AllReport->VarName[58] = "T_Q60";
  AllReport->VarName[59] = "T_Q65";
  AllReport->VarName[60] = "T_Q70";
  AllReport->VarName[61] = "T_Q75";
  AllReport->VarName[62] = "T_Q80";
  AllReport->VarName[63] = "T_Q85";
  AllReport->VarName[64] = "T_Q90";
  AllReport->VarName[65] = "T_Q95";
  AllReport->VarName[66] = "T_Q99";
  AllReport->VarName[67] = "T_MO1";
  AllReport->VarName[68] = "T_SKO1";
  AllReport->VarName[69] = "T_MO2";
  AllReport->VarName[70] = "T_SKO2";
}
//---------------------------------------------------------------------------
void DeinitOdnomAnaliz (void)
{
  AllReport->SaveStaFile("reports.sta");
  delete AllReport;
}
//---------------------------------------------------------------------------
void EmpiricParameters (TDoubleArray &X, TDoubleArray &W)
{
  long i, N = X.Length;
  double s, j, jj;

  VectorDualSort(X, W, SORT_ASCENDING);
  Report[14] = X[0];
  Report[15] = X[N - 1];

  s = 0;
  for (i = 0; i < N; i++) s += X[i];
  s /= N;
  Report[6] = s;

  j = 0;
  for (i = 0; i < N; i++) j += (X[i] - s) * (X[i] - s);
//  j = sqrt(j / (N - 1));
  Report[7] = sqrt(j / (N - 1));

  if (fabs(s) > 1e-5) Report[11] =  sqrt(j / (N - 1)) * 100 / s;

//  j = 0;
//  for (i = 0; i < N; i++) j += (X[i] - s) * (X[i] - s);
//  j := (j / N) ^ 1.5;
  jj = 0;
  for (i = 0; i < N; i++) jj += (X[i] - s) * (X[i] - s) * (X[i] - s);
  jj /= N;
  Report[12] = jj / sqrt(j * j * j / (N *  N * N));

//  j = 0;
//  for (i = 0; i < N; i++) j += (X[i] - s) * (X[i] - s);
//  j := (j / N) ^ 2;
  jj = 0;
  for (i = 0; i < N; i++) jj += (X[i] - s) * (X[i] - s) * (X[i] - s) * (X[i] - s);
  jj /= N;
  Report[13] = (jj * N * N / (j * j)) - 3;

  if (X[0] > delta) {
    s = 0;
    for (i = 0; i < N; i++) s +=log(X[i]);
    s /= N;
    Report[9] =  exp(s);

    j = 0;
    for (i = 0; i < N; i++) j += (log(X[i]) - s) * (log(X[i]) - s);
    j = sqrt(j / N);
    Report[10] = exp(j);
  }
}
//---------------------------------------------------------------------------
bool Normal (TDoubleArray &X, TDoubleArray &W, TDoubleArray &X1,
             TDoubleArray &FF, TDoubleArray &f, double *e)
{
//  TDoubleArray X1, FF, f;
  long N = X.Length;
  double eps;
  bool i;

  R(X, W, 0, N, e);

  JadrParameters(X, X1, FF, f, eps, TRUE);

  if (N <= 15) i = Hipoteza(X1, FF, IDSLABAJA, 3, e[0], e[1]);
  else if (N <= 30) i = Hipoteza(X1, FF, IDSLABAJA, 2, e[0], e[1]);
       else if (N <= 100) i = Hipoteza(X1, FF, IDSLABAJA, 1, e[0], e[1]);
            else i = Hipoteza(X1, FF, IDSILNAJA, 1, e[0], e[1]);
 
  if (i == TRUE ){
    Quantiles(NULL, e[0], e[1]);
//      Normalize(Result, Vars(vari), QQ(20), QQ(21));
    Report[2]  = 1;
    Report[5]  = 1;
    Report[37] = e[0];
    Report[38] = e[1];
    Report[43] = 0;
    Report[44] = 0;
    if (fabs(e[0]) > 1e-5) Report[42] = e[1] * 100 / e[0];
  }

  return i;
}
//---------------------------------------------------------------------------
bool LogNormal (TDoubleArray &X, TDoubleArray &W, double *e)
{
  TDoubleArray wX;
  TDoubleArray X1, FF, f;
  long N = X.Length;
  double eps;
  bool i;

  wX.Length = N;
  for (long j = 0; j < N; j++)
    if (X[j] > 1e-10) wX[j] = log(X[j]);
    else return FALSE;

  R(wX, W, 0, N, e);
//  if (e[0] < 1e-10) e[0] = 1e-10;

  JadrParameters(wX, X1, FF, f, eps, FALSE);

  if (N <= 15) i = Hipoteza(X1, FF, IDSLABAJA, 3, e[0], e[1]);
  else if (N <= 30) i = Hipoteza(X1, FF, IDSLABAJA, 2, e[0], e[1]);
       else if (N <= 100) i = Hipoteza(X1, FF, IDSLABAJA, 1, e[0], e[1]);
            else i = Hipoteza(X1, FF, IDSILNAJA, 1, e[0], e[1]);
 
  if (i == TRUE ){
    Quantiles(NULL, e[0], e[1]);
//      Normalize(Result, Vars(vari), QQ(20), QQ(21));
                                                      //     __
    Report[2]  = 1;                                   //    //\\
    Report[5]  = 0;                                   //       ||
    Report[37] = e[0];                                //      //
    Report[38] = e[1];                                //     //
    Report[40] = exp(e[0]);                           //     ||
    Report[41] = exp(e[1]);                           //     O
    if (fabs(e[0]) > 1e-5) Report[42] = e[1] * 100 / e[0];
    Report[43] = sqrt(exp(e[1] * e[1]) - 1) * (exp(e[1] * e[1]) + 2);
    Report[44] = (exp(e[1] * e[1]) - 1) * (exp(3 * e[1] * e[1]) + 3 * exp(2 * e[1] * e[1]) + 6 * exp(e[1] * e[1]) + 6);
  }

  return i;
}
//---------------------------------------------------------------------------
void JadrApprox (int nomer, TDoubleArray &X,  TDoubleArray &W,
                 TDoubleArray &X1, TDoubleArray &FF, TDoubleArray &f, double *e)
{
  TDoubleArray F_1;
  long N = X.Length, c = 2 * N, i;
  double eps;

  JadrParameters(X, X1, FF, f, eps, FALSE);

  F_1 = FF.Copy();
  long LnN = (long)floor(log((double)N) / 2);
  for (i = 0; i < LnN; i++) F_1[i] = 0;
  for (i = LnN; i < c - LnN - 1; i++) {
    F_1[i] = VectorSum(f, i - LnN, 2 * LnN + 1);
    F_1[i] /= 2 * LnN + 1;
  }
  for (i = c - LnN - 1; i < c; i++) F_1[i] = 0;

  _plot = NewGraph(X1, F_1, clBlue, LINEPLOT,
                   "Ядерная аппроксимация|функции плотности распределения",
                   Array->VarName[nomer].c_str(), "P");
  SaveGraph(_plot, "graph\\" + IntToStr(nomer) + "_1.bmp");

  if (Report[5] == 1)
    for (i = 0; i < c; i++)
      F_1[i] = dNormal(X1[i], e[0], e[1]);
  else if (Report[5] == 0)
         for (i = 0; i < c; i++)
           F_1[i] = dLogNormal(X1[i], e[0], e[1]);
       else return;

  AddGraph(_plot, X1, F_1, clRed, LINEPLOT);
  SaveGraph(_plot, "graph\\" + IntToStr(nomer) + "_2.bmp");
  DeleteGraph(_plot);
}
//---------------------------------------------------------------------------
bool isSmes1 (TDoubleArray &X,  TDoubleArray &W, TDoubleArray &X1, TDoubleArray &FF,
              TDoubleArray &Q, TDoubleArray &QA, double &vpadina, int cq)
{
  TDoubleArray F_1;
  long N = X.Length, c = 2 * N;
  int i, f_f;
  long ci, ii, jj, j;
  double t;
  long j1max, jmax2, jmin;
  double a_max, a_1, a_2;

  Q.Length = cq + 1;

  ci = 0;
  for (i = 0; i < cq + 1; i++) {
    t = (double)i / cq;
    while (t > FF[ci]) ci++;
    Q[i] = X1[ci];
  }

  QA.Length = cq - 1;

  ii = 0;
  jj = 0;
  for (i = 0; i < cq - 1; i++) {
  R2:
    if (Q[i] > X1[ii]) {
      ii++;
      if (ii >= c) break;
      goto R2;
    }

/*    if (ii > jj) */ jj = ii;

    if (jj >= c) goto R4;
  R3:
    if (X1[jj] <= Q[i + 2]) {
      jj++;
      if (jj >= c) {
        jj = c;
        goto R4;
      }
      goto R3;
    }

  R4:
    f_f = 0;

    for (j = 1; j < N - 1; j++)
      if (X[j] != X[0] && X[j] != X[N - 1]) f_f = 1;

   if (f_f == 0) return FALSE;

   if (X1[ii] == X1[jj - 1])
     if (i == 0) QA[i] = 0;
     else QA[i] = QA[i - 1];
   else QA[i] = GetA(X1, ii, jj - 1);
  }

  F_1.Length = cq - 1; 
 
  for (i = 1; i < cq - 2; i++) {
    F_1[i] = VectorSum(QA, i - 1, 3);
    F_1[i] /= 3;
  }

  j1max = 0;
  for (i = 1; i < cq - 1; i++)
    if (F_1[i] >= F_1[j1max]) j1max = i;
    else break;

  jmax2 = cq - 2;
  for (i = cq - 3; i >= 0; i--)
    if (F_1[i] >= F_1[jmax2]) jmax2 = i;
    else break;

  jmin = j1max;
  for (i = j1max; i <= jmax2; i++)
    if (F_1[i] < F_1[jmin]) jmin = i;

  if (jmin == 1 || jmin == cq - 3) return FALSE;

  j1max = 1;
  for (i = 1; i < jmin; i++)
    if (QA[i] - QA[i + 1] > QA[j1max] - QA[j1max + 1]) j1max = i;

  jmax2 = jmin;
  for (i = jmin; i < cq - 2; i++)
    if (QA[i + 1] - QA[i] > QA[jmax2 + 1] - QA[jmax2]) jmax2 = i;

  a_1 = VectorSum(QA, 0, j1max);
  a_1 /= j1max;

  a_max = VectorSum(QA, j1max, jmax2 - j1max);
  a_max /= jmax2 - j1max;

  a_2 = VectorSum(QA, jmax2, cq - 1 - jmax2);
  a_2 /= cq - 1 - jmax2;

  if (a_max > a_1 || a_max > a_2) return FALSE;

  if (fabs(a_1 - a_2) < min(a_1 - a_max, a_2 - a_max) / 2) {
    vpadina = Q[jmin + 1];
    return TRUE;
  }

  vpadina = Q[jmin + 1];
  return TRUE; // <-------------- Спросить пользователя
}
//---------------------------------------------------------------------------
bool Rascheplen1 (int nomer, TDoubleArray &X, TDoubleArray &W, TDoubleArray &X1,
                  TDoubleArray &FF, double vpadina, double *result)
{
  TDoubleArray rf;
  long N = X.Length, c = 2 * N;
  long i;
  int j, imin, jmin;
  double q1, res[2], ar[6];

  for (i = 0; i < c; i++)
    if (X1[i] == vpadina) break;

  q1 = FF[i];

  R(X, W, 0, (long)floor(q1 * N), res);
  ar[0] = res[0];
  ar[1] = res[1];
  ar[2] = q1;

  R(X, W, (long)floor(q1 * N), N - (long)floor(q1 * N), res);
  ar[3] = res[0];
  ar[4] = res[1];
  ar[5] = 1 - q1;


  progress_step = 100. / 36;
  MVariate2(X1, FF, ar[0],  ar[1],  ar[3], ar[4], ar[2], 0);
  MVariate1(X1, FF, ar[0],  ar[1],  ar[3], ar[4], ar[2], 0);
  MVariate2(X1, FF, mm1[1], ss1[1], ar[3], ar[4], ar[2], 1);
  MVariate2(X1, FF, mm1[2], ss1[2], ar[3], ar[4], ar[2], 2);
  MVariate2(X1, FF, mm1[3], ss1[3], ar[3], ar[4], ar[2], 3);
  MVariate2(X1, FF, mm1[4], ss1[4], ar[3], ar[4], ar[2], 4);
  ProgressSet(100);

  imin = 0;
  jmin = 0;
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      if (Rmin[i][j] < Rmin[imin][jmin]) {
        imin = i;
        jmin = j;
      }

  result[0] = mm1[imin];
  result[1] = ss1[imin];
  result[2] = ar[2];
  result[3] = mm2[jmin];
  result[4] = ss2[jmin];
  result[5] = ar[5];

  rf.Length = c;

  for (i = 0; i < c; i++)
    rf[i] = result[2] * dNormal(X1[i], result[0], result[1]) +
            result[5] * dNormal(X1[i], result[3], result[4]);

  AddGraph(_plot, X1, rf, clRed, LINEPLOT);
  SaveGraph(_plot, "graph\\" + IntToStr(nomer) + "_2.bmp");
  DeleteGraph(_plot);

  if (N <= 15) i = Smesi_Hipoteza(X1, FF, IDSLABAJA, 3, mm1[imin], ss1[imin], mm2[jmin], ss2[jmin], ar[2]);
  else if (N <= 30) i = Smesi_Hipoteza(X1, FF, IDSLABAJA, 2, mm1[imin], ss1[imin], mm2[jmin], ss2[jmin], ar[2]);
       else if (N <= 100) i = Smesi_Hipoteza(X1, FF, IDSLABAJA, 1, mm1[imin], ss1[imin], mm2[jmin], ss2[jmin], ar[2]);
            else i = Smesi_Hipoteza(X1, FF, IDSILNAJA, 1, mm1[imin], ss1[imin], mm2[jmin], ss2[jmin], ar[2]);

  if (i == FALSE) return FALSE;
  else {
    Report[2]  = 2;
    Report[66] = result[0];
    Report[67] = result[1];
    Report[3]  = result[2];
    Report[68] = result[3];
    Report[69] = result[4];
    Report[4]  = result[5];
    Report[37] = result[2] * result[0] + result[5] * result[3];
    SmesiQuantiles(X1, FF, NULL, result[0], result[1], result[3], result[4],  result[2]);
//    Normalize(Result, Vars(vari), QQ(20), QQ(21));
  }

  return TRUE;
}
//---------------------------------------------------------------------------
bool isSmes2 (TDoubleArray &QA, int &jmax, int &j1max, int &jmax2, int cq)
{
  int i;
  double a_max, a_1, a_2;

//  MatrixDisplay(QA, "QA");
//  
  jmax = 1;
  for (i = 1; i < cq - 2; i++)
    if (QA[i - 1] + QA[i] + QA[i + 1] > QA[jmax - 1] + QA[jmax] + QA[jmax + 1])
      jmax = i;

  if (jmax == 1 || jmax == 2 || jmax == cq - 3 || jmax == cq - 2)
    return FALSE;

  j1max = 1;
  for (i = 1; i < jmax - 2; i++)
    if (fabs(QA[i + 1] - QA[i - 1]) > fabs(QA[j1max + 1] - QA[j1max - 1])) j1max = i;

  jmax2 = jmax + 1;
  for (i = jmax + 1; i < cq - 2; i++)
    if (fabs(QA[i - 1] - QA[i + 1]) > fabs(QA[jmax2 - 1] - QA[jmax2 + 1])) jmax2 = i;

  a_1 = VectorSum(QA, 0, j1max);
  a_1 /= j1max;

  a_max = VectorSum(QA, j1max, jmax2 - j1max);
  a_max /= jmax2 - j1max;

  a_2 = VectorSum(QA, jmax2, cq - 2 - jmax2);
  a_2 /= cq - 2 - jmax2;

  if (a_max < a_1 || a_max < a_2) return FALSE;

  if (fabs(a_1 - a_2) < min(a_max - a_1, a_max - a_2) / 2) return TRUE;

  return TRUE; // <-------------- Спросить пользователя
}
//---------------------------------------------------------------------------
bool Rascheplen2 (int nomer, TDoubleArray &X1, TDoubleArray &FF, TDoubleArray &Q,
                  int j1max, int jmax2, int cq, double *result)
{
  TDoubleArray rf;
  int i, j, ii, jj, imin;
  long c = X1.Length, N = c / 2;
  double _m1, m1_, _m2, m2_, _s1, s1_, _s2, s2_, _q1, q1_;
  double m1, m2, s1, s2, q1, q2;
  double Res1[6][9];
  double minR, m1min, m2min, s1min, s2min, _R_;

  progress_step = 100. / (3 * 2 * 9 * N_MC);
  for (ii = 1; ii < 4; ii++) {
    _m2 = _m1 = Q[j1max + 1] + 0.25 * fabs(Q[jmax2 + 1] - Q[j1max + 1]);
    m2_ = m1_ = Q[jmax2 + 1] - 0.25 * fabs(Q[jmax2 + 1] - Q[j1max + 1]);

    _s1 = (Q[jmax2 + 0] - Q[j1max + 0]) / 4;
    s1_ = (Q[jmax2 + 0] - Q[j1max + 0]) / 2;

    _s2 = (Q[cq - 1 + 0] - Q[1 + 0]) / 4;
    s2_ = (Q[cq - 1 + 0] - Q[1 + 0]) / 2;

    _q1 = 0.1;
    q1_ = 0.9;

    for (jj = 0; jj < 2; jj++) {
 //     q1 = _q1;
      for (i = 0; i < 9; i++) {
        q1 = _q1 + i * (q1_ - _q1) / 8;
        minR = MAXDOUBLE;
        for (j = 1; j <  N_MC; j++) {
//          m1 = rnd * (m1_ - _m1) + _m1;
//          m2 = rnd * (m2_ - _m2) + _m2;
//          s1 = rnd * (s1_ - _s1) + _s1;
//          s2 = rnd * (s2_ - _s2) + _s2;

          _R_ = RKrit(X1, FF, m1, s1, m2, s2, q1);
          if (_R_ < minR) {
            minR  = _R_;
            m1min = m1;
            m2min = m2;
            s1min = s1;
            s2min = s2;
          }
          ProgressInc();
        }

        Res1[0][i] = m1min;        Res1[1][i] = s1min;
        Res1[2][i] = m2min;        Res1[3][i] = s2min;
        Res1[4][i] = minR;         Res1[5][i] = q1;
      }

      imin = 0;
      for (i = 1; i < 9; i++)
        if (Res1[4][i] < Res1[4][imin]) imin = i;

      m1 = Res1[0][imin];
      s1 = Res1[1][imin];
      m2 = Res1[2][imin];
      s2 = Res1[3][imin];
      q1 = Res1[5][imin];
      q2 = 1 - q1;

      if (imin == 8) {
        _m1 = min(Res1[0][7], Res1[0][8]);
        m1_ = max(Res1[0][7], Res1[0][8]);
        _s1 = min(Res1[1][7], Res1[1][8]);
        s1_ = max(Res1[1][7], Res1[1][8]);
        _m2 = min(Res1[2][7], Res1[2][8]);
        m2_ = max(Res1[2][7], Res1[2][8]);
        _s2 = min(Res1[3][7], Res1[3][8]);
        s2_ = max(Res1[3][7], Res1[3][8]);
        _q1 = 0.8;
        q1_ = 0.9;
      }
      else if (imin == 0) {
             _m1 = min(Res1[0][0], Res1[0][1]);
             m1_ = max(Res1[0][0], Res1[0][1]);
             _s1 = min(Res1[1][0], Res1[1][1]);
             s1_ = max(Res1[1][0], Res1[1][1]);
             _m2 = min(Res1[2][0], Res1[2][1]);
             m2_ = max(Res1[2][0], Res1[2][1]);
             _s2 = min(Res1[3][0], Res1[3][1]);
             s2_ = max(Res1[3][0], Res1[3][1]);
             _q1 = 0.1;
             q1_ = 0.2;
           }
           else {
             _m1 = min(Res1[0][imin - 1], min(Res1[0][imin], Res1[0][imin + 1]));
             m1_ = max(Res1[0][imin - 1], max(Res1[0][imin], Res1[0][imin + 1]));
             _s1 = min(Res1[1][imin - 1], min(Res1[1][imin], Res1[1][imin + 1]));
             s1_ = max(Res1[1][imin - 1], max(Res1[1][imin], Res1[1][imin + 1]));
             _m2 = min(Res1[2][imin - 1], min(Res1[2][imin], Res1[2][imin + 1]));
             m2_ = max(Res1[2][imin - 1], max(Res1[2][imin], Res1[2][imin + 1]));
             _s2 = min(Res1[3][imin - 1], min(Res1[3][imin], Res1[3][imin + 1]));
             s2_ = max(Res1[3][imin - 1], max(Res1[3][imin], Res1[3][imin + 1]));
             _q1 = imin * 0.1;
             q1_ = (imin + 2) * 0.1;
           }
    }

    ProgressSet(100);
    result[0] = m1;
    result[1] = s1;
    result[2] = q1;
    result[3] = m2;
    result[4] = s2;
    result[5] = q2;
 
    rf.Length = c; 
 
    for (i = 0; i < c; i++)
      rf[i] = q1 * dNormal(X1[i], m1, s1) + q2 * dNormal(X1[i], m2, s2);

    AddGraph(_plot, X1, rf, clRed << ii, LINEPLOT);
    SaveGraph(_plot, "graph\\" + IntToStr(nomer) + "_4.bmp");

    if (N <= 15) i = Smesi_Hipoteza(X1, FF, IDSLABAJA, 3, m1, s1, m2, s2, q1);
    else if (N <= 30) i = Smesi_Hipoteza(X1, FF, IDSLABAJA, 2, m1, s1, m2, s2, q1);
         else i = Smesi_Hipoteza(X1, FF, IDSLABAJA, 2, m1, s1, m2, s2, q1);

    if (i == TRUE) {
      Report[2 ] = 2;
      Report[66] = m1;
      Report[67] = s1;
      Report[3 ] = q1;
      Report[68] = m2;
      Report[69] = s2;
      Report[4 ] = q2;
      Report[37] = q1 * m1 + q2 * m2;
      SmesiQuantiles(X1, FF, NULL, m1, s1, m2, s2, q1);
//      Normalize(Result, Vars(vari), QQ(20), QQ(21));
      DeleteGraph(_plot);
      return TRUE;
    }

  }
  DeleteGraph(_plot);
  return FALSE;
}
//---------------------------------------------------------------------------
bool BoxCox (int nomer, TDoubleArray &X, TDoubleArray &W, double &lam)
{
  char buf[20];
  TDoubleArray workX, workY, X1_, FF_, f_, x, y;
  long N = X.Length;
  double lambda[2], Ri[12], e[2], b[2];
  double step1, minR, eps;
  int i, imin;

  VectorDualSort(X, W, SORT_ASCENDING);
  if (X[0] < delta) lambda[0] = -2;
  else lambda[0] = 2 * delta;
  lambda[1] = 5;
  progress_step = 100 / (10 * (floor((lambda[1] - lambda[0]) / 10) + 3));

//ik := 1;
  Ri[0] = R_BC(X, W, 1);

  do {
    step1 = (lambda[1] - lambda[0]) / 10;
    for (i = 0; i < 11; i++) {
      Ri[i + 1] = R_BC(X, W, lambda[0] + i * step1);
      ProgressInc();
    }

    minR = Ri[1];
    imin = 1;
    for (i = 1; i < 12; i++)
      if (minR > Ri[i]) {
        minR = Ri[i];
        imin = i;
      }

    lambda[0] += (imin - 1.5) * step1;
    if (X[0] < delta && lambda[0] <= delta)
      lambda[0] = 2 * delta;
    lambda[1] = lambda[0] + step1;

  //ik := ik + 1;
  } while (step1 >= 0.01);
  ProgressSet(100);

  if (Ri[0] <= minR) {
    lambda[0] = 1;
    lambda[1] = 1;
  }

//Normal probability plot of results
  lam = (lambda[0] + lambda[1]) / 2;
  minR = R_BC(X, W, lam);

  workX = X.Copy();
  BCTransform(workX, lam);
  VectorSort (workX, SORT_ASCENDING);
  workY = workX.Copy();
  VectorRank (workY, SORT_ASCENDING, RANK_MEAN);
  for (i = 0; i < N; i++)
    workY[i] = vNormal((3 * workY[i] - 1) / (3 * N + 1), 0, 1);

/*  npplot = NewGraph(workX, workY, clBlue, SCATTERPLOT,
    ("Нормальная вероятностная бумага|Lambda = " +
     (AnsiString)gcvt(lam,  4, buf) + "; R = " +
     (AnsiString)gcvt(minR, 4, buf)).c_str());*/
  npplot = NewGraph(workX, workY, clBlue, SCATTERPLOT,
    ("Нормальная вероятностная бумага|Lambda = " +
     (AnsiString)gcvt(lam,  4, buf) +
     "; R = " + (AnsiString)gcvt(minR, 4, buf) +
     " (Ro = " + (AnsiString)gcvt(Ri[0], 4, buf) + ")").c_str(),
     Array->VarName[i].c_str(), "V");
  LineApprox(workX, workY, b);
  x.Length = 2;         y.Length = 2;
  x[0] = workX[0];      y[0] = b[0] + b[1] * x[0];
  x[1] = workX[N - 1];  y[1] = b[0] + b[1] * x[1];
  AddGraph(npplot, x, y, clRed, LINEPLOT);
  SaveGraph(npplot, "graph\\" + IntToStr(nomer) + "_5.bmp");
  DeleteGraph(npplot);

  R(workX, W, 0, N, e);

  JadrParameters(workX, X1_, FF_, f_, eps, FALSE);

  if (N <= 15) i = Hipoteza(X1_, FF_, IDSLABAJA, 3, e[0], e[1]);
  else i = Hipoteza(X1_, FF_, IDSLABAJA, 2, e[0], e[1]);

  if (i == TRUE) {
    Report[2 ] = 1;
    Report[37] = e[0];
    Report[38] = e[1];
    Quantiles(NULL, e[0], e[1]);
  //  NormalizeBC(Result, Vars(vari), QQ(20), QQ(21), (lambda(1) + lambda(2)) / 2, delta);
    return TRUE;
  }

  return FALSE;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)

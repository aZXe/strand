//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <Grids.hpp>
#include <stdlib>
#include <values>
#include <algorithm>
#include <Math.hpp>  // for RandG
#include "GridArray.h"
#include "MyStatFunctions.h"
#include "MatrixFunctions.h"
#include "MatrixDisplay.h"
#include "Distributions.h"
#include "Progress.h"
#include "Config.h"
#include "Utils.h"
#include "OdnomAnaliz.h"
//---------------------------------------------------------------------------
#define rnd       ((double)rand() / RAND_MAX)
#define N_MC      100
#define jump      2
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
//const int size_rep = 71;
int plot, npplot, plot1, rplot;
int nomerDownQuantile, nomerUpQuantile;
double hip_res[2]; // Результат проверки гипотезы: 0 = alpha, 1 = add_2
TChartArray* Graphs;
AnsiString gNSR;
//---------------------------------------------------------------------------
extern TArray *AllReport;
extern TArray *Array;
extern TStringGrid *_RGrid;
extern double Rmin[5][5];
extern double mm1[5], ss1[5], mm2[5], ss2[5];
//extern double Report[size_rep];
extern TDoubleArray Report;//[size_rep];
extern int filter_num;
//---------------------------------------------------------------------------
void EmpiricParameters (TDoubleArray &X, TDoubleArray &W);
bool Normal (int n_var, TDoubleArray &X, TDoubleArray &W, TDoubleArray &W1, TDoubleArray &X1,
             TDoubleArray &FF, TDoubleArray &f, double *e);
bool LogNormal (int n_var, TDoubleArray &X, TDoubleArray &W, TDoubleArray &W1, double *e);
void JadrApprox (int n_var, TDoubleArray &X,  TDoubleArray &W, TDoubleArray &W1,
                 TDoubleArray &X1, TDoubleArray &FF, TDoubleArray &f, TDoubleArray &F_1,
                 TDoubleArray &F_2, double *e);
bool BoxCox (int n_var, TDoubleArray &X, TDoubleArray &W, TDoubleArray &W1, double &lam);
void Normalize (int n_var);
int NPPlot(int n_var, TDoubleArray &X, TDoubleArray &W);
int JAPlot(int n_var, TDoubleArray &X1, TDoubleArray &F_1, TDoubleArray &F_2,
           unsigned char position = 1);
void MakeFCorrect(TDoubleArray &F, TDoubleArray &X);
bool Rascheplen (int n_var, TDoubleArray &X, TDoubleArray &W, TDoubleArray &W1,
                 TDoubleArray &X1, TDoubleArray &FF, TDoubleArray &f);
void DeepSplitting (int n_var, TDoubleArray &X, TDoubleArray &W, double expectation1,
                    double dispersion1, double part1, double expectation2,
                    double dispersion2, double part2, double point);
void RemovalSubsample (TDoubleArray &X, TDoubleArray &R,  double expectation1,
                      double dispersion1, double part1, double expectation2,
                      double dispersion2, double part2, double pointSplitting, bool position);
void RemovalSubsample2 (TDoubleArray &X, TDoubleArray &R,  double expectation1,
                      double dispersion1, double part1, double expectation2,
                      double dispersion2, double part2, double pointSplitting, bool position);
//---------------------------------------------------------------------------
void OdnomAnaliz (int n_var, TDoubleArray &X, TDoubleArray &W, AnsiString nameStageRecursion)
{
  gNSR = nameStageRecursion;
  if (X.Length < 15) return;
  TDoubleArray X1, X1b, W1, FF, f, F_1, F_2, F_1b, F_2b, Q, QA;
  double e[2] = {0, 1}, vpadina, result[6];
  double lam;
  int jmax, j1max, jmax2;
  //  int cq = CountQuantiles(X.Length);
  long i, n;
  int plot1, npplot;
  char buf[30];
  bool flagMixture = true;

  switch (DownQuantile)
  {
    case 0  : nomerDownQuantile = 0; break;
    case 1  : nomerDownQuantile = 1; break;
    default : nomerDownQuantile = DownQuantile / 5 + 1;
  }
  switch (UpQuantile)
  {
    case 100: nomerUpQuantile = 0; break;
    case 99 : nomerUpQuantile = 21; break;
    default : nomerUpQuantile = UpQuantile / 5 + 1;
  }

  for (i = 2; i < size_rep; i++) Report[i] = MISSING_DATA;
  Report[0] = n_var;
  Report[1] = X.Length;
  // Расчёт эмпирических араметров
  EmpiricParameters(X, W);

  ProgressSet(0);
  ProgressCaption(AnsiString(n_var) + " - Ядерная аппроксимация");
  ProgressShow();
  JadrApprox(n_var, X, W, W1, X1, FF, f, F_1, F_2, e);

  // Постройка графиков
  JAPlot(n_var, X1, F_1, F_2, 0);

  npplot = NPPlot(n_var, X1, W1);
  // Сохранение графика нормальной вероятностной бумаги
  Graphs->SaveGraph(npplot, ConfigForm->eGraphsPath->Text + "\\" + AnsiString(n_var) + nameStageRecursion + "_n.wmf");
  plot1 = plot;
  ProgressSet(0);
  // Проверка на нормальность или логнормальность
  if (ConfigForm->rbNormal->Checked) {
    ProgressCaption(AnsiString(n_var) + " - Проверка на нормальность");
    if (Normal(n_var, X, W, W1, X1, FF, f, e) == true) {
      ProgressSet(0);
      Graphs->AddTitle(plot, SFormat("Normal=true, alpha=%lf, add_2=%lf", hip_res[0], hip_res[1]).c_str());
      ProgressCaption(AnsiString(n_var) + " - Ядерная аппроксимация");
      JadrApprox(n_var, X, W, W1, X1, FF, f, F_1, F_2, e);
      // Постройка графиков
      JAPlot(n_var, X1, F_1, F_2, 0);
      // Постройка графиков
      ProgressHide();
      flagMixture = false;                                                    // <----------------------
    }
    else
      Graphs->AddTitle(plot, SFormat("Normal=false, alpha=%lf, add_2=%lf", hip_res[0], hip_res[1]).c_str());
  }
  else {
    ProgressCaption(AnsiString(n_var) + " - Проверка на логнормальность");
    if (LogNormal(n_var, X, W, W1, e) == true) {
      ProgressSet(0);
      Graphs->AddTitle(plot, SFormat("LogNormal=true, alpha=%lf, add_2=%lf", hip_res[0], hip_res[1]).c_str());
      ProgressCaption(AnsiString(n_var) + " - Ядерная аппроксимация");
      JadrApprox(n_var, X, W, W1, X1, FF, f, F_1, F_2, e);
      // Постройка графиков
      JAPlot(n_var, X1, F_1, F_2, 0);
      // Постройка графиков
      ProgressHide();
      flagMixture = false;                                                    // <----------------------
    }
    else
      Graphs->AddTitle(plot, SFormat("LogNormal=false, alpha=%lf, add_2=%lf", hip_res[0], hip_res[1]).c_str());
  }
  // Расчёт смеси
  if (flagMixture) {
    flagMixture = false;
    ProgressSet(0);
    ProgressCaption(AnsiString(n_var) + " - Ядерная аппроксимация");
    JadrApprox(n_var, X, W, W1, X1, FF, f, F_1, F_2, e);
    // Постройка графиков
    rplot = JAPlot(n_var, X1, F_1, F_2, 1);
    // Постройка графиков
    ProgressSet(0);
    ProgressCaption(AnsiString(n_var) + " - Расщепление смеси");
//    X1b = X1.Copy();
//    F_1b = F_1.Copy();
//    F_2b = F_2.Copy();
    if (Rascheplen(n_var, X, W, W1, X1, FF, f) == true) {
//      rplot = JAPlot(n_var, X1b, F_1b, F_2b, 1);
      if (ConfigForm->cbGraphsShow->Checked) {
        Graphs->AddTitle(plot, SFormat("Smes=true, alpha=%lf, add_2=%lf", hip_res[0], hip_res[1]).c_str());
        Graphs->AddTitle(plot, "Аппроксимация эмпирического теоретическим",2);
        Graphs->AddTitle(plot, "Компоненты теоретического распределения",3);
      }
      //Предварительное сохранение
      flagMixture = true;
      double part1 = Report[3];
      double part2 = Report[4];
      double expectation1 = Report[66];
      double dispersion1 = Report[67];
      double expectation2 = Report[68];
      double dispersion2 = Report[69];
      double pointSplitting = Report[70];
      //Глубокое расщепление смеси на компоненты.
      DeepSplitting(n_var,X,W,expectation1,dispersion1,part1,expectation2,
                    dispersion2,part2,pointSplitting);
      //Конечная обработка параметров после расщепления всех смесей
    } else {
      Graphs->DeleteGraph(rplot);
      rplot = JAPlot(n_var, X1, F_1, F_2, 0);
    };
    if (!flagMixture) {
      //Подбор преобразования
      ProgressHide();
      if (ConfigForm->cbGraphsShow->Checked)
        Graphs->AddTitle(plot, SFormat("Smes=false, alpha=%lf, add_2=%lf", hip_res[0], hip_res[1]).c_str());
      ProgressSet(0);
      ProgressCaption(AnsiString(n_var) + " - Подбор преобразования");
      if (BoxCox(n_var, X, W, W1, lam) == true)
        if (ConfigForm->cbGraphsShow->Checked)
          Graphs->AddTitle(npplot, SFormat("BoxCox=true, alpha=%lf, add_2=%lf", hip_res[0], hip_res[1]).c_str());
      else
        if (ConfigForm->cbGraphsShow->Checked)
          Graphs->AddTitle(npplot, SFormat("BoxCox=false, alpha=%lf, add_2=%lf", hip_res[0], hip_res[1]).c_str());
    }
  }
//NextVar :

//  Graphs->DeleteGraph(npplot);
  ProgressHide();
//  SaveGraph(plot1, "graph\\" + IntToStr(nomer) + nameStageRecursion + "_0.wmf");
  if (!ConfigForm->cbGraphsShow->Checked) Graphs->DeleteGraph(plot1);
  n = AllReport->NCases;
  for (i = 1; i <= AllReport->NVars; i++)
    AllReport->Cell[i][n] = Report[i - 1];
  AllReport->NCases = AllReport->NCases + 1;
}
//---------------------------------------------------------------------------
void InitOdnomAnaliz (void)
{
  Graphs = new TChartArray();
  Graphs->InitGraph();
  Report.Length = size_rep;
  for (int i = 0; i < size_rep; i++) Report[i] = MISSING_DATA;
  randomize();

  AllReport = new TArray(_RGrid, size_rep, 1);

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
  AllReport->VarName[71] = "R_SMES";
}
//---------------------------------------------------------------------------
void DeinitOdnomAnaliz (void)
{
  AllReport->SaveStaFile("odan_rep.sta");
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
  Report[7] = sqrt(j / (N - 1));                         //???????????????????????????????????????????????????????????

  if (fabs(s) > 1e-5) Report[11] =  sqrt(j / (N - 1)) * 100 / s;

//  j = 0;
//  for (i = 0; i < N; i++) j += (X[i] - s) * (X[i] - s);
//  j := (j / N) ^ 1.5;
/*  jj = 0;
  for (i = 0; i < N; i++) jj += (X[i] - s) * (X[i] - s) * (X[i] - s);
  jj /= N;
  Report[12] = jj / sqrt(j * j * j / (N *  N * N));
*/
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
bool Normal (int n_var, TDoubleArray &X, TDoubleArray &W, TDoubleArray &W1, TDoubleArray &X1,
             TDoubleArray &FF, TDoubleArray &f, double *e)
{
//  TDoubleArray X1, FF, f;
  long N = X.Length;
  double eps;
  bool i;

  R(X, W, 0, N, e);

  JadrParameters(X, W, W1, X1, FF, f, eps, true);

  if (N <= 15) i = Hipoteza(X1, FF, IDSILNAJA, 3, e[0], e[1], hip_res);
  else if (N <= 30) i = Hipoteza(X1, FF, IDSILNAJA, 2, e[0], e[1], hip_res);
       else if (N <= 100) i = Hipoteza(X1, FF, IDSILNAJA, 1, e[0], e[1], hip_res);
            else i = Hipoteza(X1, FF, IDSILNAJA, 1, e[0], e[1], hip_res);

//  i = false; /* TODO : Убрать эту строку */

  if (i == true ){
    NewQuantiles(true, NULL, e[0], e[1]);
//      Normalize(Result, Vars(vari), QQ(20), QQ(21));
    Report[2]  = 1;
    Report[5]  = 1;
    Report[37] = e[0];
    Report[38] = e[1];
    Report[43] = 0;
    Report[44] = 0;
    if (fabs(e[0]) > 1e-5) Report[42] = e[1] * 100 / e[0];
    Normalize(n_var);
  }

  return i;
}
//---------------------------------------------------------------------------
bool LogNormal (int n_var, TDoubleArray &X, TDoubleArray &W, TDoubleArray &W1, double *e)
{
  TDoubleArray wX;
  TDoubleArray X1, FF, f;
  long N = X.Length;
  double eps;
  bool i;

  wX.Length = N;
  for (long j = 0; j < N; j++)
    if (X[j] > 1e-10) wX[j] = log(X[j]);
    else return false;

  R(wX, W, 0, N, e);
//  if (e[0] < 1e-10) e[0] = 1e-10;

  JadrParameters(wX, W, W1, X1, FF, f, eps, false);

  if (N <= 15) i = Hipoteza(X1, FF, IDSILNAJA, 3, e[0], e[1], hip_res);
  else if (N <= 30) i = Hipoteza(X1, FF, IDSILNAJA, 2, e[0], e[1], hip_res);
       else if (N <= 100) i = Hipoteza(X1, FF, IDSILNAJA, 1, e[0], e[1], hip_res);
            else i = Hipoteza(X1, FF, IDSILNAJA, 1, e[0], e[1], hip_res);

//  i = false; /* TODO : Убрать эту строку */

  if (i == true ){
    NewQuantiles(false, NULL, e[0], e[1]);
//      Normalize(Result, Vars(vari), QQ(20), QQ(21));

    Report[2]  = 1;
    Report[5]  = 0;
//    Report[37] = e[0];
//    Report[38] = e[1];
    Report[37] = exp(e[0] + e[1] * e[1] / 2);
    Report[38] = Report[37] * sqrt(exp(e[1] * e[1]) - 1); // Было = s
    Report[40] = exp(e[0]);
    Report[41] = exp(e[1]);
    if (fabs(e[0]) > 1e-5) Report[42] = e[1] * 100 / e[0];
    Report[43] = sqrt(exp(e[1] * e[1]) - 1) * (exp(e[1] * e[1]) + 2);
    Report[44] = (exp(e[1] * e[1]) - 1) * (exp(3 * e[1] * e[1]) + 3 * exp(2 * e[1] * e[1]) + 6 * exp(e[1] * e[1]) + 6);
    Normalize(n_var);
  }

  return i;
}
//---------------------------------------------------------------------------
void JadrApprox (int n_var, TDoubleArray &X,  TDoubleArray &W, TDoubleArray &W1,
                 TDoubleArray &X1, TDoubleArray &FF, TDoubleArray &f, TDoubleArray &F_1,
                 TDoubleArray &F_2, double *e)
{
//  TDoubleArray F_1;
  long N = X.Length, c = 2 * N, i;
  double eps;

  JadrParameters(X, W, W1, X1, FF, f, eps, false);

  F_1 = FF.Copy();
  long LnN = (long)floor(log(N) / 2);
  for (i = 0; i < LnN; i++) F_1[i] = 0;
  for (i = LnN; i < c - LnN - 1; i++) {
    F_1[i] = VectorSum(f, i - LnN, 2 * LnN + 1);
    F_1[i] /= 2 * LnN + 1;
  }
  for (i = c - LnN - 1; i < c; i++) F_1[i] = 0;

//  plot = Graphs->NewGraph(X1, F_1, clBlue, LINEPLOT,
//                  "Ядерная аппроксимация|функции плотности распределения",
//                  Array->VarName[n_var], "P");
//  Graphs->SaveGraph(plot, ConfigForm->eGraphsPath->Text + "\\" + AnsiString(n_var)+ gNSR + "_1.wmf");

  F_2 = F_1.Copy();
  if (Report[5] == 1) {
    for (i = 0; i < c; i++)
      F_2[i] = dNormal(X1[i], e[0], e[1]);
//    MakeFCorrect(F_1, X1);
  }
  else if (Report[5] == 0) {
         for (i = 0; i < c; i++)
           F_2[i] = dLogNormal(X1[i], e[0], e[1]);
//         MakeFCorrect(F_1, X1);
       }
       else return;

//  Graphs->AddGraph(plot, X1, F_2, clRed, LINEPLOT);
//  Graphs->SaveGraph(plot, ConfigForm->eGraphsPath->Text + "\\" + AnsiString(n_var) + gNSR + "_2.wmf");
//  if (!ConfigForm->cbGraphsShow->Checked) Graphs->DeleteGraph(plot);
}
//---------------------------------------------------------------------------
bool BoxCox (int n_var, TDoubleArray &X, TDoubleArray &W, TDoubleArray &W1, double &lam)
{
  char buf[20];
  TDoubleArray workX, workY, workW, X1_, FF_, f_, x, y;
  long N = X.Length;
  double lambda[2], Ri[12], e[2], b[2];
  double step1, minR, eps;
  int i, imin;

  VectorDualSort(X, W, SORT_ASCENDING);
//  if (X[0] < delta) lambda[0] = -2;
  if (X[0] > delta) lambda[0] = StrToFloat(ConfigForm->eBoxCoxDown->Text);
  else lambda[0] = 2 * delta;
  lambda[1] = StrToFloat(ConfigForm->eBoxCoxUp->Text);
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
  Report[5] = lam;

  workX = X.Copy();
  workW = W.Copy();
  BCTransform(workX, lam);
  VectorDualSort (workX, workW, SORT_ASCENDING);
  workY = workX.Copy();
  VectorRank (workY, SORT_ASCENDING, RANK_MEAN);
  for (i = 0; i < N; i++)
    workY[i] = vNormal((3 * workY[i] - 1) / (3 * N + 1), 0, 1);

/*  npplot = NewGraph(workX, workY, clBlue, SCATTERPLOT,
    ("Нормальная вероятностная бумага|Lambda = " +
     (AnsiString)gcvt(lam,  4, buf) + "; R = " +
     (AnsiString)gcvt(minR, 4, buf)).c_str());*/
  npplot = Graphs->NewGraph(workX, workY, clBlue, SCATTERPLOT,
    ("Нормальная вероятностная бумага|Lambda = " +
     (AnsiString)gcvt(lam,  4, buf) +
     "; R = " + (AnsiString)gcvt(minR, 4, buf) +
     " (Ro = " + (AnsiString)gcvt(Ri[0], 4, buf) + ")").c_str(),
     Array->VarName[n_var], "V");
  LineApprox(workX, workY, workW, b);
  x.Length = 2;         y.Length = 2;
  x[0] = workX[0];      y[0] = b[0] + b[1] * x[0];
  x[1] = workX[N - 1];  y[1] = b[0] + b[1] * x[1];
  Graphs->AddGraph(npplot, x, y, clRed, LINEPLOT);
  Graphs->SaveGraph(npplot, ConfigForm->eGraphsPath->Text + "\\" + AnsiString(n_var) + gNSR + "_5.wmf");
  if (!ConfigForm->cbGraphsShow->Checked) Graphs->DeleteGraph(npplot);

  R(workX, W, 0, N, e);

  JadrParameters(workX, W, W1, X1_, FF_, f_, eps, false);

  if (N <= 15) i = Hipoteza(X1_, FF_, IDSLABAJA, 3, e[0], e[1], hip_res);
  else i = Hipoteza(X1_, FF_, IDSLABAJA, 2, e[0], e[1], hip_res);

  if (i == true) {
    Report[2 ] = 1;
    Report[37] = e[0];
    Report[38] = e[1];
    NewQuantiles(true, NULL, e[0], e[1]);
  //  NormalizeBC(Result, Vars(vari), QQ(20), QQ(21), (lambda(1) + lambda(2)) / 2, delta);
    Normalize(n_var);
    return true;
  }

  Normalize(n_var);
  return false;
}
//---------------------------------------------------------------------------
void Normalize (int n_var)
{
  TDoubleArray NX;
  AnsiString name;
  double nomer = n_var; //номер признака
  int nnomer; //номер проногрмированного признака
  bool isT = (Report[45] != MISSING_DATA); //есть ли теоретические квантили?
  bool isNormalize = ConfigForm->cbNormalizingNormalize->Checked; // нормировать?
  bool isN = ConfigForm->cbNormalizingAddN->Checked; //добавлять N к имени?
  double Lambda = Report[5];
  double dq, uq; //"квантили" для нормировки
  int i;

  if (!isNormalize) return;
  if (isN) {
    name = "N" + (AnsiString)Array->VarName[nomer];
    if (name.Length() > 8) name.SetLength(8);
    nnomer = Array->VarByName(name);
    if (nnomer == 0) nnomer = Array->NVars + 1;
  }
  else {
    nnomer = nomer;
    name = Array->VarName[nomer];
  }

  NX = Array->GetVar(nomer);
  for (i = 0; i < NX.Length; i++)
    if (Array->Cell[filter_num][i + 1] == 0) NX[i] = MISSING_DATA;

  if (isT) {
    dq = (nomerDownQuantile) ? Report[44 + nomerDownQuantile] : Report[14];
    uq = (nomerUpQuantile) ? Report[44 + nomerUpQuantile] : Report[15];
  }
  else {
    dq = (nomerDownQuantile) ? Report[15 + nomerDownQuantile] : Report[14];
    uq = (nomerUpQuantile) ? Report[15 + nomerUpQuantile] : Report[15];
  }

  if (Lambda == 1 || Lambda == MISSING_DATA) {
    for (i = 0; i < NX.Length; i++)
      if (NX[i] != MISSING_DATA) NX[i] = (NX[i] - dq) / (uq - dq);
  }
  else {
    for (i = 0; i < NX.Length; i++) {
      if (NX[i] == MISSING_DATA) continue;
      if (fabs(Lambda) <= delta) NX[i] = log(NX[i]);
      else
        NX[i] = (exp(Lambda * log(fabs(NX[i]))) - 1) / Lambda; // <---------------- Модуль?
    }
    if (nomerDownQuantile == 0 || isT == false)
      dq = (fabs(Lambda) <= delta) ? log(dq) : (exp(Lambda * log(fabs(dq))) - 1) / Lambda;
    if (nomerUpQuantile == 0 || isT == false)
      uq = (fabs(Lambda) <= delta) ? log(uq) : (exp(Lambda * log(fabs(uq))) - 1) / Lambda;

    for (i = 0; i < NX.Length; i++)
      if (NX[i] != MISSING_DATA) NX[i] = (NX[i] - dq) / (uq - dq);
  }

  Array->SetVar(NX, nnomer, name);
}
//---------------------------------------------------------------------------
int NPPlot(int n_var, TDoubleArray &X, TDoubleArray &W)
{
  TDoubleArray workX, workY, workW, x, y;
  double b[2];
  int i;
  int N = X.Length, npplot;

  workX = X.Copy();
  if (ConfigForm->rbLogNormal->Checked) Log(workX);
  workW = W.Copy();
  VectorDualSort (workX, workW, SORT_ASCENDING);
  workY = workX.Copy();
  VectorRank (workY, SORT_ASCENDING, RANK_MEAN);
  for (i = 0; i < N; i++)
    workY[i] = vNormal((3 * workY[i] - 1) / (3 * N + 1), 0, 1);

  npplot = Graphs->NewGraph(workX, workY, clBlue, SCATTERPLOT,
                            "Нормальная вероятностная бумага",
                            Array->VarName[n_var], "V");

  return npplot;
}
//---------------------------------------------------------------------------
int JAPlot(int n_var, TDoubleArray &X1,TDoubleArray &F_1,TDoubleArray &F_2, unsigned char position)
{
  plot = Graphs->NewGraph(X1, F_1, clBlue, LINEPLOT,
                  //AddGraph(plot, X1, F_1, clBlue, LINEPLOT,
                  //NewGraph(X1, F_1, clBlue, LINEPLOT,
                  "Ядерная аппроксимация|функции плотности распределения",
                  Array->VarName[n_var], "P",
                  false, position);
  Graphs->SaveGraph(plot, ConfigForm->eGraphsPath->Text + "\\" + AnsiString(n_var)+ gNSR + "_1.wmf");
  if ((Report[5] == 0) || (Report[5] == 1)) {
    Graphs->AddGraph(plot, X1, F_2, clRed, LINEPLOT, "", false, position);
    Graphs->SaveGraph(plot, ConfigForm->eGraphsPath->Text + "\\" + AnsiString(n_var) + gNSR + "_2.wmf");
    if (!ConfigForm->cbGraphsShow->Checked) Graphs->DeleteGraph(plot);
  }
  return plot;
}
//---------------------------------------------------------------------------
void MakeFCorrect(TDoubleArray &F, TDoubleArray &X)
{
  int i, N = F.Length;
  double S, Xmin;

  Xmin = VectorMin(X);

  for (i = 0; i < N; i++)
    F[i] *= X[i] - Xmin;

  for (S = 0, i = 0; i < N - 1; i++)
    S += (F[i] + F[i + 1]) * (X[i + 1] - X[i]) / 2;

  for (i = 0; i < N; i++)
    F[i] /= S;
}
//---------------------------------------------------------------------------
/**
* Расщепление смеси
*/
/*
1)	Программа проверяет выборку на наличие смеси;
2)	Если результат отрицательный, то происходит завершение алгоритма - выборка
одномодальна, иначе переходим к следующему пункту;
3)	Происходит расщепление смеси. Получаем математические ожидания и дисперсии
двух компонент.
*/
bool Rascheplen (int n_var, TDoubleArray &X, TDoubleArray &W, TDoubleArray &W1,
                 TDoubleArray &X1, TDoubleArray &FF, TDoubleArray &f)
{
  TDoubleArray rf, lrf, QA, F_1,
               wX = X, wW = W, wW1 = W1, wX1 = X1, wF = f, wFF = FF,
               workX, workY, workW;
  long N = X.Length, c = 2 * N, limitPart;
  long i, i1, i2;
  double q1, res[2], result[6], eps;
  bool isNormal1, isNormal2, r;

  if (c < 10) return false;

  if (ConfigForm->rbLogNormal->Checked) Log(wX);
/*
  JadrParameters(wX, wW, wW1, wX1, wFF, wF, eps, false);

  if (ConfigForm->rbLogNormal->Checked) {
    F_1.Length = c;
    long LnN = (long)floor(log(N) / 2);
    for (i = 0; i < LnN; i++) F_1[i] = 0;
    for (i = LnN; i < c - LnN - 1; i++) {
      F_1[i] = VectorSum(wF, i - LnN, 2 * LnN + 1);
      F_1[i] /= 2 * LnN + 1;
    }
    for (i = c - LnN - 1; i < c; i++) F_1[i] = 0;

    plot1 = NewGraph(wX1, F_1, clBlue, LINEPLOT,
                     "Ядерная аппроксимация|функции плотности распределения|в логарифмической шкале",
                     Array->VarName[n_var], "P");
  }
*/
  workX = wX1.Copy();
  workW = wW1.Copy();
/*
  workW.Length = c;
  for (i = 0; i < c; i++)
    workW[i] = 1;
*/
  VectorDualSort(workX, workW, SORT_ASCENDING);
  workY = workX.Copy();
  VectorRank (workY, SORT_ASCENDING, RANK_MEAN);
  for (i = 0; i < c; i++)
    workY[i] = vNormal((3 * workY[i] - 1) / (3 * c + 1), 0, 1);

  QA.Length = c - 5;
  for (i = 0; i < c - 5; i++) {
    LineApprox(workX, workY, workW, i, i + 4, res);
    if (res[1] == -1)
      if (i > 0)
        QA[i] = QA[i - 1];
      else
        QA[i] = 1;
    else
      QA[i] = res[1];
  }
  i1 = i2 = -1;
  for (i = 0; i < c - 6; i++)
    if (QA[i] / QA[i + 1] > jump || QA[i + 1] / QA[i] > jump) {
      i1 = i;
      break;
    }

  for (i = c - 6; i >= 1; i--)
    if (QA[i] / QA[i - 1] > jump || QA[i - 1] / QA[i] > jump) {
      i2 = i;
      break;
    }

  if (i1 == -1 && i2 == -1) return false;
  if (i2 == i1 + 1) i2 = -1;

  if (i2 == -1) {
    result[0] = (workX[0] + workX[i1]) / 2;
    result[1] = fabs(workX[0] - workX[i1]) / 6;
    result[3] = (workX[i1] + workX[c - 1]) / 2;
    result[4] = fabs(workX[i1] - workX[c - 1]) / 6;
  }
  else {
    result[0] = (workX[i1] + workX[i2]) / 2;
    result[1] = fabs(workX[i1] - workX[i2]) / 6;
    result[3] = (workX[0] + workX[c - 1]) / 2;
    result[4] = fabs(workX[0] - workX[c - 1]) / 6;
  }
/*
  if (result[0] >= result[3] - result[4]) {
    result[0] = workX[0];
    result[4] = workX[c - 1];
  }*/

  if (ConfigForm->rbLogNormal->Checked) {
    result[0] = exp(result[0] + result[1] * result[1] / 2);
    result[1] = sqrt(result[0] * sqrt(exp(result[1] * result[1]) - 1));
    result[3] = exp(result[3] + result[4] * result[4] / 2);
    result[4] = sqrt(result[3] * sqrt(exp(result[4] * result[4]) - 1));
  }

  QVariate(wX1, wFF, result[0],  result[1],  result[3], result[4], result[2]);

  result[5] = 1 - result[2];
//Гипотеза присутствия смеси
  if (N <= 15) r = Smesi_Hipoteza(wX1, wFF, IDSLABAJA, 3, result[0],  result[1],  result[3], result[4], result[2], hip_res);
  else if (N <= 30) r = Smesi_Hipoteza(wX1, wFF, IDSLABAJA, 2, result[0],  result[1],  result[3], result[4], result[2], hip_res);
       else if (N <= 100) r = Smesi_Hipoteza(wX1, wFF, IDSLABAJA, 1, result[0],  result[1],  result[3], result[4], result[2], hip_res);
            else r = Smesi_Hipoteza(wX1, wFF, IDSILNAJA, 1, result[0],  result[1],  result[3], result[4], result[2], hip_res);

  r = true; ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  rf.Length = c;
/*
  lrf.Length = c;

  for (i = 0; i < c; i++)
    lrf[i] = result[2] * dNormal(wX1[i], result[0], result[1]) +
             result[5] * dNormal(wX1[i], result[3], result[4]);

  if (ConfigForm->rbNormal->Checked)
    rf = lrf;
  else
    for (i = 0; i < c; i++)
      rf[i] = result[2] * dLogNormal(X1[i], result[0], result[1]) +
              result[5] * dLogNormal(X1[i], result[3], result[4]);
*/
  if (ConfigForm->rbNormal->Checked)
    isNormal1 = isNormal2 = true;
  else
    isNormal1 = !(isNormal2 = result[2] >= 0.5);

  for (i = 0; i < c; i++)
    rf[i] = dSmes(X1[i], result[0], result[1], result[3], result[4], result[2], isNormal1, isNormal2);
//    result[2] * dLogNormal(X1[i], result[0], result[1]) +
//            result[5] * dLogNormal(X1[i], result[3], result[4]);

  if (r == false) {
    Graphs->AddGraph(plot, X1, rf, clRed, LINEPLOT);
    Graphs->SaveGraph(plot, ConfigForm->eGraphsPath->Text + "\\" + AnsiString(n_var) + gNSR + "_2.wmf");
/*
    if (ConfigForm->rbLogNormal->Checked) {
      AddGraph(plot1, wX1, lrf, clRed, LINEPLOT);
      SaveGraph(plot1, ConfigForm->eGraphsPath->Text + "\\" + AnsiString(nomer) + gNSR + "_3.wmf");
    }*/
    if (!ConfigForm->cbGraphsShow->Checked) {
      Graphs->DeleteGraph(plot);
/*      if (ConfigForm->rbLogNormal->Checked)
        DeleteGraph(plot1);*/
    }
    return false;
  }
  else {
    if (result[0] > result[3]) {
      swap(result[0], result[3]);
      swap(result[1], result[4]);
      swap(result[2], result[5]);
    }
    if (ConfigForm->rbNormal->Checked) {
      isNormal1 = isNormal2 = true;
      Report[66] = result[0];
      Report[67] = result[1];
      Report[68] = result[3];
      Report[69] = result[4];
    }
    else {
      isNormal1 = !(isNormal2 = result[2] >= 0.5);
//      isNormal1 = isNormal2 = false;
      Report[66] = result[0];
      Report[67] = result[1];
      Report[68] = result[3];
      Report[69] = result[4];
//      Report[66] = exp(result[0] + result[1] * result[1] / 2);
//      Report[67] = sqrt(Report[66] * Report[66] * (exp(result[1] * result[1]) - 1));
//      Report[68] = exp(result[3] + result[4] * result[4] / 2);
//      Report[69] = sqrt(Report[68] * Report[68] * (exp(result[4] * result[4]) - 1));
    }
    //---Точка расщепления бимодальной разнесённой смеси------------------------
    double m1, m2, s1, s2;
    m1 = result[0]*result[0];
    m2 = result[3]*result[3];
    s1 = result[1]*result[1];
    s2 = result[4]*result[4];
    Report[70] = (result[3]*s1 - result[0]*s2 - sqrt(pow(result[0]*s2 - result[3]*s1,2) -
              (s1 - s2) * (m2*s1 - m1*s2 + 2*s1*s2*log(result[4]/result[1])))) / (s1 - s2);
    if ((result[0] >= Report[70]) || (Report[70] >= result[3])) {
      Report[70] = (result[3]*s1 - result[0]*s2 + sqrt(pow(result[0]*s2 - result[3]*s1,2) -
              (s1 - s2) * (m2*s1 - m1*s2 + 2*s1*s2*log(result[4]/result[1])))) / (s1 - s2);
    }
    //---Точка расщепления бимодальной разнесённой смеси------------------------
    Report[2]  = 2;
    Report[3]  = result[2];
    Report[4]  = result[5];
    Report[37] = result[2] * Report[66] + result[5] * Report[68];
    NewQuantiles(isNormal1, NULL, result[0], result[1], result[3], result[4], result[2], isNormal2);
    Normalize(n_var);
    //---График теоретической функции плотности распределения (красный)---------
    Graphs->AddGraph(plot, X1, rf, clRed, LINEPLOT, " ", true);
    Graphs->SaveGraph(plot, ConfigForm->eGraphsPath->Text + "\\" + AnsiString(n_var) + gNSR + "_2.wmf");

    // Теоретические распределения
    double e[2] = {0, 1};

    // Первая компонента
    TDoubleArray firstSample, secondSample, fcF, scF, fcFW, scFW, fcW, fsX1, fsW1, fsFF, fsf, fsF1, scW, scX1, scW1, scFF, scf, scF1;
    limitPart = abs(Report[3] * c);
    firstSample.Length = limitPart;
    fcF.Length = limitPart;

    Randomize();
    for (i = 0; i < limitPart; i++) {//генерация случайного числа для подвыборки
//      if () { // с нормальным законом распределения
        double wMean = Report[66];
        double wSDev = Report[67];
        firstSample[i] = RandG(wMean, Report[67]);
        fcF[i] = 1/(wSDev*sqrt(2*M_PI))*pow(M_E,(-1)*pow(firstSample[i]-wMean,2)/(2*pow(wSDev,2)));
//        fcF[i] = 1/(sqrt(2*M_PI*wSDev))*pow(M_E,(-1)*pow(firstSample[i]-wMean,2)/(2*wSDev));
//      } else if () {// с логнормальным законом распределения
//      }
    }
    // Если нет запуска ядерной аппроксимации, то вроде можно не копировать
    fcW.Length = firstSample.Length;
    fcW = firstSample.Copy();
    fcFW.Length = fcF.Length;
    fcFW = fcF.Copy();

//    JadrApprox(n_var, firstSample, fsW, fsW1, fsX1, fsFF, fsf, fsF1, e);

    // Вторая компонента
    limitPart = abs(Report[4] * c);
    secondSample.Length = limitPart;
    scF.Length = limitPart;

    Randomize();
    for (i = 0; i < limitPart; i++) {//генерация случайного числа для подвыборки
//      if () { // с нормальным законом распределения
        double wMean = Report[68];
        double wSDev = Report[69];
        secondSample[i] = RandG(wMean, wSDev);
        scF[i] = 1/(wSDev*sqrt(2*M_PI))*pow(M_E,(-1)*pow(secondSample[i]-wMean,2)/(2*pow(wSDev,2)));
//        scF[i] = 1/(sqrt(2*M_PI*wSDev))*pow(M_E,(-1)*pow(secondSample[i]-wMean,2)/(2*wSDev));
//      } else if () {// с логнормальным законом распределения
//      }
    }
    // Если нет запуска ядерной аппроксимации, то вроде можно не копировать
    scW.Length = secondSample.Length;
    scW = secondSample.Copy();
    scFW.Length = scF.Length;
    scFW = scF.Copy();
//    JadrApprox(n_var, secondSample, scW, scW1, scX1, scFF, scf, scF1, e);

//    plot = Graphs->NewGraph(X1, f, clBlue, LINEPLOT, " ", " ", " ", false, 2);
    Graphs->AddGraph(plot, X1, f, clBlue, LINEPLOT, " ", false, 2);
    Graphs->AddGraph(plot, fcW, fcFW, clRed, LINEPLOT, " ", true, 2);
    Graphs->AddGraph(plot, scW, scFW, clRed, LINEPLOT, " ", true, 2);
//    Graphs->AddGraph(plot, X1, fsW, clRed, LINEPLOT, " ", true);
//    Graphs->AddGraph(plot, X1, scW, clRed, LINEPLOT, " ", true);
    Graphs->SaveGraph(plot, ConfigForm->eGraphsPath->Text + "\\" + AnsiString(n_var) + gNSR + "_z.wmf", 2);

//    plot = Graphs->NewGraph(fcW, fcFW, clRed, LINEPLOT, " ", " ", " ", true, false);
    Graphs->AddGraph(plot, fcW, fcFW, clRed, LINEPLOT, " ", true, 3);
    Graphs->AddGraph(plot, scW, scFW, clGreen, LINEPLOT, " ", true, 3);
//    plot = Graphs->NewGraph(fsX1, fsF1, clRed, LINEPLOT, " ", " ", " ", true);
//    Graphs->AddGraph(plot, scX1, scF1, clGreen, LINEPLOT, " ", true);
    Graphs->SaveGraph(plot, ConfigForm->eGraphsPath->Text + "\\" + AnsiString(n_var) + gNSR + "_x.wmf", 3);
    //---График теоретической функции плотности распределения (красный)---------
/*
    if (ConfigForm->rbLogNormal->Checked) {
      AddGraph(plot1, wX1, lrf, clRed, LINEPLOT, " ", true);
      SaveGraph(plot1, ConfigForm->eGraphsPath->Text + "\\" + AnsiString(nomer) + gNSR + "_3.wmf");
    }*/
    if (!ConfigForm->cbGraphsShow->Checked) {
      Graphs->DeleteGraph(plot);
      Graphs->DeleteGraph(plot);
//      Graphs->DeleteGraph(plot);
//      if (ConfigForm->rbLogNormal->Checked)
//        DeleteGraph(plot1);
    }
  }
  return true;
}
//---------------------------------------------------------------------------
void DeepSplitting (int n_var, TDoubleArray &X, TDoubleArray &W, double expectation1,
                    double dispersion1, double part1, double expectation2, double dispersion2,
                    double part2, double pointSplitting)
{TDoubleArray R, wReport;
static int curStageRecursion = 0;
static AnsiString nameStageRecursion = "";
if (curStageRecursion < 5) {
  bool left = 1;
  bool right = 0;
  wReport = Report.Copy();
  curStageRecursion++;
  nameStageRecursion += "L";
  RemovalSubsample2 (X, R, expectation1, dispersion1, part1, expectation2,
                    dispersion2, part2, pointSplitting, left);
  OdnomAnaliz(n_var, R, W, nameStageRecursion);
  nameStageRecursion.Delete(nameStageRecursion.Length(), 1);
  Report = wReport.Copy();

  nameStageRecursion += "R";
  RemovalSubsample2 (X, R, expectation1, dispersion1, part1, expectation2,
                    dispersion2, part2, pointSplitting, right);
  OdnomAnaliz(n_var, R, W, nameStageRecursion);
  nameStageRecursion.Delete(nameStageRecursion.Length(), 1);
  Report = wReport.Copy();
  curStageRecursion--;
  }
}
//---------------------------------------------------------------------------
/*
Производим процесс изъятия одной из компонент из выборки следующим способом:
зная интервал, на котором располагается, например, левая компонента, через мат.
ожидание и дисперсию, генерируем на этом интервале случайным образом число и
изымаем из выборки ближайшее к нему, так повторяем до тех пор, пока не будет
достигнут предел равный произведению массовой доли компоненты на общее
количество объектов в выборке. Затем для правой компоненты переходим к
расщеплению смеси. Если ветвь для её будет остановлена, то изъятию подлежит уже
эта компонента.
*/
void RemovalSubsample (TDoubleArray &X, TDoubleArray &R,  double expectation1,
                      double dispersion1, double part1, double expectation2,
                      double dispersion2, double part2, double pointSplitting, bool position)
{
  double RndNumber;
  int limitPart, countDP = 0;
  TList* wSubsample = new TList();
  TDoubleArray* wR = new TDoubleArray();
  int length = X.Length; 
  R = X.Copy();
  for (int i = 0; i < R.Length; i++) {
    wSubsample->Add(&(R[i]));
  }
  if (position) {
    limitPart = abs(part1*length);
  } else {
    limitPart = abs(part2*length);
  }
  //Удаление
  if (countDP < limitPart) {
    for (; countDP <= limitPart; countDP++)
    {//генерация случайного числа для подвыборки
      if (position) {
        Randomize();
        RndNumber = RandG(expectation1, dispersion1); // с нормальным законом распределения
        //цикл поиска ближайшего числа из выборки
        for (int i=0; i < length-countDP; i++)
          {double test = * (double *)wSubsample->Items[i];
          if ((i != 0) && (test > RndNumber))
            {// удалить sample[k-1]
            wSubsample->Delete(i-1);
            break;
            }
          else if ((i == 0) && (test > RndNumber))
            {// удалить sample[k]
            wSubsample->Delete(i);
            break;
            }
          }
      } else {
        randomize();
        RndNumber = RandG(expectation2, dispersion2); // с нормальным законом распределения
        for (int i=length-countDP-1; i >= 0; i--)
          {double test = * (double *)wSubsample->Items[i];
          if ((i != (length-countDP-1)) && (test < RndNumber))
            {// удалить sample[k+1]
            wSubsample->Delete(i+1);
            break;
            }
          else if ((i == (length-countDP-1)) && (test < RndNumber))
            {// удалить sample[k]
            wSubsample->Delete(i);
            break;
            }
          }
      }
    //пересортировка масиивы выборки
    }
  }
  wSubsample->Pack();
  wR->Length = wSubsample->Count;
  for (int i=0; i < wSubsample->Count; i++){
    (*wR)[i] = (* (double *)wSubsample->Items[i]);
  }
  R = wR->Copy();
  wSubsample->Free();
  delete wR;
//  return; // новая выборка
}
//---------------------------------------------------------------------------
void RemovalSubsample2 (TDoubleArray &X, TDoubleArray &R,  double expectation1,
                      double dispersion1, double part1, double expectation2,
                      double dispersion2, double part2, double pointSplitting, bool position)
{
  double RndNumber;
  int limitPart, countDP = 0;
  TList* wSubsample = new TList();
  TDoubleArray* wR = new TDoubleArray();
  int length = X.Length;
  R = X.Copy();
  for (int i = 0; i < R.Length; i++) {
    wSubsample->Add(&(R[i]));
  }
  //Удаление фиксировнной части подкомпоненты
  if (position) {
    limitPart = abs(part1*length);
    double limitSequence = expectation2 - dispersion2;
    double test = * (double *)wSubsample->Items[0];
    for (;(test < limitSequence) && (countDP <= limitPart); countDP++) {
      test = * (double *)wSubsample->Items[1];
      wSubsample->Delete(0);
    }
  } else {
    limitPart = abs(part2*length);
    double limitSequence = expectation1 + dispersion1;
    double test = * (double *)wSubsample->Items[length-1];
    for (int i=0; (test > limitSequence) && (countDP <= limitPart); i++, countDP++) {
      test = * (double *)wSubsample->Items[length-1-i];
      wSubsample->Delete(length-1-i);
    }
  }
  wSubsample->Pack();
  //Удаление остатка
  if (countDP < limitPart) {
    for (; countDP <= limitPart; countDP++)
    {//генерация случайного числа для подвыборки
      if (position) {
        Randomize();
        //randomize();
        //RndNumber = (rand()/(RAND_MAX/(2*dispersion1)))+expectation1-dispersion1; //равновероятныйе числа
        RndNumber = RandG(expectation1, dispersion1); // с нормальным законом распределения
        //цикл поиска ближайшего числа из выборки
        for (int i=0; i < length-countDP; i++)
          {double test = * (double *)wSubsample->Items[i];
          if ((i != 0) && (test > RndNumber))
            {// удалить sample[k-1]
            wSubsample->Delete(i-1);
            break;
            }
          else if ((i == 0) && (test > RndNumber))
            {// удалить sample[k]
            wSubsample->Delete(i);
            break;
            }
          }
      } else {
        //randomize();
        Randomize();
        //RndNumber = (rand()/(RAND_MAX/(2*dispersion2)))+expectation2-dispersion2; //равновероятныйе числа
        RndNumber = RandG(expectation2, dispersion2); // с нормальным законом распределения
        for (int i=length-countDP-1; i >= 0; i--)
          {double test = * (double *)wSubsample->Items[i];
          if ((i != (length-countDP-1)) && (test < RndNumber))
            {// удалить sample[k+1]
            wSubsample->Delete(i+1);
            break;
            }
          else if ((i == (length-countDP-1)) && (test < RndNumber))
            {// удалить sample[k]
            wSubsample->Delete(i);
            break;
            }
          }
      }
    //пересортировка масивы выборки
    }
  }
  wSubsample->Pack();
  wR->Length = wSubsample->Count;
  for (int i=0; i < wSubsample->Count; i++){
    (*wR)[i] = (* (double *)wSubsample->Items[i]);
  }
  R = wR->Copy();
  wSubsample->Free();
  delete wR;
//  return; // новая выборка
}
//---------------------------------------------------------------------------
#pragma package(smart_init)




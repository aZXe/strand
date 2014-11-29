//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <dir.h>
#pragma hdrstop

#include "GridArray.h"
#include "MatrixFunctions.h"
#include "MatrixDisplay.h"
#include "Graphing.h"
#include "OdnomAnaliz.h"
#include "Progress.h"
#include "MyStatFunctions.h"
#include "About.h"
#include "Logging.h"
#include "TreeParm.h"
#include "Utils.h"
#include "Main.h"
#include "FPConstructor.h"
//#include "MatMath\smatlab.hpp"
//---------------------------------------------------------------------------
//#pragma link "cgauges"
#pragma resource "*.dfm"
TMainForm           *MainForm;
TChildGrid          *MainChildGrid;
TChildLog           *MainChildLog;
TChildRegrMemo      *MainChildRegrMemo;
TFPConstructorForm  *MainFPConstructorForm;

AnsiString NameMainDataFile;
//---------------------------------------------------------------------------
TArray *Array, *dArray;
TAnsiStringArray VarsNames;
TIntArray VarsNums;

T2DoubleArray T, TT;
TIntArray Z, Z1;
T2DoubleArray Corr;

AnsiString PathWork;

bool new_tree;
#define MIN_COUNT        20
double min_podvyb = 0.5, max_podvyb = 0.50, max_alpha = 0.2;
int filter_num = -1;
//---------------------------------------------------------------------------
long __fastcall Ravn (double alpha);
void FactorP (void);
bool isFP (TIntArray *X);
void A (TIntArray *X, int a);
int VarNormalize (int Var);
void Regression (void);
#define SET_MAIN_CHILD_GRID_CAPTION \
  MainChildGrid->Caption = NameMainDataFile + \
                           " (v"+IntToStr((int)MainChildGrid->A->NVars)+ \
                            ";c"+IntToStr((int)MainChildGrid->A->NCases)+")"
//---------------------------------------------------------------------------
bool CompareVars(AnsiString varname1, AnsiString varname2);
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent *Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
  MainChildGrid = NULL;
  MainFPConstructorForm = NULL;
//  agProgress->Visible = false;
  EnableDataInterfaceItems(false);
/*
  strProgressBar = new TCGauge ( StatusBar1 );
  strProgressBar->Parent = StatusBar1;

  strProgressBar->Position = 0;
  strProgressBar->Visible = false;
*/  
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormActivate(TObject *Sender)
{
  MainChildLog = new TChildLog(Application);
  LogOpen("_strand_.log");
  LogAdd("--------------------------- BEGIN " + DateTimeToStr(Now()) +
         " ---------------------------");
  MainChildLog->Top    = 0;
  MainChildLog->Left   = 0;
  MainChildLog->Height = MainForm->ClientHeight / 2;
  MainChildLog->Width  = MainForm->ClientWidth - 5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormDestroy(TObject *Sender)
{
//  delete MainChildLog;
  LogClose();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CreateChildGrid(String Name)
{
  if (MainChildGrid == NULL)
    MainChildGrid = new TChildGrid(Application);
  else {
    MainChildGrid->Close();
    delete MainChildGrid;
    MainChildGrid = new TChildGrid(Application);
  }
  if (FileExists (Name))
    if (MainChildGrid->A->OpenStaFile(Name.c_str()) == 0)
      MainChildGrid->Close();
    else {
      NameMainDataFile = Name;
      SET_MAIN_CHILD_GRID_CAPTION;
      EnableDataInterfaceItems(true);
    }
  Array = MainChildGrid->A;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CreateChildGrid(const T2DoubleArray X,
                                           const TAnsiStringArray ColsCaptions,
                                           const TAnsiStringArray RowsCaptions,
                                           const AnsiString Name,
                                           const int ViewRowsCount,
                                           const int ViewColsCount)
{
  TChildGrid *Child;

  Child = new TChildGrid(Application);
  Child->Caption = Name;

  Child->A->SetData(X);
  Child->A->SetColsNames(ColsCaptions);
  Child->A->SetRowsNames(RowsCaptions);
  Child->ClientWidth  = (ViewColsCount) * Child->StringGrid1->DefaultColWidth;
  Child->ClientHeight = (ViewRowsCount + 2) * Child->StringGrid1->DefaultRowHeight;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CreateChildLog(void)
{
  TChildLog *Child;

  Child = new TChildLog(Application);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CreateChildCalcMemo(void)
{
  TChildCalcMemo *Child;

  Child = new TChildCalcMemo(Application);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CreateChildRegrMemo(void)
{
  MainChildRegrMemo = new TChildRegrMemo(Application);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CloseChildRegrMemo(void)
{
  MainChildRegrMemo->Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DataOpenExecute(TObject *Sender)
{
  if (OpenDialog->Execute())
    CreateChildGrid(OpenDialog->FileName);
  LogAdd("Файл данных: " + OpenDialog->FileName);
  if (MainChildGrid != NULL) EnableDataInterfaceItems(true);

/*
  if ((filter_num = Array->VarByName("FILTER")) == 0) {
    int nv = Array->NVars + 1;
    filter_num = nv;
    Array->NVars = nv;
    Array->VarName[nv] = "FILTER";
    LogAdd("Создана переменная 'FILTER'");
    SET_MAIN_CHILD_GRID_CAPTION;
  }
  for (long i = 0; i < Array->NCases; i++)
    Array->Cell[filter_num][i] = 1;
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::HelpAbout1Execute(TObject *Sender)
{
//  AboutBox = new TAboutBox(Application);
  AboutBox->ShowModal();
//  delete AboutBox;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FileExitExecute(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ToolButton12Click(TObject *Sender)
{
  CreateChildCalcMemo();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ToolButton13Click(TObject *Sender)
{
  new_tree = true;
  WinTreeParm = new TWinTreeParm(this);
  WinTreeParm->ShowModal();
  delete WinTreeParm;

//  FactorP();

  new_tree = false;
  WinTreeParm = new TWinTreeParm(this);
  WinTreeParm->ShowModal();
  delete WinTreeParm;

//  Regression();
}
//---------------------------------------------------------------------------
void __fastcall EnableDataInterfaceItems(bool e)
{
  MainForm->Analysis->Enabled = e;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OptimizationItemClick(TObject *Sender)
{
  CreateChildCalcMemo();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::StatusBar1Resize(TObject *Sender)
{
/*
  int Size = StatusBar1->Width;
  for ( int i = 1; i < StatusBar1->Panels->Count; i++ )
    Size -= StatusBar1->Panels->Items[i]->Width;

  //resize the first panel based on the form width
  StatusBar1->Panels->Items[ 0 ]->Width = Size;
  RECT Rect;
  StatusBar1->Perform ( SB_GETRECT,  0,  (LPARAM)&Rect );

  strProgressBar->Top = Rect.top;
  strProgressBar->Left = Rect.left;
  strProgressBar->Width = StatusBar1->Panels->Items [ 0 ]->Width;
  strProgressBar->Height = Rect.bottom - Rect.top;
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TreeOpenExecute(TObject *Sender)
{
  if (OpenTreeDialog->Execute()) {
//    CreateChildGrid(OpenDialog->FileName);
  }
  LogAdd("Файл зависимостей: " + OpenTreeDialog->FileName);
//  if (MainChildGrid != NULL) EnableDataInterfaceItems(true);
}
//---------------------------------------------------------------------------
void FactorP (void)
{
  TArray *ttt;
  FILE *f, *fp_all;
  AnsiString fun;
  char buf[200];
  TDoubleArray X, Y;
  TIntArray *XX;
  int ii, i, j, N, nv;
  int fp_count = 0;
  double d;

  fp_all = fopen((PathWork + "\\factor.txt").c_str(), "w");
  for (ii = 1; ii < 7; ii++) {
Again:
    if ((N = T[ii].Length) < 2) continue;

    Corr.Length = N;
    for (i = 0; i < N; i++)
      Corr[i].Length = N;
    for (i = 0; i < N; i++) {
      Corr[i][i] = 1;
      for (j = i + 1; j < N; j++) {
        X = Array->GetVar(nv = (int)T[ii][i]);
        Y = Array->GetVar(nv = (int)T[ii][j]);
        Corr[i][j] = Corr[j][i] = Correlation(X, Y);
      }
    }

    XX = new TIntArray;
    XX->Length = N;
    for (i = 0; i < N; i++)
      (*XX)[i] = i;

    Z1.Length = 0;
    A(XX, -1);

    if (Z1.Length > 0) {
      fun = (AnsiString)Array->VarName[(int)T[0][0]]+"=(" +
            (AnsiString)Array->VarName[(int)T[ii][Z1[0]]] + "**a0)";
      for (i = 1; i < Z1.Length; i++)
        fun = fun + "*(" + (AnsiString)Array->VarName[(int)T[ii][Z1[i]]] +
                                                      "**a" + IntToStr(i) + ")";
      Array->SaveStaFile((PathWork + "\\fp.sta").c_str());
      f = fopen((PathWork + "\\fp.scl").c_str(), "w");
      fprintf(f, "FILE=\"%s\\fp.sta\"\nINCLUDE IF \"FILTER=1\"\n", PathWork.c_str());
      fprintf(f, "NONLINEAR\nFUNCTION=\"%s\"\n/LOSS=\"(PRED-OBS)**2\"\n", fun.c_str());
      fprintf(f, "/CASEWISE\nSTATISTICS=1\nSENDKEYS \"%%O{Enter}{Esc 3}%%F");
      fprintf(f, "{Down 4}{Enter}%s\\tmp.sta{Enter}\"\n", PathWork.c_str());
      fclose(f);

      sprintf(buf, "%s\\Stat55.000\\sta_run.exe %s\\fp.scl", PathWork.c_str(), PathWork.c_str());
      system(buf);


      ttt = new TArray(NULL);
      ttt->OpenStaFile((PathWork + "\\tmp.sta").c_str());

      fun = "FP"  + IntToStr(++fp_count)+ " = (" +
            (AnsiString)Array->VarName[(int)T[ii][Z1[0]]] + "**(" + FloatToStrF(ttt->Cell[1][1], ffGeneral, 3, 0)+ "))";
      for (i = 1; i < Z1.Length; i++)
        fun = fun + " * (" + (AnsiString)Array->VarName[(int)T[ii][Z1[i]]] +
                           "**(" + FloatToStrF(ttt->Cell[i + 1][1], ffGeneral, 3, 0) + "))";
      fprintf(fp_all, "%s\n", fun.c_str());
      nv = Array->NVars + 1;
      Array->VarName[nv] = ("FP" + IntToStr(fp_count)).c_str();
      for (j = 1; j <= Array->NCases; j++) {
        d = 1;
        for (i = 0; i < Z1.Length; i++)
          if (Array->Cell[(int)T[ii][Z1[i]]][j] != MISSING_DATA)
            d *= pow(Array->Cell[(int)T[ii][Z1[i]]][j], ttt->Cell[i + 1][1]);
          else {
            d = MISSING_DATA;
            break;
          }
        Array->Cell[nv][j] = d;
      }

      delete ttt;

      for (i = 0; i < Z1.Length; i++)
        T[ii][Z1[i]] = -1;
      VectorSort(T[ii], SORT_DESCENDING);
      T[ii].Length = (N -= Z1.Length - 1);
      T[ii][N - 1] = VarNormalize(nv);

      goto Again;
    }
  }

  fclose(fp_all);
}
//---------------------------------------------------------------------------
bool isFP (TIntArray *X)
{
  int N = X->Length;
  int i, j;

  for (i = 0; i < N; i++)
    for (j = i + 1; j < N; j++)
      if (fabs(Corr[(*X)[i]][(*X)[j]]) < 0.5) return false;

  return true;
}
//---------------------------------------------------------------------------
void A (TIntArray *X, int a)
{
  TIntArray *Y;
  int N = X->Length;
  int i, t;

//  if (N == 2) return;
  if (N == 2) {
    if (fabs(Corr[(*X)[0]][(*X)[1]]) >= 0.5) {
      Z = X->Copy();
      delete X;
      if (Z.Length > Z1.Length)
        Z1 = Z.Copy();
    }
    return;
  }
  if (a != -1) {
    t = (*X)[a];
    (*X)[a] = (*X)[N - 1];
    (*X)[N - 1] = t;
    X->Length = --N;
  } else a = 0;

  if (isFP(X)) {
    Z = X->Copy();
    delete X;
    if (Z.Length > Z1.Length)
      Z1 = Z.Copy();
    return;
  }

  for (i = a; i < N; i++) {
    Y = new TIntArray;
    (*Y) = X->Copy();
    A(Y, i);
  }

  delete X;
}
//---------------------------------------------------------------------------
int VarNormalize (int Var)
{
  TDoubleArray XXX, X1, FF, f;
  int jj = Var;
  long j;
  double e[2], eps, eps1;
  bool ii;
  AnsiString tmp_str;

  XXX = Array->GetVar(jj);
  ArchArray(XXX);
  R(XXX, XXX, 0, XXX.Length, e);
  JadrParameters(XXX, X1, FF, f, eps1, FALSE);
  ii = false;
  for (j = 0; j < XXX.Length; j++)
    if (XXX[j] >= 1e-4) XXX[j] = log(XXX[j]);
    else goto z100;

  R(XXX, XXX, 0, XXX.Length, e);
  JadrParameters(XXX, X1, FF, f, eps, FALSE);

//    NewGraph(X1, f, clBlue, LINEPLOT, "Ядерная аппроксимация|функции плотности распределения", "X", "Y");

  ii = Hipoteza(X1, FF, IDSLABAJA, 10, e[0], e[1]);

  z100:

  XXX = Array->GetVar(jj);
  if (ii) {
    for (j = 0; j < XXX.Length; j++)
      if (XXX[j] != MISSING_DATA) XXX[j] = log(XXX[j]);
    Norm(XXX, eps);
  } else
      Norm(XXX, eps1);
  tmp_str = "N" + (AnsiString)Array->VarName[jj];
  tmp_str.SetLength(8);
  Array->SetVar(XXX, Array->NVars + 1, tmp_str);
  SET_MAIN_CHILD_GRID_CAPTION;

  return Array->NVars;
}
//---------------------------------------------------------------------------
void Regression (void)
{
  TArray *ttt;
  T2DoubleArray TT2;
  FILE *f, *fp_all;
  AnsiString fun, tmp_str;
  char buf[200];
  TDoubleArray X, Y;
  int ii, i, j, N, nv = Array->NVars;
  int fp_count = 0, k;
  double d, d1;

  TT.Length = 3;
  TT[0] = T[1].Copy();
  TT[1] = T[4].Copy();
  TT[2].Length = nv;
  ii = 0;
  for (i = 2; i < 7; i++) {
    if (i == 4) continue;
    for (j = 0; j < T[i].Length; j++)
      TT[2][ii++] = T[i][j];
  }
  TT[2].Length = ii;
  TT2.Length = TT[0].Length;
  for (j = 0; j < TT2.Length; j++)
    TT2[j] = TT[2].Copy();

  Array->SaveStaFile((PathWork + "\\regr.sta").c_str());
  fp_all = fopen((PathWork + "\\regr.txt").c_str(), "w");
  while (1) {
    fun = (AnsiString)Array->VarName[(int)T[0][0]] + "=a0";
    for (i = 0; i < TT[0].Length; i++) {
      fun = fun + "*(" + (AnsiString)Array->VarName[(int)TT[0][i]] + "**(a" +
                  IntToStr(i) + "0";
      for (j = 0; j < TT2[i].Length; j++)
        fun = fun + "*(" + (AnsiString)Array->VarName[(int)TT2[i][j]] +
                    "**a" + IntToStr(i)+ IntToStr(j + 1) + ")";
      fun = fun + "))";
    }
    for (i = 0; i < TT[1].Length; i++)
      fun = fun + "*(" + (AnsiString)Array->VarName[(int)TT[1][i]] + "**a" +
                  IntToStr(i + 1) + ")";

    f = fopen((PathWork + "\\regr.scl").c_str(), "w");
    fprintf(f, "FILE=\"%s\\regr.sta\"\nINCLUDE IF \"FILTER=1\"\nEDIT\n", PathWork.c_str());
    fprintf(f, "SENDKEYS \"%%A{Down 5}{Enter}{Down 4}{Enter}%%O%%F\"\n");
    for (i = 1; i < fun.Length(); i += 40)
      fprintf(f, "SENDKEYS \"%s\"\n", (fun.SubString(i, 40)).c_str());
    fprintf(f, "SENDKEYS \"%%O%%O%%O%%O%%O{Esc 3}%%F{Down 4}{Enter}\"\n");
    fprintf(f, "SENDKEYS \"%s\\tmp.sta{Enter}%%{F4}\"\n", PathWork.c_str());
    fclose(f);

//    sprintf(buf, "D:\\Stat55\\sta_run.exe %s\\regr.scl", PathWork.c_str(), PathWork.c_str());
//    system(buf);

    ttt = new TArray(NULL);
    ttt->OpenStaFile((PathWork + "\\tmp.sta").c_str());

    k = 1;
    fun = (AnsiString)Array->VarName[(int)T[0][0]] + " = (" +
          FloatToStrF(ttt->Cell[k++][1], ffGeneral, 3, 0) + ")";
    for (i = 0; i < TT[0].Length; i++) {
      fun = fun + " * (" + (AnsiString)Array->VarName[(int)TT[0][i]] + "**((" +
                   FloatToStrF(ttt->Cell[k++][1], ffGeneral, 3, 0) + ")";
      for (j = 0; j < TT2[i].Length; j++)
        fun = fun + " * (" + (AnsiString)Array->VarName[(int)TT2[i][j]] +
                    "**(" + FloatToStrF(ttt->Cell[k++][1], ffGeneral, 3, 0) + "))";
      fun = fun + "))";
    }
    for (i = 0; i < TT[1].Length; i++)
      fun = fun + " * (" + (AnsiString)Array->VarName[(int)TT[1][i]] + "**(" +
                  FloatToStrF(ttt->Cell[k++][1], ffGeneral, 3, 0) + "))";
    fprintf(fp_all, "%s\n", fun.c_str());

    nv = Array->NVars + 1;
    Array->VarName[nv] = ("REGR" + IntToStr(++fp_count)).c_str();
    for (ii = 1; ii <= Array->NCases; ii++) {
      k = 1;
      d = ttt->Cell[k++][1];
      for (i = 0; i < TT[0].Length; i++)
        if (Array->Cell[(int)TT[0][i]][ii] != MISSING_DATA && d != MISSING_DATA) {
          d1 = 1;
          for (j = 0; j < TT2[i].Length; j++)
            if (Array->Cell[(int)TT2[i][j]][ii] != MISSING_DATA)
              d1 *= pow(Array->Cell[(int)TT2[i][j]][ii], ttt->Cell[k++][1]);
            else {
              d = MISSING_DATA;
              break;
            }
          if (d != MISSING_DATA) d *= pow(Array->Cell[(int)TT[0][i]][ii], d1);
        }
        else {
          d = MISSING_DATA;
          break;
        }
      for (i = 0; i < TT[1].Length; i++)
        if (Array->Cell[(int)TT[1][i]][ii] != MISSING_DATA && d != MISSING_DATA)
          d *= pow(Array->Cell[(int)TT[1][i]][ii], ttt->Cell[k++][1]);
        else {
          d = MISSING_DATA;
          break;
        }

      Array->Cell[nv][ii] = d;
    }

    delete ttt;

break;
  }

  fclose(fp_all);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OdnomAnalizItemClick(TObject *Sender)
{
  TDoubleArray X, W, wX, wW;
//  int nom = eNomer->Value;
  long i, p;
  int  j, pv;

  VarsNames.Length = Array->NVars;
  for (pv = 0, j = 0; j < Array->NVars && j + 1 != filter_num; j++) {
    wX = Array->GetVar(j + 1);
    wW = wX.Copy();

    X.Length = wX.Length;
    W.Length = wW.Length;
    for (p = 0, i = 0; i < wX.Length; i++)
      if (wX[i] != MISSING_DATA && wW[i] != MISSING_DATA) {
        X[p] = wX[i];
        W[p] = wW[i];
        p++;
      }

    if (p > 5) {
      X.Length = p;
      W.Length = p;
      VarsNames[pv] = (AnsiString)Array->VarName[j + 1];
      pv++;

//      OdnomAnaliz(j + 1, X, W);    // <<<==================================
    }
  }
  VarsNames.Length = pv;

//  N8->Enabled = true;      <===============================================
//  N9->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::VydelPodvybItemClick(TObject *Sender)
{
  TDoubleArray XXX, X1, FF, f;
//  int nv = Array->NVars + 1;
  int i;
  long N = Array->NCases;
  char buf[20];
  AnsiString tmp_str;
/*
  if (filter_num == -1) {
    filter_num = nv;
    Array->NVars = nv;
    Array->VarName[nv] = "FILTER";
  }
*/
  VarsNums.Length = VarsNames.Length;
  for (i = 0; i < VarsNames.Length; i++) {
    VarsNums[i] = VarNormalize(Array->VarByName(VarsNames[i]));
    VarsNames[i] = Array->VarName[VarsNums[i]];
  }
/* <=========================================================
  if (N <= 30) {
//    for (i = 0; i < N; i++)
//      Array->Cell[filter_num][i] = 1;
    Array->SaveStaFile("2.sta");
    return;
  }

  double alpha = max_alpha;
  long n = 0, min_n = min_podvyb * N;//, max_n = max_podvyb * N;

  ProgressSet(0);
  ProgressShow();
  ProgressCaption("Выделение подвыборки [" + FloatToStr(alpha) + "]");
  progress_step = 2;
  do {
    n = Ravn(alpha);
    alpha /= 1.1;
    ProgressCaption("Выделение подвыборки [" + FloatToStr(alpha) + "]");
    ProgressInc();
  } while (min_n > n);
  ProgressSet(100);
  ProgressHide();

  eRes->Text = (AnsiString)itoa(n, buf, 10);
  Array->SaveStaFile("2.sta");
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ToolButton14Click(TObject *Sender)
{
  TIntSet Vars;

  if (MainChildGrid == NULL) return;

  if (MainFPConstructorForm == NULL) {
    for (int i = 1; i <= MainChildGrid->A->NVars; i++)
      Vars.insert(i);
    MainFPConstructorForm = new TFPConstructorForm(Application, Vars);
  }

  MainFPConstructorForm->Show();
}
//---------------------------------------------------------------------------
void CloseAllDependentWindows(void)
{
  if (MainFPConstructorForm != NULL)
    MainFPConstructorForm->Close();

  if (MainChildRegrMemo != NULL)
    MainChildRegrMemo->Close();
}
//---------------------------------------------------------------------------
bool CompareVars(AnsiString varname1, AnsiString varname2)
{
  if (MainChildGrid == NULL) return false;
  
  return MainChildGrid->A->VarByName(varname1) > MainChildGrid->A->VarByName(varname2);
}
//---------------------------------------------------------------------------
#pragma package(smart_init)

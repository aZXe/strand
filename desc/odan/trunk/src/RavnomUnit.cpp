//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <stdlib>
#include <stdio>
#include <math>
#include <math.hpp>
#include <dir>
#include <set>
#include "MyStatFunctions.h"
#include "MatrixFunctions.h"
#include "MatrixDisplay.h"
#include "OdnomAnaliz.h"
#include "Progress.h"
#include "RavnomUnit.h"
#include "Config.h"
#include "CreateParameters.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CGAUGES"
#pragma link "CSPIN"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
TForm1 *Form1;
TChartArray *Graph1;
TStringGrid *_RGrid;
TPanel *_Panel;
TCGauge *_Progress;
TArray *Array;
TArray *AllReport;
TAnsiStringArray VarsNames;
TIntArray VarsNums;

T2DoubleArray T, TT;
TIntArray Z, Z1;
T2DoubleArray Corr;

AnsiString PathWork;
AnsiString WorkFileName;

#define SET_CAPTION Form1->Caption = \
                      WorkFileName + " (v" + IntToStr(Array->NVars) + \
                                     ";c" + IntToStr(Array->NCases) + ")"
#define MIN_COUNT        20
double min_podvyb = 0.5, max_podvyb = 0.50, max_alpha = 0.2;
int filter_num = 0;
int weigh_num = 0;

int rowcount, colcount;
//---------------------------------------------------------------------------
//int VarNormalize (int Var);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
  char buf[201];
  getcwd(buf, 200);
  PathWork = buf;
  Graph1 = new TChartArray();
  Array = new TArray(SGrid, 10, 10);
  btnOdnomAnaliz->Enabled = FALSE;
  _RGrid = Form1->RGrid;
  _Panel = Form1->Panel;
  _Progress = Form1->Progress;
  InitOdnomAnaliz();
  N4->ShortCut = ShortCut(Word('X'), TShiftState() << ssAlt);
  btnOdnomAnaliz->Enabled = false;
  N7->Enabled = false;
  N6->Enabled = false;
  N8->Enabled = false;

  Graph1->InitGraph();
//  InitGraph(); /////////////////////////////////////////////////////////////////////////////////////////////
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
  ConfigForm->ConfigFileLoad();
  ConfigForm->ConfigFileSave();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
  DeinitOdnomAnaliz();
  delete Array;
}
//---------------------------------------------------------------------------
// Проведения одномерного анализа для одного признака
void __fastcall TForm1::btnOdnomAnalizClick(TObject *Sender)
{
  TDoubleArray X, W, wX, wW, filter_var;
  double nomer;
  int nom  = StrToInt(eNomer->Text), N;
  long i, j, p;

  N1->Enabled = false;
  btnOdnomAnaliz->Enabled = false;

  if (eWeigh->Text != "") weigh_num = StrToInt(eWeigh->Text);
  else  weigh_num = 0;
  filter_var = Array->GetVar(filter_num);
  wX = Array->GetVar(nom);
//  wW = wX.Copy();
  if (weigh_num) wW = Array->GetVar(weigh_num);
  else wW = wX.Copy();
  N = wX.Length;

  X.Length = wX.Length;
  W.Length = wW.Length;
  for (p = 0, i = 0; i < N; i++)
    if (wX[i] != MISSING_DATA && wW[i] != MISSING_DATA &&
        filter_var[i] != 0) {
      X[p] = wX[i];
      W[p] = wW[i];
      p++;
    }
  X.Length = p;
  W.Length = p;

  try {
    if (X.Length >= 15)
      OdnomAnaliz(nom, X, W);
    else
      Application->MessageBox(("Признак " + AnsiString(Array->VarName[nom]) + "содержит менее 15 значений!\nАнализ признака невозможен.").c_str(), "Ошибка", MB_OK);
  }
  __finally {
    N1->Enabled = true;
    btnOdnomAnaliz->Enabled = true;
    SET_CAPTION;
  }
}
//---------------------------------------------------------------------------
// Проведения одномерного анализа для всех признаков
void __fastcall TForm1::N7Click(TObject *Sender)
{
  TDoubleArray X, W, wX, wW, filter_var;
//  int nom = eNomer->Value;
  long i, p;
  int  j, pv;

  N1->Enabled = false;
  btnOdnomAnaliz->Enabled = false;
try {
  if (eWeigh->Text != "") weigh_num = StrToInt(eWeigh->Text);
  else  weigh_num = 0;
  filter_var = Array->GetVar(filter_num);

  VarsNames.Length = Array->NVars;
  for (pv = 0, j = 0; j < min((int)Array->NVars, filter_num - 1); j++) {
    wX = Array->GetVar(j + 1);
//    wW = wX.Copy();
    if (weigh_num) wW = Array->GetVar(weigh_num);
    else wW = wX.Copy();

    X.Length = wX.Length;
    W.Length = wW.Length;
    for (p = 0, i = 0; i < wX.Length; i++)
      if (wX[i] != MISSING_DATA && wW[i] != MISSING_DATA && filter_var[i] != 0) {
        X[p] = wX[i];
        W[p] = wW[i];
        p++;
      }

    if (p >= 15) {
      X.Length = p;
      W.Length = p;
      VarsNames[pv] = (AnsiString)Array->VarName[j + 1];
      pv++;

      OdnomAnaliz(j + 1, X, W);
      SET_CAPTION;
    }
    else
      Application->MessageBox(("Признак " + AnsiString(Array->VarName[j + 1]) + "содержит менее 15 значений!\nАнализ признака невозможен.").c_str(), "Ошибка", MB_OK);
  }
  VarsNames.Length = pv;
} //try
__finally {
    N1->Enabled = true;
    btnOdnomAnaliz->Enabled = true;
  }
}
//---------------------------------------------------------------------------
// Меню -> Файл -> Выход
void __fastcall TForm1::N4Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
// Меню -> Файл -> Открыть файл данных
void __fastcall TForm1::N2Click(TObject *Sender)
{
  OpenStaDialog->InitialDir = PathWork;
  if (OpenStaDialog->Execute() == TRUE) {
    Array->OpenStaFile(OpenStaDialog->FileName.c_str());
    WorkFileName = OpenStaDialog->FileName.c_str();

    btnOdnomAnaliz->Enabled = true;
    N7->Enabled = true;
    N6->Enabled = true;
    N8->Enabled = true;

    if ((filter_num = Array->VarByName("FILTER")) == 0) {
      int nv = Array->NVars + 1;
      filter_num = nv;
      Array->NVars = nv;
      Array->VarName[nv] = "FILTER";
      for (long i = 0; i < Array->NCases; i++)
        Array->Cell[filter_num][i + 1] = 1;
    }
    SET_CAPTION;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N10Click(TObject *Sender)
{
  ConfigForm->ShowModal();
}
//---------------------------------------------------------------------------
/*
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

  return Array->NVars;
}
*/
//---------------------------------------------------------------------------
// Меню->Файл->Сохранить файл данных
void __fastcall TForm1::N8Click(TObject *Sender)
{
  SaveStaDialog->InitialDir = PathWork;
  if (SaveStaDialog->Execute() == TRUE) {
    if (ExtractFileExt(SaveStaDialog->FileName.c_str()) == "")
      Array->SaveStaFile((SaveStaDialog->FileName + ".sta").c_str());
    else
      Array->SaveStaFile(SaveStaDialog->FileName.c_str());
  }
}
//---------------------------------------------------------------------------
// Меню->Файл->Сохранить результаты
void __fastcall TForm1::N6Click(TObject *Sender)
{
  SaveStaDialog->InitialDir = PathWork;
  if (SaveStaDialog->Execute() == TRUE) {
    if (ExtractFileExt(SaveStaDialog->FileName.c_str()) == "")
      AllReport->SaveStaFile((SaveStaDialog->FileName + ".sta").c_str());
    else
      AllReport->SaveStaFile(SaveStaDialog->FileName.c_str());
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::miCreateClick(TObject *Sender)
{
  int i, j;
  double tmp;

  if (miCreate->Checked) {
    SGrid->Options = SGrid->Options >> goEditing;
    miCreate->Checked = false;
    N2->Enabled = true;
    N8->Enabled = true;
    N6->Enabled = true;
    N7->Enabled = true;
    Button1->Enabled = true;
    btnOdnomAnaliz->Enabled = true;
    for (i = 1; i <= colcount; i++)
      for (j = 1; j <= rowcount; j++) {
        try {
          tmp = StrToFloat(SGrid->Cells[i][j]);
        }
        catch (EConvertError &) {
          tmp = MISSING_DATA;
        }
        Array->Cell[i][j] = tmp;
      }
    Array->SetFormat(3);
    int nv = Array->NVars + 1;
    filter_num = nv;
    Array->NVars = nv;
    Array->VarName[nv] = "FILTER";
    for (i = 0; i < Array->NCases; i++)
      Array->Cell[filter_num][i + 1] = 1;
  }
  else {
    if ((new TCreateParametersForm(Application))->ShowModal() == 1) {
      Array->NVars  = colcount;
      Array->NCases = rowcount;

      for (i = 1; i <= colcount; i++)
        Array->VarName[i] = ("Var" + IntToStr(i)).c_str();

      for (i = 1; i <= rowcount; i++)
        Array->CaseName[i] = "";

      for (i = 1; i <= colcount; i++)
        for (j = 1; j <= rowcount; j++)
          Array->Cell[i][j] = MISSING_DATA;

      SGrid->Options = SGrid->Options << goEditing;

      miCreate->Checked = true;
      N2->Enabled = false;
      N8->Enabled = false;
      N6->Enabled = false;
      N7->Enabled = false;
      Button1->Enabled = false;
      btnOdnomAnaliz->Enabled = false;
    }
  }
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <dir>
#include "GridArray.h"
#include "Progress.h"
#include "Classification.h"
#include "Sets.h"
#include "Maps.h"
#include "KlMain.h"
#include "Params.h"
#include "WeightUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CGAUGES"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TForm1 *Form1;
TPanel *_Panel;
TCGauge *_Progress;
TArray *Array;

AnsiString PathWork;
AnsiString WorkFileName;

int filter_num = 0;
//---------------------------------------------------------------------------
#define koef_for_union          1.1
#define koef_for_prisoed        1
#define ALPHA                   1
#define SET_CAPTION Form1->Caption = \
                      WorkFileName + " (v" + IntToStr(Array->NVars) + \
                                     ";c" + IntToStr(Array->NCases) + ")"
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

  Array = new TArray(MainGrid, 10, 10);
  _Panel = Form1->Panel3;
  _Progress = Form1->Progress;
  N7->ShortCut = ShortCut(Word('X'), TShiftState() << ssAlt);
  N3->Enabled = false;
  N5->Enabled = false;
  N8->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N7Click(TObject *Sender)
{
  Close();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
  OpenStaDialog->InitialDir = PathWork;
  if (OpenStaDialog->Execute() == true) {
    Array->OpenStaFile(OpenStaDialog->FileName.c_str());
    WorkFileName = OpenStaDialog->FileName.c_str();

    N3->Enabled = true;
    N5->Enabled = true;
    N8->Enabled = true;

    if ((filter_num = Array->VarByName("FILTER")) == 0) {
      int nv = Array->NVars + 1;
      filter_num = nv;
      Array->NVars = nv;
      Array->VarName[nv] = "FILTER";
    }
    for (long i = 1; i <= Array->NCases; i++)
      Array->Cell[filter_num][i] = 1;

    SET_CAPTION;

    WeightForm->SG->RowCount = MainGrid->ColCount - 1;
    WeightForm->SG->Cells[0][0] = "Признаки";
    WeightForm->SG->Cells[1][0] = "Веса";
    for (int i = 1; i <= filter_num; i++) {
      WeightForm->SG->Cells[0][i] = MainGrid->Cells[i][0];
      WeightForm->SG->Cells[1][i] = 1;
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N5Click(TObject *Sender)
{
  SaveStaDialog->InitialDir = PathWork;
  if (SaveStaDialog->Execute() == true) {
    if (ExtractFileExt(SaveStaDialog->FileName.c_str()) == "")
      Array->SaveStaFile((SaveStaDialog->FileName + ".sta").c_str());
    else
      Array->SaveStaFile(SaveStaDialog->FileName.c_str());
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
  ActionList1->Actions[0]->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ActionKlassifExecute(TObject *Sender)
{
  TArray *Res;
  TDoubleArray W, X;
  T2DoubleArray mean;
  TintIntSetMap Classes;
  TintIntSetMapIterator mp;
  TintIntMap Rang;
  TIntArray IK;
  TIntSetIterator p;
  int i, j, k = 6;
  int cl, mean_N;

  W.Length = WeightForm->SG->RowCount - 1;
  for (i = 0; i < WeightForm->SG->RowCount - 1; i++)
    W[i] = StrToFloat(WeightForm->SG->Cells[1][i + 1]);
/*  W[0] = 10;
  W[1] = 3;
  W[2] = 13;
  W[3] = 8;
  W[4] = 16;
  W[5] = 4;
  W[6] = 17;
  W[7] = 4;
  W[8] = 3;
  W[9] = 15;
  W[10] = 16;*/

  Classification(Array->SubTArrayIf(filter_num, 1), W, Classes, IK, k, filter_num - 1);

  for (mp = Classes.begin(); mp != Classes.end(); mp++)
    Rang[(*mp).first] = (*mp).second.size();
  WriteMap(Rang, "out\\Rang.txt");

  Res = new TArray(SG1);

  Res->VarName[1] = "Ncl";
  Res->VarName[2] = "N";
  for (i = 0; i < filter_num - 1; i++)
    Res->VarName[i + 3] = Array->VarName[i + 1];

  mean.Length = Classes.size();
  for (i = 0; i < mean.Length; i++)
    mean[i].Length = WeightForm->SG->RowCount - 1;
  cl = 0;
  j = 1;
  for (mp = Classes.begin(); mp != Classes.end(); mp++) {
    for (i = 0; i < mean[cl].Length; i++)
      mean[cl][i] = 0;
    mean_N = 0;
    for (p = (*mp).second.begin(); p != (*mp).second.end(); p++) {
      Res->Cell[1][j] = (*mp).first;
      Res->Cell[2][j] = *p;
      for (i = 0; i < filter_num - 1; i++) {
        Res->Cell[i + 3][j] = Array->Cell[i + 1][*p + 1];
        mean[cl][i] += Array->Cell[i + 1][*p + 1];
      }
      mean_N++;
      j++;
    }
    for (i = 0; i < mean[cl].Length; i++)
      mean[cl][i] /= mean_N;
    Res->Cell[1][j] = (*mp).first;
    for (i = 0; i < mean[cl].Length; i++)
      Res->Cell[i + 3][j] = mean[cl][i];
    j++;
    cl++;
  }
  Res->SaveStaFile("out\\Result.sta");

  Res->NVars  = 4;
  Res->NCases = Array->NCases;
  Res->VarName[1] = "N";
  Res->VarName[2] = "Obs";
  Res->VarName[3] = "K1";
  Res->VarName[4] = "Delta";
  W[0] = 0;

  double r0, r1;
  int t, t0, t1;

  X.Length = W.Length;
  for (i = 0; i < Res->NCases; i++) {
    for (t = 0; t < X.Length; t++)
      X[t] = Array->Cell[t + 1][i + 1];
    t0 = t1 = -1;
    for (j = 0; j < mean.Length; j++) {
      if (mean[j][0] >= 0.5 && t1 == -1) {
        t1 = j;
        continue;
      }
      if (mean[j][0] <  0.5 && t0 == -1) {
        t0 = j;
        continue;
      }
      if (mean[j][0] >= 0.5 && metrica(X, mean[j], W) < metrica(X, mean[t1], W))
        t1 = j;
      if (mean[j][0] < 0.5  && metrica(X, mean[j], W) < metrica(X, mean[t0], W))
        t0 = j;
    }
    if ((t0 == 0 && mean[0][0] >= 0.5) ||
        (t1 == 0 && mean[0][0] <  0.5)) {
      Application->MessageBox("...", "Ошибка", MB_OK);
      return;
    }
    r0 = metrica(X, mean[t0], W);
    r1 = metrica(X, mean[t1], W);
    Res->Cell[1][i + 1] = i + 1;
    Res->Cell[2][i + 1] = Array->Cell[1][i + 1];
    Res->Cell[3][i + 1] = (r0 / (1 - mean[t0][0])) /
                          (0.8 * r1 / mean[t1][0] + r0 / (1 - mean[t0][0]));
    if ((Res->Cell[2][i + 1] == 0 && Res->Cell[3][i + 1] >= StrToFloat(ePorog->Text)) ||
        (Res->Cell[2][i + 1] == 1 && Res->Cell[3][i + 1] <  StrToFloat(ePorog->Text)))
      Res->Cell[4][i + 1] = 1;
    else
      Res->Cell[4][i + 1] = MISSING_DATA;
  }
/*  for (i = 0; i < Res->NCases; i++) {
    tmp1 = tmp2 = 0;
    for (j = 0; j < mean.Length; j++) {
      X.Length = W.Length;
      for (int t = 0; t < X.Length; t++)
        X[t] = Array->Cell[t + 1][i + 1];
      tmp1 += exp(-ALPHA * metrica(X, mean[j], W)) * mean[j][0];
      tmp2 += exp(-ALPHA * metrica(X, mean[j], W));
    }
    Res->Cell[1][i + 1] = i + 1;
    Res->Cell[2][i + 1] = Array->Cell[1][i + 1];
    Res->Cell[3][i + 1] = tmp1 / tmp2;
  }*/
  Res->SaveStaFile("out\\Result_K1.sta");

  delete Res;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N3Click(TObject *Sender)
{
  ParamsForm->ShowModal();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N8Click(TObject *Sender)
{
  WeightForm->ShowModal();
}
//---------------------------------------------------------------------------


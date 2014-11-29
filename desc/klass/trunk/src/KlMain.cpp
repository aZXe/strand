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

    if ((filter_num = Array->VarByName("FILTER")) == 0) {
      int nv = Array->NVars + 1;
      filter_num = nv;
      Array->NVars = nv;
      Array->VarName[nv] = "FILTER";
      for (long i = 1; i <= Array->NCases; i++)
        Array->Cell[filter_num][i] = 1;
    }

    SET_CAPTION;
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
void __fastcall TForm1::N3Click(TObject *Sender)
{
  ActionList1->Actions[0]->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  ActionList1->Actions[0]->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
  ActionList1->Actions[1]->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
  ActionList1->Actions[2]->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
  ActionList1->Actions[3]->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ActionProseinExecute(TObject *Sender)
{
  T2DoubleArray A;
  TIntArray IA;
  TDoubleArray m, s2, R;
  int i, j, n, p, p0;
  int n_max = Array->Max(filter_num);
  double s, r_m, r_s, alpha = StrToFloat(eAlphaProsein->Text);

  ProgressCaption("Просеивание классов...");
  ProgressShow();
  ProgressSet(0);
  progress_step = 100. / n_max;
  p0 = -1;
  n = 1;
  while (true) {
    A = Array->SubTArrayIf(filter_num, n, &IA);

    p = A.Length;
    if (p > 3) {
      m.Length  = filter_num - 1;
      for (j = 0; j < filter_num - 1; j++) {
        for (m[j] = i = 0; i < p; i++)
          m[j] += A[i][j];
        m[j] /= p;
      }

      R.Length = p;
      for (i = 0; i < p; i++)
        R[i] = metrica(m, A[i]);

      for (r_m = i = 0; i < p; i++)
        r_m += R[i];
      r_m /= p;
      
      for (r_s = i = 0; i < p; i++)
        r_s += (R[i] - r_m) * (R[i] - r_m);
      r_s = sqrt(r_s / (p - 1));

      for (i = 0; i < p; i++)
        if (R[i] >= r_m + alpha * r_s)
          Array->Cell[filter_num][IA[i]] = 0;
    }

    if (p == 0)
      if (n < n_max) {
        continue;
      }
      else break;
    if (p <= 3 || p == p0) {
      n++;
      ProgressInc();
      p0 = -1;
    }
    p0 = p;
  }
  ProgressSet(100);
  ProgressHide();

  eLeft->Text = IntToStr(Array->NCases - Array->CountIf(filter_num, 0));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ActionUnionExecute(TObject *Sender)
{
  T2DoubleArray A, B, R, A1, A2;
  TIntArray IA1, IA2;
  double min;
  int i, j, k, p, u = 0;
  int n, m = filter_num - 1;
  bool b = true;

  if (eFirst->Text != "") n = StrToInt(eFirst->Text);
  else b = false;

  ProgressCaption("Объединение классов...");
  ProgressShow();
  ProgressSet(0);

  if (b) {
    progress_step = 20. / (n - 1);

    A1.Length = n - 1;
    for (i = 0; i < n - 1; i++) {
      A = Array->SubTArrayIf(filter_num, i + 1);
      A1[i].Length = m;
      for (k = 0; k < m; k++) {
        A1[i][k] = 0;
        for (j = 0; j < A.Length; j++)
          A1[i][k] += A[j][k];
        A1[i][k] /= A.Length;
      }
      ProgressInc();
    }
  }
  else n = 1;

  ProgressSet(20);

  A2.Length = Array->NCases;
  p = 0;
  while (true) {
    A = Array->SubTArrayIf(filter_num, n + p);
    if (A.Length == 0) break;

    A2[p].Length = m;
    for (k = 0; k < m; k++) {
      A2[p][k] = 0;
      for (j = 0; j < A.Length; j++)
        A2[p][k] += A[j][k];
      A2[p][k] /= A.Length;
    }

    p++;
  }
  A2.Length = p;

  if (!b) {
    A1 = A2;
    n = p + 1;
  }

  ProgressSet(40);
  progress_step = 20. / (n - 1);

  R.Length = n - 1;
  for (i = 0; i < n - 1; i++) {
    R[i].Length = p;
    for (j = 0; j < p; j++)
      R[i][j] = metrica(A1[i], A2[j]);
    ProgressInc();
  }

  IA1.Length = n - 1;
  for (i = 0; i < n - 1; i++) {
    min = MAXDOUBLE;
    for (j = 0; j < p; j++)
      if (min > R[i][j]) {
        min = R[i][j];
        IA1[i] = j;
      }
  }

  IA2.Length = p;
  for (i = 0; i < p; i++) {
    min = MAXDOUBLE;
    for (j = 0; j < n - 1; j++)
      if (min > R[j][i]) {
        min = R[j][i];
        IA2[i] = j;
      }
  }

  ProgressSet(70);
  progress_step = 30. / (n - 1);

  for (i = 0; i < n - 1; i++) {
    if (i == IA2[IA1[i]]) {
      double s_r1, s_r2, s_r;
      TDoubleArray s;

      A = Array->SubTArrayIf(filter_num, i + 1);
      if (b) B = Array->SubTArrayIf(filter_num, n + IA1[i]);
      else   B = Array->SubTArrayIf(filter_num, IA1[i] + 1);

      if (A.Length == 0 || B.Length == 0) {
        if (b) Array->Replace(filter_num, i + 1, 0);
        if (b) Array->Replace(filter_num, n + IA1[i], 0);
//        else Array->Replace(filter_num, IA1[i] + 1, 0);
        continue;
      }

      s.Length = m;
      for (k = 0; k < m; k++) {
        s[k] = 0;
        for (j = 0; j < A.Length; j++)
          s[k] += A[j][k];
        for (j = 0; j < B.Length; j++)
          s[k] += B[j][k];
        s[k] /= A.Length + B.Length;
      }

      s_r = s_r1 = s_r2 = 0; 
      for (j = 0; j < A.Length; j++) {
        s_r1 += metrica(A[j], A1[i]);
        s_r  += metrica(A[j], s);
      }
      for (j = 0; j < B.Length; j++) {
        s_r2 += metrica(B[j], A2[IA1[i]]);
        s_r  += metrica(B[j], s);
      }
      s_r1 /= A.Length;
      s_r2 /= B.Length;
      s_r  /= A.Length + B.Length;

      if (s_r <= koef_for_union * max(s_r1, s_r2)) {
        if (b) Array->Replace(filter_num, n + IA1[i], i + 1);
        else Array->Replace(filter_num, IA1[i] + 1, i + 1);
        u++;
      }
      else
        if (b) Array->Replace(filter_num, i + 1, 0);
    }

    ProgressInc();
  }

  int n_max = Array->Max(filter_num);

  if (b)
    for (i = 0; i < n - 1; i++)
      if (i != IA2[IA1[i]]) {
        Array->Replace(filter_num, i + 1, 0);
        if (b) Array->Replace(filter_num, n + IA1[i], 0);
        else Array->Replace(filter_num, IA1[i] + 1, 0);
      }

  if(b)
    for (i = n; i <= n_max; i++)
      Array->Replace(filter_num, i, 0);

  ProgressSet(100);
  ProgressHide();

  eUnions->Text = IntToStr(u);
  eLeft->Text = IntToStr(Array->NCases - Array->CountIf(filter_num, 0));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ActionPrisoedExecute(TObject *Sender)
{
  T2DoubleArray A;
  TDoubleArray sum;
  int i, j, v, c, p = 0;
  int n_max = Array->Max(filter_num), m = filter_num - 1;
  double d1, d2, m1, m2, D1, D2;

  ProgressCaption("Присоединение точек...");
  ProgressShow();
  ProgressSet(0);
  progress_step = 100. / n_max;

  sum.Length  = m;
  for (i = 1; i <= n_max; i++) {
    A = Array->SubTArrayIf(filter_num, i);
    if (A.Length == 0) {
      ProgressInc();
      continue;
    }

    for (v = 0; v < m; v++) {
      sum[v] = 0;
      for (c = 0; c < A.Length; c++)
        sum[v] += A[c][v];
    }

    for (j = 1; j <= Array->NCases; j++)
      if (Array->Cell[filter_num][j] == 0) {
        D1 = D2 = 0;
        for (v = 0; v < m; v++) {
          m1 = sum[v] / A.Length;
          m2 = (sum[v] + Array->Cell[v + 1][j]) / (A.Length + 1);
          d1 = d2 = 0;
          for(c = 0; c < A.Length; c++) {
            d1 += (A[c][v] - m1) * (A[c][v] - m1);
            d2 += (A[c][v] - m2) * (A[c][v] - m2);
          }
          d2 += (Array->Cell[v + 1][j] - m2) * (Array->Cell[v + 1][j] - m2);
          D1 += d1 / (A.Length - 1);
          D2 += d2 /  A.Length;
        }
        if (D2 <= koef_for_prisoed * D1) {
          Array->Cell[filter_num][j] = i;
          p++;
        }
      }
    ProgressInc();
  }

  ProgressSet(100);
  ProgressHide();

  ePrisoed->Text = IntToStr(p);
  eLeft->Text = IntToStr(Array->NCases - Array->CountIf(filter_num, 0));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ActionKlassifExecute(TObject *Sender)
{
  TArray *Res;
  TintIntSetMap Classes;
  TintIntSetMapIterator mp;
  TintIntMap Rang;
  TIntArray IK;
  TIntSetIterator p;
  int i, j, k = 6;

  Classification(Array->SubTArrayIf(filter_num, 1), Classes, IK, k, filter_num - 1);
  for (mp = Classes.begin(); mp != Classes.end(); mp++)
    Rang[(*mp).first] = (*mp).second.size();
  WriteMap(Rang, "out\\Rang.txt");

  Res = new TArray(SG1);

  Res->VarName[1] = "Ncl";
  Res->VarName[2] = "N";
  for (i = 0; i < filter_num - 1; i++)
    Res->VarName[i + 3] = Array->VarName[i + 1];
  j = 1;
  for (mp = Classes.begin(); mp != Classes.end(); mp++)
    for (p = (*mp).second.begin(); p != (*mp).second.end(); p++) {
      Res->Cell[1][j] = (*mp).first;
      Res->Cell[2][j] = *p;
      for (i = 0; i < filter_num - 1; i++)
        Res->Cell[i + 3][j] = Array->Cell[i + 1][*p + 1];
      j++;
    }
  Res->SaveStaFile("out\\Result.sta");

  delete Res;
}
//---------------------------------------------------------------------------


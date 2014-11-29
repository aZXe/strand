//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <math.h>
#include "DArrayTypes.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
double Corr[7][7] = {{ 1.0,-0.8,-0.4,-0.7,-0.3, 0.0, 0.0},
                     {-0.8, 1.0, 0.1, 0.4,-0.5, 0.0, 0.0},
                     {-0.4, 0.1, 1.0, 0.7,-0.3, 0.0, 0.0},
                     {-0.7, 0.4, 0.7, 1.0,-0.4, 0.0, 0.0},
                     {-0.3,-0.5,-0.3,-0.4, 1.0, 0.0, 0.0},
                     { 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0},
                     { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0}};
TIntArray Z, Z1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
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
//    return true;
    return;
  }

  for (i = a; i < N; i++) {
    Y = new TIntArray;
    (*Y) = X->Copy();
    A(Y, i);
/*
    if (A(Y, i)) {
      if (Z.Length > Z1.Length) {
        Z1 = Z.Copy();
        delete X;
        return true;
      }
    }*/
  }

  delete X;
//  return false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  TIntArray *X;
  int i;
  bool j;

  X = new TIntArray;
  X->Length = 7;
  for (i = 0; i < 7; i++)
    (*X)[i] = i;

  Z1.Length = 0;
  A(X, -1);
/*
  if (j) Edit1->Text = "True";
  else Edit1->Text = "False";
*/
  if (Z1.Length > 0)
    for (i = 0; i < Z1.Length; i++)
      ListBox1->Items->Add(IntToStr(Z1[i]));
}
//---------------------------------------------------------------------------


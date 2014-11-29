//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <stdio.h>
#include "ChildRegrMemoWin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TChildRegrMemo *ChildRegrMemo;
//---------------------------------------------------------------------------
__fastcall TChildRegrMemo::TChildRegrMemo(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TChildRegrMemo::FormCreate(TObject *Sender)
{
  Iter = 0;        
}
//---------------------------------------------------------------------------
void __fastcall TChildRegrMemo::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;        
}
//---------------------------------------------------------------------------
void __fastcall TChildRegrMemo::SetHeader(TAnsiStringArray H)
{
  AnsiString hdr;
  char buf[20];
  int i;

  hdr = " Num";
  for (i = 0; i < H.Length; i++) {
    sprintf(buf, " %8s", H[i].c_str());
    hdr += (AnsiString)buf;
  }
  meParameters->Lines->Clear();
  meParameters->Lines->Add(hdr);
}
//---------------------------------------------------------------------------
void __fastcall TChildRegrMemo::SetIteration(TDoubleArray A)
{
  AnsiString ln;
  char buf[20];
  int i;

  sprintf(buf, " %3d", Iter++);
  ln = (AnsiString)buf;
  for (i = 0; i < A.Length; i++) {
    sprintf(buf, " %8.5lf", A[i]);
    ln += (AnsiString)buf;
  }

  if (meParameters->Lines->Count > 10)
    meParameters->Lines->Delete(1);
  meParameters->Lines->Add(ln);
}
//---------------------------------------------------------------------------
void __fastcall TChildRegrMemo::SetFunction(AnsiString F)
{
  meEquation->Lines->SetText(F.c_str());
}
//---------------------------------------------------------------------------


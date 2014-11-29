//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "CreateParameters.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCreateParametersForm *CreateParametersForm;

extern int rowcount, colcount;
//---------------------------------------------------------------------------
__fastcall TCreateParametersForm::TCreateParametersForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCreateParametersForm::Button1Click(TObject *Sender)
{
  colcount = UpDown1->Position;
  rowcount = UpDown2->Position;
  ModalResult = 1;
}
//---------------------------------------------------------------------------
void __fastcall TCreateParametersForm::Button2Click(TObject *Sender)
{
  ModalResult = -1;
}
//---------------------------------------------------------------------------
void __fastcall TCreateParametersForm::FormClose(TObject *Sender, TCloseAction &Action)
{
  Action = caFree;  
}
//---------------------------------------------------------------------------

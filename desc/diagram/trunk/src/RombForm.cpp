//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "RombForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TRombProp *RombProp;
//---------------------------------------------------------------------------
__fastcall TRombProp::TRombProp(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TRombProp::bCancelClick(TObject *Sender)
{
  ModalResult = 0;
}
//---------------------------------------------------------------------------
void __fastcall TRombProp::bOkClick(TObject *Sender)
{
  ModalResult = 1;
}
//---------------------------------------------------------------------------


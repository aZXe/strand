//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FPSave.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFPSaveForm *FPSaveForm;
//---------------------------------------------------------------------------
__fastcall TFPSaveForm::TFPSaveForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFPSaveForm::bCancelClick(TObject *Sender)
{
  ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TFPSaveForm::bOkClick(TObject *Sender)
{
  if (eName->Text.Length() > 0)
    ModalResult = mrOk;
  else
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

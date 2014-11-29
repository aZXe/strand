//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Params.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TParamsForm *ParamsForm;
//---------------------------------------------------------------------------
__fastcall TParamsForm::TParamsForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TParamsForm::Button1Click(TObject *Sender)
{
  Close();        
}
//---------------------------------------------------------------------------


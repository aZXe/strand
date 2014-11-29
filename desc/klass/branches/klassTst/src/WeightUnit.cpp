//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "WeightUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWeightForm *WeightForm;
//---------------------------------------------------------------------------
__fastcall TWeightForm::TWeightForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TWeightForm::Button1Click(TObject *Sender)
{
  Close();        
}
//---------------------------------------------------------------------------

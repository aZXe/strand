//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ConnectForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TConnprop *Connprop;
//---------------------------------------------------------------------------
__fastcall TConnprop::TConnprop(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

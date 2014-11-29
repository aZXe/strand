//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ChildLogWin.h"
#include "Logging.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
//--------------------------------------------------------------------- 
__fastcall TChildLog::TChildLog(TComponent *Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------
void __fastcall TChildLog::FormClose(TObject *Sender, TCloseAction &Action)
{
  Action = caNone;
}
//---------------------------------------------------------------------
void __fastcall TChildLog::FormDestroy(TObject *Sender)
{
  LogAdd("---------------------------- END " + DateTimeToStr(Now()) +
         " ----------------------------");
}
//---------------------------------------------------------------------------
void __fastcall TChildLog::FormResize(TObject *Sender)
{
  int l = Memo1->Text.Length();

  if (l == 0) return;

  Memo1->SelStart = l - 1;
  Memo1->SelLength = 1;
}
//---------------------------------------------------------------------------


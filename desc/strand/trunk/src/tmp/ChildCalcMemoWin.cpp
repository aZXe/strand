//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ChildCalcMemoWin.h"
#include "Logging.h"
//#include "Main.h"
#include "Optimization.h"
#include "ChildGridWin.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
//---------------------------------------------------------------------
extern TChildGrid *MainChildGrid;

AnsiString dep;
int dep_n;
//---------------------------------------------------------------------
__fastcall TChildCalcMemo::TChildCalcMemo(TComponent *Owner)
	: TForm(Owner)
{
}
//--------------------------------------------------------------------- 
void __fastcall TChildCalcMemo::FormClose(TObject *Sender, TCloseAction &Action)
{
  Action = caFree;
}
//---------------------------------------------------------------------
void __fastcall TChildCalcMemo::btnStartClick(TObject *Sender)
{
  AnsiString tmp;
  int i;

  if (!isActiveData()) return;
  if (Memo1->Lines->Count == 0) return;
  else tmp = Memo1->Lines->Strings[0];
  for (i = 1; i < Memo1->Lines->Count; i++)
    tmp += Memo1->Lines->Strings[i];

  i = 1;
  while (i <= tmp.Length())
    if (tmp[i] == ' ') tmp.Delete(i, 1);
    else i++;
  tmp = tmp.UpperCase();

  LogAdd("Функция: " + tmp);

  i = tmp.Pos("=");
  if (i == 0) {
    LogAdd("!!!Пропущен символ '='");
    return;
  }
  dep = tmp.SubString(1, i - 1);

  dep_n = MainChildGrid->A->VarByName(dep);
  if (dep_n == 0) {
    LogAdd("!!!'" + dep + "' не является именем переменной в файле данных");
    return;
  }
  else
    LogAdd("\tЗависимая переменная: '" + dep + "', N" + IntToStr(dep_n));

  normal_optim(tmp.SubString(i + 1, tmp.Length() - i), dep_n, NULL, NULL);
}
//---------------------------------------------------------------------------
void __fastcall TChildCalcMemo::Button1Click(TObject *Sender)
{
  TIntArray iX;
  int i;

  dep_n = MainChildGrid->A->VarByName(Memo2->Lines->Strings[0].UpperCase());
  iX.Length = Memo2->Lines->Count - 1;
  for (i = 0; i < iX.Length; i++)
    iX[i] = MainChildGrid->A->VarByName(Memo2->Lines->Strings[i + 1].UpperCase());

  sub_optim(iX, 0.5, 1.5, dep_n);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ChildGridWin.h"
#include "Logging.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
//---------------------------------------------------------------------
extern void __fastcall EnableDataInterfaceItems(bool);
extern void CloseAllDependentWindows(void);

extern TChildGrid         *MainChildGrid;
//---------------------------------------------------------------------
__fastcall TChildGrid::TChildGrid(TComponent *Owner)
	: TForm(Owner)
{
  A = new TArray(StringGrid1);
  if (A == NULL)
    throw Sysutils::Exception("Ошибка при создании структуры TArray.");
}
//---------------------------------------------------------------------
__fastcall TChildGrid::~TChildGrid()
{
  delete A;
}
//---------------------------------------------------------------------
void __fastcall TChildGrid::FormClose(TObject *Sender, TCloseAction &Action)
{
  Action = caFree;
  if (MainChildGrid == this) {
    EnableDataInterfaceItems(false);
    CloseAllDependentWindows();
    MainChildGrid = NULL;
  }
}
//---------------------------------------------------------------------

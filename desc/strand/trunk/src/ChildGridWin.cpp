//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TreeConstructor.h"
#include "ChildGridWin.h"
#include "Logging.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
//---------------------------------------------------------------------
extern TTreeConstructorForm  *MainTreeConstructorForm;
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
void __fastcall TChildGrid::StringGrid1DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
  AnsiString str = StringGrid1->Cells[ACol][ARow];

  if (ACol == StringGrid1->Col || ARow == StringGrid1->Row)
    StringGrid1->Canvas->Font->Style = TFontStyles() << fsBold;
  else
    StringGrid1->Canvas->Font->Style = TFontStyles();

  StringGrid1->Canvas->TextRect(Rect,
                                Rect.Left + 2,
                                Rect.Top + (Rect.Bottom - Rect.Top - Canvas->TextHeight(str)) / 2,
                                str);
}
//---------------------------------------------------------------------------
void __fastcall TChildGrid::StringGrid1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  StringGrid1->Refresh();
  UpdateDependencies();
}
//---------------------------------------------------------------------------
void __fastcall TChildGrid::StringGrid1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  StringGrid1->Refresh();
  UpdateDependencies();
}
//---------------------------------------------------------------------------
void __fastcall TChildGrid::StringGrid1KeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  StringGrid1->Refresh();
  UpdateDependencies();
}
//---------------------------------------------------------------------------
void __fastcall TChildGrid::StringGrid1MouseWheelDown(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
  StringGrid1->Refresh();
  UpdateDependencies();
}
//---------------------------------------------------------------------------
void __fastcall TChildGrid::StringGrid1MouseWheelUp(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
  StringGrid1->Refresh();
  UpdateDependencies();
}
//---------------------------------------------------------------------------
void TChildGrid::UpdateDependencies(void)
{
  if (MainTreeConstructorForm &&
      MainTreeConstructorForm->chbIndicatorVisible->Checked) {
    MainTreeConstructorForm->Container->ArrangeElements();
    MainTreeConstructorForm->Container->Repaint();
  }
}
//---------------------------------------------------------------------------
int TChildGrid::CurrentRow(void)
{
  return StringGrid1->Row;
}
//---------------------------------------------------------------------------
int TChildGrid::CurrentColumn(void)
{
  return StringGrid1->Col;
}
//---------------------------------------------------------------------------


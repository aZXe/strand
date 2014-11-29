//----------------------------------------------------------------------------
#ifndef ChildGridWinH
#define ChildGridWinH
//----------------------------------------------------------------------------
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
#include <StdCtrls.hpp>
#include <Grids.hpp>

#include "GridArray.h"
//----------------------------------------------------------------------------
class TChildGrid : public TForm
{
__published:
        TStringGrid *StringGrid1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall StringGrid1DrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
        void __fastcall StringGrid1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall StringGrid1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall StringGrid1KeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall StringGrid1MouseWheelDown(TObject *Sender,
          TShiftState Shift, TPoint &MousePos, bool &Handled);
        void __fastcall StringGrid1MouseWheelUp(TObject *Sender,
          TShiftState Shift, TPoint &MousePos, bool &Handled);
private:
  void UpdateDependencies(void);
public:
        TArray *A;
	virtual __fastcall TChildGrid(TComponent *Owner);
	__fastcall ~TChildGrid();
  int CurrentRow(void);
  int CurrentColumn(void);
};
//----------------------------------------------------------------------------
#endif	

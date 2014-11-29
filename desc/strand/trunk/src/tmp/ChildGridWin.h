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
private:
public:
        TArray *A;
	virtual __fastcall TChildGrid(TComponent *Owner);
	__fastcall ~TChildGrid();
};
//----------------------------------------------------------------------------
#endif	

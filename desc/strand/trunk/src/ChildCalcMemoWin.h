//----------------------------------------------------------------------------
#ifndef ChildCalcMemoWinH
#define ChildCalcMemoWinH
//----------------------------------------------------------------------------
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
#include <StdCtrls.hpp>
//----------------------------------------------------------------------------
class TChildCalcMemo : public TForm
{
__published:
	TMemo *Memo1;
        TButton *btnStart;
        TLabel *Label1;
        TMemo *Memo2;
        TButton *Button1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall btnStartClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:
public:
	virtual __fastcall TChildCalcMemo(TComponent *Owner);
};
//----------------------------------------------------------------------------
#endif	

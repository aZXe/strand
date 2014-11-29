//----------------------------------------------------------------------------
#ifndef ChildLogWinH
#define ChildLogWinH
//----------------------------------------------------------------------------
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
#include <StdCtrls.hpp>
//----------------------------------------------------------------------------
class TChildLog : public TForm
{
__published:
	TMemo *Memo1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
private:
public:
	virtual __fastcall TChildLog(TComponent *Owner);
};
//----------------------------------------------------------------------------
#endif	

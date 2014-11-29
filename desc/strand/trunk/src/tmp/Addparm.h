//---------------------------------------------------------------------------
#ifndef addparmH
#define addparmH
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Buttons.hpp>
//---------------------------------------------------------------------------
class TWinAddParm : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TLabel *Label2;
        TComboBox *ComboBox2;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall ComboBox2Change(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TWinAddParm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TWinAddParm *WinAddParm;
//---------------------------------------------------------------------------
#endif

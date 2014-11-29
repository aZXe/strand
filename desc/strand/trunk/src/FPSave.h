//---------------------------------------------------------------------------

#ifndef FPSaveH
#define FPSaveH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFPSaveForm : public TForm
{
__published:	// IDE-managed Components
        TLabel *lName;
        TEdit *eName;
        TLabel *lPrefix;
        TButton *bOk;
        TButton *bCancel;
        void __fastcall bCancelClick(TObject *Sender);
        void __fastcall bOkClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFPSaveForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFPSaveForm *FPSaveForm;
//---------------------------------------------------------------------------
#endif

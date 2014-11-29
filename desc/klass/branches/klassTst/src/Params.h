//---------------------------------------------------------------------------

#ifndef ParamsH
#define ParamsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TParamsForm : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TEdit *Edit5;
        TEdit *Edit6;
        TEdit *Edit7;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TEdit *Edit8;
        TLabel *Label8;
        TEdit *Edit9;
        TLabel *Label9;
        TEdit *Edit10;
        TLabel *Label10;
        TCheckBox *cbFirstEtap;
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TParamsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TParamsForm *ParamsForm;
//---------------------------------------------------------------------------
#endif

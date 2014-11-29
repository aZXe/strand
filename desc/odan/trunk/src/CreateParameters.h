//---------------------------------------------------------------------------

#ifndef CreateParametersH
#define CreateParametersH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TCreateParametersForm : public TForm
{
__published:	// IDE-managed Components
  TGroupBox *GroupBox1;
  TLabel *Label1;
  TEdit *Edit1;
  TLabel *Label2;
  TUpDown *UpDown1;
  TUpDown *UpDown2;
  TEdit *Edit2;
  TButton *Button1;
  TButton *Button2;
  void __fastcall Button1Click(TObject *Sender);
  void __fastcall Button2Click(TObject *Sender);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
  __fastcall TCreateParametersForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCreateParametersForm *CreateParametersForm;
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------
#ifndef ConnectFormH
#define ConnectFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TConnprop : public TForm
{
__published:	// IDE-managed Components
        TEdit *cText1;
        TEdit *cText2;
        TLabel *Label1;
        TLabel *Label2;
private:	// User declarations
public:		// User declarations
        __fastcall TConnprop(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TConnprop *Connprop;
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------

#ifndef WeightUnitH
#define WeightUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TWeightForm : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TStringGrid *SG;
        TButton *Button1;
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TWeightForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWeightForm *WeightForm;
//---------------------------------------------------------------------------
#endif

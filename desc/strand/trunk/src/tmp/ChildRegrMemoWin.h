//---------------------------------------------------------------------------
#ifndef ChildRegrMemoWinH
#define ChildRegrMemoWinH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "DArrayTypes.h"
//---------------------------------------------------------------------------
class TChildRegrMemo : public TForm
{
__published:	// IDE-managed Components
        TMemo *meEquation;
        TMemo *meParameters;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
        int Iter;
public:		// User declarations
        __fastcall TChildRegrMemo(TComponent* Owner);
        void __fastcall SetHeader(TAnsiStringArray H);
        void __fastcall SetIteration(TDoubleArray A);
        void __fastcall SetFunction(AnsiString F);
};
//---------------------------------------------------------------------------
extern PACKAGE TChildRegrMemo *ChildRegrMemo;
//---------------------------------------------------------------------------
#endif

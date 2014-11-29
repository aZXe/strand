//---------------------------------------------------------------------------
#ifndef RombFormH
#define RombFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include "element.h"
#include "block.h"
//---------------------------------------------------------------------------
  class TRombProp : public TForm{
    __published:	// IDE-managed Components
    TEdit *eText;
        TLabel *Label1;
        TButton *bOk;
        TButton *bCancel;
        void __fastcall bCancelClick(TObject *Sender);
        void __fastcall bOkClick(TObject *Sender);
       // void __fastcall eTextChange(TObject *Sender);
    private:	// User declarations
    public:		// User declarations
    TElement *Element;
    __fastcall TRombProp(TComponent* Owner);
  };
//---------------------------------------------------------------------------
  extern PACKAGE TRombProp *RombProp;
//---------------------------------------------------------------------------
#endif

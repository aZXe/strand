//---------------------------------------------------------------------------
#ifndef BlockFormH
#define BlockFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

#include "ElementPropertyU.h"
#include <Buttons.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TBlockPropertyForm : public TElementProperty
{
__published:	// IDE-managed Components
  TLabel *Label1;
  TButton *bOk;
  TButton *bCancel;
        TColorDialog *ColorDialog;
        TShape *shBackground;
        TLabel *Label2;
        TShape *shForeground;
        TLabel *Label3;
        TPanel *pFont;
        TFontDialog *FontDialog;
        TGroupBox *gbLineWidth;
        TSpeedButton *sbWidth1;
        TSpeedButton *sbWidth2;
        TSpeedButton *sbWidth3;
        TSpeedButton *sbWidth4;
        TSpeedButton *sbWidth5;
        TSpeedButton *sbWidth6;
        TMemo *mText;
  void __fastcall bCancelClick(TObject *Sender);
  void __fastcall bOkClick(TObject *Sender);
  void __fastcall FormActivate(TObject *Sender);
        void __fastcall shBackgroundMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall shForegroundMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall pFontClick(TObject *Sender);

private:
  TSpeedButton *LineWidths[6];

public:
  __fastcall TBlockPropertyForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBlockPropertyForm *BlockPropertyForm;
//---------------------------------------------------------------------------
#endif

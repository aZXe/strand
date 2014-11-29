//---------------------------------------------------------------------------
#ifndef BlockIndicatorFormH
#define BlockIndicatorFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

#include "ElementPropertyU.h"
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TBlockIndicatorPropertyForm : public TElementProperty
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
        TShape *shIndicatorBackground;
        TLabel *Label5;
        TShape *shIndicatorForeground;
        TLabel *Label6;
        TLabel *Label7;
        TEdit *ePosition;
        TUpDown *UpDown1;
        TGroupBox *gbLineWidth;
        TSpeedButton *sbWidth1;
        TSpeedButton *sbWidth2;
        TSpeedButton *sbWidth3;
        TSpeedButton *sbWidth4;
        TSpeedButton *sbWidth5;
        TSpeedButton *sbWidth6;
        TMemo *mText;
        TCheckBox *cbIndicatorVisible;
  void __fastcall bCancelClick(TObject *Sender);
  void __fastcall bOkClick(TObject *Sender);
  void __fastcall FormActivate(TObject *Sender);
        void __fastcall shBackgroundMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall shForegroundMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall pFontClick(TObject *Sender);
        void __fastcall shIndicatorBackgroundMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall shIndicatorForegroundMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);

private:
  TSpeedButton *LineWidths[6];

public:
  __fastcall TBlockIndicatorPropertyForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBlockIndicatorPropertyForm *BlockIndicatorPropertyForm;
//---------------------------------------------------------------------------
#endif

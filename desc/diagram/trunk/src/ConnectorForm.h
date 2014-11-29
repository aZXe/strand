//---------------------------------------------------------------------------
#ifndef ConnectorFormH
#define ConnectorFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

#include "ElementPropertyU.h"
#include <Dialogs.hpp>
#include <Buttons.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TConnectorPropertyForm : public TElementProperty
{
__published:	// IDE-managed Components
        TEdit *eTextBegin;
  TLabel *Label1;
  TButton *bOk;
  TButton *bCancel;
        TLabel *Label2;
        TEdit *eTextEnd;
        TFontDialog *FontDialog;
        TColorDialog *ColorDialog;
        TShape *shLine;
        TLabel *Label4;
        TPanel *pFontBegin;
        TGroupBox *gbBeginArrowType;
        TGroupBox *gbEndArrowType;
        TSpeedButton *sbBeginType1;
        TSpeedButton *sbBeginType2;
        TSpeedButton *sbBeginType3;
        TSpeedButton *sbEndType1;
        TSpeedButton *sbEndType2;
        TSpeedButton *sbEndType3;
        TCheckBox *cbBiDirectional;
        TGroupBox *gbLineWidth;
        TSpeedButton *sbWidth1;
        TSpeedButton *sbWidth2;
        TSpeedButton *sbWidth3;
        TSpeedButton *sbWidth4;
        TSpeedButton *sbWidth5;
        TSpeedButton *sbWidth6;
        TSpeedButton *sbBeginType0;
        TSpeedButton *sbEndType0;
        TPanel *pFontEnd;
  void __fastcall bCancelClick(TObject *Sender);
  void __fastcall bOkClick(TObject *Sender);
  void __fastcall FormActivate(TObject *Sender);
        void __fastcall shLineMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall pFontBeginClick(TObject *Sender);
        void __fastcall pFontEndClick(TObject *Sender);

private:
  TSpeedButton *BeginArrowTypes[4];
  TSpeedButton *EndArrowTypes[4];
  TSpeedButton *LineWidths[6];

public:
  __fastcall TConnectorPropertyForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TConnectorPropertyForm *ConnectorPropertyForm;
//---------------------------------------------------------------------------
#endif

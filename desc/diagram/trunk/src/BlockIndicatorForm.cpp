//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "BlockIndicatorForm.h"
#include "BlockIndicator.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ElementPropertyU"
#pragma resource "*.dfm"
TBlockIndicatorPropertyForm *BlockIndicatorPropertyForm;
//---------------------------------------------------------------------------
__fastcall TBlockIndicatorPropertyForm::TBlockIndicatorPropertyForm(TComponent* Owner)
        : TElementProperty(Owner)
{
  LineWidths[0]      = sbWidth1;
  LineWidths[1]      = sbWidth2;
  LineWidths[2]      = sbWidth3;
  LineWidths[3]      = sbWidth4;
  LineWidths[4]      = sbWidth5;
  LineWidths[5]      = sbWidth6;
}
//---------------------------------------------------------------------------
void __fastcall TBlockIndicatorPropertyForm::bCancelClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TBlockIndicatorPropertyForm::bOkClick(TObject *Sender)
{
  int i;

  dynamic_cast<TBlockIndicator *>(e)->Text = mText->Lines->Strings[0];
  dynamic_cast<TBlockIndicator *>(e)->ColorBackground = shBackground->Brush->Color;
  dynamic_cast<TBlockIndicator *>(e)->ColorForeground = shForeground->Brush->Color;
  dynamic_cast<TBlockIndicator *>(e)->TextFont->Assign(pFont->Font);
  dynamic_cast<TBlockIndicator *>(e)->ColorIndicatorBackground = shIndicatorBackground->Brush->Color;
  dynamic_cast<TBlockIndicator *>(e)->ColorIndicatorForeground = shIndicatorForeground->Brush->Color;
  dynamic_cast<TBlockIndicator *>(e)->IndicatorPosition = StrToInt(ePosition->Text) / 100.;
  dynamic_cast<TBlockIndicator *>(e)->IndicatorVisible = cbIndicatorVisible->Checked;

  for (i = 0; i < 6; i++)
    if (LineWidths[i]->Down)
      dynamic_cast<TBlockIndicator *>(e)->LineWidth = i + 1;

  Close();
}
//---------------------------------------------------------------------------
void __fastcall TBlockIndicatorPropertyForm::FormActivate(TObject *Sender)
{
  int i;

//  mText->Lines->Clear();
  mText->Lines->Strings[0] = dynamic_cast<TBlockIndicator *>(e)->Text;
  shBackground->Brush->Color = dynamic_cast<TBlockIndicator *>(e)->ColorBackground;
  shForeground->Brush->Color = dynamic_cast<TBlockIndicator *>(e)->ColorForeground;
  shIndicatorBackground->Brush->Color = dynamic_cast<TBlockIndicator *>(e)->ColorIndicatorBackground;
  shIndicatorForeground->Brush->Color = dynamic_cast<TBlockIndicator *>(e)->ColorIndicatorForeground;
  pFont->Font->Assign(dynamic_cast<TBlockIndicator *>(e)->TextFont);
  ePosition->Text = IntToStr((int)(dynamic_cast<TBlockIndicator *>(e)->IndicatorPosition * 100));
  cbIndicatorVisible->Checked = dynamic_cast<TBlockIndicator *>(e)->IndicatorVisible;

  i = dynamic_cast<TBlockIndicator *>(e)->LineWidth;
  if (i > 6) i = 6;
  if (i < 1) i = 1;
  LineWidths[i - 1]->Down = true;
}
//---------------------------------------------------------------------------
void __fastcall TBlockIndicatorPropertyForm::shBackgroundMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  ColorDialog->Color = shBackground->Brush->Color;
  if (ColorDialog->Execute())
    shBackground->Brush->Color = ColorDialog->Color;
}
//---------------------------------------------------------------------------
void __fastcall TBlockIndicatorPropertyForm::shForegroundMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  ColorDialog->Color = shForeground->Brush->Color;
  if (ColorDialog->Execute())
    shForeground->Brush->Color = ColorDialog->Color;
}
//---------------------------------------------------------------------------
void __fastcall TBlockIndicatorPropertyForm::pFontClick(TObject *Sender)
{
  FontDialog->Font->Assign(pFont->Font);
  if (FontDialog->Execute())
    pFont->Font->Assign(FontDialog->Font);
}
//---------------------------------------------------------------------------
void __fastcall TBlockIndicatorPropertyForm::shIndicatorBackgroundMouseUp(
      TObject *Sender, TMouseButton Button, TShiftState Shift, int X,
      int Y)
{
  ColorDialog->Color = shIndicatorBackground->Brush->Color;
  if (ColorDialog->Execute())
    shIndicatorBackground->Brush->Color = ColorDialog->Color;
}
//---------------------------------------------------------------------------
void __fastcall TBlockIndicatorPropertyForm::shIndicatorForegroundMouseUp(
      TObject *Sender, TMouseButton Button, TShiftState Shift, int X,
      int Y)
{
  ColorDialog->Color = shIndicatorForeground->Brush->Color;
  if (ColorDialog->Execute())
    shIndicatorForeground->Brush->Color = ColorDialog->Color;
}
//---------------------------------------------------------------------------


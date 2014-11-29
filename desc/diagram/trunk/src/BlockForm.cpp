//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "BlockForm.h"
#include "Block.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ElementPropertyU"
#pragma resource "*.dfm"
TBlockPropertyForm *BlockPropertyForm;
//---------------------------------------------------------------------------
__fastcall TBlockPropertyForm::TBlockPropertyForm(TComponent* Owner)
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
void __fastcall TBlockPropertyForm::bCancelClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TBlockPropertyForm::bOkClick(TObject *Sender)
{
  int i;

  dynamic_cast<TBlock *>(e)->Text = mText->Lines->Strings[0];
  dynamic_cast<TBlock *>(e)->ColorBackground = shBackground->Brush->Color;
  dynamic_cast<TBlock *>(e)->ColorForeground = shForeground->Brush->Color;
  dynamic_cast<TBlock *>(e)->TextFont->Assign(pFont->Font);

  for (i = 0; i < 6; i++)
    if (LineWidths[i]->Down)
      dynamic_cast<TBlock *>(e)->LineWidth = i + 1;

  Close();
}
//---------------------------------------------------------------------------
void __fastcall TBlockPropertyForm::FormActivate(TObject *Sender)
{
  int i;

//  mText->Lines->Clear();
  mText->Lines->Strings[0] = dynamic_cast<TBlock *>(e)->Text;
  shBackground->Brush->Color = dynamic_cast<TBlock *>(e)->ColorBackground;
  shForeground->Brush->Color = dynamic_cast<TBlock *>(e)->ColorForeground;
  pFont->Font->Assign(dynamic_cast<TBlock *>(e)->TextFont);

  i = dynamic_cast<TBlock *>(e)->LineWidth;
  if (i > 6) i = 6;
  if (i < 1) i = 1;
  LineWidths[i - 1]->Down = true;
}
//---------------------------------------------------------------------------
void __fastcall TBlockPropertyForm::shBackgroundMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  ColorDialog->Color = shBackground->Brush->Color;
  if (ColorDialog->Execute())
    shBackground->Brush->Color = ColorDialog->Color;
}
//---------------------------------------------------------------------------
void __fastcall TBlockPropertyForm::shForegroundMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  ColorDialog->Color = shForeground->Brush->Color;
  if (ColorDialog->Execute())
    shForeground->Brush->Color = ColorDialog->Color;
}
//---------------------------------------------------------------------------
void __fastcall TBlockPropertyForm::pFontClick(TObject *Sender)
{
  FontDialog->Font->Assign(pFont->Font);
  if (FontDialog->Execute())
    pFont->Font->Assign(FontDialog->Font);
}
//---------------------------------------------------------------------------


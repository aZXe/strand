//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ConnectorForm.h"
#include "Connector.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ElementPropertyU"
#pragma resource "*.dfm"

TConnectorPropertyForm *ConnectorPropertyForm;
//---------------------------------------------------------------------------
__fastcall TConnectorPropertyForm::TConnectorPropertyForm(TComponent* Owner)
        : TElementProperty(Owner)
{
  BeginArrowTypes[0] = sbBeginType0;
  BeginArrowTypes[1] = sbBeginType1;
  BeginArrowTypes[2] = sbBeginType2;
  BeginArrowTypes[3] = sbBeginType3;

  EndArrowTypes[0]   = sbEndType0;
  EndArrowTypes[1]   = sbEndType1;
  EndArrowTypes[2]   = sbEndType2;
  EndArrowTypes[3]   = sbEndType3;

  LineWidths[0]      = sbWidth1;
  LineWidths[1]      = sbWidth2;
  LineWidths[2]      = sbWidth3;
  LineWidths[3]      = sbWidth4;
  LineWidths[4]      = sbWidth5;
  LineWidths[5]      = sbWidth6;
}
//---------------------------------------------------------------------------
void __fastcall TConnectorPropertyForm::bCancelClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TConnectorPropertyForm::bOkClick(TObject *Sender)
{
  int i;

  dynamic_cast<TConnector *>(e)->Text_begin = eTextBegin->Text;
  dynamic_cast<TConnector *>(e)->Text_end   = eTextEnd->Text;
  dynamic_cast<TConnector *>(e)->TextFontBegin->Assign(pFontBegin->Font);
  dynamic_cast<TConnector *>(e)->TextFontEnd->  Assign(pFontEnd->  Font);
  dynamic_cast<TConnector *>(e)->ColorLine      = shLine->     Brush->Color;
  dynamic_cast<TConnector *>(e)->BiDirectional  = cbBiDirectional->Checked;

  for (i = 0; i < 4; i++)
    if (BeginArrowTypes[i]->Down)
      dynamic_cast<TConnector *>(e)->BeginArrowType = i;

  for (i = 0; i < 4; i++)
    if (EndArrowTypes[i]->Down)
      dynamic_cast<TConnector *>(e)->EndArrowType = i;

  for (i = 0; i < 6; i++)
    if (LineWidths[i]->Down)
      dynamic_cast<TConnector *>(e)->LineWidth = i + 1;

  Close();
}
//---------------------------------------------------------------------------
void __fastcall TConnectorPropertyForm::FormActivate(TObject *Sender)
{
  int i;

  eTextBegin->Text = dynamic_cast<TConnector *>(e)->Text_begin;
  eTextEnd->Text   = dynamic_cast<TConnector *>(e)->Text_end;
  pFontBegin->Font->Assign(dynamic_cast<TConnector *>(e)->TextFontBegin);
  pFontEnd->  Font->Assign(dynamic_cast<TConnector *>(e)->TextFontEnd  );
  shLine->     Brush->Color = dynamic_cast<TConnector *>(e)->ColorLine;
  cbBiDirectional->Checked  = dynamic_cast<TConnector *>(e)->BiDirectional;

  i = dynamic_cast<TConnector *>(e)->BeginArrowType;
  if (i > 3) i = 3;
  BeginArrowTypes[i]->Down = true;

  i = dynamic_cast<TConnector *>(e)->EndArrowType;
  if (i > 3) i = 3;
  EndArrowTypes[i]->Down = true;

  i = dynamic_cast<TConnector *>(e)->LineWidth;
  if (i > 6) i = 6;
  if (i < 1) i = 1;
  LineWidths[i - 1]->Down = true;
}
//---------------------------------------------------------------------------
void __fastcall TConnectorPropertyForm::shLineMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  ColorDialog->Color = shLine->Brush->Color;
  if (ColorDialog->Execute())
    shLine->Brush->Color = ColorDialog->Color;
}
//---------------------------------------------------------------------------
void __fastcall TConnectorPropertyForm::pFontBeginClick(TObject *Sender)
{
  FontDialog->Font->Assign(pFontBegin->Font);
  if (FontDialog->Execute())
    pFontBegin->Font->Assign(FontDialog->Font);
}
//---------------------------------------------------------------------------
void __fastcall TConnectorPropertyForm::pFontEndClick(TObject *Sender)
{
  FontDialog->Font->Assign(pFontEnd->Font);
  if (FontDialog->Execute())
    pFontEnd->Font->Assign(FontDialog->Font);
}
//---------------------------------------------------------------------------


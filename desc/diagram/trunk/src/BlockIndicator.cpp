//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#pragma hdrstop

#include "BlockIndicator.h"
#include "Element.h"
//#include "RombForm.h"
//---------------------------------------------------------------------------
TBlockIndicator::TBlockIndicator(TCanvas **_C, int _X, int _Y, TDArrayElement *_Elements,
                                 bool _IndicatorVisible, TElementProperty *_Property)
                                : TBlock(_C, _X, _Y, _Elements, _Property)
{
  IndicatorVisible = _IndicatorVisible;
  position = 0;
  ColorIndicatorBackground = clWhite;
  ColorIndicatorForeground = clGreen;
}
//---------------------------------------------------------------------------
TBlockIndicator::TBlockIndicator(TCanvas **_C, TFileStream *stream, TDArrayElement *_Elements,
                                 TElementProperty *_Property)
                                : TBlock(_C, stream, _Elements, _Property)
{
  stream->Read(&IndicatorPosition, sizeof(IndicatorPosition));
  stream->Read(&IndicatorVisible,  sizeof(IndicatorVisible));
  stream->Read(&ColorIndicatorBackground, sizeof(ColorIndicatorBackground));
  stream->Read(&ColorIndicatorForeground, sizeof(ColorIndicatorForeground));
}
//---------------------------------------------------------------------------
TBlockIndicator::~TBlockIndicator(void)
{
}
//---------------------------------------------------------------------------
void TBlockIndicator::Draw(void)
{
  int ind_width;

  (*C)->Brush->Color = ColorBackground;
  (*C)->Pen->Color   = ColorForeground;
  (*C)->Pen->Width   = LineWidth;
  (*C)->Rectangle(X1, Y1, X2, Y2);

  if (IndicatorVisible) {
    ind_width = (X2 - X1) * 0.25;
    if (ind_width > MAX_INDICATOR_WIDTH) ind_width = MAX_INDICATOR_WIDTH;

    (*C)->Brush->Color = ColorIndicatorBackground;
    (*C)->Pen->Color   = ColorForeground;
    (*C)->Rectangle(X2 - ind_width, Y1, X2, Y2);
    (*C)->Brush->Color = ColorIndicatorForeground;
    (*C)->Pen->Color   = ColorIndicatorForeground;
    (*C)->Rectangle(X2 - ind_width + 1, Y1 + (1 - IndicatorPosition) * (Y2 - Y1 - 1) + 1,
                    X2 - 1,             Y2 - 1);
    (*C)->Brush->Style = bsClear;
    (*C)->Pen->Color   = ColorForeground;
    (*C)->Rectangle(X2 - ind_width, Y1, X2, Y2);
    (*C)->Brush->Style = bsSolid;

    DrawText(X1, Y1, X2 - ind_width - 1, Y2);
  }
  else
    DrawText(X1, Y1, X2, Y2);

  if (Active)
    DrawCorners();
}
//---------------------------------------------------------------------------
void TBlockIndicator::SetPosition(double NewPosition)
{
  position = NewPosition;
  if (position < 0) position  = 0;
  if (position > 1) position  = 1;
}
//---------------------------------------------------------------------------
void TBlockIndicator::Save(TFileStream *stream)
{
  TBlock::Save(stream);

  stream->Write(&IndicatorPosition, sizeof(IndicatorPosition));
  stream->Write(&IndicatorVisible,  sizeof(IndicatorVisible));
  stream->Write(&ColorIndicatorBackground, sizeof(ColorIndicatorBackground));
  stream->Write(&ColorIndicatorForeground, sizeof(ColorIndicatorForeground));
}
//---------------------------------------------------------------------------
void TBlockIndicator::Load(TFileStream *stream)
{
  TBlock::Save(stream);

  stream->Read(&IndicatorPosition, sizeof(IndicatorPosition));
  stream->Read(&IndicatorVisible,  sizeof(IndicatorVisible));
  stream->Read(&ColorIndicatorBackground, sizeof(ColorIndicatorBackground));
  stream->Read(&ColorIndicatorForeground, sizeof(ColorIndicatorForeground));
}
//---------------------------------------------------------------------------
#pragma package(smart_init)


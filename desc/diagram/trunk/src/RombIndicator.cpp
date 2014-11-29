//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#pragma hdrstop

#include "RombIndicator.h"
#include "Element.h"
#include "RombForm.h"
//---------------------------------------------------------------------------
TRombIndicator::TRombIndicator(TCanvas **_C, int _X, int _Y, TDArrayElement *_Elements,
                               bool _IndicatorVisible, TElementProperty *_Property)
                              : TBlockIndicator(_C, _X, _Y, _Elements, _IndicatorVisible, _Property)
{
}
//---------------------------------------------------------------------------
TRombIndicator::TRombIndicator(TCanvas **_C, TFileStream *stream, TDArrayElement *_Elements,
                               TElementProperty *_Property)
                              : TBlockIndicator(_C, stream, _Elements, _Property)
{
}
//---------------------------------------------------------------------------
TRombIndicator::~TRombIndicator(void)
{
}
//---------------------------------------------------------------------------
void TRombIndicator::Draw(void)
{
  int ind_width;

  (*C)->Brush->Color = ColorBackground;
  (*C)->Pen->Color   = ColorForeground;
  (*C)->Pen->Width   = LineWidth;
  (*C)->RoundRect(X1, Y1, X2, Y2, 40, 40);

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

    DrawText(X1, Y1, X2 - ind_width - 1, Y2);
  }
  else
    DrawText(X1, Y1, X2, Y2);

  if (Active)
    DrawCorners();
}
//---------------------------------------------------------------------------
#pragma package(smart_init)


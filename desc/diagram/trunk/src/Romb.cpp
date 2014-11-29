//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#pragma hdrstop

#include "Romb.h"
#include "Element.h"
#include "RombForm.h"
//---------------------------------------------------------------------------
TRomb::TRomb(TCanvas **_C, int _X, int _Y, TDArrayElement *_Elements,
             TElementProperty *_Property) : TBlock(_C, _X, _Y, _Elements, _Property)
{
}
//---------------------------------------------------------------------------
TRomb::TRomb(TCanvas **_C, TFileStream *stream, TDArrayElement *_Elements,
             TElementProperty *_Property) : TBlock(_C, stream, _Elements, _Property)
{
}
//---------------------------------------------------------------------------
TRomb::~TRomb(void)
{
}
//---------------------------------------------------------------------------
void TRomb::Draw(void)
{
  (*C)->Brush->Color = ColorBackground;
  (*C)->Pen->Color   = ColorForeground;
  (*C)->Pen->Width   = LineWidth;
  (*C)->RoundRect(X1, Y1, X2, Y2, 50, 50);

  DrawText(X1, Y1, X2, Y2);

  if (Active)
    DrawCorners();
}
//---------------------------------------------------------------------------
#pragma package(smart_init)


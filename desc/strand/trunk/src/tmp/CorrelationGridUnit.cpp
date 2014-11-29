//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "CorrelationGridUnit.h"
#include "MatrixFunctions.h"
//---------------------------------------------------------------------------
__fastcall TCorrelationGrid::TCorrelationGrid(TArray *_A, TIntSet *_Vars, Classes::TComponent* AOwner)
                                              : TStringGrid(AOwner)
{
  double tmp;
  int i;
  TIntSetIterator ii, jj;

  A = _A;
  Vars = _Vars;
  FLimit = 0.3;
  FIsColor = FIsNumbers = true;
  OnDrawCell = (TDrawCellEvent)&_OnDrawCell;
  DefaultDrawing = true;
  DefaultRowHeight = 20;
  DefaultColWidth  = 20;
  ColWidths[0]  = 70;
  RowHeights[0] = 70;
  Font->Name = "Times New Roman";
  Font->Size = 8;

  RowCount = A->NVars + 1;
  ColCount = RowCount;

  for (i = 1, ii = Vars->begin(); ii != Vars->end(); i++, ii++) {
    Cells[i][0] = A->VarName[*ii];
    Cells[0][i] = A->VarName[*ii];
  }

  for (ii = Vars->begin(); ii != Vars->end(); ii++) {
    Cells[*ii][*ii] = "1";
    for (jj = ii, jj++; jj != Vars->end(); jj++) {
      tmp = Correlation(A->GetVar(*ii), A->GetVar(*jj));
      Cells[*ii][*jj] = FloatToStrF(tmp, ffFixed, 2, 2);
      Cells[*jj][*ii] = Cells[*ii][*jj];
    }
  }

  VerticalFont = new TFont();
  DefaultFont = new TFont();
  DefaultFont->Assign(Font);

  CreateVerticalFont();
}
//---------------------------------------------------------------------------
__fastcall TCorrelationGrid::~TCorrelationGrid(void)
{
  DeleteObject(VerticalFont->Handle);

  delete DefaultFont;
  delete VerticalFont;
}
//---------------------------------------------------------------------------
void TCorrelationGrid::CreateVerticalFont(void)
{
  LOGFONT LogFont;

//  FillChar(LogFont, sizeof(Logont), 0);
  LogFont.lfHeight         = -11;
  LogFont.lfWidth          = 0;
  LogFont.lfEscapement     = 900;
  LogFont.lfOrientation    = 900;
  LogFont.lfWeight         = FW_NORMAL;
  LogFont.lfItalic         = 0;
  LogFont.lfUnderline      = 0;
  LogFont.lfStrikeOut      = 0;
  LogFont.lfCharSet        = 1;
  LogFont.lfOutPrecision   = OUT_DEFAULT_PRECIS;
  LogFont.lfClipPrecision  = CLIP_DEFAULT_PRECIS;
  LogFont.lfQuality        = DEFAULT_QUALITY;
  LogFont.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
  StrPCopy(LogFont.lfFaceName, Font->Name);

  VerticalFont->Handle = CreateFontIndirect(&LogFont);
}
//---------------------------------------------------------------------------
void __fastcall TCorrelationGrid::SetLimit(double new_limit)
{
  if (0 < new_limit && new_limit < 1)
    FLimit = new_limit;

  Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TCorrelationGrid::_OnDrawCell(TObject *Sender, int ACol, int ARow,
      TRect &Rect, TGridDrawState State)
{
  double tmp;
  AnsiString str = Cells[ACol][ARow];

  SetGraphicsMode(Canvas->Handle, GM_COMPATIBLE);

  if (ARow > 0 && ACol > 0) {
    Canvas->Font->Assign(DefaultFont);
    tmp = StrToFloat(str);
    if (fabs(tmp) >= Limit) {
      if (tmp > 0) Canvas->Brush->Color = clLime;
      else Canvas->Brush->Color = clRed;
      Canvas->Font->Color  = clBlack;
    }
    else
      if (fabs(tmp) >= Limit / 2) {
        Canvas->Brush->Color = clSilver;
        if (tmp > 0) Canvas->Font->Color  = clGreen;
        else  Canvas->Font->Color  = clRed;
      }
      else {
        Canvas->Brush->Color = clWhite;
        Canvas->Font->Color  = clWhite;
      }

    if (ARow == ACol) {
      Canvas->Brush->Color = clGray;
      Canvas->Font->Color  = clGray;
    }

    Canvas->Font->Size = 7;

    if (!IsColor) {
      Canvas->Brush->Color = clWhite;
      Canvas->Font->Color = clBlack;
    }

    if (!IsNumbers) str = " ";

    Canvas->TextRect(Rect,
                     Rect.Left + (Rect.Right - Rect.Left - Canvas->TextWidth(str)) / 2,
                     Rect.Top + (Rect.Bottom - Rect.Top - Canvas->TextHeight(str)) / 2,
                     str);
  }
  else {
    if (ARow == 0 && ACol != 0)
      Canvas->Font->Assign(VerticalFont);
    else
      Canvas->Font->Assign(DefaultFont);
    Canvas->Brush->Color = clBtnFace;
    Canvas->Font->Color  = clBlack;
//    Canvas->Font->Size = 8;

    if (ARow == 0 && ACol != 0)
      Canvas->TextRect(Rect,
                       Rect.Left + (Rect.Right - Rect.Left - Canvas->TextHeight(str)) / 2,
                       Rect.Bottom - 2,
                       str);
    else
      Canvas->TextRect(Rect,
                       Rect.Left + 2,
                       Rect.Top + (Rect.Bottom - Rect.Top - Canvas->TextHeight(str)) / 2,
                       str);
  }
}
//---------------------------------------------------------------------------
void __fastcall TCorrelationGrid::SetIsColor(bool isColor)
{
  FIsColor = isColor;

  Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TCorrelationGrid::SetIsNumbers(bool isNumbers)
{
  FIsNumbers = isNumbers;

  Refresh();
}
//---------------------------------------------------------------------------
#pragma package(smart_init)

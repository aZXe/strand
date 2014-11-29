//---------------------------------------------------------------------------
#include <vcl.h>
#include <values.h>
#include <math.h>
#pragma hdrstop

#include "Block.h"
#include "Connector.h"
#include "Utils.h"

typedef DynamicArray <AnsiString> TAnsiStringArray;
//---------------------------------------------------------------------------
TBlock::TBlock(TCanvas **_C, int _X, int _Y, TDArrayElement *_Elements,
               TElementProperty *_Property) : TElement(_C, _Property)
{
  FX1 = _X;
  FY1 = _Y;
  FX2 = _X + 100;
  FY2 = _Y + 50;
  Elements = _Elements;
  In.Length    = 0;
  Out.Length   = 0;
  InOut.Length = 0;

  TextFont = new TFont();
  TextFont->Name = "Times New Roman";
  ColorBackground = clWhite;
  ColorForeground = clBlack;
  LineWidth = 1;
}
//---------------------------------------------------------------------------
TBlock::TBlock(TCanvas **_C, TFileStream *stream, TDArrayElement *_Elements,
               TElementProperty *_Property) : TElement(_C, _Property)
{
  Elements = _Elements;
  In.Length    = 0;
  Out.Length   = 0;
  InOut.Length = 0;
  Load(stream);

/*  TextFont = new TFont();
  TextFont->Name = "Times New Roman";
  ColorBackground = clWhite;
  ColorForeground = clBlack;
  ColorText       = clBlack;*/
}
//---------------------------------------------------------------------------
TBlock::~TBlock(void)
{
  delete TextFont;
}
//---------------------------------------------------------------------------
void __fastcall TBlock::DeleteConnection(int ID)
{
  int j;
  
  for (j = 0; j < In.Length; j++)
    if (In[j].second->ID == ID) {
      In[j] = In[In.Length - 1];
      In.Length--;
      return;
    }

  for (j = 0; j < Out.Length; j++)
    if (Out[j].second->ID == ID) {
      Out[j] = Out[Out.Length - 1];
      Out.Length--;
      return;
    }

  for (j = 0; j < InOut.Length; j++)
    if (InOut[j].second->ID == ID) {
      InOut[j] = InOut[InOut.Length - 1];
      InOut.Length--;
      return;
    }
}
//---------------------------------------------------------------------------
bool TBlock::isMy(int X, int Y)
{
  if ((X1 - MIN_SPACE) <= X && X <= (X2 + MIN_SPACE) &&
      (Y1 - MIN_SPACE) <= Y && Y <= (Y2 + MIN_SPACE))
    return true;
  else
    return false;
}
//---------------------------------------------------------------------------
bool TBlock::MouseDown(int X, int Y)
{
  if (isMy(X, Y)) {
    Active = true;
    if (X >= (X1 - MIN_SPACE) && X <= (X1 + MIN_SPACE) &&
        Y >= (Y1 - MIN_SPACE) && Y <= (Y1 + MIN_SPACE))
      State = 1;
    else
    if (X >= (X2 - MIN_SPACE) && X <= (X2 + MIN_SPACE) &&
        Y >= (Y1 - MIN_SPACE) && Y <= (Y1 + MIN_SPACE))
      State = 2;
    else
      if (X >= (X2 - MIN_SPACE) && X <= (X2 + MIN_SPACE) &&
          Y >= (Y2 - MIN_SPACE) && Y <= (Y2 + MIN_SPACE))
        State = 3;
      else
        if (X >= (X1 - MIN_SPACE) && X <= (X1 + MIN_SPACE) &&
            Y >= (Y2 - MIN_SPACE) && Y <= (Y2 + MIN_SPACE))
          State = 4;
        else {
          State = 5;
          dx = X - X1;
          dy = Y - Y1;
        }
    return true;
  }
  else {
    Active = false;
    return false;
  }
}
//---------------------------------------------------------------------------
bool TBlock::MouseUp(int X, int Y)
{
  AdjustOrder();
  State = 0;
  return true;
}
//---------------------------------------------------------------------------
void TBlock::AdjustOrder(void)
{
  int r;

  if (FX1 > FX2) {
    r = FX2;
    FX2 = FX1;
    FX1 = r;
    switch (State) {
      case 1: State = 2; break;
      case 2: State = 1; break;
      case 3: State = 4; break;
      case 4: State = 3; break;
    }
  }

  if (FY1 > FY2) {
    r = FY2;
    FY2 = FY1;
    FY1 = r;
    switch (State) {
      case 1: State = 4; break;
      case 2: State = 3; break;
      case 3: State = 2; break;
      case 4: State = 1; break;
    }
  }
}
//---------------------------------------------------------------------------
bool TBlock::MouseMove(int X, int Y)
{
  switch (State) {
    case 1 :
      SetCoord(X, Y, X2, Y2);
      AdjustOrder();
      return true;
    case 2 :
      SetCoord(X1, Y, X, Y2);
      AdjustOrder();
      return true;
    case 3 :
      SetCoord(X1, Y1, X, Y);
      AdjustOrder();
      return true;
    case 4 :
      SetCoord(X, Y1, X2, Y);
      AdjustOrder();
      return true;
    case 5 :
      SetCoord(X - dx, Y - dy, X - dx + Width, Y - dy + Height);
      return true;
  }

  return false; // <==============================================!!!!!!!!!!!!!!!!!
}
//---------------------------------------------------------------------------
void TBlock::SetProperty(void)
{
  if (Property != NULL) {
    Property->e = this;
    Property->ShowModal();
  }
}
//---------------------------------------------------------------------------
void TBlock::Draw(void)
{
  TAnsiStringArray A, B;
  AnsiString tmp, tmp1;
  char *p;
  int i, xx, yy;

  (*C)->Brush->Color = ColorBackground;
  (*C)->Pen->Color   = ColorForeground;
  (*C)->Pen->Width   = LineWidth;
  (*C)->Rectangle(X1, Y1, X2, Y2);

  DrawText(X1, Y1, X2, Y2);

  if (Active)
    DrawCorners();
}
//---------------------------------------------------------------------------
void TBlock::DrawText(int x1, int y1, int x2, int y2)
{
  TAnsiStringArray A, B;
  AnsiString tmp, tmp1;
  char *p;
  int i, xx, yy;

  (*C)->Font->Assign(TextFont);

  A.Length = 0;
  B.Length = 0;
  tmp.Insert(Text, 0);
  if (tmp != "") {
    // –азбиение текста по словам
    p = strtok(tmp.c_str(), " ");
    while (p != NULL) {
      A.Length++;
      A[A.Length - 1] = AnsiString(p);
      p = strtok(NULL, " ");
    }

    // –азбиение текста по строкам
    i = 0;
    while (i < A.Length) {
      tmp1 = A[i];
      i++;
      while (i < A.Length && (*C)->TextWidth(tmp1 + " " + A[i]) < x2 - x1 - 5) {
        tmp1 += " " + A[i];
        i++;
      }
      B.Length++;
      B[B.Length - 1] = tmp1;
    }

    // ¬ывод текста
    xx = x1 + 3;
    yy = (y2 + y1) / 2. - B.Length * (*C)->TextHeight("H") / 2.;
    (*C)->Font->Color = TextFont->Color;
    (*C)->Brush->Style = bsClear;
    for (i = 0; i < B.Length; i++) {
      (*C)->TextOut(xx, yy, B[i]);
      yy += (*C)->TextHeight("H");
    }
  }
}
//---------------------------------------------------------------------------
void TBlock::DrawCorners(void)
{
  (*C)->Brush->Color = ColorForeground;
  (*C)->Pen->Color   = ColorForeground;
  (*C)->Rectangle((X1 - MIN_SPACE / 2), (Y1 - MIN_SPACE / 2),
                  (X1 + MIN_SPACE / 2), (Y1 + MIN_SPACE / 2));
  (*C)->Rectangle((X1 - MIN_SPACE / 2), (Y2 - MIN_SPACE / 2),
                  (X1 + MIN_SPACE / 2), (Y2 + MIN_SPACE / 2));
  (*C)->Rectangle((X2 - MIN_SPACE / 2), (Y1 - MIN_SPACE / 2),
                  (X2 + MIN_SPACE / 2), (Y1 + MIN_SPACE / 2));
  (*C)->Rectangle((X2 - MIN_SPACE / 2), (Y2 - MIN_SPACE / 2),
                  (X2 + MIN_SPACE / 2), (Y2 + MIN_SPACE / 2));
}
//---------------------------------------------------------------------------
bool TBlock::DblClick(int X, int Y)
{
  SetProperty();
  State = 0;

  return true;
}
//---------------------------------------------------------------------------
void TBlock::SetX1(int newX1)
{
  if (!Cross(newX1, Y1, X2, Y2))
    FX1 = newX1;
}
//---------------------------------------------------------------------------
void TBlock::SetX2(int newX2)
{
  if (!Cross(X1, Y1, newX2, Y2))
    FX2 = newX2;
}
//---------------------------------------------------------------------------
void TBlock::SetY1(int newY1)
{
  if (!Cross(X1, newY1, X2, Y2))
    FY1 = newY1;
}
//---------------------------------------------------------------------------
void TBlock::SetY2(int newY2)
{
  if (!Cross(X1, Y1, X2, newY2))
    FY2 = newY2;
}
//---------------------------------------------------------------------------
void TBlock::ForceSetCoord(int newX1, int newY1, int newX2, int newY2)
{
  FY2 = newY2;
  FY1 = newY1;
  FX2 = newX2;
  FX1 = newX1;
}
//---------------------------------------------------------------------------
void TBlock::SetCoord(int newX1, int newY1, int newX2, int newY2)
{
  if (!Cross(newX1, newY1, newX2, newY2)) {
    FY2 = newY2;
    FY1 = newY1;
    FX2 = newX2;
    FX1 = newX1;
  }
}
//---------------------------------------------------------------------------
bool TBlock::Cross(int X1, int Y1, int X2, int Y2)
{
  for (int i = 0; i < Elements->Length; i++) {
    if (
//        !((*Elements)[i] == this) &&
         ((*Elements)[i]->ID != ID) &&
         ((*Elements)[i]->GetType() > 0) &&
         ( //координаты движущегос€ блока
           (*Elements)[i]->isMy(X1, Y1) ||
           (*Elements)[i]->isMy(X1, Y2) ||
           (*Elements)[i]->isMy(X2, Y1) ||
           (*Elements)[i]->isMy(X2, Y2) ||
           //координаты неподвижного блока
           isMy((*Elements)[i]->X1, (*Elements)[i]->Y1) ||
           isMy((*Elements)[i]->X1, (*Elements)[i]->Y2) ||
           isMy((*Elements)[i]->X2, (*Elements)[i]->Y1) ||
           isMy((*Elements)[i]->X2, (*Elements)[i]->Y2)
         )
       )
      return true;
  }

  return false;
}
//---------------------------------------------------------------------------
bool TBlock::operator ==(TBlock &bl)
{
//  if (FX1 == bl.FX1 && FX2 == bl.FX2 && FY1 == bl.FY1 && FY2 == bl.FY2)
  if (ID == bl.ID)
    return true;
  else
    return false;
}
//---------------------------------------------------------------------------
void TBlock::GetCenter(int &X, int &Y)
{
  X = (X1 + X2) / 2;
  Y = (Y1 + Y2) / 2;
}
//---------------------------------------------------------------------------
void intersection(double x1,  double y1,  double x2,  double y2,
                  double x1_, double y1_, double x2_, double y2_,
                  double &u,  double &v)
{
  double d = (x2 - x1) * (y1_ - y2_) - (x1_ - x2_) * (y2 - y1);

  if (fabs(d) < 1e-4) {
    u = MAXDOUBLE;
    v = MAXDOUBLE;
    return;
  }

  u = ((x1_ - x1) * (y1_ - y2_) - (x1_ - x2_) * (y1_ - y1)) / d;
  v = ((x2 - x1) * (y1_ - y1) - (x1_ - x1) * (y2 - y1)) / d;
}
//---------------------------------------------------------------------------
double TBlock::Coord(double x1, double y1, double x2, double y2)
{
  double U[4], V[4];

  intersection(x1, y1, x2, y2, X1, Y1, X2, Y1, U[0], V[0]);
  intersection(x1, y1, x2, y2, X2, Y1, X2, Y2, U[1], V[1]);
  intersection(x1, y1, x2, y2, X1, Y2, X2, Y2, U[2], V[2]);
  intersection(x1, y1, x2, y2, X1, Y1, X1, Y2, U[3], V[3]);

  for (int i = 0; i < 4; i++)
    if (U[i] >= 0 && U[i] <= 1 && V[i] >= 0 && V[i] <= 1)
      return U[i];

  return -1;
}
//---------------------------------------------------------------------------
double TBlock::Coord_dp(double x1, double y1, double x2, double y2, char &draw_place)
{
  double U[4], V[4];
  char DP[4];

  intersection(x1, y1, x2, y2, X1, Y1, X2, Y1, U[0], V[0]);
  intersection(x1, y1, x2, y2, X2, Y1, X2, Y2, U[1], V[1]);
  intersection(x1, y1, x2, y2, X1, Y2, X2, Y2, U[2], V[2]);
  intersection(x1, y1, x2, y2, X1, Y1, X1, Y2, U[3], V[3]);

  if (X1 < x1 && x1 < X2 && Y1 < y1 && y1 < Y2) {
    DP[1] = DP[3] = (x2 < x1) << 1 | (y2 > y1);
    DP[0] = DP[2] = ~DP[1];
  }
  else {
    DP[1] = DP[3] = (x2 > x1) << 1 | (y2 < y1);
    DP[0] = DP[2] = ~DP[1];
  }

  for (int i = 0; i < 4; i++)
    if (U[i] >= 0 && U[i] <= 1 && V[i] >= 0 && V[i] <= 1) {
      draw_place = DP[i];
      return U[i];
    }

  return -1;
}
//---------------------------------------------------------------------------
void TBlock::Save(TFileStream *stream)
{
  int strl, type = GetType();

  stream->Write(&type, sizeof(type));
  stream->Write(&ID,  sizeof(ID));
  stream->Write(&FX1, sizeof(FX1));
  stream->Write(&FX2, sizeof(FX2));
  stream->Write(&FY1, sizeof(FY1));
  stream->Write(&FY2, sizeof(FY2));

  strl = Text.Length();
  stream->Write(&strl, sizeof(strl));
  stream->Write(Text.c_str(), strl + 1);

  stream->Write(&LineWidth, sizeof(LineWidth));

  stream->Write(&ColorBackground, sizeof(ColorBackground));
  stream->Write(&ColorForeground, sizeof(ColorForeground));

  SaveFont(stream, TextFont);
}
//---------------------------------------------------------------------------
void TBlock::Load(TFileStream *stream)
{
  stream->Read(&ID,  sizeof(ID));
  stream->Read(&FX1, sizeof(FX1));
  stream->Read(&FX2, sizeof(FX2));
  stream->Read(&FY1, sizeof(FY1));
  stream->Read(&FY2, sizeof(FY2));

  int strl;
  stream->Read(&strl,sizeof(strl));
  Text.SetLength(strl);
  stream->Read(Text.c_str(), strl + 1);

  stream->Read(&LineWidth, sizeof(LineWidth));

  stream->Read(&ColorBackground, sizeof(ColorBackground));
  stream->Read(&ColorForeground, sizeof(ColorForeground));

  TextFont = new TFont();
  LoadFont(stream, TextFont);
}
//---------------------------------------------------------------------------
#pragma package(smart_init)


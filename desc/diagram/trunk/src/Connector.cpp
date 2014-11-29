//---------------------------------------------------------------------------
#include <vcl.h>
#include <values.h>
#include <math.h>
#pragma hdrstop

#include "Constants.h"
#include "Connector.h"
//---------------------------------------------------------------------------
#include <algorithm>
#include "Utils.h"
using namespace std;
//---------------------------------------------------------------------------
TConnector::TConnector(TElement *_Begin, TElement *_End, TCanvas **_C,
                       TDArrayElement *_Elements, bool _BiDirectional, TElementProperty *_Property)
                      : TElement(_C, _Property)
{
  Begin = _Begin;
  End = _End;
  Elements = _Elements;
  BiDirectional = _BiDirectional;

  TextFontBegin = new TFont();
  TextFontBegin->Name = "Times New Roman";
  TextFontEnd = new TFont();
  TextFontEnd->Name   = "Times New Roman";
  ColorLine = clBlack;
  LineWidth = 1;
  BeginArrowType = EndArrowType = 2;

  FillRelationsLinkedElements();
}
//---------------------------------------------------------------------------
TConnector::TConnector(TCanvas **_C, TFileStream *stream,
                       TDArrayElement *_Elements, TElementProperty *_Property)
                      : TElement(_C, _Property)
{
  Elements = _Elements;
  Load(stream);
//  FillRelationsLinkedElements();
}
//---------------------------------------------------------------------------
TConnector::~TConnector(void)
{
  delete TextFontBegin;
  delete TextFontEnd;
}
//---------------------------------------------------------------------------
void TConnector::FillRelationsLinkedElements(void)
{
  if (BiDirectional) {
    Begin->InOut.Length++;
    Begin->InOut[Begin->InOut.Length - 1] = make_pair(End, this);
    End->InOut.Length++;
    End->InOut[End->InOut.Length - 1] = make_pair(Begin, this);
  }
  else {
    Begin->Out.Length++;
    Begin->Out[Begin->Out.Length - 1] = make_pair(End, this);
    End->In.Length++;
    End->In[End->In.Length - 1] = make_pair(Begin, this);
  }
}
//---------------------------------------------------------------------------
void TConnector::Draw(void)
{
  TPoint p[4];

  if (Begin == NULL || End == NULL) return;

  int x1, y1, x2, y2;
  Begin->GetCenter(x1, y1);
  End->GetCenter(x2, y2);

  double ubegin, uend;
  char dp_begin, dp_end;
  ubegin = Begin->Coord_dp(x1, y1, x2, y2, dp_begin);
  uend   = End->  Coord_dp(x1, y1, x2, y2, dp_end  );

  // a,b,c,d - координаты начала и конца линии
  double a = x1 + (x2 - x1) * ubegin;
  double b = y1 + (y2 - y1) * ubegin;
  double c = x1 + (x2 - x1) * uend;
  double d = y1 + (y2 - y1) * uend;

  //компоненты векторов для рисования стрелки
  double a1, a2, b1, b2;
  b1 = c - a;
  b2 = d - b;

  double A, B;
  B = sqrt(b1 * b1 + b2 * b2) * 2 * MIN_SPACE;
  A = cos(30 * M_PI / 180) * B;
  B = sin(30 * M_PI / 180) * B;

  //отрисовка линии
  (*C)->Brush->Color = ColorLine;
  (*C)->Pen->Color   = ColorLine;
  (*C)->Pen->Width   = LineWidth;
  (*C)->MoveTo(x1, y1);
  (*C)->LineTo(x2, y2);

  // стрелка у конца
  if (EndArrowType != atNone) {
    if (EndArrowType == atFilledArrow) (*C)->Brush->Color = ColorLine;
    else (*C)->Brush->Color = clWhite;
    p[0] = p[3] = TPoint(c, d);
    if (EndArrowType == atSimpleArrow) (*C)->MoveTo(c, d);
    a1 =  (A * b1 + B * b2) / (b1 * b1 + b2 * b2);
    a2 = -(B * b1 - A * b2) / (b1 * b1 + b2 * b2);
    if (EndArrowType == atSimpleArrow) (*C)->LineTo(c - a1, d - a2);
    p[1] = TPoint(c - a1, d - a2);

    B = -B;
    if (EndArrowType == atSimpleArrow) (*C)->MoveTo(c, d);
    a1 =  (A * b1 + B * b2) / (b1 * b1 + b2 * b2);
    a2 = -(B * b1 - A * b2) / (b1 * b1 + b2 * b2);
    p[2] = TPoint(c - a1, d - a2);
    if (EndArrowType == atSimpleArrow) (*C)->LineTo(c - a1, d - a2);
    else (*C)->Polygon(p, 3);
  }

  if (BiDirectional) {
    // стрелка у начала
    if (BeginArrowType != atNone) {
      if (BeginArrowType == atFilledArrow) (*C)->Brush->Color = ColorLine;
      else (*C)->Brush->Color = clWhite;
      b1 = -b1;
      b2 = -b2;
      p[0] = p[3] = TPoint(a, b);
      if (BeginArrowType == atSimpleArrow) (*C)->MoveTo(a, b);
      a1 =  (A * b1 + B * b2) / (b1 * b1 + b2 * b2);
      a2 = -(B * b1 - A * b2) / (b1 * b1 + b2 * b2);
      if (BeginArrowType == atSimpleArrow) (*C)->LineTo(a - a1, b - a2);
      p[1] = TPoint(a - a1, b - a2);

      B = -B;
      if (BeginArrowType == atSimpleArrow) (*C)->MoveTo(a, b);
      a1 =  (A * b1 + B * b2) / (b1 * b1 + b2 * b2);
      a2 = -(B * b1 - A * b2) / (b1 * b1 + b2 * b2);
      p[2] = TPoint(a - a1, b - a2);
      if (BeginArrowType == atSimpleArrow) (*C)->LineTo(a - a1, b - a2);
      else (*C)->Polygon(p, 3);
    }
  }

  double xx, yy;
  (*C)->Brush->Style = bsClear;
  (*C)->Font->Assign(TextFontEnd);
  xx = c;
  if (dp_end & 0x02)
    xx -= (*C)->TextWidth(Text_end) + 3;
  else
    xx += 3;
  yy = d;
  if (dp_end & 0x01)
    yy -= (*C)->TextHeight(Text_end);
  else
    yy += 3;
  (*C)->TextOut(xx, yy, Text_end);

  (*C)->Font->Assign(TextFontBegin);
  xx = a;
  if (dp_begin & 0x02)
    xx -= (*C)->TextWidth(Text_begin) + 3;
  else
    xx += 3;
  yy = b;
  if (dp_begin & 0x01)
    yy -= (*C)->TextHeight(Text_begin);
  else
    yy += 3;
  (*C)->TextOut(xx, yy, Text_begin);

  if (Active)
    DrawCorners();
}
//---------------------------------------------------------------------------
bool TConnector::MouseDown(int X, int Y)
{
  if (isMy(X, Y)) {
    Active = true;
    return true;
  }
  else {
    Active = false;
    return false;
  }
}
//---------------------------------------------------------------------------
bool TConnector::MouseUp(int X, int Y)
{
  return false;
}
//---------------------------------------------------------------------------
bool TConnector::MouseMove(int X, int Y)
{
  return false;
}
//---------------------------------------------------------------------------
void TConnector::DrawCorners(void)
{
  int x1, y1, x2, y2;
  Begin->GetCenter(x1, y1);
  End->GetCenter(x2, y2);

  double ubegin, uend;
  ubegin = Begin->Coord(x1, y1, x2, y2);
  uend   = End->  Coord(x1, y1, x2, y2);

  // a,b,c,d - координаты начала и конца линии
  double a = x1 + (x2 - x1) * ubegin;
  double b = y1 + (y2 - y1) * ubegin;
  double c = x1 + (x2 - x1) * uend;
  double d = y1 + (y2 - y1) * uend;

  (*C)->Brush->Color = ColorLine;
  (*C)->Pen->Color   = ColorLine;
  (*C)->Rectangle(a - 3, b - 3,
                  a + 3 ,b + 3);
  (*C)->Rectangle(c - 3, d - 3,
                  c + 3, d + 3);
}
//---------------------------------------------------------------------------
bool TConnector::isMy(int X,int Y)
{
  int x1, y1, x2, y2;
  Begin->GetCenter(x1, y1);
  End->GetCenter(x2, y2);

  double ubegin, uend;
  ubegin = Begin->Coord(x1, y1, x2, y2);
  uend   = End->  Coord(x1, y1, x2, y2);

  //координаты начала и конца линии
  double xbegin = x1 + (x2 - x1) * ubegin;
  double ybegin = y1 + (y2 - y1) * ubegin;
  double xend   = x1 + (x2 - x1) * uend;
  double yend   = y1 + (y2 - y1) * uend;
  double d1 = sqrt((xend - xbegin) * (xend - xbegin) + (yend - ybegin) * (yend - ybegin)),
         d2 = sqrt((X - xbegin) * (X - xbegin) + (Y - ybegin) * (Y - ybegin)),
         d3 = sqrt((X - xend  ) * (X - xend  ) + (Y - yend  ) * (Y - yend  ));

  //Косинусы углов
  double cos_a1 = (d1 * d1 + d2 * d2 - d3 * d3) / (2 * d1 * d2),
         cos_a2 = (d1 * d1 + d3 * d3 - d2 * d2) / (2 * d1 * d3);
  //  расстояние от точки до прямой
  double d = fabs(X * (y2 - y1) + Y * (x1 - x2) - x1 * y2 + x2 * y1) /
             sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

  if (cos_a1 >= 0 && cos_a2 >= 0 && fabs(d) <= MIN_SPACE)
    return true;
  else
    return false;
}
//---------------------------------------------------------------------------
void TConnector::SetProperty(void)
{
  if (Property != NULL) {
    Property->e = this;
    Property->ShowModal();
  }
}
//---------------------------------------------------------------------------
bool TConnector::DblClick(int X, int Y)
{
  SetProperty();
  return true;
}
//---------------------------------------------------------------------------
void __fastcall TConnector::DeleteConnection(int ID)
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
void TConnector::GetCenter(int &X, int &Y)
{
  int x1, y1, x2, y2;

  Begin->GetCenter(x1, y1);
  End->GetCenter(x2, y2);

  X = (x1 + x2) / 2;
  Y = (y1 + y2) / 2;
}
//---------------------------------------------------------------------------
int TConnector::GetX1(void)
{
  Begin->GetCenter(FX1, FY1);
  End->GetCenter(FX2, FY2);
  if (FX2 < FX1) swap (FX1, FX2);
//  if (FY2 < FY1) swap (FY1, FY2);

  return FX1;
}
//---------------------------------------------------------------------------
int TConnector::GetX2(void)
{
  Begin->GetCenter(FX1, FY1);
  End->GetCenter(FX2, FY2);
  if (FX2 < FX1) swap (FX1, FX2);
//  if (FY2 < FY1) swap (FY1, FY2);

  return FX2;
}
//---------------------------------------------------------------------------
int TConnector::GetY1(void)
{
  Begin->GetCenter(FX1, FY1);
  End->GetCenter(FX2, FY2);
//  if (FX2 < FX1) swap (FX1, FX2);
  if (FY2 < FY1) swap (FY1, FY2);

  return FY1;
}
//---------------------------------------------------------------------------
int TConnector::GetY2(void)
{
  Begin->GetCenter(FX1, FY1);
  End->GetCenter(FX2, FY2);
//  if (FX2 < FX1) swap (FX1, FX2);
  if (FY2 < FY1) swap (FY1, FY2);

  return FY2;
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
double TConnector::Coord(double x1, double y1, double x2, double y2)
{
  if (fabs(x1 - (X1 + X2) / 2) < 1e-9 && fabs(y1 - (Y1 + Y2) / 2) < 1e-9)
    return 0;
  else
    return 1;
}
//---------------------------------------------------------------------------
double TConnector::Coord_dp(double x1, double y1, double x2, double y2, char &draw_place)
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
    if (U[i] >= 0 && U[i] <= 1 && V[i] >= 0 && V[i] <= 1)
      draw_place = DP[i];

  if (fabs(x1 - (X1 + X2) / 2) < 1e-9 && fabs(y1 - (Y1 + Y2) / 2) < 1e-9)
    return 0;
  else
    return 1;
}
//---------------------------------------------------------------------------
void TConnector::Save(TFileStream * stream)
{
  int type = GetType();

  stream->Write(&type, sizeof(type));
  stream->Write(&ID,  sizeof(ID));
  stream->Write(&Begin->ID, sizeof(Begin->ID));
  stream->Write(&End->ID,   sizeof(End->ID  ));
  stream->Write(&BiDirectional, sizeof(BiDirectional));

  int strl = Text_begin.Length();
  stream->Write(&strl, sizeof(strl));
  stream->Write(Text_begin.c_str(), strl + 1);

  strl = Text_end.Length();
  stream->Write(&strl, sizeof(strl));
  stream->Write(Text_end.c_str(), strl + 1);

  SaveFont(stream, TextFontBegin);
  SaveFont(stream, TextFontEnd  );

  stream->Write(&ColorLine, sizeof(ColorLine));
  stream->Write(&LineWidth, sizeof(LineWidth));

  stream->Write(&BeginArrowType, sizeof(BeginArrowType));
  stream->Write(&EndArrowType,   sizeof(EndArrowType  ));
}
//---------------------------------------------------------------------------
void TConnector::Load(TFileStream* stream)
{
  int begin_id, end_id;
  int i;

  stream->Read(&ID, sizeof(ID));
  stream->Read(&begin_id, sizeof(begin_id));
  stream->Read(&end_id,   sizeof(end_id  ));
  stream->Read(&BiDirectional, sizeof(BiDirectional));

  int strl;
  stream->Read(&strl, sizeof(strl));
  Text_begin.SetLength(strl);
  stream->Read(Text_begin.c_str(), strl + 1);

  stream->Read(&strl, sizeof(strl));
  Text_end.SetLength(strl);
  stream->Read(Text_end.c_str(), strl + 1);

  TextFontBegin = new TFont();
  TextFontEnd   = new TFont();
  LoadFont(stream, TextFontBegin);
  LoadFont(stream, TextFontEnd  );

  stream->Read(&ColorLine, sizeof(ColorLine));
  stream->Read(&LineWidth, sizeof(LineWidth));

  stream->Read(&BeginArrowType, sizeof(BeginArrowType));
  stream->Read(&EndArrowType,   sizeof(EndArrowType  ));

  Begin = (TElement *)begin_id;
  End   = (TElement *)end_id;
/*
  for (i = 0; i < Elements->Length; i++) {
    if ((*Elements)[i]->ID == begin_id)
      Begin = (*Elements)[i];
    if ((*Elements)[i]->ID == end_id)
      End = (*Elements)[i];
  }
*/
}
//---------------------------------------------------------------------------
#pragma package(smart_init)


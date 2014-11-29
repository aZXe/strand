//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <string.h>
#include <values.h>
//#include <math.hpp>
#pragma hdrstop

#include "Graphing.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TGraph *Graph;

//---------------------------------------------------------------------------
__fastcall TGraph::TGraph(TComponent* Owner, TDoubleArray &X, TDoubleArray &Y,
                         long color, char Type, const char *_Caption,
                         const char *_XText, const char *_YText)
        : TForm(Owner)
{
  char *p;
  int i;

  Count = 2;
  XY.Length = 2;
  XY[0] = X.Copy();
  XY[1] = Y.Copy();
  Colors.Length = 1;
  Colors[0] = color;
  Types.Length = 1;
  Types[0] = Type;
  strncpy(XText, _XText, 10);
  strncpy(YText, _YText, 10);

  minx = miny = MAXDOUBLE;
  maxx = maxy = MINDOUBLE;
  for (i = 0; i < XY[0].Length; i++) {
    if (maxx < XY[0][i]) maxx = XY[0][i];
    if (minx > XY[0][i]) minx = XY[0][i];
  }
  for (i = 0; i < XY[1].Length; i++) {
    if (maxy < XY[1][i]) maxy = XY[1][i];
    if (miny > XY[1][i]) miny = XY[1][i];
  }

  if (p = (char *)strstr(_Caption, "|")) {
    strncpy(Captions[0], _Caption, min(p - _Caption, 40));
    strncpy(Captions[1], p + 1, 40);
  }
  else {
    strncpy(Captions[0], _Caption, 40);
    Captions[1][0] = 0;
  }
}
//---------------------------------------------------------------------------
void __fastcall TGraph::btnSaveClick(TObject *Sender)
{
  if (SaveDialog->Execute() == TRUE)
    Image->Picture->Bitmap->SaveToFile(SaveDialog->FileName);
}
//---------------------------------------------------------------------------
void __fastcall TGraph::FormCreate(TObject *Sender)
{
  Image->Width  = Screen->Width;
  Image->Height = Screen->Height;
  Image->Canvas->Font->Name = "Arial";
  Draw();
}
//---------------------------------------------------------------------------
void __fastcall TGraph::FormResize(TObject *Sender)
{
  Panel->Height = ClientHeight;
  Panel->Width  = ClientWidth;
  Image->Picture->Bitmap->Height = Panel->Height;
  Image->Picture->Bitmap->Width  = Panel->Width;
  btnSave->Left = ClientWidth - btnSave->Width;
  Draw();
}
//---------------------------------------------------------------------------
/*
void __fastcall TGraph::TimerTimer(TObject *Sender)
{
  static x, y;

  if (x != Panel->Width || y != Panel->Height) {
    x = Panel->Width;
    y = Panel->Height;
//    Draw();
  }
}
*/
//---------------------------------------------------------------------------
void __fastcall TGraph::Draw(void)
{
  double sx, sy, dx, dy;
  double borderx = 0.10, bordery = 0.14, border = 0.06;
  int i, j;
  char buf1[41], buf2[41];

  sx = Panel->Width;
  sy = Panel->Height;
  bordery *= sy;
  borderx *= sx;
  border  *= (sx > sy) ? sy : sx;

  Image->Canvas->Brush->Color = clWhite;
  Image->Canvas->Pen->Color = clWhite;
  Image->Canvas->Rectangle(0, 0, Image->Width, Image->Height);
  Image->Canvas->Pen->Color = clGray;
  Image->Canvas->Pen->Style = psDot;
  Image->Canvas->Rectangle((int)(borderx),      (int)(bordery),
                           (int)(sx - borderx), (int)(sy - border) + 1);
  Image->Canvas->Pen->Style = psSolid;
  Image->Canvas->MoveTo((int)(sx - border), (int)(sy - border));
  Image->Canvas->LineTo((int)(borderx), (int)(sy - border));
  Image->Canvas->LineTo((int)(borderx), (int)(0.7 * bordery));

  strcpy(buf1, Captions[0]);
  dx = borderx / (4. * Image->Canvas->TextHeight(buf1));
  dy = dx * bordery / borderx;
//  Image->Canvas->Font->Height = Floor(Image->Canvas->Font->Height * min(dx, dy));
  Image->Canvas->Font->Height *= min(dx, dy);
  Image->Canvas->TextOut((int)(borderx + sx - border -
                                Image->Canvas->TextWidth(buf1)) / 2, 0, buf1);
  strcpy(buf2, Captions[1]);
  Image->Canvas->TextOut((int)(borderx + sx - border -
                                Image->Canvas->TextWidth(buf2)) / 2,
                          Image->Canvas->TextHeight(buf1), buf2);
  strcpy(buf1, YText);
  Image->Canvas->TextOut((int)(borderx) - Image->Canvas->TextWidth(buf1) - 3,
                         (int)(0.7 * bordery) - Image->Canvas->TextHeight(buf1), buf1);
  strcpy(buf1, XText);
  Image->Canvas->TextOut((int)(sx - border - Image->Canvas->TextWidth(buf1) / 1.8),
                         (int)(sy - border) - Image->Canvas->TextHeight(buf1) - 1, buf1);

  Image->Canvas->Pen->Color = clGray;
  Image->Canvas->Pen->Style = psDot;
  dx = (sx - 2 * borderx) / 5;
  for (i = 1; i < 5; i++) {
    Image->Canvas->MoveTo((int)(borderx + i * dx), (int)(sy - border));
    Image->Canvas->LineTo((int)(borderx + i * dx), (int)(bordery));
  }
  Image->Canvas->Pen->Style = psSolid;
  for (i = 0; i < 5; i++)
    for (j = 0; j <= 10; j++) {
      Image->Canvas->MoveTo((int)(borderx + i * dx + j * dx / 10), (int)(sy - 0.9 * border));
      Image->Canvas->LineTo((int)(borderx + i * dx + j * dx / 10), (int)(sy - 1.1 * border));
    }
  for (i = 0; i <= 5; i++) {
    gcvt(minx + i * (maxx - minx) / 5, 4, buf1);
    Image->Canvas->TextOut((int)(borderx + i * dx - Image->Canvas->TextWidth(buf1) / 2),
                           (int)(sy - 0.8 * border), buf1);
  }

  Image->Canvas->Pen->Style = psDot;
  dy = (sy - bordery - border) / 5;
  for (i = 1; i < 5; i++) {
    Image->Canvas->MoveTo((int)(borderx), (int)(sy - border - i * dy));
    Image->Canvas->LineTo((int)(sx - borderx), (int)(sy - border - i * dy));
  }
  Image->Canvas->Pen->Style = psSolid;
  for (i = 0; i < 5; i++)
    for (j = 0; j <= 10; j++) {
      Image->Canvas->MoveTo((int)(borderx - 0.1 * border), (int)(sy - border - i * dy - j * dy / 10));
      Image->Canvas->LineTo((int)(borderx + 0.1 * border), (int)(sy - border - i * dy - j * dy / 10));
    }
  for (i = 0; i <= 5; i++) {
    gcvt(miny + i * (maxy - miny) / 5, 4, buf1);
    Image->Canvas->TextOut((int)(borderx) - Image->Canvas->TextWidth(buf1) - 3,
            (int)(sy - border - i * dy - Image->Canvas->TextHeight(buf1) / 2.), buf1);
  }

  Image->Canvas->Pen->Style = psSolid;
  dx = (sx - 2 * borderx) / (maxx - minx);
  dy = (sy - bordery - border) / (maxy - miny);

  for (i = 0; i < Count; i += 2) {
    switch (Types[i / 2]) {
      case SCATTERPLOT :
        Image->Canvas->Pen->Color = (TColor)Colors[i / 2];
        for (j = 1; j < XY[i].Length; j++) {
          int xx = (int)((XY[i][j] - minx) * dx + borderx),
              yy = (int)(sy - border - (XY[i + 1][j] - miny) * dy);
          Image->Canvas->Ellipse(xx - 2, yy - 2, xx + 2, yy + 2);
        }
        break;
      case LINEPLOT :
        Image->Canvas->Pen->Color = (TColor)Colors[i / 2];
        Image->Canvas->MoveTo((int)((XY[i][0] - minx) * dx + borderx),
                              (int)(sy - border - (XY[i + 1][0] - miny) * dy));
        for (j = 1; j < XY[i].Length; j++)
          Image->Canvas->LineTo((int)((XY[i][j] - minx) * dx + borderx),
                                (int)(sy - border - (XY[i + 1][j] - miny) * dy));
        break;
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TGraph::AddGraph(TDoubleArray &X, TDoubleArray &Y,
                                 long color, char Type)
{
  int i;

  Colors.Length = Count / 2 + 1;
  Colors[Count / 2] = color;
  Types.Length = Count / 2 + 1;
  Types[Count / 2] = Type;
  XY.Length = Count + 2;
  XY[Count    ] = X.Copy();
  XY[Count + 1] = Y.Copy();
  for (i = 0; i < XY[Count].Length; i++) {
    if (maxx < XY[Count][i]) maxx = XY[Count][i];
    if (minx > XY[Count][i]) minx = XY[Count][i];
  }
  for (i = 0; i < XY[Count + 1].Length; i++) {
    if (maxy < XY[Count + 1][i]) maxy = XY[Count + 1][i];
    if (miny > XY[Count + 1][i]) miny = XY[Count + 1][i];
  }
  Count += 2;

  Draw();
}
//---------------------------------------------------------------------------
DynamicArray < TGraph * > G;
int num = -1;
//---------------------------------------------------------------------------
void __fastcall InitGraph(void)
{
  num = 0;
  G.Length = 1;
  G[0] = NULL;
}
//---------------------------------------------------------------------------
int  __fastcall NewGraph(TDoubleArray &X, TDoubleArray &Y,
                    long color, char Type, const char *_Caption,
                    const char *_XText, const char *_YText)
{
  static int xx, yy;
  int i, ind = -1;

  if (num == -1) return -1;

  for (i = 0; i < G.Length; i++)
    if (G[i] == NULL) {
      ind = i;
      break;
    }
  if (ind == -1) {
    ind = G.Length;
    G.Length = G.Length + 1;
  }
  num++;
  G[ind] = new TGraph(dynamic_cast <TComponent *>(Application->MainForm),
                      X, Y, color, Type, _Caption, _XText, _YText);
  G[ind]->Caption = (AnsiString)"Graph " + CurrToStr(num);
  if ((xx += 20) > (Screen->Width  / 2)) xx = 0;
  if ((yy += 20) > (Screen->Height / 2)) yy = 0;
  G[ind]->Left = xx;
  G[ind]->Top  = yy;
  G[ind]->Show();

  return ind;
}
//---------------------------------------------------------------------------
void __fastcall AddGraph(int ind, TDoubleArray &X, TDoubleArray &Y,
                         long color, char Type)
{
  if (ind >= G.Length) return;
  if (num != -1 && G[ind]) G[ind]->AddGraph(X, Y, color, Type);
}
//---------------------------------------------------------------------------
void __fastcall DeleteGraph(int ind)
{
  if (ind >= G.Length) return;
  if (num != -1 && G[ind]) delete G[ind];
}
//---------------------------------------------------------------------------
void __fastcall DeleteGraphs(void)
{
  if (num == 1) return;

  for (int i = 0; i < G.Length; i++)
    if (G[i]) delete G[i];
}
//---------------------------------------------------------------------------
void __fastcall SaveGraph(int ind, AnsiString name)
{
  if (ind >= G.Length) return;
  if (num != -1 && G[ind]) G[ind]->SaveGraph(name);
}


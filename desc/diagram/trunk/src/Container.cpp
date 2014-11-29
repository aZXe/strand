//---------------------------------------------------------------------------
#include <vcl.h>
#include <math.hpp>
#include <math.h>
#include <values.h>
#pragma hdrstop

#include <stdio.h>
#include "Constants.h"
#include "Container.h"
#include "BlockForm.h"
//---------------------------------------------------------------------------
//#define MIN_SPACE 5

int XX, YY;
bool isDblClickNow;
bool isCanvasSizeLock;
//---------------------------------------------------------------------------
__fastcall TContainer::TContainer(TComponent* Owner): TImage(Owner)
{
  buffer = new TMetafile;
  OnMouseDown = _OnMouseDown;
  OnMouseUp   = _OnMouseUp;
  OnMouseMove = _OnMouseMove;
  OnDblClick  = _OnDblClick;
//  ControlStyle << csOpaque;

  Elements.Length = 0;

  ActiveElement = NULL;
  ActiveElement = NULL;
  isAddConnector = false;
  isCanvasSizeLock = false;

  IDs.clear();
  Properties.clear();

  is_Repaint = true;
}
//---------------------------------------------------------------------------
__fastcall TContainer::~TContainer()
{
  Clear();

//  for (i = 0; i < Connectors.Length; i++)
//    DeleteElement(Connectors[i--]->ID);

  delete buffer;

  for (map <int, TElementProperty *>::iterator i = Properties.begin();
       i != Properties.end(); i++)
    delete i->second;

  Properties.clear();
}
//---------------------------------------------------------------------------
void TContainer::Clear(void)
{
  int i = 0;

  while (i < Elements.Length)
    if (Elements[i]->GetType() > 0) {
      DeleteElement(Elements[i]->ID);
      i = 0;
    }
    else
      i++;

//  Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TContainer::_OnMouseDown(TObject *Sender,
    TMouseButton Button, TShiftState Shift, int X, int Y)
{
  int i, k;

  XX = X;
  YY = Y;
  if (isDblClickNow) {
    isDblClickNow = false;
    return;
  }

  isCanvasSizeLock = true;

  if (isAddConnector) {
    if (!ActiveElement->MouseDown(PhisToLog(X), PhisToLog(Y)))
      for (i = 0; i < Elements.Length; i++) {
        if (Elements[i]->MouseDown(PhisToLog(X), PhisToLog(Y))) {
//          Elements[i]->HaveCon++;
          k = Elements.Length;
          Elements.Length = k + 1;
          Elements[k] = new TConnector(ActiveElement, Elements[i],
                                       (TCanvas **)&buffer_Canvas, &Elements,
                                       isBiConnector, Properties[TCONNECTOR]);
          Elements[k]->ID = GenerateID();
          AddID(Elements[k]->ID);
          dynamic_cast<TConnector *>(Elements[k])->Text_begin = "";
          dynamic_cast<TConnector *>(Elements[k])->Text_end   = "";
          Elements[i]->Active = false;
          Repaint();
          break;
        }
      }//for
    ActiveElement->Active = false;
    ActiveElement = NULL;
    isAddConnector = false;
    return;
  }

  if (ActiveElement != NULL) {
    if (ActiveElement->MouseDown(PhisToLog(X), PhisToLog(Y)))
      return;
    else {
      ActiveElement->Active = false;
      ActiveElement = NULL;
    }
  }

  for (i = 0; i < Elements.Length; i++) {
    if (Elements[i]->MouseDown(PhisToLog(X), PhisToLog(Y))) {
//      Elements[i]->DX = PhisToLog(X);
//      Elements[i]->DY = PhisToLog(Y);
      ActiveElement = Elements[i];
      ActiveElement->Active = true;
      break;
    }
  }

  Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TContainer::_OnMouseMove(TObject *Sender, TShiftState Shift,
                                         int X, int Y)
{
  if (ActiveElement) {
    if (ActiveElement->MouseMove(PhisToLog(X), PhisToLog(Y)))
      Repaint();
  }
}
//-----------------------------------------------------------------------------
void __fastcall TContainer::_OnMouseUp(TObject *Sender, TMouseButton Button,
                                       TShiftState Shift, int X, int Y)
{
  isCanvasSizeLock = false;

  if (ActiveElement)
    ActiveElement->MouseUp(PhisToLog(X), PhisToLog(Y));

//  minX = GetXmin();
//  minY = GetYmin();
  AlignDiagram();

  Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TContainer::Repaint1(void)
{
//  Repaint1();
//  Repaint1();
}
//---------------------------------------------------------------------------
void __fastcall TContainer::Repaint(void)
{
  int i;
  TRect d;
  TScrollBox *parent = dynamic_cast<TScrollBox *>(Parent);
  int w, h;

  if (!is_Repaint) return;

  Canvas->Lock();

for (int j = 0; j < 2; j++) {
  w = max(GetWidth()  + 2 * MIN_SPACE, parent->ClientWidth);
  h = max(GetHeight() + 2 * MIN_SPACE, parent->ClientHeight);
  if (isCanvasSizeLock) {
    if (Width  < w)
      Width  = w + 200;
    if (Height < h)
      Height = h + 200;
  }
  else {
    Width  = w;
    Height = h;
  }

  Picture->Bitmap->Height = Height;
  Picture->Bitmap->Width  = Width;
  buffer->Height = PhisToLog(Height);
  buffer->Width  = PhisToLog(Width);

  buffer_Canvas = new TMetafileCanvas(buffer, 0);
  buffer_Canvas->Pen->Color   = clWhite;
  buffer_Canvas->Brush->Color = clWhite;
  buffer_Canvas->Rectangle(0, 0, buffer->Width, buffer->Height);
//  buffer_Canvas->Pen->Color   = clBlack;
//  buffer_Canvas->Font->Name = "Times New Roman";

  for (i = 0; i < Elements.Length; i++)
    if (Elements[i]->GetType() < 0)
      Elements[i]->Draw();

  for (i = 0; i < Elements.Length; i++)
    if (Elements[i]->GetType() > 0)
      Elements[i]->Draw();

  TRect R;
  R.Left = 0;
  R.Top  = 0;
  R.Bottom = Height;
  R.Right  = Width;

//  if (fabs(Koef - 1) < 1e-9) Canvas->Draw(0, 0, buffer);
  if (j == 1) Canvas->StretchDraw(R, buffer);

  delete buffer_Canvas;
}

  Canvas->Unlock();
}
//---------------------------------------------------------------------------
int TContainer::GetWidth(void)
{
  int i, max = 0;

  for (i = 0; i < Elements.Length; i++) {
    if (Elements[i]->GetType() > 0 && Elements[i]->X2 > max)
      max = Elements[i]->X2;
  }

  return LogToPhis(max + 10);
}
//---------------------------------------------------------------------------
int TContainer::GetHeight(void)
{
  int i, max = 0;

  for (i = 0; i < Elements.Length; i++) {
    if (Elements[i]->GetType() > 0 && Elements[i]->Y2 > max)
      max = Elements[i]->Y2;
  }

  return LogToPhis(max + 10);
}
//---------------------------------------------------------------------------
int TContainer::GetXmin(void)
{
  int i, min = MAXINT;

  for (i = 0; i < Elements.Length; i++) {
    if (Elements[i]->GetType() > 0 && Elements[i]->X1 < min)
      min = Elements[i]->X1;
  }

  return min;
}
//---------------------------------------------------------------------------
int TContainer::GetYmin(void)
{
  int i, min = MAXINT;

  for (i = 0; i < Elements.Length; i++) {
    if (Elements[i]->GetType() > 0 && Elements[i]->Y1 < min)
      min = Elements[i]->Y1;
  }

  return min;
}
//---------------------------------------------------------------------------
void TContainer::AlignDiagram(void)
{
  int i, Xmin, Ymin;

  Xmin = GetXmin();
  Ymin = GetYmin();

  if (Xmin == 10 && Ymin == 10)
    return;

  for (i = 0; i < Elements.Length; i++) {
    if (Elements[i]->GetType() > 0)
      dynamic_cast<TBlock *>(Elements[i])->
                   ForceSetCoord(Elements[i]->X1 - Xmin + 10, Elements[i]->Y1 - Ymin + 10,
                                 Elements[i]->X2 - Xmin + 10, Elements[i]->Y2 - Ymin + 10);
  }
}
//---------------------------------------------------------------------------
TBlock * __fastcall TContainer::AddBlock(void)
{
  int k, i, maxX2 = 0;

  k = Elements.Length;
  Elements.Length = k + 1;
  for (i = 0; i < k; i++) {
    if (Elements[i]->GetType() > 0 && Elements[i]->X2 > maxX2)
      maxX2 = Elements[i]->X2;
  }

  Elements[k] = new TBlock((TCanvas **)&buffer_Canvas, 15 + maxX2, 20, &Elements, Properties[TBLOCK]);
  Elements[k]->ID = GenerateID();
  AddID(Elements[k]->ID);
  Elements[k]->Active = true;
  dynamic_cast<TBlock *>(Elements[k])->State = 0;

  if (ActiveElement != NULL)
    ActiveElement->Active = false;
  ActiveElement = Elements[k];

  AlignDiagram();
  Repaint();

  return (TBlock *)Elements[k];
}
//---------------------------------------------------------------------------
TBlockIndicator * __fastcall TContainer::AddBlockIndicator(void)
{
  int k, maxX2 = 0;

  k = Elements.Length;
  Elements.Length = k + 1;
  for (int i = 0; i < k; i++)
    if (Elements[i]->GetType() > 0 && Elements[i]->X2 > maxX2)
      maxX2 = Elements[i]->X2;

  Elements[k] = new TBlockIndicator((TCanvas **)&buffer_Canvas, 15 + maxX2, 20, &Elements, true, Properties[TBLOCKINDICATOR]);
  dynamic_cast<TBlockIndicator *>(Elements[k])->IndicatorPosition = 0.5;
  Elements[k]->ID = GenerateID();
  AddID(Elements[k]->ID);
  Elements[k]->Active = true;
  dynamic_cast<TBlock *>(Elements[k])->State = 0;

  if (ActiveElement != NULL)
    ActiveElement->Active = false;
  ActiveElement = Elements[k];

  AlignDiagram();
  Repaint();

  return (TBlockIndicator *)Elements[k];
}
//---------------------------------------------------------------------------
TRomb * __fastcall TContainer::AddRomb(void)
{
  int k, maxX2 = 0;

  k = Elements.Length;
  Elements.Length = k + 1;
  for (int i = 0; i < Elements.Length - 1; i++)
    if (Elements[i]->GetType() > 0 && Elements[i]->X2 > maxX2)
      maxX2 = Elements[i]->X2;

  Elements[k] = new TRomb((TCanvas **)&buffer_Canvas, 15 + maxX2, 80, &Elements, Properties[TROMB]);
  Elements[k]->ID = GenerateID();
  AddID(Elements[k]->ID);
  Elements[k]->Active = true;
  dynamic_cast<TBlock *>(Elements[k])->State = 0;

  if (ActiveElement != NULL)
    ActiveElement->Active = false;
  ActiveElement = Elements[k];

  AlignDiagram();
  Repaint();

  return (TRomb *)Elements[k];
}
//---------------------------------------------------------------------------
TRombIndicator * __fastcall TContainer::AddRombIndicator(void)
{
  int k, maxX2 = 0;

  k = Elements.Length;
  Elements.Length = k + 1;
  for (int i = 0; i < Elements.Length - 1; i++)
    if (Elements[i]->GetType() > 0 && Elements[i]->X2 > maxX2)
      maxX2 = Elements[i]->X2;

  Elements[k] = new TRombIndicator((TCanvas **)&buffer_Canvas, 15 + maxX2, 80, &Elements, true, Properties[TROMBINDICATOR]);
  dynamic_cast<TRombIndicator *>(Elements[k])->IndicatorPosition = 0.5;
  Elements[k]->ID = GenerateID();
  AddID(Elements[k]->ID);
  Elements[k]->Active = true;
  dynamic_cast<TBlock *>(Elements[k])->State = 0;

  if (ActiveElement != NULL)
    ActiveElement->Active = false;
  ActiveElement = Elements[k];

  AlignDiagram();
  Repaint();

  return (TRombIndicator *)Elements[k];
}
//---------------------------------------------------------------------------
void __fastcall TContainer::AddConnector(bool isBiDirectional)
{
  if (ActiveElement != NULL) {
    for (int i = 0; i < Elements.Length; i++) {
      if (Elements[i]->Active) {
        isAddConnector = true;
        isBiConnector  = isBiDirectional;
        break;
      }
      else
        isAddConnector = false;
    }
    Repaint();
  }
}
//---------------------------------------------------------------------------
TConnector * __fastcall TContainer::AddConnector(int BeginID, int EndID,
                                                 bool isBiDirectional)
{
  int i, k;
  TElement *BeginElement = NULL, *EndElement = NULL;
  
  for (i = 0; i < Elements.Length; i++) {
    if (Elements[i]->ID == BeginID)
      BeginElement = Elements[i];
    if (Elements[i]->ID == EndID)
      EndElement = Elements[i];
  }
  
  if (BeginElement == NULL || EndElement == NULL) return NULL;

  k = Elements.Length;
  Elements.Length = k + 1;
  Elements[k] = new TConnector(BeginElement, EndElement,
                               (TCanvas **)&buffer_Canvas, &Elements,
                               isBiDirectional, Properties[TCONNECTOR]);
  Elements[k]->ID = GenerateID();
  AddID(Elements[k]->ID);
  dynamic_cast<TConnector *>(Elements[k])->Text_begin = "";
  dynamic_cast<TConnector *>(Elements[k])->Text_end   = "";
  Elements[k]->Active = false;

  return (TConnector *)Elements[k];
}
//---------------------------------------------------------------------------
void __fastcall TContainer::DeleteActiveElement(void)
{
  int i, j;

  if (ActiveElement != NULL) {
    DeleteElement(ActiveElement->ID);
    ActiveElement = NULL;
  }

  AlignDiagram();
  Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TContainer::DeleteElement(int ID)
{
  int i, j;
  TConnector *tmp;

  for (i = 0; i < Elements.Length; i++)
    if (Elements[i]->ID == ID) {
      for (j = 0; j < Elements[i]->In.Length; j++) {
        tmp = dynamic_cast<TConnector *>(Elements[i]->In[j].second);
        if (tmp->Begin->ID == ID)
          tmp->End->DeleteConnection(tmp->ID);
        else
          tmp->Begin->DeleteConnection(tmp->ID);
        tmp->Begin = tmp->End = NULL;
        DeleteElement(tmp->ID);
      }

      for (j = 0; j < Elements[i]->Out.Length; j++) {
        tmp = dynamic_cast<TConnector *>(Elements[i]->Out[j].second);
        if (tmp->Begin->ID == ID)
          tmp->End->DeleteConnection(tmp->ID);
        else
          tmp->Begin->DeleteConnection(tmp->ID);
        tmp->Begin = tmp->End = NULL;
        DeleteElement(tmp->ID);
      }

      for (j = 0; j < Elements[i]->InOut.Length; j++) {
        tmp = dynamic_cast<TConnector *>(Elements[i]->InOut[j].second);
        if (tmp->Begin->ID == ID)
          tmp->End->DeleteConnection(tmp->ID);
        else
          tmp->Begin->DeleteConnection(tmp->ID);
        tmp->Begin = tmp->End = NULL;
        DeleteElement(tmp->ID);
      }

      if (Elements[i]->GetType() < 0) {
        tmp = dynamic_cast<TConnector *>(Elements[i]);
        if (tmp->Begin != NULL)
          tmp->Begin->DeleteConnection(tmp->ID);
        if (tmp->End != NULL)
          tmp->End->DeleteConnection(tmp->ID);
      }

      IDs.erase(Elements[i]->ID);
      delete Elements[i];
      Elements[i] = Elements[Elements.Length - 1];
      Elements.Length--;
      break;
    }

  ActiveElement = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TContainer::_OnDblClick(TObject *Sender)
{
  isDblClickNow = true;

  if (ActiveElement != NULL)
    if (!ActiveElement->DblClick(PhisToLog(XX), PhisToLog(YY))) {
      ActiveElement->Active = false;
      ActiveElement = NULL;
    }

  Repaint();
}
//---------------------------------------------------------------------------
void TContainer::SetKoef(double K)
{
  Koef = K;
}
//---------------------------------------------------------------------------
int TContainer::LogToPhis(int X1)
{
//  return Ceil((X1 - minX) * Koef);
  return Ceil(X1 * Koef);
}
//---------------------------------------------------------------------------
int TContainer::PhisToLog(int X)
{
//  return Ceil(X / Koef) + minX;
  return Ceil(X / Koef);
}
//---------------------------------------------------------------------------
int TContainer::GenerateID()
{
  int i = 1;

  while (IDs.count(i))
    i++;

  return i;
}
//---------------------------------------------------------------------------
void TContainer::AddID(int ID)
{
  if (IDs.count(ID))
    throw Exception("Добавление элемента с повторяющимся индексом!");
  else
    IDs.insert(ID);
}
//---------------------------------------------------------------------------
void TContainer::ViewActiveElementPropertyForm(void)
{
  if (ActiveElement)
    ActiveElement->SetProperty();

  Repaint();
}
//---------------------------------------------------------------------------
void TContainer::SaveAsWMF(AnsiString filename)
{
  int i;

  buffer->Height = PhisToLog(GetHeight() + 2 * MIN_SPACE);
  buffer->Width  = PhisToLog(GetWidth()  + 2 * MIN_SPACE);

  buffer_Canvas = new TMetafileCanvas(buffer, 0);
  buffer_Canvas->Pen->Color   = clWhite;
  buffer_Canvas->Brush->Color = clWhite;
  buffer_Canvas->Rectangle(0, 0, buffer->Width, buffer->Height);
  buffer_Canvas->Pen->Color   = clBlack;
  buffer_Canvas->Font->Name = "Times New Roman";

  for (i = 0; i < Elements.Length; i++)
    if (Elements[i]->GetType() < 0)
      Elements[i]->Draw();

  for (i = 0; i < Elements.Length; i++)
    if (Elements[i]->GetType() > 0)
      Elements[i]->Draw();

  buffer->Enhanced = false;
  buffer->SaveToFile(filename);
}
//---------------------------------------------------------------------------
void TContainer::SaveAsEMF(AnsiString filename)
{
  int i;

  buffer->Height = PhisToLog(GetHeight() + 2 * MIN_SPACE);
  buffer->Width  = PhisToLog(GetWidth()  + 2 * MIN_SPACE);

  buffer_Canvas = new TMetafileCanvas(buffer, 0);
  buffer_Canvas->Pen->Color   = clWhite;
  buffer_Canvas->Brush->Color = clWhite;
  buffer_Canvas->Rectangle(0, 0, buffer->Width, buffer->Height);
  buffer_Canvas->Pen->Color   = clBlack;
  buffer_Canvas->Font->Name = "Times New Roman";

  for (i = 0; i < Elements.Length; i++)
    if (Elements[i]->GetType() < 0)
      Elements[i]->Draw();

  for (i = 0; i < Elements.Length; i++)
    if (Elements[i]->GetType() > 0)
      Elements[i]->Draw();

  buffer->Enhanced = true;
  buffer->SaveToFile(filename);
}
//---------------------------------------------------------------------------
void TContainer::SaveToFile(AnsiString filename)
{
  TFileStream *stream;
  int len, i;

  stream = new TFileStream(filename, fmCreate);

  if (stream != NULL) {
    len = Elements.Length;
    stream->Write(&len, sizeof(len));

    for (i = 0; i < len; i++)
      if (Elements[i]->GetType() > 0)
        Elements[i]->Save(stream);

    for (i = 0; i < len; i++)
      if (Elements[i]->GetType() < 0)
        Elements[i]->Save(stream);
  }

  delete stream;
}
//---------------------------------------------------------------------------
void TContainer::LoadFromFile(AnsiString filename)
{
  TFileStream *stream;
  int len, i, j, type;

  stream = new TFileStream(filename, fmOpenRead);

  if (stream != NULL) {
    stream->Read(&len, sizeof(len));

    Clear();
    
    Elements.Length = len;
    for (i = 0; i < Elements.Length; i++)
      Elements[i] = NULL;

    for (i = 0; i < len; i++) {
      stream->Read(&type, sizeof(type));

      switch (type) {
        case TBLOCK :
          Elements[i] = new TBlock((TCanvas **)&buffer_Canvas, stream, &Elements, Properties[TBLOCK]);
          break;
        case TROMB :
          Elements[i] = new TRomb((TCanvas **)&buffer_Canvas, stream, &Elements, Properties[TROMB]);
          break;
        case TBLOCKINDICATOR :
          Elements[i] = new TBlockIndicator((TCanvas **)&buffer_Canvas, stream, &Elements, Properties[TBLOCKINDICATOR]);
          break;
        case TROMBINDICATOR :
          Elements[i] = new TRombIndicator((TCanvas **)&buffer_Canvas, stream, &Elements, Properties[TROMBINDICATOR]);
          break;
        case TCONNECTOR :
          Elements[i] = new TConnector((TCanvas **)&buffer_Canvas, stream, &Elements, Properties[TCONNECTOR]);
          break;
        default :
          Elements.Length = 0;
          Application->MessageBox("Неизвестный тип элемента!", "Ошибка", MB_OK);
          return;
      }

      AddID(Elements[i]->ID);
    }

    delete stream;
  }

  //Резрешение ссылок для коннекторов
  TConnector *tmp;
  for (i = 0; i < Elements.Length; i++)
    if (Elements[i]->GetType() < 0) {
      tmp = dynamic_cast<TConnector *>(Elements[i]);
      for (j = 0; j < Elements.Length; j++) {
        if (Elements[j]->ID == (int)tmp->Begin)
          tmp->Begin = Elements[j];
        if (Elements[j]->ID == (int)tmp->End)
          tmp->End = Elements[j];
      }
      tmp->FillRelationsLinkedElements();
    }

  AlignDiagram();

  Repaint();
}
//---------------------------------------------------------------------------
#pragma package(smart_init)


//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "FPContainer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
#define DEFAULT_BLOCK_HEIGHT    30
#define DEFAULT_BLOCK_WIDTH     70
//---------------------------------------------------------------------------
extern bool CompareVars(AnsiString varname1, AnsiString varname2);
//---------------------------------------------------------------------------
__fastcall TFPContainer::TFPContainer(TComponent* Owner): TContainer(Owner)
{
  Properties[TBLOCK]          = NULL;
  Properties[TROMB ]          = NULL;
  Properties[TBLOCKINDICATOR] = NULL;
  Properties[TROMBINDICATOR ] = NULL;
  Properties[TCONNECTOR]      = NULL;

  AllocationType = 1;
}
//---------------------------------------------------------------------------
__fastcall TFPContainer::~TFPContainer(void)
{
}
//---------------------------------------------------------------------------
void __fastcall TFPContainer::_OnMouseMove(TObject *Sender, TShiftState Shift,
                                           int X, int Y)
{
}
//-----------------------------------------------------------------------------
void __fastcall TFPContainer::_OnDblClick(TObject *Sender)
{
}
//---------------------------------------------------------------------------
void TFPContainer::ArrangeElements(void)
{
  int i, j, y1, y2;
  int count = 0, height;
  int width = dynamic_cast<TScrollBox *>(Parent)->Width;
  TElement *tmp;

  //Сортируем блоки
  for (i = 0; i < Elements.Length; i++) {
    if (Elements[i]->GetType() != TBLOCK) continue;
    for (j = i + 1; j < Elements.Length; j++) {
      if (Elements[j]->GetType() != TBLOCK) continue;
      if (CompareVars(dynamic_cast<TBlock *>(Elements[i])->Text,
                      dynamic_cast<TBlock *>(Elements[j])->Text)) {
        tmp = Elements[i];
        Elements[i] = Elements[j];
        Elements[j] = tmp;
      }
    }
  }

  for (i = 0; i < Elements.Length; i++)
    if (Elements[i]->GetType() == TBLOCK) count++;

  if (AllocationType == 1) { // В один ряд
    height = DEFAULT_BLOCK_HEIGHT * count + (DEFAULT_BLOCK_HEIGHT / 2) * (count - 1);
    if (height < 0 ) height = 0;

    FPRomb->ForceSetCoord(width - 120, height / 2 - DEFAULT_BLOCK_HEIGHT,
                          width - 35,  height / 2 + DEFAULT_BLOCK_HEIGHT);

    for (i = y1 = 0; i < Elements.Length; i++)
      if (Elements[i]->GetType() == TBLOCK) {
        dynamic_cast<TBlock *>(Elements[i])->
          ForceSetCoord(0,                   y1,
                        DEFAULT_BLOCK_WIDTH, y1 + DEFAULT_BLOCK_HEIGHT);
        y1 += DEFAULT_BLOCK_HEIGHT + DEFAULT_BLOCK_HEIGHT / 2;
      }
  }
  else
    if (AllocationType == 2) { // В два ряда
      count = count / 2 + count % 2;
      height = DEFAULT_BLOCK_HEIGHT * count + (DEFAULT_BLOCK_HEIGHT / 2) * (count - 1);
      if (height < 0 ) height = 0;

      if (width < DEFAULT_BLOCK_WIDTH * 2 + 85 + 2 * 40)
        width = DEFAULT_BLOCK_WIDTH * 2 + 85 + 2 * 40;

      FPRomb->ForceSetCoord(width / 2 - 10 - 42, height / 2 - DEFAULT_BLOCK_HEIGHT,
                            width / 2 - 10 + 42,  height / 2 + DEFAULT_BLOCK_HEIGHT);

      for (i = j = y1 = y2 = 0; i < Elements.Length; i++)
        if (Elements[i]->GetType() == TBLOCK) {
          if (j < count) {
            dynamic_cast<TBlock *>(Elements[i])->
              ForceSetCoord(0,                   y1,
                            DEFAULT_BLOCK_WIDTH, y1 + DEFAULT_BLOCK_HEIGHT);
            y1 += DEFAULT_BLOCK_HEIGHT + DEFAULT_BLOCK_HEIGHT / 2;
          }
          else {
            dynamic_cast<TBlock *>(Elements[i])->
              ForceSetCoord(width - DEFAULT_BLOCK_WIDTH - 20, y2,
                            width - 20,                       y2 + DEFAULT_BLOCK_HEIGHT);
            y2 += DEFAULT_BLOCK_HEIGHT + DEFAULT_BLOCK_HEIGHT / 2;
          }
          j++;
        }
    }
    else { // По кругу
      double alpha, d_alpha = (count > 0) ? 2 * M_PI / count : 1,
             l = sqrt(DEFAULT_BLOCK_WIDTH  * DEFAULT_BLOCK_WIDTH +
                      DEFAULT_BLOCK_HEIGHT * DEFAULT_BLOCK_HEIGHT),
             R = (l + 10) / (2 * sin(d_alpha / 2));

      if (R < l + 35) R = l + 35;
      if (count < 2) R = width - DEFAULT_BLOCK_WIDTH - 40;

      FPRomb->ForceSetCoord(-42, -DEFAULT_BLOCK_HEIGHT,
                             42,  DEFAULT_BLOCK_HEIGHT);

      alpha = 0;
      for (i = 0; i < Elements.Length; i++)
        if (Elements[i]->GetType() == TBLOCK) {
          dynamic_cast<TBlock *>(Elements[i])->
            ForceSetCoord(-R * cos(alpha) - DEFAULT_BLOCK_WIDTH  / 2,
                          -R * sin(alpha) - DEFAULT_BLOCK_HEIGHT / 2,
                          -R * cos(alpha) + DEFAULT_BLOCK_WIDTH  / 2,
                          -R * sin(alpha) + DEFAULT_BLOCK_HEIGHT / 2);
          alpha += d_alpha;
        }
    }

  if (ActiveElement != NULL) {
    ActiveElement->Active = false;
    ActiveElement = NULL;
  }

  AlignDiagram();
}
//---------------------------------------------------------------------------
void TFPContainer::SetAllocationType(short NewAllocationType)
{
  AllocationType = NewAllocationType;
  ArrangeElements();
  Repaint();
}
//---------------------------------------------------------------------------
void TFPContainer::ClearInformation(void)
{
  int i;
  TConnector *c;

  for (i = 0; i < Elements.Length; i++)
    if (Elements[i]->GetType() == TCONNECTOR) {
      c = dynamic_cast<TConnector *>(Elements[i]);
      c->Text_begin = "";
      c->Text_end = "";
      c->ColorLine = clBlack;
      c->LineWidth = 1;
    }
}
//---------------------------------------------------------------------------
bool TFPContainer::ContainVar(AnsiString name)
{
  int i;

  for (i = 0; i < Elements.Length; i++)
    if (Elements[i]->GetType() == TBLOCK)
      if (dynamic_cast<TBlock *>(Elements[i])->Text == name)
        return true;

  return false;
}
//---------------------------------------------------------------------------
const TElement *TFPContainer::GetActiveElement()
{
  return const_cast<const TElement *>(ActiveElement);
}
//---------------------------------------------------------------------------
const TDArrayElement *TFPContainer::GetElements()
{
  return const_cast<const TDArrayElement *>(&Elements);
}
//---------------------------------------------------------------------------
void TFPContainer::DeleteAllVars(void)
{
  int i;

  while (Elements.Length > 1)
    for (i = 0; i < Elements.Length; i++)
      if (Elements[i]->GetType() == TBLOCK)
        DeleteElement(Elements[i]->ID);
}
//---------------------------------------------------------------------------


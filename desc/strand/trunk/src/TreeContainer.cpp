//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TreeContainer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
#define DEFAULT_BLOCK_HEIGHT    30
#define DEFAULT_BLOCK_WIDTH     70
#define DEFAULT_BLOCK_SKIP      20
//---------------------------------------------------------------------------
extern bool CompareVars(AnsiString varname1, AnsiString varname2);
extern AnsiString GetVarName(int var);
extern double GetVarValue(int var);
//---------------------------------------------------------------------------
TIntSet used_elems;
//---------------------------------------------------------------------------
__fastcall TTreeContainer::TTreeContainer(TComponent* Owner): TContainer(Owner)
{
  Properties[TBLOCK]          = NULL;
  Properties[TROMB ]          = NULL;
  Properties[TBLOCKINDICATOR] = NULL;
  Properties[TROMBINDICATOR ] = NULL;
  Properties[TCONNECTOR]      = NULL;

  AllocationType = 1;
  color_elements = false;
}
//---------------------------------------------------------------------------
__fastcall TTreeContainer::~TTreeContainer(void)
{
  for (int i = 0; i < Elements.Length; i++)
    delete Elements[i];

  Elements.Length = 0;
}
//---------------------------------------------------------------------------
void __fastcall TTreeContainer::_OnMouseMove(TObject *Sender, TShiftState Shift,
                                           int X, int Y)
{
}
//-----------------------------------------------------------------------------
void __fastcall TTreeContainer::_OnDblClick(TObject *Sender)
{
}
//---------------------------------------------------------------------------
void TTreeContainer::CreateBranch(TBlockIndicator *b, int ib)
{
  TBlockIndicator *tmp;
  TConnector *c, *cc;
  TIntSetIterator i;
  TintIntSetMapIterator ielems;
  int pi, pj;
  double v;

  if (elems[ib].size()) {
    for (pj = 0, ielems = elems[ib].begin(); ielems != elems[ib].end(); pj++, ielems++) {
      tmp = AddBlockIndicator();
      tmp->Text = GetVarName(ielems->first);
      tmp->IndicatorPosition = GetVarValue(ielems->first);
      c = AddConnector(tmp->ID, b->ID);
      if (color_elements) {
        v = values[ib][pj][0];
        c->ColorLine = (v > 0) ? clGreen : clRed;
        c->Text_begin = "";
        c->Text_end = (v > 0) ? "+" : "-";
        v = fabs(v);
        if (v >= 0.4) c->LineWidth = 3;
        else
          if (v >= 0.2) c->LineWidth = 2;
          else c->LineWidth = 1;
        if (v < 0.05) {
          c->ColorLine = TColor(0xe0e0e0);
          c->Text_end = "";
        }
      }
      if (!used_elems.count(ielems->first)) {
        used_elems.insert(ielems->first);
        CreateBranch(tmp, ielems->first - 1);
      }

      if (ielems->second.size()) {
        for (pi = 1, i = ielems->second.begin(); i != ielems->second.end(); pi++, i++) {
          tmp = AddBlockIndicator();
          tmp->Text = GetVarName(*i);
          tmp->IndicatorPosition = GetVarValue(*i);
          cc = AddConnector(tmp->ID, c->ID);
          if (color_elements) {
            v = values[ib][pj][pi];
            cc->ColorLine = (v > 0) ? clGreen : clRed;
            cc->Text_begin = "";
            cc->Text_end = (v > 0) ? "+" : "-";
            v = fabs(v);
            if (v >= 0.4) cc->LineWidth = 3;
            else
              if (v >= 0.2) cc->LineWidth = 2;
              else cc->LineWidth = 1;
            if (v < 0.05) {
              cc->ColorLine = TColor(0xe0e0e0);
              cc->Text_end = "";
            }
          }
          if (!used_elems.count(*i)) {
            used_elems.insert(*i);
            CreateBranch(tmp, (*i) - 1);
          }
        }
      }
    }
  }
}
//---------------------------------------------------------------------------
int TTreeContainer::GetBoundingSize(TBlockIndicator *b)
{
  int i, j;
  int size = -DEFAULT_BLOCK_SKIP;
  int N = b->In.Length, M;
  TConnector *c;

  if (N == 0)
    return b->Height;

  for (i = 0; i < N; i++) {
    size += GetBoundingSize(dynamic_cast<TBlockIndicator *>(b->In[i].first)) + DEFAULT_BLOCK_SKIP;
    c = dynamic_cast<TConnector *>(b->In[i].second);
    M = c->In.Length;
    for (j = 0; j < M; j++)
      size += GetBoundingSize(dynamic_cast<TBlockIndicator *>(c->In[j].first)) + DEFAULT_BLOCK_SKIP;
  }

  return size;
}
//---------------------------------------------------------------------------
void TTreeContainer::SetPosition(TBlockIndicator *b, int x, int y)
{
  int h = GetBoundingSize(b);
  int i, j, dy;
  int N = b->In.Length, M;
  TBlockIndicator *tmp;
  TConnector *c;

  b->ForceSetCoord(x, y + h / 2 - b->Height / 2, x + b->Width, y + h / 2 + b->Height / 2);

  dy = 0;
  for (i = 0; i < N; i++) {
    tmp = dynamic_cast<TBlockIndicator *>(b->In[i].first);
    SetPosition(tmp, x + b->Width + 5 * DEFAULT_BLOCK_SKIP, y + dy);
    dy += GetBoundingSize(tmp) + DEFAULT_BLOCK_SKIP;

    c = dynamic_cast<TConnector *>(b->In[i].second);
    M = c->In.Length;
    for (j = 0; j < M; j++) {
      tmp = dynamic_cast<TBlockIndicator *>(c->In[j].first);
      SetPosition(tmp, x + b->Width + 5 * DEFAULT_BLOCK_SKIP, y + dy);
      dy += GetBoundingSize(tmp) + DEFAULT_BLOCK_SKIP;
    }
  }
}
//---------------------------------------------------------------------------
void TTreeContainer::ArrangeElements(void)
{
  TBlockIndicator *b, *main_block;
  int i, j;

  if (main_elem == 0) return;

  is_Repaint = false;

  for (i = 0; i < Elements.Length; i++)
    delete Elements[i];

  Elements.Length = 0;

  used_elems.clear();
  i = main_elem - 1;
  b = AddBlockIndicator();
  b->Text = GetVarName(i + 1);
  b->IndicatorPosition = GetVarValue(i + 1);
  main_block = b;
  used_elems.insert(i + 1);
  CreateBranch(b, i);
  SetPosition(main_block, 0, 0);

  is_Repaint = true;
}
//---------------------------------------------------------------------------
void TTreeContainer::SetAllocationType(short NewAllocationType)
{
  AllocationType = NewAllocationType;
  ArrangeElements();
  Repaint();
}
//---------------------------------------------------------------------------
void TTreeContainer::ClearInformation(void)
{
  color_elements = false;
/*
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
*/
}
//---------------------------------------------------------------------------
bool TTreeContainer::ContainVar(AnsiString name)
{
  int i;

  for (i = 0; i < Elements.Length; i++)
    if (Elements[i]->GetType() == TBLOCKINDICATOR)
      if (dynamic_cast<TBlockIndicator *>(Elements[i])->Text == name)
        return true;

  return false;
}
//---------------------------------------------------------------------------
const TElement *TTreeContainer::GetActiveElement()
{
  return const_cast<const TElement *>(ActiveElement);
}
//---------------------------------------------------------------------------
const TDArrayElement *TTreeContainer::GetElements()
{
  return const_cast<const TDArrayElement *>(&Elements);
}
//---------------------------------------------------------------------------
void TTreeContainer::DeleteAllVars(void)
{
  int i;

  while (Elements.Length > 1)
    for (i = 0; i < Elements.Length; i++)
      if (Elements[i]->GetType() == TBLOCKINDICATOR)
        DeleteElement(Elements[i]->ID);
}
//---------------------------------------------------------------------------
void TTreeContainer::SetIndicatorVisible(bool Visible)
{
  int i;

  for (i = 0; i < Elements.Length; i++)
    if (Elements[i]->GetType() == TBLOCKINDICATOR)
      dynamic_cast<TBlockIndicator *>(Elements[i])->IndicatorVisible = Visible;

  Repaint();
}
//---------------------------------------------------------------------------


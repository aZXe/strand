//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TreeConstructor.h"
#include "ChildGridWin.h"
#include "Optimization.h"
#include "MatrixFunctions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
extern TTreeConstructorForm  *MainTreeConstructorForm;
extern TChildGrid            *MainChildGrid;
//---------------------------------------------------------------------------
AnsiString TreeFunction;
//---------------------------------------------------------------------------
AnsiString GetVarName(int var)
{
  if (MainTreeConstructorForm)
    return MainTreeConstructorForm->A->VarName[var];
  else return "";
}
//---------------------------------------------------------------------------
double GetVarValue(int var)
{
  double tmp;

  if (MainTreeConstructorForm) {
    tmp = MainTreeConstructorForm->A->Cell[var][MainChildGrid->CurrentRow()];
    return tmp;
  }
  else return 0;
}
//---------------------------------------------------------------------------
AnsiString TTreeConstructorForm::ConstructFunction(int main_var, int &param_count)
{
  bool isMultiply = rbMultRegression->Checked;
  int p;
  AnsiString tmp;
  TintIntSetMapIterator i;
  TIntSetIterator j;

  if (isMultiply) {
    tmp = "a0";
    p = 1;
    if (Container->elems[main_var].size())
      for (i = Container->elems[main_var].begin(); i != Container->elems[main_var].end(); i++) {
        tmp += " * (" + AnsiString(A->VarName[i->first]) + " ^ (a" + IntToStr(p++);
        if (i->second.size())
          for (j = i->second.begin(); j != i->second.end(); j++) {
            tmp += " + a" + IntToStr(p++) + "*" + A->VarName[*j];
          }
        tmp += "))";
      }
  }
  else {
    tmp = "a0";
    p = 1;
    if (Container->elems[main_var].size())
      for (i = Container->elems[main_var].begin(); i != Container->elems[main_var].end(); i++)
        tmp += " + (" + AnsiString(A->VarName[i->first]) + " * a" + IntToStr(p++) + ")";
  }

  param_count = p;

  if (tmp == "a0") return "";
  else return tmp;
}
//---------------------------------------------------------------------------
void TTreeConstructorForm::FillResultValues(int main_var, double *res)
{
  bool isMultiply = rbMultRegression->Checked;
  int p, pi, pj;
  TintIntSetMapIterator i;
  TIntSetIterator j;

  p = 1;
  if (Container->elems[main_var].size()) {
    Container->values[main_var].Length = Container->elems[main_var].size();
    for (pi = 0, i = Container->elems[main_var].begin(); i != Container->elems[main_var].end(); pi++, i++) {
      Container->values[main_var][pi].Length = i->second.size() + 1;
      Container->values[main_var][pi][0] = res[p++];
      if (i->second.size())
        for (pj = 0, j = i->second.begin(); j != i->second.end(); pj++, j++)
          Container->values[main_var][pi][pj + 1] = isMultiply ? res[p++] : 0;
    }
  }
}
//---------------------------------------------------------------------------
__fastcall TTreeConstructorForm::TTreeConstructorForm(TComponent* Owner, TIntSet _Vars)
        : TForm(Owner)
{
  TIntSetIterator ii;
  TIntSet tmp; //

  Vars = _Vars;

  if (MainChildGrid == NULL) return;

  A = MainChildGrid->A;

  MainVar = -1;

  cbMainVar->Items->Clear();
  for (ii = Vars.begin(); ii != Vars.end(); ii++)
    cbMainVar->Items->Add(A->VarName[*ii]);

  Container = new TTreeContainer(this);

  Container->SetKoef(1);
  Container->Parent = sbDiagram;
  Container->Left = 0;
  Container->Top = 0;
  Container->Width  = 100;
  Container->Height = 100;
  Container->Picture->Bitmap->Height = Container->Height;
  Container->Picture->Bitmap->Width  = Container->Width;

  ChangeVarsList();

  Container->elems.Length = lbVars->Items->Count;
  for (int i = 0; i < Container->elems.Length; i++)
    Container->elems[i].clear();

  Container->main_elem = 0;

  Container->ArrangeElements();
  Container->Repaint();
}
//---------------------------------------------------------------------------
__fastcall TTreeConstructorForm::~TTreeConstructorForm(void)
{
}
//---------------------------------------------------------------------------
void __fastcall TTreeConstructorForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;
  if (MainTreeConstructorForm == this)
    MainTreeConstructorForm = NULL;

  delete Container;
}
//---------------------------------------------------------------------------
void TTreeConstructorForm::ChangeVarsList(void)
{
  TIntSetIterator ii;

  lbVars->Items->Clear();
  for (ii = Vars.begin(); ii != Vars.end(); ii++)
      lbVars->Items->Add(A->VarName[*ii]);
}
//---------------------------------------------------------------------------
void __fastcall TTreeConstructorForm::cbMainVarChange(TObject *Sender)
{
  static int itemindex = -1;

  if (cbMainVar->Text == "") return;

  if (Container->ContainVar(cbMainVar->Text)) {
    cbMainVar->ItemIndex = itemindex;
    return;
  }
  itemindex = cbMainVar->ItemIndex;

  if (MainVar != -1) Vars.insert(MainVar);

  MainVar = A->VarByName(cbMainVar->Text);
  Vars.erase(MainVar);

  Container->main_elem = MainVar;

  Container->ArrangeElements();
  Container->SetIndicatorVisible(chbIndicatorVisible->Checked);
  Container->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TTreeConstructorForm::cbMainVarKeyPress(TObject *Sender,
      char &Key)
{
  Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TTreeConstructorForm::cbMainVarKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TTreeConstructorForm::bCloseClick(TObject *Sender)
{
  Close();        
}
//---------------------------------------------------------------------------
void __fastcall TTreeConstructorForm::FormResize(TObject *Sender)
{
  Container->ArrangeElements();
  Container->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TTreeConstructorForm::bOneToDiagramClick(TObject *Sender)
{
  int i = lbVars->ItemIndex;
  const TElement *e;
  int pe, pe1, pe2;
  TIntSet tmp;

  if (i == -1) return;
  if (Container->GetActiveElement() == NULL) return;

  tmp.clear();
  pe = A->VarByName(lbVars->Items->Strings[i]);

  e = Container->GetActiveElement();

  if (e->GetType() > 0) {
    pe1 = A->VarByName(dynamic_cast<const TBlockIndicator *>(e)->Text);
    Container->elems[pe1 - 1][pe] = tmp;
  }
  else {
    pe1 = A->VarByName( dynamic_cast<const TBlockIndicator *>(
                          dynamic_cast<const TConnector *>(e)->Begin
                        )->Text
                      );
    pe2 = A->VarByName( dynamic_cast<const TBlockIndicator *>(
                          dynamic_cast<const TConnector *>(e)->End
                        )->Text
                      );
    Container->elems[pe2 - 1][pe1].insert(pe);
  }

  Container->ClearInformation();
  Container->ArrangeElements();
  Container->SetIndicatorVisible(chbIndicatorVisible->Checked);
  Container->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TTreeConstructorForm::bOneFromDiagramClick(TObject *Sender)
{
  const TElement *e;
  int pe, pe1, pe2;

  if (Container->GetActiveElement() == NULL) return;
  if (Container->GetActiveElement()->GetType() != TBLOCKINDICATOR) return;

  e = Container->GetActiveElement();
  pe = A->VarByName(dynamic_cast<const TBlockIndicator *>(e)->Text);
  if (e->Out.Length)
    if (e->Out[0].first->GetType() > 0)
      Container->elems[pe - 1].erase(A->VarByName(dynamic_cast<TBlockIndicator *>(e->Out[0].first)->Text));
    else {
      pe1 = A->VarByName( dynamic_cast<TBlockIndicator *>(
                            dynamic_cast<const TConnector *>(
                              e->Out[0].first
                            )->Begin
                          )->Text
                        );
      pe2 = A->VarByName( dynamic_cast<TBlockIndicator *>(
                            dynamic_cast<const TConnector *>(
                              e->Out[0].first
                            )->End
                          )->Text
                        );
      Container->elems[pe - 1][pe2].erase(pe1);
    }

  Container->DeleteActiveElement();

  Container->ClearInformation();
  Container->ArrangeElements();
  Container->SetIndicatorVisible(chbIndicatorVisible->Checked);
  Container->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TTreeConstructorForm::Panel1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  if (Button == mbLeft) {
    Panel1->BevelInner = bvLowered;
    Panel1->BevelOuter = bvLowered;
  }
}
//---------------------------------------------------------------------------
void __fastcall TTreeConstructorForm::Panel1MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  if (Button == mbLeft) {
    Panel1->BevelInner = bvRaised;
    Panel1->BevelOuter = bvRaised;
  }
}
//---------------------------------------------------------------------------
void __fastcall TTreeConstructorForm::bCalculateClick(TObject *Sender)
{
  int i;
  AnsiString func;
  double *res;
  int param_count;
  double o[20] = {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0};

  Container->values.Length = Container->elems.Length;
  for (i = 0; i < Container->elems.Length; i++) {
    func = ConstructFunction(i, param_count);
    if (func == "") continue;
    res = new double[param_count];
    normal_optim(func, i + 1, o, res);
    FillResultValues(i, res);
    delete[] res;
  }
  Container->color_elements = true;
  Container->ArrangeElements();
//  Container->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TTreeConstructorForm::chbIndicatorVisibleClick(
      TObject *Sender)
{
  Container->SetIndicatorVisible(chbIndicatorVisible->Checked);
}
//---------------------------------------------------------------------------


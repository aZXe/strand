//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "FPConstructor.h"
#include "ChildGridWin.h"
#include "Optimization.h"
#include "MatrixFunctions.h"
#include "FPSave.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
extern TFPConstructorForm  *MainFPConstructorForm;
extern TChildGrid          *MainChildGrid;
//---------------------------------------------------------------------------
AnsiString FPFunction;
//---------------------------------------------------------------------------
AnsiString TFPConstructorForm::ConstructFunction(T2IntArray &X, bool isMultiply)
{
  int i, j, p;
  AnsiString tmp;

  if (isMultiply) {
    tmp = "a0";
    p = 1;
    for (i = 0; i < X.Length; i++) {
      tmp += " * (" + AnsiString(A->VarName[X[i][0]]) + " ^ (a" + IntToStr(p++);
      for (j = 1; j < X[i].Length; j++) {
        tmp += " + a" + IntToStr(p++) + "*" + A->VarName[X[i][j]];
      }
      tmp += "))";
    }
  }
  else {
    tmp = "a0";
    p = 1;
    for (i = 0; i < X.Length; i++)
      tmp += " + (" + AnsiString(A->VarName[X[i][0]]) + " * a" + IntToStr(p++) + ")";
  }

  return tmp;
}
//---------------------------------------------------------------------------
AnsiString TFPConstructorForm::ConstructFunction(T2IntArray &X, T2DoubleArray &R, bool isMultiply)
{
  int i, j;
  AnsiString tmp;

  if (isMultiply) {
    tmp = "1";
    for (i = 0; i < X.Length; i++) {
      tmp += " * (" + AnsiString(A->VarName[X[i][0]]) + " ^ (" + FloatToStr(R[i][0]);
      for (j = 1; j < X[i].Length; j++) {
        tmp += " + (" + FloatToStr(R[i][j]) + ")*" + A->VarName[X[i][j]];
      }
      tmp += "))";
    }
  }
  else {
    tmp = "0";
    for (i = 0; i < X.Length; i++)
      tmp += " + (" + AnsiString(A->VarName[X[i][0]]) + " * (" + FloatToStr(R[i][0]) + "))";
  }

  return tmp;
}
//---------------------------------------------------------------------------
__fastcall TFPConstructorForm::TFPConstructorForm(TComponent* Owner, TIntSet _Vars)
        : TForm(Owner)
{
  TIntSetIterator ii;

  Vars = _Vars;

  if (MainChildGrid == NULL) return;

  A = MainChildGrid->A;

  CorrGrid = new TCorrelationGrid(A, &Vars, this);
  CorrGrid->Parent = pCorrelation;
  CorrGrid->Top  = 100;
  CorrGrid->Left = 0;
  CorrGrid->Align  = alClient;

  MainVar = -1;

  cbMainVar->Items->Clear();
  for (ii = Vars.begin(); ii != Vars.end(); ii++)
    cbMainVar->Items->Add(A->VarName[*ii]);

  Container = new TFPContainer(this);

  Container->SetKoef(1);
  Container->Parent = sbDiagram;
  Container->Left = 0;
  Container->Top = 0;
  Container->Width  = 100;
  Container->Height = 100;
  Container->Picture->Bitmap->Height = Container->Height;
  Container->Picture->Bitmap->Width  = Container->Width;

  Container->FPRomb = Container->AddRomb();
  Container->FPRomb->Text = "Новый фактор-признак";

//  Container->AddBlock();
//  Container->AddBlock();

  Container->ArrangeElements();
  Container->Repaint();

  ChangeVarsList();
}
//---------------------------------------------------------------------------
__fastcall TFPConstructorForm::~TFPConstructorForm(void)
{
}
//---------------------------------------------------------------------------
void __fastcall TFPConstructorForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;
  if (MainFPConstructorForm == this)
    MainFPConstructorForm = NULL;        

  delete Container;
}
//---------------------------------------------------------------------------
void TFPConstructorForm::ChangeVarsList(void)
{
  TIntSetIterator ii;

  lbVars->Items->Clear();
  for (ii = Vars.begin(); ii != Vars.end(); ii++)
    if (!Container->ContainVar(A->VarName[*ii]))
      lbVars->Items->Add(A->VarName[*ii]);

  FPFunction = "";
}
//---------------------------------------------------------------------------
void __fastcall TFPConstructorForm::cbColorClick(TObject *Sender)
{
  CorrGrid->IsColor = cbColor->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TFPConstructorForm::cbNumbersClick(TObject *Sender)
{
  CorrGrid->IsNumbers = cbNumbers->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TFPConstructorForm::cbMainVarChange(TObject *Sender)
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

  ChangeVarsList();
}
//---------------------------------------------------------------------------
void __fastcall TFPConstructorForm::cbMainVarKeyPress(TObject *Sender,
      char &Key)
{
  Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFPConstructorForm::cbMainVarKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFPConstructorForm::bCloseClick(TObject *Sender)
{
  Close();        
}
//---------------------------------------------------------------------------
void __fastcall TFPConstructorForm::FormResize(TObject *Sender)
{
  Container->ArrangeElements();
  Container->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TFPConstructorForm::bOneToDiagramClick(TObject *Sender)
{
  int i = lbVars->ItemIndex;
  TBlock *b;
  TConnector *c;

  if (i == -1) return;

  b = Container->AddBlock();
  b->Text = lbVars->Items->Strings[i];
  c = Container->AddConnector(b->ID, Container->FPRomb->ID);
  c->EndArrowType = 1;
  lbVars->Items->Delete(i);

  lCorrelation->Caption = "R = ???";
  FPFunction = "";

  Container->ClearInformation();
  Container->ArrangeElements();
  Container->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TFPConstructorForm::bAllToDiagramClick(TObject *Sender)
{
  int i;
  TBlock *b;
  TConnector *c;

  for (i = 0; i < lbVars->Items->Count; i++) {
    b = Container->AddBlock();
    b->Text = lbVars->Items->Strings[i];
    c = Container->AddConnector(b->ID, Container->FPRomb->ID);
    c->EndArrowType = 1;
  }
  lbVars->Clear();

  lCorrelation->Caption = "R = ???";
  FPFunction = "";

  Container->ClearInformation();
  Container->ArrangeElements();
  Container->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TFPConstructorForm::bOneFromDiagramClick(TObject *Sender)
{
  if (Container->GetActiveElement() == NULL) return;
  if (Container->GetActiveElement()->GetType() != TBLOCK) return;

  Container->DeleteActiveElement();

  lCorrelation->Caption = "R = ???";
  FPFunction = "";

  Container->ClearInformation();
  Container->ArrangeElements();
  Container->Repaint();

  ChangeVarsList();
}
//---------------------------------------------------------------------------
void __fastcall TFPConstructorForm::bAllFromDiagramClick(TObject *Sender)
{
  Container->DeleteAllVars();

  lCorrelation->Caption = "R = ???";
  FPFunction = "";

  Container->ArrangeElements();
  Container->Repaint();

  ChangeVarsList();
}
//---------------------------------------------------------------------------
void __fastcall TFPConstructorForm::udLimitChangingEx(TObject *Sender,
      bool &AllowChange, short NewValue, TUpDownDirection Direction)
{
  if (NewValue < 1 || NewValue > 19) {
    AllowChange = false;
    return;
  }

  eLimit->Text = FloatToStrF(0.05 * NewValue, ffFixed, 2, 2);
  CorrGrid->Limit = 0.05 * NewValue;
}
//---------------------------------------------------------------------------
void __fastcall TFPConstructorForm::bCalculateClick(TObject *Sender)
{
  int i, j, count;
  double tmp, corr;
  const TDArrayElement *E = Container->GetElements();
  T2IntArray X;
  T2DoubleArray R;
  TDoubleArray Rtmp;
  TConnector *c;

  if (E->Length < 3) return;
  if (cbMainVar->ItemIndex == -1) return;

  count = (E->Length - 1) / 2;
  X.Length = count;
  for (j = i = 0; i < E->Length; i++)
    if ((*E)[i]->GetType() == TBLOCK) {
      X[j].Length = 1;
      X[j][0] = A->VarByName(dynamic_cast<TBlock *>((*E)[i])->Text);
      j++;
    }

  R = simpleoptim(A, X, A->VarByName(cbMainVar->Text), corr, rbMultRegression->Checked);

  lCorrelation->Caption = "R = " + FloatToStrF(corr, ffFixed, 2, 2);

  Rtmp.Length = count;

  tmp = 0;
  for (i = 0; i < R.Length; i++)
    tmp += fabs(R[i][0]);

  for (i = 0; i < R.Length; i++)
    Rtmp[i] = R[i][0] / tmp;

  for (j = i = 0; i < E->Length; i++)
    if ((*E)[i]->GetType() == TBLOCK) {
      c = dynamic_cast<TConnector *>(dynamic_cast<TBlock *>((*E)[i])->Out[0].second);
      c->Text_begin = FloatToStrF(fabs(Rtmp[j]), ffFixed, 2, 2);
      tmp = StrToFloat(c->Text_begin);
      c->TextFontBegin->Size = 7;
      c->TextFontEnd  ->Size = 7;

      if (Rtmp[j] >= 0) {
        c->Text_end = "";
        c->ColorLine = clGreen;
      }
      else {
        c->Text_end = "";
        c->ColorLine = clRed;
      }

      if (tmp < 0.05 ||
          Rtmp[j] * Correlation(A->GetVar(X[j][0]),
                                A->GetVar(A->VarByName(cbMainVar->Text))) < 0)
        c->ColorLine = TColor(0xe0e0e0); //clLtLtGray

      if (tmp >= 0.4) c->LineWidth = 3;
      else
        if (tmp >= 0.2) c->LineWidth = 2;
        else c->LineWidth = 1;

      j++;
    }

  FPFunction = ConstructFunction(X, R, rbMultRegression->Checked);

  Container->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TFPConstructorForm::sbAllocationClick(TObject *Sender)
{
  if (sbAllocation1->Down) Container->SetAllocationType(1);
  if (sbAllocation2->Down) Container->SetAllocationType(2);
  if (sbAllocation3->Down) Container->SetAllocationType(3);
}
//---------------------------------------------------------------------------
void __fastcall TFPConstructorForm::bSaveClick(TObject *Sender)
{
  if (FPFunction != "")
    if (FPSaveForm->ShowModal())
      A->AddVar(FPFunction, "F" + FPSaveForm->eName->Text);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
#ifndef TreeConstructorH
#define TreeConstructorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>

#include "TreeContainer.h"
#include "GridArray.h"
#include "Sets.h"
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TTreeConstructorForm : public TForm
{
__published:	// IDE-managed Components
        TPanel *pOptions;
        TPanel *pVars;
        TListBox *lbVars;
        TButton *bOneToDiagram;
        TButton *bOneFromDiagram;
        TLabel *lVars;
        TPanel *pDiagram;
        TScrollBox *sbDiagram;
        TPanel *pMisc;
        TLabel *lDiagram;
        TButton *bCalculate;
        TGroupBox *gbKindRegression;
        TRadioButton *rbAddRegression;
        TRadioButton *rbMultRegression;
        TGroupBox *gbMainVar;
        TComboBox *cbMainVar;
        TButton *bClose;
        TButton *bSave;
        TPanel *Panel1;
        TLabel *Label1;
        TCheckBox *chbIndicatorVisible;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall cbMainVarChange(TObject *Sender);
        void __fastcall cbMainVarKeyPress(TObject *Sender, char &Key);
        void __fastcall cbMainVarKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall bOneToDiagramClick(TObject *Sender);
        void __fastcall bOneFromDiagramClick(TObject *Sender);
        void __fastcall bCloseClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall bCalculateClick(TObject *Sender);
        void __fastcall Panel1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Panel1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
  void __fastcall chbIndicatorVisibleClick(TObject *Sender);

private:
  TArray *A;

  int MainVar;

  AnsiString ConstructFunction(int main_var, int &param_count);
  void FillResultValues(int main_var, double *res);
public:
  TIntSet Vars;

  TTreeContainer *Container;

  __fastcall TTreeConstructorForm(TComponent* Owner, TIntSet _Vars);
  __fastcall ~TTreeConstructorForm(void);

  void ChangeVarsList(void);
  friend AnsiString GetVarName(int var);
  friend double GetVarValue(int var);
};
//---------------------------------------------------------------------------
#endif

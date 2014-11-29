//---------------------------------------------------------------------------
#ifndef FPConstructorH
#define FPConstructorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>

#include "FPContainer.h"
#include "CorrelationGridUnit.h"
#include "Sets.h"
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFPConstructorForm : public TForm
{
__published:	// IDE-managed Components
        TPanel *pOptions;
        TPanel *pCorrelation;
        TGroupBox *gbCorrelation;
        TPanel *pVars;
        TListBox *lbVars;
        TButton *bOneToDiagram;
        TButton *bAllToDiagram;
        TButton *bOneFromDiagram;
        TButton *bAllFromDiagram;
        TEdit *eLimit;
        TLabel *lLimit;
        TCheckBox *cbColor;
        TCheckBox *cbNumbers;
        TLabel *lVars;
        TPanel *pDiagram;
        TScrollBox *sbDiagram;
        TPanel *pMisc;
        TLabel *lDiagram;
        TButton *bCalculate;
        TButton *bSave;
        TGroupBox *gbKindRegression;
        TRadioButton *rbAddRegression;
        TRadioButton *rbMultRegression;
        TGroupBox *gbMainVar;
        TComboBox *cbMainVar;
        TButton *bClose;
        TUpDown *udLimit;
        TGroupBox *GroupBox1;
        TSpeedButton *sbAllocation1;
        TSpeedButton *sbAllocation2;
        TSpeedButton *sbAllocation3;
        TLabel *lCorrelation;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall cbColorClick(TObject *Sender);
        void __fastcall cbNumbersClick(TObject *Sender);
        void __fastcall cbMainVarChange(TObject *Sender);
        void __fastcall cbMainVarKeyPress(TObject *Sender, char &Key);
        void __fastcall cbMainVarKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall bOneToDiagramClick(TObject *Sender);
        void __fastcall bOneFromDiagramClick(TObject *Sender);
        void __fastcall bCloseClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall bAllToDiagramClick(TObject *Sender);
        void __fastcall bAllFromDiagramClick(TObject *Sender);
        void __fastcall bCalculateClick(TObject *Sender);
        void __fastcall sbAllocationClick(TObject *Sender);
        void __fastcall udLimitChangingEx(TObject *Sender,
          bool &AllowChange, short NewValue, TUpDownDirection Direction);

private:
  TCorrelationGrid *CorrGrid;
  TArray *A;

  int MainVar;

public:
  TIntSet Vars;

  TFPContainer *Container;

  __fastcall TFPConstructorForm(TComponent* Owner, TIntSet _Vars);
  __fastcall ~TFPConstructorForm(void);

  void ChangeVarsList(void);
};
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------
#ifndef RavnomUnitH
#define RavnomUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "CGAUGES.h"
#include "CSPIN.h"
#include <ImgList.hpp>
#include <Menus.hpp>
#include "Charts.h"
#include "GraphingThreeChart.h"
#include "GridArray.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TStringGrid *SGrid;
        TOpenDialog *OpenStaDialog;
        TButton *btnOdnomAnaliz;
        TPanel *Panel;
        TCGauge *Progress;
        TStringGrid *RGrid;
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *N7;
        TMenuItem *N10;
        TMenuItem *N5;
        TMenuItem *N6;
        TMenuItem *N8;
        TEdit *eWeigh;
        TButton *Button1;
        TEdit *eNomer;
        TSaveDialog *SaveStaDialog;
  TMenuItem *miCreate;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall N7Click(TObject *Sender);
        void __fastcall btnOdnomAnalizClick(TObject *Sender);
        void __fastcall N10Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall N8Click(TObject *Sender);
        void __fastcall N6Click(TObject *Sender);
  void __fastcall miCreateClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

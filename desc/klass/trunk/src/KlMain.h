//---------------------------------------------------------------------------

#ifndef KlMainH
#define KlMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include "CGAUGES.h"
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TStringGrid *MainGrid;
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TCGauge *Progress;
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *N7;
        TOpenDialog *OpenStaDialog;
        TSaveDialog *SaveStaDialog;
        TMenuItem *N5;
        TMenuItem *N6;
        TPanel *Panel4;
        TEdit *eLeft;
        TLabel *Label1;
        TEdit *eFirst;
        TLabel *Label2;
        TButton *Button1;
        TButton *Button2;
        TActionList *ActionList1;
        TAction *ActionProsein;
        TAction *ActionUnion;
        TEdit *eUnions;
        TLabel *Label3;
        TButton *Button3;
        TEdit *ePrisoed;
        TLabel *Label4;
        TAction *ActionPrisoed;
        TEdit *eKlass;
        TLabel *Label5;
        TButton *Button4;
        TAction *ActionKlassif;
        TEdit *eAlphaProsein;
        TStringGrid *SG1;
        void __fastcall N7Click(TObject *Sender);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall N3Click(TObject *Sender);
        void __fastcall N5Click(TObject *Sender);
        void __fastcall ActionProseinExecute(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall ActionUnionExecute(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall ActionPrisoedExecute(TObject *Sender);
        void __fastcall ActionKlassifExecute(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

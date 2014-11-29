//---------------------------------------------------------------------------
#ifndef ConfigH
#define ConfigH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ActnList.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TConfigForm : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TButton *bOk;
        TButton *bCancel;
        TButton *bDefault;
        TGroupBox *GroupBox2;
        TCheckBox *cbGraphsShow;
        TLabel *Label1;
        TEdit *eGraphsPath;
        TGroupBox *GroupBox3;
        TCheckBox *cbNormalizingAddN;
        TCheckBox *cbNormalizingNormalize;
        TGroupBox *gbNormalizingDownBound;
        TGroupBox *gbNormalizingUpBound;
        TStaticText *StaticText2;
        TRadioButton *rbMinQuantile;
        TRadioButton *rb05Quantile;
        TRadioButton *rb25Quantile;
        TRadioButton *rbDownQuantile;
        TComboBox *cmbDownQuantile;
        TRadioButton *rbMaxQuantile;
        TRadioButton *rb95Quantile;
        TRadioButton *rb75Quantile;
        TRadioButton *rbUpQuantile;
        TComboBox *cmbUpQuantile;
        TActionList *ActionList1;
        TAction *Action1;
        TGroupBox *GroupBox4;
        TEdit *eBoxCoxDown;
        TEdit *eBoxCoxUp;
        TLabel *Label3;
        TLabel *Label4;
        TRadioButton *rbNormal;
        TRadioButton *rbLogNormal;
  TImage *Image1;
  TImage *Image2;
  TRadioButton *rbFormula2;
  TRadioButton *rbFormula1;
  TGroupBox *GroupBox6;
  TImage *Image3;
  TImage *Image4;
  TRadioButton *RadioButton1;
  TRadioButton *RadioButton2;
  TGroupBox *GroupBox5;
  TLabel *Label2;
  TLabel *Label5;
  TLabel *Label6;
  TLabel *Label7;
  TUpDown *UpDown1;
  TUpDown *UpDown2;
  TEdit *Edit1;
  TEdit *Edit2;
  TComboBox *ComboBox1;
  TComboBox *ComboBox2;
        void __fastcall cbNormalizingNormalizeClick(TObject *Sender);
        void __fastcall bDefaultClick(TObject *Sender);
        void __fastcall bOkClick(TObject *Sender);
        void __fastcall bCancelClick(TObject *Sender);
        void __fastcall Action1Execute(TObject *Sender);
        void __fastcall cmbDownQuantileChange(TObject *Sender);
        void __fastcall cmbUpQuantileChange(TObject *Sender);
        void __fastcall rbMinQuantileClick(TObject *Sender);
        void __fastcall rb05QuantileClick(TObject *Sender);
        void __fastcall rb25QuantileClick(TObject *Sender);
        void __fastcall rbDownQuantileClick(TObject *Sender);
        void __fastcall rbMaxQuantileClick(TObject *Sender);
        void __fastcall rb95QuantileClick(TObject *Sender);
        void __fastcall rb75QuantileClick(TObject *Sender);
        void __fastcall rbUpQuantileClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TConfigForm(TComponent* Owner);
        void __fastcall ConfigFileSave(void);
        void __fastcall ConfigFileLoad(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TConfigForm *ConfigForm;
extern int DownQuantile, UpQuantile;
//---------------------------------------------------------------------------
#endif

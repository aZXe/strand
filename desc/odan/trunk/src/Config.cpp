//---------------------------------------------------------------------------
#include <dir.h>
#include <vcl.h>
#pragma hdrstop

#include <inifiles.hpp>
#include "Config.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

extern AnsiString PathWork;

int DownQuantile, UpQuantile;
TConfigForm *ConfigForm;
//---------------------------------------------------------------------------
__fastcall TConfigForm::TConfigForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TConfigForm::FormCreate(TObject *Sender)
{
  cmbDownQuantile->ItemIndex = 0;
  cmbUpQuantile->ItemIndex   = 20;
  ConfigFileLoad();
}
//---------------------------------------------------------------------------
void __fastcall TConfigForm::ConfigFileSave(void)
{
  TMemIniFile *f;

  f = new TMemIniFile(PathWork + "\\odan.ini");

  f->WriteBool("Nature", "Normal", rbNormal->Checked);
  f->WriteBool("Graphs", "Show", cbGraphsShow->Checked);
  f->WriteString("Graphs", "Path", eGraphsPath->Text);
  f->WriteBool("Normalizing", "Normalize", cbNormalizingNormalize->Checked);
  f->WriteBool("Normalizing", "AddN", cbNormalizingAddN->Checked);
  f->WriteInteger("Normalizing", "DownQuantile", DownQuantile);
  f->WriteInteger("Normalizing", "UpQuantile", UpQuantile);
  f->WriteFloat("BoxCox", "Down", StrToFloat(eBoxCoxDown->Text));
  f->WriteFloat("BoxCox", "Up", StrToFloat(eBoxCoxUp->Text));
  f->UpdateFile();
  delete f;
}
//---------------------------------------------------------------------------
void __fastcall TConfigForm::ConfigFileLoad(void)
{
  TMemIniFile *f;
  bool b;

  f = new TMemIniFile(PathWork + "\\odan.ini");

  b = f->ReadBool("Nature", "Normal", true);
  if (b) rbNormal->Checked = true;
  else rbLogNormal->Checked = true;
  cbGraphsShow->Checked = f->ReadBool("Graphs", "Show", false);
  eGraphsPath->Text = f->ReadString("Graphs", "Path", PathWork + "\\graph");
  mkdir(eGraphsPath->Text.c_str());
  cbNormalizingNormalize->Checked = f->ReadBool("Normalizing", "Normalize", true);
  cbNormalizingAddN->Checked = f->ReadBool("Normalizing", "AddN", true);
  DownQuantile = f->ReadInteger("Normalizing", "DownQuantile", 5);
  UpQuantile = f->ReadInteger("Normalizing", "UpQuantile", 95);
  eBoxCoxDown->Text = FloatToStr(f->ReadFloat("BoxCox", "Down", -2.));
  eBoxCoxUp->Text = FloatToStr(f->ReadFloat("BoxCox", "Up", 5.));

  delete f;

  if (DownQuantile > 95  || DownQuantile < 0) DownQuantile = 5;
  if (UpQuantile   > 100 || UpQuantile   < 1) UpQuantile   = 95;
  if (DownQuantile >= UpQuantile) {
    DownQuantile = 25;
    UpQuantile   = 75;
  }
  switch (DownQuantile) {
    case 0  : rbMinQuantile->Checked = true; break;
    case 5  : rb05Quantile->Checked  = true; break;
    case 25 : rb25Quantile->Checked  = true; break;
    default :
      rbDownQuantile->Checked = true;
      cmbDownQuantile->ItemIndex = DownQuantile / 5;
  }
  switch (UpQuantile) {
    case 100 : rbMaxQuantile->Checked = true; break;
    case 95 : rb95Quantile->Checked  = true; break;
    case 75 : rb75Quantile->Checked  = true; break;
    default :
      rbUpQuantile->Checked = true;
      cmbUpQuantile->ItemIndex = UpQuantile / 5;
  }
}
//---------------------------------------------------------------------------
void __fastcall TConfigForm::cbNormalizingNormalizeClick(TObject *Sender)
{
  ActionList1->Actions[0]->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TConfigForm::bDefaultClick(TObject *Sender)
{
  rbNormal->Checked = true;
  cbGraphsShow->Checked = false;
  eGraphsPath->Text = PathWork + "\\graph";
  cbNormalizingNormalize->Checked = true;
  cbNormalizingAddN->Checked = true;
  rb05Quantile->Checked = true;
  rb95Quantile->Checked = true;
  eBoxCoxDown->Text = FloatToStr(-2.);
  eBoxCoxUp->Text = FloatToStr(5.);
}
//---------------------------------------------------------------------------
void __fastcall TConfigForm::bOkClick(TObject *Sender)
{
  ConfigFileSave();
  ConfigFileLoad();
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TConfigForm::bCancelClick(TObject *Sender)
{
  ConfigFileLoad();
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TConfigForm::Action1Execute(TObject *Sender)
{
  cbNormalizingAddN->Enabled = cbNormalizingNormalize->Checked;
  rbMinQuantile->Enabled = cbNormalizingNormalize->Checked;
  rb05Quantile->Enabled = cbNormalizingNormalize->Checked;
  rb25Quantile->Enabled = cbNormalizingNormalize->Checked;
  rbDownQuantile->Enabled = cbNormalizingNormalize->Checked;
  cmbDownQuantile->Enabled = cbNormalizingNormalize->Checked;
  rbMaxQuantile->Enabled = cbNormalizingNormalize->Checked;
  rb95Quantile->Enabled = cbNormalizingNormalize->Checked;
  rb75Quantile->Enabled = cbNormalizingNormalize->Checked;
  rbUpQuantile->Enabled = cbNormalizingNormalize->Checked;
  cmbUpQuantile->Enabled = cbNormalizingNormalize->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TConfigForm::cmbDownQuantileChange(TObject *Sender)
{
  rbDownQuantile->Checked = true;
  if (cmbDownQuantile->ItemIndex >= cmbUpQuantile->ItemIndex)
    cmbDownQuantile->ItemIndex = cmbUpQuantile->ItemIndex - 1;

  if (cmbDownQuantile->ItemIndex == 0)
    DownQuantile = 1;
  else
    DownQuantile = cmbDownQuantile->ItemIndex * 5;
}
//---------------------------------------------------------------------------
void __fastcall TConfigForm::cmbUpQuantileChange(TObject *Sender)
{
  rbUpQuantile->Checked = true;
  if (cmbUpQuantile->ItemIndex <= cmbDownQuantile->ItemIndex)
    cmbUpQuantile->ItemIndex = cmbDownQuantile->ItemIndex + 1;

  if (cmbUpQuantile->ItemIndex == 20)
    UpQuantile = 99;
  else
    UpQuantile = cmbUpQuantile->ItemIndex * 5;
}
//---------------------------------------------------------------------------
void __fastcall TConfigForm::rbMinQuantileClick(TObject *Sender)
{
  cmbDownQuantile->Enabled = false;
  DownQuantile = 0;
}
//---------------------------------------------------------------------------
void __fastcall TConfigForm::rb05QuantileClick(TObject *Sender)
{
  cmbDownQuantile->Enabled = false;
  DownQuantile = 5;
}
//---------------------------------------------------------------------------
void __fastcall TConfigForm::rb25QuantileClick(TObject *Sender)
{
  cmbDownQuantile->Enabled = false;
  DownQuantile = 25;
}
//---------------------------------------------------------------------------
void __fastcall TConfigForm::rbDownQuantileClick(TObject *Sender)
{
  cmbDownQuantile->Enabled = true;
  if (cmbDownQuantile->ItemIndex == 0)
    DownQuantile = 1;
  else
    DownQuantile = cmbDownQuantile->ItemIndex * 5;
}
//---------------------------------------------------------------------------
void __fastcall TConfigForm::rbMaxQuantileClick(TObject *Sender)
{
  cmbUpQuantile->Enabled = false;
  UpQuantile = 100;
}
//---------------------------------------------------------------------------
void __fastcall TConfigForm::rb95QuantileClick(TObject *Sender)
{
  cmbUpQuantile->Enabled = false;
  UpQuantile = 95;
}
//---------------------------------------------------------------------------

void __fastcall TConfigForm::rb75QuantileClick(TObject *Sender)
{
  cmbUpQuantile->Enabled = false;
  UpQuantile = 75;
}
//---------------------------------------------------------------------------
void __fastcall TConfigForm::rbUpQuantileClick(TObject *Sender)
{
  cmbUpQuantile->Enabled = true;
  if (cmbUpQuantile->ItemIndex == 20)
    UpQuantile = 99;
  else
    UpQuantile = cmbUpQuantile->ItemIndex * 5;
}
//---------------------------------------------------------------------------
void __fastcall TConfigForm::FormActivate(TObject *Sender)
{
  ConfigFileLoad();        
}
//---------------------------------------------------------------------------


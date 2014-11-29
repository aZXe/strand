//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Container.h"
#include "Constants.h"
#include "BlockForm.h"
#include "BlockIndicatorForm.h"
#include "ConnectorForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"

TDiagramForm *DiagramForm;
TContainer *Container;

AnsiString PathWork;
//---------------------------------------------------------------------------
__fastcall TDiagramForm::TDiagramForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::FormCreate(TObject *Sender)
{
  PathWork = ExtractFilePath(Application->ExeName);

  Container = new TContainer(this);

  Container->Properties[TBLOCK]          = new TBlockPropertyForm(NULL);
  Container->Properties[TROMB ]          = new TBlockPropertyForm(NULL);
  Container->Properties[TBLOCKINDICATOR] = new TBlockIndicatorPropertyForm(NULL);
  Container->Properties[TROMBINDICATOR ] = new TBlockIndicatorPropertyForm(NULL);
  Container->Properties[TCONNECTOR]      = new TConnectorPropertyForm(NULL);

  Container->SetKoef(1);
  Container->Parent = SB;
  Container->Left = 0;
  Container->Top = 0;
  Container->Width  = 800;
  Container->Height = 600;
  Container->Picture->Bitmap->Height = Container->Height;
  Container->Picture->Bitmap->Width  = Container->Width;
  if (ParamCount() > 0) {
    Container->LoadFromFile(ParamStr(1));
    PathWork = ExtractFilePath(ParamStr(1));
  }
  Container->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::FormDestroy(TObject *Sender)
{
  delete Container;
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::miOpenClick(TObject *Sender)
{
  OpenDlg->InitialDir = PathWork;
  if (OpenDlg->Execute()) {
    Container->LoadFromFile(OpenDlg->FileName);
    PathWork = ExtractFilePath(OpenDlg->FileName);
  }
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::miExitClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::BtnAddRombClick(TObject *Sender)
{
  Container->AddRomb();
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::FormActivate(TObject *Sender)
{
  Container->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::miNewClick(TObject *Sender)
{
  Container->Clear();
//  Container->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::miSaveAsClick(TObject *Sender)
{
  SaveDlg->DefaultExt = "dia";
  SaveDlg->InitialDir = PathWork;
  SaveDlg->Filter     = "Äטאדנאללû (*.dia)|*.dia";
  if (SaveDlg->Execute()) {
    Container->SaveToFile(SaveDlg->FileName);
    PathWork = ExtractFilePath(SaveDlg->FileName);
  }
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::miExportBMPClick(TObject *Sender)
{
  SaveDlg->DefaultExt = "bmp";
  SaveDlg->InitialDir = PathWork;
  SaveDlg->Filter     = "Windows Bitmap (*.bmp)|*.bmp";
  if (SaveDlg->Execute()) {
    Container->SaveAsBMP(SaveDlg->FileName);
    PathWork = ExtractFilePath(SaveDlg->FileName);
  }
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::miExportWMFClick(TObject *Sender)
{
  SaveDlg->DefaultExt = "wmf";
  SaveDlg->InitialDir = PathWork;
  SaveDlg->Filter     = "Windows Metafile (*.wmf)|*.wmf";
  if (SaveDlg->Execute()) {
    Container->SaveAsWMF(SaveDlg->FileName);
    PathWork = ExtractFilePath(SaveDlg->FileName);
  }
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::miExportEMFClick(TObject *Sender)
{
  SaveDlg->DefaultExt = "emf";
  SaveDlg->InitialDir = PathWork;
  SaveDlg->Filter     = "Windows Enhanced Metafile (*.emf)|*.emf";
  if (SaveDlg->Execute()) {
    Container->SaveAsEMF(SaveDlg->FileName);
    PathWork = ExtractFilePath(SaveDlg->FileName);
  }
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::ePercentChange(TObject *Sender)
{
  ePercent->Text += "%";
  Container->SetKoef(udPercent->Position * 0.01);
  Container->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::tbNewClick(TObject *Sender)
{
  miNew->Click();
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::tbOpenClick(TObject *Sender)
{
  miOpen->Click();
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::tbSaveAsClick(TObject *Sender)
{
  miSaveAs->Click();
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::tbExportBMPClick(TObject *Sender)
{
  miExportBMP->Click();
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::tbExportWMFClick(TObject *Sender)
{
  miExportWMF->Click();
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::tbExportEMFClick(TObject *Sender)
{
  miExportEMF->Click();
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::tbDeleteActiveElementClick(TObject *Sender)
{
  Container->DeleteActiveElement();
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::tbAddBlockClick(TObject *Sender)
{
  Container->AddBlock();
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::tbAddRombClick(TObject *Sender)
{
  Container->AddRomb();
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::tbAddBlockIndicatorClick(TObject *Sender)
{
  Container->AddBlockIndicator();
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::tbAddRombIndicatorClick(TObject *Sender)
{
  Container->AddRombIndicator();
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::tbPropertyClick(TObject *Sender)
{
  Container->ViewActiveElementPropertyForm();
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::tbAddConnectorClick(TObject *Sender)
{
  Container->AddConnector();
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::tbAddBiDirectConnectorClick(TObject *Sender)
{
  Container->AddConnector(true);
}
//---------------------------------------------------------------------------
void __fastcall TDiagramForm::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if (Key == VK_DELETE)
    Container->DeleteActiveElement();
}
//---------------------------------------------------------------------------


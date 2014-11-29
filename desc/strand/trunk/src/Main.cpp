//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <dir.h>
#pragma hdrstop

#include "GridArray.h"
#include "MatrixFunctions.h"
#include "MatrixDisplay.h"
#include "Graphing.h"
#include "OdnomAnaliz.h"
#include "Progress.h"
#include "MyStatFunctions.h"
#include "About.h"
#include "Logging.h"
#include "TreeParm.h"
#include "Utils.h"
#include "Main.h"
#include "FPConstructor.h"
#include "TreeConstructor.h"
//#include "MatMath\smatlab.hpp"
//---------------------------------------------------------------------------
//#pragma link "cgauges"
#pragma resource "*.dfm"
#pragma package(smart_init)
TMainForm            *MainForm;
TChildGrid           *MainChildGrid;
TChildLog            *MainChildLog;
TChildRegrMemo       *MainChildRegrMemo;
TFPConstructorForm   *MainFPConstructorForm;
TTreeConstructorForm *MainTreeConstructorForm;

AnsiString NameMainDataFile;
//---------------------------------------------------------------------------
TArray *Array, *dArray;
TAnsiStringArray VarsNames;
TIntArray VarsNums;

T2DoubleArray T, TT;
TIntArray Z, Z1;
T2DoubleArray Corr;

AnsiString PathWork;

bool new_tree;
#define MIN_COUNT        20
int filter_num = -1;
//---------------------------------------------------------------------------
#define SET_MAIN_CHILD_GRID_CAPTION \
  MainChildGrid->Caption = NameMainDataFile + \
                           " (v"+IntToStr((int)MainChildGrid->A->NVars)+ \
                            ";c"+IntToStr((int)MainChildGrid->A->NCases)+")"
//---------------------------------------------------------------------------
bool CompareVars(AnsiString varname1, AnsiString varname2);
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent *Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
  MainChildGrid = NULL;
  MainFPConstructorForm = NULL;
//  agProgress->Visible = false;
  EnableDataInterfaceItems(false);
/*
  strProgressBar = new TCGauge ( StatusBar1 );
  strProgressBar->Parent = StatusBar1;

  strProgressBar->Position = 0;
  strProgressBar->Visible = false;
*/  
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormActivate(TObject *Sender)
{
  MainChildLog = new TChildLog(Application);
  LogOpen("_strand_.log");
  LogAdd("--------------------------- BEGIN " + DateTimeToStr(Now()) +
         " ---------------------------");
  MainChildLog->Top    = 0;
  MainChildLog->Left   = 0;
  MainChildLog->Height = MainForm->ClientHeight / 2;
  MainChildLog->Width  = MainForm->ClientWidth - 5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormDestroy(TObject *Sender)
{
//  delete MainChildLog;
  LogClose();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CreateChildGrid(String Name)
{
  if (MainChildGrid == NULL)
    MainChildGrid = new TChildGrid(Application);
  else {
    MainChildGrid->Close();
    delete MainChildGrid;
    MainChildGrid = new TChildGrid(Application);
  }

  if (FileExists (Name)) {
    MainChildGrid->WindowState = wsMinimized;
    if (MainChildGrid->A->OpenDescFile(Name,
                                       Application->MessageBox("Обновить данные?",
                                                               "Обновление",
                                                               MB_YESNO + MB_ICONQUESTION
                                                              ) == IDYES
                                      ) == 0) {
      MainChildGrid->Close();
      MainChildGrid = NULL;
      return;
    }
    else {
      MainChildGrid->WindowState = wsNormal;
      NameMainDataFile = Name;
      SET_MAIN_CHILD_GRID_CAPTION;
      EnableDataInterfaceItems(true);
    }
  }
  else {
    Application->MessageBox(("Файл " + Name+ " не существует!").c_str(), "Ошибка", MB_OK + MB_ICONERROR);
    LogAdd("!!!Файл " + Name + " не существует");
    MainChildGrid->Close();
    MainChildGrid = NULL;
    return;
  }

  Array = MainChildGrid->A;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CreateChildGrid(const T2DoubleArray X,
                                           const TAnsiStringArray ColsCaptions,
                                           const TAnsiStringArray RowsCaptions,
                                           const AnsiString Name,
                                           const int ViewRowsCount,
                                           const int ViewColsCount)
{
  TChildGrid *Child;

  Child = new TChildGrid(Application);
  Child->Caption = Name;

  Child->A->SetData(X);
  Child->A->SetColsNames(ColsCaptions);
  Child->A->SetRowsNames(RowsCaptions);
  Child->ClientWidth  = (ViewColsCount) * Child->StringGrid1->DefaultColWidth;
  Child->ClientHeight = (ViewRowsCount + 2) * Child->StringGrid1->DefaultRowHeight;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CreateChildLog(void)
{
  TChildLog *Child;

  Child = new TChildLog(Application);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CreateChildCalcMemo(void)
{
  TChildCalcMemo *Child;

  Child = new TChildCalcMemo(Application);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CreateChildRegrMemo(void)
{
  MainChildRegrMemo = new TChildRegrMemo(Application);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CloseChildRegrMemo(void)
{
  MainChildRegrMemo->Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DataOpenExecute(TObject *Sender)
{
  if (OpenDialog->Execute())
    CreateChildGrid(OpenDialog->FileName);

  if (MainChildGrid != NULL) {
    LogAdd("Файл данных: " + OpenDialog->FileName);
    EnableDataInterfaceItems(true);
  }

/*
  if ((filter_num = Array->VarByName("FILTER")) == 0) {
    int nv = Array->NVars + 1;
    filter_num = nv;
    Array->NVars = nv;
    Array->VarName[nv] = "FILTER";
    LogAdd("Создана переменная 'FILTER'");
    SET_MAIN_CHILD_GRID_CAPTION;
  }
  for (long i = 0; i < Array->NCases; i++)
    Array->Cell[filter_num][i] = 1;
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::HelpAbout1Execute(TObject *Sender)
{
//  AboutBox = new TAboutBox(Application);
  AboutBox->ShowModal();
//  delete AboutBox;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FileExitExecute(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ToolButton12Click(TObject *Sender)
{
  CreateChildCalcMemo();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ToolButton13Click(TObject *Sender)
{
  new_tree = true;
  WinTreeParm = new TWinTreeParm(this);
  WinTreeParm->ShowModal();
  delete WinTreeParm;

//  FactorP();

  new_tree = false;
  WinTreeParm = new TWinTreeParm(this);
  WinTreeParm->ShowModal();
  delete WinTreeParm;

//  Regression();
}
//---------------------------------------------------------------------------
void __fastcall EnableDataInterfaceItems(bool e)
{
  MainForm->Analysis->Enabled = e;
  MainForm->DataSave->Enabled = e;
  MainForm->DataSaveAs->Enabled = e;
  MainForm->DataClose->Enabled = e;
  MainForm->DataRefresh->Enabled = e;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OptimizationItemClick(TObject *Sender)
{
  CreateChildCalcMemo();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::StatusBar1Resize(TObject *Sender)
{
/*
  int Size = StatusBar1->Width;
  for ( int i = 1; i < StatusBar1->Panels->Count; i++ )
    Size -= StatusBar1->Panels->Items[i]->Width;

  //resize the first panel based on the form width
  StatusBar1->Panels->Items[ 0 ]->Width = Size;
  RECT Rect;
  StatusBar1->Perform ( SB_GETRECT,  0,  (LPARAM)&Rect );

  strProgressBar->Top = Rect.top;
  strProgressBar->Left = Rect.left;
  strProgressBar->Width = StatusBar1->Panels->Items [ 0 ]->Width;
  strProgressBar->Height = Rect.bottom - Rect.top;
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TreeOpenExecute(TObject *Sender)
{
  if (OpenTreeDialog->Execute()) {
//    CreateChildGrid(OpenDialog->FileName);
  }
  LogAdd("Файл зависимостей: " + OpenTreeDialog->FileName);
//  if (MainChildGrid != NULL) EnableDataInterfaceItems(true);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ToolButton14Click(TObject *Sender)
{
  TIntSet Vars;

  if (MainChildGrid == NULL) return;

  if (MainFPConstructorForm == NULL) {
    for (int i = 1; i <= MainChildGrid->A->NVars; i++)
      Vars.insert(i);
    MainFPConstructorForm = new TFPConstructorForm(Application, Vars);
  }

  MainFPConstructorForm->Show();
}
//---------------------------------------------------------------------------
void CloseAllDependentWindows(void)
{
  if (MainFPConstructorForm != NULL)
    MainFPConstructorForm->Close();

  if (MainTreeConstructorForm != NULL)
    MainTreeConstructorForm->Close();

  if (MainChildRegrMemo != NULL)
    MainChildRegrMemo->Close();
}
//---------------------------------------------------------------------------
bool CompareVars(AnsiString varname1, AnsiString varname2)
{
  if (MainChildGrid == NULL) return false;
  
  return MainChildGrid->A->VarByName(varname1) > MainChildGrid->A->VarByName(varname2);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DataSaveExecute(TObject *Sender)
{
  if (MainChildGrid)
    MainChildGrid->A->SaveDescFile(NameMainDataFile,
                                   Application->MessageBox("Сохранить также и текущие данные?",
                                                           "Сохранение",
                                                           MB_YESNO + MB_ICONQUESTION
                                                          ) == IDYES);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DataCloseExecute(TObject *Sender)
{
  if (MainChildGrid)
    MainChildGrid->Close();

  MainChildGrid = NULL;
  EnableDataInterfaceItems(false);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DataSaveAsExecute(TObject *Sender)
{
  if (MainChildGrid)
    if (SaveDialog->Execute()) {
      MainChildGrid->A->SaveDescFile(SaveDialog->FileName,
                                     Application->MessageBox("Сохранить также и текущие данные?",
                                                             "Сохранение",
                                                             MB_YESNO + MB_ICONQUESTION
                                                            ) == IDYES);
      NameMainDataFile = SaveDialog->FileName;
      SET_MAIN_CHILD_GRID_CAPTION;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DataRefreshExecute(TObject *Sender)
{
  if (MainChildGrid)
    MainChildGrid->A->RefreshData();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ToolButton16Click(TObject *Sender)
{
  TIntSet Vars;

  if (MainChildGrid == NULL) return;

  if (MainTreeConstructorForm == NULL) {
    for (int i = 1; i <= MainChildGrid->A->NVars; i++)
      Vars.insert(i);
    MainTreeConstructorForm = new TTreeConstructorForm(Application, Vars);
  }

  MainTreeConstructorForm->Show();
}
//---------------------------------------------------------------------------


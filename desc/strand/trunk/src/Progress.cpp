//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

//#include "main.h"
#include "Progress.h"

double position;
double progress_step;
//extern TMainForm *MainForm;
//---------------------------------------------------------------------------
void ProgressCaption(AnsiString caption)
{
//  MainForm->strProgressBar->Caption = caption;
}
//---------------------------------------------------------------------------
void ProgressSet(double num)
{
/*
  position = (num > 100) ? 100 : ((num < 0) ? 0 : num);
  MainForm->strProgress->Position = (long)position;
*/
}
//---------------------------------------------------------------------------
void ProgressInc(void)
{
/*
  position += progress_step;
  position = (position > 100) ? 100 : ((position < 0) ? 0 : position);
  MainForm->agProgress->Position = (long)position;
*/
}
//---------------------------------------------------------------------------
void ProgressShow(void)
{
//  MainForm->strProgressBar->Visible = true;
}
//---------------------------------------------------------------------------
void ProgressHide(void)
{
//  ProgressCaption("");
//  MainForm->strProgressBar->Visible = false;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)

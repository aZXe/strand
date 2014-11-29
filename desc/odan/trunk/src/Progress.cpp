//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "CGAUGES.h"
#include "Progress.h"

double position;
double progress_step;
long   progress_position;
extern TPanel *_Panel;
extern TCGauge *_Progress;

//---------------------------------------------------------------------------
void ProgressCaption(AnsiString caption)
{
  _Panel->Caption = caption;
  _Panel->Repaint();
}
//---------------------------------------------------------------------------
void ProgressSet(double num)
{
  position = (num > 100) ? 100 : ((num < 0) ? 0 : num);
  _Progress->Progress = progress_position = (long)position;
}
//---------------------------------------------------------------------------
void ProgressInc(void)
{
  position += progress_step;
  position = (position > 100) ? 100 : ((position < 0) ? 0 : position);
  _Progress->Progress = progress_position = (long)position;
  Application->ProcessMessages();
}
//---------------------------------------------------------------------------
void ProgressShow(void)
{
  _Progress->Visible = TRUE;
}
//---------------------------------------------------------------------------
void ProgressHide(void)
{
  ProgressCaption("");
  _Progress->Visible = FALSE;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
#ifndef ProgressH
#define ProgressH
//---------------------------------------------------------------------------
extern double progress_step;
//---------------------------------------------------------------------------
void ProgressCaption(AnsiString caption);
void ProgressSet(double num);
void ProgressInc(void);
void ProgressShow(void);
void ProgressHide(void);
//---------------------------------------------------------------------------
#endif

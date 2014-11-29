//---------------------------------------------------------------------------
#ifndef ProgressH
#define ProgressH
//---------------------------------------------------------------------------
extern double progress_step;
extern long   progress_position;
//---------------------------------------------------------------------------
void ProgressCaption(AnsiString caption);
void ProgressSet(double num);
void ProgressInc(void);
void ProgressShow(void);
void ProgressHide(void);
//---------------------------------------------------------------------------
#endif

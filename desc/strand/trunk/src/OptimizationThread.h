//---------------------------------------------------------------------------
#ifndef OptimizationThreadH
#define OptimizationThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "MatMath\smatlab.hpp"
//---------------------------------------------------------------------------
typedef mwArray (*REGR_FUNCTION)(mwArray);
//---------------------------------------------------------------------------
class TOptimizationThread : public TThread
{
private:
  REGR_FUNCTION func;
  double *options;
  mwArray y, beta0;
  AnsiString str_tmp;
  double d_tmp;

  void __fastcall SLogAdd(void);
  void __fastcall SProgressCaption(void);
  void __fastcall SProgressSet(void);
  void __fastcall SProgressInc(void);
  void __fastcall SProgressShow(void);
  void __fastcall SProgressHide(void);
protected:
  void __fastcall Execute();
public:
  mwArray *beta_out, *r_out, *J_out;
  __fastcall TOptimizationThread(bool CreateSuspended, REGR_FUNCTION _func,
                                 mwArray *_beta_out, mwArray *_r_out,
                                 mwArray *_J_out, mwArray _y,
                                 mwArray _beta0, double *_options);
};
//---------------------------------------------------------------------------
#endif

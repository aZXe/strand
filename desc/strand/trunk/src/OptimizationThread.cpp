//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Logging.h"
#include "Progress.h"
#include "OptimizationThread.h"
#include "MatMath.cpp"

#pragma package(smart_init)
//---------------------------------------------------------------------------
//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TOptimizationThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------
__fastcall TOptimizationThread::TOptimizationThread(bool CreateSuspended, REGR_FUNCTION _func,
                                                    mwArray *_beta_out, mwArray *_r_out,
                                                    mwArray *_J_out, mwArray _y,
                                                    mwArray _beta0, double *_options)
        : TThread(CreateSuspended), func(_func), beta_out(_beta_out),
                                    r_out(_r_out), J_out(_J_out),
                                    y(_y), beta0(_beta0), options(_options)
{
}
//---------------------------------------------------------------------------
void __fastcall TOptimizationThread::SLogAdd(void)
{
  LogAdd(str_tmp);
}
void __fastcall TOptimizationThread::SProgressCaption(void)
{
  ProgressCaption(str_tmp);
}
void __fastcall TOptimizationThread::SProgressSet(void)
{
  ProgressSet(d_tmp);
}
void __fastcall TOptimizationThread::SProgressInc(void)
{
  ProgressInc();
}
void __fastcall TOptimizationThread::SProgressShow(void)
{
  ProgressShow();
}
void __fastcall TOptimizationThread::SProgressHide(void)
{
  ProgressHide();
}
//---------------------------------------------------------------------------
void __fastcall TOptimizationThread::Execute()
{
   int n = 0;
   int p = 0;
   mwArray betanew;
   int maxiter = 0;
   int iter = 0;
   double betatol = 0.0;
   double rtol = 0.0;
   mwArray sse;
   mwArray sseold;
   mwArray yfit;
   int k = 0;
   mwArray delta;
   mwArray yplus;
   mwArray Jplus;
   mwArray rplus;
   mwArray step;
   mwArray yfitnew;
   mwArray rnew;
   int iter1 = 0;

   options[0] = 0;
  str_tmp = "Ðåãðåññèÿ (ÒÅÑÒ)";
  Synchronize(SProgressCaption);
  progress_step = 1.0 / (p + 2);
  d_tmp = 0;
  Synchronize(SProgressSet);
  Synchronize(SProgressShow);
   mwArray beta = ((mxArray *) NULL);
   mwArray r = ((mxArray *) NULL);
   mwArray J = ((mxArray *) NULL);

   n = length(y);
   if ( tobool(min(size(y))!=1) )
   {
//      error("Requires a vector second input argument.");
     Synchronize(SProgressHide);
     str_tmp = "!!![nlinfit]Requires a vector 'second' input argument";
     Synchronize(SLogAdd);
     throw Exception("Requires a vector 'second' input argument.");
   }
   y = y(colon());
   p = length(beta0);
   beta0 = beta0(colon());
   J = zeros(n,p);
   beta = beta0;
   betanew = beta+1;
   maxiter = 100;
   iter = 0;
   betatol = 1.0e-4;
   rtol = 1.0e-4;
   sse = 1;
   sseold = sse;
   while ( (tobool(norm(rdivide(betanew-beta,beta+sqrt(eps())))>betatol) ||
            tobool(abs(sseold-sse)/(sse+sqrt(eps()))>rtol)) && tobool(iter<maxiter) )
   {
      if ( /*tobool*/(iter>0) )
      {
         beta = betanew;
      }
      iter = iter+1;
//      A = beta;
//      yfit = f->Evaluate();//RegrFunc();
      yfit = (*func)(beta);
     Synchronize(SProgressInc);
      options[0]++;
      r = y-yfit;
      sseold = ctranspose(r)*r;
      for (k=1; k<=p; k++ )
      {
//         k=_index1_k;
         delta = zeros(size(beta));
//         delta(k) = sqrt(eps())*beta(k);
         delta.Assign(sqrt(eps())*beta(k), k, 1);
//         A = beta+delta;
//         yplus = f->Evaluate();//RegrFunc();
         yplus = (*func)(beta+delta);
        Synchronize(SProgressInc);
         options[0]++;
//         J(colon(),k) = (yplus-yfit)/(sqrt(eps())*beta(k));
         J.Assign((yplus-yfit)/(sqrt(eps())*beta(k)), colon(), k);
      }
      Jplus = vertcat(J,1.0e-2*eye(p));
      rplus = vertcat(r,zeros(p,1));
      // % Levenberg-Marquardt type adjustment
      // % Gauss-Newton step -> J\r
      // % LM step -> inv(J'*J+constant*eye(p))*J'*r
      step = mldivide(Jplus,rplus);
      betanew = beta+step;
//      A = betanew;
//      yfitnew = f->Evaluate();//RegrFunc();
      yfitnew = (*func)(betanew);
     Synchronize(SProgressInc);
      options[0]++;
      rnew = y-yfitnew;
      sse = ctranspose(rnew)*rnew;
      iter1 = 0;
      while ( tobool(sse>sseold) && /*tobool*/(iter1<12) )
      {
         step = step/sqrt(mwArray(10));
         betanew = beta+step;
//         A = betanew;
//         yfitnew = f->Evaluate();//RegrFunc();
         yfitnew = (*func)(betanew);
         options[0]++;
         rnew = y-yfitnew;
         sse = ctranspose(rnew)*rnew;
         iter1 = iter1+1;
      }
   }
   if ( /*tobool*/(iter==maxiter) )
   {
//      disp("NLINFIT did NOT converge. Returning results from last iteration.");
     str_tmp = "[nlinfit]NLINFIT did NOT converge. Returning results from last iteration.";
     Synchronize(SLogAdd);
   }

   // Copy local variable(s) to corresponding output variable(s).
   if (r_out != 0) *r_out = r;
   if (J_out != 0) *J_out = J;
   Synchronize(SProgressHide);
   *beta_out = beta;
}
//---------------------------------------------------------------------------

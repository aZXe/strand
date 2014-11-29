static char mc_version[] = "MATLAB Compiler 1.2 Jan 17 1998 infun";
/*
 *  MATLAB Compiler: 1.2
 *  Date: Jan 17 1998
 *  Arguments: -p nlinfit 
 */
#ifndef ARRAY_ACCESS_INLINING
#error You must use the -inline option when compiling MATLAB compiler generated code with MEX or MBUILD
#endif

#include <iostream.h>
#include "matlab.hpp"
/***************** Compiler Assumptions ****************
 *
 *       J           	complex vector/matrix
 *       Jplus       	complex vector/matrix
 *       X           	complex vector/matrix
 *       abs         	<function>
 *       beta        	complex vector/matrix
 *       beta0       	complex vector/matrix
 *       betanew     	complex vector/matrix
 *       betatol     	real scalar
 *       delta       	complex vector/matrix
 *       disp        	<function>
 *       eps         	<function>
 *       error       	<function>
 *       eye         	<function>
 *       feval       	<function>
 *       iter        	integer scalar
 *       iter1       	integer scalar
 *       k           	integer scalar
 *       length      	<function>
 *       maxiter     	integer scalar
 *       min         	<function>
 *       model       	complex vector/matrix
 *       n           	integer scalar
 *       nlinfit     	<function being defined>
 *       norm        	<function>
 *       p           	integer scalar
 *       r           	complex vector/matrix
 *       rnew        	complex vector/matrix
 *       rplus       	complex vector/matrix
 *       rtol        	real scalar
 *       size        	<function>
 *       sqrt        	<function>
 *       sse         	complex vector/matrix
 *       sseold      	complex vector/matrix
 *       step        	complex vector/matrix
 *       y           	complex vector/matrix
 *       yfit        	complex vector/matrix
 *       yfitnew     	complex vector/matrix
 *       yplus       	complex vector/matrix
 *       zeros       	<function>
 *******************************************************/

mwArray nlinfit(mwArray *r_out_,mwArray *J_out_,mwArray X,mwArray y,mwArray model,mwArray beta0)
{
   mwArray TempMatrix_[32];
   mwArray rhs_[2];
   mwArray lhs_[1];
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
   
   mwArray beta = ((mxArray *) NULL);
   mwArray r = ((mxArray *) NULL);
   mwArray J = ((mxArray *) NULL);
   // NLINFIT Nonlinear least-squares data fitting by the Gauss-Newton method.
   // NLINFIT(X,Y,'MODEL',BETA0) finds the coefficients of the nonlinear 
   // function described in MODEL. MODEL is a user supplied function having 
   // the form y = f(beta,x). That is MODEL returns the predicted values of y
   // given initial parameter estimates, beta, and the independent variable, X.   
   // [BETA,R,J] = NLINFIT(X,Y,'MODEL',BETA0) returns the fitted coefficients
   // BETA the residuals, R, and the Jacobian, J, for use with NLINTOOL to
   // produce error estimates on predictions.
   // B.A. Jones 12-06-94.
   // Copyright (c) 1993-98 by The MathWorks, Inc.
   // $Revision: 2.10 $  $Date: 1997/11/29 01:46:10 $
   n = length(y);
   if ( tobool(min(size(y))!=1) )
   {
      error("Requires a vector second input argument.");
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
   while ( (tobool(norm(rdivide(betanew-beta,beta+sqrt(eps())))>betatol) || tobool(abs(sseold-sse)/(sse+sqrt(eps()))>rtol)) && tobool(iter<maxiter) )
   {
      if ( tobool(iter>0) )
      {
         beta = betanew;
      }
      iter = iter+1;
      rhs_[0] = beta;
      rhs_[1] = X;
      feval( 1, lhs_, 2, rhs_, model.ToString() );
      yfit = lhs_[0];
      r = y-yfit;
      sseold = ctranspose(r)*r;
      for (int _index1_k=1; _index1_k<=p; ++_index1_k )
      {
         k=_index1_k;
         delta = zeros(size(beta));
         delta(k) = sqrt(eps())*beta(k);
         rhs_[0] = beta+delta;
         rhs_[1] = X;
         feval( 1, lhs_, 2, rhs_, model.ToString() );
         yplus = lhs_[0];
         J(colon(),k) = (yplus-yfit)/(sqrt(eps())*beta(k));
      }
      Jplus = vertcat(J,1.0e-2*eye(p));
      rplus = vertcat(r,zeros(p,1));
      // % Levenberg-Marquardt type adjustment 
      // % Gauss-Newton step -> J\r
      // % LM step -> inv(J'*J+constant*eye(p))*J'*r
      step = mldivide(Jplus,rplus);
      betanew = beta+step;
      rhs_[0] = betanew;
      rhs_[1] = X;
      feval( 1, lhs_, 2, rhs_, model.ToString() );
      yfitnew = lhs_[0];
      rnew = y-yfitnew;
      sse = ctranspose(rnew)*rnew;
      iter1 = 0;
      while ( tobool(sse>sseold) && tobool(iter1<12) )
      {
         step = step/sqrt(mwArray(10));
         betanew = beta+step;
         rhs_[0] = betanew;
         rhs_[1] = X;
         feval( 1, lhs_, 2, rhs_, model.ToString() );
         yfitnew = lhs_[0];
         rnew = y-yfitnew;
         sse = ctranspose(rnew)*rnew;
         iter1 = iter1+1;
      }
   }
   if ( tobool(iter==maxiter) )
   {
      disp("NLINFIT did NOT converge. Returning results from last iteration.");
   }
   
   // Copy local variable(s) to corresponding output variable(s).
   if (r_out_ != 0) *r_out_ = r;
   if (J_out_ != 0) *J_out_ = J;
   return(beta);
}

//
// MATLAB Compiler: 2.1
// Date: Fri Jan 04 16:59:50 2002
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "Cpp" "-A"
// "annotation:all" "-O" "all" "-O" "fold_scalar_mxarrays:on" "-O"
// "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "nlinfit" 
//
#include "nlinfit.hpp"
#include "libmatlbm.hpp"

static mxChar _array1_[132] = { 'R', 'u', 'n', '-', 't', 'i', 'm', 'e', ' ',
                                'E', 'r', 'r', 'o', 'r', ':', ' ', 'F', 'i',
                                'l', 'e', ':', ' ', 'n', 'l', 'i', 'n', 'f',
                                'i', 't', ' ', 'L', 'i', 'n', 'e', ':', ' ',
                                '1', ' ', 'C', 'o', 'l', 'u', 'm', 'n', ':',
                                ' ', '1', ' ', 'T', 'h', 'e', ' ', 'f', 'u',
                                'n', 'c', 't', 'i', 'o', 'n', ' ', '"', 'n',
                                'l', 'i', 'n', 'f', 'i', 't', '"', ' ', 'w',
                                'a', 's', ' ', 'c', 'a', 'l', 'l', 'e', 'd',
                                ' ', 'w', 'i', 't', 'h', ' ', 'm', 'o', 'r',
                                'e', ' ', 't', 'h', 'a', 'n', ' ', 't', 'h',
                                'e', ' ', 'd', 'e', 'c', 'l', 'a', 'r', 'e',
                                'd', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ',
                                'o', 'f', ' ', 'o', 'u', 't', 'p', 'u', 't',
                                's', ' ', '(', '3', ')', '.' };
static mwArray _mxarray0_ = mclInitializeString(132, _array1_);

static mxChar _array3_[131] = { 'R', 'u', 'n', '-', 't', 'i', 'm', 'e', ' ',
                                'E', 'r', 'r', 'o', 'r', ':', ' ', 'F', 'i',
                                'l', 'e', ':', ' ', 'n', 'l', 'i', 'n', 'f',
                                'i', 't', ' ', 'L', 'i', 'n', 'e', ':', ' ',
                                '1', ' ', 'C', 'o', 'l', 'u', 'm', 'n', ':',
                                ' ', '1', ' ', 'T', 'h', 'e', ' ', 'f', 'u',
                                'n', 'c', 't', 'i', 'o', 'n', ' ', '"', 'n',
                                'l', 'i', 'n', 'f', 'i', 't', '"', ' ', 'w',
                                'a', 's', ' ', 'c', 'a', 'l', 'l', 'e', 'd',
                                ' ', 'w', 'i', 't', 'h', ' ', 'm', 'o', 'r',
                                'e', ' ', 't', 'h', 'a', 'n', ' ', 't', 'h',
                                'e', ' ', 'd', 'e', 'c', 'l', 'a', 'r', 'e',
                                'd', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ',
                                'o', 'f', ' ', 'i', 'n', 'p', 'u', 't', 's',
                                ' ', '(', '4', ')', '.' };
static mwArray _mxarray2_ = mclInitializeString(131, _array3_);

static mxChar _array5_[32] = { 'N', 'L', 'I', 'N', 'F', 'I', 'T', ' ',
                               'r', 'e', 'q', 'u', 'i', 'r', 'e', 's',
                               ' ', 'f', 'o', 'u', 'r', ' ', 'a', 'r',
                               'g', 'u', 'm', 'e', 'n', 't', 's', '.' };
static mwArray _mxarray4_ = mclInitializeString(32, _array5_);
static mwArray _mxarray6_ = mclInitializeDouble(1.0);

static mxChar _array8_[40] = { 'R', 'e', 'q', 'u', 'i', 'r', 'e', 's',
                               ' ', 'a', ' ', 'v', 'e', 'c', 't', 'o',
                               'r', ' ', 's', 'e', 'c', 'o', 'n', 'd',
                               ' ', 'i', 'n', 'p', 'u', 't', ' ', 'a',
                               'r', 'g', 'u', 'm', 'e', 'n', 't', '.' };
static mwArray _mxarray7_ = mclInitializeString(40, _array8_);
static mwArray _mxarray9_ = mclInitializeDouble(2.0);
static mwArray _mxarray10_ = mclInitializeDouble(100.0);
static mwArray _mxarray11_ = mclInitializeDouble(0.0);
static mwArray _mxarray12_ = mclInitializeDouble(.0001);
static mwArray _mxarray13_ = mclInitializeDouble(2.220446049250313e-16);
static mwArray _mxarray14_ = mclInitializeDouble(10.0);
static mwArray _mxarray15_ = mclInitializeDoubleVector(0, 0, (double *)NULL);
static mwArray _mxarray16_ = mclInitializeDouble(.01);
static mwArray _mxarray17_ = mclInitializeDouble(12.0);

static mxChar _array19_[64] = { 'N', 'L', 'I', 'N', 'F', 'I', 'T', ' ',
                                'd', 'i', 'd', ' ', 'N', 'O', 'T', ' ',
                                'c', 'o', 'n', 'v', 'e', 'r', 'g', 'e',
                                '.', ' ', 'R', 'e', 't', 'u', 'r', 'n',
                                'i', 'n', 'g', ' ', 'r', 'e', 's', 'u',
                                'l', 't', 's', ' ', 'f', 'r', 'o', 'm',
                                ' ', 'l', 'a', 's', 't', ' ', 'i', 't',
                                'e', 'r', 'a', 't', 'i', 'o', 'n', '.' };
static mwArray _mxarray18_ = mclInitializeString(64, _array19_);

void InitializeModule_nlinfit() {
}

void TerminateModule_nlinfit() {
}

static mwArray Mnlinfit(mwArray * r,
                        mwArray * J,
                        int nargout_,
                        mwArray X,
                        mwArray y,
                        mwArray model,
                        mwArray beta0);

_mexLocalFunctionTable _local_function_table_nlinfit
  = { 0, (mexFunctionTableEntry *)NULL };

//
// The function "nlinfit" contains the normal interface for the "nlinfit"
// M-function from file "D:\matlabR12\toolbox\stats\nlinfit.m" (lines 1-118).
// This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
mwArray nlinfit(mwArray * r,
                mwArray * J,
                mwArray X,
                mwArray y,
                mwArray model,
                mwArray beta0) {
    int nargout(1);
    mwArray beta(mclGetUninitializedArray());
    mwArray r__(mclGetUninitializedArray());
    mwArray J__(mclGetUninitializedArray());
    if (r != NULL) {
        ++nargout;
    }
    if (J != NULL) {
        ++nargout;
    }
    beta = Mnlinfit(&r__, &J__, nargout, X, y, model, beta0);
    if (r != NULL) {
        *r = r__;
    }
    if (J != NULL) {
        *J = J__;
    }
    return beta;
}

//
// The function "mlxNlinfit" contains the feval interface for the "nlinfit"
// M-function from file "D:\matlabR12\toolbox\stats\nlinfit.m" (lines 1-118).
// The feval function calls the implementation version of nlinfit through this
// function. This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
void mlxNlinfit(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    MW_BEGIN_MLX();
    {
        mwArray mprhs[4];
        mwArray mplhs[3];
        int i;
        mclCppUninitializeArrays(3, mplhs);
        if (nlhs > 3) {
            error(_mxarray0_);
        }
        if (nrhs > 4) {
            error(_mxarray2_);
        }
        for (i = 0; i < 4 && i < nrhs; ++i) {
            mprhs[i] = mwArray(prhs[i], 0);
        }
        for (; i < 4; ++i) {
            mprhs[i].MakeDIN();
        }
        mplhs[0]
          = Mnlinfit(
              &mplhs[1],
              &mplhs[2],
              nlhs,
              mprhs[0],
              mprhs[1],
              mprhs[2],
              mprhs[3]);
        plhs[0] = mplhs[0].FreezeData();
        for (i = 1; i < 3 && i < nlhs; ++i) {
            plhs[i] = mplhs[i].FreezeData();
        }
    }
    MW_END_MLX();
}

//
// The function "Mnlinfit" is the implementation version of the "nlinfit"
// M-function from file "D:\matlabR12\toolbox\stats\nlinfit.m" (lines 1-118).
// It contains the actual compiled code for that M-function. It is a static
// function and must only be called from one of the interface functions,
// appearing below.
//
//
// function [beta,r,J] = nlinfit(X,y,model,beta0)
//
static mwArray Mnlinfit(mwArray * r,
                        mwArray * J,
                        int nargout_,
                        mwArray X,
                        mwArray y,
                        mwArray model,
                        mwArray beta0) {
    mwLocalFunctionTable save_local_function_table_(&_local_function_table_nlinfit);
    int nargin_(nargin(4, mwVarargin(X, y, model, beta0)));
    mwArray beta(mclGetUninitializedArray());
    mwArray iter1(mclGetUninitializedArray());
    mwArray rnew(mclGetUninitializedArray());
    mwArray yfitnew(mclGetUninitializedArray());
    mwArray step(mclGetUninitializedArray());
    mwArray rplus(mclGetUninitializedArray());
    mwArray Jplus(mclGetUninitializedArray());
    mwArray yplus(mclGetUninitializedArray());
    mwArray nb(mclGetUninitializedArray());
    mwArray delta(mclGetUninitializedArray());
    mwArray k(mclGetUninitializedArray());
    mwArray yfit(mclGetUninitializedArray());
    mwArray zerosp(mclGetUninitializedArray());
    mwArray eyep(mclGetUninitializedArray());
    mwArray s10(mclGetUninitializedArray());
    mwArray zbeta(mclGetUninitializedArray());
    mwArray seps(mclGetUninitializedArray());
    mwArray sseold(mclGetUninitializedArray());
    mwArray sse(mclGetUninitializedArray());
    mwArray rtol(mclGetUninitializedArray());
    mwArray betatol(mclGetUninitializedArray());
    mwArray iter(mclGetUninitializedArray());
    mwArray maxiter(mclGetUninitializedArray());
    mwArray betanew(mclGetUninitializedArray());
    mwArray p(mclGetUninitializedArray());
    mwArray n(mclGetUninitializedArray());
    mwArray wasnan(mclGetUninitializedArray());
    mwArray ans(mclGetUninitializedArray());
    //
    // %NLINFIT Nonlinear least-squares data fitting by the Gauss-Newton method.
    // %   NLINFIT(X,Y,FUN,BETA0) estimates the coefficients of a nonlinear
    // %   function.  Y is a vector.  X is a vector or matrix with the same
    // %   number of rows as Y.  FUN is a function that accepts two arguments,
    // %   a coefficient vector and an array of X values, and returns a vector
    // %   of fitted Y values.  BETA0 is a vector containing initial guesses for
    // %   the coefficients.
    // %
    // %   [BETA,R,J] = NLINFIT(X,Y,FUN,BETA0) returns the fitted coefficients
    // %   BETA, the residuals R, and the Jacobian J.  You can use these outputs
    // %   with NLPREDCI to produce error estimates on predictions, and with
    // %   NLPARCI to produce error estimates on the estimated coefficients.
    // %
    // %   Examples
    // %   --------
    // %   FUN can be specified using @:
    // %      nlintool(x, y, @myfun, b0)
    // %   where MYFUN is a MATLAB function such as:
    // %      function yhat = myfun(beta, x)
    // %      b1 = beta(1);
    // %      b2 = beta(2);
    // %      yhat = 1 ./ (1 + exp(b1 + b2*x));
    // %
    // %   FUN can also be an inline object:
    // %      fun = inline('1 ./ (1 + exp(b(1) + b(2)*x))', 'b', 'x')
    // %      nlintool(x, y, fun, b0)
    // %
    // %   See also NLPARCI, NLPREDCI, NLINTOOL.
    // 
    // %   B.A. Jones 12-06-94.
    // %   Copyright 1993-2000 The MathWorks, Inc. 
    // % $Revision: 2.20 $  $Date: 2000/05/26 18:53:20 $
    // 
    // if (nargin<4), error('NLINFIT requires four arguments.'); end
    //
    if (nargin_ < 4) {
        error(_mxarray4_);
    }
    //
    // 
    // if min(size(y)) ~= 1
    //
    if (mclNeBool(
          mwVe(min(mwVe(size(mwValueVarargout(), mwVa(y, "y"))))),
          _mxarray6_)) {
        //
        // error('Requires a vector second input argument.');
        //
        error(_mxarray7_);
    //
    // end
    //
    }
    //
    // y = y(:);
    //
    y = mclArrayRef(mwVsa(y, "y"), colon());
    //
    // 
    // if size(X,1) == 1 % turn a row vector into a column vector.
    //
    if (mclEqBool(
          mwVe(size(mwValueVarargout(), mwVa(X, "X"), _mxarray6_)),
          _mxarray6_)) {
        //
        // X = X(:);
        //
        X = mclArrayRef(mwVsa(X, "X"), colon());
    //
    // end
    //
    }
    //
    // 
    // wasnan = (isnan(y) | any(isnan(X),2));
    //
    wasnan
      = mwVe(isnan(mwVa(y, "y")))
        | mwVe(any(mwVe(isnan(mwVa(X, "X"))), _mxarray9_));
    //
    // if (any(wasnan))
    //
    if (tobool(mwVe(any(mwVv(wasnan, "wasnan"))))) {
        //
        // y(wasnan) = [];
        //
        y(mwVsv(wasnan, "wasnan")) = mwEmptySqBracket();
        //
        // X(wasnan,:) = [];
        //
        X(mwVsv(wasnan, "wasnan"), colon()) = mwEmptySqBracket();
    //
    // end
    //
    }
    //
    // n = length(y);
    //
    n = mclLengthInt(mwVa(y, "y"));
    //
    // 
    // p = length(beta0);
    //
    p = mclLengthInt(mwVa(beta0, "beta0"));
    //
    // beta0 = beta0(:);
    //
    beta0 = mclArrayRef(mwVsa(beta0, "beta0"), colon());
    //
    // 
    // J = zeros(n,p);
    //
    *J = zeros(mwVarargin(mwVv(n, "n"), mwVv(p, "p")));
    //
    // beta = beta0;
    //
    beta = mwVsa(beta0, "beta0");
    //
    // betanew = beta + 1;
    //
    betanew = mwVv(beta, "beta") + _mxarray6_;
    //
    // maxiter = 100;
    //
    maxiter = _mxarray10_;
    //
    // iter = 0;
    //
    iter = _mxarray11_;
    //
    // betatol = 1.0E-4;
    //
    betatol = _mxarray12_;
    //
    // rtol = 1.0E-4;
    //
    rtol = _mxarray12_;
    //
    // sse = 1;
    //
    sse = _mxarray6_;
    //
    // sseold = sse;
    //
    sseold = mwVsv(sse, "sse");
    //
    // seps = sqrt(eps);
    //
    seps = sqrt(_mxarray13_);
    //
    // zbeta = zeros(size(beta));
    //
    zbeta
      = zeros(mwVarargin(mwVe(size(mwValueVarargout(), mwVv(beta, "beta")))));
    //
    // s10 = sqrt(10);
    //
    s10 = sqrt(_mxarray14_);
    //
    // eyep = eye(p);
    //
    eyep = eye(mwVv(p, "p"));
    //
    // zerosp = zeros(p,1);
    //
    zerosp = zeros(mwVarargin(mwVv(p, "p"), _mxarray6_));
    //
    // 
    // while (norm((betanew-beta)./(beta+seps)) > betatol | abs(sseold-sse)/(sse+seps) > rtol) & iter < maxiter
    //
    for (;;) {
        mwArray a_(mwVe(
                     norm(
                       rdivide(
                         mwVv(betanew, "betanew") - mwVv(beta, "beta"),
                         mwVv(beta, "beta") + mwVv(seps, "seps"))))
                   > mwVv(betatol, "betatol"));
        if (tobool(a_)) {
            a_ = 1;
        } else {
            a_
              = a_
                | mwVe(abs(mwVv(sseold, "sseold") - mwVv(sse, "sse")))
                  / (mwVv(sse, "sse") + mwVv(seps, "seps"))
                  > mwVv(rtol, "rtol");
        }
        if (tobool(a_)
            && tobool(a_ & mwVv(iter, "iter") < mwVv(maxiter, "maxiter"))) {
        } else {
            break;
        }
        //
        // if iter > 0, 
        //
        if (mclGtBool(mwVv(iter, "iter"), _mxarray11_)) {
            //
            // beta = betanew;
            //
            beta = mwVsv(betanew, "betanew");
        //
        // end
        //
        }
        //
        // 
        // iter = iter + 1;
        //
        iter = mwVv(iter, "iter") + _mxarray6_;
        //
        // yfit = feval(model,beta,X);
        //
        yfit
          = feval(
              mwValueVarargout(),
              mwVarargin(
                mwVa(model, "model"), mwVv(beta, "beta"), mwVa(X, "X")));
        //
        // r = y - yfit;
        //
        *r = mwVa(y, "y") - mwVv(yfit, "yfit");
        //
        // sseold = r'*r;
        //
        sseold = ctranspose(mwVv(*r, "r")) * mwVv(*r, "r");
        //
        // 
        // for k = 1:p,
        //
        {
            int v_(mclForIntStart(1));
            int e_(mclForIntEnd(mwVv(p, "p")));
            if (v_ > e_) {
                k = _mxarray15_;
            } else {
                //
                // delta = zbeta;
                // if (beta(k) == 0)
                // nb = sqrt(norm(beta));
                // delta(k) = seps * (nb + (nb==0));
                // else
                // delta(k) = seps*beta(k);
                // end
                // yplus = feval(model,beta+delta,X);
                // J(:,k) = (yplus - yfit)/delta(k);
                // end
                //
                for (; ; ) {
                    delta = mwVsv(zbeta, "zbeta");
                    if (mclEqBool(
                          mwVe(mclIntArrayRef(mwVsv(beta, "beta"), v_)),
                          _mxarray11_)) {
                        nb = sqrt(mwVe(norm(mwVv(beta, "beta"))));
                        mclIntArrayAssign(
                          &delta,
                          mwVv(seps, "seps")
                          * (mwVv(nb, "nb") + (mwVv(nb, "nb") == _mxarray11_)),
                          v_);
                    } else {
                        mclIntArrayAssign(
                          &delta,
                          mwVv(seps, "seps")
                          * mwVe(mclIntArrayRef(mwVsv(beta, "beta"), v_)),
                          v_);
                    }
                    yplus
                      = feval(
                          mwValueVarargout(),
                          mwVarargin(
                            mwVa(model, "model"),
                            mwVv(beta, "beta") + mwVv(delta, "delta"),
                            mwVa(X, "X")));
                    mclArrayAssign(
                      J,
                      (mwVv(yplus, "yplus") - mwVv(yfit, "yfit"))
                      / mwVe(mclIntArrayRef(mwVsv(delta, "delta"), v_)),
                      colon(),
                      v_);
                    if (v_ == e_) {
                        break;
                    }
                    ++v_;
                }
                k = v_;
            }
        }
        //
        // 
        // Jplus = [J;(1.0E-2)*eyep];
        //
        Jplus
          = vertcat(
              mwVarargin(mwVv(*J, "J"), _mxarray16_ * mwVv(eyep, "eyep")));
        //
        // rplus = [r;zerosp];
        //
        rplus = vertcat(mwVarargin(mwVv(*r, "r"), mwVv(zerosp, "zerosp")));
        //
        // 
        // % Levenberg-Marquardt type adjustment 
        // % Gauss-Newton step -> J\r
        // % LM step -> inv(J'*J+constant*eye(p))*J'*r
        // step = Jplus\rplus;
        //
        step = mldivide(mwVv(Jplus, "Jplus"), mwVv(rplus, "rplus"));
        //
        // 
        // betanew = beta + step;
        //
        betanew = mwVv(beta, "beta") + mwVv(step, "step");
        //
        // yfitnew = feval(model,betanew,X);
        //
        yfitnew
          = feval(
              mwValueVarargout(),
              mwVarargin(
                mwVa(model, "model"), mwVv(betanew, "betanew"), mwVa(X, "X")));
        //
        // rnew = y - yfitnew;
        //
        rnew = mwVa(y, "y") - mwVv(yfitnew, "yfitnew");
        //
        // sse = rnew'*rnew;
        //
        sse = ctranspose(mwVv(rnew, "rnew")) * mwVv(rnew, "rnew");
        //
        // iter1 = 0;
        //
        iter1 = _mxarray11_;
        //
        // while sse > sseold & iter1 < 12
        //
        for (;;) {
            mwArray a_(mwVv(sse, "sse") > mwVv(sseold, "sseold"));
            if (tobool(a_) && tobool(a_ & mwVv(iter1, "iter1") < _mxarray17_)) {
            } else {
                break;
            }
            //
            // step = step/s10;
            //
            step = mwVv(step, "step") / mwVv(s10, "s10");
            //
            // betanew = beta + step;
            //
            betanew = mwVv(beta, "beta") + mwVv(step, "step");
            //
            // yfitnew = feval(model,betanew,X);
            //
            yfitnew
              = feval(
                  mwValueVarargout(),
                  mwVarargin(
                    mwVa(model, "model"),
                    mwVv(betanew, "betanew"),
                    mwVa(X, "X")));
            //
            // rnew = y - yfitnew;
            //
            rnew = mwVa(y, "y") - mwVv(yfitnew, "yfitnew");
            //
            // sse = rnew'*rnew;
            //
            sse = ctranspose(mwVv(rnew, "rnew")) * mwVv(rnew, "rnew");
            //
            // iter1 = iter1 + 1;
            //
            iter1 = mwVv(iter1, "iter1") + _mxarray6_;
        //
        // end
        //
        }
    //
    // end
    //
    }
    //
    // if iter == maxiter
    //
    if (mclEqBool(mwVv(iter, "iter"), mwVv(maxiter, "maxiter"))) {
        //
        // disp('NLINFIT did NOT converge. Returning results from last iteration.');
        //
        disp(_mxarray18_);
    //
    // end
    //
    }
    mwValidateOutput(beta, 1, nargout_, "beta", "nlinfit");
    mwValidateOutput(*r, 2, nargout_, "r", "nlinfit");
    mwValidateOutput(*J, 3, nargout_, "J", "nlinfit");
    return beta;
}

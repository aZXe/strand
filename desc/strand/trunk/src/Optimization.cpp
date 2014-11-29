//---------------------------------------------------------------------------
#include <vcl.h>
#include <fstream.h>
#pragma hdrstop

#include "DArrayTypes.h"
#include "Optimization.h"
//#include "OptimizationThread.h"
#include "CalcMFunctions.h"
#include "Progress.h"
#include "MatrixFunctions.h"
#include "Options.h"
//#include "BugslayerUtil.h"
#include "DiagAssert.h"
#include "Maps.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
#define MAX_VARS        100
#define a0_down         0.5      // нижняя и
#define a0_up           1.5      // верхняя границы для а0
#define e1              5e-3
#define e2              5e-3
#define e3              1.3
//---------------------------------------------------------------------------
typedef mwArray (*REGR_FUNCTION)(mwArray);
//---------------------------------------------------------------------------
//TOptimizationThread *OptThread;
TMCalculate *f;
TAnsiStringArray coeffs;
mwArray A;
int XNumber, N, Dep;
T2DoubleArray *Data;
TmwArrayArray X;
//int pX;
double *xxx;
FILE *tmp_f = NULL;
//---------------------------------------------------------------------------
int GETVARID(char *s);
mwArray GETVARVALUE(int i);
mwArray RegrFunc(mwArray beta);
mwArray nlinfit(REGR_FUNCTION func, mwArray *r_out_,mwArray *J_out_,mwArray y,mwArray beta0, double *options);
mwArray snlinfit(REGR_FUNCTION func, mwArray *r_out_,mwArray *J_out_,mwArray y,mwArray beta0, double *options);
mwArray mwVectorRank(mwArray);
mwArray sub_optim(TIntArray &X, double a0_d, double a0_u, int dep_n);
//---------------------------------------------------------------------------
#define WriteArray(A, name)                     \
{                                               \
  ofstream out(name, ios::out);                 \
  out << A << ends;                             \
  out.close();                                  \
}
//---------------------------------------------------------------------------
int GETVARID(char *s)
{
  int i;
  static TintIntMap m;

  i = MainChildGrid->A->VarByName((AnsiString)s);
  if (i == 0) {
    i = coeffs.Length + 1;
    coeffs.Length = i;
    coeffs[i - 1] = s;
    if (tmp_f) fprintf(tmp_f, "%s\t%d\n", s, (i<<1) | 1);
    return (i<<1) | 1;
  }
  else {
//    if (pX >= MAX_VARS) return UNKNOWN_VAR;
    if (m.count(i)) {
      if (tmp_f) fprintf(tmp_f, "%s\t%d\n", s, m[i] << 1);
      return m[i] << 1;
    }

    X.Length++;
    for (int j = 0; j < MainChildGrid->A->NCases; j++)
      xxx[j] = MainChildGrid->A->Cell[i][j + 1];
    X[X.Length - 1] = new mwArray(N, 1, xxx);
    m[i] = X.Length;

    if (tmp_f) fprintf(tmp_f, "%s\t%d\n", s, m[i] << 1);

    return m[i] << 1;
  }
}

mwArray GETVARVALUE(int i)
{
  switch (i&1) {
    case 0: return *(X[(i >> 1) - 1]);//(*Data)[(i>>1) - 1][XNumber - 1];//MainChildGrid->A->Cell[i>>1][XNumber];
    case 1:
      SUPERASSERT((i >> 1) <= A.Size(1)); return A(i >> 1, 1);
  }

  return 0;
}
//---------------------------------------------------------------------------
mwArray RegrFunc(mwArray beta)
{
  Application->ProcessMessages();
  A = beta;
  return f->Evaluate();
}
//---------------------------------------------------------------------------
int normal_optim(AnsiString func, int dep_n, double *options, double *result)
{
  mwArray tmp, res, res_r, res_J, Y;
  double *po = options;
  double o[20], *dres;

  if (po == NULL) {
    po = o;
    po[3] = po[4] = 1;
  }

  if (po[3])
    MainForm->CreateChildRegrMemo();

  N = MainChildGrid->A->NCases;
//  xxx = (double *)malloc(N*sizeof(double));
  xxx = new double[N];
  coeffs.Length = 0;
  Dep = dep_n;

//  pX = 0;

  for (int i = 0; i < N; i++)
    xxx[i] = MainChildGrid->A->Cell[Dep][i+1];
  Y = mwArray(N, 1, xxx);

  tmp_f = fopen("out\\func_coeff.txt", "w");
  f = new TMCalculate(func, GETVARID, GETVARVALUE);
  fclose(tmp_f);
  if (po[3]) {
    MainChildRegrMemo->SetFunction((AnsiString)MainChildGrid->A->VarName[dep_n] + " = " + func);
    MainChildRegrMemo->SetHeader(coeffs);
    MainChildRegrMemo->Repaint();
  }
  tmp = ones(coeffs.Length, 1);
/*  tmp.Write("_tmp0_.txt");
  A = tmp;
  tmp = RegrFunc();
  tmp.Write("_tmp1_.txt");
*/
//  OptThread = new TOptimizationThread(false, RegrFunc, &res, &res_r, &res_J, Y, tmp, o);
//  OptThread->WaitFor();
  res = nlinfit(RegrFunc, &res_r, &res_J, Y, tmp, po);
  if (result) res.ExtractData(result);
//  res.Write("_res_.txt");
// ShowMessage("Количество вычислений функции: " + IntToStr((int)o[0]));

  if (po[4]) {
    T2DoubleArray result1;
    TAnsiStringArray str_tmp;
    str_tmp.Length = 1;
    str_tmp[0] = "Значение";
    result1.Length = res.Size(1);
    for (int i = 0; i < result1.Length; i++) {
      result1[i].Length = 1;
      result1[i][0] = res(i + 1, 1).Double();
    }
    MainForm->CreateChildGrid(result1, coeffs, str_tmp, "Коэффициенты регрессии", 2);

    TArray *test = new TArray(NULL, res);
    test->SaveStaFile("11test11.sta");
    delete test;
  }

  if (po[3])
    MainForm->CloseChildRegrMemo();
//  delete OptThread;
//  delete xxx;
  delete[] xxx;
  delete f;

  return res.Size(1);
}
//---------------------------------------------------------------------------
mwArray nlinfit(REGR_FUNCTION func, mwArray *r_out_, mwArray *J_out_,
                mwArray y, mwArray beta0, double *options)
{
   TDoubleArray tmp_res; //Для формирования строки значений параметров в ChildRegrMemo
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
   ProgressCaption("Регрессия (ТЕСТ)");
   progress_step = 1;
   ProgressSet(0);
   ProgressShow();
   mwArray beta = ((mxArray *) NULL);
   mwArray r = ((mxArray *) NULL);
   mwArray J = ((mxArray *) NULL);

   n = length(y).Int();
   if ( tobool(min(size(y))!=1) )
   {
//      error("Requires a vector second input argument.");
     ProgressHide();
     LogAdd("!!![nlinfit]Requires a vector 'second' input argument");
     throw Sysutils::Exception("Requires a vector 'second' input argument.");
   }
   y = y(colon());
   p = length(beta0).Int();
   beta0 = beta0(colon());
   J = zeros(n, p);
   beta = beta0;
   tmp_res.Length = beta.Size(1);
   betanew = beta + 1;
   maxiter = 100;
   iter = 0;
   betatol = 1.0e-4;
   rtol = 1.0e-4;
   sse = 1;
   sseold = sse;
   while ( (tobool(norm(rdivide(betanew - beta, beta + sqrt(eps()))) > betatol) ||
            tobool(abs(sseold - sse) / (sse + sqrt(eps())) > rtol)) && tobool(iter < maxiter))
   {
      if ( /*tobool*/(iter > 0) )
      {
         beta = betanew;
      }
      iter = iter + 1;
      ProgressInc();
      for (int i = 0; i < tmp_res.Length; i++)   //Формирование строки значений
        tmp_res[i] = beta(i + 1, 1).Double();    // параметров в ChildRegrMemo
      if (options[3])
        MainChildRegrMemo->SetIteration(tmp_res);  //
//      A = beta;
//      yfit = f->Evaluate();//RegrFunc();
      yfit = (*func)(beta);
      options[0]++;
      options[5] = corrcoef(y, yfit)(1, 2).Double();
      r = y - yfit;
      sseold = ctranspose(r) * r;
      for (k = 1; k <= p; k++)
      {
//         k=_index1_k;
         delta = zeros(size(beta));
//         delta.Assign(sqrt(eps())*beta(k), k, 1);
         delta(k) = sqrt(eps()) * beta(k);
//         A = beta+delta;
//         yplus = f->Evaluate();//RegrFunc();
         yplus = (*func)(beta + delta);
         options[0]++;
//         J.Assign((yplus-yfit)/(sqrt(eps())*beta(k)), colon(), k);
         J(colon(), k) = (yplus - yfit) / (sqrt(eps()) * beta(k));
      }
      Jplus = vertcat(J, 1.0e-2 * eye(p));
      rplus = vertcat(r, zeros(p, 1));
      // % Levenberg-Marquardt type adjustment
      // % Gauss-Newton step -> J\r
      // % LM step -> inv(J'*J+constant*eye(p))*J'*r
      step = mldivide(Jplus, rplus);
      betanew = beta + step;
//      A = betanew;
//      yfitnew = f->Evaluate();//RegrFunc();
      yfitnew = (*func)(betanew);
      options[0]++;
      rnew = y - yfitnew;
      sse = ctranspose(rnew)*rnew;
      iter1 = 0;
      while ( tobool(sse > sseold) && /*tobool*/(iter1 < 12) )
      {
         step = step / sqrt(mwArray(10));
         betanew = beta + step;
//         A = betanew;
//         yfitnew = f->Evaluate();//RegrFunc();
         yfitnew = (*func)(betanew);
         options[0]++;
         rnew = y - yfitnew;
         sse = ctranspose(rnew) * rnew;
         iter1 = iter1 + 1;
      }
   }
   if ( /*tobool*/(iter == maxiter) )
   {
//      disp("NLINFIT did NOT converge. Returning results from last iteration.");
     LogAdd("[nlinfit]NLINFIT did NOT converge. Returning results from last iteration.");
   }

   // Copy local variable(s) to corresponding output variable(s).
   if (r_out_ != 0) *r_out_ = r;
   if (J_out_ != 0) *J_out_ = J;
   ProgressHide();
   return(beta);
}
//---------------------------------------------------------------------------
mwArray snlinfit(REGR_FUNCTION func, mwArray *r_out_, mwArray *J_out_,
                 mwArray y, mwArray beta0, double *options)
{
   TDoubleArray tmp_res; //Для формирования строки значений параметров в ChildRegrMemo
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
   ProgressCaption("Регрессия (ТЕСТ)");
   progress_step = 1;
   ProgressSet(0);
   ProgressShow();
   mwArray beta = ((mxArray *) NULL);
   mwArray r = ((mxArray *) NULL);
   mwArray J = ((mxArray *) NULL);

   mwArray rnk0, rnk, tmp;

   n = length(y).Int();
   if ( tobool(min(size(y)) != 1) )
   {
//      error("Requires a vector second input argument.");
     ProgressHide();
     LogAdd("!!![nlinfit]Requires a vector 'second' input argument");
     throw Sysutils::Exception("Requires a vector 'second' input argument.");
   }
   y = y(colon());
   p = length(beta0).Int();
   beta0 = beta0(colon());
   rnk0 = mwVectorRank(beta0(colon(2, p)));
   WriteArray(rnk0, "out\\rnk0.txt");
   J = zeros(n, p);
   beta = beta0;
   WriteArray(beta0, "out\\beta0.txt");
   tmp_res.Length = beta.Size(1);
   betanew = beta + 1;
   maxiter = 100;
   iter = 0;
   betatol = 1.0e-4;
   rtol = 1.0e-4;
   sse = 1;
   sseold = sse;
   while ( (tobool(norm(rdivide(betanew - beta, beta + sqrt(eps()))) > betatol) ||
            tobool(abs(sseold - sse) / (sse + sqrt(eps())) > rtol)) && tobool(iter < maxiter))
   {
      if ( /*tobool*/(iter > 0) )
      {
         beta = betanew;
      }
      iter = iter + 1;
      ProgressInc();
      for (int i = 0; i < tmp_res.Length; i++)   //Формирование строки значений
        tmp_res[i] = beta(i + 1, 1).Double();    // параметров в ChildRegrMemo
      if (options[3])
        MainChildRegrMemo->SetIteration(tmp_res);  //
//      A = beta;
//      yfit = f->Evaluate();//RegrFunc();
      WriteArray(beta, "out\\beta_y.txt");
      yfit = (*func)(beta);
      options[0]++;
      r = y - yfit;
      sseold = ctranspose(r) * r;
      for (k = 1; k <= p; k++)
      {
//         k=_index1_k;
         delta = zeros(size(beta));
//         delta.Assign(sqrt(eps())*beta(k), k, 1);
         delta(k) = sqrt(eps()) * beta(k);
//         A = beta+delta;
//         yplus = f->Evaluate();//RegrFunc();
         yplus = (*func)(beta + delta);
         options[0]++;
         J(colon(), k) = (yplus - yfit) / (sqrt(eps()) * beta(k));
//         J.Assign((yplus-yfit)/(sqrt(eps())*beta(k)), colon(), k);
      }
      Jplus = vertcat(J, 1.0e-2 * eye(p));
      rplus = vertcat(r, zeros(p, 1));
      // % Levenberg-Marquardt type adjustment
      // % Gauss-Newton step -> J\r
      // % LM step -> inv(J'*J+constant*eye(p))*J'*r
      step = mldivide(Jplus, rplus);
      betanew = beta + step;
      WriteArray(betanew, "out\\betanew0.txt");
      WriteArray(step, "out\\step0.txt");
      if (betanew(1).Double() < options[1])
        betanew(1) = options[1];
      if (betanew(1).Double() > options[2])
        betanew(1) = options[2];
      do {
        rnk = mwVectorRank((beta + step)(colon(2, p)));
        WriteArray(rnk, "out\\rnk.txt");
        tmp = abs(rnk0 - rnk);
        WriteArray(tmp, "out\\tmp.txt");
        // если ранги сильно отличаются, то уменьшить соотв. шаг вдвое
        step(colon(2, p)) = times(step(colon(2, p)),
                                  ((tmp > (p / 2)) * 0.5) + ((tmp > (p / 2)) == 0));
        WriteArray(step, "out\\step1.txt");
        // усли нек. шаг < e2, то считать его = 0
        step(colon(1, p)) = times(step(colon(1, p)), abs(step) >= e2);
        WriteArray(step, "out\\step2.txt");
      }
      while (tobool(sum(tmp > (p / 2)) > 0));
///////////////////////////////////////////////////////////////////////
      betanew = beta + step;
      WriteArray(betanew, "out\\betanew1.txt");
//      A = betanew;
//      yfitnew = f->Evaluate();//RegrFunc();
      yfitnew = (*func)(betanew);
      options[0]++;
      rnew = y - yfitnew;
      sse = ctranspose(rnew) * rnew;
      iter1 = 0;
      while ( tobool(sse > sseold) && (iter1 < 12) )
      {
         step = step / sqrt(mwArray(10));
         betanew = beta + step;
          if (betanew(1).Double() < options[1])
            betanew(1) = options[1];
          if (betanew(1).Double() > options[2])
            betanew(1) = options[2];
          do {
            rnk = mwVectorRank((beta + step)(colon(2, p)));
            WriteArray(rnk, "out\\rnk.txt");
            tmp = abs(rnk0 - rnk);
            WriteArray(tmp, "out\\tmp.txt");
            // если ранги сильно отличаются, то уменьшить соотв. шаг вдвое
            step(colon(2, p)) = times(step(colon(2, p)),
                                      ((tmp > (p / 2)) * 0.5) + ((tmp > (p / 2)) == 0));
            WriteArray(step, "out\\step1.txt");
            // усли нек. шаг < e2, то считать его = 0
            step(colon(1, p)) = times(step(colon(1, p)), abs(step) >= e2);
            WriteArray(step, "out\\step2.txt");
          }
          while (tobool(sum(tmp > (p / 2)) > 0));
//         A = betanew;
//         yfitnew = f->Evaluate();//RegrFunc();
         yfitnew = (*func)(betanew);
         options[0]++;
         rnew = y - yfitnew;
         sse = ctranspose(rnew) * rnew;
         iter1 = iter1 + 1;
      }
   }
   if ( /*tobool*/(iter == maxiter) )
   {
//      disp("NLINFIT did NOT converge. Returning results from last iteration.");
     LogAdd("[nlinfit]NLINFIT did NOT converge. Returning results from last iteration.");
   }

   // Copy local variable(s) to corresponding output variable(s).
   if (r_out_ != 0) *r_out_ = r;
   if (J_out_ != 0) *J_out_ = J;
   ProgressHide();
   return(beta);
}
//---------------------------------------------------------------------------
mwArray mwVectorRank(mwArray X)
{
  mwArray x, y;

  x = X(colon());
  y = colon(1, size(x, 1));
  VectorDualSort(x, y, SORT_ASCENDING);
  x = colon(1, size(y, 1));
  VectorDualSort(y, x, SORT_ASCENDING);

  return x;
}
//---------------------------------------------------------------------------
mwArray sub_optim(TIntArray &iX, double a0_d, double a0_u, int dep_n)
{
  AnsiString func;
  TDoubleArray dY;
  mwArray a, r;
  mwArray res, res_r, res_J, Y;
  double o[20], *dres;
  double al[10]; // 10 - на всякий случай :)
  double *al0;
  int p = 0;
  int i;

  N = MainChildGrid->A->NCases;
  xxx = new double[N];
  coeffs.Length = 0;

//  pX = 0;

  for (int i = 0; i < N; i++)
    xxx[i] = MainChildGrid->A->Cell[dep_n][i+1];
  Y = mwArray(N, 1, xxx);
  delete[] xxx;

  al0 = new double[iX.Length + 1];
  dY = MainChildGrid->A->GetVar(dep_n);
  o[3] = o[4] = 0;
  try {
    al0[0] = 1; p++;
    for (i = 0; i < iX.Length; i++) {
      normal_optim((AnsiString)MainChildGrid->A->VarName[iX[i]] + "^A1", dep_n, o, al);
      if (fabs(al[0]) <= e1 ||
          al[0]*Correlation(MainChildGrid->A->GetVar(iX[i]), dY) <= e1)
        DeleteElement(iX, i--);
      else
        al0[p++] = al[0];
    }

    if (p == 1)  // только а0 (все иксы ушли)
      return mwArray();
    a = mwArray(p, 1, al0);
    if (p == 2)  // остался только один из иксов и а0
      return a;

////////////
    o[1] = a0_d;
    o[2] = a0_u;
    o[3] = 0;
    o[4] = 1;
    if (o[3])
      MainForm->CreateChildRegrMemo();
    N = MainChildGrid->A->NCases;
    xxx = new double[N];
    coeffs.Length = 0;
//    pX = 0;
//    func = (AnsiString)MainChildGrid->A->VarName[dep_n] + " = a0";
    func = "a0";
    for (i = 0; i < iX.Length; i++)
      func += " * (" + (AnsiString)MainChildGrid->A->VarName[iX[i]] +
                       " ^ a" + IntToStr(iX[i]) + ")";
    tmp_f = fopen("out\\func_coeff.txt", "w");
    f = new TMCalculate(func.UpperCase(), GETVARID, GETVARVALUE);
    fclose(tmp_f);
    f->Print("out\\func_tree.txt");
    res = snlinfit(RegrFunc, &res_r, &res_J, Y, a, o);

    if (o[4]) {
      T2DoubleArray result1;
      TAnsiStringArray str_tmp;
      str_tmp.Length = 1;
      str_tmp[0] = "Значение";
      result1.Length = res.Size(1);
      for (int i = 0; i < result1.Length; i++) {
        result1[i].Length = 1;
        result1[i][0] = res(i + 1, 1).Double();
      }
      MainForm->CreateChildGrid(result1, coeffs, str_tmp, "Коэффициенты регрессии", 2);
    }

    if (o[3])
      MainForm->CloseChildRegrMemo();

    return res;
  }
  __finally {
    delete[] al0;
    delete[] xxx;
    delete f;
  }
}
//---------------------------------------------------------------------------
T2DoubleArray simpleoptim(TArray *A, T2IntArray X, int dep_n, double &corr, bool isMultiply)
{
  int i, j, p;
  double *result;
  double options[20] = {0, 0, 0, 1, 0,
                        0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0};
  AnsiString func;
  T2DoubleArray res;

  if (isMultiply) {
    func = "a0";
    p = 1;
    for (i = 0; i < X.Length; i++) {
      func += " * (" + AnsiString(A->VarName[X[i][0]]) + " ^ (a" + IntToStr(p++);
      for (j = 1; j < X[i].Length; j++) {
        func += " + a" + IntToStr(p++) + "*" + A->VarName[X[i][j]];
      }
      func += "))";
    }
  }
  else {
    func = "a0";
    p = 1;
    for (i = 0; i < X.Length; i++)
      func += " + (" + AnsiString(A->VarName[X[i][0]]) + " * a" + IntToStr(p++) + ")";
  }

  result = new double[p];

  __try {
    normal_optim(func, dep_n, options, result);

    p = 1;
    res.Length = X.Length;
    if (isMultiply) {
      for (i = 0; i < X.Length; i++) {
        res[i].Length = X[i].Length;
        for (j = 0; j < X[i].Length; j++)
          res[i][j] = result[p++];
      }
    }
    else {
      for (i = 0; i < X.Length; i++) {
        res[i].Length = 1;
        res[i][0] = result[p++];
      }
    }

    corr = options[5];

    return res;
  }
  __finally {
    delete[] result;
  }
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
#ifndef OptimizationH
#define OptimizationH

#include "GridArray.h"
#include "DArrayTypes.h"
#include "MatMath\matlab.hpp"
//---------------------------------------------------------------------------
int normal_optim(AnsiString func, int dep_n, double *options, double *result);
mwArray sub_optim(TIntArray &X, double a0_d, double a0_u, int dep_n);
T2DoubleArray simpleoptim(TArray *A, T2IntArray X, int dep_n, double &corr,
                          bool isMultiply = true);
//---------------------------------------------------------------------------
#endif

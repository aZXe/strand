//---------------------------------------------------------------------------
#ifndef MatrixFunctionsH
#define MatrixFunctionsH

#include "DArrayTypes.h"
#include "GridArray.h"
#include "Logging.h"
#include "MatMath\matlab.hpp"

#define SORT_DESCENDING         0
#define SORT_ASCENDING          1

#define RANK_FIRST      0
#define RANK_LAST       1
#define RANK_MEAN       2

void VectorSort (TDoubleArray &, int const);
void VectorDualSort (TDoubleArray &, TDoubleArray &, int const);
void VectorSort (mwArray &, int const);
void VectorDualSort (mwArray &, mwArray &, int const);
void VectorRank(TDoubleArray &, int const, int const);
double VectorSum(TDoubleArray &A, long No, long N);
void CorrelationMatrix(TDoubleArray &Corr, TArray &A, TIntArray &Nums);
double Correlation(TDoubleArray &X, TDoubleArray &Y);
//---------------------------------------------------------------------------
#endif

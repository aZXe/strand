//---------------------------------------------------------------------------
#ifndef MatrixFunctionsH
#define MatrixFunctionsH

#include "DArrayTypes.h"
#include "GridArray.h"

#define SORT_DESCENDING         0
#define SORT_ASCENDING          1

#define RANK_FIRST      0
#define RANK_LAST       1
#define RANK_MEAN       2

void VectorSort (TDoubleArray &, int const);
void VectorDualSort (TDoubleArray &, TDoubleArray &, int const);
void VectorRank(TDoubleArray &, int const, int const);
double VectorSum(TDoubleArray &A, long No, long N);
double VectorMin(TDoubleArray &A);
void CorrelationMatrix(TDoubleArray &Corr, TArray &A, TIntArray &Nums);
void Log(TDoubleArray &A, double eps = 1e-10);
void Exp(TDoubleArray &A);
//---------------------------------------------------------------------------
#endif

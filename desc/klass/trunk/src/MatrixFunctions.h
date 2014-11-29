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

#define matrix_functions_prototypes1(type, Type)                        \
void VectorSort(T##Type##Array &A, int const);                          \
void VectorRank(T##Type##Array &A, int const, int const);               \
type VectorSum(T##Type##Array &A, long No, long N);                     \
type VectorMin(T##Type##Array &A, int *ind = NULL);                     \
type VectorMax(T##Type##Array &A, int *ind = NULL);                     \
void VectorSet(T##Type##Array &A, type value);

#define matrix_functions_prototypes2(type, Type1, Type2)                \
void VectorDualSort (T##Type1##Array &, T##Type1##Array &, int const);

matrix_functions_prototypes1(double, Double)
matrix_functions_prototypes1(long,   Long  )
matrix_functions_prototypes1(char,   Char  )
matrix_functions_prototypes1(int,    Int   )
matrix_functions_prototypes2(double, Double, Double)
matrix_functions_prototypes2(double, Double, Long  )
matrix_functions_prototypes2(double, Double, int   )

void CorrelationMatrix(TDoubleArray &Corr, TArray &A, TIntArray &Nums);
void Log(TDoubleArray &A, double eps = 1e-10);
void Exp(TDoubleArray &A);
//---------------------------------------------------------------------------
#endif

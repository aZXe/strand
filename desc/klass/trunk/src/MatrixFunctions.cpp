//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <stdlib.h>
#include <math.h>
#include "MatrixFunctions.h"
//---------------------------------------------------------------------
#define matrix_functions_defines2(type1, Type1, type2, Type2)                               \
void QuickDualSortA(T##Type1##Array &A, T##Type2##Array &B, long const AHigh, long iLo, long iHi) \
{                                                                                           \
  long Lo, Hi;                                                                              \
  type1 T1, Mid;                                                                            \
  type2 T2;                                                                                 \
                                                                                            \
  Lo = iLo;                                                                                 \
  Hi = iHi;                                                                                 \
  Mid = A[(Lo+Hi)/2];                                                                       \
                                                                                            \
  do                                                                                        \
  {                                                                                         \
    while (A[Lo] < Mid) Lo++;                                                               \
    while (A[Hi] > Mid) Hi--;                                                               \
    if (Lo <= Hi)                                                                           \
    {                                                                                       \
      T1 = A[Lo];                                                                           \
      A[Lo] = A[Hi];                                                                        \
      A[Hi] = T1;                                                                           \
                                                                                            \
      T2 = B[Lo];                                                                           \
      B[Lo] = B[Hi];                                                                        \
      B[Hi] = T2;                                                                           \
                                                                                            \
      Lo++;                                                                                 \
      Hi--;                                                                                 \
    }                                                                                       \
  }                                                                                         \
  while (Lo <= Hi);                                                                         \
                                                                                            \
  if (Hi > iLo)                                                                             \
    QuickDualSortA(A, B, AHigh, iLo, Hi);                                                   \
  if (Lo < iHi)                                                                             \
    QuickDualSortA(A, B, AHigh, Lo, iHi);                                                   \
}                                                                                           \
/*---------------------------------------------------------------------*/                   \
void QuickDualSortD(T##Type1##Array &A, T##Type2##Array &B, long const AHigh, long iLo, long iHi) \
{                                                                                           \
  long Lo, Hi;                                                                              \
  type1 T1, Mid;                                                                            \
  type2 T2;                                                                                 \
                                                                                            \
  Lo = iLo;                                                                                 \
  Hi = iHi;                                                                                 \
  Mid = A[(Lo+Hi)/2];                                                                       \
                                                                                            \
  do                                                                                        \
  {                                                                                         \
    while (A[Lo] > Mid) Lo++;                                                               \
    while (A[Hi] < Mid) Hi--;                                                               \
    if (Lo <= Hi)                                                                           \
    {                                                                                       \
      T1 = A[Lo];                                                                           \
      A[Lo] = A[Hi];                                                                        \
      A[Hi] = T1;                                                                           \
                                                                                            \
      T2 = B[Lo];                                                                           \
      B[Lo] = B[Hi];                                                                        \
      B[Hi] = T2;                                                                           \
                                                                                            \
      Lo++;                                                                                 \
      Hi--;                                                                                 \
    }                                                                                       \
  }                                                                                         \
  while (Lo <= Hi);                                                                         \
                                                                                            \
  if (Hi > iLo)                                                                             \
    QuickDualSortD(A, B, AHigh, iLo, Hi);                                                   \
  if (Lo < iHi)                                                                             \
    QuickDualSortD(A, B, AHigh, Lo, iHi);                                                   \
}                                                                                           \
/*---------------------------------------------------------------------*/                   \
void VectorDualSort(T##Type1##Array &A, T##Type2##Array &B, int const Direction)            \
{                                                                                           \
  if (Direction == SORT_ASCENDING) QuickDualSortA(A, B, A.Length - 1, 0, A.Length - 1);     \
  else  QuickDualSortD(A, B, A.Length - 1, 0, A.Length - 1);                                \
}                                                                                           
//---------------------------------------------------------------------
#define matrix_functions_defines1(type, Type)                                               \
void QuickSortA(T##Type##Array &A, long const AHigh, long iLo, long iHi)                    \
{                                                                                           \
  long Lo, Hi;                                                                              \
  type T, Mid;                                                                              \
                                                                                            \
  Lo = iLo;                                                                                 \
  Hi = iHi;                                                                                 \
  Mid = A[(Lo+Hi)/2];                                                                       \
                                                                                            \
  do                                                                                        \
  {                                                                                         \
    while (A[Lo] < Mid) Lo++;                                                               \
    while (A[Hi] > Mid) Hi--;                                                               \
    if (Lo <= Hi)                                                                           \
    {                                                                                       \
      T = A[Lo];                                                                            \
      A[Lo] = A[Hi];                                                                        \
      A[Hi] = T;                                                                            \
                                                                                            \
      Lo++;                                                                                 \
      Hi--;                                                                                 \
    }                                                                                       \
  }                                                                                         \
  while (Lo <= Hi);                                                                         \
                                                                                            \
  if (Hi > iLo)                                                                             \
    QuickSortA(A, AHigh, iLo, Hi);                                                          \
  if (Lo < iHi)                                                                             \
    QuickSortA(A, AHigh, Lo, iHi);                                                          \
}                                                                                           \
/*---------------------------------------------------------------------*/                   \
void QuickSortD(T##Type##Array &A, long const AHigh, long iLo, long iHi)                    \
{                                                                                           \
  long Lo, Hi;                                                                              \
  type T, Mid;                                                                              \
                                                                                            \
  Lo = iLo;                                                                                 \
  Hi = iHi;                                                                                 \
  Mid = A[(Lo+Hi)/2];                                                                       \
                                                                                            \
  do                                                                                        \
  {                                                                                         \
    while (A[Lo] > Mid) Lo++;                                                               \
    while (A[Hi] < Mid) Hi--;                                                               \
    if (Lo <= Hi)                                                                           \
    {                                                                                       \
      T = A[Lo];                                                                            \
      A[Lo] = A[Hi];                                                                        \
      A[Hi] = T;                                                                            \
                                                                                            \
      Lo++;                                                                                 \
      Hi--;                                                                                 \
    }                                                                                       \
  }                                                                                         \
  while (Lo <= Hi);                                                                         \
                                                                                            \
  if (Hi > iLo)                                                                             \
    QuickSortD(A, AHigh, iLo, Hi);                                                          \
  if (Lo < iHi)                                                                             \
    QuickSortD(A, AHigh, Lo, iHi);                                                          \
}                                                                                           \
/*---------------------------------------------------------------------*/                   \
void VectorSort(T##Type##Array &A, int const Direction)                                     \
{                                                                                           \
  if (Direction == SORT_ASCENDING) QuickSortA(A, A.Length - 1, 0, A.Length - 1);            \
  else  QuickSortD(A, A.Length - 1, 0, A.Length - 1);                                       \
}                                                                                           \
/*---------------------------------------------------------------------*/                   \
void VectorRank(T##Type##Array &A, int const Direction, int const DupControl)               \
{                                                                                           \
  int i, j, k;                                                                              \
  type r;                                                                                   \
                                                                                            \
  VectorSort(A, Direction);                                                                 \
                                                                                            \
  for (i = 0; i < A.Length; i++) {                                                          \
    for (j = i; j < A.Length; j++)                                                          \
      if (j == A.Length - 1 && A[j] == A[j - 1]) {                                          \
        j = A.Length;                                                                       \
        break;                                                                              \
      }                                                                                     \
      else if (A[j] != A[i]) break;                                                         \
    if (j == i + 1) A[i] = i + 1;                                                           \
    else {                                                                                  \
      switch (DupControl) {                                                                 \
        case RANK_FIRST : r = i + 1; break;                                                 \
        case RANK_LAST  : r = j;     break;                                                 \
        case RANK_MEAN  : for (r = 0, k = i; k < j; r += k + 1, k++); r /= j - i;           \
      }                                                                                     \
      for (k = i; k < j; k++) A[k] = r;                                                     \
      i = j - 1;                                                                            \
    }                                                                                       \
  }                                                                                         \
}                                                                                           \
/*---------------------------------------------------------------------*/                   \
type VectorSum(T##Type##Array &A, long No, long N)                                          \
{                                                                                           \
  type s = 0;                                                                               \
  for (long i = No; i < No + N; i++) s += A[i];                                             \
                                                                                            \
  return s;                                                                                 \
}                                                                                           \
/*---------------------------------------------------------------------*/                   \
type VectorMin(T##Type##Array &A, int *ind)                                                 \
{                                                                                           \
  type Amin = MAXDOUBLE;                                                                    \
  long N = A.Length;                                                                        \
                                                                                            \
  for (long i = 0; i < N; i++)                                                              \
    if (A[i] < Amin) {                                                                      \
      Amin = A[i];                                                                          \
      if (ind) *ind = i;                                                                    \
    }                                                                                       \
                                                                                            \
  return Amin;                                                                              \
}                                                                                           \
/*---------------------------------------------------------------------*/                   \
type VectorMax(T##Type##Array &A, int *ind)                                                 \
{                                                                                           \
  type Amax = MINDOUBLE;                                                                    \
  long N = A.Length;                                                                        \
                                                                                            \
  for (long i = 0; i < N; i++)                                                              \
    if (A[i] > Amax) {                                                                      \
      Amax = A[i];                                                                          \
      if (ind) *ind = i;                                                                    \
    }                                                                                       \
                                                                                            \
  return Amax;                                                                              \
}                                                                                           \
/*---------------------------------------------------------------------*/                   \
void VectorSet(T##Type##Array &A, type value)                                               \
{                                                                                           \
  long N = A.Length;                                                                        \
                                                                                            \
  for (long i = 0; i < N; i++)                                                              \
    A[i] = value;                                                                           \
}                                                                                           
//---------------------------------------------------------------------
matrix_functions_defines1(double, Double)
matrix_functions_defines1(long,   Long  )
matrix_functions_defines1(char,   Char  )
matrix_functions_defines1(int,    Int   )
matrix_functions_defines2(double, Double, double, Double)
matrix_functions_defines2(double, Double, long,   Long  )
matrix_functions_defines2(double, Double, int,    Int   )
//---------------------------------------------------------------------
void CorrelationMatrix(T2DoubleArray &Corr, TArray &A, TIntArray &Nums)
{
  int nv = Nums.Length, i, k, ii, kk;
  long nc = A.NCases, j;
  double sx, sy, x, y, sxy, c;

  Corr.Length = nv;
  for (i = 0; i < nv; i++)
    Corr[i].Length = nv;

  for (i = 0; i < nv; i++)
    for (k = 0; k < nv; k++) {
      ii = Nums[i];
      kk = Nums[k];
      x = 0;
      y = 0;
      c = 0;
      for (j = 0; j < nc; j++)
        if (A.Cell[ii][j] != MISSING_DATA && A.Cell[kk][j] != MISSING_DATA) {
          x += A.Cell[ii][j];
          y += A.Cell[kk][j];
          c++;
        }
      x /= c;
      y /= c;

      sx = 0;
      sy = 0;
      sxy = 0;
      for (j = 0; j < nc; j++)
        if (A.Cell[ii][j] != MISSING_DATA && A.Cell[kk][j] != MISSING_DATA) {
          sx += (A.Cell[ii][j] - x) * (A.Cell[ii][j] - x);
          sy += (A.Cell[kk][j] - y) * (A.Cell[kk][j] - y);
          sxy += (A.Cell[ii][j] - x)*(A.Cell[kk][j] - y);
        }
      Corr[i][j] = Corr[k][i] = sxy / sqrt(sx * sy); 
    }
}
//---------------------------------------------------------------------
void Log(TDoubleArray &A, double eps)
{
  for (int i = 0; i < A.Length; i++)
    if (A[i] > eps) A[i] = log(A[i]);
    else A[i] = log(eps);
}
//---------------------------------------------------------------------
void Exp(TDoubleArray &A)
{
  for (int i = 0; i < A.Length; i++)
    A[i] = exp(A[i]);
}
//---------------------------------------------------------------------
#pragma package(smart_init)

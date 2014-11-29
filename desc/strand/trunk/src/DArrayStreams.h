//---------------------------------------------------------------------------
#ifndef DArrayStreamsH
#define DArrayStreamsH

#include "DArrayTypes.h"
#include <fstream>
//---------------------------------------------------------------------------
#define DynamicArray1DStreamsOperators(Type)                    \
ostream& operator <<(ostream& out, T##Type##Array &A)           \
{                                                               \
  int i;                                                        \
                                                                \
  out << fixed;                                                 \
                                                                \
  for (i = 0; i < A.Length; i++)                                \
    out << A[i] << " ";                                         \
                                                                \
  return out;                                                   \
}

DynamicArray1DStreamsOperators(Int)
DynamicArray1DStreamsOperators(Double)

#define DynamicArray2DStreamsOperators(Type)                    \
ostream& operator <<(ostream& out, T2##Type##Array &A)          \
{                                                               \
  int i, j;                                                     \
                                                                \
  out << fixed << endl;                                         \
                                                                \
  for (i = 0; i < A.Length; i++) {                              \
    out << "\t";                                                \
    for (j = 0; j < A[i].Length; j++)                           \
      out << A[i][j] << " ";                                    \
    out << endl;                                                \
  }                                                             \
                                                                \
  return out;                                                   \
}

DynamicArray2DStreamsOperators(Int)
DynamicArray2DStreamsOperators(Double)
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------
#ifndef DArrayTypesH
#define DArrayTypesH

#include <sysdyn.h>
#include <stdlib.h>
#include <mem.h>
#include "MatMath\matlab.hpp"

typedef System::DynamicArray < System::DynamicArray < double > > T2DoubleArray;
typedef System::DynamicArray < double > TDoubleArray;
typedef DynamicArray < long > TLongArray;
typedef DynamicArray < DynamicArray < int > > T2IntArray;
typedef DynamicArray < int > TIntArray;
typedef DynamicArray < char > TCharArray;
typedef DynamicArray < AnsiString > TAnsiStringArray;

typedef DynamicArray < mwArray* > TmwArrayArray;

#define DynamicArray1DProcedures(Type, type)                    \
void AddElement(T##Type##Array &A, type x);                     \
void AddElement(T##Type##Array &A, type x)                      \
{                                                               \
  int i = A.Length;                                             \
  A.Length = i+1;                                               \
  A[i] = x;                                                     \
}                                                               \
type MinElement(T##Type##Array A);                              \
type MinElement(T##Type##Array A)                               \
{                                                               \
  int i = A.Length, j;                                          \
  type t;                                                       \
  if (!i) {                                                     \
    setmem(&t, sizeof(type), 0xff);                             \
    return t;                                                   \
  }                                                             \
  t = A[0];                                                     \
  for(j = 1; j < i; j++)                                        \
    if (A[j] < t) t = A[j];                                     \
  return t;                                                     \
}                                                               \
type MaxElement(T##Type##Array A);                              \
type MaxElement(T##Type##Array A)                               \
{                                                               \
  int i = A.Length, j;                                          \
  type t;                                                       \
  if (!i) {                                                     \
    setmem(&t, sizeof(type), 0xff);                             \
    return t;                                                   \
  }                                                             \
  t = A[0];                                                     \
  for(j = 1; j < i; j++)                                        \
    if (A[j] > t) t = A[j];                                     \
  return t;                                                     \
}                                                               \
void DeleteElement(T##Type##Array &A, int n);                   \
void DeleteElement(T##Type##Array &A, int n)                    \
{                                                               \
  int i = A.Length, j;                                          \
  if (i == 0 || n >= i || n < 0)                                \
    return;                                                     \
                                                                \
  for(j = n; j < i - 1; j++)                                    \
    A[j] = A[j + 1];                                            \
  A.Length = i - 1;                                             \
}

DynamicArray1DProcedures(Int, int)
DynamicArray1DProcedures(Double, double)

#define ADDELEMENT(A, x)                        \
{                                               \
  int i = (A).Length;                           \
  (A).Length = i+1;                             \
  (A)[i] = (x);                                 \
}

#define CLEAR(A)                                \
{                                               \
  (A).Length = 0;                               \
}
//---------------------------------------------------------------------------
#endif

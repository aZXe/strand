//---------------------------------------------------------------------------
#ifndef DArrayTypesH
#define DArrayTypesH

#include <fstream>
#include <sysdyn>
#include <stdlib>
#include <mem>

using namespace std;

typedef DynamicArray < DynamicArray < double > > T2DoubleArray;
typedef DynamicArray < double > TDoubleArray;
typedef DynamicArray < DynamicArray < long   > > T2LongArray;
typedef DynamicArray < long   > TLongArray;
typedef DynamicArray < DynamicArray < int    > > T2IntArray;
typedef DynamicArray < int    > TIntArray;
typedef DynamicArray < DynamicArray < char   > > T2CharArray;
typedef DynamicArray < char   > TCharArray;
typedef DynamicArray < AnsiString > TAnsiStringArray;

#define DynamicArray1DProcedures(Type, type) \
void AddElement(T##Type##Array A, type x); \
void AddElement(T##Type##Array A, type x) \
{ \
  int i = A.Length;\
  A.Length = i+1;\
  A[i] = x;\
} \
type MinElement(T##Type##Array A); \
type MinElement(T##Type##Array A) \
{ \
  int i = A.Length, j;\
  type t;\
  if (!i) {\
    setmem(&t, sizeof(type), 0xff);\
    return t;\
  }\
  t = A[0];\
  for(j = 1; j < i; j++)\
    if (A[j] < t) t = A[j];\
  return t;\
} \
type MaxElement(T##Type##Array A); \
type MaxElement(T##Type##Array A) \
{ \
  int i = A.Length, j;\
  type t;\
  if (!i) {\
    setmem(&t, sizeof(type), 0xff);\
    return t;\
  }\
  t = A[0];\
  for(j = 1; j < i; j++)\
    if (A[j] > t) t = A[j];\
  return t;\
} \
void FillOrder(T##Type##Array A, type begin = 0); \
void FillOrder(T##Type##Array A, type begin) \
{ \
  int i, N = A.Length;\
  for (i = 0; i < N; i++) \
    A[i] = begin + i; \
} \
void SwapElements(T##Type##Array A, type i, type j); \
void SwapElements(T##Type##Array A, type i, type j) \
{ \
  type t = A[i];\
  A[i] = A[j]; \
  A[j] = t; \
}

DynamicArray1DProcedures(Int, int)
DynamicArray1DProcedures(Double, double)

#define ADDELEMENT(A, x) \
{ \
  int i = (A).Length;\
  (A).Length = i+1;\
  (A)[i] = (x);\
}

#define CLEAR(A) \
{ \
  (A).Length = 0;\
}
//---------------------------------------------------------------------------
#define define_WriteArray(type, Type)                           \
void WriteArray(T##Type##Array &A, AnsiString name)             \
{                                                               \
  long i;                                                       \
  ofstream f(name.c_str());                                     \
                                                                \
  if (A.Length == 0)                                            \
    f << "Empty...";                                            \
  else                                                          \
    for (i = 0; i < A.Length; i++)                              \
      f << i << "\t" << A[i] << endl;                           \
}                                                               \
                                                                \
void WriteArray(T##Type##Array &A, ofstream &f)                 \
{                                                               \
  long i;                                                       \
                                                                \
  if (A.Length == 0)                                            \
    f << "Empty...";                                            \
  else                                                          \
    for (i = 0; i < A.Length; i++)                              \
      f << i << "\t" << A[i] << endl;                           \
}                                                               \
                                                                \
void WriteArray(T2##Type##Array &A, AnsiString name)            \
{                                                               \
  long i, j;                                                    \
  ofstream f(name.c_str());                                     \
                                                                \
  if (A.Length == 0)                                            \
    f << "Empty...";                                            \
  else {                                                        \
    for (j = 0; j < A[0].Length; j++)                           \
      f << "\t" << j;                                           \
    f << endl;                                                  \
    for (i = 0; i < A.Length; i++) {                            \
      f << i;                                                   \
      for (j = 0; j < A[i].Length; j++)                         \
        f << "\t" << A[i][j];                                   \
      f << endl;                                                \
    }                                                           \
  }                                                             \
}                                                               \
                                                                \
void WriteArray(T2##Type##Array &A, ofstream &f)                \
{                                                               \
  long i, j;                                                    \
                                                                \
  if (A.Length == 0)                                            \
    f << "Empty...";                                            \
  else {                                                        \
    for (j = 0; j < A[0].Length; j++)                           \
      f << "\t" << j;                                           \
    f << endl;                                                  \
    for (i = 0; i < A.Length; i++) {                            \
      f << i;                                                   \
      for (j = 0; j < A[i].Length; j++)                         \
        f << "\t" << A[i][j];                                   \
      f << endl;                                                \
    }                                                           \
  }                                                             \
}
define_WriteArray(int,    Int   )
define_WriteArray(double, Double)
define_WriteArray(char,   Char  )
define_WriteArray(long,   Long  )
//---------------------------------------------------------------------------
#endif

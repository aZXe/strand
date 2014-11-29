//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <stdlib.h>
#include <math.h>
#include "MatrixFunctions.h"
//---------------------------------------------------------------------
void QuickSortA(TDoubleArray &A, long const AHigh, long iLo, long iHi)
{
  long Lo, Hi;
  double T, Mid;

  Lo = iLo;
  Hi = iHi;
  Mid = A[(Lo+Hi)/2];

  do
  {
    while (A[Lo] < Mid) Lo++;
    while (A[Hi] > Mid) Hi--;
    if (Lo <= Hi)
    {
      T = A[Lo];
      A[Lo] = A[Hi];
      A[Hi] = T;

      Lo++;
      Hi--;
    }
  }
  while (Lo <= Hi);

  if (Hi > iLo)
    QuickSortA(A, AHigh, iLo, Hi);
  if (Lo < iHi)
    QuickSortA(A, AHigh, Lo, iHi);
}
//---------------------------------------------------------------------
void QuickSortD(TDoubleArray &A, long const AHigh, long iLo, long iHi)
{
  long Lo, Hi;
  double T, Mid;

  Lo = iLo;
  Hi = iHi;
  Mid = A[(Lo+Hi)/2];

  do
  {
    while (A[Lo] > Mid) Lo++;
    while (A[Hi] < Mid) Hi--;
    if (Lo <= Hi)
    {
      T = A[Lo];
      A[Lo] = A[Hi];
      A[Hi] = T;

      Lo++;
      Hi--;
    }
  }
  while (Lo <= Hi);

  if (Hi > iLo)
    QuickSortD(A, AHigh, iLo, Hi);
  if (Lo < iHi)
    QuickSortD(A, AHigh, Lo, iHi);
}
//---------------------------------------------------------------------
void VectorSort(TDoubleArray &A, int const Direction)
{
  if (Direction == SORT_ASCENDING) QuickSortA(A, A.Length - 1, 0, A.Length - 1);
  else  QuickSortD(A, A.Length - 1, 0, A.Length - 1);
}
//---------------------------------------------------------------------
void QuickDualSortA(TDoubleArray &A, TDoubleArray &B, long const AHigh, long iLo, long iHi)
{
  long Lo, Hi;
  double T, Mid;

  Lo = iLo;
  Hi = iHi;
  Mid = A[(Lo+Hi)/2];

  do
  {
    while (A[Lo] < Mid) Lo++;
    while (A[Hi] > Mid) Hi--;
    if (Lo <= Hi)
    {
      T = A[Lo];
      A[Lo] = A[Hi];
      A[Hi] = T;

      T = B[Lo];
      B[Lo] = B[Hi];
      B[Hi] = T;

      Lo++;
      Hi--;
    }
  }
  while (Lo <= Hi);

  if (Hi > iLo)
    QuickDualSortA(A, B, AHigh, iLo, Hi);
  if (Lo < iHi)
    QuickDualSortA(A, B, AHigh, Lo, iHi);
}
//---------------------------------------------------------------------
void QuickDualSortD(TDoubleArray &A, TDoubleArray &B, long const AHigh, long iLo, long iHi)
{
  long Lo, Hi;
  double T, Mid;

  Lo = iLo;
  Hi = iHi;
  Mid = A[(Lo+Hi)/2];

  do
  {
    while (A[Lo] > Mid) Lo++;
    while (A[Hi] < Mid) Hi--;
    if (Lo <= Hi)
    {
      T = A[Lo];
      A[Lo] = A[Hi];
      A[Hi] = T;

      T = B[Lo];
      B[Lo] = B[Hi];
      B[Hi] = T;

      Lo++;
      Hi--;
    }
  }
  while (Lo <= Hi);

  if (Hi > iLo)
    QuickDualSortD(A, B, AHigh, iLo, Hi);
  if (Lo < iHi)
    QuickDualSortD(A, B, AHigh, Lo, iHi);
}
//---------------------------------------------------------------------
void VectorDualSort(TDoubleArray &A, TDoubleArray &B, int const Direction)
{
  if (Direction == SORT_ASCENDING) QuickDualSortA(A, B, A.Length - 1, 0, A.Length - 1);
  else  QuickDualSortD(A, B, A.Length - 1, 0, A.Length - 1);
}
//---------------------------------------------------------------------
void VectorRank(TDoubleArray &A, int const Direction, int const DupControl)
{
  int i, j, k;
  double r;

  VectorSort(A, Direction);

  for (i = 0; i < A.Length; i++) {
    for (j = i; j < A.Length; j++)
      if (j == A.Length - 1 && A[j] == A[j - 1]) {
        j = A.Length;
        break;
      }
      else if (A[j] != A[i]) break;
    if (j == i + 1) A[i] = i + 1;
    else {
      switch (DupControl) {
        case RANK_FIRST : r = i + 1; break;
        case RANK_LAST  : r = j;     break;
        case RANK_MEAN  : for (r = 0, k = i; k < j; r += k + 1, k++); r /= j - i;
      }
      for (k = i; k < j; k++) A[k] = r;
      i = j - 1;
    }
  }
}
//---------------------------------------------------------------------
double VectorSum(TDoubleArray &A, long No, long N)
{
  double s = 0;
  for (long i = No; i < No + N; i++) s += A[i];

  return s;
}
//---------------------------------------------------------------------
double VectorMin(TDoubleArray &A)
{
  double Amin = MAXDOUBLE;
  long N = A.Length;

  for (long i = 0; i < N; i++)
    if (A[i] < Amin) Amin = A[i];

  return Amin;
}
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

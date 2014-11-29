//---------------------------------------------------------------------------
#ifndef ClassificationH
#define ClassificationH
//---------------------------------------------------------------------------
#include "Sets.h"
#include "Maps.h"
//---------------------------------------------------------------------------
double metrica(TDoubleArray &X, TDoubleArray &Y, bool isMayBeNull = true);
void CalcDistances(T2DoubleArray &A, T2DoubleArray &R, int count_vars = -1);
void Classification(T2DoubleArray &A, TintIntSetMap &Classes, TIntArray &IK, int k, int count_vars = -1);
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------
#ifndef DistributionsH
#define DistributionsH

#include <math.h>
//---------------------------------------------------------------------------
double dNormal   (double x, double m, double s);
double dNormal01 (double x);
double iNormal (double x, double m, double s);
double vNormal (double p, double m, double s);
double dLogNormal (double x, double m, double s);
//---------------------------------------------------------------------------
#endif

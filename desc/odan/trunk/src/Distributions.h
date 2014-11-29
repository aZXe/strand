//---------------------------------------------------------------------------
#ifndef DistributionsH
#define DistributionsH

#include <math.h>
//---------------------------------------------------------------------------
double dNormal  (double x, double m, double s);
double dNormal01(double x);
double iNormal(double x, double m, double s);
double vNormal(double p, double m, double s);
double dLogNormal(double x, double m, double s);
double dLogNormal1(double x, double m, double s);
double vStudent(double p, double v);
double dSmes(double x, double m1, double s1, double m2, double s2, double q1,
             bool isNormal1 = true, bool isNormal2 = true);
double iSmes(double x, double m1, double s1, double m2, double s2, double q1,
             bool isNormal1 = true, bool isNormal2 = true);
double vSmes(double p, double m1, double s1, double m2, double s2, double q1,
             bool isNormal1, bool isNormal2);
//---------------------------------------------------------------------------
#endif

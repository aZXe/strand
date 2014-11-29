//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Distributions.h"
//---------------------------------------------------------------------------
#define A0 2.515517
#define A1 0.802853
#define A2 0.010328
#define B1 1.432788
#define B2 0.189269
#define B3 0.001308

#define C1 0.196854
#define C2 0.115194
#define C3 0.000344
#define C4 0.019527

#define P   0.2316419
#define D1  0.319381530
#define D2 -0.356563782
#define D3  1.781477937
#define D4 -1.821255978
#define D5  1.330274429
//---------------------------------------------------------------------------
double dNormal (double x, double m, double s)
{
  return exp(- (x - m) * (x - m) / (2 * s * s)) / (s * sqrt(2 * M_PI));
}
//---------------------------------------------------------------------------
double dNormal01 (double x)
{
  return exp(- x * x / 2) / sqrt(2 * M_PI);
}
//---------------------------------------------------------------------------
double iNormal (double x, double m, double s)
{
  double xx = (x - m) / s, t, AA2;

  if (xx < 0) {
    xx = -xx;
    t = 1 / (1 + P * xx);
    AA2 = dNormal01(xx) * (D1*t + D2*t*t + D3*t*t*t + D4*t*t*t*t + D5*t*t*t*t*t);
  } else {
      t = 1 / (1 + P * xx);
      AA2 = 1 - dNormal01(xx) * (D1*t + D2*t*t + D3*t*t*t + D4*t*t*t*t + D5*t*t*t*t*t);
    }

  return AA2;
}
//---------------------------------------------------------------------------
double vNormal (double p, double m, double s)
{
  int Sgn = 1;
  double AA = p, t;

  if (AA >= 0 && AA < 0.5) {
    Sgn = -1;
    AA = 1 - AA;
  }
  if (AA == 1) AA = 1 - 1./900;
  t = sqrt(-2 * log(1 - AA));
  return m + s * Sgn * (t - (A0 + A1 * t + A2 * t * t) / (1  + B1 * t + B2 * t * t + B3 * t * t * t));
}
//---------------------------------------------------------------------------
double dLogNormal (double x, double m, double s)
{
  if (x < 1e-10) return 0;
  else return dNormal (log(x), m, s) / x;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)

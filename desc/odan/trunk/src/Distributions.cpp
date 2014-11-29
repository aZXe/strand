//---------------------------------------------------------------------------
// Добавлено:
// 1. Функция vStudent
// 2. Функция psi и как следствие упрощена vNormal
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
double psi(double alpha)
{
  int Sgn = 1;
  double AA = alpha, t;

  if (AA >= 0 && AA < 0.5) {
    Sgn = -1;
    AA = 1 - AA;
  }
  if (AA == 1) AA = 1 - 1./900;
  t = sqrt(-2 * log(1 - AA));
  return Sgn * (t - (A0 + A1 * t + A2 * t * t) / (1  + B1 * t + B2 * t * t + B3 * t * t * t));
}
//---------------------------------------------------------------------------
double vNormal (double p, double m, double s)
{
  return m + s * psi(p);
}
//---------------------------------------------------------------------------
double dLogNormal (double x, double m, double s)
{
  if (x < 1e-10) return 0;
  else return dNormal (log(x), m, s) / x;
}
//---------------------------------------------------------------------------
double dLogNormal1 (double x, double m, double s)
{
  if (x < 1e-10) return 0;
  else return dNormal (log(x), log(m*m/sqrt(s*s+m*m)), sqrt(log(s*s/(m*m) + 1))) / x;
}
//---------------------------------------------------------------------------
double g1(double x)
{
  return (x*x*x + x) / 4;
}
//---------------------------------------------------------------------------
double g2(double x)
{
  return (5*x*x*x*x*x + 16*x*x*x + 3*x) / 96;
}
//---------------------------------------------------------------------------
double g3(double x)
{
  return (3*x*x*x*x*x*x*x + 19*x*x*x*x*x + 17*x*x*x - 15*x) / 384;
}
//---------------------------------------------------------------------------
double g4(double x)
{
  return (79*x*x*x*x*x*x*x*x*x + 776*x*x*x*x*x*x*x + 1482*x*x*x*x*x - 1920*x*x*x - 945*x) / 92160;
}
//---------------------------------------------------------------------------
double vStudent(double p, double v)
{
  double x;

  x = psi(p);

  return x + g1(x) / v + g2(x) / (v*v) + g3(x) / (v*v*v) + g4(x) / (v*v*v*v);
}
//---------------------------------------------------------------------------
double dSmes(double x, double m1, double s1, double m2, double s2, double q1,
             bool isNormal1, bool isNormal2)
{
  return q1 * ((isNormal1) ? dNormal(x, m1, s1) : dLogNormal1(x, m1, s1)) +
   (1 - q1) * ((isNormal2) ? dNormal(x, m2, s2) : dLogNormal1(x, m2, s2));
}
//---------------------------------------------------------------------------
double iSmes(double x, double m1, double s1, double m2, double s2, double q1,
             bool isNormal1, bool isNormal2)
{
  return q1 * ((isNormal1) ? iNormal(x, m1, s1) : (x < 1e-10) ? 0 : iNormal(log(x), log(m1*m1/sqrt(s1*s1+m1*m1)), sqrt(log(s1*s1/(m1*m1)+1)))) +
   (1 - q1) * ((isNormal2) ? iNormal(x, m2, s2) : (x < 1e-10) ? 0 : iNormal(log(x), log(m2*m2/sqrt(s2*s2+m2*m2)), sqrt(log(s2*s2/(m2*m2)+1))));
}
//---------------------------------------------------------------------------
double vSmes(double p, double m1, double s1, double m2, double s2, double q1,
             bool isNormal1, bool isNormal2)
{
  double x = q1 * m1 + (1 - q1) * m2, step = max(s1, s2);

  if (step < 1) step = 1;

  do {
    if (iSmes(x, m1, s1, m2, s2, q1, isNormal1, isNormal2) > p)
      if (iSmes(x - step, m1, s1, m2, s2, q1, isNormal1, isNormal2) > p)
        x -= step;
      else
        step /= 2;
    else
      if (iSmes(x + step, m1, s1, m2, s2, q1, isNormal1, isNormal2) < p)
        x += step;
      else
        step /= 2;
  }
  while (step >= 1e-6);

  return x;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)

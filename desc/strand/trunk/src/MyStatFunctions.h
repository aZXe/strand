//---------------------------------------------------------------------------
#ifndef MyStatFunctionsH
#define MyStatFunctionsH

#include "DArrayTypes.h"
//#include "GridArray.h"
#include "MatrixFunctions.h"
#include "Distributions.h"
//---------------------------------------------------------------------------
#define delta           1e-2

#define IDSLABAJA       0
#define IDSILNAJA       1
//---------------------------------------------------------------------------
void R (TDoubleArray &XX, TDoubleArray &W, long Nbeg, long NN, double *b);
int SizeJadr (long NN);
void JadrParameters (TDoubleArray &X, TDoubleArray &X1, TDoubleArray &FF,
                     TDoubleArray &f, double &eps, bool isQuantiles);
double D_2 (TDoubleArray &X1, TDoubleArray &FF, double m, double s);
double Smesi_D_2 (TDoubleArray &X1, TDoubleArray &FF,
                  double m1, double s1, double m2, double s2, double q1);
double Kn (double lambda);
bool Hipoteza (TDoubleArray &X1, TDoubleArray &FF, int Stepen, int i_H, double m, double s);
bool Smesi_Hipoteza (TDoubleArray &X1, TDoubleArray &FF, int Stepen,int Propusk,
                     double m1, double s1, double m2, double s2, double q1);
void Norm (TDoubleArray &XX, double eps);
void NormBC (TDoubleArray &XX, double lam, double eps);
void BCTransform (TDoubleArray &X, double lam);
double R_BC (TDoubleArray &X, TDoubleArray &W, double lam);
int CountQuantiles (long NN);
double GetA (TDoubleArray &X, long Nbegin, long Nend);
double RKrit (TDoubleArray &X1, TDoubleArray &FF,
              double m1, double s1, double m2, double s2, double q1);
void SVariate1 (TDoubleArray &X1, TDoubleArray &FF,
                double m1, double s1, double m2, double s2, double q1,
                double _Rmin_, int ind, int ind1);
void MVariate1 (TDoubleArray &X1, TDoubleArray &FF,
                double m1, double s1, double m2, double s2, double q1, int ind);
void SVariate2 (TDoubleArray &X1, TDoubleArray &FF,
                double m1, double s1, double m2, double s2, double q1,
                double _Rmin_, int ind, int ind1);
void MVariate2 (TDoubleArray &X1, TDoubleArray &FF,
                double m1, double s1, double m2, double s2, double q1, int ind);
void SmesiQuantiles (TDoubleArray &X1, TDoubleArray &FF, double *Q,
                     double m1, double s1, double m2, double s2, double q1);
void Quantiles (double *Q, double m, double s);
void LineApprox(TDoubleArray &X, TDoubleArray &Y, double *b);
void ArchArray(TDoubleArray &X);
//---------------------------------------------------------------------------
#endif

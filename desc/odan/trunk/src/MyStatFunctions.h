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
#define size_rep        71
//---------------------------------------------------------------------------
void R (TDoubleArray &XX, TDoubleArray &W, long Nbeg, long NN, double *b);
int SizeJadr (long NN);
void JadrParameters (TDoubleArray &X, TDoubleArray &W, TDoubleArray &W1,
                     TDoubleArray &X1, TDoubleArray &FF,
                     TDoubleArray &f, double &eps, bool isQuantiles);
double D_2 (TDoubleArray &X1, TDoubleArray &FF, double m, double s);
double Smesi_D_2 (TDoubleArray &X1, TDoubleArray &FF,
                  double m1, double s1, double m2, double s2, double q1);
double Kn (double lambda);
bool Hipoteza (TDoubleArray &X1, TDoubleArray &FF, int Stepen, int i_H, double m, double s, double *hip_res);
bool Smesi_Hipoteza (TDoubleArray &X1, TDoubleArray &FF, int Stepen,int Propusk,
                     double m1, double s1, double m2, double s2, double q1, double *hip_res);
void Norm (TDoubleArray &XX, double eps);
void NormBC (TDoubleArray &XX, double lam, double eps);
void BCTransform (TDoubleArray &X, double lam);
double R_BC (TDoubleArray &X, TDoubleArray &W, double lam);
int CountQuantiles (long NN);
double GetA (TDoubleArray &X, TDoubleArray &W, long Nbegin, long Nend);
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
void LineApprox(TDoubleArray &X, TDoubleArray &Y, TDoubleArray &W, double *b);
void LineApprox(TDoubleArray &X, TDoubleArray &Y, TDoubleArray &W,
                long Nbegin, long Nend, double *b);
void ArchArray(TDoubleArray &X);
double Correlation(TDoubleArray &X, TDoubleArray &Y);
double QVariate(TDoubleArray &XX1, TDoubleArray &FF1,
                double &m1, double &s1, double &m2, double &s2, double &q1);
void NewQuantiles (bool isNormal1, double *Q, double m1, double s1,
                   double m2 = 0, double s2 = 0, double q1 = 0, bool isNormal2 = true);
//---------------------------------------------------------------------------
#endif

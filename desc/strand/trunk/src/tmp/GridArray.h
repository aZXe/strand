//---------------------------------------------------------------------------
#ifndef GridArrayH
#define GridArrayH

//#include <sysdyn.h>
#include <values.h>
#include <Grids.hpp>
#include "stadev32.h"
#include "DArrayTypes.h"
#include "Logging.h"
#include "VarDescription.h"
#include "MatMath\matlab.hpp"
//---------------------------------------------------------------------------
#define MISSING_DATA MAXDOUBLE
//---------------------------------------------------------------------------
TDoubleArray ReplaceMissingData(TDoubleArray A, double d);
//---------------------------------------------------------------------------
class TArray
{
private:
  TStringGrid *Grid;
  bool isDeleteGrid;  //Удалять ли Grid в деструкторе
  TAnsiStringArray varsnames, casesnames;
  T2DoubleArray Array;
  TDoubleArray Means;
  long nvars, ncases;
  char format[5];
  TVarDescriptionArray VarDesc;

  double __fastcall GetCell (long ACol, long ARow);
  void   __fastcall SetCell (long ACol, long ARow, double Val);

  char const * __fastcall GetVarName (long Var);
  void         __fastcall SetVarName (long Var, char const *name);

  char const * __fastcall GetCaseName (long Var);
  void         __fastcall SetCaseName (long Var, char const *name);

  void __fastcall SetNVars  (long nv);
  void __fastcall SetNCases (long nc);

  int GETVARID(char *s);
  mwArray GETVARVALUE(int i);
  TmwArrayArray X;
  double *xxx;
protected:
public:
  bool isReplaceMissingDataByMean;

  __fastcall TArray(TStringGrid *StrGrid, long _nvars = 5, long _ncases = 5,
                    unsigned form = 8);
  __fastcall TArray(TStringGrid *StrGrid, mwArray A, unsigned form = 8);
  __fastcall ~TArray(void);
  __property double Cell[long ACol][long ARow] = {read=GetCell, write=SetCell};
  __property const char* VarName [long Var] = {read=GetVarName,  write=SetVarName };
  __property const char* CaseName[long Var] = {read=GetCaseName, write=SetCaseName};
  __property long NVars  = {read=nvars,  write=SetNVars };
  __property long NCases = {read=ncases, write=SetNCases};
  void _fastcall CalculateMeans(void);
  void _fastcall CalculateMean (int Var);
  void _fastcall SetFormat (unsigned form);
  void _fastcall SetNumVars  (void);
  void _fastcall SetNumCases (void);
  void _fastcall SetData (const TDoubleArray &A);
  void _fastcall SetData (const T2DoubleArray &A);
  T2DoubleArray _fastcall GetData (void);
  void _fastcall SetColsNames (const TAnsiStringArray &CN);
  void _fastcall SetRowsNames (const TAnsiStringArray &RN);
  int  _fastcall OpenStaFile (const char *filename);
  int  _fastcall SaveStaFile (const char *filename);
  int  _fastcall VarByName (const AnsiString varname);
  TDoubleArray _fastcall GetVar(int Var)
    {return (isReplaceMissingDataByMean) ?
               ReplaceMissingData(Array[Var - 1].Copy(), Means[Var - 1]) :
               Array[Var - 1].Copy();}
  void _fastcall SetVar(TDoubleArray &X, int Var, AnsiString vname = "");
  void _fastcall SetVar(mwArray &X, int Var, AnsiString vname = "");
  void AddVar(void) {NVars++;}
  void AddVar(char *name) {NVars++; VarName[NVars] = name;}
  void AddVar(int count) {NVars += count;}
  void AddVar(AnsiString name, AnsiString func);
};
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------
#ifndef GridArrayH
#define GridArrayH

//#include <sysdyn.h>
#include <values.h>
#include <Grids.hpp>
#include "stadev32.h"
#include "DArrayTypes.h"

#define MISSING_DATA MAXDOUBLE

class TArray
{
private:
  TStringGrid *Grid;
  TAnsiStringArray varsnames, casesnames;
  T2DoubleArray Array;
  long nvars, ncases;
  char format[5];

  double __fastcall GetCell (long ACol, long ARow);
  void   __fastcall SetCell (long ACol, long ARow, double Val);

  char const * __fastcall GetVarName (long Var);
  void         __fastcall SetVarName (long Var, char const *name);

  char const * __fastcall GetCaseName (long Var);
  void         __fastcall SetCaseName (long Var, char const *name);

  void __fastcall SetNVars  (long nv);
  void __fastcall SetNCases (long nc);
protected:
public:
  __fastcall TArray(TStringGrid *StrGrid, long _nvars = 5, long _ncases = 5,
                    unsigned form = 8);
  __property double Cell[long ACol][long ARow] = {read=GetCell, write=SetCell};
  __property const char* VarName [long Var] = {read=GetVarName,  write=SetVarName };
  __property const char* CaseName[long Var] = {read=GetCaseName, write=SetCaseName};
  __property long NVars  = {read=nvars,  write=SetNVars };
  __property long NCases = {read=ncases, write=SetNCases};
  void _fastcall SetFormat (unsigned form);
  void _fastcall SetNumVars  (void);
  void _fastcall SetNumCases (void);
  void _fastcall SetData (TDoubleArray &A);
  void _fastcall SetData (T2DoubleArray &A);
  int  _fastcall OpenStaFile (const char *filename);
  int  _fastcall SaveStaFile (const char *filename);
  int  _fastcall VarByName (const AnsiString varname);
  TDoubleArray _fastcall GetVar(int Var) {return Array[Var - 1].Copy();}
  void _fastcall SetVar(TDoubleArray &X, int Var, AnsiString vname = "");
  void AddVar(void) {NVars++;}
  void AddVar(char *name) {NVars++; VarName[NVars] = name;}
  void AddVar(int count) {NVars += count;}
};
//---------------------------------------------------------------------------
#endif

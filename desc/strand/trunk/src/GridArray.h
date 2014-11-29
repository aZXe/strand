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

protected:

  TStringGrid *Grid;
  bool isDeleteGrid;  //Удалять ли Grid в деструкторе
  TAnsiStringArray casesnames;
  T2DoubleArray Array;
  TDoubleArray Means;
  long nvars, ncases;
  char format[5];

  TVarDescriptionArray VarDesc;

  double __fastcall GetCell (long ACol, long ARow);
  void   __fastcall SetCell (long ACol, long ARow, double Val);

  AnsiString __fastcall GetVarName (long Var);
  void       __fastcall SetVarName (long Var, AnsiString name);

  AnsiString __fastcall GetCaseName (long Var);
  void       __fastcall SetCaseName (long Var, AnsiString name);

  void __fastcall SetNVars  (long nv);
  void __fastcall SetNCases (long nc);

  TDoubleArray LoadStaVar(AnsiString filename, int var);

public:
  bool isReplaceMissingDataByMean;

  __fastcall TArray(TStringGrid *StrGrid, long _nvars = 5, long _ncases = 5,
                    unsigned form = 8);
  __fastcall TArray(TStringGrid *StrGrid, mwArray A, unsigned form = 8);
  __fastcall ~TArray(void);
  __property double Cell[long ACol][long ARow] = {read=GetCell, write=SetCell};
  __property AnsiString VarName [long Var] = {read=GetVarName,  write=SetVarName };
  __property AnsiString CaseName[long Var] = {read=GetCaseName, write=SetCaseName};
  __property long NVars  = {read=nvars,  write=SetNVars };
  __property long NCases = {read=ncases, write=SetNCases};
  void __fastcall CalculateMeans(void);
  void __fastcall CalculateMean (int Var);
  void __fastcall SetFormat (unsigned form);
  void __fastcall SetNumVars  (void);
  void __fastcall SetNumCases (void);
  void __fastcall SetData (const TDoubleArray &A);
  void __fastcall SetData (const T2DoubleArray &A);
  T2DoubleArray __fastcall GetData (void);
  void __fastcall SetColsNames (const TAnsiStringArray &CN);
  void __fastcall SetRowsNames (const TAnsiStringArray &RN);
  int  __fastcall OpenStaFile (const char *filename);
  int  __fastcall SaveStaFile (const char *filename);
  int  __fastcall OpenDescFile (AnsiString filename, bool refresh_data = false);
  int  __fastcall SaveDescFile (AnsiString filename, bool save_data = true);
  int  __fastcall RefreshData (void);
  int  __fastcall VarByName (const AnsiString varname);
  TDoubleArray __fastcall GetVar(int Var)
    {return (isReplaceMissingDataByMean) ?
               ReplaceMissingData(Array[Var - 1].Copy(), Means[Var - 1]) :
               Array[Var - 1].Copy();}
  void __fastcall SetVar(TDoubleArray &X, int Var, AnsiString vname = "");
  void __fastcall SetVar(mwArray &X, int Var, AnsiString vname = "");
  void __fastcall SetVar(AnsiString func, int Var, AnsiString vname = "");
  void AddVar(void) {NVars++;}
  void AddVar(char *name) {NVars++; VarName[NVars] = name;}
  void AddVar(int count) {NVars += count;}
  void AddVar(AnsiString func, AnsiString name = "") {SetVar(func, NVars + 1, name);};
};
//---------------------------------------------------------------------------
#endif

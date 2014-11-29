//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <stdio>
#include <math>
#include <stdlib>
#include <string>
#include <set>
#include "Progress.h"
#include "Utils.h"
#include "GridArray.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
__fastcall TArray::TArray (TStringGrid *StrGrid, long _nvars, long _ncases,
                           unsigned form)
{
  Grid = StrGrid;
  if (Grid) {
    Grid->ColCount = (nvars  = (_nvars  > 0 ? _nvars  : 1)) + 1;
    Grid->RowCount = (ncases = (_ncases > 0 ? _ncases : 1)) + 1;
  }
  else {
    nvars  = (_nvars  > 0 ? _nvars  : 1);
    ncases = (_ncases > 0 ? _ncases : 1);
  }
  sprintf(format, "%%.%ulf", form);

//  varsnames  = new TAnsiStringArray;
//  casesnames = new TAnsiStringArray;
  varsnames.Length  = nvars;
  casesnames.Length = ncases;

  Array.Length = nvars;
  for (int i = 0; i < Array.Length; i++)
    Array[i].Length = ncases;

  for (int i = 0; i < nvars; i++)
    for (int j = 0; j < ncases; j++)
      Array[i][j] = MISSING_DATA;
}
//---------------------------------------------------------------------------
double __fastcall TArray::GetCell (long ACol, long ARow)
{
  if (0 < ACol && ACol <= nvars && 0 < ARow && ARow <= ncases)
    return Array[ACol - 1][ARow - 1];
/*
    if (Grid->Cells[ACol][ARow] != (AnsiString)"")
      return atof(Grid->Cells[ACol][ARow].c_str());
    else return MISSING_DATA;
*/
  else return MINDOUBLE;
}

void __fastcall TArray::SetCell (long ACol, long ARow, double Val)
{
  char buf[100];
  int i, j;
  long _nvars = nvars, _ncases = ncases;

  if (ACol > nvars || ARow > ncases) {
    if (Grid) {
      Grid->ColCount = (nvars  = max(ACol, nvars))  + 1;
      Grid->RowCount = (ncases = max(ARow, ncases)) + 1;
    }
    else {
      nvars  = max(ACol, nvars);
      ncases = max(ARow, ncases);
    }

    varsnames.Length  = nvars;
    casesnames.Length = ncases;
    Array.Length = nvars;
    for (i = 0; i < Array.Length; i++)
      Array[i].Length = ncases;

    for (i = _nvars; i < nvars; i++)
      for (j = 0; j < ncases; j++)
        Array[i][j] = MISSING_DATA;
    for (j = _ncases; j < ncases; j++)
      for (i = 0; i < nvars; i++)
        Array[i][j] = MISSING_DATA;                           
  }

  if (0 < ACol && 0 < ARow) {
    if (Grid)
      if (Val != MISSING_DATA) {
        if (fabs(Val) > 1e-3 || Val == 0) sprintf(buf, format, Val);
        else sprintf(buf, "%.5e", Val);
        Grid->Cells[ACol][ARow] = (AnsiString)buf;
      }
      else Grid->Cells[ACol][ARow] = (AnsiString)"";
      Array[ACol - 1][ARow - 1] = Val;
  }
}
//---------------------------------------------------------------------------
char const * __fastcall TArray::GetVarName (long Var)
{
  if (0 < Var && Var <= nvars)
    return varsnames[Var - 1].c_str();
  else return NULL;
}

void __fastcall TArray::SetVarName(long Var, char const *name)
{
  int i, j;
  long _nvars = nvars;

  if (Var > nvars) {
    if (Grid) Grid->ColCount = (nvars = Var) + 1;
    else nvars = Var;

    varsnames.Length  = nvars;
    Array.Length = nvars;
    for (i = 0; i < Array.Length; i++)
      Array[i].Length = ncases;

    for (i = _nvars; i < nvars; i++)
      for (j = 0; j < ncases; j++)
        Array[i][j] = MISSING_DATA;
  }

  if (0 < Var)
    if (Grid) {
      Grid->Cells[Var][0] = (AnsiString)name;
      varsnames[Var - 1]  = ((AnsiString)name).Trim();
    }
    else varsnames[Var - 1] = ((AnsiString)name).Trim();
}
//---------------------------------------------------------------------------
char const * __fastcall TArray::GetCaseName (long Var)
{
  if (0 < Var && Var <= ncases && Grid)
    return casesnames[Var - 1].c_str();
  else return NULL;
}

void __fastcall TArray::SetCaseName (long Var, char const *name)
{
  int i, j;
  long _ncases = ncases;

  if (Var > ncases) {
    if (Grid) Grid->RowCount = (ncases = Var) + 1;
    else ncases = Var;

    casesnames.Length = ncases;
    Array.Length = nvars;
    for (i = 0; i < Array.Length; i++)
      Array[i].Length = ncases;

    for (j = _ncases; j < ncases; j++)
      for (i = 0; i < nvars; i++)
        Array[i][j] = MISSING_DATA;
  }

  if (0 < Var)
    if (Grid) {
      Grid->Cells[0][Var] = (AnsiString)name;
      casesnames[Var - 1] = (AnsiString)name;
    }
    else casesnames[Var - 1] = (AnsiString)name;
}
//---------------------------------------------------------------------------
void __fastcall TArray::SetNVars (long nv)
{
  int i, j;
  long _nvars = nvars;

  if (Grid) Grid->ColCount = (nvars =  (nv > 0 ? nv : 1)) + 1;
  else nvars =  (nv > 0 ? nv : 1);

  varsnames.Length  = nvars;
  Array.Length = nvars;
  for (i = 0; i < Array.Length; i++)
    Array[i].Length = ncases;

  for (i = _nvars; i < nvars; i++)
    for (j = 0; j < ncases; j++)
      Array[i][j] = MISSING_DATA;

}

void __fastcall TArray::SetNCases (long nc)
{
  int i, j;
  long _ncases = ncases;

  if (Grid) Grid->RowCount = (ncases = (nc > 0 ? nc : 1)) + 1;
  else ncases = (nc > 0 ? nc : 1);

  casesnames.Length = ncases;
  Array.Length = nvars;
  for (i = 0; i < Array.Length; i++)
    Array[i].Length = ncases;

  for (j = _ncases; j < ncases; j++)
    for (i = 0; i < nvars; i++)
      Array[i][j] = MISSING_DATA;
}
//---------------------------------------------------------------------------
void _fastcall TArray::SetFormat (unsigned form)
{
  sprintf(format, "%%.%ulf", form);
}
//---------------------------------------------------------------------------
int  _fastcall TArray::OpenStaFile (const char *filename)
{
  char Varname [STAMAX_VARNAMELEN  + 1],
       Casename[STAMAX_CASENAMELEN + 1];
  short i, nv;
  long  j, nc;
  AnsiString tmp_str;
  HSTAFILE hSta;

  hSta = StaOpenFile (filename);
  if ( hSta == 0 ) {
    MessageBox (NULL, "Cannot open requested STATISTICA file !!!", "Error", MB_OK);
    return 0;
  }
  else {
    ProgressCaption(SFormat("Открытие файла %s", filename));
    ProgressSet(0);
    ProgressShow();

    NVars  = nv = StaGetNVars (hSta);
    NCases = nc = StaGetNCases(hSta);
    Varname [STAMAX_VARNAMELEN ] = 0;
    Casename[STAMAX_CASENAMELEN] = 0;

    progress_step = 100.0 / (nvars * ncases + nvars + ncases);

    for (i = 1; i <= nv; i++) {
      StaGetVarName (hSta, i, Varname);
      tmp_str = (AnsiString)(Varname);
      VarName[i] = (tmp_str.TrimRight()).c_str();
      
      ProgressInc();
    }

    short cnl = StaGetCaseNameLength (hSta);
    for (j = 1; j <= nc; j++ ) {
      if ( cnl != 0 ) {
        StaGetCaseName (hSta, j, Casename, sizeof(Casename));
        CaseName[j] = Casename;
      }
      else CaseName[j] = "";

      ProgressInc();
    }

    short wid, dec, type, subt;
    double MD;
    double d;
    for ( i = 1; i <= nv; i++ ) {
      StaGetVarFormat (hSta, i, &wid, &dec, &type, &subt);
      SetFormat (dec);
      StaGetVarMD (hSta, i, &MD);
      for ( j = 1; j <= nc; j++ ) {
        StaGetData (hSta, i, j, &d);
        if (d != MD) Cell[i][j] = d;
        else Cell[i][j] = MISSING_DATA;

        ProgressInc();
      }
    }
  }

  ProgressSet(100);
  ProgressHide();
  
  StaCloseFile(hSta);

  return 1;
}
//---------------------------------------------------------------------------
int  _fastcall TArray::SaveStaFile (const char *filename)
{
  short i;
  long  j;

  HSTAFILE hSta;
  
  hSta = StaCreateFile ((short)NVars, NCases, filename);
  if ( hSta == 0 ) {
    MessageBox (NULL, "Cannot create STATISTICA file !!!", "Error", MB_OK);
    return 0;
  }
  else {
    ProgressCaption(SFormat("Сохранение файла %s", filename));
    ProgressSet(0);
    ProgressShow();
    progress_step = 100.0 / (nvars * ncases + nvars + ncases);

    for (i = 1; i <= NVars; i++) {
      StaSetVarName (hSta, i, VarName[i]);
      ProgressInc();
    }

    StaSetCaseNameLength (hSta, 8);  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    for (j = 1; j <= NCases; j++ ) {
      StaSetCaseName (hSta, j, CaseName[j]);
      ProgressInc();
    }

    double d;
    for ( i = 1; i <= NVars; i++ ) {
      StaSetVarFormat (hSta, i, 8, 3, 0, 0);
      StaSetVarMD (hSta, i, -9999);  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
      for ( j = 1; j <= NCases; j++ ) {
        d = Cell[i][j];
        if (d == MISSING_DATA) StaSetData (hSta, i, j, -9999);
        else StaSetData (hSta, i, j, d);
        ProgressInc();
      }
    }
  }

  ProgressSet(100);
  ProgressHide();
  
  StaCloseFile(hSta);

  return 1;
}
//---------------------------------------------------------------------------
int _fastcall TArray::VarByName (const AnsiString varname)
{
  for (int i = 0; i < nvars; i++) {
    if (varsnames[i] == varname)
      return i + 1;
  }

  return 0;
}
//---------------------------------------------------------------------------
void _fastcall TArray::SetData (TDoubleArray &A)
{
  NVars = 1;
  NCases = A.Length;

  for (long j = 1; j <= A.Length; j++)
    Cell[1][j] = A[j - 1];

  varsnames.Length  = nvars;
  casesnames.Length = ncases;
}
//---------------------------------------------------------------------------
void _fastcall TArray::SetData (T2DoubleArray &A)
{
  NVars = A.Length;
  NCases = A[0].Length;
  for (int i = 1; i <= A.Length; i++)
    for (long j = 1; j <= A[i].Length; j++)
      Cell[i][j] = A[i - 1][j - 1];

  varsnames.Length  = nvars;
  casesnames.Length = ncases;
}
//---------------------------------------------------------------------------
void _fastcall TArray::SetNumVars (void)
{
  char buf[20];

  for (int i = 1; i <= NVars; i++)
    VarName[i] = itoa(i, buf, 10);
}
//---------------------------------------------------------------------------
void _fastcall TArray::SetNumCases (void)
{
  char buf[20];

  for (long i = 1; i <= NCases; i++)
    CaseName[i] = itoa(i, buf, 10);
}
//---------------------------------------------------------------------------
void _fastcall TArray::SetVar(TDoubleArray &X, int Var, AnsiString vname)
{
  int i, j;
  long N = X.Length;
  long _nvars  = nvars,
       _ncases = ncases;

  if (N > ncases) {
    if (Grid) Grid->RowCount = (ncases = N) + 1;
    else ncases = N;

    casesnames.Length = ncases;
    Array.Length = nvars;
    for (i = 0; i < Array.Length; i++)
      Array[i].Length = ncases;

    for (j = _ncases; j < ncases; j++)
      for (i = 0; i < nvars; i++)
        Array[i][j] = MISSING_DATA;
  }

  if (Var > nvars) {
    if (Grid) Grid->ColCount = (nvars = Var) + 1;
    else nvars = Var;

    varsnames.Length  = nvars;
    Array.Length = nvars;
    for (i = 0; i < Array.Length; i++)
      Array[i].Length = ncases;

    for (i = _nvars; i < nvars; i++)
      for (j = 0; j < ncases; j++)
        Array[i][j] = MISSING_DATA;
  }

  if (vname != "") VarName[Var] = vname.c_str();
  for (long j = 1; j <= X.Length; j++)
    Cell[Var][j] = X[j - 1];
//  Array[Var - 1] = X.Copy();
}
//---------------------------------------------------------------------------
int _fastcall TArray::CountIf (const AnsiString varname, const double value)
{
  return CountIf(VarByName(varname), value);
}
//---------------------------------------------------------------------------
int _fastcall TArray::CountIf (const int varnum, const double value)
{
  int i, c;

  if (varnum < 1 || varnum > NVars) return 0;

  for(c = i = 0; i < NCases; i++)
    if (Cell[varnum][i + 1] == value) c++;

  return c;
}
//---------------------------------------------------------------------------
int  _fastcall TArray::Replace (const AnsiString varname, const double value, const double newvalue)
{
  return Replace(VarByName(varname), value, newvalue);
}
//---------------------------------------------------------------------------
int  _fastcall TArray::Replace (const int varnum,  const double value, const double newvalue)
{
  int i, c;

  if (varnum < 1 || varnum > NVars) return 0;

  for(c = i = 0; i < NCases; i++)
    if (Cell[varnum][i + 1] == value) {
      Cell[varnum][i + 1] = newvalue;
      c++;
    }

  return c;
}
//---------------------------------------------------------------------------
T2DoubleArray _fastcall TArray::SubArrayIf (const AnsiString varname, const double value, TIntArray *I)
{
  return SubArrayIf(VarByName(varname), value, I);
}
//---------------------------------------------------------------------------
T2DoubleArray _fastcall TArray::SubArrayIf (const int varnum,  const double value, TIntArray *I)
{
  T2DoubleArray A;
  int i, j, p;

  A.Length = 0;

  if (varnum >= 1 && varnum <= NVars) {
    A.Length = NVars;
    if (I) I->Length = NCases;
    for(j = 0; j < NVars; j++)
      A[j].Length = NCases;

    for(p = i = 0; i < NCases; i++)
      if (Cell[varnum][i + 1] == value) {
        for(j = 0; j < NVars; j++)
          A[j][p] = Cell[j + 1][i + 1];
        if (I) (*I)[p] = i + 1;
        p++;
      }

    for(j = 0; j < NVars; j++)
      A[j].Length = p;
    if (I) I->Length = p;
  }

  return A;
}
//---------------------------------------------------------------------------
T2DoubleArray _fastcall TArray::SubTArrayIf (const AnsiString varname, const double value, TIntArray *I)
{
  return SubTArrayIf(VarByName(varname), value, I);
}
//---------------------------------------------------------------------------
T2DoubleArray _fastcall TArray::SubTArrayIf (const int varnum,  const double value, TIntArray *I)
{
  T2DoubleArray A;
  int i, j, p;

  A.Length = 0;

  if (varnum >= 1 && varnum <= NVars) {
    A.Length = NCases;
    if (I) I->Length = NCases;

    for(p = i = 0; i < NCases; i++)
      if (Cell[varnum][i + 1] == value) {
        A[p].Length = NVars;
        for(j = 0; j < NVars; j++)
          A[p][j] = Cell[j + 1][i + 1];
        if (I) (*I)[p] = i + 1;
        p++;
      }

    A.Length = p;
    if (I) I->Length = p;
  }

  return A;
}
//---------------------------------------------------------------------------
double _fastcall TArray::Max(const AnsiString varname, int *ind)
{
  return Max(VarByName(varname), ind);
}
//---------------------------------------------------------------------------
double _fastcall TArray::Max(const int varnum, int *ind)
{
  int i;
  double max = MINDOUBLE;

  if (varnum < 1 || varnum > NVars) return MINDOUBLE;

  for (i = 1; i <= NCases; i++)
    if (max < Cell[varnum][i]) {
      max = Cell[varnum][i];
      if (ind) *ind = i;
    }

  return max;
}
//---------------------------------------------------------------------------
double _fastcall TArray::Min(const AnsiString varname, int *ind)
{
  return Min(VarByName(varname), ind);
}
//---------------------------------------------------------------------------
double _fastcall TArray::Min(const int varnum, int *ind)
{
  int i;
  double min = MAXDOUBLE;

  if (varnum < 1 || varnum > NVars) return MAXDOUBLE;

  for (i = 1; i <= NCases; i++)
    if (min > Cell[varnum][i]) {
      min = Cell[varnum][i];
      if (ind) *ind = i;
    }

  return min;
}
//---------------------------------------------------------------------------
int  _fastcall TArray::CountDiff (const AnsiString varname)
{
  return CountDiff(VarByName(varname));
}
//---------------------------------------------------------------------------
int  _fastcall TArray::CountDiff (const int varnum)
{
  set<double, less<double> > NSet;

  if (varnum < 1 || varnum > NVars) return 0;

  for (int i = 1; i <= NCases; i++)
    if (Cell[varnum][i] != MISSING_DATA)
      NSet.insert(Cell[varnum][i]);

  return NSet.size();
}
//---------------------------------------------------------------------------
T2DoubleArray _fastcall TArray::SubArray (TIntSet &I)
{
  T2DoubleArray A;
  TIntSetIterator p;
  int i, j;

  A.Length = 0;
  if (I.size() == 0) return A;

  A.Length = NVars;
  for(j = 0; j < NVars; j++)
    A[j].Length = I.size();

  for(i = 0, p = I.begin(); p != I.end(); i++, p++)
    for(j = 0; j < NVars; j++)
      A[j][i] = Cell[j + 1][*p + 1];

  return A;
}
//---------------------------------------------------------------------------
T2DoubleArray _fastcall TArray::SubTArray(TIntSet &I)
{
  T2DoubleArray A;
  TIntSetIterator p;
  int i, j;

  A.Length = 0;
  if (I.size() == 0) return A;

  A.Length = I.size();
  for(j = 0; j < A.Length; j++)
    A[j].Length = NVars;

  for(i = 0, p = I.begin(); p != I.end(); i++, p++)
    for(j = 0; j < NVars; j++)
      A[i][j] = Cell[j + 1][*p + 1];

  return A;
}
//---------------------------------------------------------------------------
void _fastcall TArray::SetVarConst(int varnum, double newvalue)
{
  if (varnum < 1 || varnum > NVars) return;

  for (int i = 1; i <= NCases; i++)
    Cell[varnum][i] = newvalue;
}
//---------------------------------------------------------------------------


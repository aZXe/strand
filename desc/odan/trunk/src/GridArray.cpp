//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GridArray.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
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
  char buf[20];
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
        sprintf(buf, format, Val);
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
    NVars  = nv = StaGetNVars (hSta);
    NCases = nc = StaGetNCases(hSta);
    Varname [STAMAX_VARNAMELEN ] = 0;
    Casename[STAMAX_CASENAMELEN] = 0;

    for (i = 1; i <= nv; i++) {
      StaGetVarName (hSta, i, Varname);
      tmp_str = (AnsiString)(Varname);
      VarName[i] = (tmp_str.TrimRight()).c_str();
    }

    short cnl = StaGetCaseNameLength (hSta);
    for (j = 1; j <= nc; j++ )
      if ( cnl != 0 ) {
        StaGetCaseName (hSta, j, Casename, sizeof(Casename));
        CaseName[j] = Casename;
      }
      else CaseName[j] = "";

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
      }
    }
  }

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
    for (i = 1; i <= NVars; i++)
      StaSetVarName (hSta, i, VarName[i]);

    StaSetCaseNameLength (hSta, 8);  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    for (j = 1; j <= NCases; j++ )
      StaSetCaseName (hSta, j, CaseName[j]);

    double d;
    for ( i = 1; i <= NVars; i++ ) {
      StaSetVarFormat (hSta, i, 8, 3, 0, 0);
      StaSetVarMD (hSta, i, -9999);  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
      for ( j = 1; j <= NCases; j++ ) {
        d = Cell[i][j];
        if (d == MISSING_DATA) StaSetData (hSta, i, j, -9999);
        else StaSetData (hSta, i, j, d);
      }
    }
  }

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
/*
TDoubleArray _fastcall TArray::GetVar(int Var)
{
  return Array[Var].Copy();
}
*/

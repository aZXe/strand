//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GridArray.h"
#include "CalcMFunctions.h"
#include "Logging.h"
#include "Utils.h"
#include "Maps.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
int TArray::GETVARID(char *s)
{
  int i;
  static TintIntMap m;

  i = VarByName((AnsiString)s);
  if (i == 0)
    return UNKNOWN_VAR;
  else {
    if (m.count(i))
      return m[i] << 1;

    X.Length++;
    for (int j = 0; j < NCases; j++)
      xxx[j] = Cell[i][j + 1];
    X[X.Length - 1] = new mwArray(NCases, 1, xxx);
    m[i] = X.Length - 1;

    return m[i];
  }
}

mwArray TArray::GETVARVALUE(int i)
{
  return *(X[i]);
}
//---------------------------------------------------------------------------
TDoubleArray ReplaceMissingData(TDoubleArray A, double d)
{
  for (int i = 0; i < A.Length; i++)
    if (A[i] == MISSING_DATA) A[i] = d;
  return A;
}
//---------------------------------------------------------------------------
__fastcall TArray::TArray (TStringGrid *StrGrid, long _nvars, long _ncases,
                           unsigned form)
{
  if (StrGrid) {
    Grid = StrGrid;
    isDeleteGrid = false;
  }
  else {
    Grid = new TStringGrid(Application->MainForm);
    Grid->Parent = Application->MainForm;
    Grid->Top  = 0;
    Grid->Left = 0;
    Grid->Visible = false;
    isDeleteGrid = true;
  }
//  if (Grid) {
  Grid->ColCount = (nvars  = (_nvars  > 0 ? _nvars  : 1)) + 1;
  Grid->RowCount = (ncases = (_ncases > 0 ? _ncases : 1)) + 1;
/*  }
  else {
    nvars  = (_nvars  > 0 ? _nvars  : 1);
    ncases = (_ncases > 0 ? _ncases : 1);
  }*/
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

  isReplaceMissingDataByMean = false;
}
//---------------------------------------------------------------------------
__fastcall TArray::TArray (TStringGrid *StrGrid, mwArray A, unsigned form)
{
  if (StrGrid) {
    Grid = StrGrid;
    isDeleteGrid = false;
  }
  else {
    Grid = new TStringGrid(Application->MainForm);
    Grid->Parent = Application->MainForm;
    Grid->Top  = 0;
    Grid->Left = 0;
    Grid->Visible = false;
    isDeleteGrid = true;
  }

  Grid->ColCount = (nvars  = A.Size(1));
  Grid->RowCount = (ncases = A.Size(2));

  sprintf(format, "%%.%ulf", form);

  varsnames.Length  = nvars;
  casesnames.Length = ncases;

  Array.Length = nvars;
  for (int i = 0; i < Array.Length; i++)
    Array[i].Length = ncases;

  for (int i = 0; i < nvars; i++)
    for (int j = 0; j < ncases; j++) {
      Array[i][j] = A(i + 1,j + 1).Double();
      Grid->Cells[i + 1][j + 1] = SFormat(format, A(i + 1,j + 1).Double());
    }

  isReplaceMissingDataByMean = false;
}

//---------------------------------------------------------------------------
__fastcall TArray::~TArray(void)
{
  try {
    if (isDeleteGrid) delete Grid;
  }
  __except (EXCEPTION_CONTINUE_EXECUTION) {
    Application->MessageBox("Ошибка в деструкторе типа TArray!", "Ошибка", MB_OK + MB_ICONERROR);
  }
}
//---------------------------------------------------------------------------
double __fastcall TArray::GetCell (long ACol, long ARow)
{
  if (0 < ACol && ACol <= nvars && 0 < ARow && ARow <= ncases)
    return (Array[ACol - 1][ARow - 1] == MISSING_DATA && isReplaceMissingDataByMean)?Means[ACol - 1]:Array[ACol - 1][ARow - 1];
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
    Application->MessageBox ("Cannot open requested STATISTICA file !!!", "Error", MB_OK + MB_ICONERROR);
    LogAdd("!!!Ошибка открытия файла " + (AnsiString)filename);
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

  CalculateMeans();

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
    Application->MessageBox ("Cannot create STATISTICA file !!!", "Error", MB_OK + MB_ICONERROR);
    LogAdd("!!!Ошибка создания/записи файла " + (AnsiString)filename);
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
void _fastcall TArray::SetData (const TDoubleArray &A)
{
  NVars = 1;
  NCases = A.Length;

  for (long j = 1; j <= A.Length; j++)
    Cell[1][j] = A[j - 1];

  varsnames.Length  = nvars;
  casesnames.Length = ncases;

  CalculateMeans();
}
//---------------------------------------------------------------------------
void _fastcall TArray::SetData (const T2DoubleArray &A)
{
  NVars = A.Length;
  NCases = A[0].Length;
  for (int i = 1; i <= A.Length; i++)
    for (long j = 1; j <= A[i - 1].Length; j++)
      Cell[i][j] = A[i - 1][j - 1];

  varsnames.Length  = nvars;
  casesnames.Length = ncases;

  CalculateMeans();
}
//---------------------------------------------------------------------------
T2DoubleArray _fastcall TArray::GetData (void)
{
  return Array;
}
//---------------------------------------------------------------------------
void _fastcall TArray::SetColsNames (const TAnsiStringArray &CN)
{
  if (CN.Length == 0) return;
  for (int i = 1; i <= CN.Length; i++)
    VarName[i] = CN[i - 1].c_str();
}
//---------------------------------------------------------------------------
void _fastcall TArray::SetRowsNames (const TAnsiStringArray &RN)
{
  if (RN.Length == 0) return;
  for (int i = 1; i <= RN.Length; i++)
    CaseName[i] = RN[i - 1].c_str();
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

  CalculateMean(Var);
}
//---------------------------------------------------------------------------
void _fastcall TArray::SetVar(mwArray &X, int Var, AnsiString vname)
{
  int i, j;
  long N = X.Size(2);
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
  for (int j = 1; j <= N; j++)
    Cell[Var][j] = X(1, j).Double();
//  Array[Var - 1] = X.Copy();

  CalculateMean(Var);
}
//---------------------------------------------------------------------------
void _fastcall TArray::CalculateMeans(void)
{
  int i, j, n;
  double mean;

  Means.Length = nvars;
  for (i = 0; i < nvars; i++) {
    mean = n = 0;
    for (j = 0; j < ncases; j++)
      if (Array[i][j] != MISSING_DATA) {
        mean += Array[i][j];
        n++;
      }
    if (n != 0) Means[i] = mean / n;
    else Means[i] = MISSING_DATA;
  }
}
//---------------------------------------------------------------------------
void _fastcall TArray::CalculateMean(int Var)
{
  int j, n;
  double mean;

  Means.Length = nvars;
  mean = n = 0;
  for (j = 0; j < ncases; j++)
    if (Array[Var - 1][j] != MISSING_DATA) {
      mean += Array[Var - 1][j];
      n++;
    }
  if (n != 0) Means[Var - 1] = mean / n;
  else Means[Var - 1] = MISSING_DATA;
}
//---------------------------------------------------------------------------
void TArray::AddVar(AnsiString name, AnsiString func)
{
  xxx = new double[NCases];

  delete[] xxx;
}
//---------------------------------------------------------------------------


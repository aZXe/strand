//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma hdrstop

#include "GridArray.h"
#include "CalcMFunctions.h"
#include "Logging.h"
#include "Constants.h"
#include "Utils.h"
#include "Maps.h"
#include "VarDescriptionSimple.h"
#include "VarDescriptionSta.h"
#include "VarDescriptionCalc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
class TArrayGlobal
{
public:
  static TArray *_this;
  static TmwArrayArray X;
  static double *xxx;
};
TArray *TArrayGlobal::_this = NULL;
TmwArrayArray TArrayGlobal::X = TmwArrayArray();
double *TArrayGlobal::xxx = NULL;
//---------------------------------------------------------------------------
int GETVARID_gridarray(char *s)
{
  int i;
  static TintIntMap m;

  i = TArrayGlobal::_this->VarByName((AnsiString)s);
  if (i == 0)
    return UNKNOWN_VAR;
  else {
    if (m.count(i))
      return (m[i] + 1) << 1;

    TArrayGlobal::X.Length++;
    for (int j = 0; j < TArrayGlobal::_this->NCases; j++)
      TArrayGlobal::xxx[j] = TArrayGlobal::_this->Cell[i][j + 1];
    TArrayGlobal::X[TArrayGlobal::X.Length - 1] = new mwArray(TArrayGlobal::_this->NCases, 1, TArrayGlobal::xxx);
    m[i] = TArrayGlobal::X.Length - 1;

    return (m[i] + 1) << 1;
  }
}

mwArray GETVARVALUE_gridarray(int i)
{
  return *(TArrayGlobal::X[(i >> 1) - 1]);
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
  int i, j;
  TDoubleArray tmp;

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

  nvars  = 0;
  ncases = 0;

  NVars  = _nvars;
  NCases = _ncases;

  sprintf(format, "%%.%ulf", form);

  isReplaceMissingDataByMean = false;
/*
  tmp.Length = NCases;
  for (i = 0; i < tmp.Length; i++)
    tmp[i] = MISSING_DATA;

  VarDesc.Length = NVars;
  for (i = 0; i < VarDesc.Length; i++) {
    VarDesc[i] = new TSimpleVarDescription("");
    SetVar(tmp, i + 1);
  }*/
}
//---------------------------------------------------------------------------
__fastcall TArray::TArray (TStringGrid *StrGrid, mwArray A, unsigned form)
{
  int i, j;
  TDoubleArray tmp;

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

  nvars  = 0;
  ncases = 0;

  NVars  = A.Size(1);
  NCases = A.Size(2);

  sprintf(format, "%%.%ulf", form);

  isReplaceMissingDataByMean = false;

  tmp.Length = NCases;

//  VarDesc.Length = NVars;
  for (i = 0; i < NVars; i++) {
//    VarDesc[i] = new TSimpleVarDescription("");
    for (j = 0; j < tmp.Length; j++)
      tmp[j] = A(i + 1,j + 1).Double();
    SetVar(tmp, i + 1);
  }
}
//---------------------------------------------------------------------------
__fastcall TArray::~TArray(void)
{
  try {
    if (isDeleteGrid) delete Grid;
    for (int i = 0; i < VarDesc.Length; i++)
      if (VarDesc[i]) delete VarDesc[i];
  }
  __except (EXCEPTION_CONTINUE_EXECUTION) {
    Application->MessageBox("Ошибка в деструкторе типа TArray!", "Ошибка", MB_OK + MB_ICONERROR);
    LogAdd("!!!Ошибка в деструкторе ~TArray");
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
  int i, j;

  if (ACol > nvars || ARow > ncases) {
    NVars  = max(ACol, NVars);
    NCases = max(ARow, NCases);
  }

  if (0 < ACol && 0 < ARow) {
    if (Grid) {
      if (Val != MISSING_DATA)
        Grid->Cells[ACol][ARow] = SFormat(format, Val);
      else
        Grid->Cells[ACol][ARow] = (AnsiString)"";
    }
    Array[ACol - 1][ARow - 1] = Val;
  }
}
//---------------------------------------------------------------------------
AnsiString __fastcall TArray::GetVarName (long Var)
{
  if (0 < Var && Var <= NVars && VarDesc[Var - 1] != NULL)
    return VarDesc[Var - 1]->Name;
  else return "";
}

void __fastcall TArray::SetVarName(long Var, AnsiString name)
{
  int i, j;

  if (Var > nvars)
    NVars = Var;

  if (0 < Var)
    if (Grid)
      Grid->Cells[Var][0] = (AnsiString)name;
    if (VarDesc[Var - 1] == NULL)
      VarDesc[Var - 1] = new TSimpleVarDescription(name.Trim());
    else
      VarDesc[Var - 1]->Name  = name.Trim();
}
//---------------------------------------------------------------------------
AnsiString __fastcall TArray::GetCaseName (long Var)
{
  if (0 < Var && Var <= ncases && Grid)
    return casesnames[Var - 1];
  else return NULL;
}

void __fastcall TArray::SetCaseName (long Var, AnsiString name)
{
  int i, j;

  if (Var > ncases)
    NCases = Var;

  if (0 < Var)
    if (Grid)
      Grid->Cells[0][Var] = (AnsiString)name;
    casesnames[Var - 1] = (AnsiString)name;
}
//---------------------------------------------------------------------------
void __fastcall TArray::SetNVars (long nv)
{
  int i, j;
  long _nvars = nvars;
  TDoubleArray tmp;

  if (Grid) Grid->ColCount = (nvars =  (nv > 0 ? nv : 1)) + 1;
  else nvars =  (nv > 0 ? nv : 1);

  if (nvars < _nvars)
    for (i = nvars; i < _nvars; i++)
      if (VarDesc[i]) delete VarDesc[i];

  Array.Length = nvars;
  for (i = 0; i < Array.Length; i++)
    Array[i].Length = ncases;

  for (i = _nvars; i < nvars; i++)
    for (j = 0; j < ncases; j++)
      Array[i][j] = MISSING_DATA;

  tmp.Length = NCases;
  for (i = 0; i < tmp.Length; i++)
    tmp[i] = MISSING_DATA;

  VarDesc.Length = nvars;
  for (i = _nvars; i < VarDesc.Length; i++) {
    VarDesc[i] = NULL;//new TSimpleVarDescription("");
    SetVar(tmp, i + 1);
  }
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
void __fastcall TArray::SetFormat (unsigned form)
{
  sprintf(format, "%%.%ulf", form);
}
//---------------------------------------------------------------------------
int  __fastcall TArray::OpenStaFile (const char *filename)
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
      VarName[i] = (tmp_str.TrimRight());
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
int  __fastcall TArray::SaveStaFile (const char *filename)
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
      StaSetVarName (hSta, i, VarName[i].c_str());

    StaSetCaseNameLength (hSta, 8);  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    for (j = 1; j <= NCases; j++ )
      StaSetCaseName (hSta, j, CaseName[j].c_str());

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
TDoubleArray TArray::LoadStaVar(AnsiString filename, int var)
{
  TDoubleArray tmp;
  HSTAFILE hSta;
  int i;
  int nv, nc;
  double MD;
  double d;

  tmp.Length = 0;

  hSta = StaOpenFile (filename.c_str());
  if ( hSta == 0 ) {
    Application->MessageBox ("Cannot open requested STATISTICA file !!!", "Error", MB_OK + MB_ICONERROR);
    LogAdd("!!!Ошибка открытия файла данных " + filename);
    return tmp;
  }

  nv = StaGetNVars (hSta);
  nc = StaGetNCases(hSta);

  if (var < 1 || var > nv) {
    Application->MessageBox ("Невозможно загрузить признак из .sta-файла!!!", "Ошибка", MB_OK + MB_ICONERROR);
    LogAdd("!!!Ошибка загрузки переменной #" + IntToStr(var) + " в файле данных " + filename);
    return tmp;
  }

  tmp.Length = nc;

  StaGetVarMD (hSta, var, &MD);
  for (i = 1; i <= nc; i++) {
    StaGetData (hSta, var, i, &d);
    if (d != MD) tmp[i - 1] = d;
    else tmp[i - 1] = MISSING_DATA;
  }

  StaCloseFile(hSta);

  return tmp;
}
//---------------------------------------------------------------------------
int  __fastcall TArray::OpenDescFile (AnsiString filename, bool refresh_data)
{
  TFileStream *stream;
  int i, j, type, count;
  AnsiString sta_file;
  TDoubleArray tmp;

  for (i = 0; i < VarDesc.Length; i++)
    if (VarDesc[i]) delete VarDesc[i];

  VarDesc.Length = 0;

  try {
    stream = new TFileStream(filename, fmOpenRead);

    try {
      stream->Read(&count, sizeof(count));
      NVars = (count > 0) ? count : 0;
      strcpy(format, "%.3lf");
      if (Grid) Grid->ColWidths[0] = 15;
      for (i = 0; i < count; i++) {
//        delete VarDesc[i];
        stream->Read(&type, sizeof(type));
        switch (type) {
          case SIMPLE_VAR:
            VarDesc[i] = new TSimpleVarDescription(stream);
            LoadArray(stream, tmp);
            SetVar(tmp, i + 1, VarDesc[i]->Name);
            break;

          case STA_VAR:
            VarDesc[i] = new TStaVarDescription(stream);
            LoadArray(stream, tmp);
            if (refresh_data)
              tmp = LoadStaVar(dynamic_cast<TStaVarDescription *>(VarDesc[i])->StaFileName,
                               dynamic_cast<TStaVarDescription *>(VarDesc[i])->NumVar);
            SetVar(tmp, i + 1, VarDesc[i]->Name);
            break;

          case CALC_VAR:
            VarDesc[i] = new TCalcVarDescription(stream);
            LoadArray(stream, tmp);
            SetVar(tmp, i + 1, VarDesc[i]->Name);
            break;

          default:
            Application->MessageBox ("Неизвестный тип переменной!!!", "Ошибка", MB_OK + MB_ICONERROR);
            LogAdd("!!!Неизвестный тип переменной (type = " + IntToStr(type) + ")");
            return 0;
        }
      }

      if (refresh_data)
        for (i = 0; i < VarDesc.Length; i++)
          if (VarDesc[i]->GetType() == CALC_VAR)
            SetVar(dynamic_cast<TCalcVarDescription *>(VarDesc[i])->Function,
                   i + 1,
                   VarDesc[i]->Name);
    }
    __finally {
      delete stream;
    }
  }
  catch(...) {
    Application->MessageBox ("Cannot open requested file of descriptions!!!", "Error", MB_OK + MB_ICONERROR);
    LogAdd("!!!Ошибка открытия файла описаний " + (AnsiString)filename);
    return 0;
  }

  return 1;
}
//---------------------------------------------------------------------------
int  __fastcall TArray::SaveDescFile (AnsiString filename, bool save_data)
{
  TFileStream *stream;
  int i, j, type, count = VarDesc.Length;
  TDoubleArray tmp;

  try {
    stream = new TFileStream(filename, fmCreate);

    try {
      stream->Write(&count, sizeof(count));
      for (i = 0; i < count; i++) {
        VarDesc[i]->Save(stream);
        tmp.Length = 0;
        if (save_data)
          tmp = GetVar(i + 1);
        SaveArray(stream, tmp);
      }
    }
    __finally {
      delete stream;
    }
  }
  catch(...) {
    Application->MessageBox ("Cannot create requested file of descriptions!!!", "Error", MB_OK + MB_ICONERROR);
    LogAdd("!!!Ошибка создания файла описаний " + (AnsiString)filename);
    return 0;
  }

  return 1;
}
//---------------------------------------------------------------------------
int  __fastcall TArray::RefreshData (void)
{
  int i, type;
  TDoubleArray tmp;

  for (i = 0; i < VarDesc.Length; i++) {
    type = VarDesc[i]->GetType();
    switch (type) {
      case SIMPLE_VAR:
        break;

      case STA_VAR:
        tmp = LoadStaVar(dynamic_cast<TStaVarDescription *>(VarDesc[i])->StaFileName,
                         dynamic_cast<TStaVarDescription *>(VarDesc[i])->NumVar);
        SetVar(tmp, i + 1, VarDesc[i]->Name);
        break;

      case CALC_VAR:
        break;

      default:
        Application->MessageBox ("Неизвестный тип переменной!!!", "Ошибка", MB_OK + MB_ICONERROR);
        LogAdd("!!!Неизвестный тип переменной (type = " + IntToStr(type) + ")");
        return 0;
    }
  }

  for (i = 0; i < VarDesc.Length; i++)
    if (VarDesc[i]->GetType() == CALC_VAR)
      SetVar(dynamic_cast<TCalcVarDescription *>(VarDesc[i])->Function,
             i + 1,
             VarDesc[i]->Name);
  return 1;
}
//---------------------------------------------------------------------------
int __fastcall TArray::VarByName (const AnsiString varname)
{
  for (int i = 1; i <= NVars; i++) {
    if (VarName[i] == varname)
      return i;
  }

  return 0;
}
//---------------------------------------------------------------------------
void __fastcall TArray::SetData (const TDoubleArray &A)
{
  NVars = 1;
  NCases = A.Length;

  for (long j = 1; j <= A.Length; j++)
    Cell[1][j] = A[j - 1];

//  casesnames.Length = ncases;

  CalculateMeans();
}
//---------------------------------------------------------------------------
void __fastcall TArray::SetData (const T2DoubleArray &A)
{
  NVars = A.Length;
  NCases = A[0].Length;

  for (int i = 1; i <= A.Length; i++)
    for (long j = 1; j <= A[i - 1].Length; j++)
      Cell[i][j] = A[i - 1][j - 1];

//  casesnames.Length = ncases;

  CalculateMeans();
}
//---------------------------------------------------------------------------
T2DoubleArray __fastcall TArray::GetData (void)
{
  return Array;
}
//---------------------------------------------------------------------------
void __fastcall TArray::SetColsNames (const TAnsiStringArray &CN)
{
  if (CN.Length == 0) return;
  for (int i = 1; i <= CN.Length; i++)
    VarName[i] = CN[i - 1];
}
//---------------------------------------------------------------------------
void __fastcall TArray::SetRowsNames (const TAnsiStringArray &RN)
{
  if (RN.Length == 0) return;
  for (int i = 1; i <= RN.Length; i++)
    CaseName[i] = RN[i - 1];
}
//---------------------------------------------------------------------------
void __fastcall TArray::SetNumVars (void)
{
  char buf[20];

  for (int i = 1; i <= NVars; i++)
    VarName[i] = itoa(i, buf, 10);
}
//---------------------------------------------------------------------------
void __fastcall TArray::SetNumCases (void)
{
  char buf[20];

  for (long i = 1; i <= NCases; i++)
    CaseName[i] = itoa(i, buf, 10);
}
//---------------------------------------------------------------------------
void __fastcall TArray::SetVar(TDoubleArray &X, int Var, AnsiString vname)
{
  int i, j;
  long N = X.Length;

  if (N > ncases)
    NCases = N;

  if (Var > nvars)
    NVars = Var;

  if (vname != "") VarName[Var] = vname;
  for (j = 1; j <= X.Length; j++)
    Cell[Var][j] = X[j - 1];
  for (j = X.Length + 1; j <= NCases; j++)
    Cell[Var][j] = MISSING_DATA;
//  Array[Var - 1] = X.Copy();

  CalculateMean(Var);
}
//---------------------------------------------------------------------------
void __fastcall TArray::SetVar(mwArray &X, int Var, AnsiString vname)
{
  int i, j;
  long N = X.Size(2);

  if (N > ncases)
    NCases = N;

  if (Var > nvars)
    NVars = Var;

  if (vname != "") VarName[Var] = vname;
  for (int j = 1; j <= N; j++)
    Cell[Var][j] = X(1, j).Double();
//  Array[Var - 1] = X.Copy();

  CalculateMean(Var);
}
//---------------------------------------------------------------------------
void __fastcall TArray::CalculateMeans(void)
{
  int i, j, n;
  double mean;

  Means.Length = NVars;
  for (i = 0; i < NVars; i++) {
    mean = n = 0;
    for (j = 0; j < NCases; j++)
      if (Array[i][j] != MISSING_DATA) {
        mean += Array[i][j];
        n++;
      }
    if (n != 0) Means[i] = mean / n;
    else Means[i] = MISSING_DATA;
  }
}
//---------------------------------------------------------------------------
void __fastcall TArray::CalculateMean(int Var)
{
  int j, n;
  double mean;

  Means.Length = NVars;
  mean = n = 0;
  for (j = 0; j < NCases; j++)
    if (Array[Var - 1][j] != MISSING_DATA) {
      mean += Array[Var - 1][j];
      n++;
    }
  if (n != 0) Means[Var - 1] = mean / n;
  else Means[Var - 1] = MISSING_DATA;
}
//---------------------------------------------------------------------------
void __fastcall TArray::SetVar(AnsiString func, int Var, AnsiString vname)
{
  mwArray tmp;
  TMCalculate *f;
  int j, N;

  if (Var > nvars)
    NVars = Var;

  delete VarDesc[Var - 1];
  VarDesc[Var - 1] = new TCalcVarDescription(vname, func);
  VarName[Var] = vname;
//  if (vname != "") VarName[Var] = vname;

  TArrayGlobal::xxx = new double[NCases];

  TArrayGlobal::_this = this;
  f = new TMCalculate(func, GETVARID_gridarray, GETVARVALUE_gridarray);
  f->Print("out\\fp_tree.txt");
  tmp = f->Evaluate();

  tmp = tmp(colon());
  N = tmp.Size(1);
  for (int j = 1; j <= N; j++)
    Cell[Var][j] = tmp(j, 1).Double();

  delete f;
  delete[] TArrayGlobal::xxx;

  CalculateMean(Var);
}
//---------------------------------------------------------------------------


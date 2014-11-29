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

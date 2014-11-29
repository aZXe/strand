//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "VarDescriptionCalc.h"
#include "Utils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TCalcVarDescription::TCalcVarDescription(AnsiString _Name, AnsiString _Function)
{
  Name = _Name;
  Function = _Function;
}
//---------------------------------------------------------------------------
__fastcall TCalcVarDescription::TCalcVarDescription(TFileStream *stream)
{
  Load(stream);
}
//---------------------------------------------------------------------------
void TCalcVarDescription::Save(TFileStream *stream)
{
  int itmp = GetType();

  stream->Write(&itmp, sizeof(itmp));
  SaveString(stream, FName);
  SaveString(stream, FFunction);
  SaveString(stream, Description);
}
//---------------------------------------------------------------------------
void TCalcVarDescription::Load(TFileStream *stream)
{
  LoadString(stream, FName);
  LoadString(stream, FFunction);
  LoadString(stream, Description);
}
//---------------------------------------------------------------------------


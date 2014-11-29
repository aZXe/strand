//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "VarDescriptionSimple.h"
#include "Utils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TSimpleVarDescription::TSimpleVarDescription(AnsiString _Name)
{
  Name = _Name;
}
//---------------------------------------------------------------------------
__fastcall TSimpleVarDescription::TSimpleVarDescription(TFileStream *stream)
{
  Load(stream);
}
//---------------------------------------------------------------------------
void TSimpleVarDescription::Save(TFileStream *stream)
{
  int itmp = GetType();

  stream->Write(&itmp, sizeof(itmp));
  SaveString(stream, FName);
  SaveString(stream, Description);
}
//---------------------------------------------------------------------------
void TSimpleVarDescription::Load(TFileStream *stream)
{
  LoadString(stream, FName);
  LoadString(stream, Description);
}
//---------------------------------------------------------------------------

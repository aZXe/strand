//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "VarDescriptionSta.h"
#include "Utils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TStaVarDescription::TStaVarDescription(AnsiString _Name)
{
  Name = _Name;
}
//---------------------------------------------------------------------------
__fastcall TStaVarDescription::TStaVarDescription(TFileStream *stream)
{
  Load(stream);
}
//---------------------------------------------------------------------------
void TStaVarDescription::Save(TFileStream *stream)
{
  int itmp = GetType();

  stream->Write(&itmp, sizeof(itmp));
  SaveString(stream, FName);
  SaveString(stream, Description);
  SaveString(stream, StaFileName);
  stream->Write(&NumVar, sizeof(NumVar));
}
//---------------------------------------------------------------------------
void TStaVarDescription::Load(TFileStream *stream)
{
  LoadString(stream, FName);
  LoadString(stream, Description);
  LoadString(stream, StaFileName);
  stream->Read(&NumVar, sizeof(NumVar));
}
//---------------------------------------------------------------------------

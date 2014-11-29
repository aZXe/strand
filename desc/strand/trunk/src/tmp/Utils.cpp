//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdio.h>
#include <stdarg.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "Utils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
AnsiString SFormat(AnsiString f, ...)
{
  AnsiString buf;
  char *cbuf;
  va_list paramList;

  va_start(paramList, f);
  int size = vsnprintf(NULL, 0, f.c_str(), paramList);
  cbuf = new char[size + 1];
  vsnprintf(cbuf, size + 1, f.c_str(), paramList);
  buf = (AnsiString)cbuf;
//  SetLength(size);
//  return vsnprintf(Data, size, format, paramList);
//  buf.vprintf(f.c_str(), ap);
  va_end(paramList);
  delete[] cbuf;

  return buf;
}
//---------------------------------------------------------------------------
void SaveFont(TFileStream *stream, TFont *font)
{
  int itmp;
  bool btmp;
  TFontPitch Pitch;
  TColor Color;

  itmp = font->Name.Length();
  stream->Write(&itmp, sizeof(itmp));
  stream->Write(font->Name.c_str(), itmp + 1);

  itmp = font->Size;
  stream->Write(&itmp, sizeof(itmp));

  itmp = font->Height;
  stream->Write(&itmp, sizeof(itmp));

  itmp = font->Charset;
  stream->Write(&itmp, sizeof(itmp));

  Pitch = font->Pitch;
  stream->Write(&Pitch, sizeof(Pitch));

  Color = font->Color;
  stream->Write(&Color, sizeof(Color));

  btmp = font->Style.Contains(fsBold);
  stream->Write(&btmp, sizeof(btmp));
  btmp = font->Style.Contains(fsItalic);
  stream->Write(&btmp, sizeof(btmp));
  btmp = font->Style.Contains(fsUnderline);
  stream->Write(&btmp, sizeof(btmp));
  btmp = font->Style.Contains(fsStrikeOut);
  stream->Write(&btmp, sizeof(btmp));
}
//---------------------------------------------------------------------------
void LoadFont(TFileStream *stream, TFont *font)
{
  int itmp;
  bool btmp;
  TFontPitch Pitch;
  TColor Color;
  AnsiString stmp;
  TFontStyles Style;

  stream->Read(&itmp, sizeof(itmp));
  stmp.SetLength(itmp);
  stream->Read(stmp.c_str(), itmp + 1);
  font->Name = stmp;

  stream->Read(&itmp, sizeof(itmp));
  font->Size = itmp;

  stream->Read(&itmp, sizeof(itmp));
  font->Height = itmp;

  stream->Read(&itmp, sizeof(itmp));
  font->Charset = itmp;

  stream->Read(&Pitch, sizeof(Pitch));
  font->Pitch = Pitch;

  stream->Read(&Color, sizeof(Color));
  font->Color = Color;

  Style = TFontStyles();
  stream->Read(&btmp, sizeof(btmp));
  if (btmp) Style << fsBold;
  stream->Read(&btmp, sizeof(btmp));
  if (btmp) Style << fsItalic;
  stream->Read(&btmp, sizeof(btmp));
  if (btmp) Style << fsUnderline;
  stream->Read(&btmp, sizeof(btmp));
  if (btmp) Style << fsStrikeOut;
  font->Style = Style;
}
//---------------------------------------------------------------------------
void SaveString(TFileStream *stream, AnsiString &str)
{
  int itmp;

  itmp = str.Length();
  stream->Write(&itmp, sizeof(itmp));
  stream->Write(str.c_str(), itmp + 1);
}
//---------------------------------------------------------------------------
void LoadString(TFileStream *stream, AnsiString &str)
{
  int itmp;
  AnsiString stmp;

  stream->Read(&itmp, sizeof(itmp));
  stmp.SetLength(itmp);
  stream->Read(stmp.c_str(), itmp + 1);
  str = stmp;
}
//---------------------------------------------------------------------------


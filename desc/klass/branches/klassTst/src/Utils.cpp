//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <stdio.h>
#include <stdarg.h>
#include "Utils.h"

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
#pragma package(smart_init)

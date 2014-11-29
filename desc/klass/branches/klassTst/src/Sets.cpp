//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Sets.h"

//---------------------------------------------------------------------------
#define define_WriteSet(type, Type)                             \
void WriteSet(T##Type##Set &S, AnsiString name)                 \
{                                                               \
  ofstream f(name.c_str());                                     \
  f << S;                                                       \
}                                                               \
                                                                \
void WriteSet(T##Type##Set &S, ofstream &f)                     \
{                                                               \
  f << S;                                                       \
}
//---------------------------------------------------------------------------
define_WriteSet(double, Double)
define_WriteSet(int, Int)
//---------------------------------------------------------------------------
#pragma package(smart_init)

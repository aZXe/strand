//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Maps.h"

#define define_WriteMap(type, Type)                             \
void WriteMap(T##type##Type##Map &M, AnsiString name)           \
{                                                               \
  T##type##Type##MapIterator i;                                 \
  ofstream f(name.c_str());                                     \
                                                                \
  if (M.empty())                                                \
    f << "Empty...";                                            \
  else                                                          \
    for (i = M.begin(); i != M.end(); i++)                      \
      f << (*i).first << "\t" << (*i).second << endl;           \
}                                                               \
                                                                \
void WriteMap(T##type##Type##Map &M, ofstream &f)               \
{                                                               \
  T##type##Type##MapIterator i;                                 \
                                                                \
  if (M.empty())                                                \
    f << "Empty...";                                            \
  else                                                          \
    for (i = M.begin(); i != M.end(); i++)                      \
      f << (*i).first << "\t" << (*i).second << endl;           \
}
//---------------------------------------------------------------------------
define_WriteMap(int,  DoubleSet)
define_WriteMap(int,  IntSet   )
define_WriteMap(long, DoubleSet)
define_WriteMap(long, LongSet  )
define_WriteMap(int,    Int   )
define_WriteMap(int,    Long  )
define_WriteMap(int,    Double)
define_WriteMap(long,   Int   )
define_WriteMap(long,   Long  )
define_WriteMap(long,   Double)
define_WriteMap(double, Int   )
define_WriteMap(double, Long  )
define_WriteMap(double, Double)

define_WriteMap(int,    DoubleArray)
define_WriteMap(int,    IntArray   )
define_WriteMap(long,   DoubleArray)
define_WriteMap(long,   IntArray   )
define_WriteMap(double, DoubleArray)
define_WriteMap(double, IntArray   )

define_WriteMap(int,    Double2Array)
define_WriteMap(int,    Int2Array   )
define_WriteMap(long,   Double2Array)
define_WriteMap(long,   Int2Array   )
define_WriteMap(double, Double2Array)
define_WriteMap(double, Int2Array   )
//---------------------------------------------------------------------------
#pragma package(smart_init)

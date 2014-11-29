//---------------------------------------------------------------------------
#ifndef MapsH
#define MapsH

#include <fstream>
#include <map>
#include "Sets.h"

using namespace std;                          

#define defmap(type, Type, TType)                                       \
typedef map<type, TType, less<type> > T##type##Type##Map;               \
typedef T##type##Type##Map::iterator T##type##Type##MapIterator;        \
void WriteMap(T##type##Type##Map &M, AnsiString name);                  \
void WriteMap(T##type##Type##Map &M, ofstream &f);

defmap(int,    Int,    int   )
defmap(int,    Long,   long  )
defmap(int,    Double, double)
defmap(long,   Int,    int   )
defmap(long,   Long,   long  )
defmap(long,   Double, double)
defmap(double, Int,    int   )
defmap(double, Long,   long  )
defmap(double, Double, double)
defmap(int,  IntSet,    TIntSet   )
defmap(int,  DoubleSet, TDoubleSet)
defmap(long, LongSet,   TLongSet  )
defmap(long, DoubleSet, TDoubleSet)
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------
#ifndef SetsH
#define SetsH

#include <fstream>
#include <set>

using namespace std;

#define union(in1, in2, out)                                            \
  set_union(in1.begin(), in1.end(),                                     \
            in2.begin(), in2.end(),                                     \
            inserter(out, out.begin()))

#define intersection(in1, in2, out)                                     \
  set_intersection(in1.begin(), in1.end(),                              \
                   in2.begin(), in2.end(),                              \
                   inserter(out, out.begin()))

#define difference(in1, in2, out)                                       \
  out.clear();                                                          \
  set_difference(in1.begin(), in1.end(),                                \
                 in2.begin(), in2.end(),                                \
                 inserter(out, out.begin()))

#define symmetric_difference(in1, in2, out)                             \
  out.clear();                                                          \
  set_symmetric_difference(in1.begin(), in1.end(),                      \
                           in2.begin(), in2.end(),                      \
                           inserter(out, out.begin()))

#define defset(type, Type)                                              \
                                                                        \
typedef set<type, less<type> > T##Type##Set;                            \
typedef T##Type##Set::iterator T##Type##SetIterator;                    \
                                                                        \
T##Type##Set operator *(const T##Type##Set &S, const T##Type##Set &T)   \
{                                                                       \
  T##Type##Set I; /* Пересечение */                                     \
  intersection(S, T, I);                                                \
  return I;                                                             \
}                                                                       \
                                                                        \
T##Type##Set operator +(const T##Type##Set &S, const T##Type##Set &T)   \
{                                                                       \
  T##Type##Set I; /* Объединение */                                     \
  union(S, T, I);                                                       \
  return I;                                                             \
}                                                                       \
                                                                        \
T##Type##Set operator -(const T##Type##Set &S, const T##Type##Set &T)   \
{                                                                       \
  T##Type##Set I; /* Разность */                                        \
  difference(S, T, I);                                                  \
  return I;                                                             \
}                                                                       \
                                                                        \
T##Type##Set operator ^(const T##Type##Set &S, const T##Type##Set &T)   \
{                                                                       \
  T##Type##Set I; /* Симметричная разность */                           \
  symmetric_difference(S, T, I);                                        \
  return I;                                                             \
}

defset(double,     Double)
defset(long,       Long  )
defset(int,        Int   )
defset(char,       Char  )
defset(AnsiString, AnsiString)

#define defsetoutput(Type)                                              \
ostream& operator <<(ostream& out_data, T##Type##Set& S)                \
{                                                                       \
   if (S.empty())                                                       \
     out_data << "Empty...";                                            \
   else {                                                               \
     for (T##Type##SetIterator i = S.begin(); i != S.end(); i++)        \
       out_data << *i <<" ";                                            \
     cout << endl;                                                      \
   }                                                                    \
   return out_data;                                                     \
}                                                                       \
                                                                        \
void WriteSet(T##Type##Set &S, AnsiString name);                        \
void WriteSet(T##Type##Set &S, ofstream &f);

defsetoutput(Double)
defsetoutput(Long  )
defsetoutput(Int   )
defsetoutput(Char  )
//---------------------------------------------------------------------------
#endif

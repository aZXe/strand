//---------------------------------------------------------------------------
#ifndef UtilsH
#define UtilsH
//---------------------------------------------------------------------------
#include "DArrayTypes.h"
//---------------------------------------------------------------------------
AnsiString SFormat(AnsiString f, ...);
void SaveFont(TFileStream *stream, TFont *font);
void LoadFont(TFileStream *stream, TFont *font);
void SaveString(TFileStream *stream, AnsiString &str);
void LoadString(TFileStream *stream, AnsiString &str);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
template <class T>
void SaveArray(TFileStream *stream, DynamicArray <T> &A);
template <class T>
void SaveArray(TFileStream *stream, DynamicArray <T> &A)
{
  int itmp;
  T   tmp;

  itmp = A.Length;
  stream->Write(&itmp, sizeof(itmp));

  for (itmp = 0; itmp < A.Length; itmp++) {
    tmp = A[itmp];
    stream->Write(&tmp, sizeof(tmp));
  }
}
//---------------------------------------------------------------------------
template <class T>
void LoadArray(TFileStream *stream, DynamicArray <T> &A);
template <class T>
void LoadArray(TFileStream *stream, DynamicArray <T> &A)
{
  int itmp;
  T   tmp;

  stream->Read(&itmp, sizeof(itmp));
  A.Length = itmp;

  for (itmp = 0; itmp < A.Length; itmp++) {
    stream->Read(&tmp, sizeof(tmp));
    A[itmp] = tmp;
  }
}
//---------------------------------------------------------------------------
template <class T>
void SaveArray(TFileStream *stream, DynamicArray < DynamicArray <T> > &A);
template <class T>
void SaveArray(TFileStream *stream, DynamicArray < DynamicArray <T> > &A)
{
  int itmp;

  itmp = A.Length;
  stream->Write(&itmp, sizeof(itmp));

  for (itmp = 0; itmp < A.Length; itmp++)
    SaveArray(stream, A[i]);
}
//---------------------------------------------------------------------------
template <class T>
void LoadArray(TFileStream *stream, DynamicArray < DynamicArray <T> > &A);
template <class T>
void LoadArray(TFileStream *stream, DynamicArray < DynamicArray <T> > &A)
{
  int itmp;

  stream->Read(&itmp, sizeof(itmp));
  A.Length = itmp;

  for (itmp = 0; itmp < A.Length; itmp++)
    LoadArray(stream, A[i]);
}
//---------------------------------------------------------------------------
#endif

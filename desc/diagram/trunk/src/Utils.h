//---------------------------------------------------------------------------
#ifndef UtilsH
#define UtilsH

AnsiString SFormat(AnsiString f, ...);
void SaveFont(TFileStream *stream, TFont *font);
void LoadFont(TFileStream *stream, TFont *font);
//---------------------------------------------------------------------------
#endif

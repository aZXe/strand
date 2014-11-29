//---------------------------------------------------------------------------
#ifndef UtilsH
#define UtilsH

AnsiString SFormat(AnsiString f, ...);
void SaveFont(TFileStream *stream, TFont *font);
void LoadFont(TFileStream *stream, TFont *font);
void SaveString(TFileStream *stream, AnsiString &str);
void LoadString(TFileStream *stream, AnsiString &str);
//---------------------------------------------------------------------------
#endif

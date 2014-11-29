//---------------------------------------------------------------------------
#ifndef LoggingH
#define LoggingH
//---------------------------------------------------------------------------
void LogOpen(AnsiString name);
void LogAdd(AnsiString LogStr);
void LogSave(void);
void LogClose(void);
bool isActiveData(void);
//---------------------------------------------------------------------------
#endif

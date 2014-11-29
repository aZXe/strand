//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "ChildLogWin.h"
#include "ChildGridWin.h"
#include "Logging.h"

extern TChildLog  *MainChildLog;
extern TChildGrid *MainChildGrid;

static FILE *out;
//---------------------------------------------------------------------------
void LogOpen(AnsiString name)
{
  if (out != NULL)
    fclose(out);
  if (FileExists(name)) {
    MainChildLog->Memo1->Lines->LoadFromFile(name);
    out = fopen(name.c_str(), "a");
  }
  else
    out = fopen(name.c_str(), "w");
}
//---------------------------------------------------------------------------
void LogAdd(AnsiString LogStr)
{
  MainChildLog->Memo1->Lines->Add(LogStr);
  fprintf(out, "%s\n", LogStr.c_str());
}
//---------------------------------------------------------------------------
void LogSave(void)
{
//  flush(out);
}
//---------------------------------------------------------------------------
void LogClose(void)
{
  fclose(out);
}
//---------------------------------------------------------------------------
bool isActiveData(void)
{
  if (MainChildGrid == NULL) {
    LogAdd("!!!Не открыт файл данных");
    return false;
  }
  else return true;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)

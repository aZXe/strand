//----------------------------------------------------------------------------
#ifndef VarDescriptionStaH
#define VarDescriptionStaH
//----------------------------------------------------------------------------
#include "Constants.h"
#include "VarDescription.h"
//----------------------------------------------------------------------------
class TStaVarDescription : public TVarDescription
{
private:

protected:

public:
  AnsiString StaFileName; // Имя файла статистики
  int NumVar; // Номер переменной в файле статистики

  __fastcall TStaVarDescription(AnsiString _Name);
  __fastcall TStaVarDescription(TFileStream *stream);
//  __fastcall ~TStaVarDescription(void);

  virtual inline int GetType(void) const {return STA_VAR;};
  virtual void Save(TFileStream *stream);
  virtual void Load(TFileStream *stream);
};
//----------------------------------------------------------------------------
#endif


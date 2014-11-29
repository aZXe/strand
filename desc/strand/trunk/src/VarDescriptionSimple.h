//----------------------------------------------------------------------------
#ifndef VarDescriptionSimpleH
#define VarDescriptionSimpleH
//----------------------------------------------------------------------------
#include "Constants.h"
#include "VarDescription.h"
//----------------------------------------------------------------------------
class TSimpleVarDescription : public TVarDescription
{
private:

protected:

public:
  __fastcall TSimpleVarDescription(AnsiString _Name);
  __fastcall TSimpleVarDescription(TFileStream *stream);
//  __fastcall ~TSimpleVarDescription(void);

  virtual inline int GetType(void) const {return SIMPLE_VAR;};
  virtual void Save(TFileStream *stream);
  virtual void Load(TFileStream *stream);
};
//----------------------------------------------------------------------------
#endif


//----------------------------------------------------------------------------
#ifndef VarDescriptionCalcH
#define VarDescriptionCalcH
//----------------------------------------------------------------------------
#include "Constants.h"
#include "VarDescription.h"
//----------------------------------------------------------------------------
class TCalcVarDescription : public TVarDescription
{
private:

protected:
  AnsiString FFunction;

  virtual AnsiString GetFunction(void) {return FFunction;};
  virtual void SetFunction(AnsiString newFunction)
    {if (newFunction != "") FFunction = newFunction;};

public:
  __fastcall TCalcVarDescription(AnsiString _Name, AnsiString _Function);
  __fastcall TCalcVarDescription(TFileStream *stream);
//  __fastcall ~TCalcVarDescription(void);

  __property AnsiString Function = {read=GetFunction, write=SetFunction};
  virtual inline int GetType(void) const {return CALC_VAR;};
  virtual void Save(TFileStream *stream);
  virtual void Load(TFileStream *stream);
  virtual TCalcVarDescription& operator =(const TCalcVarDescription& V) {
    if (this == &V) return *this;

    this->FName = V.FName;
    this->FFunction = V.FFunction;
    this->Description = V.Description;

    return *this;
  }
};
//----------------------------------------------------------------------------
#endif


//----------------------------------------------------------------------------
#ifndef VarDescriptionH
#define VarDescriptionH
//----------------------------------------------------------------------------
#include <sysdyn.h>
//----------------------------------------------------------------------------
class TVarDescription
{
private:

protected:
  AnsiString FName;

  virtual AnsiString GetName(void) {return FName;};
  virtual void SetName(AnsiString newName) {FName = newName;};

public:
//  __fastcall TVarDescription();
//  __fastcall ~TVarDescription(void);
  AnsiString Description;

  __property AnsiString Name = {read=GetName, write=SetName};
  virtual inline int GetType(void) = 0;
  virtual void Save(TFileStream *stream) = 0;
  virtual void Load(TFileStream *stream) = 0;
};
//----------------------------------------------------------------------------
typedef DynamicArray < TVarDescription * > TVarDescriptionArray;
//----------------------------------------------------------------------------
#endif

 
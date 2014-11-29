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
  virtual inline int GetType(void) const = 0;
  virtual void Save(TFileStream *stream) = 0;
  virtual void Load(TFileStream *stream) = 0;
  virtual TVarDescription& operator =(const TVarDescription& V) {
    if (this == &V) return *this;

    this->FName = V.FName;
    this->Description = V.Description;

    return *this;
  }
};
//----------------------------------------------------------------------------
typedef DynamicArray < TVarDescription * > TVarDescriptionArray;
//----------------------------------------------------------------------------
#endif

 
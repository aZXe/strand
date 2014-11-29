//---------------------------------------------------------------------------
#ifndef RombH
#define RombH

#include "Constants.h"
#include "Block.h"
#include "Element.h"
//---------------------------------------------------------------------------
class TRomb : public TBlock
{
public:
  TRomb(TCanvas **_C, int _X, int _Y, TDArrayElement *_Elements,
        TElementProperty *_Property);
  TRomb(TCanvas **_C, TFileStream *stream, TDArrayElement *_Elements,
        TElementProperty *_Property);
  ~TRomb(void);
  void Draw(void);
  inline int GetType(void) const {return TROMB;};
protected:
};
//---------------------------------------------------------------------------
#endif


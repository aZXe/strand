//---------------------------------------------------------------------------
#ifndef RombIndicatorH
#define RombIndicatorH

#include "BlockIndicator.h"
#include "Element.h"
//---------------------------------------------------------------------------
class TRombIndicator : public TBlockIndicator
{
public:
  TRombIndicator(TCanvas **_C, int _X, int _Y, TDArrayElement *_Elements,
                 bool _IndicatorVisible = false, TElementProperty *_Property = NULL);
  TRombIndicator(TCanvas **_C, TFileStream *stream, TDArrayElement *_Elements,
                 TElementProperty *_Property = NULL);
  ~TRombIndicator(void);
  void Draw(void);
  inline int GetType(void) const {return TROMBINDICATOR;};
protected:
};
//---------------------------------------------------------------------------
#endif


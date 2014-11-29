//---------------------------------------------------------------------------
#ifndef BlockIndicatorH
#define BlockIndicatorH

#include "Constants.h"
#include "Block.h"
#include "Element.h"
//---------------------------------------------------------------------------
#define MAX_INDICATOR_WIDTH         15
//---------------------------------------------------------------------------
class TBlockIndicator : public TBlock
{
public:
  TBlockIndicator(TCanvas **_C, int _X, int _Y, TDArrayElement *_Elements,
                  bool _IndicatorVisible = false, TElementProperty *_Property = NULL);
  TBlockIndicator(TCanvas **_C, TFileStream *stream, TDArrayElement *_Elements,
                  TElementProperty *_Property = NULL);
  ~TBlockIndicator(void);

  __property double IndicatorPosition = {read=position, write=SetPosition};

  bool IndicatorVisible;
  TColor ColorIndicatorBackground,
         ColorIndicatorForeground;

  virtual void Draw(void);
  virtual inline int GetType(void) const {return TBLOCKINDICATOR;};
  virtual void Save(TFileStream * stream);
  virtual void Load(TFileStream * stream);

protected:
  void SetPosition(double NewPosition);

private:
  double position;
};
//---------------------------------------------------------------------------
#endif


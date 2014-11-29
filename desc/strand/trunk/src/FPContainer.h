//---------------------------------------------------------------------------
#ifndef FPContainerH
#define FPContainerH

#include "Constants.h"
#include "Container.h"
//---------------------------------------------------------------------------
class TFPContainer : public TContainer
{
private:
  short AllocationType;

protected:

public:
  TRomb *FPRomb;

  __fastcall TFPContainer(TComponent* Owner);
  __fastcall ~TFPContainer(void);

  virtual void __fastcall _OnMouseMove(TObject *Sender, TShiftState Shift,
        int X, int Y);
  virtual void __fastcall _OnDblClick(TObject *Sender);

  void ArrangeElements(void);
  void SetAllocationType(short NewAllocationType);

  void ClearInformation(void);

  void DeleteAllVars(void);
  bool ContainVar(AnsiString name);

  const TElement *GetActiveElement();
  const TDArrayElement *GetElements();
};

//---------------------------------------------------------------------------
#endif

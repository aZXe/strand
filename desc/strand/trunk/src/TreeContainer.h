//---------------------------------------------------------------------------
#ifndef TreeContainerH
#define TreeContainerH

#include "Constants.h"
#include "Container.h"
#include "Maps.h"

typedef DynamicArray < TintIntSetMap > tree_struct;
typedef DynamicArray < T2DoubleArray > T3DoubleArray;

//---------------------------------------------------------------------------
class TTreeContainer : public TContainer
{
private:
  short AllocationType;

  void CreateBranch(TBlockIndicator *b, int ib);
  int  GetBoundingSize(TBlockIndicator *b);
  void SetPosition(TBlockIndicator *b, int x, int y);
protected:

public:
  __fastcall TTreeContainer(TComponent* Owner);
  __fastcall ~TTreeContainer(void);

  virtual void __fastcall _OnMouseMove(TObject *Sender, TShiftState Shift,
        int X, int Y);
  virtual void __fastcall _OnDblClick(TObject *Sender);

  void ArrangeElements(void);
  void SetAllocationType(short NewAllocationType);

  void SetIndicatorVisible(bool Visible);

  void ClearInformation(void);

  void DeleteAllVars(void);
  bool ContainVar(AnsiString name);

  const TElement *GetActiveElement();
  const TDArrayElement *GetElements();

  bool color_elements;

  int main_elem;
  tree_struct elems;
  T3DoubleArray values;
};

//---------------------------------------------------------------------------
#endif

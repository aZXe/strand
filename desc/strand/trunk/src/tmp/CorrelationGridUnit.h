//---------------------------------------------------------------------------
#ifndef CorrelationGridUnitH
#define CorrelationGridUnitH
//---------------------------------------------------------------------------
#include "GridArray.h"
#include "Sets.h"
//---------------------------------------------------------------------------
class TCorrelationGrid : public TStringGrid
{
private:
  TArray *A;
  TIntSet *Vars;
  double FLimit;
  bool FIsColor, FIsNumbers;
  void CreateVerticalFont(void);

protected:
  void __fastcall _OnDrawCell(TObject *Sender, int ACol, int ARow,
                              TRect &Rect, TGridDrawState State);

  void __fastcall SetIsColor(bool isColor);
  void __fastcall SetIsNumbers(bool isNumbers);
  void __fastcall SetLimit(double new_limit);

public:
  TFont *VerticalFont, *DefaultFont;

  __fastcall TCorrelationGrid(TArray *_A, TIntSet *_Vars, Classes::TComponent* AOwner);
  __fastcall ~TCorrelationGrid(void);

  __property bool   IsColor   = {read=FIsColor,   write=SetIsColor  };
  __property bool   IsNumbers = {read=FIsNumbers, write=SetIsNumbers};
  __property double Limit     = {read=FLimit,     write=SetLimit    };
};

//---------------------------------------------------------------------------
#endif

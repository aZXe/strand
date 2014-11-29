//---------------------------------------------------------------------------
#ifndef ElementPropertyUH
#define ElementPropertyUH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

#include "Element.h"
//---------------------------------------------------------------------------
class TElement;
//---------------------------------------------------------------------------
class TElementProperty : public TForm
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
  TElement *e;

  __fastcall TElementProperty(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif

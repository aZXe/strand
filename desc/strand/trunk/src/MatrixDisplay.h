//---------------------------------------------------------------------------
#ifndef MatrixDisplayH
#define MatrixDisplayH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <stdlib.h>
#include "GridArray.h"
//---------------------------------------------------------------------------
class TfrmMatrixDisplay : public TForm
{
__published:	// IDE-managed Components
        TStringGrid *Grid;
private:	// User declarations
public:		// User declarations
        __fastcall TfrmMatrixDisplay(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMatrixDisplay *frmMatrixDisplay;
//---------------------------------------------------------------------------
void MatrixDisplay(TDoubleArray A, char *title);

#endif

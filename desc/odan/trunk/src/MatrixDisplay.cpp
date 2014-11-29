//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MatrixDisplay.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TfrmMatrixDisplay::TfrmMatrixDisplay(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void MatrixDisplay(TDoubleArray A, char *title)
{
  static int xx, yy;
  TfrmMatrixDisplay *frmMatrixDisplay;
  TArray *AA;

  frmMatrixDisplay = new TfrmMatrixDisplay(NULL);
  AA = new TArray(frmMatrixDisplay->Grid);

  AA->SetData(A);
  AA->SetNumCases();
  AA->SetNumVars();

  frmMatrixDisplay->Caption = (AnsiString)title;
  frmMatrixDisplay->Show();

  if ((xx += 20) > (Screen->Width  / 2)) xx = 0;
  if ((yy += 20) > (Screen->Height / 2)) yy = 0;
  frmMatrixDisplay->Left = xx;
  frmMatrixDisplay->Top  = yy;

//  delete AA;
}
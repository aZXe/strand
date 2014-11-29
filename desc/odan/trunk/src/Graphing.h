//---------------------------------------------------------------------------
#ifndef GraphingH
#define GraphingH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

#include "DArrayTypes.h"
#include <Dialogs.hpp>
//#include "GridArray.h"

#define SCATTERPLOT     1
#define LINEPLOT        2
//---------------------------------------------------------------------------
class TGraph : public TForm
{
__published:	// IDE-managed Components
        TButton *btnSave;
        TPanel *Panel;
        TImage *Image;
        TSaveDialog *SaveDialog;
        void __fastcall btnSaveClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
//        void __fastcall TimerTimer(TObject *Sender);
private:
  T2DoubleArray XY;
  TLongArray Colors;
  TCharArray Types;
  int Count;
  double minx, maxx, miny, maxy;
  char XText[11], YText[11];
  char Captions[2][41];
public:
  __fastcall TGraph(TComponent* Owner, TDoubleArray &X, TDoubleArray &Y,
                    long color, char Type = LINEPLOT, const char *_Caption = " ",
                    const char *_XText = "", const char *_YText = "");
  void __fastcall AddGraph(TDoubleArray &X, TDoubleArray &Y,
                           long color, char Type = LINEPLOT);
  void __fastcall Draw(void);
  void __fastcall SaveGraph(AnsiString name)
    {Image->Picture->Bitmap->SaveToFile(name);}
};

void __fastcall InitGraph(void);
int  __fastcall NewGraph(TDoubleArray &X, TDoubleArray &Y,
                    long color, char Type = LINEPLOT, const char *_Caption = " ",
                    const char *_XText = "", const char *_YText = "");
void __fastcall AddGraph(int ind, TDoubleArray &X, TDoubleArray &Y,
                         long color, char Type = LINEPLOT);
void __fastcall SaveGraph(int ind, AnsiString name);
void __fastcall DeleteGraph(int ind);
void __fastcall DeleteGraphs(void);
//---------------------------------------------------------------------------
extern PACKAGE TGraph *Graph;
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------
#ifndef GraphingChartH
#define GraphingChartH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

#include "DArrayTypes.h"
#include <Dialogs.hpp>
#include <Chart.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
//#include "GridArray.h"

#define SCATTERPLOT     1
#define LINEPLOT        2
#define RADARPLOT       3
//---------------------------------------------------------------------------
class TGraph : public TForm
{
__published:	// IDE-managed Components
        TButton *btnSave;
        TSaveDialog *SaveDialog;
        TChart *Chart1;
        void __fastcall btnSaveClick(TObject *Sender);
//        void __fastcall TimerTimer(TObject *Sender);
public:
  __fastcall TGraph(TComponent* Owner);
  __fastcall TGraph(TComponent* Owner, TDoubleArray &X, TDoubleArray &Y,
                    long color, char Type = LINEPLOT, const char *_Caption = " ",
                    const char *_XText = "", const char *_YText = "", bool isBold = false);
  void __fastcall AddGraph(TDoubleArray &X, TDoubleArray &Y, long color,
                           char Type = LINEPLOT, const char *_Caption = " ", bool isBold = false);
  void __fastcall AddTitle(const char *_Caption);
  void __fastcall SaveGraph(AnsiString name);
  void __fastcall MakeLastGraphBold(void);
};

//---------------------------------------------------------------------------
extern PACKAGE TGraph *Graph;
//---------------------------------------------------------------------------
#endif

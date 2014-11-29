//---------------------------------------------------------------------------
#ifndef ThreeGraphingChartH
#define ThreeGraphingChartH
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
#include "GraphingChart.h"
//#include "GridArray.h"
//---------------------------------------------------------------------------
class TThreeGraph : public TGraph
{
__published:	// IDE-managed Components
//  TSaveDialog *SaveDialog1;
  TChart *Chart2;
  TChart *Chart3;
  TButton *Button2;
  TButton *Button1;
  void __fastcall btnSave1Click(TObject *Sender);
  void __fastcall FormResize(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
public:
  __fastcall TThreeGraph(TComponent* Owner);
  __fastcall TThreeGraph(TComponent* Owner, TDoubleArray &X, TDoubleArray &Y,
                    long color, char Type = LINEPLOT, const char *_Caption = " ",
                    const char *_XText = "", const char *_YText = "",
                    bool isBold = false, unsigned char position = 1);
  void __fastcall AddGraph(TDoubleArray &X, TDoubleArray &Y, long color,
                           char Type = LINEPLOT, const char *_Caption = " ",
                           bool isBold = false, unsigned char position = 1);
  void __fastcall AddTitle(const char *_Caption, unsigned char position = 1);
  void __fastcall SaveGraph(AnsiString name, unsigned char position = 1);
  void __fastcall MakeLastGraphBold(void);
};

//---------------------------------------------------------------------------
extern PACKAGE TThreeGraph *ThreeGraph;
//---------------------------------------------------------------------------
#endif

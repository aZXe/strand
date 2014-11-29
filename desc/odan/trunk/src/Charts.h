//---------------------------------------------------------------------------
#ifndef ChartsH
#define ChartsH
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
#include "GraphingThreeChart.h"
//#include "GridArray.h"
//---------------------------------------------------------------------------
class TChartArray
{
private:
  int num;
  DynamicArray < TGraph * > G;
  static TChartArray* instance;
public:
//  __fastcall GetInstance();
  void __fastcall InitGraph(void);
  int  __fastcall NewGraph(TDoubleArray &X, TDoubleArray &Y,
                          long color, char Type = LINEPLOT, const char *_Caption = " ",
                          const char *_XText = "", const char *_YText = "",
                          bool isBold = false, unsigned char position = 0);
  void __fastcall AddGraph(int ind, TDoubleArray &X, TDoubleArray &Y, long color,
                           char Type = LINEPLOT, const char *_Caption = " ", bool
                           isBold = false,  unsigned char position = 0);
  void __fastcall AddTitle(int ind, const char *_Caption, unsigned char position = 0);
  void __fastcall MakeLastGraphBold(int ind);
  void __fastcall SaveGraph(int ind, AnsiString name, unsigned char position = 0);
  void __fastcall DeleteGraph(int ind);
  void __fastcall DeleteGraphs(void);
};
//---------------------------------------------------------------------------
#endif

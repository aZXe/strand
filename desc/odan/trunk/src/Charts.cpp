//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <string.h>
#include <values.h>
//#include <math.hpp>
#pragma hdrstop
#include "Charts.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
/*__fastcall TChartArray::TChartArray()
{
  if(instance == NULL) {
    instance = new TChartArray();
    num = -1;
  }
}*/
//---------------------------------------------------------------------------
void __fastcall TChartArray::InitGraph(void)
{
  num = 0;
  G.Length = 1;
  G[0] = NULL;
}
//---------------------------------------------------------------------------
int  __fastcall TChartArray::NewGraph(TDoubleArray &X, TDoubleArray &Y,
                    long color, char Type, const char *_Caption,
                    const char *_XText, const char *_YText, bool isBold, unsigned char position)
{
  static int xx, yy;
  int i, ind = -1;

  if (num == -1) return -1;

  for (i = 0; i < G.Length; i++)
    if (G[i] == NULL) {
      ind = i;
      break;
    }
  if (ind == -1) {
    ind = G.Length;
    G.Length = G.Length + 1;
  }
  num++;
  if ((position == 1) || (position == 2) || (position == 3)) {
    G[ind] = new TThreeGraph(dynamic_cast <TComponent *>(Application->MainForm),
                            X, Y, color, Type, _Caption, _XText, _YText, isBold, position);
  } else {
    G[ind] = new TGraph(dynamic_cast <TComponent *>(Application->MainForm),
                        X, Y, color, Type, _Caption, _XText, _YText, isBold);
  };
  G[ind]->Caption = (AnsiString)"Graph " + CurrToStr(num);
  if ((xx += 20) > (Screen->Width  / 2)) xx = 0;
  if ((yy += 20) > (Screen->Height / 2)) yy = 0;
  G[ind]->Left = xx;
  G[ind]->Top  = yy;
  G[ind]->Show();

  return ind;
}
//---------------------------------------------------------------------------
void __fastcall TChartArray::AddGraph(int ind, TDoubleArray &X, TDoubleArray &Y, long color,
                         char Type, const char *_Caption, bool isBold, unsigned char position)
{
  if (ind >= G.Length) return;
  if (num != -1 && G[ind]) {
    if ((position == 1) || (position == 2) || (position == 3)) {
      ((TThreeGraph*)G[ind])->AddGraph(X, Y, color, Type, _Caption, isBold, position);
    } else {
      G[ind]->AddGraph(X, Y, color, Type, _Caption, isBold);
    };
  };
}
//---------------------------------------------------------------------------
void __fastcall TChartArray::AddTitle(int ind, const char *_Caption, unsigned char position)
{
  if (ind >= G.Length) return;
  if (num != -1 && G[ind]) {
    if ((position == 1) || (position == 2) || (position == 3)) {
      ((TThreeGraph*)G[ind])->AddTitle(_Caption, position);
    } else {
      G[ind]->AddTitle(_Caption);
    };
  }
}
//---------------------------------------------------------------------------
void __fastcall TChartArray::MakeLastGraphBold(int ind)
{
  if (ind >= G.Length) return;
  if (num != -1 && G[ind]) G[ind]->MakeLastGraphBold();
}
//---------------------------------------------------------------------------
void __fastcall TChartArray::DeleteGraph(int ind)
{
  if (ind >= G.Length) return;
  if (num != -1 && G[ind]) delete G[ind];
}
//---------------------------------------------------------------------------
void __fastcall TChartArray::DeleteGraphs(void)
{
  if (num == 1) return;

  for (int i = 0; i < G.Length; i++)
    if (G[i]) delete G[i];
}
//---------------------------------------------------------------------------
void __fastcall TChartArray::SaveGraph(int ind, AnsiString name, unsigned char position)
{
  if (ind >= G.Length) return;
  if (num != -1 && G[ind]) {
    if ((position == 1) || (position == 2) || (position == 3)) {
      ((TThreeGraph*)G[ind])->SaveGraph(name, position);
    } else {
      G[ind]->SaveGraph(name);
    };
  }
}
//---------------------------------------------------------------------------

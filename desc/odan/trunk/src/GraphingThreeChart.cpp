//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <string.h>
#include <values.h>
//#include <math.hpp>
#pragma hdrstop
#include "GraphingThreeChart.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TThreeGraph *ThreeGraph;
//---------------------------------------------------------------------------
__fastcall TThreeGraph::TThreeGraph(TComponent* Owner) : TGraph(Owner)
{
  Chart1->Align = alTop;
  Chart2->Align = alTop;
  Chart3->Align = alTop;
  Chart1->Anchors.Contains(akLeft + akTop + akRight);
  Chart2->Anchors.Contains(akLeft + akTop + akRight);
  Chart3->Anchors.Contains(akLeft + akTop + akRight);
  Constraints->MinHeight = 540;
  Constraints->MinWidth = 180;
  FormResize(this);
}
//---------------------------------------------------------------------------
__fastcall TThreeGraph::TThreeGraph(TComponent* Owner, TDoubleArray &X, TDoubleArray &Y,
                                    long color, char Type, const char *_Caption,
                                    const char *_XText, const char *_YText, bool isBold,
                                    unsigned char position) : TGraph(Owner)
{
  TChart *ChartPtr;
  char *p;
  int num = -1;
  p = strtok((char *)_Caption, "|\0");

  if (position == 2) {
    ChartPtr = Chart2;
  } else if (position == 3) {
    ChartPtr = Chart3;
  } else {
     TGraph::AddGraph(X, Y, color, Type, _Caption, isBold);
  }

  if ((position == 2) || (position == 3)) {

    ChartPtr->Title->Text->Clear();

    while (p) {
      ChartPtr->Title->Text->Add((AnsiString)p);
      p = strtok(NULL, "|");
    }

    if (Type == SCATTERPLOT) {
      TPointSeries *s = new TPointSeries(ChartPtr);
      s->ParentChart = ChartPtr;
      s->SeriesColor = (TColor)color;
      s->ShowInLegend = false;
      s->Pointer->Style = psCircle;
      s->Pointer->Brush->Color = clWhite;
      ChartPtr->AddSeries(s);
    }
    else {
      TFastLineSeries *s = new TFastLineSeries(ChartPtr);
      s->ParentChart = ChartPtr;
      s->SeriesColor = (TColor)color;
      if (isBold) s->LinePen->Width = 2 * s->LinePen->Width;
      ChartPtr->AddSeries(s);
    }

    int j = ChartPtr->SeriesCount() - 1;

    for (long i = 0; i < X.Length; i++)
      ChartPtr->Series[j]->AddXY(X[i], Y[i], "", clTeeColor);

    ChartPtr->BottomAxis->Title->Caption = (AnsiString)_XText;
    ChartPtr->LeftAxis->Title->Caption = (AnsiString)_YText;
  }
  FormResize(this);
}
//---------------------------------------------------------------------------
void __fastcall TThreeGraph::btnSave1Click(TObject *Sender)
{
  if (SaveDialog->Execute() == TRUE) {
    if (true) {
      Chart1->SaveToMetafile(SaveDialog->FileName);
    } else if (false) {
      Chart2->SaveToMetafile(SaveDialog->FileName);
    } else if (false) {
      Chart3->SaveToMetafile(SaveDialog->FileName);
    };
  };
}
//---------------------------------------------------------------------------
void __fastcall TThreeGraph::AddGraph(TDoubleArray &X, TDoubleArray &Y, long color,
                                 char Type, const char *_Caption, bool isBold,
                                 unsigned char position)
{
  TChart *ChartPtr;

  if (position == 2) {
    ChartPtr = Chart2;
  } else if (position == 3) {
    ChartPtr = Chart3;
  } else {
    TGraph::AddGraph(X, Y, color, Type, _Caption, isBold);
  }

  if ((position == 2) || (position == 3)) {

    if (Type == SCATTERPLOT) {
      TPointSeries *s = new TPointSeries(ChartPtr);
      s->ParentChart = ChartPtr;
      s->SeriesColor = (TColor)color;
      s->Pointer->Style = psCircle;
      s->Pointer->Brush->Color = clWhite;
      ChartPtr->AddSeries(s);
    }
    else {
      TFastLineSeries *s = new TFastLineSeries(ChartPtr);
      s->ParentChart = ChartPtr;
      s->SeriesColor = (TColor)color;
      if (isBold) s->LinePen->Width = 2 * s->LinePen->Width;
      ChartPtr->AddSeries(s);
    }

    int j = ChartPtr->SeriesCount() - 1;

    for (long i = 0; i < X.Length; i++)
      ChartPtr->Series[j]->AddXY(X[i], Y[i], "", clTeeColor);

    if ((AnsiString)_Caption != " ") {
      char *p;

      p = strtok((char *)_Caption, "|\0");
      while (p) {
        ChartPtr->Title->Text->Add((AnsiString)p);
        p = strtok(NULL, "|");
      }
    }
    ChartPtr->Repaint();
  }
  FormResize(this);
}
//---------------------------------------------------------------------------
void __fastcall TThreeGraph::AddTitle(const char *_Caption, unsigned char position)
{
  TChart *ChartPtr;
  char *p;

  if (position == 2) {
    ChartPtr = Chart2;
  } else if (position == 3) {
    ChartPtr = Chart3;
  } else {
    TGraph::AddTitle(_Caption);
  }

  if ((position == 2) || (position == 3)) {
    p = strtok((char *)_Caption, "|\0");
    while (p) {
      ChartPtr->Title->Text->Add((AnsiString)p);
      p = strtok(NULL, "|");
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TThreeGraph::MakeLastGraphBold(void)
{
/*
  int j = Chart1->SeriesCount() - 1;
  TFastLineSeries *tmp;
  if (Chart1->Series[j]->SameClass(tmp))
    dynamic_cast <TFastLineSeries *> (Chart1->Series[j])->LinePen->Width *= 2;
*/
}
//---------------------------------------------------------------------------
void __fastcall TThreeGraph::FormResize(TObject *Sender)
{
//
  int ChartHeigh = ClientHeight/3;
  Chart1->Align = alTop;
  Chart1->Width = ClientWidth;
  Chart2->Width = ClientWidth;
  Chart3->Width = ClientWidth;
  Chart1->Height = ChartHeigh;
  Chart2->Height = ChartHeigh;
  Chart3->Height = ChartHeigh;
  Chart2->Top = ChartHeigh;
  Chart3->Top = ChartHeigh*2;
  Chart1->Repaint();
  Chart2->Repaint();
  Chart3->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TThreeGraph::FormShow(TObject *Sender)
{
  FormResize(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TThreeGraph::SaveGraph(AnsiString name, unsigned char position)
{
  TChart *ChartPtr;

  if (position == 2) {
    ChartPtr = Chart2;
  } else if (position == 3) {
    ChartPtr = Chart3;
  } else {
    TGraph::SaveGraph(name);
  }

  if ((position == 2) || (position == 3)) {
    ChartPtr->SaveToMetafile(name);
  };
}
//---------------------------------------------------------------------------

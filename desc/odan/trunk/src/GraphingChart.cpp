//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <string.h>
#include <values.h>
//#include <math.hpp>
#pragma hdrstop

#include "GraphingChart.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TGraph *Graph;
//---------------------------------------------------------------------------
__fastcall TGraph::TGraph(TComponent* Owner) : TForm(Owner)
{
//
}
//---------------------------------------------------------------------------
__fastcall TGraph::TGraph(TComponent* Owner, TDoubleArray &X, TDoubleArray &Y,
                         long color, char Type, const char *_Caption,
                         const char *_XText, const char *_YText, bool isBold)
        : TForm(Owner)
{
  char *p;
//  int num = -1;
  Chart1->Title->Text->Clear();
  p = strtok((char *)_Caption, "|\0");
  while (p) {
    Chart1->Title->Text->Add((AnsiString)p);
    p = strtok(NULL, "|");
  }

  if (Type == SCATTERPLOT) {
    TPointSeries *s = new TPointSeries(Chart1);
    s->ParentChart = Chart1;
    s->SeriesColor = (TColor)color;
    s->ShowInLegend = false;
    s->Pointer->Style = psCircle;
    s->Pointer->Brush->Color = clWhite;
    Chart1->AddSeries(s);
  }
  else {
    TFastLineSeries *s = new TFastLineSeries(Chart1);
    s->ParentChart = Chart1;
    s->SeriesColor = (TColor)color;
    if (isBold) s->LinePen->Width = 2 * s->LinePen->Width;
    Chart1->AddSeries(s);
  }

  int j = Chart1->SeriesCount() - 1;

  for (long i = 0; i < X.Length; i++)
    Chart1->Series[j]->AddXY(X[i], Y[i], "", clTeeColor);

  Chart1->BottomAxis->Title->Caption = (AnsiString)_XText;
  Chart1->LeftAxis->Title->Caption = (AnsiString)_YText;

  Chart1->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TGraph::btnSaveClick(TObject *Sender)
{
  if (SaveDialog->Execute() == TRUE)
    Chart1->SaveToMetafile(SaveDialog->FileName);
}
//---------------------------------------------------------------------------
void __fastcall TGraph::AddGraph(TDoubleArray &X, TDoubleArray &Y, long color,
                                 char Type, const char *_Caption, bool isBold)
{
  if (Type == SCATTERPLOT) {
    TPointSeries *s = new TPointSeries(Chart1);
    s->ParentChart = Chart1;
    s->SeriesColor = (TColor)color;
    s->Pointer->Style = psCircle;
    s->Pointer->Brush->Color = clWhite;
    Chart1->AddSeries(s);
  }
  else {
    TFastLineSeries *s = new TFastLineSeries(Chart1);
    s->ParentChart = Chart1;
    s->SeriesColor = (TColor)color;
    if (isBold) s->LinePen->Width = 2 * s->LinePen->Width;
    Chart1->AddSeries(s);
  }

  int j = Chart1->SeriesCount() - 1;

  for (long i = 0; i < X.Length; i++)
    Chart1->Series[j]->AddXY(X[i], Y[i], "", clTeeColor);

  if ((AnsiString)_Caption != " ") {
    char *p;

    p = strtok((char *)_Caption, "|\0");
    while (p) {
      Chart1->Title->Text->Add((AnsiString)p);
      p = strtok(NULL, "|");
    }
  }

  Chart1->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TGraph::AddTitle(const char *_Caption)
{
  char *p;

  p = strtok((char *)_Caption, "|\0");
  while (p) {
    Chart1->Title->Text->Add((AnsiString)p);
    p = strtok(NULL, "|");
  }
}
//---------------------------------------------------------------------------
void __fastcall TGraph::MakeLastGraphBold(void)
{
  int j = Chart1->SeriesCount() - 1;
  TFastLineSeries *tmp;
  if (Chart1->Series[j]->SameClass(tmp))
    dynamic_cast <TFastLineSeries *> (Chart1->Series[j])->LinePen->Width *= 2;
}
//---------------------------------------------------------------------------
void __fastcall TGraph::SaveGraph(AnsiString name)
{
  Chart1->SaveToMetafile(name);
}
//---------------------------------------------------------------------------

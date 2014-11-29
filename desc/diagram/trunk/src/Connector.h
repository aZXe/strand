//---------------------------------------------------------------------------
#ifndef ConnectorH
#define ConnectorH
//---------------------------------------------------------------------------
#include "Element.h"
#include "Block.h"
//---------------------------------------------------------------------------
// Типы стрелок
#define atNone          0
#define atSimpleArrow   1
#define atFilledArrow   2
#define atEmptyArrow    3
//---------------------------------------------------------------------------
class TElement;
//---------------------------------------------------------------------------
class TConnector : public TElement
{
public:
  TElement *Begin, *End;
  AnsiString Text_begin;
  AnsiString Text_end;

  bool BiDirectional;

  TColor ColorLine;

  TFont *TextFontBegin,
        *TextFontEnd;

  unsigned char LineWidth;

  unsigned char BeginArrowType,
                EndArrowType;

  TDArrayElement *Elements;

  TConnector (TElement *_Begin, TElement *_End, TCanvas **_C, TDArrayElement *_Elements,
              bool _BiDirectional = false, TElementProperty *_Property = NULL);
  TConnector (TCanvas **_C, TFileStream *stream, TDArrayElement *_Elements,
              TElementProperty *_Property = NULL);
  ~TConnector(void);

  __property int X1 = {read=GetX1};
  __property int Y1 = {read=GetY1};
  __property int X2 = {read=GetX2};
  __property int Y2 = {read=GetY2};

  virtual void __fastcall DeleteConnection(int ID);
  virtual bool isMy(int X, int Y);
  virtual bool MouseDown(int X, int Y);
  virtual bool MouseUp(int X, int Y);
  virtual bool MouseMove(int X, int Y);
  virtual bool DblClick(int X, int Y);
  virtual void SetProperty(void);
  virtual void DrawCorners(void);
  virtual void Draw(void);
  virtual void Save(TFileStream * stream);
  virtual void Load(TFileStream*);
  virtual inline int GetType(void) const {return TCONNECTOR;};
  virtual void GetCenter(int &X, int &Y);
  virtual double Coord(double x1, double y1, double x2, double y2);
  virtual double Coord_dp(double x1, double y1, double x2, double y2, char &draw_place);
  void FillRelationsLinkedElements(void);

protected:
  virtual int GetX1(void);
  virtual int GetX2(void);
  virtual int GetY1(void);
  virtual int GetY2(void);

private:
};
//---------------------------------------------------------------------------
#endif


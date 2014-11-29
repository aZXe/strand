//---------------------------------------------------------------------------
#ifndef BlockH
#define BlockH

#include "Constants.h"
#include "ElementPropertyU.h"
#include "Element.h"
//---------------------------------------------------------------------------
class TBlock;
class TConnector;
//---------------------------------------------------------------------------
class TBlock : public TElement
{
protected:
  int FNumber;
  int dx, dy;

  void DrawCorners(void);

public:
  AnsiString Text;
  int State;

  TColor ColorBackground,
         ColorForeground;

  unsigned char LineWidth;

  TFont *TextFont;

  TDArrayElement *Elements;

  TBlock(TCanvas **_C, int _X, int _Y, TDArrayElement *_Elements, TElementProperty *_Property);
  TBlock(TCanvas **_C, TFileStream *stream, TDArrayElement *_Elements, TElementProperty *_Property);
  ~TBlock(void);

  virtual void __fastcall DeleteConnection(int ID);
  virtual bool isMy(int X, int Y);
  virtual bool MouseDown(int X, int Y);
  virtual bool MouseUp(int X, int Y);
  virtual bool MouseMove(int X, int Y);
  virtual bool DblClick(int X, int Y);
  virtual void AdjustOrder(void); //упорядочить вершины
  virtual void SetProperty(void);
  virtual void ForceSetCoord(int newX1, int newY1, int newX2, int newY2);
  virtual void Draw(void);
  virtual void DrawText(int x1, int y1, int x2, int y2);
  virtual void GetCenter(int &X, int &Y);
  virtual double Coord(double x1, double y1, double x2, double y2);
  virtual double Coord_dp(double x1, double y1, double x2, double y2, char &draw_place);

  __property int Number = {read=FNumber, write=FNumber};

  bool operator ==(TBlock &bl);
  virtual void Save(TFileStream * stream);
  virtual void Load(TFileStream * stream);
  virtual inline int GetType(void) const {return TBLOCK;};

protected:
  virtual void SetX1(int newX1);
  virtual void SetX2(int newX2);
  virtual void SetY1(int newY1);
  virtual void SetY2(int newY2);

  virtual void SetCoord(int newX1, int newY1, int newX2, int newY2);
  virtual bool Cross(int newX1, int newY1, int newX2, int newY2);
};
//---------------------------------------------------------------------------
#endif


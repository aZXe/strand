//---------------------------------------------------------------------------
#ifndef ElementH
#define ElementH

#include <sysdyn.h>
#include <alloc.h>
#include "ElementPropertyU.h"
//---------------------------------------------------------------------------
#define MIN_SPACE 5
//---------------------------------------------------------------------------
#include <utility>
using namespace std;
//---------------------------------------------------------------------------
class TElementProperty;
class TElement;
//---------------------------------------------------------------------------
typedef DynamicArray <TElement *> TDArrayElement;
typedef DynamicArray <pair<TElement *, TElement *> > TDArrayConnectedElement;// <Element, Connector>
//---------------------------------------------------------------------------
class TElement
{
protected:
  int FX1, FX2, FY1, FY2;
  bool isActive;
  TCanvas **C;
  void SetActive(bool);
  virtual void DrawCorners(void) = 0;
  TElementProperty *Property;

  virtual void SetX1(int newX1) {FX1 = newX1;};
  virtual void SetX2(int newX2) {FX1 = newX2;};
  virtual void SetY1(int newY1) {FX1 = newY1;};
  virtual void SetY2(int newY2) {FX1 = newY2;};

  virtual inline int GetWidth(void) {return (FX2 - FX1);}
  virtual inline int GetHeight(void) {return (FY2 - FY1);}
public:
  int ID;

  // Элементы связанные коннектором направленным к данному элементу
  TDArrayConnectedElement In;
  // Элементы связанные коннектором направленным от данного элемента
  TDArrayConnectedElement Out;
  // Элементы связанные с данным элементом двунапревленным коннектором
  TDArrayConnectedElement InOut;

  TElement(TCanvas **_C, TElementProperty *_Property) : isActive(false),
           C(_C), ID(0), Property(_Property) {};

  __property bool Active = {read=isActive, write=SetActive};
  __property int X1 = {read=FX1, write=SetX1};
  __property int Y1 = {read=FY1, write=SetY1};
  __property int X2 = {read=FX2, write=SetX2};
  __property int Y2 = {read=FY2, write=SetY2};
  __property int Width  = {read = GetWidth};
  __property int Height = {read = GetHeight};

  virtual void __fastcall DeleteConnection(int ID) = 0;
  
  virtual bool isMy(int X, int Y) = 0;
  virtual bool MouseDown(int X, int Y) = 0;
  virtual bool MouseUp(int X, int Y) = 0;
  virtual bool MouseMove(int X, int Y) = 0;
  virtual bool DblClick(int X, int Y) = 0;
  virtual void SetProperty(void) = 0;
  virtual void Draw(void) = 0;
  virtual void Save(TFileStream *stream) = 0;
  virtual void Load(TFileStream *stream) = 0;
  virtual inline int GetType(void) const = 0;
  virtual void GetCenter(int &X, int &Y) = 0;
  virtual double Coord(double x1, double y1, double x2, double y2) = 0;
  virtual double Coord_dp(double x1, double y1, double x2, double y2, char &draw_place) = 0;
};
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------
#ifndef ContainerH
#define ContainerH

#include "Block.h"
#include "Romb.h"
#include "Connector.h"
#include "BlockIndicator.h"
#include "RombIndicator.h"
//---------------------------------------------------------------------------
#include <set>
#include <map>

using namespace std;
//---------------------------------------------------------------------------
class TContainer : public TImage
{
public:
  virtual void __fastcall _OnMouseDown(TObject *Sender, TMouseButton Button,
        TShiftState Shift, int X, int Y);
  virtual void __fastcall _OnMouseMove(TObject *Sender, TShiftState Shift,
        int X, int Y);
  virtual void __fastcall _OnMouseUp(TObject *Sender, TMouseButton Button,
        TShiftState Shift, int X, int Y);
  virtual void __fastcall _OnDblClick(TObject *Sender);

  void __fastcall Repaint1(void);
  virtual void __fastcall Repaint(void);
//  void __fastcall Update(void);

  virtual TBlock          * __fastcall AddBlock(void);
  virtual TRomb           * __fastcall AddRomb(void);
  virtual TBlockIndicator * __fastcall AddBlockIndicator(void);
  virtual TRombIndicator  * __fastcall AddRombIndicator(void);
  virtual TConnector      * __fastcall AddConnector(int BeginID, int EndID,
                                                    bool isBiDirectional = false);
  virtual void __fastcall AddConnector(bool isBiDirectional = false);
  virtual void __fastcall DeleteActiveElement(void);
  virtual void __fastcall DeleteElement(int ID);
  virtual void Clear(void);
  virtual void ViewActiveElementPropertyForm(void);
//    void __fastcall Add(TElement *NewElement);

  __fastcall TContainer(TComponent* Owner);
  __fastcall ~TContainer();

  int LogToPhis(int X1);
  int PhisToLog(int X);
  int GetWidth(void);
  int GetHeight(void);
  void SetKoef(double K);

  void AlignDiagram(void);

  void SaveAsBMP(AnsiString filename) {Picture->SaveToFile(filename);};
  void SaveAsWMF(AnsiString filename);
  void SaveAsEMF(AnsiString filename);
  void SaveToFile(AnsiString filename);
  void LoadFromFile(AnsiString filename);

  map <int, TElementProperty *> Properties;

  bool is_Repaint;

protected:
  TMetafile *buffer;
  TMetafileCanvas *buffer_Canvas;

  int CountBlocks;

  double Koef;

  TDArrayElement Elements;
  TElement *ActiveElement;

  bool isAddConnector, isBiConnector;

  std::set <int> IDs;
  int GenerateID();
  void AddID(int ID);

  int GetXmin(void);
  int GetYmin(void);
};
//---------------------------------------------------------------------------
#endif

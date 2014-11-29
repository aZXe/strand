//---------------------------------------------------------------------------
#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

#include "Block.h"
#include <Menus.hpp>
#include "CSPIN.h"
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
  class TDiagramForm : public TForm{
    __published:	// IDE-managed Components
    TScrollBox *SB;
    TMainMenu *MainMenu1;
    TMenuItem *File1;
        TMenuItem *miOpen;
    TMenuItem *N1;
        TMenuItem *miExit;
    TOpenDialog *OpenDlg;
    TSaveDialog *SaveDlg;
        TMenuItem *miExport;
        TMenuItem *miSaveAs;
        TMenuItem *N2;
        TMenuItem *miExportBMP;
        TMenuItem *miExportWMF;
        TMenuItem *miExportEMF;
        TControlBar *ControlBar1;
        TToolBar *tbFile;
        TToolButton *tbNew;
        TToolButton *tbOpen;
        TToolButton *ToolButton3;
        TToolButton *tbExportBMP;
        TToolButton *tbExportWMF;
        TToolButton *tbExportEMF;
        TToolBar *tbElements;
        TToolButton *tbAddBlock;
        TToolButton *tbAddRomb;
        TToolButton *tbAddConnector;
        TToolButton *tbAddBiDirectConnector;
        TToolButton *tbAddBlockIndicator;
        TToolButton *tbDeleteActiveElement;
        TToolButton *tbAddRombIndicator;
        TToolButton *ToolButton10;
        TToolButton *tbProperty;
        TImageList *ImageList1;
        TToolButton *tbSaveAs;
        TMenuItem *miNew;
        TToolButton *ToolButton12;
        TToolBar *tbUtil;
        TEdit *ePercent;
        TUpDown *udPercent;
        TLabel *Label1;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall miOpenClick(TObject *Sender);
    void __fastcall miExitClick(TObject *Sender);
        void __fastcall BtnAddRombClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall miNewClick(TObject *Sender);
        void __fastcall miSaveAsClick(TObject *Sender);
        void __fastcall miExportBMPClick(TObject *Sender);
        void __fastcall miExportWMFClick(TObject *Sender);
        void __fastcall miExportEMFClick(TObject *Sender);
        void __fastcall ePercentChange(TObject *Sender);
        void __fastcall tbOpenClick(TObject *Sender);
        void __fastcall tbNewClick(TObject *Sender);
        void __fastcall tbSaveAsClick(TObject *Sender);
        void __fastcall tbExportBMPClick(TObject *Sender);
        void __fastcall tbExportWMFClick(TObject *Sender);
        void __fastcall tbExportEMFClick(TObject *Sender);
        void __fastcall tbDeleteActiveElementClick(TObject *Sender);
        void __fastcall tbAddBlockClick(TObject *Sender);
        void __fastcall tbAddRombClick(TObject *Sender);
        void __fastcall tbAddBlockIndicatorClick(TObject *Sender);
        void __fastcall tbAddRombIndicatorClick(TObject *Sender);
        void __fastcall tbPropertyClick(TObject *Sender);
        void __fastcall tbAddConnectorClick(TObject *Sender);
        void __fastcall tbAddBiDirectConnectorClick(TObject *Sender);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
    private:
    public:		// User declarations
    __fastcall TDiagramForm(TComponent* Owner);
  };
//---------------------------------------------------------------------------
  extern PACKAGE TDiagramForm *DiagramForm;
//---------------------------------------------------------------------------
#endif

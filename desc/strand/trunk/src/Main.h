//----------------------------------------------------------------------------
#ifndef MainH
#define MainH
//----------------------------------------------------------------------------
#include <vcl\ComCtrls.hpp>
#include <vcl\ExtCtrls.hpp>
#include <vcl\Messages.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\Dialogs.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Menus.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
#include <ActnList.hpp>
#include <ImgList.hpp>
#include <StdActns.hpp>
#include <ToolWin.hpp>

#include "ChildGridWin.h"
#include "ChildLogWin.h"
#include "ChildCalcMemoWin.h"
#include "ChildRegrMemoWin.h"
//----------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *FileOpenItem;
	TMenuItem *FileCloseItem;
	TMenuItem *Window1;
	TMenuItem *Help1;
	TMenuItem *N1;
	TMenuItem *FileExitItem;
	TMenuItem *WindowCascadeItem;
	TMenuItem *WindowTileItem;
	TMenuItem *WindowArrangeItem;
	TMenuItem *HelpAboutItem;
	TOpenDialog *OpenDialog;
	TMenuItem *FileSaveItem;
	TMenuItem *FileSaveAsItem;
	TMenuItem *Edit1;
	TMenuItem *CutItem;
	TMenuItem *CopyItem;
	TMenuItem *PasteItem;
	TMenuItem *WindowMinimizeItem;
        TActionList *ActionList1;
        TAction *DataSave;
        TAction *FileExit;
        TAction *DataOpen;
        TAction *DataSaveAs;
        TWindowCascade *WindowCascade1;
        TWindowTileHorizontal *WindowTileHorizontal1;
        TWindowArrange *WindowArrangeAll1;
        TWindowMinimizeAll *WindowMinimizeAll1;
        TWindowClose *DataClose;
        TWindowTileVertical *WindowTileVertical1;
        TMenuItem *WindowTileItem2;
        TImageList *ImageList1;
//        TagStatusPanel *agStatusPanel1;
        TStatusBar *StatusBar1;
        TMenuItem *Analysis;
        TMenuItem *N2;
        TMenuItem *OptimizationItem;
        TSaveDialog *SaveDialog;
        TOpenDialog *OpenTreeDialog;
        TAction *TreeOpen;
        TMenuItem *TreeOpenItem;
        TMenuItem *OdnomAnalizItem;
        TMenuItem *VydelPodvybItem;
        TControlBar *ControlBar1;
        TToolBar *ToolBar2;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TToolButton *ToolButton5;
        TToolButton *ToolButton6;
        TToolButton *ToolButton7;
        TToolButton *ToolButton8;
        TToolButton *ToolButton10;
        TToolButton *ToolButton11;
        TToolButton *ToolButton9;
        TToolButton *ToolButton12;
        TToolButton *ToolButton13;
        TToolButton *ToolButton14;
        TOpenDialog *ImportDialog;
        TMenuItem *ImportItem;
        TMenuItem *STATISTICAdataItem;
        TToolButton *ToolButton15;
        TMenuItem *RefreshDataItem;
        TAction *DataRefresh;
        TToolButton *ToolButton16;
        TMenuItem *FPConstructItem;
        TMenuItem *TreeConstructItem;
        void __fastcall DataOpenExecute(TObject *Sender);
        void __fastcall HelpAbout1Execute(TObject *Sender);
        void __fastcall FileExitExecute(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ToolButton12Click(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall ToolButton13Click(TObject *Sender);
        void __fastcall OptimizationItemClick(TObject *Sender);
        void __fastcall StatusBar1Resize(TObject *Sender);
        void __fastcall TreeOpenExecute(TObject *Sender);
        void __fastcall ToolButton14Click(TObject *Sender);
        void __fastcall DataSaveExecute(TObject *Sender);
        void __fastcall DataCloseExecute(TObject *Sender);
        void __fastcall DataSaveAsExecute(TObject *Sender);
        void __fastcall DataRefreshExecute(TObject *Sender);
        void __fastcall ToolButton16Click(TObject *Sender);
private:
public:
//        TCGauge *strProgressBar;
        
	virtual __fastcall TMainForm(TComponent *Owner);
	void __fastcall CreateChildGrid(const String Name);
	void __fastcall CreateChildGrid(const T2DoubleArray X,
                                        const TAnsiStringArray ColsCaptions,
                                        const TAnsiStringArray RowsCaptions,
                                        const AnsiString Name = "",
                                        const int ViewRowsCount = 10,
                                        const int ViewColsCount = 10);
	void __fastcall CreateChildLog(void);
	void __fastcall CreateChildCalcMemo(void);
	void __fastcall CreateChildRegrMemo(void);
	void __fastcall CloseChildRegrMemo(void);
};
//----------------------------------------------------------------------------
extern TMainForm  *MainForm;
extern TChildGrid *MainChildGrid;
extern TChildLog  *MainChildLog;
extern TChildRegrMemo  *MainChildRegrMemo;
//extern TMDIChild *__fastcall MDIChildCreate(void);
extern void __fastcall EnableDataInterfaceItems(bool e);
extern void CloseAllDependentWindows(void);
//----------------------------------------------------------------------------
#endif
 
//---------------------------------------------------------------------------
#ifndef TreeParmH
#define TreeParmH
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\ComCtrls.hpp>
#include <vcl\ExtCtrls.hpp>
#include <vcl\Menus.hpp>
#include <DdeMan.hpp>
#include <ImgList.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TWinTreeParm : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *BitBtn1;
        TTreeView *TreeView1;
        TGroupBox *GroupBox1;
        TBitBtn *BitBtn5;
        TBitBtn *BitBtn6;
        TBitBtn *BitBtn7;
        TGroupBox *GroupBox2;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtn4;
        TBitBtn *BitBtn10;
        TBitBtn *BitBtn11;
        TOpenDialog *OpenTree;
        TSaveDialog *SaveTree;
        void __fastcall BitBtn1Click(TObject *Sender);

        void __fastcall FormCreate(TObject *Sender);
        void __fastcall BitBtn5Click(TObject *Sender);

        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall BitBtn4Click(TObject *Sender);

        void __fastcall BitBtn6Click(TObject *Sender);
        void __fastcall BitBtn7Click(TObject *Sender);

        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

        void __fastcall TreeView1Change(TObject *Sender, TTreeNode *Node);

        void __fastcall BitBtn10Click(TObject *Sender);
        void __fastcall BitBtn11Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TWinTreeParm(TComponent* Owner);
  void BegNode(void);
  void DelNode(TTreeNode *);
//  void DelTabl(TTreeNode *);
  int  VerifyTree(int &, int &, int &);
  void VerifyTreeBtn(void);
};
//---------------------------------------------------------------------------
extern TWinTreeParm *WinTreeParm;
//---------------------------------------------------------------------------
#endif

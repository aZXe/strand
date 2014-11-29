//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "NodeParm.def"
#include "treeparm.h"
#include "addparm.h"
#include "DArrayTypes.h"

#include "define.def"
#include "StrData.def"
#include "var_ext.def"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
extern TAnsiStringArray VarsNames;

TWinAddParm *WinAddParm;
//---------------------------------------------------------------------------
__fastcall TWinAddParm::TWinAddParm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
//  ���������� ���� || ����������� ��
//---------------------------------------------------------------------------
void __fastcall TWinAddParm::BitBtn2Click(TObject *Sender)
{
  int Obj = 0;//retNumObj(WinTreeParm->Panel1->Caption);
/*
  for (int k = 0; k < numStrParm; k++) {
    if (uStrParm[k].numObjParm == Obj &&
        uStrParm[k].nameParm == ComboBox2->Text) {
      Parm = uStrParm[k].numParm;
      break;
    }
  }
*/
  if (BitBtn2->Caption == "&��������") {
    NodeParm *np = new NodeParm;
    np->type = 2;
    np->numObj = Obj;
    WinTreeParm->TreeView1->Items->
      AddChildObject(WinTreeParm->TreeView1->Selected, ComboBox2->Text, np);

    WinTreeParm->TreeView1->Selected->Expanded = true;
    WinTreeParm->BitBtn5->Enabled = true;
    WinTreeParm->BitBtn6->Enabled = true;
  }
  else {  // ����������� ��
    WinTreeParm->TreeView1->Items->Item[0]->Text = ComboBox2->Text;
    NodeParm *np = (NodeParm *)WinTreeParm->TreeView1->Items->Item[0]->Data;
    np->type = 0;
    np->numObj = Obj;
    WinTreeParm->BitBtn5->Enabled = true;
    WinTreeParm->BitBtn6->Enabled = true;
    Close();
  }
}
//---------------------------------------------------------------------------
//  �������� ����
//---------------------------------------------------------------------------
void __fastcall TWinAddParm::FormCreate(TObject *Sender)
{
    for (int i = 0; i < VarsNames.Length; i++) {
        ComboBox2->Items->Add(VarsNames[i]);
    }
    ComboBox2->ItemIndex = 0;
}
//---------------------------------------------------------------------------
//  ����� �� ����
//---------------------------------------------------------------------------
void __fastcall TWinAddParm::BitBtn1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
//  ����� ��������
//---------------------------------------------------------------------------
void __fastcall TWinAddParm::ComboBox2Change(TObject *Sender)
{
  if (ComboBox2->Text != "")
    BitBtn2->Enabled = true;
  else
    BitBtn2->Enabled = false;
}
//---------------------------------------------------------------------------

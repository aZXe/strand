//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include <stdio.h>

#include "DArrayTypes.h"
#include "GridArray.h"
#include "AddParm.h"
#include "TreeParm.h"

#include "define.def"
#include "StrData.def"
#include "var.def"
#include "NodeParm.def"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TWinTreeParm *WinTreeParm;

extern bool new_tree;
extern T2DoubleArray T;
extern TArray *Array;
//---------------------------------------------------------------------------
__fastcall TWinTreeParm::TWinTreeParm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
//  �������� ���� "��"
//---------------------------------------------------------------------------
void TWinTreeParm::BegNode()
{
  TreeView1->Items->Clear();
  NodeParm *np = new NodeParm, *tp;
  np->type = 0;
  np->numObj = -1;
  TreeView1->Items->AddObjectFirst(TreeView1->Selected,"!!! ������� ������ '���������� ��' !!!",np);
  TreeView1->Selected = TreeView1->Items->Item[0];
  tp = new NodeParm;
  tp->type = 1;
  tp->numObj = -1;
  TreeView1->Items->AddChildObject(TreeView1->Selected,"��������",tp);
  TreeView1->Items->AddChildObject(TreeView1->Selected,"����������",tp);
  TreeView1->Items->AddChildObject(TreeView1->Selected,"�������",tp);
  TreeView1->Items->AddChildObject(TreeView1->Selected,"�������� ��",tp);
  TreeView1->Items->AddChildObject(TreeView1->Selected,"�������� ��",tp);
  TreeView1->Items->AddChildObject(TreeView1->Selected,"���",tp);
  TreeView1->Selected->Expand(true);
  NameTree = "";
  BitBtn2->Enabled = false;
  BitBtn4->Enabled = false;
}
//---------------------------------------------------------------------------
//  ����� �� ����
//---------------------------------------------------------------------------
void __fastcall TWinTreeParm::BitBtn1Click(TObject *Sender)
{
  TTreeNode *cur, *cur_child;
  int i, j;
  int NMax = Array->NVars;

  T.Length = 7;

  T[0].Length = 1;
  T[0][0] = Array->VarByName(TreeView1->Items->Item[0]->Text);
  cur = TreeView1->Items->Item[1];
  for (i = 1; i < 7; i++) {
    T[i].Length = NMax;
    cur_child = cur->getFirstChild();
    j = 0;
    while (cur_child != NULL) {
      T[i][j++] = Array->VarByName(cur_child->Text);
      cur_child = cur->GetNextChild(cur_child);
    }
    T[i].Length = j;
    cur = cur->getNextSibling();
  }

  Close();
}
//---------------------------------------------------------------------------
//  �������� ����
//---------------------------------------------------------------------------
void __fastcall TWinTreeParm::FormClose(TObject *Sender, TCloseAction &Action)
{
/*  if (BitBtn6->Enabled == true) {
    if (Application->MessageBox("��������� ��������� ������ ���������?",
        "������",MB_YESNO) == IDYES) {
    }
  }*/
}
//---------------------------------------------------------------------------
//  �������� ����
//---------------------------------------------------------------------------
void __fastcall TWinTreeParm::FormCreate(TObject *Sender)
{
  TTreeNode *tn;
  int i;

  if (new_tree)
    BegNode();
  else {
    TreeView1->Items->Clear();
    NodeParm *np = new NodeParm, *tp;
    np->type = 0;
    np->numObj = -1;
    TreeView1->Items->AddObjectFirst(TreeView1->Selected,Array->VarName[T[0][0]],np);
    TreeView1->Selected = TreeView1->Items->Item[0];
    tp = new NodeParm;
    tp->type = 1;
    tp->numObj = -1;
    tn = TreeView1->Items->AddChildObject(TreeView1->Selected,"��������",tp);
    tp->type = 2;
    for (i = 0; i < T[1].Length; i++)
      TreeView1->Items->AddChildObject(tn,Array->VarName[T[1][i]],tp);
    tp->type = 1;
    tn = TreeView1->Items->AddChildObject(TreeView1->Selected,"����������",tp);
    tp->type = 2;
    for (i = 0; i < T[2].Length; i++)
      TreeView1->Items->AddChildObject(tn,Array->VarName[T[2][i]],tp);
    tp->type = 1;
    tn = TreeView1->Items->AddChildObject(TreeView1->Selected,"�������",tp);
    tp->type = 2;
    for (i = 0; i < T[3].Length; i++)
      TreeView1->Items->AddChildObject(tn,Array->VarName[T[3][i]],tp);
    tp->type = 1;
    tn = TreeView1->Items->AddChildObject(TreeView1->Selected,"�������� ��",tp);
    tp->type = 2;
    for (i = 0; i < T[4].Length; i++)
      TreeView1->Items->AddChildObject(tn,Array->VarName[T[4][i]],tp);
    tp->type = 1;
    tn = TreeView1->Items->AddChildObject(TreeView1->Selected,"�������� ��",tp);
    tp->type = 2;
    for (i = 0; i < T[5].Length; i++)
      TreeView1->Items->AddChildObject(tn,Array->VarName[T[5][i]],tp);
    tp->type = 1;
    tn = TreeView1->Items->AddChildObject(TreeView1->Selected,"���",tp);
    tp->type = 2;
    for (i = 0; i < T[6].Length; i++)
      TreeView1->Items->AddChildObject(tn,Array->VarName[T[6][i]],tp);
    TreeView1->Selected->Expand(true);
    NameTree = "";
    BitBtn2->Enabled = false;
    BitBtn4->Enabled = false;
    BitBtn11->Enabled = false;
  }
}
//---------------------------------------------------------------------------
//  ���������� � ������ ��������
//---------------------------------------------------------------------------
void __fastcall TWinTreeParm::BitBtn2Click(TObject *Sender)
{
  ActiveControl = TreeView1;
  if (TreeView1->Selected != NULL) {
    WinAddParm = new TWinAddParm(this);
    WinAddParm->Caption = "���������� � ������ ��������";
    WinAddParm->BitBtn2->Caption = "&��������";
    WinAddParm->ShowModal();
    delete WinAddParm;
//    VerifyTreeBtn();
  }
  else
    Application->MessageBox("�� ������ ���� � ������","���������",MB_OK);
}
//---------------------------------------------------------------------------
//  �������� ���� �������� ����
//---------------------------------------------------------------------------
void TWinTreeParm::DelNode(TTreeNode *sel)
{
  TTreeNode *ch = sel->getFirstChild();
  TTreeNode *chN;
  while (ch != NULL){
    DelNode(ch);
//AnsiString s = ch->Text;
//    DelTabl(ch);
    chN = ch;
    ch = sel->GetNextChild(chN);
    chN->Delete();
  }
}
//---------------------------------------------------------------------------
//  �������� ����
//---------------------------------------------------------------------------
void __fastcall TWinTreeParm::BitBtn4Click(TObject *Sender)
{
  ActiveControl = TreeView1;
  if (TreeView1->Selected != NULL) {
    if (TreeView1->Selected->HasChildren == false) {
      if (Application->MessageBox("������� ����?",
          "������",MB_YESNO) == IDNO)
        return;
    }
    else {
      char str[256];
      strcpy(str,"��� �������� ���� ����� ������� ��� ��� �������.\n\n");
      strcat(str,"                                        ������� ����?");
      if (Application->MessageBox
          (str,
          "������",MB_YESNO) == IDNO)
        return;
    }
    TTreeNode *parent = TreeView1->Selected->Parent;
    NodeParm *np = (NodeParm *)TreeView1->Selected->Data;
    DelNode(TreeView1->Selected);
//    DelTabl(TreeView1->Selected);
    if (np->type != 1) {
      TreeView1->Selected->Delete();
      TreeView1->Selected = parent;
    }
//    NodeParm *np = (NodeParm *)TreeView1->Selected->Data;
    BitBtn6->Enabled = true;
    BitBtn5->Enabled = true;
//    VerifyTreeBtn();
  if (new_tree)
    switch (np->type) {
      case 0: BitBtn2->Enabled = false;
              BitBtn4->Enabled = false;
              break;
      case 1: BitBtn2->Enabled = true;
              BitBtn4->Enabled = true;
              break;
      case 2: BitBtn4->Enabled = true;
              BitBtn2->Enabled = false;
              break;
    }
  }
  else
    Application->MessageBox("�� ������ ���� � ������","���������",MB_OK);
}
//---------------------------------------------------------------------------
// ������� ������ ��� �������� ������
//---------------------------------------------------------------------------
void __fastcall TWinTreeParm::BitBtn5Click(TObject *Sender)
{
  ActiveControl = TreeView1;
/*  if (BitBtn6->Enabled == true) {
    if (Application->MessageBox("��������� ��������� ������ ���������?",
        "������",MB_YESNO) == IDYES) {
      if (SaveTree->Execute() == TRUE)
        TreeView1->SaveToFile(SaveTree->FileName);
    }
  }*/
  BegNode();
}
//---------------------------------------------------------------------------
// ���������� ������
//---------------------------------------------------------------------------
void __fastcall TWinTreeParm::BitBtn6Click(TObject *Sender)
{
  if (SaveTree->Execute() == TRUE)
    TreeView1->SaveToFile(SaveTree->FileName);
}
//---------------------------------------------------------------------------
// �������� ������
//---------------------------------------------------------------------------
void __fastcall TWinTreeParm::BitBtn7Click(TObject *Sender)
{
  TTreeNode *a;
  NodeParm *np;
  int i;
  AnsiString txt;

  ActiveControl = TreeView1;
/*  if (BitBtn6->Enabled == true) {
    if (Application->MessageBox("��������� ��������� ������ ���������?",
        "������",MB_YESNO) == IDYES) {
      if (SaveTree->Execute() == TRUE)
        TreeView1->SaveToFile(SaveTree->FileName);
    }
  }*/
  if (OpenTree->Execute() == TRUE)
    TreeView1->LoadFromFile(OpenTree->FileName);

  np = new NodeParm;
  np->type = 0;
  np->numObj = 0;
  TreeView1->Items->Item[0]->Data = np;
  for (i = 1; i < TreeView1->Items->Count; i++) {
    a = TreeView1->Items->Item[i];
    txt = a->Text;
    if (txt == "��������" || txt == "����������" || txt == "�������" ||
        txt == "�������� ��" || txt == "�������� ��" || txt == "���") {
      np = new NodeParm;
      np->type = 1;
      np->numObj = 0;
      a->Data = np;
    } else {
        np = new NodeParm;
        np->type = 2;
        np->numObj = 0;
        a->Data = np;
      }
  }
  TreeView1->FullExpand();
  TreeView1->Selected = TreeView1->Items->Item[0];
}
//---------------------------------------------------------------------------
// ����� ���� ������
//---------------------------------------------------------------------------
void __fastcall TWinTreeParm::TreeView1Change(TObject *Sender, TTreeNode *Node)
{
  NodeParm *np = (NodeParm *)TreeView1->Selected->Data;
if (new_tree)
  switch (np->type) {
    case 0: BitBtn2->Enabled = false;
            BitBtn4->Enabled = false;
            break;
    case 1: BitBtn2->Enabled = true;
            BitBtn4->Enabled = true;
            break;
    case 2: BitBtn4->Enabled = true;
            BitBtn2->Enabled = false;
            break;
  }
}
//---------------------------------------------------------------------------/*    TTreeNode* AnItem = new TTreeNode(TreeView1->Items);
// �������� ������
//---------------------------------------------------------------------------
void __fastcall TWinTreeParm::BitBtn10Click(TObject *Sender)
{
/*  ActiveControl = TreeView1;
  WinDelTree = new TWinDelTree(this);
  WinDelTree->ShowModal();
  delete WinDelTree;*/
}
//---------------------------------------------------------------------------
// ����������� ��
//---------------------------------------------------------------------------
void __fastcall TWinTreeParm::BitBtn11Click(TObject *Sender)
{
  ActiveControl = TreeView1;
  if (((NodeParm *)TreeView1->Items->Item[0]->Data)->numObj >= 0 ) {
    WinAddParm = new TWinAddParm(this);
    WinAddParm->Caption = "��������������� �������� �������� (��)";
    WinAddParm->BitBtn2->Caption = "&��������������";
    WinAddParm->ShowModal();
    delete WinAddParm;
  }
  else {
    WinAddParm = new TWinAddParm(this);
    WinAddParm->Caption = "������� �������� �������� (��)";
    WinAddParm->BitBtn2->Caption = "&����������";
    WinAddParm->ShowModal();
    delete WinAddParm;
  }
//  VerifyTreeBtn();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <math.h>
#include <mem.h>
#include "CalcMFunctions.h"
#include "Logging.h"
#include "MatMath\matlab.hpp"
//---------------------------------------------------------------------------
__fastcall TMCalculate::TMCalculate(void)
{
  GetVarID    = NULL;
  GetVarValue = NULL;
  T = NULL;
}
//-------------------------------------
__fastcall TMCalculate::TMCalculate(GET_MVAR_ID    _GetVarID,
                                  GET_MVAR_VALUE _GetVarValue)
{
  GetVarID    = _GetVarID;
  GetVarValue = _GetVarValue;
  T = NULL;
}
//-------------------------------------
__fastcall TMCalculate::TMCalculate(char * f)
{
  func        = ((AnsiString)f).Trim();
  GetVarID    = NULL;
  GetVarValue = NULL;
  T = NULL;
  TransformNormalToTree();
}
//-------------------------------------
__fastcall TMCalculate::TMCalculate(char * f, GET_MVAR_ID    _GetVarID,
                                            GET_MVAR_VALUE _GetVarValue)
{
  func        = ((AnsiString)f).Trim();
  GetVarID    = _GetVarID;
  GetVarValue = _GetVarValue;
  T = NULL;
  TransformNormalToTree();
}
//-------------------------------------
__fastcall TMCalculate::TMCalculate(AnsiString f)
{
  func        = f.Trim();
  GetVarID    = NULL;
  GetVarValue = NULL;
  T = NULL;
  TransformNormalToTree();
}
//-------------------------------------
__fastcall TMCalculate::TMCalculate(AnsiString f, GET_MVAR_ID    _GetVarID,
                                                GET_MVAR_VALUE _GetVarValue)
{
  func        = f.Trim();
  GetVarID    = _GetVarID;
  GetVarValue = _GetVarValue;
  T = NULL;
  TransformNormalToTree();
}
//---------------------------------------------------------------------------
__fastcall TMCalculate::~TMCalculate()
{
  ClearTree(T);
}
//---------------------------------------------------------------------------
// ������� ������
void TMCalculate::ClearTree(Node *t)
{
  if (t == NULL) return;

  if (t->A) delete t->A;    ///
  if (t->B) delete t->B;    ///
  ClearTree(t->pA);
  ClearTree(t->pB);

  delete t;
}
//---------------------------------------------------------------------------
void TMCalculate::WriteFunction(AnsiString Function)
{
  func = Function.Trim();
  TransformNormalToTree();
}
//---------------------------------------------------------------------------
void TMCalculate::CompForm (void)
{
  register char sign;
  CompTerm();
  while ( (sign = *infix) == '+' || sign == '-' ) {
    ++infix;
    CompTerm();
    func_polish += sign;
    func_polish += ' ';
  }
}
//-------------------------------------
void TMCalculate::CompTerm (void)
{
  register char sign;
  CompPow();
  while ( (sign = *infix) == '*' || sign == '/' ) {
    ++infix;
    CompPow();
    func_polish += sign;
    func_polish += ' ';
  }
}
//-------------------------------------
void TMCalculate::CompPow  (void)
{
  CompElNeg();
  while ( *infix == '^' ) {
    ++infix;
    CompElNeg();
    func_polish += "^ ";
  }
}
//-------------------------------------
void TMCalculate::CompElNeg(void)
{
  if ( *infix == '-' ) {
    if (isdigit(*(infix + 1)))
      CompEl();
    else {
      ++infix;
      CompEl();
      func_polish += "~ ";
    }
  }
  else CompEl();
}
//-------------------------------------
void TMCalculate::CompEl   (void)
{
  if ( *infix == '(' ) {
    ++infix;
    CompForm();
    if ( *infix++ != ')' )
      throw Sysutils::Exception("�� ������� ����������� ������!\n\n�������\n"+func+"\n�� ����� ���� �������������.");
  }
  else {
    if (*infix == '-')
      func_polish += *infix++;
    if ( isdigit(*infix) ) {
      register char c = 0;
//      if ( !isdigit(*infix) && *infix != '-' && *infix != ',' && *infix != 'e'  )
//        throw Exception("����������� ������!\n\n�������\n"+func+"\n�� ����� ���� �������������.");
      while ( isdigit(*infix) || *infix == ',' ) {
        if (*infix == ',') c++;
        func_polish += *infix++;
      }
      if ( c > 1 )
        throw Sysutils::Exception("������ � ������ �����!\n\n�������\n"+func+"\n�� ����� ���� �������������.");
      if ( isalpha(*infix) ) {
        if (*infix != 'e' && *infix != 'E')                      //2,7w
          throw Sysutils::Exception("������ � ������ �����!\n\n�������\n"+func+"\n�� ����� ���� �������������.");
        func_polish += *infix++;
        if (!isdigit(*infix) && *infix != '-' && *infix != '+')  //2,7ew
          throw Sysutils::Exception("������ � ������ �����!\n\n�������\n"+func+"\n�� ����� ���� �������������.");
        if (*infix == '-' || *infix == '+')
          func_polish += *infix++;
        if (!isdigit(*infix))                                    //2,7e+w
          throw Sysutils::Exception("������ � ������ �����!\n\n�������\n"+func+"\n�� ����� ���� �������������.");
        while ( isdigit(*infix) )
          func_polish += *infix++;
        if (isalpha(*infix))                                     //2,7e+003w
          throw Sysutils::Exception("������ � ������ �����!\n\n�������\n"+func+"\n�� ����� ���� �������������.");
      }
    }
    else
      if ( isalpha(*infix) || *infix == '_' ) {
        while ( isalpha(*infix) || isdigit(*infix) || *infix == '_' )
          func_polish += *infix++;
      }
      else
        throw Sysutils::Exception("����������� ������!\n\n�������\n"+func+"\n�� ����� ���� �������������.");
    func_polish += ' ';
  }
}
//---------------------------------------------------------------------------
// �������������� ������� �� ��������� ������ � ��������
void TMCalculate::TransformNormalToPolish(void)
{
  char *p;

  func_polish.SetLength(0);
  infix = func.c_str();
// �������� �������� ����� ���������������
  p = infix;
  while (*p) {
    if (*p < 0x21) memmove(p, p + 1, strlen(p + 1) + 1);
    else p++;
  }
// ��������������
  try {
    CompForm();
//    ShowMessage(func_polish);
  }
  catch (const Sysutils::Exception &E) {
    func_polish.SetLength(0);
    Application->MessageBox(E.Message.c_str(), "������ �������������� �������", MB_OK);
  }
}
//---------------------------------------------------------------------------
// �������������� ������� �� �������� ������ � ������ ��������
void TMCalculate::TransformPolishToTree(void)
{
  char *p;
  AnsiString polish = func_polish;
  Stack *s = NULL, *t, *k;
  Node *nA;

  ClearTree(T);

  if (polish.Length() == 0) {
    T = new Node;
    T->pA = T->pB = NULL;
    T->Operation = 0;
    T->A = T->B = NULL;                   ///
    T->iA = T->iB = NO_VAR;
    return;
  }

  p =  strtok(polish.c_str(), " ");
  try {
    do {
      t = new Stack;
      t->Prev = s;
      t->pA = NULL;
      t->A = NULL;                     ///
      t->iA = NO_VAR;

      if (isalpha(*p) || *p == '_') {
// ����������
        s = t;
        if (GetVarID == NULL)
          throw Sysutils::Exception("�� ���������� ������� ������������� ���������� (GetVarID)!\n\n�������������� ����������.");
        s->iA = (*GetVarID)(p);
        if (s->iA == UNKNOWN_VAR)
          throw Sysutils::Exception("����������� ���������� ("+(AnsiString)p+")!\n\n�������������� ����������.");
      } else
// �����
          if (isdigit(*p) || (*p == '-' && isdigit(*(p + 1)))) {
            s = t;
            s->A = new mwArray(((AnsiString)p).ToDouble());       ///
          } else {
// ��������
              delete t;
              nA = new Node;

              nA->B  = s->A;
              nA->iB = s->iA;
              nA->pB = s->pA;
              nA->Operation = *p;
              if (*p == '~') {
                nA->A  = NULL;     ///
                nA->iA = NO_VAR;
                nA->pA = NULL;
                s->pA  = nA;
              }
              else {
                k = s->Prev;
                nA->A  = k->A;
                nA->iA = k->iA;
                nA->pA = k->pA;
                k->pA  = nA;
                delete s;
                s = k;
              }
            }
    } while (p = strtok(NULL, " "));
    if (s->pA) T = s->pA;
    else {
      T = new Node;
      T->A = NULL;               ///
      T->iA = NO_VAR;
      T->B = s->A;
      T->iB = s->iA;
      T->pB = T->pA = NULL;
      T->Operation = 0;
    }
    s->pA = NULL;
// ������� ����������� �����
    while (s) {
      k = s->Prev;
      ClearTree(s->pA);
      if (s->A) delete s->A;    ///
      delete s;
      s = k;
    }
    return;
  }
  catch (const Sysutils::Exception &E) {
    Application->MessageBox(E.Message.c_str(), "������ �������������� �������", MB_OK);
  }
// ������� �����
  while (s) {
    k = s->Prev;
    ClearTree(s->pA);
    if (s->A) delete s->A;    ///
    delete s;
    s = k;
  }
}
//---------------------------------------------------------------------------
// ������� ���������� ������� � ���� �
mwArray TMCalculate::EvaluateTree(Node *A)
{
  mwArray a, b;

  if (A->pA) a = EvaluateTree(A->pA);
  else if (A->iA != NO_VAR) a = GetVarValue(A->iA);
       else a = *(A->A);

  if (A->pB) b = EvaluateTree(A->pB);
  else if (A->iB != NO_VAR) b = GetVarValue(A->iB);
       else b = *(A->B);

  switch (A->Operation) {
    case '*': return times(a, b);
    case '+': return plus(a, b);
    case '-': return minus(a, b);
    case '/': return rdivide(a, b);
    case '^': return power(a, b);
    case '~': return uminus(b);
  }

  return b;
}
//---------------------------------------------------------------------------
// ������� ����������
mwArray TMCalculate::Evaluate(void)
{
  if (T) return EvaluateTree(T);
  else return 0;
}
//---------------------------------------------------------------------------
// ����� ������ � ���� ������� � ���� �
void TMCalculate::PrintTree(Node *A, FILE *f)
{
  fprintf(f, "Node : %ld\n", (long)A);

  if (A->pA) fprintf(f, "  pA : %ld\n", (long)A->pA);
  else if (A->iA != NO_VAR) fprintf(f, "  iA : %d\n", A->iA);
       else fprintf(f, "   A : %ld\n", (long)A->A);

  if (A->pB) fprintf(f, "  pB : %ld\n", (long)A->pB);
  else if (A->iB != NO_VAR) fprintf(f, "  iB : %d\n", A->iB);
       else fprintf(f, "   B : %ld\n", (long)A->B);

  fprintf(f, "  Op : %c\n---------------------------------------------------\n",
          A->Operation);

  if (A->pA) PrintTree(A->pA, f);
  if (A->pB) PrintTree(A->pB, f);
}
//---------------------------------------------------------------------------
// ������� ����������
void TMCalculate::Print(AnsiString name)
{
  FILE *f;

  f = fopen(name.c_str(), "w");
  
  if (T) PrintTree(T, f);

  fclose(f);
}
//---------------------------------------------------------------------------
#pragma package(smart_init)

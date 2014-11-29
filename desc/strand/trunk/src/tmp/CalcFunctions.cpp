//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <math.h>
#include <mem.h>
#include "CalcFunctions.h"
//---------------------------------------------------------------------------
__fastcall TCalculate::TCalculate(void)
{
  GetVarID    = NULL;
  GetVarValue = NULL;
  T = NULL;
}

__fastcall TCalculate::TCalculate(GET_VAR_ID    _GetVarID,
                                  GET_VAR_VALUE _GetVarValue)
{
  GetVarID    = _GetVarID;
  GetVarValue = _GetVarValue;
  T = NULL;
}

__fastcall TCalculate::TCalculate(char * f)
{
  func        = ((AnsiString)f).Trim();
  GetVarID    = NULL;
  GetVarValue = NULL;
  T = NULL;
  TransformNormalToTree();
}

__fastcall TCalculate::TCalculate(char * f, GET_VAR_ID    _GetVarID,
                                            GET_VAR_VALUE _GetVarValue)
{
  func        = ((AnsiString)f).Trim();
  GetVarID    = _GetVarID;
  GetVarValue = _GetVarValue;
  T = NULL;
  TransformNormalToTree();
}

__fastcall TCalculate::TCalculate(AnsiString f)
{
  func        = f.Trim();
  GetVarID    = NULL;
  GetVarValue = NULL;
  T = NULL;
  TransformNormalToTree();
}

__fastcall TCalculate::TCalculate(AnsiString f, GET_VAR_ID    _GetVarID,
                                                GET_VAR_VALUE _GetVarValue)
{
  func        = f.Trim();
  GetVarID    = _GetVarID;
  GetVarValue = _GetVarValue;
  T = NULL;
  TransformNormalToTree();
}
//---------------------------------------------------------------------------
__fastcall TCalculate::~TCalculate()
{
  ClearTree(T);
}
//---------------------------------------------------------------------------
// ������� ������
void TCalculate::ClearTree(Node *t)
{
  if (t == NULL) return;

  ClearTree(t->pA);
  ClearTree(t->pB);

  delete t;
}
//---------------------------------------------------------------------------
void TCalculate::WriteFunction(AnsiString Function)
{
  func = Function.Trim();
  TransformNormalToTree();
}
//---------------------------------------------------------------------------
void TCalculate::CompForm (void)
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

void TCalculate::CompTerm (void)
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

void TCalculate::CompPow  (void)
{
  CompElNeg();
  while ( *infix == '^' ) {
    ++infix;
    CompElNeg();
    func_polish += "^ ";
  }
}

void TCalculate::CompElNeg(void)
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

void TCalculate::CompEl   (void)
{
  if ( *infix == '(' ) {
    ++infix;
    CompForm();
    if ( *infix++ != ')' )
      throw Exception("�� ������� ����������� ������!\n\n�������\n"+func+"\n�� ����� ���� �������������.");
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
        throw Exception("������ � ������ �����!\n\n�������\n"+func+"\n�� ����� ���� �������������.");
      if ( isalpha(*infix) ) {
        if (*infix != 'e' && *infix != 'E')                      //2,7w
          throw Exception("������ � ������ �����!\n\n�������\n"+func+"\n�� ����� ���� �������������.");
        func_polish += *infix++;
        if (!isdigit(*infix) && *infix != '-' && *infix != '+')  //2,7ew
          throw Exception("������ � ������ �����!\n\n�������\n"+func+"\n�� ����� ���� �������������.");
        if (*infix == '-' || *infix == '+')
          func_polish += *infix++;
        if (!isdigit(*infix))                                    //2,7e+w
          throw Exception("������ � ������ �����!\n\n�������\n"+func+"\n�� ����� ���� �������������.");
        while ( isdigit(*infix) )
          func_polish += *infix++;
        if (isalpha(*infix))                                     //2,7e+003w
          throw Exception("������ � ������ �����!\n\n�������\n"+func+"\n�� ����� ���� �������������.");
      }
    }
    else
      if ( isalpha(*infix) || *infix == '_' ) {
        while ( isalpha(*infix) || isdigit(*infix) || *infix == '_' )
          func_polish += *infix++;
      }
      else
        throw Exception("����������� ������!\n\n�������\n"+func+"\n�� ����� ���� �������������.");
    func_polish += ' ';
  }
}
//---------------------------------------------------------------------------
// �������������� ������� �� ��������� ������ � ��������
void TCalculate::TransformNormalToPolish(void)
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
    ShowMessage(func_polish);
  }
  catch (const Exception &E) {
    func_polish.SetLength(0);
    Application->MessageBox(E.Message.c_str(), "������ �������������� �������", MB_OK);
  }
}
//---------------------------------------------------------------------------
// �������������� ������� �� �������� ������ � ������ ��������
void TCalculate::TransformPolishToTree(void)
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
    T->A = T->B = 0;
    T->iA = T->iB = NO_VAR;
    return;
  }

  p =  strtok(polish.c_str(), " ");
  try {
    do {
      t = new Stack;
      t->Prev = s;
      t->pA = NULL;
      t->A = 0;
      t->iA = NO_VAR;

      if (isalpha(*p) || *p == '_') {
// ����������
        s = t;
        if (GetVarID == NULL)
          throw Exception("�� ���������� ������� ������������� ���������� (GetVarID)!\n\n�������������� ����������.");
        s->iA = (*GetVarID)(p);
        if (s->iA == UNKNOWN_VAR)
          throw Exception("����������� ���������� ("+(AnsiString)p+")!\n\n�������������� ����������.");
      } else
// �����
          if (isdigit(*p) || (*p == '-' && isdigit(*(p + 1)))) {
            s = t;
            s->A = ((AnsiString)p).ToDouble();
          } else {
// ��������
              delete t;
              nA = new Node;

              nA->B  = s->A;
              nA->iB = s->iA;
              nA->pB = s->pA;
              nA->Operation = *p;
              if (*p == '~') {
                nA->A  = 0;
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
      T->A = 0;
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
      delete s;
      s = k;
    }
    return;
  }
  catch (const Exception &E) {
    Application->MessageBox(E.Message.c_str(), "������ �������������� �������", MB_OK);
  }
// ������� �����
  while (s) {
    k = s->Prev;
    ClearTree(s->pA);
    delete s;
    s = k;
  }
}
//---------------------------------------------------------------------------
// ������� ���������� ������� � ���� �
double TCalculate::EvaluateTree(Node *A)
{
  double a, b;

  if (A->pA) a = EvaluateTree(A->pA);
  else if (A->iA != NO_VAR) a = GetVarValue(A->iA);
       else a = A->A;

  if (A->pB) b = EvaluateTree(A->pB);
  else if (A->iB != NO_VAR) b = GetVarValue(A->iB);
       else b = A->B;

  switch (A->Operation) {
    case '*': return a * b;
    case '+': return a + b;
    case '-': return a - b;
    case '/': return a / b;
    case '^': return pow(a, b);
    case '~': return -b;
  }

  return b;
}
//---------------------------------------------------------------------------
// ������� ����������
double TCalculate::Evaluate(void)
{
  if (T) return EvaluateTree(T);
  else return 0;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)

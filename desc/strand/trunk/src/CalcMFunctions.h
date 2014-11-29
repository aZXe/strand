//---------------------------------------------------------------------------
#ifndef CalcMFunctionsH
#define CalcMFunctionsH
//---------------------------------------------------------------------------
#define UNKNOWN_VAR     (int)-1
#define NO_VAR          0
//---------------------------------------------------------------------------
#include "MatMath\matlab.hpp"
//---------------------------------------------------------------------------
typedef int (*GET_MVAR_ID)(char *);
typedef mwArray (*GET_MVAR_VALUE)(int);
//---------------------------------------------------------------------------
class TMCalculate
{
private:
  struct Node {
    double A, B;
    int iA, iB;
    Node *pA, *pB;
    char Operation;
  };

  struct Stack{
    double A;
    int iA;
    Node *pA;
    Stack *Prev;
  };

  AnsiString func, func_polish;
//  char *in, *out;
  char *infix, *postfix;
  Node *T;                      // Tree Of Operations

  void ClearTree(Node *);

  void CompForm (void);
  void CompTerm (void);
  void CompPow  (void);
  void CompElNeg(void);
  void CompEl   (void);

  void TransformNormalToPolish(void);
  void TransformPolishToTree(void);
  void TransformNormalToTree(void)
  {
    TransformNormalToPolish();
    TransformPolishToTree();
  }

  mwArray EvaluateTree(Node *);
  void PrintTree(Node *, FILE *);
  void PrintTreeTmp(Node *, FILE *);

  void WriteFunction(AnsiString Function);

protected:

public:
  GET_MVAR_ID GetVarID;
  GET_MVAR_VALUE GetVarValue;

  __fastcall TMCalculate(void);
  __fastcall TMCalculate(GET_MVAR_ID, GET_MVAR_VALUE);
  __fastcall TMCalculate(char *);
  __fastcall TMCalculate(char *, GET_MVAR_ID, GET_MVAR_VALUE);
  __fastcall TMCalculate(AnsiString);
  __fastcall TMCalculate(AnsiString, GET_MVAR_ID, GET_MVAR_VALUE);
  __fastcall ~TMCalculate();

  __property AnsiString Function = {read = func, write = WriteFunction};

  mwArray Evaluate(void);
  void Print(AnsiString name);
};
//---------------------------------------------------------------------------
#endif

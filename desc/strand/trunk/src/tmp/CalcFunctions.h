//---------------------------------------------------------------------------
#ifndef CalcFunctionsH
#define CalcFunctionsH

#define UNKNOWN_VAR     (int)-1
#define NO_VAR          0

typedef int (*GET_VAR_ID)(char *);
typedef double (*GET_VAR_VALUE)(int);

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

class TCalculate
{
private:
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

  double EvaluateTree(Node *);

  void WriteFunction(AnsiString Function);
protected:
public:
  GET_VAR_ID GetVarID;
  GET_VAR_VALUE GetVarValue;

  __fastcall TCalculate(void);
  __fastcall TCalculate(GET_VAR_ID, GET_VAR_VALUE);
  __fastcall TCalculate(char *);
  __fastcall TCalculate(char *, GET_VAR_ID, GET_VAR_VALUE);
  __fastcall TCalculate(AnsiString);
  __fastcall TCalculate(AnsiString, GET_VAR_ID, GET_VAR_VALUE);
  __fastcall ~TCalculate();

  __property AnsiString Function = {read = func, write = WriteFunction};

  double Evaluate(void);
};

//---------------------------------------------------------------------------
#endif

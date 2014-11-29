//---------------------------------------------------------------------------
#ifndef CalcThreadH
#define CalcThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TCalcThread : public TThread
{
private:
protected:
        void __fastcall Execute();
public:
        __fastcall TCalcThread(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Prosein.res");
USEFORM("KlMain.cpp", Form1);
USEUNIT("GridArray.cpp");
USEUNIT("Progress.cpp");
USEUNIT("Utils.cpp");
USEUNIT("Sets.cpp");
USEUNIT("Maps.cpp");
USEUNIT("Classification.cpp");
USEUNIT("MatrixFunctions.cpp");
USEUNIT("ThisProgramInGSU.pas");
USEFORM("Params.cpp", ParamsForm);
USELIB("STADEV.LIB");
USEFORM("WeightUnit.cpp", WeightForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->CreateForm(__classid(TParamsForm), &ParamsForm);
                 Application->CreateForm(__classid(TWeightForm), &WeightForm);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------

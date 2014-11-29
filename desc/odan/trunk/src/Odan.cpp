//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("Odan.res");
USEFORM("RavnomUnit.cpp", Form1);
USEUNIT("GridArray.cpp");
USEUNIT("MatrixFunctions.cpp");
USEUNIT("MyStatFunctions.cpp");
USEUNIT("MatrixDisplay.cpp");
USEUNIT("GraphingChart.cpp");
USEUNIT("OdnomAnaliz.cpp");
USEUNIT("Distributions.cpp");
USEUNIT("Progress.cpp");
USEFORM("Config.cpp", ConfigForm);
USE("Odan.todo", ToDo);
USEUNIT("ThisProgramInGSU.pas");
USEUNIT("Utils.cpp");
USELIB("STADEV.LIB");
USEFORM("CreateParameters.cpp", CreateParametersForm);
USEUNIT("GraphingThreeChart.cpp");
USEUNIT("Charts.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->CreateForm(__classid(TConfigForm), &ConfigForm);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------

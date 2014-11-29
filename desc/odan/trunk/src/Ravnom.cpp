//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("Ravnom.res");
USEFORM("RavnomUnit.cpp", Form1);
USEUNIT("GridArray.cpp");
USEUNIT("MatrixFunctions.cpp");
USEUNIT("MyStatFunctions.cpp");
USEUNIT("MatrixDisplay.cpp");
USEUNIT("Graphing.cpp");
USEUNIT("OdnomAnaliz.cpp");
USEUNIT("Distributions.cpp");
USEUNIT("Progress.cpp");
USEUNIT("Treeparm.cpp");
USEUNIT("Addparm.cpp");
USEFORM("Config.cpp", ConfigForm);
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

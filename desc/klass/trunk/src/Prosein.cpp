//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Prosein.res");
USEFORM("KlMain.cpp", Form1);
USEUNIT("GridArray.cpp");
USEUNIT("Progress.cpp");
USELIB("Stadev.lib");
USEUNIT("Utils.cpp");
USEUNIT("Sets.cpp");
USEUNIT("Maps.cpp");
USEUNIT("Classification.cpp");
USEUNIT("MatrixFunctions.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------

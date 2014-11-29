//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("StrDiagram.res");
USEUNIT("Connector.cpp");
USEUNIT("Container.cpp");
USEUNIT("Block.cpp");
USEUNIT("Element.cpp");
USEFORM("Main.cpp", DiagramForm);
USEUNIT("BlockIndicator.cpp");
USEFORM("ElementPropertyU.cpp", ElementProperty);
USEUNIT("RombIndicator.cpp");
USEUNIT("Romb.cpp");
USEFORM("BlockIndicatorForm.cpp", BlockIndicatorPropertyForm);
USEUNIT("ThisProgramInGSU.pas");
USEUNIT("Utils.cpp");
USEFORM("BlockForm.cpp", BlockPropertyForm);
USEFORM("ConnectorForm.cpp", ConnectorPropertyForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TDiagramForm), &DiagramForm);
                 Application->CreateForm(__classid(TBlockPropertyForm), &BlockPropertyForm);
                 Application->CreateForm(__classid(TConnectorPropertyForm), &ConnectorPropertyForm);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------

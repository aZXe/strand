//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------
USEFORM("Main.cpp", MainForm);
USERES("strand.res");
USEFORM("about.cpp", AboutBox);
USEFORM("ChildGridWin.cpp", ChildGrid);
USEUNIT("GridArray.cpp");
USEUNIT("OdnomAnaliz.cpp");
USEUNIT("MatrixFunctions.cpp");
USEUNIT("Progress.cpp");
USEUNIT("Distributions.cpp");
USEFORM("Graphing.cpp", Graph);
USEUNIT("CalcMFunctions.cpp");
USEFORM("ChildCalcMemoWin.cpp", ChildCalcMemo);
USEFORM("ChildLogWin.cpp", ChildLog);
USEUNIT("Logging.cpp");
USEUNIT("Optimization.cpp");
USEUNIT("CalcFunctions.cpp");
USEFORM("Config.cpp", PagesDlg);
USEFORM("ChildRegrMemoWin.cpp", ChildRegrMemo);
USEFORM("Addparm.cpp", WinAddParm);
USEFORM("Treeparm.cpp", WinTreeParm);
USEUNIT("Utils.cpp");
USEUNIT("MyStatFunctions.cpp");
USE("strand.todo", ToDo);
USELIB("libmx.lib");
USELIB("libmatlb.lib");
USELIB("libmatlbmx.lib");
USELIB("libmatpb55.lib");
USELIB("libmmfile.lib");
USELIB("libmat.lib");
USELIB("STADEV.LIB");
USELIB("BugslayerUtil.lib");
USEFORM("FPConstructor.cpp", FPConstructorForm);
USEUNIT("CorrelationGridUnit.cpp");
USEUNIT("Sets.cpp");
USEUNIT("Maps.cpp");
USEUNIT("..\Diagram\Block.cpp");
USEUNIT("..\Diagram\Connector.cpp");
USEUNIT("..\Diagram\Element.cpp");
USEUNIT("..\Diagram\Romb.cpp");
USEFORM("..\Diagram\ElementPropertyU.cpp", ElementProperty);
USEUNIT("..\Diagram\Container.cpp");
USEUNIT("FPContainer.cpp");
USEUNIT("..\Diagram\RombIndicator.cpp");
USEUNIT("..\Diagram\BlockIndicator.cpp");
USEUNIT("VarDescriptionSimple.cpp");
USEUNIT("VarDescriptionCalc.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        Application->Initialize();
        Application->CreateForm(__classid(TMainForm), &MainForm);
                 Application->CreateForm(__classid(TAboutBox), &AboutBox);
                 Application->CreateForm(__classid(TPagesDlg), &PagesDlg);
                 Application->Run();

	return 0;
}
//---------------------------------------------------------------------

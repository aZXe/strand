# Microsoft Developer Studio Project File - Name="BugslayerUtil" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=BugslayerUtil - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "BugslayerUtil.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "BugslayerUtil.mak" CFG="BugslayerUtil - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "BugslayerUtil - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "BugslayerUtil - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "BugslayerUtil - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\Release"
# PROP Intermediate_Dir "WinRel"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MD /W4 /WX /GX /Zi /O1 /I "..\Include" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "BUILDING_BUGSUTILITY_DLL" /D "STRICT" /D "WORK_AROUND_SRCLINE_BUG" /D "USE_BUGSLAYERUTIL" /YX"pch.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib DBGHELP.lib /nologo /base:"0x60000000" /subsystem:windows /dll /map:"$(OUTDIR)\BugslayerUtil.map" /debug /machine:I386 /def:".\BugslayerUtil.def" /OPT:REF /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "BugslayerUtil - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\Output"
# PROP Intermediate_Dir "WinDebug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MDd /W4 /WX /GX /Zi /Od /I "..\Include" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "BUILDING_BUGSUTILITY_DLL" /D "STRICT" /D "WORK_AROUND_SRCLINE_BUG" /D "USE_BUGSLAYERUTIL" /YX"pch.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib DBGHELP.lib /nologo /base:"0x60000000" /subsystem:windows /dll /debug /machine:I386

!ENDIF 

# Begin Target

# Name "BugslayerUtil - Win32 Release"
# Name "BugslayerUtil - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AllocAndFillProcessModuleList.cpp
# End Source File
# Begin Source File

SOURCE=.\BSUFunctions.cpp
# End Source File
# Begin Source File

SOURCE=.\BugslayerUtil.def

!IF  "$(CFG)" == "BugslayerUtil - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BugslayerUtil - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\CrashHandler.cpp
# End Source File
# Begin Source File

SOURCE=.\DiagAssert.cpp
# End Source File
# Begin Source File

SOURCE=.\DllMain.cpp
# End Source File
# Begin Source File

SOURCE=.\GetLoadedModules.cpp
# End Source File
# Begin Source File

SOURCE=.\HookImportedFunctionByName.cpp
# End Source File
# Begin Source File

SOURCE=.\HookOrdinalExport.cpp
# End Source File
# Begin Source File

SOURCE=.\IsNT.cpp
# End Source File
# Begin Source File

SOURCE=.\MemDumperValidator.cpp
# End Source File
# Begin Source File

SOURCE=.\MemStress.cpp
# End Source File
# Begin Source File

SOURCE=.\NT4ProcessInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\PCH.cpp
# End Source File
# Begin Source File

SOURCE=.\TLHELPProcessInfo.cpp
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\BugslayerUtil.rc
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\Include\BugslayerUtil.h
# End Source File
# Begin Source File

SOURCE=..\Include\CrashHandler.h
# End Source File
# Begin Source File

SOURCE=..\Include\CriticalSection.h
# End Source File
# Begin Source File

SOURCE=.\CRTDBG_Internals.h
# End Source File
# Begin Source File

SOURCE=..\Include\DiagAssert.h
# End Source File
# Begin Source File

SOURCE=.\Internal.h
# End Source File
# Begin Source File

SOURCE=..\Include\MemDumperValidator.h
# End Source File
# Begin Source File

SOURCE=..\Include\MemStress.h
# End Source File
# Begin Source File

SOURCE=.\MemStressConstants.h
# End Source File
# Begin Source File

SOURCE=..\Include\MSJDBG.h
# End Source File
# Begin Source File

SOURCE=.\PCH.h
# End Source File
# Begin Source File

SOURCE=..\Include\PSAPI.H
# End Source File
# Begin Source File

SOURCE=..\Include\SymbolEngine.h
# End Source File
# Begin Source File

SOURCE=..\Include\WarningsOff.h
# End Source File
# Begin Source File

SOURCE=..\Include\WarningsOn.h
# End Source File
# End Group
# End Target
# End Project

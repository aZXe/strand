if not exist .\WinDebug/NUL mkdir .\WinDebug
if not exist ..\..\..\Output/NUL mkdir ..\..\..\Output
cl.exe  -D_X86_=1 /DWIN32 /D_WINDOWS /DSTRICT /D_DEBUG /DDEBUG /D_MBCS /D_AFXDLL  /nologo /WX /GX    /MDd /Od /W3 /c  /Zi          /Fp.\WinDebug\CH_Tests.pch -I..\..\..\include /Fd..\..\..\Output/"CH_Tests.pdb" /YX.\WinDebug\CH_Tests.pch /Fo.\WinDebug/ CH_Tests.cpp
link.exe kernel32.lib user32.lib gdi32.lib advapi32.lib ..\..\..\output\BugslayerUtil.lib DBGHELP.LIB    /NOLOGO /MACHINE:i386 /OUT:..\..\..\Output/CH_Tests_PDB.exe   /SUBSYSTEM:console /INCREMENTAL:no  /DEBUG /PDB:..\..\..\Output/"CH_Tests_PDB.pdb" /PDBTYPE:CON   .\WinDebug/CH_Tests.OBJ


; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "STRAND (STatistical and Regression ANalysis of Data)"
#define MyAppVersion "1.0"
#define MyAppPublisher "Gomel State University named after Francysk Skaryna"
#define MyAppURL "http://www.gsu.by/chairs/Math/mpu.html"
#define MyAppExeName "strand.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{F700256A-BF8D-4BAB-91DC-0AAE71AB3007}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\Strand
DefaultGroupName=Strand
AllowNoIcons=yes
OutputDir=D:\Work\Project\Strand 5\Release\Strand\setup
OutputBaseFilename=setup_strand
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked; OnlyBelowVersion: 0,6.1

[Files]
Source: "D:\Work\Project\Strand 5\Release\Strand\source\strand.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Work\Project\Strand 5\Release\Strand\source\atlas_PIII.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Work\Project\Strand 5\Release\Strand\source\BugslayerUtil.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Work\Project\Strand 5\Release\Strand\source\lapack.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Work\Project\Strand 5\Release\Strand\source\libmat.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Work\Project\Strand 5\Release\Strand\source\libmatlb.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Work\Project\Strand 5\Release\Strand\source\libmex.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Work\Project\Strand 5\Release\Strand\source\libmi.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Work\Project\Strand 5\Release\Strand\source\libmmfile.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Work\Project\Strand 5\Release\Strand\source\libmwarpack.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Work\Project\Strand 5\Release\Strand\source\libmwbuiltins.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Work\Project\Strand 5\Release\Strand\source\libmwcl.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Work\Project\Strand 5\Release\Strand\source\libmwfftw.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Work\Project\Strand 5\Release\Strand\source\libmwgcl.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Work\Project\Strand 5\Release\Strand\source\libmwlapack.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Work\Project\Strand 5\Release\Strand\source\libmwservices.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Work\Project\Strand 5\Release\Strand\source\libmwsglm.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Work\Project\Strand 5\Release\Strand\source\libmx.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Work\Project\Strand 5\Release\Strand\source\libut.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Work\Project\Strand 5\Release\Strand\source\m_ir.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Work\Project\Strand 5\Release\Strand\source\m_parser.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Work\Project\Strand 5\Release\Strand\source\mpath.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Work\Project\Strand 5\Release\Strand\source\numerics.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Work\Project\Strand 5\Release\Strand\source\STADEV.DLL"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Work\Project\Strand 5\Release\Strand\source\STADEV32.DLL"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{group}\{cm:ProgramOnTheWeb,{#MyAppName}}"; Filename: "{#MyAppURL}"
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, "&", "&&")}}"; Flags: nowait postinstall skipifsilent


//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "About.h"
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
TAboutBox *AboutBox;
//---------------------------------------------------------------------
__fastcall TAboutBox::TAboutBox(TComponent *Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------
void __fastcall TAboutBox::FormCreate(TObject *Sender)
{
    DWORD h;
    DWORD Size=GetFileVersionInfoSize(Application->ExeName.c_str(), &h);
    if(Size==0) return;
    char *buf;
    buf=(char*)GlobalAlloc(GMEM_FIXED, Size);
    if(GetFileVersionInfo(Application->ExeName.c_str(),
                          h,
                          Size,
                          buf)!=0)
    {
       char *ValueBuf;
       UINT Len;
       VerQueryValue(buf, "\\VarFileInfo\\Translation", &(void*)ValueBuf,&Len);
       if(Len>=4)
       {
          AnsiString CharSet=IntToHex((int)MAKELONG(*(int*)(ValueBuf+2),*(int*)ValueBuf), 8);

          if(VerQueryValue(buf,
                        AnsiString("\\StringFileInfo\\"+CharSet+"\\ProductName").c_str(),
                        &(void*)ValueBuf,
                        &Len)!=0)
             AppName->Caption=ValueBuf;
          if(VerQueryValue(buf,
                        AnsiString("\\StringFileInfo\\"+CharSet+"\\FileVersion").c_str(),
                        &(void*)ValueBuf,
                        &Len)!=0)
             Version->Caption=ValueBuf;
          if(VerQueryValue(buf,
                        AnsiString("\\StringFileInfo\\"+CharSet+"\\LegalCopyright").c_str(),
                        &(void*)ValueBuf,
                        &Len)!=0)
             Copyright->Caption=ValueBuf;
          if(VerQueryValue(buf,
                        AnsiString("\\StringFileInfo\\"+CharSet+"\\Comments").c_str(),
                        &(void*)ValueBuf,
                        &Len)!=0)
             Comments->Caption=ValueBuf;
       }
    }
    GlobalFree((HGLOBAL)buf);
}
//---------------------------------------------------------------------------
void __fastcall TAboutBox::OKButtonClick(TObject *Sender)
{
  Hide();
}
//---------------------------------------------------------------------------


//----------------------------------------------------------------------------
#ifndef ConfigH
#define ConfigH
//----------------------------------------------------------------------------
#include <vcl\ExtCtrls.hpp>
#include <vcl\ComCtrls.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
//----------------------------------------------------------------------------
class TPagesDlg : public TForm
{
__published:
	TPanel *Panel1;
	TPanel *Panel2;
        TPageControl *PageControl;
        TTabSheet *TabSheetGeneral;
        TTabSheet *TabSheetOdnomAnaliz;
        TTabSheet *TabSheetNLinRegr;
	TButton *OKBtn;
	TButton *CancelBtn;
        TTabSheet *TabSheetFiles;
        TEdit *eMaxIter;
        TLabel *Label1;
        TEdit *eCriter;
        TLabel *Label2;
        TLabel *Label3;
        TEdit *eStartValue;
        TLabel *Label4;
        TEdit *eInitStep;
        TComboBox *cbMethod;
        TLabel *Label5;
private:
public:
	virtual __fastcall TPagesDlg(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TPagesDlg *PagesDlg;
//----------------------------------------------------------------------------
#endif    

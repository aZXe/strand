object ChildCalcMemo: TChildCalcMemo
  Left = 80
  Top = 131
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  ClientHeight = 212
  ClientWidth = 642
  Color = clBtnFace
  DockSite = True
  ParentFont = True
  FormStyle = fsMDIChild
  OldCreateOrder = True
  Position = poDefault
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 0
    Top = 0
    Width = 44
    Height = 13
    Caption = 'Function:'
  end
  object Memo1: TMemo
    Left = 0
    Top = 16
    Width = 441
    Height = 166
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Courier New'
    Font.Style = []
    Lines.Strings = (
      'neff_pr ='
      'a0 *'
      '  (nkachupr ^ a1) *'
      '  (nball    ^ a2) *'
      '  (nobestr  ^ a3) *'
      '  (npotent  ^ a4) *'
      '  (nud_ves  ^ a5) *'
      '  (ns_zhiv  ^ a6) *'
      '  (ns_r_z   ^ a7)'
      ' ')
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 0
    WordWrap = False
  end
  object btnStart: TButton
    Left = 0
    Top = 184
    Width = 441
    Height = 25
    Caption = '&Start optimization'
    TabOrder = 1
    OnClick = btnStartClick
  end
  object Memo2: TMemo
    Left = 444
    Top = 16
    Width = 197
    Height = 166
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Courier New'
    Font.Style = []
    Lines.Strings = (
      'neff_pr'
      'nkachupr'
      'nball'
      'nobestr'
      'npotent'
      'nud_ves'
      'ns_zhiv'
      'ns_r_z')
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 2
    WordWrap = False
  end
  object Button1: TButton
    Left = 444
    Top = 184
    Width = 197
    Height = 25
    Caption = '&Start optimization'
    TabOrder = 3
    OnClick = Button1Click
  end
end

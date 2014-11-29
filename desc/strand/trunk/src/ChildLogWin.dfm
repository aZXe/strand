object ChildLog: TChildLog
  Left = 35
  Top = 124
  Width = 736
  Height = 209
  Caption = 'Log'
  Color = clBtnFace
  Constraints.MinHeight = 100
  Constraints.MinWidth = 200
  DockSite = True
  ParentFont = True
  FormStyle = fsMDIChild
  OldCreateOrder = True
  Position = poDefault
  Visible = True
  OnClose = FormClose
  OnDestroy = FormDestroy
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 728
    Height = 182
    Align = alClient
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Courier New'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 0
    WordWrap = False
  end
end

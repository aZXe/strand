object ChildRegrMemo: TChildRegrMemo
  Left = 218
  Top = 183
  Width = 492
  Height = 269
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  BorderIcons = [biSystemMenu, biMaximize]
  Caption = 'Коэффициенты уравнения регрессии'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object meEquation: TMemo
    Left = 0
    Top = 0
    Width = 484
    Height = 50
    Align = alClient
    Constraints.MaxHeight = 50
    Constraints.MinHeight = 50
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Courier New'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object meParameters: TMemo
    Left = 0
    Top = 48
    Width = 484
    Height = 190
    Align = alBottom
    Constraints.MaxHeight = 190
    Constraints.MinHeight = 190
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Courier New'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssHorizontal
    TabOrder = 1
  end
end

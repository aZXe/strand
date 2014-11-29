object WeightForm: TWeightForm
  Left = 417
  Top = 167
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Веса'
  ClientHeight = 326
  ClientWidth = 192
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 285
    Width = 192
    Height = 41
    Align = alBottom
    TabOrder = 0
    object Button1: TButton
      Left = 108
      Top = 8
      Width = 74
      Height = 25
      Anchors = [akTop, akRight]
      Caption = 'Закрыть'
      Default = True
      TabOrder = 0
      OnClick = Button1Click
    end
  end
  object SG: TStringGrid
    Left = 0
    Top = 0
    Width = 192
    Height = 285
    Align = alClient
    ColCount = 2
    DefaultRowHeight = 17
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goEditing, goAlwaysShowEditor]
    TabOrder = 1
  end
end

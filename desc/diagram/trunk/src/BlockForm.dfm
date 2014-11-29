object BlockPropertyForm: TBlockPropertyForm
  Left = 217
  Top = 113
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Свойства'
  ClientHeight = 244
  ClientWidth = 327
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 12
    Top = 12
    Width = 36
    Height = 13
    Caption = 'Текст: '
  end
  object shBackground: TShape
    Left = 12
    Top = 128
    Width = 110
    Height = 25
    Pen.Style = psClear
    Shape = stRoundRect
    OnMouseUp = shBackgroundMouseUp
  end
  object Label2: TLabel
    Left = 12
    Top = 112
    Width = 57
    Height = 13
    Caption = 'Цвет фона:'
  end
  object shForeground: TShape
    Left = 12
    Top = 172
    Width = 110
    Height = 25
    Brush.Color = clBlack
    Pen.Style = psClear
    Shape = stRoundRect
    OnMouseUp = shForegroundMouseUp
  end
  object Label3: TLabel
    Left = 12
    Top = 156
    Width = 61
    Height = 13
    Caption = 'Цвет линий:'
  end
  object bOk: TButton
    Left = 12
    Top = 208
    Width = 75
    Height = 25
    Caption = 'Ok'
    Default = True
    TabOrder = 3
    OnClick = bOkClick
  end
  object bCancel: TButton
    Left = 120
    Top = 208
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 4
    OnClick = bCancelClick
  end
  object pFont: TPanel
    Left = 204
    Top = 28
    Width = 110
    Height = 41
    BevelInner = bvLowered
    Caption = 'Шрифт'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = pFontClick
  end
  object gbLineWidth: TGroupBox
    Left = 205
    Top = 80
    Width = 109
    Height = 153
    Caption = 'Толщина линий'
    TabOrder = 2
    object sbWidth1: TSpeedButton
      Left = 12
      Top = 16
      Width = 85
      Height = 22
      GroupIndex = 3
      Glyph.Data = {
        BE000000424DBE000000000000003E000000280000003C000000100000000100
        010000000000800000000000000000000000020000000000000000000000FFFF
        FF00FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFF
        FFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0000000000000
        0000FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFF
        FFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFF
        FFF0}
    end
    object sbWidth2: TSpeedButton
      Left = 12
      Top = 37
      Width = 85
      Height = 22
      GroupIndex = 3
      Glyph.Data = {
        BE000000424DBE000000000000003E000000280000003C000000100000000100
        010000000000800000000000000000000000020000000000000000000000FFFF
        FF00FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFF
        FFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0000000000000
        00000000000000000000FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFF
        FFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFF
        FFF0}
    end
    object sbWidth3: TSpeedButton
      Left = 12
      Top = 58
      Width = 85
      Height = 22
      GroupIndex = 3
      Glyph.Data = {
        BE000000424DBE000000000000003E000000280000003C000000100000000100
        010000000000800000000000000000000000020000000000000000000000FFFF
        FF00FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFF
        FFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0000000000000
        000000000000000000000000000000000000FFFFFFFFFFFFFFF0FFFFFFFFFFFF
        FFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFF
        FFF0}
    end
    object sbWidth4: TSpeedButton
      Left = 12
      Top = 79
      Width = 85
      Height = 22
      GroupIndex = 3
      Glyph.Data = {
        BE000000424DBE000000000000003E000000280000003C000000100000000100
        010000000000800000000000000000000000020000000000000000000000FFFF
        FF00FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFF
        FFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF00000000000000000000000000000
        000000000000000000000000000000000000FFFFFFFFFFFFFFF0FFFFFFFFFFFF
        FFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFF
        FFF0}
    end
    object sbWidth5: TSpeedButton
      Left = 12
      Top = 100
      Width = 85
      Height = 22
      GroupIndex = 3
      Glyph.Data = {
        BE000000424DBE000000000000003E000000280000003C000000100000000100
        010000000000800000000000000000000000020000000000000000000000FFFF
        FF00FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFF
        FFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF00000000000000000000000000000
        0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
        FFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFF
        FFF0}
    end
    object sbWidth6: TSpeedButton
      Left = 12
      Top = 121
      Width = 85
      Height = 22
      GroupIndex = 3
      Glyph.Data = {
        BE000000424DBE000000000000003E000000280000003C000000100000000100
        010000000000800000000000000000000000020000000000000000000000FFFF
        FF00FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFF
        FFF0FFFFFFFFFFFFFFF000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000FFFFFFFFFFFF
        FFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFFFFF0FFFFFFFFFFFF
        FFF0}
    end
  end
  object mText: TMemo
    Left = 12
    Top = 28
    Width = 185
    Height = 77
    TabOrder = 0
    WantReturns = False
  end
  object ColorDialog: TColorDialog
    Ctl3D = True
    Options = [cdAnyColor]
    Left = 148
    Top = 172
  end
  object FontDialog: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Times New Roman'
    Font.Style = []
    MinFontSize = 0
    MaxFontSize = 0
    Left = 144
    Top = 116
  end
end

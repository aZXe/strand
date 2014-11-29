object BlockIndicatorPropertyForm: TBlockIndicatorPropertyForm
  Left = 191
  Top = 164
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Свойства'
  ClientHeight = 302
  ClientWidth = 370
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
    Left = 132
    Top = 128
    Width = 110
    Height = 25
    Brush.Color = clBlack
    Pen.Style = psClear
    Shape = stRoundRect
    OnMouseUp = shForegroundMouseUp
  end
  object Label3: TLabel
    Left = 132
    Top = 112
    Width = 61
    Height = 13
    Caption = 'Цвет линий:'
  end
  object shIndicatorBackground: TShape
    Left = 12
    Top = 176
    Width = 110
    Height = 25
    Pen.Style = psClear
    Shape = stRoundRect
    OnMouseUp = shIndicatorBackgroundMouseUp
  end
  object Label5: TLabel
    Left = 12
    Top = 160
    Width = 91
    Height = 13
    Caption = 'Фон индикатора: '
  end
  object shIndicatorForeground: TShape
    Left = 132
    Top = 176
    Width = 110
    Height = 25
    Brush.Color = clGreen
    Pen.Style = psClear
    Shape = stRoundRect
    OnMouseUp = shIndicatorForegroundMouseUp
  end
  object Label6: TLabel
    Left = 132
    Top = 160
    Width = 93
    Height = 13
    Caption = 'Цвет индикатора: '
  end
  object Label7: TLabel
    Left = 12
    Top = 212
    Width = 112
    Height = 13
    Caption = 'Позиция индикатора: '
  end
  object mText: TMemo
    Left = 12
    Top = 28
    Width = 229
    Height = 77
    TabOrder = 0
    WantReturns = False
  end
  object bOk: TButton
    Left = 12
    Top = 268
    Width = 75
    Height = 25
    Caption = 'Ok'
    Default = True
    TabOrder = 6
    OnClick = bOkClick
  end
  object bCancel: TButton
    Left = 284
    Top = 268
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 7
    OnClick = bCancelClick
  end
  object pFont: TPanel
    Left = 248
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
  object ePosition: TEdit
    Left = 124
    Top = 208
    Width = 37
    Height = 21
    TabOrder = 2
    Text = '0'
  end
  object UpDown1: TUpDown
    Left = 161
    Top = 208
    Width = 14
    Height = 21
    Associate = ePosition
    Min = 0
    Position = 0
    TabOrder = 3
    Wrap = False
  end
  object gbLineWidth: TGroupBox
    Left = 249
    Top = 76
    Width = 109
    Height = 153
    Caption = 'Толщина линий'
    TabOrder = 4
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
  object cbIndicatorVisible: TCheckBox
    Left = 8
    Top = 236
    Width = 137
    Height = 17
    Alignment = taLeftJustify
    Caption = 'Видимость индикатора'
    Checked = True
    State = cbChecked
    TabOrder = 5
  end
  object ColorDialog: TColorDialog
    Ctl3D = True
    Options = [cdAnyColor]
    Left = 240
  end
  object FontDialog: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Times New Roman'
    Font.Style = []
    MinFontSize = 0
    MaxFontSize = 0
    Left = 212
  end
end

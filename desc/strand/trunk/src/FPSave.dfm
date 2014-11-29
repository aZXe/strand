object FPSaveForm: TFPSaveForm
  Left = 345
  Top = 187
  ActiveControl = eName
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Сохранение'
  ClientHeight = 110
  ClientWidth = 186
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object lName: TLabel
    Left = 12
    Top = 12
    Width = 162
    Height = 13
    Caption = 'Введите имя фактор-признака: '
    FocusControl = eName
  end
  object lPrefix: TLabel
    Left = 12
    Top = 32
    Width = 12
    Height = 20
    Caption = 'F'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object eName: TEdit
    Left = 24
    Top = 32
    Width = 149
    Height = 21
    TabOrder = 0
  end
  object bOk: TButton
    Left = 12
    Top = 72
    Width = 75
    Height = 25
    Caption = 'Ok'
    Default = True
    TabOrder = 1
    OnClick = bOkClick
  end
  object bCancel: TButton
    Left = 96
    Top = 72
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 2
    OnClick = bCancelClick
  end
end

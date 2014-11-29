object CreateParametersForm: TCreateParametersForm
  Left = 211
  Top = 189
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Создание'
  ClientHeight = 125
  ClientWidth = 216
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 4
    Top = 8
    Width = 205
    Height = 69
    Caption = 'Введите'
    TabOrder = 0
    object Label1: TLabel
      Left = 12
      Top = 20
      Width = 115
      Height = 13
      Caption = 'Количество столбцов: '
    end
    object Label2: TLabel
      Left = 32
      Top = 44
      Width = 94
      Height = 13
      Caption = 'Количество строк:'
    end
    object Edit1: TEdit
      Left = 128
      Top = 16
      Width = 29
      Height = 21
      TabOrder = 0
      Text = '1'
    end
    object UpDown1: TUpDown
      Left = 157
      Top = 16
      Width = 16
      Height = 21
      Associate = Edit1
      Min = 1
      Position = 1
      TabOrder = 1
      Wrap = False
    end
    object UpDown2: TUpDown
      Left = 157
      Top = 40
      Width = 16
      Height = 21
      Associate = Edit2
      Min = 15
      Max = 10000
      Position = 15
      TabOrder = 2
      Wrap = False
    end
    object Edit2: TEdit
      Left = 128
      Top = 40
      Width = 29
      Height = 21
      TabOrder = 3
      Text = '15'
    end
  end
  object Button1: TButton
    Left = 8
    Top = 88
    Width = 75
    Height = 25
    Caption = 'Ok'
    Default = True
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 132
    Top = 88
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 2
    OnClick = Button2Click
  end
end

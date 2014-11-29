object ParamsForm: TParamsForm
  Left = 241
  Top = 98
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Параметры'
  ClientHeight = 348
  ClientWidth = 208
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 48
    Top = 12
    Width = 26
    Height = 13
    Caption = 'alpha'
  end
  object Label2: TLabel
    Left = 52
    Top = 40
    Width = 24
    Height = 13
    Caption = 'betta'
  end
  object Label3: TLabel
    Left = 40
    Top = 68
    Width = 34
    Height = 13
    Caption = 'gamma'
  end
  object Label4: TLabel
    Left = 52
    Top = 96
    Width = 23
    Height = 13
    Caption = 'delta'
  end
  object Label5: TLabel
    Left = 60
    Top = 124
    Width = 14
    Height = 13
    Caption = 'phi'
  end
  object Label6: TLabel
    Left = 52
    Top = 152
    Width = 24
    Height = 13
    Caption = 'theta'
  end
  object Label7: TLabel
    Left = 36
    Top = 212
    Width = 38
    Height = 13
    Caption = 'c_alpha'
  end
  object Label8: TLabel
    Left = 60
    Top = 184
    Width = 13
    Height = 13
    Caption = 'psi'
  end
  object Label9: TLabel
    Left = 36
    Top = 268
    Width = 37
    Height = 13
    Caption = 'p_max2'
  end
  object Label10: TLabel
    Left = 36
    Top = 240
    Width = 37
    Height = 13
    Caption = 'p_max1'
  end
  object Button1: TButton
    Left = 72
    Top = 316
    Width = 75
    Height = 25
    Caption = 'Ok'
    Default = True
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 80
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 1
    Text = '1,3'
  end
  object Edit2: TEdit
    Left = 80
    Top = 36
    Width = 121
    Height = 21
    TabOrder = 2
    Text = '1'
  end
  object Edit3: TEdit
    Left = 80
    Top = 64
    Width = 121
    Height = 21
    TabOrder = 3
    Text = '0,2'
  end
  object Edit4: TEdit
    Left = 80
    Top = 92
    Width = 121
    Height = 21
    TabOrder = 4
    Text = '1,1'
  end
  object Edit5: TEdit
    Left = 80
    Top = 120
    Width = 121
    Height = 21
    TabOrder = 5
    Text = '0,5'
  end
  object Edit6: TEdit
    Left = 80
    Top = 148
    Width = 121
    Height = 21
    TabOrder = 6
    Text = '1,75'
  end
  object Edit7: TEdit
    Left = 80
    Top = 180
    Width = 121
    Height = 21
    TabOrder = 7
    Text = '1,5'
  end
  object Edit8: TEdit
    Left = 80
    Top = 208
    Width = 121
    Height = 21
    TabOrder = 8
    Text = '2'
  end
  object Edit9: TEdit
    Left = 80
    Top = 236
    Width = 121
    Height = 21
    TabOrder = 9
    Text = '0,90'
  end
  object Edit10: TEdit
    Left = 80
    Top = 264
    Width = 121
    Height = 21
    TabOrder = 10
    Text = '0,95'
  end
  object cbFirstEtap: TCheckBox
    Left = 4
    Top = 292
    Width = 201
    Height = 17
    Caption = 'Проводить отбрасывание на 1 эт.'
    TabOrder = 11
  end
end

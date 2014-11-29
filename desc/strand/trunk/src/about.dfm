object AboutBox: TAboutBox
  Left = 444
  Top = 127
  ActiveControl = OKButton
  BorderStyle = bsDialog
  Caption = 'About'
  ClientHeight = 195
  ClientWidth = 281
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clBlack
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = True
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 281
    Height = 161
    BevelOuter = bvLowered
    TabOrder = 0
    object ProgramIcon: TImage
      Left = 8
      Top = 8
      Width = 65
      Height = 57
      Picture.Data = {
        055449636F6E0000010001002020100000000000E80200001600000028000000
        2000000040000000010004000000000080020000000000000000000000000000
        0000000000000000000080000080000000808000800000008000800080800000
        C0C0C000808080000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000
        FFFFFF00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF77FFFFFFFFFFF88FFFFFFFF9
        7FFFFFFF997FFFFFFFFFFF00FFFFFF999FFFFFFFF997FFFFFFFFFFF00FFFF997
        FFFFFFFFFF997FFFFFFFFFFF0FFF797FFFFFFFFFFFF99FFFFFFFFFFF70FF99FF
        FFFFFFFFFFF797FFFFFFFFFFF0879FFFFFFFFFFFFFFF99FFFFFFFFFFFF099FFF
        FFFFFFFFFFFF79FFFFFFFFFFFF09FFFFFFFFFFFFFFFFF97FFFFFFFFFFF07FFFF
        FFFFFFFFFFFFF39FFFFFFFFFFF00FFFFFFFFFFFFFFFFF99FFFFFFFFFFF90FFFF
        FFFFFFFFFFFFF79FFFFFFFFFFF90FFFFFFFFFFFFFFFFFF97FFFFFFFFF7300FFF
        FFFFFFF0FFFFFF97FFFFFFFFF7900FFFFFFFFFF0FFFFFF99FFFFFFFFF9900FFF
        FFFFFFF0FFFFFF99FFFFFFFFF99F0FFFFFFFFFF0FFFFFF79FFFFFFFFF97F00FF
        FFFFFF00FFFFFF79FFFFFFFF797F80FFFFFFFF08FFFFFFF97FFFFFFF39FFF0FF
        FFFFFF0FFFFFFFF99FFFFFFF99FFF00FFFFFF00FFFFFFFF79FFFFFF797FFFF00
        FFFF00FFFFFFFFFF99FFFFF99FFFFFF000000FFFFFFFFFFF799FFF99FFFFFFFF
        8008FFFFFFFFFFFFF7999997FFFFFFFFFFFFFFFFFFFFFFFFFF7997FFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFF00000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000}
      IsControl = True
    end
    object ProductName: TLabel
      Left = 88
      Top = 8
      Width = 71
      Height = 13
      Caption = 'Product Name:'
      IsControl = True
    end
    object Version1: TLabel
      Left = 88
      Top = 66
      Width = 38
      Height = 14
      Caption = 'Version:'
      IsControl = True
    end
    object Copyright1: TLabel
      Left = 8
      Top = 82
      Width = 47
      Height = 13
      Caption = 'Copyright:'
      IsControl = True
    end
    object Comments1: TLabel
      Left = 8
      Top = 128
      Width = 52
      Height = 13
      Caption = 'Comments:'
      WordWrap = True
      IsControl = True
    end
    object Version: TLabel
      Left = 128
      Top = 66
      Width = 43
      Height = 14
      Caption = 'Version'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object AppName: TLabel
      Left = 160
      Top = 8
      Width = 113
      Height = 59
      AutoSize = False
      Caption = 'AppName'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      WordWrap = True
    end
    object Copyright: TLabel
      Left = 58
      Top = 82
      Width = 216
      Height = 41
      AutoSize = False
      Caption = 'Copyright'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      WordWrap = True
    end
    object Comments: TLabel
      Left = 64
      Top = 128
      Width = 58
      Height = 13
      Caption = 'Comments'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
  object OKButton: TButton
    Left = 112
    Top = 170
    Width = 81
    Height = 23
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 1
    OnClick = OKButtonClick
    IsControl = True
  end
end

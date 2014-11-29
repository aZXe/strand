object Form1: TForm1
  Left = 19
  Top = 113
  Width = 759
  Height = 462
  Caption = 'Классификация и т. п.'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object MainGrid: TStringGrid
    Left = 0
    Top = 0
    Width = 751
    Height = 360
    Align = alClient
    DefaultRowHeight = 15
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 0
    Top = 399
    Width = 751
    Height = 17
    Align = alBottom
    Alignment = taLeftJustify
    BevelOuter = bvNone
    TabOrder = 1
    object Panel2: TPanel
      Left = 408
      Top = 0
      Width = 343
      Height = 17
      Align = alRight
      BevelOuter = bvLowered
      TabOrder = 0
      object Progress: TCGauge
        Left = 1
        Top = 1
        Width = 341
        Height = 15
        Align = alClient
        Color = clBtnFace
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clCaptionText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        BorderStyle = bsNone
        ForeColor = clActiveCaption
        BackColor = clBtnFace
        ParentColor = False
        ParentFont = False
        Visible = False
      end
    end
    object Panel3: TPanel
      Left = 0
      Top = 0
      Width = 408
      Height = 17
      Align = alClient
      Alignment = taLeftJustify
      BevelOuter = bvLowered
      TabOrder = 1
    end
  end
  object Panel4: TPanel
    Left = 0
    Top = 360
    Width = 751
    Height = 39
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    object Button4: TButton
      Left = 4
      Top = 6
      Width = 97
      Height = 25
      Caption = 'Классификация'
      TabOrder = 0
      OnClick = Button4Click
    end
    object ePorog: TEdit
      Left = 264
      Top = 8
      Width = 121
      Height = 21
      TabOrder = 1
      Text = '0,35'
    end
  end
  object SG1: TStringGrid
    Left = 256
    Top = 152
    Width = 489
    Height = 169
    DefaultRowHeight = 15
    TabOrder = 3
    Visible = False
  end
  object OpenStaDialog: TOpenDialog
    Filter = 'Statistica Data|*.sta'
    Left = 72
    Top = 152
  end
  object SaveStaDialog: TSaveDialog
    Filter = 'Statistica Data|*.sta'
    Left = 104
    Top = 152
  end
  object MainMenu1: TMainMenu
    Left = 40
    Top = 152
    object N1: TMenuItem
      Caption = '&Файл'
      object N2: TMenuItem
        Caption = '&Открыть...'
        ShortCut = 16463
        OnClick = N2Click
      end
      object N5: TMenuItem
        Caption = '&Сохранить...'
        ShortCut = 16467
        OnClick = N5Click
      end
      object N6: TMenuItem
        Caption = '-'
      end
      object N8: TMenuItem
        Caption = 'Веса...'
        ShortCut = 16471
        OnClick = N8Click
      end
      object N3: TMenuItem
        Caption = '&Параметры...'
        ShortCut = 16464
        OnClick = N3Click
      end
      object N4: TMenuItem
        Caption = '-'
      end
      object N7: TMenuItem
        Caption = 'Exit'
        ShortCut = 16472
        OnClick = N7Click
      end
    end
  end
  object ActionList1: TActionList
    Left = 136
    Top = 152
    object ActionKlassif: TAction
      Caption = 'ActionKlassif'
      OnExecute = ActionKlassifExecute
    end
  end
end

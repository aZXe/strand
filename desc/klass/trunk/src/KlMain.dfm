object Form1: TForm1
  Left = 23
  Top = 103
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
    Height = 341
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
    Top = 341
    Width = 751
    Height = 58
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    object Label1: TLabel
      Left = 112
      Top = -1
      Width = 53
      Height = 26
      Caption = 'Объектов в классах:'
      WordWrap = True
    end
    object Label2: TLabel
      Left = 216
      Top = 0
      Width = 120
      Height = 26
      Caption = 'Номер первого класса второй группы:'
      WordWrap = True
    end
    object Label3: TLabel
      Left = 384
      Top = 0
      Width = 70
      Height = 26
      Caption = 'Количество объединений:'
      WordWrap = True
    end
    object Label4: TLabel
      Left = 512
      Top = 0
      Width = 119
      Height = 26
      Caption = 'Количество присоединенных точек:'
      WordWrap = True
    end
    object Label5: TLabel
      Left = 0
      Top = 0
      Width = 59
      Height = 26
      Caption = 'Количество классов:'
      WordWrap = True
    end
    object eLeft: TEdit
      Left = 168
      Top = 3
      Width = 41
      Height = 21
      TabOrder = 0
    end
    object eFirst: TEdit
      Left = 336
      Top = 3
      Width = 41
      Height = 21
      TabOrder = 1
      Text = '22'
    end
    object Button1: TButton
      Left = 112
      Top = 30
      Width = 75
      Height = 25
      Caption = 'Просеять'
      TabOrder = 2
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 240
      Top = 30
      Width = 113
      Height = 25
      Caption = 'Объединить классы'
      TabOrder = 3
      OnClick = Button2Click
    end
    object eUnions: TEdit
      Left = 456
      Top = 3
      Width = 49
      Height = 21
      TabOrder = 4
    end
    object Button3: TButton
      Left = 360
      Top = 30
      Width = 113
      Height = 25
      Caption = 'Присоединить точки'
      TabOrder = 5
      OnClick = Button3Click
    end
    object ePrisoed: TEdit
      Left = 632
      Top = 3
      Width = 41
      Height = 21
      TabOrder = 6
    end
    object eKlass: TEdit
      Left = 64
      Top = 3
      Width = 41
      Height = 21
      TabOrder = 7
    end
    object Button4: TButton
      Left = 0
      Top = 30
      Width = 97
      Height = 25
      Caption = 'Классификация'
      TabOrder = 8
      OnClick = Button4Click
    end
    object eAlphaProsein: TEdit
      Left = 192
      Top = 32
      Width = 41
      Height = 21
      TabOrder = 9
      Text = '1,75'
    end
  end
  object SG1: TStringGrid
    Left = 256
    Top = 152
    Width = 489
    Height = 169
    DefaultRowHeight = 15
    TabOrder = 3
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
      object N3: TMenuItem
        Caption = '&Анализ'
        ShortCut = 16449
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
    object ActionProsein: TAction
      Caption = 'ActionProsein'
      OnExecute = ActionProseinExecute
    end
    object ActionUnion: TAction
      Caption = 'ActionUnion'
      OnExecute = ActionUnionExecute
    end
    object ActionPrisoed: TAction
      Caption = 'ActionPrisoed'
      OnExecute = ActionPrisoedExecute
    end
    object ActionKlassif: TAction
      Caption = 'ActionKlassif'
      OnExecute = ActionKlassifExecute
    end
  end
end

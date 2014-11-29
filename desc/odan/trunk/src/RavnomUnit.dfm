object Form1: TForm1
  Left = 307
  Top = 217
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Одномерный анализ v.1.0'
  ClientHeight = 450
  ClientWidth = 729
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object SGrid: TStringGrid
    Left = 0
    Top = 0
    Width = 729
    Height = 281
    DefaultRowHeight = 15
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 0
    RowHeights = (
      15
      15
      15
      15
      15)
  end
  object btnOdnomAnaliz: TButton
    Left = 0
    Top = 408
    Width = 169
    Height = 25
    Caption = 'Одномерный анализ признака:'
    TabOrder = 1
    OnClick = btnOdnomAnalizClick
  end
  object Panel: TPanel
    Left = 0
    Top = 432
    Width = 729
    Height = 17
    Alignment = taLeftJustify
    BevelOuter = bvLowered
    TabOrder = 2
    object Progress: TCGauge
      Left = 288
      Top = 1
      Width = 441
      Height = 15
      Color = clGreen
      BorderStyle = bsNone
      ForeColor = clGreen
      ParentColor = False
      Visible = False
    end
  end
  object RGrid: TStringGrid
    Left = 0
    Top = 280
    Width = 729
    Height = 129
    DefaultRowHeight = 15
    TabOrder = 3
  end
  object eWeigh: TEdit
    Left = 384
    Top = 408
    Width = 65
    Height = 21
    TabOrder = 4
  end
  object Button1: TButton
    Left = 240
    Top = 408
    Width = 145
    Height = 25
    Caption = 'Номер переменной весов:'
    TabOrder = 5
  end
  object eNomer: TEdit
    Left = 168
    Top = 408
    Width = 73
    Height = 21
    TabOrder = 6
    Text = '1'
  end
  object OpenStaDialog: TOpenDialog
    Filter = 'Statistica Data|*.sta'
    Left = 40
    Top = 224
  end
  object MainMenu1: TMainMenu
    Left = 176
    Top = 224
    object N1: TMenuItem
      Caption = '&Файл'
      object miCreate: TMenuItem
        Caption = 'Создать...'
        ShortCut = 16462
        OnClick = miCreateClick
      end
      object N2: TMenuItem
        Caption = '&Открыть файл данных...'
        ShortCut = 16463
        OnClick = N2Click
      end
      object N8: TMenuItem
        Caption = '&Сохранить файл данных...'
        ShortCut = 16467
        OnClick = N8Click
      end
      object N6: TMenuItem
        Caption = 'Сохранить &результаты...'
        ShortCut = 16466
        OnClick = N6Click
      end
      object N5: TMenuItem
        Caption = '-'
      end
      object N7: TMenuItem
        Caption = 'Одномерный &анализ (All)'
        ShortCut = 16449
        OnClick = N7Click
      end
      object N10: TMenuItem
        Caption = '&Настройка анализа...'
        OnClick = N10Click
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object N4: TMenuItem
        Caption = '&Выход'
        ShortCut = 16472
        OnClick = N4Click
      end
    end
  end
  object SaveStaDialog: TSaveDialog
    Filter = 'Statistica Data|*.sta'
    Left = 72
    Top = 224
  end
end

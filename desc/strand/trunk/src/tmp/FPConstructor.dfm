object FPConstructorForm: TFPConstructorForm
  Left = 70
  Top = 107
  Width = 700
  Height = 400
  ActiveControl = lbVars
  Caption = 'Конструктор фактор-признаков'
  Color = clBtnFace
  Constraints.MinHeight = 400
  Constraints.MinWidth = 700
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefaultPosOnly
  Visible = True
  OnClose = FormClose
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object pOptions: TPanel
    Left = 0
    Top = 324
    Width = 692
    Height = 49
    Align = alBottom
    TabOrder = 0
    object bCalculate: TButton
      Left = 140
      Top = 12
      Width = 75
      Height = 25
      Caption = 'Рассчет'
      Default = True
      TabOrder = 0
      OnClick = bCalculateClick
    end
    object bSave: TButton
      Left = 292
      Top = 12
      Width = 149
      Height = 25
      Anchors = [akLeft, akTop, akRight, akBottom]
      Caption = 'Сохранить фактор-признак'
      TabOrder = 1
    end
    object gbMainVar: TGroupBox
      Left = 1
      Top = 1
      Width = 131
      Height = 47
      Align = alLeft
      Caption = 'Целевой признак'
      TabOrder = 2
      object cbMainVar: TComboBox
        Left = 8
        Top = 16
        Width = 113
        Height = 21
        DropDownCount = 255
        ItemHeight = 13
        TabOrder = 0
        OnChange = cbMainVarChange
        OnKeyDown = cbMainVarKeyDown
        OnKeyPress = cbMainVarKeyPress
      end
    end
    object bClose: TButton
      Left = 604
      Top = 12
      Width = 75
      Height = 25
      Anchors = [akTop, akRight, akBottom]
      Caption = 'Закрыть'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = bCloseClick
    end
  end
  object pCorrelation: TPanel
    Left = 443
    Top = 0
    Width = 249
    Height = 324
    Align = alRight
    TabOrder = 1
    object gbCorrelation: TGroupBox
      Left = 1
      Top = 1
      Width = 247
      Height = 44
      Align = alTop
      Caption = 'Корреляционная матрица'
      TabOrder = 0
      object lLimit: TLabel
        Left = 4
        Top = 20
        Width = 37
        Height = 13
        Caption = 'Порог: '
      end
      object eLimit: TEdit
        Left = 40
        Top = 16
        Width = 33
        Height = 21
        ReadOnly = True
        TabOrder = 0
        Text = '0,30'
      end
      object cbColor: TCheckBox
        Left = 104
        Top = 16
        Width = 53
        Height = 17
        Caption = 'Цвет'
        Checked = True
        State = cbChecked
        TabOrder = 1
        OnClick = cbColorClick
      end
      object cbNumbers: TCheckBox
        Left = 164
        Top = 16
        Width = 73
        Height = 17
        Caption = 'Значения'
        Checked = True
        State = cbChecked
        TabOrder = 2
        OnClick = cbNumbersClick
      end
      object udLimit: TUpDown
        Left = 72
        Top = 16
        Width = 15
        Height = 22
        Min = 1
        Max = 19
        Position = 6
        TabOrder = 3
        Wrap = False
        OnChangingEx = udLimitChangingEx
      end
    end
  end
  object pVars: TPanel
    Left = 0
    Top = 0
    Width = 133
    Height = 324
    Align = alLeft
    TabOrder = 2
    object lVars: TLabel
      Left = 1
      Top = 1
      Width = 131
      Height = 20
      Align = alTop
      AutoSize = False
      Caption = 'Признаки:'
      Color = clBtnFace
      FocusControl = lbVars
      ParentColor = False
    end
    object lbVars: TListBox
      Left = 1
      Top = 21
      Width = 84
      Height = 187
      Align = alLeft
      ItemHeight = 13
      TabOrder = 0
    end
    object bOneToDiagram: TButton
      Left = 96
      Top = 36
      Width = 25
      Height = 29
      Caption = '>'
      TabOrder = 1
      OnClick = bOneToDiagramClick
    end
    object bAllToDiagram: TButton
      Left = 96
      Top = 68
      Width = 25
      Height = 29
      Caption = '>>'
      TabOrder = 2
      OnClick = bAllToDiagramClick
    end
    object bOneFromDiagram: TButton
      Left = 96
      Top = 132
      Width = 25
      Height = 29
      Caption = '<'
      TabOrder = 3
      OnClick = bOneFromDiagramClick
    end
    object bAllFromDiagram: TButton
      Left = 96
      Top = 164
      Width = 25
      Height = 29
      Caption = '<<'
      TabOrder = 4
      OnClick = bAllFromDiagramClick
    end
    object gbKindRegression: TGroupBox
      Left = 1
      Top = 254
      Width = 131
      Height = 69
      Align = alBottom
      Caption = 'Вид зависимости'
      TabOrder = 5
      object rbAddRegression: TRadioButton
        Left = 4
        Top = 20
        Width = 113
        Height = 17
        Caption = 'аддитивная'
        TabOrder = 0
      end
      object rbMultRegression: TRadioButton
        Left = 4
        Top = 40
        Width = 121
        Height = 17
        Caption = 'мультипликативная'
        Checked = True
        TabOrder = 1
        TabStop = True
      end
    end
    object GroupBox1: TGroupBox
      Left = 1
      Top = 208
      Width = 131
      Height = 46
      Align = alBottom
      Caption = 'Размещение блоков'
      TabOrder = 6
      object sbAllocation1: TSpeedButton
        Left = 12
        Top = 16
        Width = 23
        Height = 22
        GroupIndex = 1
        Down = True
        Flat = True
        Glyph.Data = {
          7E000000424D7E000000000000003E0000002800000010000000100000000100
          010000000000400000000000000000000000020000000000000000000000FFFF
          FF00FFFF00000FFF00006FFF00000FFF0000FFFF00000FFF00006FE100000FDE
          0000FFDE00000FDE00006FE100000FFF0000FFFF00000FFF00006FFF00000FFF
          0000}
        OnClick = sbAllocationClick
      end
      object sbAllocation2: TSpeedButton
        Left = 54
        Top = 16
        Width = 23
        Height = 22
        GroupIndex = 1
        Flat = True
        Glyph.Data = {
          7E000000424D7E000000000000003E0000002800000010000000100000000100
          010000000000400000000000000000000000020000000000000000000000FFFF
          FF00FFFF00000FF000006FF600000FF00000FFFF00000FF000006C3600000BD0
          0000FBDF00000BD000006C3600000FF00000FFFF00000FF000006FF600000FF0
          0000}
        OnClick = sbAllocationClick
      end
      object sbAllocation3: TSpeedButton
        Left = 96
        Top = 16
        Width = 23
        Height = 22
        GroupIndex = 1
        Flat = True
        Glyph.Data = {
          7E000000424D7E000000000000003E0000002800000010000000100000000100
          010000000000400000000000000000000000020000000000000000000000FFFF
          FF00FFFF0000E1870000EDB70000E1870000FFFF00000FF000006C3600000BD0
          0000FBDF00000BD000006C3600000FF00000FFFF0000E1870000EDB70000E187
          0000}
        OnClick = sbAllocationClick
      end
    end
  end
  object pDiagram: TPanel
    Left = 133
    Top = 0
    Width = 310
    Height = 324
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 3
    object sbDiagram: TScrollBox
      Left = 0
      Top = 21
      Width = 310
      Height = 303
      Align = alClient
      Color = clWhite
      ParentColor = False
      TabOrder = 0
    end
    object pMisc: TPanel
      Left = 0
      Top = 0
      Width = 310
      Height = 21
      Align = alTop
      TabOrder = 1
      object lDiagram: TLabel
        Left = 1
        Top = 1
        Width = 157
        Height = 13
        Caption = 'Диаграмма фактор-признака: '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object lCorrelation: TLabel
        Left = 252
        Top = 1
        Width = 46
        Height = 13
        Anchors = [akTop, akRight]
        Caption = 'R = ???'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
    end
  end
end

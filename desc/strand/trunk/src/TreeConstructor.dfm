object TreeConstructorForm: TTreeConstructorForm
  Left = 79
  Top = 109
  Width = 700
  Height = 460
  ActiveControl = lbVars
  Caption = 'Конструктор деревьев взаимосвязей'
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
    Top = 382
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
    object gbMainVar: TGroupBox
      Left = 1
      Top = 1
      Width = 131
      Height = 47
      Align = alLeft
      Caption = 'Целевой признак'
      TabOrder = 1
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
      TabOrder = 2
      OnClick = bCloseClick
    end
    object bSave: TButton
      Left = 256
      Top = 12
      Width = 75
      Height = 25
      Caption = 'Сохранить'
      TabOrder = 3
    end
    object chbIndicatorVisible: TCheckBox
      Left = 364
      Top = 16
      Width = 197
      Height = 17
      Caption = 'Показывать значения признаков'
      TabOrder = 4
      OnClick = chbIndicatorVisibleClick
    end
  end
  object pVars: TPanel
    Left = 0
    Top = 0
    Width = 133
    Height = 382
    Align = alLeft
    TabOrder = 1
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
      Height = 291
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
    object bOneFromDiagram: TButton
      Left = 96
      Top = 172
      Width = 25
      Height = 29
      Caption = '<'
      TabOrder = 2
      OnClick = bOneFromDiagramClick
    end
    object gbKindRegression: TGroupBox
      Left = 1
      Top = 312
      Width = 131
      Height = 69
      Align = alBottom
      Caption = 'Вид зависимости'
      TabOrder = 3
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
    object Panel1: TPanel
      Left = 84
      Top = 68
      Width = 49
      Height = 97
      BevelInner = bvRaised
      TabOrder = 4
      OnMouseDown = Panel1MouseDown
      OnMouseUp = Panel1MouseUp
      object Label1: TLabel
        Left = 4
        Top = 8
        Width = 43
        Height = 84
        Caption = 'Интерпре тация схемы формиров ания целевого признака'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -9
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        WordWrap = True
        OnMouseDown = Panel1MouseDown
        OnMouseUp = Panel1MouseUp
      end
    end
  end
  object pDiagram: TPanel
    Left = 133
    Top = 0
    Width = 559
    Height = 382
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 2
    object sbDiagram: TScrollBox
      Left = 0
      Top = 21
      Width = 559
      Height = 361
      Align = alClient
      Color = clWhite
      ParentColor = False
      TabOrder = 0
    end
    object pMisc: TPanel
      Left = 0
      Top = 0
      Width = 559
      Height = 21
      Align = alTop
      TabOrder = 1
      object lDiagram: TLabel
        Left = 1
        Top = 1
        Width = 122
        Height = 13
        Caption = 'Дерево взаимосвязей: '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
    end
  end
end

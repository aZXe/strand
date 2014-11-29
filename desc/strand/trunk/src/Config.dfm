object PagesDlg: TPagesDlg
  Left = 213
  Top = 107
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Параметры'
  ClientHeight = 351
  ClientWidth = 517
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 517
    Height = 317
    Align = alClient
    BevelOuter = bvNone
    BorderWidth = 5
    ParentColor = True
    TabOrder = 0
    object PageControl: TPageControl
      Left = 5
      Top = 5
      Width = 507
      Height = 307
      ActivePage = TabSheetNLinRegr
      Align = alClient
      TabOrder = 0
      object TabSheetGeneral: TTabSheet
        Caption = 'Общие'
      end
      object TabSheetOdnomAnaliz: TTabSheet
        Caption = 'Одномерный анализ'
      end
      object TabSheetNLinRegr: TTabSheet
        Caption = 'Нелинейная регрессия'
        object Label1: TLabel
          Left = 3
          Top = 42
          Width = 191
          Height = 13
          Caption = 'Максимальное количество &итераций:'
          FocusControl = eMaxIter
        end
        object Label2: TLabel
          Left = 80
          Top = 60
          Width = 114
          Height = 13
          Caption = 'Критерий &сходимости:'
          FocusControl = eCriter
        end
        object Label3: TLabel
          Left = 22
          Top = 78
          Width = 172
          Height = 13
          Caption = 'Начальное значение &параметров:'
          FocusControl = eStartValue
        end
        object Label4: TLabel
          Left = 58
          Top = 96
          Width = 136
          Height = 13
          Caption = 'Начальное значение &шага:'
          FocusControl = eInitStep
        end
        object Label5: TLabel
          Left = 88
          Top = 16
          Width = 106
          Height = 13
          Caption = '&Метод приближения:'
          FocusControl = cbMethod
        end
        object eMaxIter: TEdit
          Left = 200
          Top = 40
          Width = 57
          Height = 21
          TabOrder = 1
          Text = '100'
        end
        object eCriter: TEdit
          Left = 200
          Top = 59
          Width = 57
          Height = 21
          TabOrder = 2
          Text = '0,0001'
        end
        object eStartValue: TEdit
          Left = 200
          Top = 77
          Width = 57
          Height = 21
          TabOrder = 3
          Text = '0,1'
        end
        object eInitStep: TEdit
          Left = 200
          Top = 96
          Width = 57
          Height = 21
          TabOrder = 4
          Text = '0,5'
        end
        object cbMethod: TComboBox
          Left = 200
          Top = 12
          Width = 145
          Height = 21
          Ctl3D = True
          DropDownCount = 2
          ItemHeight = 13
          ParentCtl3D = False
          TabOrder = 0
          Items.Strings = (
            'Gauss-Newton'
            'Levenberg-Marquardt')
        end
      end
      object TabSheetFiles: TTabSheet
        Caption = 'Файлы/Каталоги'
        ImageIndex = 3
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 317
    Width = 517
    Height = 34
    Align = alBottom
    BevelOuter = bvNone
    ParentColor = True
    TabOrder = 1
    object OKBtn: TButton
      Left = 187
      Top = 2
      Width = 75
      Height = 25
      Caption = 'OK'
      Default = True
      ModalResult = 1
      TabOrder = 0
    end
    object CancelBtn: TButton
      Left = 267
      Top = 2
      Width = 75
      Height = 25
      Cancel = True
      Caption = 'Cancel'
      ModalResult = 2
      TabOrder = 1
    end
  end
end

object Graph: TGraph
  Left = 213
  Top = 126
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  AutoScroll = False
  ClientHeight = 361
  ClientWidth = 500
  Color = clBtnFace
  Constraints.MaxHeight = 600
  Constraints.MaxWidth = 800
  Constraints.MinHeight = 100
  Constraints.MinWidth = 100
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Panel: TPanel
    Left = 0
    Top = 0
    Width = 500
    Height = 361
    Align = alClient
    BevelOuter = bvNone
    Ctl3D = False
    ParentCtl3D = False
    TabOrder = 1
    object Image: TImage
      Left = 1
      Top = 1
      Width = 498
      Height = 360
    end
  end
  object btnSave: TButton
    Left = 424
    Top = 0
    Width = 49
    Height = 17
    Caption = '&Save'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -9
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    TabStop = False
    OnClick = btnSaveClick
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'bmp'
    Filter = 'Bitmap graphic files|*.bmp|All files|*.*'
    Left = 424
    Top = 24
  end
end

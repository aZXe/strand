object ChildGrid: TChildGrid
  Left = 271
  Top = 117
  Width = 367
  Height = 207
  Color = clBtnFace
  DockSite = True
  ParentFont = True
  FormStyle = fsMDIChild
  OldCreateOrder = True
  Position = poDefault
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object StringGrid1: TStringGrid
    Left = 0
    Top = 0
    Width = 359
    Height = 178
    Align = alClient
    ColCount = 2
    DefaultRowHeight = 15
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goThumbTracking]
    TabOrder = 0
    OnDrawCell = StringGrid1DrawCell
    OnKeyDown = StringGrid1KeyDown
    OnKeyUp = StringGrid1KeyUp
    OnMouseDown = StringGrid1MouseDown
    OnMouseWheelDown = StringGrid1MouseWheelDown
    OnMouseWheelUp = StringGrid1MouseWheelUp
  end
end

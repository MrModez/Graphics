object MainForm: TMainForm
  Left = 220
  Top = 83
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'MainForm'
  ClientHeight = 656
  ClientWidth = 1145
  Color = clBtnHighlight
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Segoe UI'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  ScreenSnap = True
  OnCloseQuery = FormCloseQuery
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 17
  object PaintBoxDD: TPaintBox
    Left = 560
    Top = 0
    Width = 585
    Height = 656
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    OnPaint = PaintBoxDDPaint
    ExplicitLeft = 566
  end
  object PaintBoxTD: TPaintBox
    Left = 0
    Top = 0
    Width = 560
    Height = 656
    Align = alLeft
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    OnPaint = PaintBoxTDPaint
    ExplicitLeft = 8
  end
  object Label10: TLabel
    Left = 282
    Top = 8
    Width = 32
    Height = 17
    Caption = 'Point:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label7: TLabel
    Left = 323
    Top = 8
    Width = 29
    Height = 17
    Caption = 'XPos'
  end
  object Label8: TLabel
    Left = 324
    Top = 31
    Width = 28
    Height = 17
    Caption = 'YPos'
  end
  object Label9: TLabel
    Left = 324
    Top = 54
    Width = 28
    Height = 17
    Caption = 'ZPos'
  end
  object Label6: TLabel
    Left = 556
    Top = 8
    Width = 33
    Height = 17
    Caption = 'Angle'
  end
  object Label15: TLabel
    Left = 65
    Top = 54
    Width = 28
    Height = 17
    Caption = 'ZPos'
  end
  object Label16: TLabel
    Left = 65
    Top = 31
    Width = 28
    Height = 17
    Caption = 'YPos'
  end
  object Label17: TLabel
    Left = 64
    Top = 8
    Width = 29
    Height = 17
    Caption = 'XPos'
  end
  object Label18: TLabel
    Left = 566
    Top = 77
    Width = 23
    Height = 17
    Caption = 'Yaw'
    Visible = False
  end
  object Label19: TLabel
    Left = 567
    Top = 54
    Width = 22
    Height = 17
    Caption = 'Roll'
    Visible = False
  end
  object Label50: TLabel
    Left = 562
    Top = 31
    Width = 27
    Height = 17
    Caption = 'Pitch'
    Visible = False
  end
  object Label1: TLabel
    Left = 922
    Top = 54
    Width = 28
    Height = 17
    Caption = 'ZPos'
  end
  object Label2: TLabel
    Left = 922
    Top = 31
    Width = 28
    Height = 17
    Caption = 'YPos'
  end
  object Label3: TLabel
    Left = 921
    Top = 8
    Width = 29
    Height = 17
    Caption = 'XPos'
  end
  object Label4: TLabel
    Left = 8
    Top = 8
    Width = 50
    Height = 17
    Caption = '3D View:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 865
    Top = 8
    Width = 50
    Height = 17
    Caption = '2D View:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object AACheck: TCheckBox
    Left = 956
    Top = 77
    Width = 97
    Height = 17
    Caption = 'Anti-Aliasing'
    Checked = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    State = cbChecked
    TabOrder = 0
    OnClick = AACheckClick
  end
  object ProjCheck: TCheckBox
    Left = 774
    Top = 8
    Width = 86
    Height = 17
    Caption = 'Projection'
    Checked = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    State = cbChecked
    TabOrder = 1
    OnClick = ProjCheckClick
  end
  object XScroll: TScrollBar
    Left = 358
    Top = 8
    Width = 176
    Height = 17
    PageSize = 0
    Position = 80
    TabOrder = 2
    OnChange = XSpinChange
  end
  object YScroll: TScrollBar
    Left = 358
    Top = 31
    Width = 176
    Height = 17
    PageSize = 0
    Position = 60
    TabOrder = 3
    OnChange = XSpinChange
  end
  object ZScroll: TScrollBar
    Left = 358
    Top = 54
    Width = 176
    Height = 17
    PageSize = 0
    Position = 70
    TabOrder = 4
    OnChange = XSpinChange
  end
  object AScroll: TScrollBar
    Left = 595
    Top = 8
    Width = 166
    Height = 17
    Max = 57
    PageSize = 0
    Position = 25
    TabOrder = 5
    OnChange = ASpinChange
  end
  object ZShiftScroll: TScrollBar
    Left = 99
    Top = 54
    Width = 166
    Height = 17
    Max = 50
    Min = 5
    PageSize = 0
    Position = 12
    TabOrder = 6
    OnChange = XShiftSpinChange
  end
  object YShiftScroll: TScrollBar
    Left = 99
    Top = 31
    Width = 166
    Height = 17
    Max = 600
    Min = 300
    PageSize = 0
    Position = 400
    TabOrder = 7
    OnChange = XShiftSpinChange
  end
  object XShiftScroll: TScrollBar
    Left = 99
    Top = 8
    Width = 166
    Height = 17
    Max = 300
    Min = 100
    PageSize = 0
    Position = 200
    TabOrder = 8
    OnChange = XShiftSpinChange
  end
  object YawScroll: TScrollBar
    Left = 595
    Top = 77
    Width = 166
    Height = 17
    Min = -100
    PageSize = 0
    TabOrder = 9
    Visible = False
    OnChange = PitchSpinChange
  end
  object RollScroll: TScrollBar
    Left = 595
    Top = 54
    Width = 166
    Height = 17
    Min = -100
    PageSize = 0
    Position = -46
    TabOrder = 10
    Visible = False
    OnChange = PitchSpinChange
  end
  object PitchScroll: TScrollBar
    Left = 595
    Top = 31
    Width = 166
    Height = 17
    Min = -100
    PageSize = 0
    TabOrder = 11
    Visible = False
    OnChange = PitchSpinChange
  end
  object ZShiftScrollDD: TScrollBar
    Left = 956
    Top = 54
    Width = 176
    Height = 17
    Max = 50
    Min = 5
    PageSize = 0
    Position = 16
    TabOrder = 12
    OnChange = XShiftSpinChange
  end
  object YShiftScrollDD: TScrollBar
    Left = 956
    Top = 31
    Width = 176
    Height = 17
    Max = 600
    Min = 300
    PageSize = 0
    Position = 400
    TabOrder = 13
    OnChange = XShiftSpinChange
  end
  object XShiftScrollDD: TScrollBar
    Left = 956
    Top = 8
    Width = 176
    Height = 17
    Max = 300
    Min = 100
    PageSize = 0
    Position = 270
    TabOrder = 14
    OnChange = XShiftSpinChange
  end
  object DrawTimer: TTimer
    Enabled = False
    Interval = 100
    OnTimer = DrawTimerTimer
    Left = 1088
    Top = 56
  end
end

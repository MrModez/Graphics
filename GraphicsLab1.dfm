object MainForm: TMainForm
  Left = 128
  Top = 15
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 
    #1051#1072#1073#1072#1088#1072#1090#1086#1088#1085#1072#1103' '#1088#1072#1073#1086#1090#1072' '#8470'1 '#1050#1086#1084#1087#1100#1102#1090#1077#1088#1085#1072#1103' '#1043#1088#1072#1092#1080#1082#1072', '#1060#1072#1073#1072#1088#1080#1089#1086#1074#1099' '#1047#1072#1075#1080#1088' '#1080' ' +
    #1058#1072#1075#1080#1088'. '#1052#1054'-303'
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
  Position = poDesktopCenter
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
    ExplicitLeft = -2
  end
  object Label10: TLabel
    Left = 300
    Top = 8
    Width = 38
    Height = 17
    Caption = #1058#1086#1095#1082#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label7: TLabel
    Left = 341
    Top = 8
    Width = 8
    Height = 17
    Caption = 'X'
  end
  object Label8: TLabel
    Left = 342
    Top = 31
    Width = 7
    Height = 17
    Caption = 'Y'
  end
  object Label9: TLabel
    Left = 342
    Top = 54
    Width = 7
    Height = 17
    Caption = 'Z'
  end
  object Label6: TLabel
    Left = 566
    Top = 8
    Width = 27
    Height = 17
    Caption = #1059#1075#1086#1083
  end
  object Label15: TLabel
    Left = 73
    Top = 54
    Width = 7
    Height = 17
    Caption = 'Z'
  end
  object Label16: TLabel
    Left = 73
    Top = 31
    Width = 7
    Height = 17
    Caption = 'Y'
  end
  object Label17: TLabel
    Left = 72
    Top = 8
    Width = 8
    Height = 17
    Caption = 'X'
  end
  object Label18: TLabel
    Left = 563
    Top = 77
    Width = 23
    Height = 17
    Caption = 'Yaw'
    Visible = False
  end
  object Label19: TLabel
    Left = 564
    Top = 54
    Width = 22
    Height = 17
    Caption = 'Roll'
    Visible = False
  end
  object Label50: TLabel
    Left = 559
    Top = 31
    Width = 27
    Height = 17
    Caption = 'Pitch'
    Visible = False
  end
  object Label1: TLabel
    Left = 918
    Top = 54
    Width = 7
    Height = 17
    Caption = 'Z'
  end
  object Label2: TLabel
    Left = 918
    Top = 31
    Width = 7
    Height = 17
    Caption = 'Y'
  end
  object Label3: TLabel
    Left = 917
    Top = 8
    Width = 8
    Height = 17
    Caption = 'X'
  end
  object Label4: TLabel
    Left = 8
    Top = 8
    Width = 44
    Height = 17
    Caption = '3D '#1042#1080#1076':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 867
    Top = 8
    Width = 44
    Height = 17
    Caption = '2D '#1042#1080#1076':'
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
    Caption = #1057#1075#1083#1072#1078#1080#1074#1072#1085#1080#1077
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
    Left = 683
    Top = 31
    Width = 75
    Height = 17
    Caption = #1055#1088#1086#1077#1082#1094#1080#1080
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
    Left = 376
    Top = 8
    Width = 153
    Height = 17
    Min = -100
    PageSize = 0
    Position = 80
    TabOrder = 2
    OnChange = XSpinChange
  end
  object YScroll: TScrollBar
    Left = 376
    Top = 31
    Width = 153
    Height = 17
    Min = -100
    PageSize = 0
    Position = 60
    TabOrder = 3
    OnChange = XSpinChange
  end
  object ZScroll: TScrollBar
    Left = 376
    Top = 54
    Width = 153
    Height = 17
    Min = -100
    PageSize = 0
    Position = 70
    TabOrder = 4
    OnChange = XSpinChange
  end
  object AScroll: TScrollBar
    Left = 621
    Top = 8
    Width = 137
    Height = 17
    Max = 115
    PageSize = 0
    Position = 40
    TabOrder = 5
    OnChange = ASpinChange
  end
  object ZShiftScroll: TScrollBar
    Left = 115
    Top = 54
    Width = 150
    Height = 17
    Max = 50
    Min = 5
    PageSize = 0
    Position = 12
    TabOrder = 6
    OnChange = XShiftSpinChange
  end
  object YShiftScroll: TScrollBar
    Left = 115
    Top = 31
    Width = 150
    Height = 17
    Max = 600
    Min = 300
    PageSize = 0
    Position = 400
    TabOrder = 7
    OnChange = XShiftSpinChange
  end
  object XShiftScroll: TScrollBar
    Left = 115
    Top = 8
    Width = 150
    Height = 17
    Max = 400
    Min = 100
    PageSize = 0
    Position = 350
    TabOrder = 8
    OnChange = XShiftSpinChange
  end
  object YawScroll: TScrollBar
    Left = 592
    Top = 77
    Width = 166
    Height = 17
    Min = -100
    PageSize = 0
    Position = 74
    TabOrder = 9
    Visible = False
    OnChange = PitchSpinChange
  end
  object RollScroll: TScrollBar
    Left = 592
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
    Left = 592
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
    Width = 149
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
    Width = 149
    Height = 17
    Max = 600
    Min = 300
    PageSize = 0
    Position = 350
    TabOrder = 13
    OnChange = XShiftSpinChange
  end
  object XShiftScrollDD: TScrollBar
    Left = 956
    Top = 8
    Width = 149
    Height = 17
    Max = 300
    Min = 100
    PageSize = 0
    Position = 270
    TabOrder = 14
    OnChange = XShiftSpinChange
  end
  object Button1: TButton
    Left = 1043
    Top = 616
    Width = 81
    Height = 33
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 15
    OnClick = Button1Click
  end
  object DrawTimer: TTimer
    Enabled = False
    Interval = 100
    OnTimer = DrawTimerTimer
    Left = 1088
    Top = 56
  end
end

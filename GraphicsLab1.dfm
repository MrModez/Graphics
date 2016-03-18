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
  object PaintBoxTD: TPaintBox
    Left = 0
    Top = 0
    Width = 1145
    Height = 656
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    OnPaint = PaintBoxTDPaint
    ExplicitLeft = -6
    ExplicitWidth = 560
  end
  object Label6: TLabel
    Left = 830
    Top = 631
    Width = 27
    Height = 17
    Caption = #1059#1075#1086#1083
    Visible = False
  end
  object Label15: TLabel
    Left = 17
    Top = 77
    Width = 7
    Height = 17
    Caption = 'Z'
  end
  object Label16: TLabel
    Left = 17
    Top = 54
    Width = 7
    Height = 17
    Caption = 'Y'
  end
  object Label17: TLabel
    Left = 16
    Top = 31
    Width = 8
    Height = 17
    Caption = 'X'
  end
  object Label18: TLabel
    Left = 504
    Top = 77
    Width = 7
    Height = 17
    Caption = 'Z'
  end
  object Label19: TLabel
    Left = 504
    Top = 54
    Width = 7
    Height = 17
    Caption = 'Y'
  end
  object Label50: TLabel
    Left = 503
    Top = 31
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
  object Label11: TLabel
    Left = 503
    Top = 8
    Width = 50
    Height = 17
    Caption = #1058#1086#1095#1082#1072' C:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object TPointLabel: TLabel
    Left = 17
    Top = 146
    Width = 47
    Height = 17
    Caption = 'TDLabel'
  end
  object CPointLabel: TLabel
    Left = 17
    Top = 169
    Width = 47
    Height = 17
    Caption = 'TDLabel'
  end
  object AACheck: TCheckBox
    Left = 794
    Top = 75
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
    Left = 705
    Top = 75
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
  object AScroll: TScrollBar
    Left = 885
    Top = 631
    Width = 84
    Height = 17
    Max = 115
    PageSize = 0
    TabOrder = 2
    Visible = False
    OnChange = ASpinChange
  end
  object ZShiftScroll: TScrollBar
    Left = 59
    Top = 77
    Width = 130
    Height = 17
    Max = 50
    Min = 5
    PageSize = 0
    Position = 12
    TabOrder = 3
    OnChange = XShiftSpinChange
  end
  object YShiftScroll: TScrollBar
    Left = 59
    Top = 54
    Width = 130
    Height = 17
    Max = 600
    Min = 300
    PageSize = 0
    Position = 420
    TabOrder = 4
    OnChange = XShiftSpinChange
  end
  object XShiftScroll: TScrollBar
    Left = 59
    Top = 31
    Width = 130
    Height = 17
    Max = 400
    Min = 100
    PageSize = 0
    Position = 280
    TabOrder = 5
    OnChange = XShiftSpinChange
  end
  object YawScroll: TScrollBar
    Left = 539
    Top = 77
    Width = 130
    Height = 17
    Max = 300
    PageSize = 0
    Position = 55
    TabOrder = 6
    OnChange = PitchSpinChange
  end
  object RollScroll: TScrollBar
    Left = 539
    Top = 54
    Width = 130
    Height = 17
    Max = 300
    PageSize = 0
    Position = 280
    TabOrder = 7
    OnChange = PitchSpinChange
  end
  object PitchScroll: TScrollBar
    Left = 539
    Top = 31
    Width = 130
    Height = 17
    Max = 300
    PageSize = 0
    Position = 50
    TabOrder = 8
    OnChange = PitchSpinChange
  end
  object Button1: TButton
    Left = 1043
    Top = 616
    Width = 81
    Height = 33
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 9
    OnClick = Button1Click
  end
  object RadioGroup1: TRadioGroup
    Left = 737
    Top = 8
    Width = 133
    Height = 63
    Caption = #1055#1088#1086#1077#1094#1080#1088#1086#1074#1072#1085#1080#1077
    TabOrder = 10
  end
  object OProj: TRadioButton
    Left = 737
    Top = 29
    Width = 110
    Height = 17
    Caption = #1054#1088#1090#1086#1075#1086#1085#1072#1083#1100#1085#1086#1077
    Checked = True
    TabOrder = 11
    TabStop = True
    OnClick = OProjClick
  end
  object CProj: TRadioButton
    Left = 737
    Top = 52
    Width = 107
    Height = 17
    Caption = #1062#1077#1085#1090#1088#1072#1083#1100#1085#1086#1077
    TabOrder = 12
    OnClick = CProjClick
  end
  object DrawTimer: TTimer
    Enabled = False
    Interval = 100
    OnTimer = DrawTimerTimer
    Left = 1088
    Top = 56
  end
end

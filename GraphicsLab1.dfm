object MainForm: TMainForm
  Left = 220
  Top = 83
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'MainForm'
  ClientHeight = 772
  ClientWidth = 1114
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
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 17
  object Label1: TLabel
    Left = 315
    Top = 8
    Width = 22
    Height = 17
    Caption = 'Roll'
  end
  object Label10: TLabel
    Left = 11
    Top = 31
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
  object Label11: TLabel
    Left = 269
    Top = 8
    Width = 27
    Height = 17
    Caption = 'Pitch'
  end
  object Label2: TLabel
    Left = 361
    Top = 8
    Width = 23
    Height = 17
    Caption = 'Yaw'
  end
  object Label3: TLabel
    Left = 421
    Top = 8
    Width = 29
    Height = 17
    Caption = 'XPos'
  end
  object Label4: TLabel
    Left = 467
    Top = 8
    Width = 28
    Height = 17
    Caption = 'YPos'
  end
  object Label5: TLabel
    Left = 513
    Top = 8
    Width = 28
    Height = 17
    Caption = 'ZPos'
  end
  object Label6: TLabel
    Left = 215
    Top = 31
    Width = 48
    Height = 17
    Caption = 'Camera:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label7: TLabel
    Left = 49
    Top = 8
    Width = 29
    Height = 17
    Caption = 'XPos'
  end
  object Label8: TLabel
    Left = 95
    Top = 8
    Width = 28
    Height = 17
    Caption = 'YPos'
  end
  object Label9: TLabel
    Left = 141
    Top = 8
    Width = 28
    Height = 17
    Caption = 'ZPos'
  end
  object PaintBoxDD: TPaintBox
    Left = 560
    Top = 0
    Width = 554
    Height = 772
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    OnPaint = PaintBoxDDPaint
    ExplicitLeft = 535
    ExplicitWidth = 589
  end
  object Label13: TLabel
    Left = 906
    Top = 7
    Width = 28
    Height = 17
    Caption = 'YPos'
  end
  object Label14: TLabel
    Left = 953
    Top = 7
    Width = 28
    Height = 17
    Caption = 'ZPos'
  end
  object Label12: TLabel
    Left = 861
    Top = 7
    Width = 29
    Height = 17
    Caption = 'XPos'
  end
  object Label15: TLabel
    Left = 807
    Top = 30
    Width = 48
    Height = 17
    Caption = 'Camera:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object PaintBoxTD: TPaintBox
    Left = 0
    Top = 0
    Width = 560
    Height = 772
    Align = alLeft
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    OnPaint = PaintBoxTDPaint
  end
  object AABut: TCheckBox
    Left = 1013
    Top = 31
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
    OnClick = AAButClick
  end
  object XShiftSpinDD: TSpinEdit
    Left = 861
    Top = 26
    Width = 45
    Height = 27
    MaxValue = 0
    MinValue = 0
    TabOrder = 1
    Value = 250
    OnChange = XShiftSpinChange
  end
  object YShiftSpinDD: TSpinEdit
    Left = 907
    Top = 26
    Width = 45
    Height = 27
    MaxValue = 0
    MinValue = 0
    TabOrder = 2
    Value = 400
    OnChange = XShiftSpinChange
  end
  object ZShiftSpinDD: TSpinEdit
    Left = 953
    Top = 26
    Width = 45
    Height = 27
    MaxValue = 0
    MinValue = 0
    TabOrder = 3
    Value = 20
    OnChange = XShiftSpinChange
  end
  object PitchSpin: TSpinEdit
    Left = 269
    Top = 27
    Width = 45
    Height = 27
    MaxValue = 0
    MinValue = 0
    TabOrder = 4
    Value = 0
    OnChange = PitchSpinChange
  end
  object RollSpin: TSpinEdit
    Left = 315
    Top = 27
    Width = 45
    Height = 27
    MaxValue = 0
    MinValue = 0
    TabOrder = 5
    Value = -46
    OnChange = PitchSpinChange
  end
  object XShiftSpin: TSpinEdit
    Left = 421
    Top = 27
    Width = 45
    Height = 27
    MaxValue = 0
    MinValue = 0
    TabOrder = 6
    Value = 200
    OnChange = XShiftSpinChange
  end
  object XSpin: TSpinEdit
    Left = 49
    Top = 27
    Width = 45
    Height = 27
    MaxValue = 0
    MinValue = 0
    TabOrder = 7
    Value = 50
    OnChange = XSpinChange
  end
  object YawSpin: TSpinEdit
    Left = 361
    Top = 27
    Width = 45
    Height = 27
    MaxValue = 0
    MinValue = 0
    TabOrder = 8
    Value = -26
    OnChange = PitchSpinChange
  end
  object YShiftSpin: TSpinEdit
    Left = 467
    Top = 27
    Width = 45
    Height = 27
    MaxValue = 0
    MinValue = 0
    TabOrder = 9
    Value = 400
    OnChange = XShiftSpinChange
  end
  object YSpin: TSpinEdit
    Left = 95
    Top = 27
    Width = 45
    Height = 27
    MaxValue = 0
    MinValue = 0
    TabOrder = 10
    Value = 10
    OnChange = XSpinChange
  end
  object ZShiftSpin: TSpinEdit
    Left = 513
    Top = 27
    Width = 45
    Height = 27
    MaxValue = 0
    MinValue = 0
    TabOrder = 11
    Value = 12
    OnChange = XShiftSpinChange
  end
  object ZSpin: TSpinEdit
    Left = 141
    Top = 27
    Width = 45
    Height = 27
    MaxValue = 0
    MinValue = 0
    TabOrder = 12
    Value = 20
    OnChange = XSpinChange
  end
  object DrawTimer: TTimer
    Enabled = False
    Interval = 100
    OnTimer = DrawTimerTimer
    Left = 1072
    Top = 56
  end
end

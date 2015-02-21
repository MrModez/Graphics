object MainForm: TMainForm
  Left = 220
  Top = 83
  BorderStyle = bsSingle
  Caption = 'MainForm'
  ClientHeight = 772
  ClientWidth = 794
  Color = clBtnHighlight
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  ScreenSnap = True
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object MainPaintBox: TPaintBox
    Left = 0
    Top = 0
    Width = 794
    Height = 772
    Align = alClient
    OnPaint = MainPaintBoxPaint
    ExplicitTop = 8
  end
  object Pitch: TLabel
    Left = 269
    Top = 8
    Width = 23
    Height = 13
    Caption = 'Pitch'
  end
  object Label1: TLabel
    Left = 315
    Top = 8
    Width = 17
    Height = 13
    Caption = 'Roll'
  end
  object Label2: TLabel
    Left = 361
    Top = 8
    Width = 20
    Height = 13
    Caption = 'Yaw'
  end
  object Label3: TLabel
    Left = 421
    Top = 8
    Width = 23
    Height = 13
    Caption = 'XPos'
  end
  object Label4: TLabel
    Left = 467
    Top = 8
    Width = 23
    Height = 13
    Caption = 'YPos'
  end
  object Label5: TLabel
    Left = 513
    Top = 8
    Width = 23
    Height = 13
    Caption = 'ZPos'
  end
  object Label6: TLabel
    Left = 222
    Top = 30
    Width = 41
    Height = 13
    Caption = 'Camera:'
  end
  object XSpin: TSpinEdit
    Left = 24
    Top = 27
    Width = 40
    Height = 22
    MaxValue = 0
    MinValue = 0
    TabOrder = 0
    Value = 20
  end
  object YSpin: TSpinEdit
    Left = 71
    Top = 27
    Width = 40
    Height = 22
    MaxValue = 0
    MinValue = 0
    TabOrder = 1
    Value = 30
  end
  object ZSpin: TSpinEdit
    Left = 119
    Top = 27
    Width = 40
    Height = 22
    MaxValue = 0
    MinValue = 0
    TabOrder = 2
    Value = 40
  end
  object AABut: TCheckBox
    Left = 616
    Top = 16
    Width = 97
    Height = 17
    Caption = 'AABut'
    Checked = True
    State = cbChecked
    TabOrder = 3
    OnClick = AAButClick
  end
  object PitchSpin: TSpinEdit
    Left = 269
    Top = 27
    Width = 40
    Height = 22
    MaxValue = 0
    MinValue = 0
    TabOrder = 4
    Value = 0
    OnChange = PitchSpinChange
  end
  object RollSpin: TSpinEdit
    Left = 315
    Top = 27
    Width = 40
    Height = 22
    MaxValue = 0
    MinValue = 0
    TabOrder = 5
    Value = -46
    OnChange = PitchSpinChange
  end
  object YawSpin: TSpinEdit
    Left = 361
    Top = 27
    Width = 40
    Height = 22
    MaxValue = 0
    MinValue = 0
    TabOrder = 6
    Value = -26
    OnChange = PitchSpinChange
  end
  object XShiftSpin: TSpinEdit
    Left = 421
    Top = 27
    Width = 40
    Height = 22
    MaxValue = 0
    MinValue = 0
    TabOrder = 7
    Value = 300
    OnChange = XShiftSpinChange
  end
  object YShiftSpin: TSpinEdit
    Left = 467
    Top = 27
    Width = 40
    Height = 22
    MaxValue = 0
    MinValue = 0
    TabOrder = 8
    Value = 500
    OnChange = XShiftSpinChange
  end
  object ZShiftSpin: TSpinEdit
    Left = 513
    Top = 27
    Width = 40
    Height = 22
    MaxValue = 0
    MinValue = 0
    TabOrder = 9
    Value = 20
    OnChange = XShiftSpinChange
  end
  object DrawTimer: TTimer
    Enabled = False
    Interval = 100
    OnTimer = DrawTimerTimer
    Left = 736
    Top = 16
  end
end

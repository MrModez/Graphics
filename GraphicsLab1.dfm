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
    ExplicitLeft = -8
    ExplicitTop = 8
    ExplicitWidth = 784
    ExplicitHeight = 762
  end
  object Pitch: TLabel
    Left = 205
    Top = 8
    Width = 23
    Height = 13
    Caption = 'Pitch'
  end
  object Label1: TLabel
    Left = 251
    Top = 8
    Width = 17
    Height = 13
    Caption = 'Roll'
  end
  object Label2: TLabel
    Left = 297
    Top = 8
    Width = 20
    Height = 13
    Caption = 'Yaw'
  end
  object XSpin: TSpinEdit
    Left = 24
    Top = 24
    Width = 40
    Height = 22
    MaxValue = 0
    MinValue = 0
    TabOrder = 0
    Value = 20
  end
  object YSpin: TSpinEdit
    Left = 71
    Top = 24
    Width = 40
    Height = 22
    MaxValue = 0
    MinValue = 0
    TabOrder = 1
    Value = 30
  end
  object ZSpin: TSpinEdit
    Left = 119
    Top = 24
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
    Left = 205
    Top = 24
    Width = 40
    Height = 22
    MaxValue = 0
    MinValue = 0
    TabOrder = 4
    Value = 0
    OnChange = PitchSpinChange
  end
  object RollSpin: TSpinEdit
    Left = 251
    Top = 24
    Width = 40
    Height = 22
    MaxValue = 0
    MinValue = 0
    TabOrder = 5
    Value = -46
    OnChange = RollSpinChange
  end
  object YawSpin: TSpinEdit
    Left = 297
    Top = 24
    Width = 40
    Height = 22
    MaxValue = 0
    MinValue = 0
    TabOrder = 6
    Value = -26
    OnChange = YawSpinChange
  end
  object DrawTimer: TTimer
    Enabled = False
    Interval = 100
    OnTimer = DrawTimerTimer
    Left = 736
    Top = 16
  end
end

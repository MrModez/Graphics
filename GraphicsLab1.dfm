object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'MainForm'
  ClientHeight = 762
  ClientWidth = 784
  Color = clBtnHighlight
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object MainPaintBox: TPaintBox
    Left = 0
    Top = 0
    Width = 784
    Height = 762
    Align = alClient
    OnPaint = MainPaintBoxPaint
    ExplicitLeft = -8
    ExplicitTop = 8
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
  end
  object PitchSpin: TSpinEdit
    Left = 205
    Top = 24
    Width = 40
    Height = 22
    MaxValue = 0
    MinValue = 0
    TabOrder = 4
    Value = 64
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
    Value = -22
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
    Value = 57
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

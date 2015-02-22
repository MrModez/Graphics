object MainForm: TMainForm
  Left = 220
  Top = 83
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'MainForm'
  ClientHeight = 772
  ClientWidth = 1118
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
  object Pitch: TLabel
    Left = 269
    Top = 8
    Width = 27
    Height = 17
    Caption = 'Pitch'
  end
  object Label1: TLabel
    Left = 315
    Top = 8
    Width = 22
    Height = 17
    Caption = 'Roll'
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
  object Splitter1: TSplitter
    Left = 541
    Top = 0
    Width = 5
    Height = 772
    AutoSnap = False
    Beveled = True
    Color = clBtnHighlight
    MinSize = 50
    ParentColor = False
    ResizeStyle = rsUpdate
    ExplicitLeft = 518
  end
  object PanelDD: TPanel
    Left = 546
    Top = 0
    Width = 572
    Height = 772
    Align = alClient
    BevelOuter = bvNone
    Caption = 'PanelDD'
    ShowCaption = False
    TabOrder = 10
    ExplicitLeft = 517
    ExplicitWidth = 601
    object PaintBoxDD: TPaintBox
      Left = 0
      Top = 0
      Width = 572
      Height = 772
      Align = alClient
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      OnPaint = PaintBoxTDPaint
      ExplicitLeft = -33
      ExplicitTop = 8
      ExplicitWidth = 584
    end
  end
  object PanelTD: TPanel
    Left = 0
    Top = 0
    Width = 541
    Height = 772
    Align = alLeft
    BevelOuter = bvNone
    Caption = 'PanelTD'
    ShowCaption = False
    TabOrder = 11
    object PaintBoxTD: TPaintBox
      Left = 0
      Top = 0
      Width = 541
      Height = 772
      Align = alClient
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      OnPaint = PaintBoxTDPaint
      ExplicitWidth = 772
      ExplicitHeight = 584
    end
  end
  object XSpin: TSpinEdit
    Left = 49
    Top = 27
    Width = 45
    Height = 27
    MaxValue = 0
    MinValue = 0
    TabOrder = 0
    Value = 50
    OnChange = XSpinChange
  end
  object YSpin: TSpinEdit
    Left = 95
    Top = 27
    Width = 45
    Height = 27
    MaxValue = 0
    MinValue = 0
    TabOrder = 1
    Value = 10
    OnChange = XSpinChange
  end
  object ZSpin: TSpinEdit
    Left = 141
    Top = 27
    Width = 45
    Height = 27
    MaxValue = 0
    MinValue = 0
    TabOrder = 2
    Value = 20
    OnChange = XSpinChange
  end
  object AABut: TCheckBox
    Left = 576
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
    TabOrder = 3
    OnClick = AAButClick
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
  object YawSpin: TSpinEdit
    Left = 361
    Top = 27
    Width = 45
    Height = 27
    MaxValue = 0
    MinValue = 0
    TabOrder = 6
    Value = -26
    OnChange = PitchSpinChange
  end
  object XShiftSpin: TSpinEdit
    Left = 421
    Top = 27
    Width = 45
    Height = 27
    MaxValue = 0
    MinValue = 0
    TabOrder = 7
    Value = 200
    OnChange = XShiftSpinChange
  end
  object YShiftSpin: TSpinEdit
    Left = 467
    Top = 27
    Width = 45
    Height = 27
    MaxValue = 0
    MinValue = 0
    TabOrder = 8
    Value = 400
    OnChange = XShiftSpinChange
  end
  object ZShiftSpin: TSpinEdit
    Left = 513
    Top = 27
    Width = 45
    Height = 27
    MaxValue = 0
    MinValue = 0
    TabOrder = 9
    Value = 12
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

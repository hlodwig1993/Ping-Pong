object Form2: TForm2
  Left = 194
  Top = 129
  Width = 280
  Height = 295
  Caption = 'Options'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Shape1: TShape
    Left = 0
    Top = 0
    Width = 264
    Height = 256
    Align = alClient
    Brush.Color = clLime
  end
  object RadioGroup1: TRadioGroup
    Left = 32
    Top = 32
    Width = 201
    Height = 129
    Caption = 'Music'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Items.Strings = (
      'Yes'
      'No')
    ParentFont = False
    TabOrder = 0
  end
  object Button1: TButton
    Left = 64
    Top = 184
    Width = 113
    Height = 49
    Caption = 'Save'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button1Click
  end
end

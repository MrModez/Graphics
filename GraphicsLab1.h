// ---------------------------------------------------------------------------

#ifndef GraphicsLab1H
#define GraphicsLab1H
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Samples.Spin.hpp>
#include <Direct2D.hpp>
#include <Vcl.ComCtrls.hpp>
#include <vector>
#define Pi 3.1415926536

#include "GraphicsObjectDD.h"
#include "GraphicsObjectTD.h"
#include "GraphicsCamera.h"
#include "GraphicsOrtoSystem.h"
#include "GraphicsShared.h"

// ---------------------------------------------------------------------------
class TMainForm : public TForm {
__published: // IDE-managed Components

	TPaintBox *MainPaintBox;
	TSpinEdit *XSpin;
	TSpinEdit *YSpin;
	TSpinEdit *ZSpin;
	TTimer *DrawTimer;
	TCheckBox *AABut;
	TSpinEdit *PitchSpin;
	TSpinEdit *RollSpin;
	TSpinEdit *YawSpin;
	TLabel *Pitch;
	TLabel *Label1;
	TLabel *Label2;
	TSpinEdit *XShiftSpin;
	TLabel *Label3;
	TSpinEdit *YShiftSpin;
	TLabel *Label4;
	TSpinEdit *ZShiftSpin;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;

	void __fastcall MainPaintBoxPaint(TObject * Sender);
	void __fastcall DrawTimerTimer(TObject * Sender);
	void __fastcall PitchSpinChange(TObject * Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall AAButClick(TObject *Sender);
	void __fastcall XShiftSpinChange(TObject *Sender);
	void __fastcall XSpinChange(TObject *Sender);

private: // User declarations

	OrtoSystem *pSystem;
	OCamera *pCamera;
	ObjectTD *LabPoint;

public: // User declarations

	__fastcall TMainForm(TComponent * Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
// ---------------------------------------------------------------------------
#endif

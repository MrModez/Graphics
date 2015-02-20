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

	void __fastcall MainPaintBoxPaint(TObject * Sender);
	void __fastcall DrawTimerTimer(TObject * Sender);
	void __fastcall PitchSpinChange(TObject * Sender);
	void __fastcall RollSpinChange(TObject * Sender);
	void __fastcall YawSpinChange(TObject * Sender);
	void __fastcall FormShow(TObject *Sender);

private: // User declarations

	OrtoSystem *pSystem;
	OCamera *pCamera;

public: // User declarations

	__fastcall TMainForm(TComponent * Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
// ---------------------------------------------------------------------------
#endif

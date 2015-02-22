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
#include "GraphicsCameraDD.h"
#include "GraphicsCameraTD.h"
#include "GraphicsOrtoSystem.h"
#include "GraphicsComplexSystem.h"
#include "GraphicsShared.h"

// ---------------------------------------------------------------------------
class TMainForm : public TForm {
__published: // IDE-managed Components
	TSpinEdit *XSpin;
	TSpinEdit *YSpin;
	TSpinEdit *ZSpin;
	TTimer *DrawTimer;
	TCheckBox *AABut;
	TSpinEdit *PitchSpin;
	TSpinEdit *RollSpin;
	TSpinEdit *YawSpin;
	TLabel *Label11;
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
	TPaintBox *PaintBoxDD;
	TSpinEdit *ZShiftSpinDD;
	TSpinEdit *YShiftSpinDD;
	TSpinEdit *XShiftSpinDD;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TPaintBox *PaintBoxTD;

	void __fastcall PaintBoxDDPaint(TObject * Sender);
	void __fastcall DrawTimerTimer(TObject * Sender);
	void __fastcall PitchSpinChange(TObject * Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall AAButClick(TObject *Sender);
	void __fastcall XShiftSpinChange(TObject *Sender);
	void __fastcall XSpinChange(TObject *Sender);
	void __fastcall PaintBoxTDPaint(TObject *Sender);


private: // User declarations

	OrtoSystem *pOrtoSystem;
	ComplexSystem *pCompSystem;
	CameraTD *pCameraTD;
	CameraDD *pCameraDD;
	ObjectTD *LabPoint;

public: // User declarations

	__fastcall TMainForm(TComponent * Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
// ---------------------------------------------------------------------------
#endif

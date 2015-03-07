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
	TTimer *DrawTimer;
	TCheckBox *AACheck;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TPaintBox *PaintBoxDD;
	TPaintBox *PaintBoxTD;
	TCheckBox *ProjCheck;
	TLabel *Label6;
	TScrollBar *XScroll;
	TScrollBar *YScroll;
	TScrollBar *ZScroll;
	TScrollBar *AScroll;
	TLabel *Label15;
	TScrollBar *ZShiftScroll;
	TLabel *Label16;
	TScrollBar *YShiftScroll;
	TLabel *Label17;
	TScrollBar *XShiftScroll;
	TLabel *Label18;
	TScrollBar *YawScroll;
	TLabel *Label19;
	TScrollBar *RollScroll;
	TLabel *Label50;
	TScrollBar *PitchScroll;
	TScrollBar *ZShiftScrollDD;
	TLabel *Label1;
	TLabel *Label2;
	TScrollBar *YShiftScrollDD;
	TLabel *Label3;
	TScrollBar *XShiftScrollDD;
	TLabel *Label4;
	TLabel *Label5;

	void __fastcall PaintBoxDDPaint(TObject * Sender);
	void __fastcall DrawTimerTimer(TObject * Sender);
	void __fastcall PitchSpinChange(TObject * Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall AACheckClick(TObject *Sender);
	void __fastcall XShiftSpinChange(TObject *Sender);
	void __fastcall XSpinChange(TObject *Sender);
	void __fastcall PaintBoxTDPaint(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall ProjCheckClick(TObject *Sender);
	void __fastcall ASpinChange(TObject *Sender);


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

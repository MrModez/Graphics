// ---------------------------------------------------------------------------

#ifndef GraphicsLab1H
#define GraphicsLab1H
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Samples.Spin.hpp>
#include <Direct2D.hpp>
#include <Vcl.ComCtrls.hpp>
#include <vector>
#define Pi 3.1415926536

class OrtoSystem;
class ComplexSystem;
class CameraTD;
class CameraDD;
class ObjectTD;

// ---------------------------------------------------------------------------
class TMainForm : public TForm {
__published: // IDE-managed Components

	TTimer *DrawTimer;
	TCheckBox *AACheck;
	TPaintBox *PaintBoxTD;
	TCheckBox *ProjCheck;
	TLabel *Label6;
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
	TLabel *Label4;
	TButton *Button1;
	TRadioGroup *RadioGroup1;
	TRadioButton *OProj;
	TRadioButton *CProj;
	TLabel *Label11;
	TLabel *TPointLabel;
	TLabel *CPointLabel;
	void __fastcall DrawTimerTimer(TObject * Sender);
	void __fastcall PitchSpinChange(TObject * Sender);
	void __fastcall AACheckClick(TObject *Sender);
	void __fastcall XShiftSpinChange(TObject *Sender);
	void __fastcall XSpinChange(TObject *Sender);
	void __fastcall PaintBoxTDPaint(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall ProjCheckClick(TObject *Sender);
	void __fastcall ASpinChange(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall OProjClick(TObject *Sender);
	void __fastcall CProjClick(TObject *Sender);

private: // User declarations

	OrtoSystem *pOrtoSystem;
	//ComplexSystem *pCompSystem;
	CameraTD *pCameraTD;
	//CameraDD *pCameraDD;
	ObjectTD *LabPoint;
	ObjectTD *CamPoint;

	void __fastcall TMainForm::AddLabels(TScrollBar* Scroll);

public: // User declarations

	__fastcall TMainForm(TComponent * Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
// ---------------------------------------------------------------------------
#endif

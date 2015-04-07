// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GraphicsLab1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TMainForm *MainForm;

#define Point(X, Y)		Ellipse(X-5, Y-5, X+5, Y+5)
#define DEBUG			ShowMessage
#define INT				StrToInt
#define STR				IntToStr
#define COS 			cos
#define SIN 			sin
#define PITCH 			PitchScroll->Position
#define ROLL 			RollScroll->Position
#define YAW 			YawScroll->Position - 0.5
#define SPINX 			XScroll->Position
#define SPINY 			YScroll->Position
#define SPINZ 			ZScroll->Position
#define SHIFTX 			XShiftScroll->Position
#define SHIFTY 			YShiftScroll->Position
#define SHIFTZ 			ZShiftScroll->Position
#define SHIFTXDD 		XShiftScrollDD->Position
#define SHIFTYDD 		YShiftScrollDD->Position
#define SHIFTZDD 		ZShiftScrollDD->Position
#define SPINA 			AScroll->Position   / 2.0

// ---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner) : TForm(Owner) {
	MainForm->ControlStyle << csOpaque;
	pCameraTD = new CameraTD(SHIFTX, SHIFTY, SHIFTZ, PITCH, ROLL, YAW);
	pCameraTD->SetAngle(SPINA);
	pCameraDD = new CameraDD(SHIFTXDD, SHIFTYDD, SHIFTZDD);
	pOrtoSystem = new OrtoSystem(pCameraTD);
	pCompSystem = new ComplexSystem(pCameraDD);

	///label shit
	AddLabels(XShiftScroll);
	AddLabels(YShiftScroll);
	AddLabels(ZShiftScroll);

	AddLabels(XScroll);
	AddLabels(YScroll);
	AddLabels(ZScroll);
	AddLabels(AScroll);

	AddLabels(ZShiftScrollDD);
	AddLabels(YShiftScrollDD);
	AddLabels(XShiftScrollDD);

	// AddLabels(YawScroll);
	// AddLabels(RollScroll);
	// AddLabels(PitchScroll);
}

void __fastcall TMainForm::AddLabels(TScrollBar* Scroll) {
	TLabel *ScrollLeft = new TLabel(this);
	ScrollLeft->SetParentComponent(this);
	ScrollLeft->Left = Scroll->Left - 25;
	ScrollLeft->Top = Scroll->Top - 0;
	ScrollLeft->Caption = Scroll->Min;
	TLabel *ScrollRight = new TLabel(this);
	ScrollRight->SetParentComponent(this);
	ScrollRight->Left = Scroll->Left + Scroll->Width + 3;
	ScrollRight->Top = Scroll->Top - 0;
	ScrollRight->Caption = Scroll->Max;
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::PaintBoxDDPaint(TObject *Sender) {
	TDirect2DCanvas* LCanvas;
	LCanvas = new TDirect2DCanvas(PaintBoxDD->Canvas, PaintBoxDD->ClientRect);
	if (AACheck->Checked)
		LCanvas->RenderTarget->SetAntialiasMode
			(D2D1_ANTIALIAS_MODE_FORCE_DWORD);
	else
		LCanvas->RenderTarget->SetAntialiasMode(D2D1_ANTIALIAS_MODE_ALIASED);
	LCanvas->BeginDraw();
	try {
		pCompSystem->Paint(LCanvas);
	}
	__finally {
		LCanvas->EndDraw();
		LCanvas->Free();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::PaintBoxTDPaint(TObject *Sender) {
	TDirect2DCanvas* LCanvas;
	LCanvas = new TDirect2DCanvas(PaintBoxTD->Canvas, PaintBoxTD->ClientRect);
	if (AACheck->Checked)
		LCanvas->RenderTarget->SetAntialiasMode
			(D2D1_ANTIALIAS_MODE_FORCE_DWORD);
	else
		LCanvas->RenderTarget->SetAntialiasMode(D2D1_ANTIALIAS_MODE_ALIASED);
	LCanvas->BeginDraw();
	try {
		pOrtoSystem->Paint(LCanvas); // (TCanvas*)
	}
	__finally {
		LCanvas->EndDraw();
		LCanvas->Free();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::DrawTimerTimer(TObject *Sender) {
	PaintBoxTD->Refresh();
	PaintBoxDD->Refresh();
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::PitchSpinChange(TObject *Sender) {
	pOrtoSystem->pCamera->SetRotation(PITCH, ROLL, YAW);
	PaintBoxTD->Refresh();
	PaintBoxDD->Refresh();
}

// ---------------------------------------------------------------------------

void __fastcall TMainForm::AACheckClick(TObject *Sender) {
	PaintBoxTD->Refresh();
	PaintBoxDD->Refresh();
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::XShiftSpinChange(TObject *Sender) {
	pOrtoSystem->pCamera->SetPosition(SHIFTX, SHIFTY, SHIFTZ);
	pCompSystem->pCamera->SetPosition(SHIFTXDD, SHIFTYDD, SHIFTZDD);
	PaintBoxTD->Refresh();
	PaintBoxDD->Refresh();
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::XSpinChange(TObject *Sender) {
	LabPoint->SetPos(SPINX, SPINY, SPINZ);
	PaintBoxTD->Refresh();
	PaintBoxDD->Refresh();
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::FormCloseQuery(TObject *Sender, bool &CanClose) {
	delete pOrtoSystem;
	delete pCompSystem;
	delete pCameraTD;
	delete pCameraDD;
	delete LabPoint;
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::ProjCheckClick(TObject *Sender) {
	LabPoint->Par.bProj = ProjCheck->Checked;
	PaintBoxTD->Refresh();
	PaintBoxDD->Refresh();
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::ASpinChange(TObject *Sender) {
	pOrtoSystem->pCamera->SetAngle(SPINA);
	PaintBoxTD->Refresh();
	PaintBoxDD->Refresh();
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::Button1Click(TObject *Sender) {
	delete pOrtoSystem;
	delete pCompSystem;
	delete pCameraTD;
	delete pCameraDD;
	delete LabPoint;
	MainForm->Close();
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender) {
	// 3D stuff
	float L = 250;
	for (int i = 7; i >= 0; i--) {
		float lX, lY, lZ;
		switch (i) {
		case 0:
			lX = 1, lY = 1, lZ = 1;
			break;
		case 1:
			lX = 1, lY = -1, lZ = 1;
			break;
		case 2:
			lX = 1, lY = -1, lZ = -1;
			break;
		case 3:
			lX = 1, lY = 1, lZ = -1;
			break;
		case 4:
			lX = -1, lY = 1, lZ = 1;
			break;
		case 5:
			lX = -1, lY = -1, lZ = 1;
			break;
		case 6:
			lX = -1, lY = -1, lZ = -1;
			break;
		case 7:
			lX = -1, lY = 1, lZ = -1;
			break;
		default:
			break;
		}
		float X = lX * (L - 20);
		float Y = lY * (L - 20);
		float Z = lZ * (L - 20);
		ObjectTD *Cube = new ObjectTD();
		Cube->AddPoint(new PointTD(0, 0, 0, ACT_MOVE));
		Cube->AddPoint(new PointTD(X, 0, 0, ACT_DRAW));
		Cube->AddPoint(new PointTD(X, Y, 0, ACT_DRAW));
		Cube->AddPoint(new PointTD(0, Y, 0, ACT_DRAW));
		Cube->AddPoint(new PointTD(0, 0, 0, ACT_DRAW));
		Cube->AddPoint(new PointTD(0, 0, Z, ACT_DRAW));
		Cube->AddPoint(new PointTD(X, 0, Z, ACT_DRAW));
		Cube->AddPoint(new PointTD(X, Y, Z, ACT_DRAW));
		Cube->AddPoint(new PointTD(0, Y, Z, ACT_DRAW));
		Cube->AddPoint(new PointTD(0, 0, Z, ACT_DRAW));
		Cube->AddPoint(new PointTD(X, 0, 0, ACT_MOVE));
		Cube->AddPoint(new PointTD(X, 0, Z, ACT_DRAW));
		Cube->AddPoint(new PointTD(0, Y, 0, ACT_MOVE));
		Cube->AddPoint(new PointTD(0, Y, Z, ACT_DRAW));
		Cube->AddPoint(new PointTD(X, Y, 0, ACT_MOVE));
		Cube->AddPoint(new PointTD(X, Y, Z, ACT_DRAW));
		if (i == 0)
			Cube->SetParameters(DrawPar(clBlue, psDashDot, 2));
		else
			Cube->SetParameters(DrawPar(clMenu, psSolid, 1));
		ObjectShared* CubeShared = (ObjectShared*)Cube;
		pOrtoSystem->AddObject(CubeShared);
	}

	ObjectTD *Coords = new ObjectTD();
	Coords->AddPoint(new PointTD(-L, 0, 0, ACT_MOVE));
	Coords->AddPoint(new PointTD(L, 0, 0, ACT_DRAW));
	Coords->AddPoint(new PointTD(L - 5, -5, 0, ACT_DRAW));
	Coords->AddPoint(new PointTD(L, 0, 0, ACT_MOVE));
	Coords->AddPoint(new PointTD(L - 5, 5, 0, ACT_DRAW));

	Coords->AddPoint(new PointTD(0, -L, 0, ACT_MOVE));
	Coords->AddPoint(new PointTD(0, L, 0, ACT_DRAW));
	Coords->AddPoint(new PointTD(-5, L - 5, 0, ACT_DRAW));
	Coords->AddPoint(new PointTD(0, L, 0, ACT_MOVE));
	Coords->AddPoint(new PointTD(5, L - 5, 0, ACT_DRAW));

	Coords->AddPoint(new PointTD(0, 0, -L, ACT_MOVE));
	Coords->AddPoint(new PointTD(0, 0, L, ACT_DRAW));
	Coords->AddPoint(new PointTD(-5, 0, L - 5, ACT_DRAW));
	Coords->AddPoint(new PointTD(0, 0, L, ACT_MOVE));
	Coords->AddPoint(new PointTD(5, 0, L - 5, ACT_DRAW));

	Coords->AddPoint(new PointTD(L + 10, 0, 0, TYPE_TEXT, "X"));
	Coords->AddPoint(new PointTD(0, L + 10, 0, TYPE_TEXT, "Y"));
	Coords->AddPoint(new PointTD(0, 0, L + 10, TYPE_TEXT, "Z"));
	Coords->AddPoint(new PointTD(0, 0, 0, TYPE_POINT));
	// LabPoint->SetDrawProj(true);
	ObjectShared* CoordsShared = (ObjectShared*)Coords;
	pOrtoSystem->AddObject(CoordsShared);

	ObjectDD *TextViewTD = new ObjectDD();
	TextViewTD->AddPoint(new PointDD(50, 100, TYPE_TEXT,
		"Пространственный чертеж"));
	ObjectShared* TextViewTDShared = (ObjectShared*)TextViewTD;
	pOrtoSystem->AddObject(TextViewTDShared);

	ObjectDD *PointViewTD = new ObjectDD();
	PointViewTD->AddPoint(new PointDD(45, 107, TYPE_POINT));
	ObjectShared* PointViewTDShared = (ObjectShared*)PointViewTD;
	pOrtoSystem->AddObject(PointViewTDShared);

	// Point
	LabPoint = new ObjectTD("LabaPoint");
	LabPoint->AddPoint(new PointTD(SPINX, SPINY, SPINZ, TYPE_TEXT, "T"));
	LabPoint->AddPoint(new PointTD(SPINX, SPINY, SPINZ, TYPE_POINT));
	LabPoint->SetParameters(DrawPar(clRed, psDot, 3));
	LabPoint->SetDrawProj(true);
	ObjectShared* PointShared = (ObjectShared*)LabPoint;
	pOrtoSystem->AddObject(PointShared);
	pCompSystem->AddObject(PointShared);

	// 2D stuff
	L = 150;
	ObjectTD *CoordsDD = new ObjectTD();
	CoordsDD->AddPoint(new PointTD(-L, 0, 0, ACT_MOVE));
	CoordsDD->AddPoint(new PointTD(-L + 5, -5, 0, ACT_DRAW));
	CoordsDD->AddPoint(new PointTD(-L, 0, 0, ACT_MOVE));
	CoordsDD->AddPoint(new PointTD(-L + 5, 5, 0, ACT_DRAW));
	CoordsDD->AddPoint(new PointTD(-L, 0, 0, ACT_MOVE));
	CoordsDD->AddPoint(new PointTD(L, 0, 0, ACT_DRAW));
	CoordsDD->AddPoint(new PointTD(L - 5, -5, 0, ACT_DRAW));
	CoordsDD->AddPoint(new PointTD(L, 0, 0, ACT_MOVE));
	CoordsDD->AddPoint(new PointTD(L - 5, 5, 0, ACT_DRAW));

	CoordsDD->AddPoint(new PointTD(0, -L, 0, ACT_MOVE));
	CoordsDD->AddPoint(new PointTD(-5, -L + 5, 0, ACT_DRAW));
	CoordsDD->AddPoint(new PointTD(0, -L, 0, ACT_MOVE));
	CoordsDD->AddPoint(new PointTD(5, -L + 5, 0, ACT_DRAW));
	CoordsDD->AddPoint(new PointTD(0, -L, 0, ACT_MOVE));
	CoordsDD->AddPoint(new PointTD(0, L, 0, ACT_DRAW));
	CoordsDD->AddPoint(new PointTD(-5, L - 5, 0, ACT_DRAW));
	CoordsDD->AddPoint(new PointTD(0, L, 0, ACT_MOVE));
	CoordsDD->AddPoint(new PointTD(5, L - 5, 0, ACT_DRAW));

	CoordsDD->AddPoint(new PointTD(L + 15, 0, 0, TYPE_TEXT, "X"));
	CoordsDD->AddPoint(new PointTD(0, L + 15, 0, TYPE_TEXT, "X"));
	CoordsDD->AddPoint(new PointTD(-L - 15, 0, 0, TYPE_TEXT, "Y"));
	CoordsDD->AddPoint(new PointTD(0, -L - 15, 0, TYPE_TEXT, "Z"));
	CoordsDD->AddPoint(new PointTD(0, 0, 0, TYPE_POINT));
	ObjectShared* CoordsDDShared = (ObjectShared*)CoordsDD;
	pCompSystem->AddObject(CoordsDDShared);

	ObjectDD *TextViewDD = new ObjectDD();
	TextViewDD->AddPoint(new PointDD(50, 100, TYPE_TEXT, "Комплексный чертеж"));
	ObjectShared* TextViewDDShared = (ObjectShared*)TextViewDD;
	pCompSystem->AddObject(TextViewDDShared);

	ObjectDD *PointViewDD = new ObjectDD();
	PointViewDD->AddPoint(new PointDD(45, 107, TYPE_POINT));
	ObjectShared* PointViewDDShared = (ObjectShared*)PointViewDD;
	pCompSystem->AddObject(PointViewDDShared);
}
// ---------------------------------------------------------------------------

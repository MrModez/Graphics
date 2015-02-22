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
#define PITCH 			PitchSpin->Value
#define ROLL 			RollSpin->Value
#define YAW 			YawSpin->Value
#define SPINX 			XSpin->Value
#define SPINY 			YSpin->Value
#define SPINZ 			ZSpin->Value
#define SHIFTX 			XShiftSpin->Value
#define SHIFTY 			YShiftSpin->Value
#define SHIFTZ 			ZShiftSpin->Value

// ---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner) : TForm(Owner) {
	MainForm->ControlStyle << csOpaque;
	pCameraTD = new CameraTD(SHIFTX, SHIFTY, SHIFTZ, PITCH, ROLL, YAW);
	pCameraDD = new CameraDD(SHIFTX, SHIFTY, SHIFTZ);
	pOrtoSystem = new OrtoSystem(pCameraTD);
	pCompSystem = new ComplexSystem(pCameraDD);
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender) {
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
	ObjectShared* CoordsShared = (ObjectShared*)Coords;
	pOrtoSystem->AddObject(CoordsShared);

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
	CoordsDD->AddPoint(new PointTD(-L - 15, 0, 0, TYPE_TEXT, "Y"));
	CoordsDD->AddPoint(new PointTD(0, L + 15, 0, TYPE_TEXT, "Y"));
	CoordsDD->AddPoint(new PointTD(0, -L - 15, 0, TYPE_TEXT, "Z"));
	CoordsDD->AddPoint(new PointTD(0, 0, 0, TYPE_POINT));
	ObjectShared* CoordsDDShared = (ObjectShared*)CoordsDD;
	pCompSystem->AddObject(CoordsDDShared);

	ObjectDD *TextDD = new ObjectDD();
	TextDD->AddPoint(new PointDD(50, 100, TYPE_TEXT, "Laba1"));
	ObjectShared* TextDDShared = (ObjectShared*)TextDD;
	pOrtoSystem->AddObject(TextDDShared);

	ObjectDD *PointDDD = new ObjectDD();
	PointDDD->AddPoint(new PointDD(45, 107, TYPE_POINT));
	ObjectShared* PointDDShared = (ObjectShared*)PointDDD;
	pOrtoSystem->AddObject(PointDDShared);

	LabPoint = new ObjectTD("LabaPoint");
	// LabPoint->AddPoint(new PointTD(SPINX, SPINY, SPINZ, TYPE_TEXT, "Point3D"));
	LabPoint->AddPoint(new PointTD(SPINX, SPINY, SPINZ, TYPE_POINT));
	LabPoint->SetParameters(DrawPar(clRed, psDot, 3));
	LabPoint->SetDrawProj(true);
	ObjectShared* PointShared = (ObjectShared*)LabPoint;
	pOrtoSystem->AddObject(PointShared);
	pCompSystem->AddObject(PointShared);
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::PaintBoxDDPaint(TObject *Sender) {
	TDirect2DCanvas* LCanvas;
	LCanvas = new TDirect2DCanvas(PaintBoxDD->Canvas, PaintBoxDD->ClientRect);
	if (AABut->Checked)
		LCanvas->RenderTarget->SetAntialiasMode
			(D2D1_ANTIALIAS_MODE_FORCE_DWORD);
	else
		LCanvas->RenderTarget->SetAntialiasMode(D2D1_ANTIALIAS_MODE_ALIASED);
	LCanvas->BeginDraw();
	try {
		pOrtoSystem->Paint(LCanvas); // (TCanvas*)
		// pCompSystem->Paint(LCanvas);
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
	if (AABut->Checked)
		LCanvas->RenderTarget->SetAntialiasMode
			(D2D1_ANTIALIAS_MODE_FORCE_DWORD);
	else
		LCanvas->RenderTarget->SetAntialiasMode(D2D1_ANTIALIAS_MODE_ALIASED);
	LCanvas->BeginDraw();
	try {
		pOrtoSystem->Paint(LCanvas); // (TCanvas*)
		// pCompSystem->Paint(LCanvas);
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

void __fastcall TMainForm::AAButClick(TObject *Sender) {
	PaintBoxTD->Refresh();
	PaintBoxDD->Refresh();
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::XShiftSpinChange(TObject *Sender) {
	pOrtoSystem->pCamera->SetPosition(SHIFTX, SHIFTY, SHIFTZ);
	pCompSystem->pCamera->SetPosition(SHIFTX, SHIFTY, SHIFTZ);
	PaintBoxTD->Refresh();
	PaintBoxDD->Refresh();
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::XSpinChange(TObject *Sender) {
	/* ObjectTD* pPoint = dynamic_cast<ObjectTD*>
	 (pSystem->FindObject("LabaPoint"));
	 if (!pPoint)
	 return;
	 DEBUG("Found"); */
	LabPoint->SetPos(SPINX, SPINY, SPINZ);
	PaintBoxTD->Refresh();
	PaintBoxDD->Refresh();
}

// ---------------------------------------------------------------------------

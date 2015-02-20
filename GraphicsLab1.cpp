// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GraphicsLab1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TMainForm *MainForm;

#define Point(X, Y)		Ellipse(X-5, Y-5, X+5, Y+5)
#define MainCanvas		MainPaintBox->Canvas
#define DEBUG			ShowMessage
#define INT				StrToInt
#define STR				IntToStr
#define QMoveTo			MainCanvas->MoveTo
#define QLineTo 		MainCanvas->LineTo
#define COS 			cos
#define SIN 			sin
#define PITCH 			PitchSpin->Value + 0.5
#define ROLL 			RollSpin->Value + 0.5
#define YAW 			YawSpin->Value + 0.5
#define _X 				XSpin->Value
#define _Y 				YSpin->Value
#define _Z 				ZSpin->Value

// ---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner) : TForm(Owner) {
	MainForm->ControlStyle << csOpaque;
	pCamera = new OCamera(350, 500, 2.5, PITCH, ROLL, YAW);
	pSystem = new OrtoSystem(pCamera);
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender) {
	float L = 250;
	ObjectTD *Coords = new ObjectTD();
	Coords->AddPoint(new PointTD(0, 0, 0, ACT_MOVE));
	Coords->AddPoint(new PointTD(L, 0, 0, ACT_DRAW));
	Coords->AddPoint(new PointTD(0, 0, 0, ACT_MOVE));
	Coords->AddPoint(new PointTD(0, L, 0, ACT_DRAW));
	Coords->AddPoint(new PointTD(0, 0, 0, ACT_MOVE));
	Coords->AddPoint(new PointTD(0, 0, L, ACT_DRAW));
	Coords->AddPoint(new PointTD(L, 0, 0, TYPE_TEXT, "X"));
	Coords->AddPoint(new PointTD(0, L, 0, TYPE_TEXT, "Y"));
	Coords->AddPoint(new PointTD(0, 0, L, TYPE_TEXT, "Z"));
	Coords->AddPoint(new PointTD(0, 0, 0, TYPE_POINT));
	ObjectShared* CoordsShared = (ObjectShared*)Coords;
	pSystem->AddObject(CoordsShared);

	ObjectTD *Cube = new ObjectTD();
	Cube->AddPoint(new PointTD(0, 0, 0, ACT_MOVE));
	Cube->AddPoint(new PointTD(100, 0, 0, ACT_DRAW));
	Cube->AddPoint(new PointTD(100, 100, 0, ACT_DRAW));
	Cube->AddPoint(new PointTD(0, 100, 0, ACT_DRAW));
	Cube->AddPoint(new PointTD(0, 0, 0, ACT_DRAW));
	Cube->AddPoint(new PointTD(0, 0, 100, ACT_DRAW));
	Cube->AddPoint(new PointTD(100, 0, 100, ACT_DRAW));
	Cube->AddPoint(new PointTD(100, 100, 100, ACT_DRAW));
	Cube->AddPoint(new PointTD(0, 100, 100, ACT_DRAW));
	Cube->AddPoint(new PointTD(0, 0, 100, ACT_DRAW));
	Cube->AddPoint(new PointTD(100, 0, 0, ACT_MOVE));
	Cube->AddPoint(new PointTD(100, 0, 100, ACT_DRAW));
	Cube->AddPoint(new PointTD(0, 100, 0, ACT_MOVE));
	Cube->AddPoint(new PointTD(0, 100, 100, ACT_DRAW));
	Cube->AddPoint(new PointTD(100, 100, 0, ACT_MOVE));
	Cube->AddPoint(new PointTD(100, 100, 100, ACT_DRAW));
	ObjectShared* CubeShared = (ObjectShared*)Cube;
	pSystem->AddObject(CubeShared);

	int X = MainForm->Width / 2;
	int Y = MainForm->Height / 2;
	ObjectDD *Crosshair = new ObjectDD();
	Crosshair->AddPoint(new PointDD(X, Y, ACT_MOVE));
	Crosshair->AddPoint(new PointDD(X, Y - 10, ACT_DRAW));
	Crosshair->AddPoint(new PointDD(X, Y, ACT_MOVE));
	Crosshair->AddPoint(new PointDD(X, Y + 10, ACT_DRAW));
	Crosshair->AddPoint(new PointDD(X, Y, ACT_MOVE));
	Crosshair->AddPoint(new PointDD(X - 10, Y, ACT_DRAW));
	Crosshair->AddPoint(new PointDD(X, Y, ACT_MOVE));
	Crosshair->AddPoint(new PointDD(X + 10, Y, ACT_DRAW));
	ObjectShared* CrosshairShared = (ObjectShared*)Crosshair;
	pSystem->AddObject(CrosshairShared);

	ObjectTD *Text = new ObjectTD();
	Text->AddPoint(new PointTD(100, 100, 100, TYPE_TEXT, "Text3D"));
	ObjectShared* TextShared = (ObjectShared*)Text;
	pSystem->AddObject(TextShared);

	ObjectDD *TextDD = new ObjectDD();
	TextDD->AddPoint(new PointDD(200, 100, TYPE_TEXT, "Text2D"));
	ObjectShared* TextDDShared = (ObjectShared*)TextDD;
	pSystem->AddObject(TextDDShared);

	ObjectDD *PointDDD = new ObjectDD();
	PointDDD->AddPoint(new PointDD(180, 120, TYPE_POINT));
	ObjectShared* PointDDShared = (ObjectShared*)PointDDD;
	pSystem->AddObject(PointDDShared);

	ObjectTD *Point = new ObjectTD();
	Text->AddPoint(new PointTD(50, 50, 50, ACT_MOVE));
	Text->AddPoint(new PointTD(0, 50, 50, ACT_DRAW));
	Text->AddPoint(new PointTD(50, 50, 50, ACT_MOVE));
	Text->AddPoint(new PointTD(50, 0, 50, ACT_DRAW));
	Text->AddPoint(new PointTD(50, 50, 50, ACT_MOVE));
	Text->AddPoint(new PointTD(50, 50, 0, ACT_DRAW));
	Text->AddPoint(new PointTD(50, 50, 50, TYPE_POINT));
	ObjectShared* PointShared = (ObjectShared*)Point;
	pSystem->AddObject(PointShared);
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::MainPaintBoxPaint(TObject *Sender) {
	TDirect2DCanvas* LCanvas;
	LCanvas = new TDirect2DCanvas(MainPaintBox->Canvas,
		MainPaintBox->ClientRect);
	if (AABut->Checked)
		LCanvas->RenderTarget->SetAntialiasMode
			(D2D1_ANTIALIAS_MODE_FORCE_DWORD);
	else
		LCanvas->RenderTarget->SetAntialiasMode(D2D1_ANTIALIAS_MODE_ALIASED);
	LCanvas->BeginDraw();
	try {
		pSystem->Paint((TCanvas*)LCanvas);
	}
	__finally {
		LCanvas->EndDraw();
		LCanvas->Free();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::DrawTimerTimer(TObject *Sender) {
	MainPaintBox->Refresh();
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::PitchSpinChange(TObject *Sender) {
	pSystem->pCamera->SetRotation(PITCH, ROLL, YAW);
	MainPaintBox->Refresh();
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::RollSpinChange(TObject *Sender) {
	pSystem->pCamera->SetRotation(PITCH, ROLL, YAW);
	MainPaintBox->Refresh();
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::YawSpinChange(TObject *Sender) {
	pSystem->pCamera->SetRotation(PITCH, ROLL, YAW);
	MainPaintBox->Refresh();
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::AAButClick(TObject *Sender) {
	MainPaintBox->Refresh();
}
// ---------------------------------------------------------------------------

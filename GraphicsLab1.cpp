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
#define ROLL 			RollSpin->Value
#define YAW 			YawSpin->Value + 0.5
#define _X 				XSpin->Value
#define _Y 				YSpin->Value
#define _Z 				ZSpin->Value

// ---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner) : TForm(Owner) {
	MainForm->ControlStyle << csOpaque;
	pCamera = new OCamera(300, 500, 2.5, PITCH, ROLL, YAW);
	pSystem = new OrtoSystem(pCamera);
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender) {
	float L = 250;
	ObjectTD *Coords = new ObjectTD();
	Coords->AddPoint(new PointTD(0, 0, 0, move));
	Coords->AddPoint(new PointTD(L, 0, 0, draw));
	Coords->AddPoint(new PointTD(0, 0, 0, move));
	Coords->AddPoint(new PointTD(0, L, 0, draw));
	Coords->AddPoint(new PointTD(0, 0, 0, move));
	Coords->AddPoint(new PointTD(0, 0, L, draw));
	pSystem->AddObject(Coords);
	ObjectTD *Cube = new ObjectTD();
	Cube->AddPoint(new PointTD(0, 0, 0, move));
	Cube->AddPoint(new PointTD(100, 0, 0, draw));
	Cube->AddPoint(new PointTD(100, 100, 0, draw));
	Cube->AddPoint(new PointTD(0, 100, 0, draw));
	Cube->AddPoint(new PointTD(0, 0, 0, draw));
	Cube->AddPoint(new PointTD(0, 0, 100, draw));
	Cube->AddPoint(new PointTD(100, 0, 100, draw));
	Cube->AddPoint(new PointTD(100, 100, 100, draw));
	Cube->AddPoint(new PointTD(0, 100, 100, draw));
	Cube->AddPoint(new PointTD(0, 0, 100, draw));
	Cube->AddPoint(new PointTD(100, 0, 0, move));
	Cube->AddPoint(new PointTD(100, 0, 100, draw));
	Cube->AddPoint(new PointTD(0, 100, 0, move));
	Cube->AddPoint(new PointTD(0, 100, 100, draw));
	Cube->AddPoint(new PointTD(100, 100, 0, move));
	Cube->AddPoint(new PointTD(100, 100, 100, draw));
	pSystem->AddObject(Cube);
	ObjectTD *Point = new ObjectTD();
	Cube->AddPoint(new PointTD(_X, _Y, _Z, move));
	Cube->AddPoint(new PointTD(_X, _Y, _Z + 2, draw));
	pSystem->AddObject(Point);
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
		pSystem->Paint(LCanvas);
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
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::RollSpinChange(TObject *Sender) {
	pSystem->pCamera->SetRotation(PITCH, ROLL, YAW);
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::YawSpinChange(TObject *Sender) {
	pSystem->pCamera->SetRotation(PITCH, ROLL, YAW);
}

// ---------------------------------------------------------------------------

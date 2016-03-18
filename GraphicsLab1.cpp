// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GraphicsLab1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TMainForm *MainForm;

#include "GraphicsPointTD.h"
#include "GraphicsPointDD.h"
#include "GraphicsObjectDD.h"
#include "GraphicsObjectTD.h"
#include "GraphicsCameraDD.h"
#include "GraphicsCameraTD.h"
#include "GraphicsOrtoSystem.h"
#include "GraphicsComplexSystem.h"
#include "GraphicsShared.h"

#define Point(X, Y)		Ellipse(X-5, Y-5, X+5, Y+5)
#define DEBUG			ShowMessage
#define INT				StrToInt
#define STR				IntToStr
#define COS 			cos
#define SIN 			sin
#define PITCH 			PitchScroll->Position
#define ROLL 			RollScroll->Position
#define YAW 			YawScroll->Position
#define SPINX 			XScroll->Position
#define SPINY 			YScroll->Position
#define SPINZ 			ZScroll->Position
#define SHIFTX 			XShiftScroll->Position
#define SHIFTY 			YShiftScroll->Position
#define SHIFTZ 			ZShiftScroll->Position
#define SHIFTXDD 		XShiftScrollDD->Position
#define SHIFTYDD 		YShiftScrollDD->Position
#define SHIFTZDD 		ZShiftScrollDD->Position
#define SPINA 			AScroll->Position   / 2.0    + 1.0

// ---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner) : TForm(Owner)
{
	MainForm->ControlStyle << csOpaque;
	pCameraTD = new CameraTD(SHIFTX, SHIFTY, SHIFTZ, PITCH, ROLL, YAW);
	pCameraTD->SetAngle(SPINA);
	//pCameraDD = new CameraDD(SHIFTXDD, SHIFTYDD, SHIFTZDD);
	pOrtoSystem = new OrtoSystem(pCameraTD);
	//pCompSystem = new ComplexSystem(pCameraDD);

	///label shit
	AddLabels(XShiftScroll);
	AddLabels(YShiftScroll);
	AddLabels(ZShiftScroll);

	//AddLabels(XScroll);
	//AddLabels(YScroll);
	//AddLabels(ZScroll);
	//AddLabels(AScroll);

	//AddLabels(ZShiftScrollDD);
	//AddLabels(YShiftScrollDD);
	//AddLabels(XShiftScrollDD);

	AddLabels(YawScroll);
	AddLabels(RollScroll);
	AddLabels(PitchScroll);
	// AddLabels(YawScroll);
	// AddLabels(RollScroll);
	// AddLabels(PitchScroll);
}

void __fastcall TMainForm::AddLabels(TScrollBar* Scroll)
{
	TLabel *ScrollLeft = new TLabel(this);
	ScrollLeft->SetParentComponent(this);
	ScrollLeft->Left = Scroll->Left - 28;
	ScrollLeft->Top = Scroll->Top - 0;
	ScrollLeft->Caption = Scroll->Min;
	TLabel *ScrollRight = new TLabel(this);
	ScrollRight->SetParentComponent(this);
	ScrollRight->Left = Scroll->Left + Scroll->Width + 3;
	ScrollRight->Top = Scroll->Top - 0;
	ScrollRight->Caption = Scroll->Max;
	if (Scroll->Max > 0 && Scroll->Min < 0)
	{
		TLabel *ScrollCenter = new TLabel(this);
		ScrollCenter->SetParentComponent(this);
		// int size = Scroll->Max + Scroll->Min;
		ScrollCenter->Left = // Scroll->Left + size / 2.0;
			Scroll->Left - 2.0 + (Scroll->Width / 2.0);
		ScrollCenter->Top = Scroll->Top - 10;
		ScrollCenter->Caption = "|";
	}
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::PaintBoxTDPaint(TObject *Sender)
{
	TDirect2DCanvas* LCanvas;
	LCanvas = new TDirect2DCanvas(PaintBoxTD->Canvas, PaintBoxTD->ClientRect);
	if (AACheck->Checked)
		LCanvas->RenderTarget->SetAntialiasMode
			(D2D1_ANTIALIAS_MODE_FORCE_DWORD);
	else
		LCanvas->RenderTarget->SetAntialiasMode(D2D1_ANTIALIAS_MODE_ALIASED);
	LCanvas->BeginDraw();
	try
	{
		pOrtoSystem->Paint(LCanvas); // (TCanvas*)
	}
	__finally
	{
		LCanvas->EndDraw();
		LCanvas->Free();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::DrawTimerTimer(TObject *Sender)
{
	PaintBoxTD->Refresh();
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::PitchSpinChange(TObject *Sender)
{
	// CamPoint->SetPos(PITCH, ROLL, YAW);
	pOrtoSystem->pCamera->SetRotation(PITCH, ROLL, YAW);
	PaintBoxTD->Refresh();
	CPointLabel->Caption = "Точка C - X: " + STR(PITCH) + " Y: " + STR(ROLL) +
		" Z: " + STR(YAW);
}

// ---------------------------------------------------------------------------

void __fastcall TMainForm::AACheckClick(TObject *Sender)
{
	PaintBoxTD->Refresh();
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::XShiftSpinChange(TObject *Sender)
{
	pOrtoSystem->pCamera->SetPosition(SHIFTX, SHIFTY, SHIFTZ);
	pCompSystem->pCamera->SetPosition(SHIFTXDD, SHIFTYDD, SHIFTZDD);
	PaintBoxTD->Refresh();
	PaintBoxDD->Refresh();
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::XSpinChange(TObject *Sender)
{
	// LabPoint->SetPos(SPINX, SPINY, SPINZ);
	PaintBoxTD->Refresh();
	PaintBoxDD->Refresh();
	TPointLabel->Caption = "Точка T - X: " + STR(SPINX) + " Y: " + STR(SPINY) +
		" Z: " + STR(SPINZ);
	CPointLabel->Caption = "Точка C - X: " + STR(PITCH) + " Y: " + STR(ROLL) +
		" Z: " + STR(YAW);
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	delete pOrtoSystem;
	delete pCompSystem;
	delete pCameraTD;
	delete pCameraDD;
	delete LabPoint;
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::ProjCheckClick(TObject *Sender)
{
	LabPoint->Par.bProj = false; // ProjCheck->Checked;
	PaintBoxTD->Refresh();
	PaintBoxDD->Refresh();
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::ASpinChange(TObject *Sender)
{
	pOrtoSystem->pCamera->SetAngle(SPINA);
	PaintBoxTD->Refresh();
	PaintBoxDD->Refresh();
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::Button1Click(TObject *Sender)
{
	delete pOrtoSystem;
	delete pCompSystem;
	delete pCameraTD;
	delete pCameraDD;
	delete LabPoint;
	MainForm->Close();
}

float sh(float x)
{
	return (exp(x) - exp(-x)) / 2;
}

float ch(float x)
{
	return (exp(x) + exp(-x)) / 2;
}

void FindXYZ(float *x, float *y, float *z, float u, float v)
{
	// ch(

	// *x = u * ch(v) * 10.0;
	// *y = u * sh(v) * 10.0;
	// *z = pow(u, 2);
	*x = u * cos(v) * 10.0;
	*y = u * sin(v) * 10.0;
	*z = pow(u, 2) * cos(2 * v); // / 10.0;
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{

	// Point
	LabPoint = new ObjectTD("LabaPoint");
	float max = 13.0;
	float su = 0.6;
	float sv = 0.1;
	float PI = 3.14159265359;
	for (float u = 0; u < max; u += su)
	{
		for (float v = 0; v < PI * 2; v += sv)
		{
			float x, y, z;
			float uu, vv;

			uu = u;
			vv = v;
			FindXYZ(&x, &y, &z, uu, vv);
			LabPoint->AddPoint(new PointTD(x, y, z, TYPE_POINT));
			 LabPoint->AddPoint(new PointTD(x, y, z, ACT_MOVE, TYPE_POINT));

			uu = u + su;
			vv = v;
			FindXYZ(&x, &y, &z, uu, vv);
			 LabPoint->AddPoint(new PointTD(x, y, z, ACT_DRAW, TYPE_POINT));

			uu = u + su;
			vv = v + sv;
			FindXYZ(&x, &y, &z, uu, vv);
			 LabPoint->AddPoint(new PointTD(x, y, z, ACT_DRAW, TYPE_POINT));

			uu = u;
			vv = v + sv;
			FindXYZ(&x, &y, &z, uu, vv);
			 LabPoint->AddPoint(new PointTD(x, y, z, ACT_DRAW, TYPE_POINT));

			uu = u;
			vv = v;
			FindXYZ(&x, &y, &z, uu, vv);
			 LabPoint->AddPoint(new PointTD(x, y, z, ACT_DRAW, TYPE_POINT));
		}
	}
	LabPoint->SetParameters(DrawPar(clRed, psSolid, 2));
	LabPoint->SetDrawProj(false);
	pOrtoSystem->AddObject(LabPoint);
	//pCompSystem->AddObject(LabPoint);

	/*
	 CamPoint = new ObjectTD("CameraPoint");
	 CamPoint->AddPoint(new PointTD(SPINX, SPINY, SPINZ, TYPE_TEXT, "C"));
	 CamPoint->AddPoint(new PointTD(SPINX, SPINY, SPINZ, TYPE_POINT));
	 CamPoint->SetParameters(DrawPar(clBlue, psSolid, 4));
	 CamPoint->SetDrawProj(true);
	 pOrtoSystem->AddObject(CamPoint);
	 pCompSystem->AddObject(CamPoint);
	 */

	// 3D stuff
	float L = 250;
	for (int i = 7; i >= 0; i--)
	{
		float lX, lY, lZ;
		switch (i)
		{
		case 0:
			continue;
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
			Cube->SetParameters(DrawPar(clGradientInactiveCaption, psSolid, 1));
		pOrtoSystem->AddObject(Cube);
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
	pOrtoSystem->AddObject(Coords);

	ObjectDD *TextViewTD = new ObjectDD();
	TextViewTD->AddPoint(new PointDD(50, 100, TYPE_TEXT,
		"Пространственный чертеж"));
	pOrtoSystem->AddObject(TextViewTD);

	ObjectDD *PointViewTD = new ObjectDD();
	PointViewTD->AddPoint(new PointDD(45, 107, TYPE_POINT));
	pOrtoSystem->AddObject(PointViewTD);

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

	CoordsDD->AddPoint(new PointTD(L + 15, 0, 0, TYPE_TEXT, "Y"));
	CoordsDD->AddPoint(new PointTD(0, L + 15, 0, TYPE_TEXT, "Y"));
	CoordsDD->AddPoint(new PointTD(-L - 15, 0, 0, TYPE_TEXT, "X"));
	CoordsDD->AddPoint(new PointTD(0, -L - 15, 0, TYPE_TEXT, "Z"));
	CoordsDD->AddPoint(new PointTD(0, 0, 0, TYPE_POINT));
	//pCompSystem->AddObject(CoordsDD);

	//ObjectDD *TextViewDD = new ObjectDD();
	//TextViewDD->AddPoint(new PointDD(50, 100, TYPE_TEXT, "Комплексный чертеж"));
	//pCompSystem->AddObject(TextViewDD);

	//ObjectDD *PointViewDD = new ObjectDD();
	//PointViewDD->AddPoint(new PointDD(45, 107, TYPE_POINT));
	//pCompSystem->AddObject(PointViewDD);

	XSpinChange(this);
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::OProjClick(TObject *Sender)
{
	pCameraTD->SetMod(CAM_ORTO);
	PaintBoxTD->Refresh();
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::CProjClick(TObject *Sender)
{
	pCameraTD->SetMod(CAM_CENTRAL);
	PaintBoxTD->Refresh();
}
// ---------------------------------------------------------------------------

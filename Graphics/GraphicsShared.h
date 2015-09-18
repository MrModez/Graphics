// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: Shared classes and enums accessable by all other classes
//
// =============================================================================

#ifndef GRAPCHICS_SHARED_H_
#define GRAPCHICS_SHARED_H_

#include <vector>
#include <Direct2D.hpp>

#define Pi			3.1415926536
#define DefCanvas 	TDirect2DCanvas
// #define DefCanvas TCanvas

#define DEFAULT_WIDTH  	1
#define DEFAULT_RADIUS 	2
#define DEFAULT_COLOR 	clBlack
#define DEFAULT_STYLE 	psSolid
#define STAT_CAST static_cast
#define N 4     // Размерность матриц
#define inac 0.0000000000000001
#define x0 250  // абсцисса центра ск
#define y0 250  // ордината центра ск

enum Action {
	ACT_NONE, ACT_MOVE, ACT_DRAW, ACT_ARC, ACT_COUNT
};

enum Axis {
	AXIS_X, AXIS_Y, AXIS_Z, AXIS_COUNT
};

enum Dim { // unused
	DIM_DD, DIM_TD
};

enum Type {
	TYPE_OBJECT, TYPE_POINT, TYPE_TEXT
};

enum ProjStyle {
	PROJ_NONE, PROJ_LINES, PROJ_LINES_NIGGA, PROJ_DOTS, PROJ_DOTS_NIGGA
};

enum Quarter {
	QXZ, QXY, QYY, QYZ
};

enum CameraMode {
	CAM_ORTO, CAM_CENTRAL
};

class DrawPar {
public:
	DrawPar() {
		iColor = clBlack;
		iStyle = psSolid;
		iWidth = 1;
		bProj = false;
		iProjStyle = PROJ_NONE;
	};

	DrawPar(TColor Color, TPenStyle Style, int Width) {
		iColor = Color;
		iStyle = Style;
		iWidth = Width;
		bProj = false;
		iProjStyle = PROJ_NONE;
	};

	TColor iColor;
	TPenStyle iStyle;
	int iWidth;
	bool bProj;
	ProjStyle iProjStyle;
};

class CameraTD;
class CameraDD;

class ObjectShared {
public:
	ObjectShared() {
	}

	virtual ~ObjectShared() {
	}

	virtual void PaintTD(DefCanvas* pCanvas, CameraTD* pCamera) {
		return;
	}

	virtual void PaintDD(DefCanvas* pCanvas, CameraDD* pCamera) {
		return;
	}

	String ObjectID;
};

#endif //GRAPCHICS_SHARED_H_

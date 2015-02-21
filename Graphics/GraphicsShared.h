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
#define DEFAULT_COLOR 	clBlack
#define DEFAULT_STYLE 	psSolid

enum Action {
	ACT_NONE, ACT_MOVE, ACT_DRAW
};

enum Axis {
	AXIS_X, AXIS_Y, AXIS_Z, AXIS_COUNT
};

enum Dim { // unused
	DIM_DD, DIM_TD
};

class DrawPar {
public:
	DrawPar() {
		iColor = clBlack;
		iStyle = psSolid;
		iWidth = 1;
	};

	DrawPar(TColor Color, TPenStyle Style, int Width) {
		iColor = Color;
		iStyle = Style;
		iWidth = Width;
	};

	TColor iColor;
	TPenStyle iStyle;
	int iWidth;
};

enum Type {
	TYPE_OBJECT, TYPE_POINT, TYPE_TEXT
};

class OCamera;

class ObjectShared {
public:
	ObjectShared() {
	}

	~ObjectShared() {
	}

	virtual void Paint(DefCanvas* pCanvas, OCamera* pCamera) {
		return;
	}
};

#endif //GRAPCHICS_SHARED_H_

#include "GraphicsPointDD.h"

PointDD::PointDD() {
	x = 0;
	y = 0;
	action = ACT_NONE;
	iType = TYPE_OBJECT;
	sText = "";
};

PointDD::PointDD(float ix, float iy, Action iA) {
	x = ix;
	y = iy;
	action = iA;
	iType = TYPE_OBJECT;
	sText = "";
};

PointDD::PointDD(float ix, float iy, Action iA, Type T) {
	x = ix;
	y = iy;
	action = iA;
	iType = T;
	sText = "";
};
// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: 2D Point
//
// =============================================================================

PointDD::PointDD(float ix, float iy, Type T) {
	x = ix;
	y = iy;
	action = ACT_NONE;
	iType = T;
	sText = "";
};

PointDD::PointDD(float ix, float iy, Type T, String Text) {
	x = ix;
	y = iy;
	action = ACT_NONE;
	iType = T;
	sText = Text;
};

PointDD::~PointDD() {
	x = 0;
	y = 0;
	action = ACT_NONE;
	iType = TYPE_OBJECT;
	sText = "";
}

void PointDD::AddShift(float iXShift, float iYShift, float iZShift) {
	x = iZShift * x + iXShift;
	y = iZShift * y + iYShift;
};

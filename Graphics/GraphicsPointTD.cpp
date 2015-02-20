// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: 3D Point
//
// =============================================================================

#include "GraphicsPointTD.h"

PointTD::PointTD(float ix, float iy, float iz, Action iA) {
	x = ix;
	y = iy;
	z = iz;
	action = iA;
	iType = TYPE_OBJECT;
	sText = "";
};

PointTD::PointTD(float ix, float iy, float iz, Action iA, Type T) {
	x = ix;
	y = iy;
	z = iz;
	action = iA;
	iType = T;
	sText = "";
};

PointTD::PointTD(float ix, float iy, float iz, Type T) {
	x = ix;
	y = iy;
	z = iz;
	action = ACT_NONE;
	iType = T;
	sText = "";
};

PointTD::PointTD(float ix, float iy, float iz, Type T, String Text) {
	x = ix;
	y = iy;
	z = iz;
	action = ACT_NONE;
	iType = T;
	sText = Text;
};

PointTD::~PointTD() {
	x = 0;
	y = 0;
	z = 0;
	action = ACT_NONE;
	iType = TYPE_OBJECT;
	sText = "";
};

PointDD* PointTD::GetPointDD() {
	PointDD* result = new PointDD();
	return result;
};

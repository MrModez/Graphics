// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: 3D Point
//
// =============================================================================

#include "GraphicsPointTD.h"

PointTD::PointTD(float X, float Y, float Z, Action iA) {
	fX = X;
	fY = Y;
	fZ = Z;
	iAction = iA;
	iType = TYPE_OBJECT;
	sText = "";
};

PointTD::PointTD(float X, float Y, float Z, Action iA, Type T) {
	fX = X;
	fY = Y;
	fZ = Z;
	iAction = iA;
	iType = T;
	sText = "";
};

PointTD::PointTD(float X, float Y, float Z, Type T) {
	fX = X;
	fY = Y;
	fZ = Z;
	iAction = ACT_NONE;
	iType = T;
	sText = "";
};

PointTD::PointTD(float X, float Y, float Z, Type T, String Text) {
	fX = X;
	fY = Y;
	fZ = Z;
	iAction = ACT_NONE;
	iType = T;
	sText = Text;
};

PointTD::~PointTD() {
	fX = 0.0;
	fY = 0.0;
	fZ = 0.0;
	iAction = ACT_NONE;
	iType = TYPE_OBJECT;
	sText = "";
};

PointDD* PointTD::GetPointDD() {
	// PointDD* result = new PointDD();
	return new PointDD();
};

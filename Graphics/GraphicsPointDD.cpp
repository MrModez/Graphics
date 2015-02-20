// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: 2D Point
//
// =============================================================================
#include "GraphicsPointDD.h"

PointDD::PointDD() {
	fX = 0;
	fY = 0;
	iAction = ACT_NONE;
	iType = TYPE_OBJECT;
	sText = "";
};

PointDD::PointDD(float X, float Y, Action iA) {
	fX = X;
	fY = Y;
	iAction = iA;
	iType = TYPE_OBJECT;
	sText = "";
};

PointDD::PointDD(float X, float Y, Action iA, Type T) {
	fX = X;
	fY = Y;
	iAction = iA;
	iType = T;
	sText = "";
};

PointDD::PointDD(float X, float Y, Type T) {
	fX = X;
	fY = Y;
	iAction = ACT_NONE;
	iType = T;
	sText = "";
};

PointDD::PointDD(float X, float Y, Type T, String Text) {
	fX = X;
	fY = Y;
	iAction = ACT_NONE;
	iType = T;
	sText = Text;
};

PointDD::~PointDD() {
	fX = 0;
	fX = 0;
	iAction = ACT_NONE;
	iType = TYPE_OBJECT;
	sText = "";
}

void PointDD::AddShift(float iXShift, float iYShift, float iZShift) {
	fX = iZShift * fX + iXShift;
	fY = iZShift * fY + iYShift;
};

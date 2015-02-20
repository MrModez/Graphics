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

PointTD& PointTD:: operator = (const PointTD & rhs) {
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	action = rhs.action;
	return *this;
};

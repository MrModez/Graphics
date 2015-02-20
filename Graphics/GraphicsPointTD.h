#ifndef GraphicsPointTD
#define GraphicsPointTD

#include "GraphicsShared.h"

class PointTD {
public:
	PointTD(float ix, float iy, float iz, Action iA) {
		x = ix;
		y = iy;
		z = iz;
		action = iA;
		iType = TYPE_OBJECT;
		sText = "";
	};

	PointTD(float ix, float iy, float iz, Action iA, Type T) {
		x = ix;
		y = iy;
		z = iz;
		action = iA;
		iType = T;
		sText = "";
	};

	PointTD(float ix, float iy, float iz, Type T) {
		x = ix;
		y = iy;
		z = iz;
		action = ACT_NONE;
		iType = T;
		sText = "";
	};

	PointTD(float ix, float iy, float iz, Type T, String Text) {
		x = ix;
		y = iy;
		z = iz;
		action = ACT_NONE;
		iType = T;
		sText = Text;
	};

	PointTD & operator = (const PointTD & rhs) {
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		action = rhs.action;
		return *this;
	};

	float x;
	float y;
	float z;
	Action action;
	Type iType;
	String sText;
};

#endif

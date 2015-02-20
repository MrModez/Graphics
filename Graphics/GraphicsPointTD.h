#ifndef GraphicsPointTD
#define GraphicsPointTD

#include "GraphicsShared.h"

class PointTD : GraphicsBase {
public:
	PointTD(float ix, float iy, float iz, Action iA) {
		x = ix;
		y = iy;
		z = iz;
		action = iA;
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
};

#endif

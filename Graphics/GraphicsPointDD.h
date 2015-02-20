#ifndef GraphicsPointDD
#define GraphicsPointDD

#include "GraphicsPointTD.h"
#include "GraphicsShared.h"

class PointDD {
public:
	PointDD() {
		x = 0;
		y = 0;
		action = none;
	};

	PointDD(float ix, float iy, Action iA) {
		x = ix;
		y = iy;
		action = iA;
	};

	PointDD(PointTD & rhs) {
		x = rhs.x;
		y = rhs.y;
		action = rhs.action;
	};

	PointDD & operator = (const PointTD & rhs) {
		x = rhs.x;
		y = rhs.y;
		action = rhs.action;
		return *this;
	};

	PointDD & operator = (const PointDD & rhs) {
		x = rhs.x;
		y = rhs.y;
		action = rhs.action;
		return *this;
	};

	float x;
	float y;
	Action action;
};

#endif

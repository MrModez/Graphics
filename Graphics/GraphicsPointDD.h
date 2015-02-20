#ifndef GraphicsPointDD
#define GraphicsPointDD

#include "GraphicsPointTD.h"
#include "GraphicsShared.h"

class PointDD {
public:
	PointDD() {
		x = 0;
		y = 0;
		action = ACT_NONE;
		iType = TYPE_OBJECT;
		sText = "";
	};

	PointDD(float ix, float iy, Action iA) {
		x = ix;
		y = iy;
		action = iA;
		iType = TYPE_OBJECT;
		sText = "";
	};

	PointDD(float ix, float iy, Action iA, Type T) {
		x = ix;
		y = iy;
		action = iA;
		iType = T;
		sText = "";
	};

	PointDD(float ix, float iy, Type T) {
		x = ix;
		y = iy;
		action = ACT_NONE;
		iType = T;
		sText = "";
	};

	PointDD(float ix, float iy, Type T, String Text) {
		x = ix;
		y = iy;
		action = ACT_NONE;
		iType = T;
		sText = Text;
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
	Type iType;
	String sText;
};

#endif

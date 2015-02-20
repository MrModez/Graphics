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

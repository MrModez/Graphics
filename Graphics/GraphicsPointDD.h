#ifndef GraphicsPointDD
#define GraphicsPointDD

#include "GraphicsShared.h"
// #include "GraphicsPointTD.h"

class PointDD {
public:
	PointDD();

	PointDD(float ix, float iy, Action iA);
	PointDD(float ix, float iy, Action iA, Type T);
	PointDD(float ix, float iy, Type T);
	PointDD(float ix, float iy, Type T, String Text);

	float x;
	float y;
	Action action;
	Type iType;
	String sText;
};

#endif

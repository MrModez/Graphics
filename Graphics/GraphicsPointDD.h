// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: 2D Point
//
// =============================================================================

#ifndef GRAPCHICS_POINTDD_H_
#define GRAPCHICS_POINTDD_H_

#include "GraphicsShared.h"
// #include "GraphicsPointTD.h"

class PointDD {
public:
	PointDD();

	PointDD(float ix, float iy, Action iA);
	PointDD(float ix, float iy, Action iA, Type T);
	PointDD(float ix, float iy, Type T);
	PointDD(float ix, float iy, Type T, String Text);
	~PointDD();

	void AddShift(float iXShift, float iYShift, float iZShift);

	float x;
	float y;
	Action action;
	Type iType;
	String sText;
};

#endif //GRAPCHICS_POINTDD_H_

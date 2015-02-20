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

	PointDD(float X, float Y, Action iA);
	PointDD(float X, float Y, Action iA, Type T);
	PointDD(float X, float Y, Type T);
	PointDD(float X, float Y, Type T, String Text);
	~PointDD();

	void AddShift(float iXShift, float iYShift, float iZShift);

	float fX;
	float fY;
	Action iAction;
	Type iType;
	String sText;
};

#endif //GRAPCHICS_POINTDD_H_

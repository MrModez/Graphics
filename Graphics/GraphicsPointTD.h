// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: 3D Point
//
// =============================================================================

#ifndef GRAPCHICS_POINTTD_H_
#define GRAPCHICS_POINTTD_H_

#include "GraphicsShared.h"
#include "GraphicsPointDD.h"

class PointTD : public PointDD {
public:
	PointTD(float X, float Y, float Z, Action iA);
	PointTD(float X, float Y, float Z, Action iA, Type T);
	PointTD(float X, float Y, float Z, Type T);
	PointTD(float X, float Y, float Z, Type T, String Text);
	~PointTD();

	float fZ;
};

#endif //GRAPCHICS_POINTTD_H_

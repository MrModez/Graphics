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
	PointTD(float ix, float iy, float iz, Action iA);
	PointTD(float ix, float iy, float iz, Action iA, Type T);
	PointTD(float ix, float iy, float iz, Type T);
	PointTD(float ix, float iy, float iz, Type T, String Text);
	~PointTD();

	PointDD* GetPointDD();

	float z;
};

#endif //GRAPCHICS_POINTTD_H_

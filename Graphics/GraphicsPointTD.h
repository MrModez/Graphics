#ifndef GraphicsPointTD
#define GraphicsPointTD

#include "GraphicsShared.h"
#include "GraphicsPointDD.h"

class PointTD : public PointDD {
public:
	PointTD(float ix, float iy, float iz, Action iA);
	PointTD(float ix, float iy, float iz, Action iA, Type T);
	PointTD(float ix, float iy, float iz, Type T);
	PointTD(float ix, float iy, float iz, Type T, String Text);
	PointTD& operator = (const PointTD & rhs);

	float z;
};

#endif

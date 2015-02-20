// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: 3D Object
//
// =============================================================================

#ifndef GRAPCHICS_OBJECTTD_H_
#define GRAPCHICS_OBJECTTD_H_

#include "GraphicsShared.h"
#include "GraphicsPointTD.h"
#include "GraphicsCamera.h"

class ObjectTD : ObjectShared {
public:
	ObjectTD(std::vector<PointTD*>Object);
	ObjectTD();
	~ObjectTD();

	virtual void Paint(TCanvas* pCanvas, OCamera* pCamera);
	void AddPoint(PointTD * Point);

	std::vector<PointTD*>pPointsTD;
};

#endif //GRAPCHICS_OBJECTTD_H_

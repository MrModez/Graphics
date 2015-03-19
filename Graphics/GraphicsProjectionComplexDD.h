// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: Projection from 3D Object to 2D Object by the OCamera
//
// =============================================================================

#ifndef GRAPCHICS_PROJECTIONCOMPLEXDD_H_
#define GRAPCHICS_PROJECTIONCOMPLEXDD_H_

#include "GraphicsShared.h"
#include "GraphicsCameraDD.h"
#include "GraphicsCameraTD.h"
#include "GraphicsObjectTD.h"
#include "GraphicsObjectDD.h"
#include "GraphicsPointTD.h"
#include "GraphicsPointDD.h"

class ProjectionComplexDD : public ObjectDD {
public:
	ProjectionComplexDD(ObjectTD* pObjectTD, CameraDD* pCamera);
	virtual ~ProjectionComplexDD();

	virtual void Paint(DefCanvas* pCanvas, CameraDD* pCamera);
	PointTD*CreatePointTD(PointTD* pPointTD, Action ACT, bool iX, bool iY,
		bool iZ);
	std::vector<PointDD*>Projection(ObjectTD* pObjectTD, CameraDD* pCamera);
	void AddShift(std::vector<PointDD*>vectorDD, float iXShift, float iYShift,
		float iZShift);
	PointTD* Rotate3D(PointTD pPointTD);
	PointDD* Rotate3D(PointTD pPointTD, Quarter Quart);
	ObjectDD* ToObject();
};

#endif //GRAPCHICS_PROJECTIONCOMPLEXDD_H_

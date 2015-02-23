// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: Projection from 3D Object to 2D Object by the OCamera
//
// =============================================================================

#ifndef GRAPCHICS_PROJECTIONORTODD_H_
#define GRAPCHICS_PROJECTIONORTODD_H_

#include "GraphicsShared.h"
#include "GraphicsCameraDD.h"
#include "GraphicsCameraTD.h"
#include "GraphicsObjectTD.h"
#include "GraphicsObjectDD.h"
#include "GraphicsPointTD.h"
#include "GraphicsPointDD.h"

class ProjectionOrtoDD : public ObjectDD {
public:
	ProjectionOrtoDD(ObjectTD* pObjectTD, CameraTD* pCamera);
	virtual ~ProjectionOrtoDD();

	virtual void Paint(DefCanvas* pCanvas, CameraTD* pCamera);
	std::vector<PointDD*>Projection(ObjectTD* pObjectTD, CameraTD* pCamera);
	PointTD Multiple(float m[AXIS_COUNT][AXIS_COUNT], PointTD m2);
	PointTD* Rotate3D(PointTD pPointTD, float fPitch, float fRoll, float fYaw);
	ObjectDD* ToObject();
	float DegToRad(float in);

	static float matrix[AXIS_COUNT][AXIS_COUNT];

	// std::vector<PointDD*>pPointsDD;
};

#endif //GRAPCHICS_PROJECTIONORTODD_H_

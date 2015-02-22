// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: Projection from 3D Object to 2D Object by the OCamera
//
// =============================================================================

#ifndef GRAPCHICS_PROJECTIONDD_H_
#define GRAPCHICS_PROJECTIONDD_H_

#include "GraphicsShared.h"
#include "GraphicsCameraDD.h"
#include "GraphicsCameraTD.h"
#include "GraphicsObjectTD.h"
#include "GraphicsObjectDD.h"
#include "GraphicsPointTD.h"
#include "GraphicsPointDD.h"

class ProjectionDD : public ObjectDD {
public:
	ProjectionDD(ObjectTD* pObjectTD, CameraTD* pCamera);
	ProjectionDD(ObjectTD* pObjectTD, CameraDD* pCamera);
	~ProjectionDD();

	virtual void Paint(DefCanvas* pCanvas, CameraTD* pCamera);
	virtual void Paint(DefCanvas* pCanvas, CameraDD* pCamera);
	std::vector<PointDD*>Projection(ObjectTD* pObjectTD, CameraTD* pCamera);
	std::vector<PointDD*>Projection(ObjectTD* pObjectTD, CameraDD* pCamera);
	PointTD Multiple(float m[AXIS_COUNT][AXIS_COUNT], PointTD m2);
	PointTD MultipleW(float m[AXIS_COUNT][AXIS_COUNT], PointTD m2);
	PointTD* Rotate3D(PointTD pPointTD, float fPitch, float fRoll, float fYaw);
	PointTD* Rotate3D(PointTD pPointTD);
	PointTD* Rotate3D(PointTD pPointTD, Quarter Quart);
	ObjectDD* ToObject();
	float DegToRad(float in);

	static float matrix[AXIS_COUNT][AXIS_COUNT];

	// std::vector<PointDD*>pPointsDD;
};

#endif //GRAPCHICS_PROJECTIONDD_H_

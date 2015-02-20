#ifndef GraphicsProjectionDD
#define GraphicsProjectionDD

#include "GraphicsShared.h"
#include "GraphicsCamera.h"
#include "GraphicsObjectTD.h"
#include "GraphicsObjectDD.h"
#include "GraphicsPointTD.h"
#include "GraphicsPointDD.h"

class ProjectionDD : ObjectDD {
public:
	ProjectionDD(ObjectTD* pObjectTD, OCamera* pCamera);
	// ProjectionDD(PointTD* pPointTD, OCamera* pCamera);

	// PointDD* Projection(PointTD* pPointTD, OCamera* pCamera);
	std::vector<PointDD*>Projection(ObjectTD* pObjectTD, OCamera* pCamera);
	PointTD Multiple(float m[AXIS_COUNT][AXIS_COUNT], PointTD m2);
	PointTD Rotate3D(PointTD oPointTD, float fPitch, float fRoll, float fYaw);
	float DegToRad(float in);

	static float matrix[AXIS_COUNT][AXIS_COUNT];

	std::vector<PointDD*>pPointsDD;
};

#endif

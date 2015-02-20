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
	PointTD Multiple(float m[AxisCount][AxisCount], PointTD m2);
	PointTD Rotate3D(PointTD oPointTD, float fPitch, float fRoll, float fYaw);
	float DegToRad(float in);

	static float matrix[AxisCount][AxisCount];

	std::vector<PointDD*>pPointsDD;
};

#endif

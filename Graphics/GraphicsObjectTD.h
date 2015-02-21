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

class ObjectTD : public  ObjectShared {
public:
	ObjectTD(std::vector<PointTD*>Object);
	ObjectTD();
	ObjectTD(String ID);
	~ObjectTD();

	virtual void Paint(DefCanvas* pCanvas, OCamera* pCamera);
	void AddPoint(PointTD * Point);
	void SetParameters(DrawPar Par);

	void SetCanvasSettings(DefCanvas* pCanvas);
	void SetCanvasDefaults(DefCanvas* pCanvas);

	void SetPos(float X, float Y, float Z);

	std::vector<PointTD*>pPointsTD;

	DrawPar Par;
	String ObjectID;
};

#endif //GRAPCHICS_OBJECTTD_H_

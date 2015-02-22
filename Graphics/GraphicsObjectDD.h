// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: 2D Object
//
// =============================================================================

#ifndef GRAPCHICS_OBJECTDD_H_
#define GRAPCHICS_OBJECTDD_H_

#include "GraphicsShared.h"
#include "GraphicsObjectTD.h"
#include "GraphicsPointDD.h"

class ObjectDD : public ObjectShared {
public:
	ObjectDD(std::vector<PointDD*>Object);
	ObjectDD();
	ObjectDD(String ID);
	~ObjectDD();

	virtual void PaintTD(DefCanvas* pCanvas, CameraTD* pCamera);
	virtual void PaintDD(DefCanvas* pCanvas, CameraDD* pCamera);
	void AddPoint(PointDD * Point);
	void SetParameters(DrawPar Par);

	void SetCanvasSettings(DefCanvas* pCanvas);
	void SetCanvasDefaults(DefCanvas* pCanvas);

	std::vector<PointDD*>pPointsDD;

	DrawPar Par;
	String ObjectID;
};

#endif //GRAPCHICS_OBJECTDD_H_

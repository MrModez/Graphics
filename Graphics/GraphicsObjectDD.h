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

class ObjectDD : ObjectShared {
public:
	ObjectDD(std::vector<PointDD*>Object);
	ObjectDD();
	~ObjectDD();

	virtual void Paint(TCanvas* pCanvas, OCamera* pCamera);
	void AddPoint(PointDD * Point);

	std::vector<PointDD*>pPointsDD;

	// Param iParam;
};

#endif //GRAPCHICS_OBJECTDD_H_

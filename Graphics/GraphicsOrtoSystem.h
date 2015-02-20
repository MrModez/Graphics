// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: Ortogonal System. Requires OCamera
//
// =============================================================================

#ifndef GRAPCHICS_OTROSYSTEM_H_
#define GRAPCHICS_OTROSYSTEM_H_

#include "GraphicsShared.h"
#include "GraphicsCamera.h"
// #include "GraphicsProjectionDD.h"
// Ortogonal System

#include "GraphicsObjectTD.h"

class OrtoSystem {
public:
	OrtoSystem() {
	};

	OrtoSystem(OCamera* Camera);
	~OrtoSystem();

	void Paint(TCanvas* pCanvas);
	void AddObject(ObjectShared * pObject);

	OCamera* pCamera;

	// std::vector<ObjectTD*>pObjectsTD;
	std::vector<ObjectShared*>pObjects;
};

#endif //GRAPCHICS_OTROSYSTEM_H_

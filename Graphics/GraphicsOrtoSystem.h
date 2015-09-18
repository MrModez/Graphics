// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: Ortogonal System. Requires CameraTD
//
// =============================================================================

#ifndef GRAPCHICS_OTROSYSTEM_H_
#define GRAPCHICS_OTROSYSTEM_H_

#include "GraphicsShared.h"

class CameraTD;

class OrtoSystem {
public:
	OrtoSystem() {
	};

	OrtoSystem(CameraTD* Camera);
	~OrtoSystem();

	void Paint(DefCanvas* pCanvas);
	void AddObject(ObjectShared* pObject);
	ObjectShared* FindObject(String ID);

	CameraTD* pCamera;

	std::vector<ObjectShared*>pObjects;
};

#endif //GRAPCHICS_OTROSYSTEM_H_

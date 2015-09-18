// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: Ortogonal System. Requires CameraDD
//
// =============================================================================

#ifndef GRAPCHICS_COMPLEXSYSTEM_H_
#define GRAPCHICS_COMPLEXSYSTEM_H_

#include "GraphicsShared.h"

class CameraDD;

class ComplexSystem {
public:
	ComplexSystem() {
	};

	ComplexSystem(CameraDD* Camera);
	~ComplexSystem();

	void Paint(DefCanvas* pCanvas);
	void AddObject(ObjectShared* pObject);
	ObjectShared* FindObject(String ID);

	CameraDD* pCamera;

	std::vector<ObjectShared*>pObjects;
};

#endif //GRAPCHICS_COMPLEXSYSTEM_H_

// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: Ortogonal System. Requires OCamera
//
// =============================================================================

#include "GraphicsOrtoSystem.h"

OrtoSystem::OrtoSystem(OCamera* Camera) {
	pCamera = Camera;
};

OrtoSystem::~OrtoSystem() {
	for (unsigned int i = 0; i < pObjects.size(); i++) {
		delete pObjects[i];
	}
	pObjects.clear();
};

void OrtoSystem::Paint(DefCanvas* pCanvas) {
	for (unsigned int i = 0; i < pObjects.size(); i++) {
		pObjects[i]->Paint(pCanvas, pCamera);
	}
}

void OrtoSystem::AddObject(ObjectShared * pObject) {
	pObjects.push_back(pObject);
};

ObjectShared* OrtoSystem::FindObject(String ID) {
	for (unsigned int i = 0; i < pObjects.size(); i++) {
		if (pObjects[i]->ObjectID == ID) {
			return pObjects[i];
		}
	}
	return NULL;
};

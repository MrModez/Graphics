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

void OrtoSystem::Paint(TCanvas* pCanvas) {

	for (unsigned int i = 0; i < pObjects.size(); i++) {
		//int qwe = pCanvas->Pen->Width;
		pObjects[i]->Paint(pCanvas, pCamera);
	}

}

void OrtoSystem::AddObject(ObjectShared * pObject) {
	pObjects.push_back(pObject);
};

// Ortogonal System

#include "GraphicsOrtoSystem.h"

OrtoSystem::OrtoSystem(OCamera* Camera) {
	pCamera = Camera;
};

OrtoSystem::~OrtoSystem() {
	for (int i = 0; i < pObjects.size(); i++) {
		delete pObjects[i];
	}
	pObjects.clear();
};

void OrtoSystem::Paint(TCanvas* pCanvas) {

	for (int i = 0; i < pObjects.size(); i++) {
		pObjects[i]->Paint(pCanvas, pCamera);
	}

}

void OrtoSystem::AddObject(ObjectShared * pObject) {
	pObjects.push_back(pObject);
};

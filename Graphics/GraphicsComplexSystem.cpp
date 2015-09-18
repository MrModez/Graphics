// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: Ortogonal System. Requires CameraDD
//
// =============================================================================

#include "GraphicsComplexSystem.h"
#include "GraphicsCameraDD.h"
#include "GraphicsObjectTD.h"

ComplexSystem::ComplexSystem(CameraDD* Camera) {
	pCamera = Camera;
};

ComplexSystem::~ComplexSystem() {
	for (unsigned int i = 0; i < pObjects.size(); i++) {
		delete pObjects[i];
	}
	pObjects.clear();
};

void ComplexSystem::Paint(DefCanvas* pCanvas) {
	for (unsigned int i = 0; i < pObjects.size(); i++) {
		pObjects[i]->PaintDD(pCanvas, pCamera);
	}
}

void ComplexSystem::AddObject(ObjectShared * pObject) {
	pObjects.push_back(pObject);
};

ObjectShared* ComplexSystem::FindObject(String ID) {
	for (unsigned int i = 0; i < pObjects.size(); i++) {
		if (pObjects[i]->ObjectID == ID) {
			return pObjects[i];
		}
	}
	return NULL;
};

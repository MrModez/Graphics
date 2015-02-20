// Ortogonal System

#include "GraphicsOrtoSystem.h"

OrtoSystem::OrtoSystem(OCamera* Camera) {
	pCamera = Camera;
};

OrtoSystem::~OrtoSystem() {
	for (int i = 0; i < pObjectsTD.size(); i++) {
		delete pObjectsTD[i];
	}
	pObjectsTD.clear();
};

void OrtoSystem::Paint(TDirect2DCanvas* pCanvas) {
	for (int i = 0; i < pObjectsTD.size(); i++) {
		ProjectionDD* pProjection = new ProjectionDD(pObjectsTD[i], pCamera);
		for (int j = 0; j < pProjection->pProjection->pPointsDD.size(); j++) {
			PointDD* pObjectDD = pProjection->pProjection->pPointsDD[j];
			if (pObjectDD->action == move)
				pCanvas->MoveTo(pObjectDD->x, pObjectDD->y);
			else
				pCanvas->LineTo(pObjectDD->x, pObjectDD->y);
		}
	}
}

void OrtoSystem::AddObject(ObjectTD * pObject) {
	pObjectsTD.push_back(pObject);
};

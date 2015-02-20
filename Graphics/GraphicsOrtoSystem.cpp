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

void OrtoSystem::Paint(TDirect2DCanvas* pCanvas) {

	for (int i = 0; i < pObjects.size(); i++) {
		pObjects[i]->Paint(pCanvas, pCamera);

		/*
		 ProjectionDD* pProjection = new ProjectionDD(pObjects[i], pCamera);

		 for (int j = 0; j < pProjection->pProjection->pPointsDD.size(); j++) {
		 PointDD* pObjectDD = pProjection->pProjection->pPointsDD[j];
		 // if (pObjectDD->action == move)
		 // pCanvas->MoveTo(pObjectDD->x, pObjectDD->y);
		 // else
		 // pCanvas->LineTo(pObjectDD->x, pObjectDD->y);
		 }
		 */
		/*
		 for (int j = 0; j < pObjects[i]->pPointsTD.size(); j++) {
		 PointTD* pObjectTD = pObjects[i]->pPointsTD[j];
		 if (pObjectsTD[i]->pPointsTD[j]->action == move)
		 pCanvas->MoveTo(pObjectTD->x, pObjectTD->y);
		 else
		 pCanvas->LineTo(pObjectTD->x, pObjectTD->y);
		 } */
	}

}

void OrtoSystem::AddObject(ObjectShared * pObject) {
	pObjects.push_back(pObject);
};

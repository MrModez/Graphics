// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: 3D Object
//
// =============================================================================

#include "GraphicsObjectTD.h"
#include "GraphicsProjectionDD.h"

ObjectTD::ObjectTD(std::vector<PointTD*>Object) {
	pPointsTD = Object;
}

ObjectTD::ObjectTD() {
}

ObjectTD::~ObjectTD() {
	for (unsigned int i = 0; i < pPointsTD.size(); i++) {
		delete pPointsTD[i];
	}
	pPointsTD.clear();
}

void ObjectTD::Paint(TCanvas* pCanvas, OCamera* pCamera) {
	ProjectionDD* pProjection = new ProjectionDD(this, pCamera);
	for (unsigned int j = 0; j < pProjection->pPointsDD.size(); j++) {
		PointDD* pObjectDD = pProjection->pPointsDD[j];
		switch (pObjectDD->action) {
		case ACT_MOVE:
			pCanvas->MoveTo(pObjectDD->x, pObjectDD->y);
			break;
		case ACT_DRAW:
			pCanvas->LineTo(pObjectDD->x, pObjectDD->y);
			break;
		case ACT_NONE:
			switch (pPointsTD[j]->iType) {
			case TYPE_TEXT:
				pCanvas->TextOutW(pObjectDD->x, pObjectDD->y,
					pPointsTD[j]->sText);
				break;
			case TYPE_POINT:
				pCanvas->Ellipse(pObjectDD->x - 2, pObjectDD->y - 2,
					pObjectDD->x + 2, pObjectDD->y + 2);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
	delete pProjection;
}

void ObjectTD::AddPoint(PointTD * Point) {
	pPointsTD.push_back(Point);
}

// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: 2D Object
//
// =============================================================================

#include "GraphicsObjectDD.h"

ObjectDD::ObjectDD(std::vector<PointDD*>Object) {
	pPointsDD = Object;
}

ObjectDD::ObjectDD() {
}

ObjectDD::~ObjectDD() {
	for (unsigned int i = 0; i < pPointsDD.size(); i++) {
		delete pPointsDD[i];
	}
	pPointsDD.clear();
}

void ObjectDD::Paint(DefCanvas* pCanvas, OCamera* pCamera) {
	for (unsigned int j = 0; j < pPointsDD.size(); j++) {
		PointDD* pObjectDD = pPointsDD[j];
		switch (pObjectDD->iAction) {
		case ACT_MOVE:
			pCanvas->MoveTo(pObjectDD->fX, pObjectDD->fY);
			break;
		case ACT_DRAW:
			pCanvas->LineTo(pObjectDD->fX, pObjectDD->fY);
			break;
		case ACT_NONE:
			switch (pPointsDD[j]->iType) {
			case TYPE_TEXT:
				pCanvas->TextOutW(pObjectDD->fX, pObjectDD->fY,
					pPointsDD[j]->sText);
				break;
			case TYPE_POINT:
				pCanvas->Ellipse(pObjectDD->fX - 2, pObjectDD->fY - 2,
					pObjectDD->fX + 2, pObjectDD->fY + 2);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}

void ObjectDD::AddPoint(PointDD * Point) {
	pPointsDD.push_back(Point);
}

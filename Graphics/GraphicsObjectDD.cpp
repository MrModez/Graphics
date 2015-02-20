#include "GraphicsObjectDD.h"

ObjectDD::ObjectDD(std::vector<PointDD*>Object) {
	pPointsDD = Object;
}

ObjectDD::ObjectDD() {
}

void ObjectDD::Paint(TCanvas* pCanvas, OCamera* pCamera) {
	for (int j = 0; j < pPointsDD.size(); j++) {
		PointDD* pObjectDD = pPointsDD[j];
		switch (pObjectDD->action) {
		case ACT_MOVE:
			pCanvas->MoveTo(pObjectDD->x, pObjectDD->y);
			break;
		case ACT_DRAW:
			pCanvas->LineTo(pObjectDD->x, pObjectDD->y);
			break;
		case ACT_NONE:
			switch (pPointsDD[j]->iType) {
			case TYPE_TEXT:
				pCanvas->TextOutW(pObjectDD->x, pObjectDD->y,
					pPointsDD[j]->sText);
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
}

void ObjectDD::AddPoint(PointDD * Point) {
	pPointsDD.push_back(Point);
}

#include "GraphicsObjectDD.h"

ObjectDD::ObjectDD(std::vector<PointDD*>Object) {
	pPointsDD = Object;
}

ObjectDD::ObjectDD() {
}

void ObjectDD::Paint(TDirect2DCanvas* pCanvas, OCamera* pCamera) {
	for (int j = 0; j < pPointsDD.size(); j++) {
		PointDD* pObjectDD = pPointsDD[j];
		if (pObjectDD->action == ACT_MOVE)
			pCanvas->MoveTo(pObjectDD->x, pObjectDD->y);
		else
			pCanvas->LineTo(pObjectDD->x, pObjectDD->y);
	}
}

void ObjectDD::AddPoint(PointDD * Point) {
	pPointsDD.push_back(Point);
}

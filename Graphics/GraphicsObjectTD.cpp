#include "GraphicsObjectTD.h"
#include "GraphicsProjectionDD.h"

ObjectTD::ObjectTD(std::vector<PointTD*>Object) {
	pPointsTD = Object;
}

ObjectTD::ObjectTD() {
}

ObjectTD::~ObjectTD() {

}

void ObjectTD::Paint(TDirect2DCanvas* pCanvas, OCamera* pCamera) {
	ProjectionDD* pProjection = new ProjectionDD(this, pCamera);
	for (int j = 0; j < pProjection->pPointsDD.size(); j++) {
		PointDD* pObjectDD = pProjection->pPointsDD[j];
		if (pObjectDD->action == move)
			pCanvas->MoveTo(pObjectDD->x, pObjectDD->y);
		else
			pCanvas->LineTo(pObjectDD->x, pObjectDD->y);
	}
}

void ObjectTD::AddPoint(PointTD * Point) {
	pPointsTD.push_back(Point);
}

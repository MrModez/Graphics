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

ObjectTD::ObjectTD(String ID) {
	ObjectID = ID;
}

ObjectTD::~ObjectTD() {
	for (unsigned int i = 0; i < pPointsTD.size(); i++) {
		delete pPointsTD[i];
	}
	pPointsTD.clear();
}

void ObjectTD::Paint(DefCanvas* pCanvas, OCamera* pCamera) {
	ProjectionDD* pProjection = new ProjectionDD(this, pCamera);
	ObjectDD* pObjectDD = pProjection->ToObject();
	pObjectDD->Paint(pCanvas, pCamera);
	delete pProjection;
	delete pObjectDD;
}

void ObjectTD::SetParameters(DrawPar P) {
	Par = P;
};

void ObjectTD::AddPoint(PointTD * Point) {
	pPointsTD.push_back(Point);
}

void ObjectTD::SetCanvasSettings(DefCanvas* pCanvas) {
	pCanvas->Pen->Width = Par.iWidth;
	pCanvas->Pen->Color = Par.iColor;
	pCanvas->Pen->Style = Par.iStyle;
}

void ObjectTD::SetCanvasDefaults(DefCanvas* pCanvas) {
	pCanvas->Pen->Width = DEFAULT_WIDTH;
	pCanvas->Pen->Color = DEFAULT_COLOR;
	pCanvas->Pen->Style = DEFAULT_STYLE;
}

void ObjectTD::SetPos(float X, float Y, float Z) {
	for (unsigned int i = 0; i < pPointsTD.size(); i++) {
		if (pPointsTD[i]->iType == TYPE_POINT) {
			pPointsTD[i]->SetPos(X, Y, Z);
		}
	}
};

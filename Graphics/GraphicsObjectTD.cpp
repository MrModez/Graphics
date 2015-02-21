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

void ObjectTD::Paint(DefCanvas* pCanvas, OCamera* pCamera) {
	ProjectionDD* pProjection = new ProjectionDD(this, pCamera);
	for (unsigned int j = 0; j < pProjection->pPointsDD.size(); j++) {
		PointDD* pObjectDD = pProjection->pPointsDD[j];
		SetCanvasSettings(pCanvas);
		switch (pObjectDD->iAction) {
		case ACT_MOVE:
			pCanvas->MoveTo(pObjectDD->fX, pObjectDD->fY);
			break;
		case ACT_DRAW:
			pCanvas->LineTo(pObjectDD->fX, pObjectDD->fY);
			break;
		case ACT_NONE:
			switch (pPointsTD[j]->iType) {
			case TYPE_TEXT:
				pCanvas->TextOutW(pObjectDD->fX, pObjectDD->fY,
					pPointsTD[j]->sText);
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
		SetCanvasDefaults(pCanvas);
	}
	delete pProjection;
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

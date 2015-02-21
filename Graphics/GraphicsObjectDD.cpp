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

ObjectDD::ObjectDD(String ID) {
	ObjectID = ID;
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
		SetCanvasSettings(pCanvas);
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
				pCanvas->Ellipse(pObjectDD->fX - DEFAULT_RADIUS,
					pObjectDD->fY - DEFAULT_RADIUS,
					pObjectDD->fX + DEFAULT_RADIUS,
					pObjectDD->fY + DEFAULT_RADIUS);
				break;
			default:
				// pCanvas->TextOutW(pObjectDD->fX, pObjectDD->fY, this->ObjectID);
				break;
			}
			break;
		default:
			break;
		}
		SetCanvasDefaults(pCanvas);
	}
}

void ObjectDD::SetParameters(DrawPar P) {
	Par = P;
};

void ObjectDD::AddPoint(PointDD * Point) {
	pPointsDD.push_back(Point);
}

void ObjectDD::SetCanvasSettings(DefCanvas* pCanvas) {
	pCanvas->Pen->Width = Par.iWidth;
	pCanvas->Pen->Color = Par.iColor;
	pCanvas->Pen->Style = Par.iStyle;
}

void ObjectDD::SetCanvasDefaults(DefCanvas* pCanvas) {
	pCanvas->Pen->Width = DEFAULT_WIDTH;
	pCanvas->Pen->Color = DEFAULT_COLOR;
	pCanvas->Pen->Style = DEFAULT_STYLE;
}

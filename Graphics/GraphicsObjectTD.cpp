// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: 3D Object
//
// =============================================================================

#include "GraphicsObjectTD.h"
#include "GraphicsProjectionOrtoDD.h"
#include "GraphicsProjectionComplexDD.h"

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

ObjectTD* ObjectTD::CopyObjectTD() {
	ObjectTD* CopyTD = new ObjectTD(ObjectID);
	for (unsigned int i = 0; i < pPointsTD.size(); i++) {
		CopyTD->AddPoint(new PointTD(pPointsTD[i]->fX, pPointsTD[i]->fY,
			pPointsTD[i]->fZ, pPointsTD[i]->iAction, pPointsTD[i]->iType,
			pPointsTD[i]->sText));
	}
	CopyTD->SetParameters(this->Par);
	return CopyTD;
}

void ObjectTD::PaintTD(DefCanvas* pCanvas, CameraTD* pCamera) {
	if (Par.bProj == 1) {
		ProjectionOrtoDD* pProjection;

		Par.iProjStyle = PROJ_LINES;
		pProjection = new ProjectionOrtoDD(this, pCamera);
		pProjection->Par.iColor = clSilver;
		pProjection->Par.iStyle = psDash;
		pProjection->Par.iWidth = 2;
		pProjection->PaintTD(pCanvas, pCamera);
		delete pProjection;

		Par.iProjStyle = PROJ_DOTS;
		pProjection = new ProjectionOrtoDD(this, pCamera);
		pProjection->Par.iColor = clRed;
		pProjection->Par.iStyle = psDash;
		pProjection->Par.iWidth = 3;
		pProjection->PaintTD(pCanvas, pCamera);
		delete pProjection;
	}
	Par.iProjStyle = PROJ_NONE;
	ProjectionOrtoDD* pProjection = new ProjectionOrtoDD(this, pCamera);
	pProjection->PaintTD(pCanvas, pCamera);
	delete pProjection;
}

void ObjectTD::PaintDD(DefCanvas* pCanvas, CameraDD* pCamera) {
	if (Par.bProj == 1) {
		ProjectionComplexDD* pProjection;

		Par.iProjStyle = PROJ_LINES;
		pProjection = new ProjectionComplexDD(this, pCamera);
		pProjection->Par.iColor = clSilver;
		pProjection->Par.iStyle = psDash;
		pProjection->Par.iWidth = 2;
		pProjection->PaintDD(pCanvas, pCamera);
		delete pProjection;

		Par.iProjStyle = PROJ_DOTS;
		pProjection = new ProjectionComplexDD(this, pCamera);
		pProjection->Par.iColor = clRed;
		pProjection->Par.iStyle = psDash;
		pProjection->Par.iWidth = 3;
		pProjection->PaintDD(pCanvas, pCamera);
		delete pProjection;
	}
	else {
		Par.iProjStyle = PROJ_NONE;
		ProjectionComplexDD* pProjection =
			new ProjectionComplexDD(this, pCamera);
		pProjection->PaintDD(pCanvas, pCamera);
		delete pProjection;
	}
}

void ObjectTD::SetParameters(DrawPar P) {
	Par = P;
};

void ObjectTD::SetDrawProj(bool bDraw) {
	Par.bProj = bDraw;
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
		if (pPointsTD[i]->iType == TYPE_POINT ||
			pPointsTD[i]->iType == TYPE_TEXT) {
			pPointsTD[i]->SetPos(X, Y, Z);
		}
	}
};

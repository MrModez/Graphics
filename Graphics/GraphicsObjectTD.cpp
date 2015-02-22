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
		ObjectTD* Obj = GetAxisProjection();
		if (!Obj)
			return;
		ProjectionDD* pObjProjection = new ProjectionDD(Obj, pCamera);
		ObjectDD* pObjectObjDD = pObjProjection->ToObject();
		pObjectObjDD->PaintTD(pCanvas, pCamera);
		delete Obj;
		delete pObjProjection;
		delete pObjectObjDD;
	}

	ProjectionDD* pProjection = new ProjectionDD(this, pCamera);
	ObjectDD* pObjectDD = pProjection->ToObject();
	pObjectDD->PaintTD(pCanvas, pCamera);
	delete pProjection;
	delete pObjectDD;
}

void ObjectTD::PaintDD(DefCanvas* pCanvas, CameraDD* pCamera) {
	if (Par.bProj == 1) {
		ObjectTD* Obj = new ObjectTD(*this);
		Obj->Par.iColor = clSilver;
		Obj->Par.iStyle = psDash;
		Obj->Par.iWidth = 2;
		Obj->Par.iProjStyle = PROJ_LINES;
		ProjectionDD* pProjection = new ProjectionDD(Obj, pCamera);
		ObjectDD* pObjectDD = pProjection->ToObject();
		pObjectDD->PaintDD(pCanvas, pCamera);
		delete pProjection;
		delete pObjectDD;

		Obj = new ObjectTD(*this);
		Obj->Par.iColor = clRed;
		Obj->Par.iStyle = psDash;
		Obj->Par.iWidth = 3;
		Obj->Par.iProjStyle = PROJ_DOTS;
		pProjection = new ProjectionDD(Obj, pCamera);
		pObjectDD = pProjection->ToObject();
		pObjectDD->PaintDD(pCanvas, pCamera);
		delete pProjection;
		delete pObjectDD;
	}
	else {
		ProjectionDD* pProjection = new ProjectionDD(this, pCamera);
		ObjectDD* pObjectDD = pProjection->ToObject();
		pObjectDD->PaintDD(pCanvas, pCamera);
		delete pProjection;
		delete pObjectDD;
	}

	/* if (Par.bProj == 1) {
	 ObjectTD* Obj = GetAxisProjection();
	 if (!Obj)
	 return;
	 ProjectionDD* pObjProjection = new ProjectionDD(Obj, pCamera);
	 ObjectDD* pObjectObjDD = pObjProjection->ToObject();
	 pObjectObjDD->PaintDD(pCanvas, pCamera);
	 delete Obj;
	 delete pObjProjection;
	 delete pObjectObjDD;
	 }
	 else {
	 ProjectionDD* pProjection = new ProjectionDD(this, pCamera);
	 ObjectDD* pObjectDD = pProjection->ToObject();
	 pObjectDD->PaintDD(pCanvas, pCamera);
	 delete pProjection;
	 delete pObjectDD;
	 } */
}

ObjectTD* ObjectTD::GetAxisProjection() {
	ObjectTD* Obj = new ObjectTD(ObjectID);
	for (unsigned int i = 0; i < pPointsTD.size(); i++) {
		if (pPointsTD[i]->iType == TYPE_POINT) {
			Obj->AddPoint(new PointTD(pPointsTD[i]->fX, pPointsTD[i]->fY,
				pPointsTD[i]->fZ, ACT_MOVE));
			Obj->AddPoint(new PointTD(0, pPointsTD[i]->fY, pPointsTD[i]->fZ,
				ACT_DRAW));
			Obj->AddPoint(new PointTD(pPointsTD[i]->fX, pPointsTD[i]->fY,
				pPointsTD[i]->fZ, ACT_MOVE));
			Obj->AddPoint(new PointTD(pPointsTD[i]->fX, 0, pPointsTD[i]->fZ,
				ACT_DRAW));
			Obj->AddPoint(new PointTD(pPointsTD[i]->fX, pPointsTD[i]->fY,
				pPointsTD[i]->fZ, ACT_MOVE));
			Obj->AddPoint(new PointTD(pPointsTD[i]->fX, pPointsTD[i]->fY, 0,
				ACT_DRAW));
			Obj->AddPoint(new PointTD(0, pPointsTD[i]->fY, pPointsTD[i]->fZ,
				pPointsTD[i]->iAction, pPointsTD[i]->iType,
				pPointsTD[i]->sText));
			Obj->AddPoint(new PointTD(pPointsTD[i]->fX, 0, pPointsTD[i]->fZ,
				pPointsTD[i]->iAction, pPointsTD[i]->iType,
				pPointsTD[i]->sText));
			Obj->AddPoint(new PointTD(pPointsTD[i]->fX, pPointsTD[i]->fY, 0,
				pPointsTD[i]->iAction, pPointsTD[i]->iType,
				pPointsTD[i]->sText));
		}
	}
	Obj->Par.iColor = clSilver;
	Obj->Par.iStyle = psDash;
	Obj->Par.iWidth = 2;

	return Obj;
};

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

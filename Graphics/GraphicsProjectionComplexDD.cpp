// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: Projection from 3D Object to 2D Object by the OCamera
//
// =============================================================================

#include "GraphicsProjectionComplexDD.h"

ProjectionComplexDD::ProjectionComplexDD(ObjectTD* pObjectTD, CameraDD* pCamera)
{
	Par = pObjectTD->Par;
	ObjectID = pObjectTD->ObjectID;
	pPointsDD = Projection(pObjectTD, pCamera);
}

ProjectionComplexDD::~ProjectionComplexDD() {
	for (unsigned int i = 0; i < pPointsDD.size(); i++) {
		delete pPointsDD[i];
	}
	pPointsDD.clear();
};

std::vector<PointDD*>ProjectionComplexDD::Projection(ObjectTD* pObjectTD,
	CameraDD* pCamera) {
	std::vector<PointDD*>result;
	float fX = pCamera->iXShift;
	float fY = pCamera->iYShift;
	float fZ = pCamera->iZShift;
	if (this->Par.iProjStyle == PROJ_NONE) {
		for (unsigned int i = 0; i < pObjectTD->pPointsTD.size(); i++) {
			PointDD* pPointDD = Rotate3D(*pObjectTD->pPointsTD[i]);
			pPointDD->AddShift(fX, fY, fZ);
			result.push_back(pPointDD);
		}
	}
	if (this->Par.iProjStyle == PROJ_LINES) {
		for (unsigned int i = 0; i < pObjectTD->pPointsTD.size(); i++) {
			if (pObjectTD->pPointsTD[i]->iType != TYPE_TEXT) {
				PointDD* pPointTDXZ = Rotate3D(*pObjectTD->pPointsTD[i], QXZ);
				PointDD* pPointTDXY = Rotate3D(*pObjectTD->pPointsTD[i], QXY);
				PointDD* pPointTDYY = Rotate3D(*pObjectTD->pPointsTD[i], QYY);
				PointDD* pPointTDYZ = Rotate3D(*pObjectTD->pPointsTD[i], QYZ);

				// Lines
				PointDD* pPointDDXZ1 = new PointDD(*pPointTDXZ);
				PointDD* pPointDDXY1 = new PointDD(*pPointTDXY);
				PointDD* pPointDDYY3 = new PointDD(*pPointTDYY);
				PointDD* pPointDDYZ1 = new PointDD(*pPointTDYZ);
				PointDD* pPointDDYZ3 = new PointDD(*pPointTDYZ);

				pPointDDXZ1->SetSettings(ACT_MOVE, TYPE_OBJECT, "");
				pPointDDXY1->SetSettings(ACT_DRAW, TYPE_OBJECT, "");
				pPointDDYY3->SetSettings(ACT_DRAW, TYPE_OBJECT, "");
				pPointDDYZ3->SetSettings(ACT_ARC, TYPE_OBJECT, "");
				pPointDDYZ1->SetSettings(ACT_DRAW, TYPE_OBJECT, "");

				pPointDDYY3->fX = 0;
				pPointDDYZ3->fY = 0;

				pPointDDXZ1->AddShift(fX, fY, fZ);
				pPointDDXY1->AddShift(fX, fY, fZ);
				pPointDDYY3->AddShift(fX, fY, fZ);
				pPointDDYZ1->AddShift(fX, fY, fZ);
				pPointDDYZ3->AddShift(fX, fY, fZ);

				result.push_back(pPointDDXZ1);
				result.push_back(pPointDDXY1);
				result.push_back(pPointDDYY3);
				result.push_back(pPointDDYZ3);
				result.push_back(pPointDDYZ1);
				result.push_back(pPointDDXZ1);
				result.push_back(pPointDDYZ1);

				// Dots
				PointDD* pPointDDXZ2 = new PointDD(*pPointTDXZ);
				PointDD* pPointDDXY2 = new PointDD(*pPointTDXY);
				PointDD* pPointDDYY2 = new PointDD(*pPointTDYY);
				PointDD* pPointDDYZ2 = new PointDD(*pPointTDYZ);

				pPointDDXZ2->fY = 0;
				pPointDDXY2->fX = 0;
				pPointDDYY2->fY = 0;
				pPointDDYZ2->fX = 0;

				pPointDDXZ2->AddShift(fX, fY, fZ);
				pPointDDXY2->AddShift(fX, fY, fZ);
				pPointDDYY2->AddShift(fX, fY, fZ);
				pPointDDYZ2->AddShift(fX, fY, fZ);

				result.push_back(pPointDDXZ2);
				result.push_back(pPointDDXY2);
				result.push_back(pPointDDYY2);
				result.push_back(pPointDDYZ2);
			}
		}
	}
	for (unsigned int i = 0; i < pObjectTD->pPointsTD.size(); i++) {
		if (this->Par.iProjStyle == PROJ_DOTS) {
			// if (pObjectTD->pPointsTD[i]->iType != TYPE_TEXT) {
			PointDD* pPointDDXZ = Rotate3D(*pObjectTD->pPointsTD[i], QXZ);
			PointDD* pPointDDXY = Rotate3D(*pObjectTD->pPointsTD[i], QXY);
			PointDD* pPointDDYY = Rotate3D(*pObjectTD->pPointsTD[i], QYY);
			PointDD* pPointDDYZ = Rotate3D(*pObjectTD->pPointsTD[i], QYZ);

			// Dots
			PointDD* pPointDDXZ2 = new PointDD(*pPointDDXZ);
			PointDD* pPointDDXY2 = new PointDD(*pPointDDXY);
			PointDD* pPointDDYY2 = new PointDD(*pPointDDYY);
			PointDD* pPointDDYZ2 = new PointDD(*pPointDDYZ);

			pPointDDXZ2->fY = 0;
			pPointDDXY2->fX = 0;
			pPointDDYY2->fY = 0;
			pPointDDYZ2->fX = 0;
			pPointDDXZ2->sText += "X";
			pPointDDXY2->sText += "Y1";
			pPointDDYY2->sText += "Y2";
			pPointDDYZ2->sText += "Z";

			pPointDDXZ2->AddShift(fX, fY, fZ);
			pPointDDXY2->AddShift(fX, fY, fZ);
			pPointDDYY2->AddShift(fX, fY, fZ);
			pPointDDYZ2->AddShift(fX, fY, fZ);

			result.push_back(pPointDDXZ);
			result.push_back(pPointDDXY);
			result.push_back(pPointDDYZ);

			pPointDDXZ->sText += "1";
			pPointDDXY->sText += "2";
			pPointDDYZ->sText += "4";
			pPointDDXZ->AddShift(fX, fY, fZ);
			pPointDDXY->AddShift(fX, fY, fZ);
			pPointDDYZ->AddShift(fX, fY, fZ);

			result.push_back(pPointDDXZ2);
			result.push_back(pPointDDXY2);
			result.push_back(pPointDDYY2);
			result.push_back(pPointDDYZ2);
		}
	}
	return result;
};

ObjectDD* ProjectionComplexDD::ToObject() {
	ObjectDD* result = new ObjectDD();
	result->pPointsDD = this->pPointsDD;
	result->ObjectID = this->ObjectID;
	result->Par = this->Par;
	return result;
};

void ProjectionComplexDD::Paint(DefCanvas* pCanvas, CameraDD* pCamera) {
}

PointTD* ProjectionComplexDD::Rotate3D(PointTD pPointTD) {
	PointTD Result(pPointTD.fX, pPointTD.fY, 0, pPointTD.iAction,
		pPointTD.iType, pPointTD.sText);
	return new PointTD(Result);
}

PointDD* ProjectionComplexDD::Rotate3D(PointTD pPointTD, Quarter Quart) {
	float X, Y;
	switch (Quart) {
	case QXZ:
		X = pPointTD.fX;
		Y = -1.0 * pPointTD.fZ;
		break;
	case QXY:
		X = pPointTD.fX;
		Y = pPointTD.fY;
		break;
	case QYY:
		X = -1.0 * pPointTD.fY;
		Y = pPointTD.fY;
		break;
	case QYZ:
		X = -1.0 * pPointTD.fY;
		Y = -1.0 * pPointTD.fZ;
		break;
	default:
		break;
	}
	PointDD Result(X, Y, pPointTD.iAction, pPointTD.iType, pPointTD.sText);
	return new PointDD(Result);
}

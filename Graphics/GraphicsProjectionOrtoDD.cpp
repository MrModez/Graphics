// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: Projection from 3D Object to 2D Object by the OCamera
//
// =============================================================================

#include "GraphicsProjectionOrtoDD.h"

ProjectionOrtoDD::ProjectionOrtoDD(ObjectTD* pObjectTD, CameraTD* pCamera) {
	Par = pObjectTD->Par;
	ObjectID = pObjectTD->ObjectID;
	pPointsDD = Projection(pObjectTD, pCamera);
}

ProjectionOrtoDD::~ProjectionOrtoDD() {
	for (unsigned int i = 0; i < pPointsDD.size(); i++) {
		delete pPointsDD[i];
	}
	pPointsDD.clear();
};

std::vector<PointDD*>ProjectionOrtoDD::Projection(ObjectTD* pObjectTD,
	CameraTD* pCamera) {
	std::vector<PointDD*>result;
	float fX = pCamera->iXShift;
	float fY = pCamera->iYShift;
	float fZ = pCamera->iZShift;
	float fP = DegToRad(pCamera->fPitch);
	float fR = DegToRad(pCamera->fRoll);
	float fW = DegToRad(pCamera->fYaw);
	if (Par.iProjStyle == PROJ_NONE) {
		for (unsigned int i = 0; i < pObjectTD->pPointsTD.size(); i++) {
			PointTD* pPointTD = Rotate3D(*pObjectTD->pPointsTD[i], fP, fR, fW);
			PointDD* pPointDD = static_cast<PointDD*>(pPointTD);
			pPointDD->AddShift(fX, fY, fZ);
			result.push_back(pPointDD);
		}
	}
	if (Par.iProjStyle == PROJ_LINES) {
		for (unsigned int i = 0; i < pObjectTD->pPointsTD.size(); i++) {
			PointTD* pPointTD = new PointTD(*pObjectTD->pPointsTD[i]);
			PointTD* pPointTDXY = new PointTD(*pObjectTD->pPointsTD[i]);
			pPointTDXY->fZ = 0;
			PointTD* pPointTDXZ = new PointTD(*pObjectTD->pPointsTD[i]);
			pPointTDXZ->fY = 0;
			PointTD* pPointTDZY = new PointTD(*pObjectTD->pPointsTD[i]);
			pPointTDZY->fX = 0;

			pPointTD->SetSettings(ACT_MOVE, TYPE_OBJECT, "");
			pPointTDXY->SetSettings(ACT_DRAW, TYPE_OBJECT, "");
			pPointTDXZ->SetSettings(ACT_DRAW, TYPE_OBJECT, "");
			pPointTDZY->SetSettings(ACT_DRAW, TYPE_OBJECT, "");

			PointTD* pPointTD1 = Rotate3D(*pPointTD, fP, fR, fW);
			PointTD* pPointTDXY1 = Rotate3D(*pPointTDXY, fP, fR, fW);
			PointTD* pPointTDXZ1 = Rotate3D(*pPointTDXZ, fP, fR, fW);
			PointTD* pPointTDZY1 = Rotate3D(*pPointTDZY, fP, fR, fW);

			PointDD* pPointDD1 = static_cast<PointDD*>(pPointTD1);
			pPointDD1->AddShift(fX, fY, fZ);
			PointDD* pPointDDXY1 = static_cast<PointDD*>(pPointTDXY1);
			pPointDDXY1->AddShift(fX, fY, fZ);
			PointDD* pPointDDXZ1 = static_cast<PointDD*>(pPointTDXZ1);
			pPointDDXZ1->AddShift(fX, fY, fZ);
			PointDD* pPointDDZY1 = static_cast<PointDD*>(pPointTDZY1);
			pPointDDZY1->AddShift(fX, fY, fZ);

			result.push_back(pPointDD1);
			result.push_back(pPointDDXY1);
			result.push_back(pPointDD1);
			result.push_back(pPointDDXZ1);
			result.push_back(pPointDD1);
			result.push_back(pPointDDZY1);
		}
	}
	if (Par.iProjStyle == PROJ_DOTS) {
		for (unsigned int i = 0; i < pObjectTD->pPointsTD.size(); i++) {
			PointTD* pPointTDXY = new PointTD(*pObjectTD->pPointsTD[i]);
			pPointTDXY->fZ = 0;
			PointTD* pPointTDXZ = new PointTD(*pObjectTD->pPointsTD[i]);
			pPointTDXZ->fY = 0;
			PointTD* pPointTDZY = new PointTD(*pObjectTD->pPointsTD[i]);
			pPointTDZY->fX = 0;

			PointTD* pPointTDXY1 = Rotate3D(*pPointTDXY, fP, fR, fW);
			PointTD* pPointTDXZ1 = Rotate3D(*pPointTDXZ, fP, fR, fW);
			PointTD* pPointTDZY1 = Rotate3D(*pPointTDZY, fP, fR, fW);

			PointDD* pPointDDXY1 = static_cast<PointDD*>(pPointTDXY1);
			pPointDDXY1->AddShift(fX, fY, fZ);
			PointDD* pPointDDXZ1 = static_cast<PointDD*>(pPointTDXZ1);
			pPointDDXZ1->AddShift(fX, fY, fZ);
			PointDD* pPointDDZY1 = static_cast<PointDD*>(pPointTDZY1);
			pPointDDZY1->AddShift(fX, fY, fZ);

			result.push_back(pPointDDXY1);
			result.push_back(pPointDDXZ1);
			result.push_back(pPointDDZY1);
		}
	}
	return result;
};

ObjectDD* ProjectionOrtoDD::ToObject() {
	ObjectDD* result = new ObjectDD();
	result->pPointsDD = this->pPointsDD;
	result->ObjectID = this->ObjectID;
	result->Par = this->Par;
	return result;
};

void ProjectionOrtoDD::Paint(DefCanvas* pCanvas, CameraTD* pCamera) {
}

PointTD ProjectionOrtoDD::Multiple(float mat[AXIS_COUNT][AXIS_COUNT],
	PointTD pPTD) {
	float X = mat[0][0] * pPTD.fX + mat[0][1] * pPTD.fY + mat[0][2] * pPTD.fZ;
	float Y = mat[1][0] * pPTD.fX + mat[1][1] * pPTD.fY + mat[1][2] * pPTD.fZ;
	float Z = mat[2][0] * pPTD.fX + mat[2][1] * pPTD.fY + mat[2][2] * pPTD.fZ;
	PointTD Result(X, Y, Z, pPTD.iAction, pPTD.iType, pPTD.sText);
	return Result;
}

PointTD* ProjectionOrtoDD::Rotate3D(PointTD pPointTD, float fPitch, float fRoll,
	float fYaw) {
	for (int i = AXIS_X; i < AXIS_COUNT; i++) {
		float matrix[AXIS_COUNT][AXIS_COUNT];
		switch (i) {
		case AXIS_X:
			matrix[0][0] = cos(fYaw);
			matrix[0][1] = sin(fYaw);
			matrix[0][2] = 0.0;
			matrix[1][0] = -sin(fYaw);
			matrix[1][1] = cos(fYaw);
			matrix[1][2] = 0.0;
			matrix[2][0] = 0.0;
			matrix[2][1] = 0.0;
			matrix[2][2] = 1.0;
			break;
		case AXIS_Y:
			matrix[0][0] = cos(fPitch);
			matrix[0][1] = 0.0;
			matrix[0][2] = -sin(fPitch);
			matrix[1][0] = 0.0;
			matrix[1][1] = 1.0;
			matrix[1][2] = 0.0;
			matrix[2][0] = sin(fPitch);
			matrix[2][1] = 0.0;
			matrix[2][2] = cos(fPitch);
			break;
		case AXIS_Z:
			matrix[0][0] = 1.0;
			matrix[0][1] = 0.0;
			matrix[0][2] = 0.0;
			matrix[1][0] = 0.0;
			matrix[1][1] = cos(fRoll);
			matrix[1][2] = sin(fRoll);
			matrix[2][0] = 0.0;
			matrix[2][1] = -sin(fRoll);
			matrix[2][2] = cos(fRoll);
			break;
		default:
			break;
		}
		pPointTD = Multiple(matrix, pPointTD);
	}
	return new PointTD(pPointTD);
}

float ProjectionOrtoDD::DegToRad(float fDeg) {
	float fRad = fDeg * Pi / 180.0;
	return tan(fRad);
};

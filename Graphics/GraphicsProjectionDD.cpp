// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: Projection from 3D Object to 2D Object by the OCamera
//
// =============================================================================

#include "GraphicsProjectionDD.h"

ProjectionDD::ProjectionDD(ObjectTD* pObjectTD, CameraTD* pCamera) {
	Par = pObjectTD->Par;
	ObjectID = pObjectTD->ObjectID;
	pPointsDD = Projection(pObjectTD, pCamera);
}

ProjectionDD::ProjectionDD(ObjectTD* pObjectTD, CameraDD* pCamera) {
	Par = pObjectTD->Par;
	ObjectID = pObjectTD->ObjectID;
	pPointsDD = Projection(pObjectTD, pCamera);
}

ProjectionDD::~ProjectionDD() {
	for (unsigned int i = 0; i < pPointsDD.size(); i++) {
		delete pPointsDD[i];
	}
	pPointsDD.clear();
};

std::vector<PointDD*>ProjectionDD::Projection(ObjectTD* pObjectTD,
	CameraTD* pCamera) {
	std::vector<PointDD*>result;
	for (unsigned int i = 0; i < pObjectTD->pPointsTD.size(); i++) {
		PointTD* pPointTD = Rotate3D(*pObjectTD->pPointsTD[i],
			DegToRad(pCamera->fPitch), DegToRad(pCamera->fRoll),
			DegToRad(pCamera->fYaw));
		PointDD* pPointDD = static_cast<PointDD*>(pPointTD);
		pPointDD->AddShift(pCamera->iXShift, pCamera->iYShift,
			pCamera->iZShift);
		result.push_back(pPointDD);
	}
	return result;
};

std::vector<PointDD*>ProjectionDD::Projection(ObjectTD* pObjectTD,
	CameraDD* pCamera) {
	std::vector<PointDD*>result;
	for (unsigned int i = 0; i < pObjectTD->pPointsTD.size(); i++) {
		if (this->Par.iProjStyle == PROJ_NONE) {
			PointTD* pPointTD = Rotate3D(*pObjectTD->pPointsTD[i]);
			PointDD* pPointDD = static_cast<PointDD*>(pPointTD);
			pPointDD->AddShift(pCamera->iXShift, pCamera->iYShift,
				pCamera->iZShift);
			result.push_back(pPointDD);
		}
		if (this->Par.iProjStyle == PROJ_LINES) {
			PointTD* pPointTDXZ = Rotate3D(*pObjectTD->pPointsTD[i], QXZ);
			PointTD* pPointTDXY = Rotate3D(*pObjectTD->pPointsTD[i], QXY);
			PointTD* pPointTDYY = Rotate3D(*pObjectTD->pPointsTD[i], QYY);
			PointTD* pPointTDYZ = Rotate3D(*pObjectTD->pPointsTD[i], QYZ);

			PointTD* pPointTDXZ1 = new PointTD(*pPointTDXZ);
			PointTD* pPointTDXY1 = new PointTD(*pPointTDXY);
			PointTD* pPointTDYY3 = new PointTD(*pPointTDYY);
			PointTD* pPointTDYZ1 = new PointTD(*pPointTDYZ);
			PointTD* pPointTDYZ3 = new PointTD(*pPointTDYZ);

			pPointTDXZ1->SetSettings(ACT_MOVE, TYPE_OBJECT, "");
			pPointTDXY1->SetSettings(ACT_DRAW, TYPE_OBJECT, "");
			pPointTDYY3->SetSettings(ACT_DRAW, TYPE_OBJECT, "");
			pPointTDYZ3->SetSettings(ACT_ARC, TYPE_OBJECT, "");
			pPointTDYZ1->SetSettings(ACT_DRAW, TYPE_OBJECT, "");

			PointTD* pPointTDXZ2 = new PointTD(*pPointTDXZ);
			PointTD* pPointTDXY2 = new PointTD(*pPointTDXY);
			PointTD* pPointTDYY2 = new PointTD(*pPointTDYY);
			PointTD* pPointTDYZ2 = new PointTD(*pPointTDYZ);

			PointDD* pPointDDXZ = static_cast<PointDD*>(pPointTDXZ);
			pPointDDXZ->AddShift(pCamera->iXShift, pCamera->iYShift,
				pCamera->iZShift);
			PointDD* pPointDDXY = static_cast<PointDD*>(pPointTDXY);
			pPointDDXY->AddShift(pCamera->iXShift, pCamera->iYShift,
				pCamera->iZShift);
			PointDD* pPointDDYZ = static_cast<PointDD*>(pPointTDYZ);
			pPointDDYZ->AddShift(pCamera->iXShift, pCamera->iYShift,
				pCamera->iZShift);

			PointDD* pPointDDXZ1 = static_cast<PointDD*>(pPointTDXZ1);
			pPointDDXZ1->AddShift(pCamera->iXShift, pCamera->iYShift,
				pCamera->iZShift);
			PointDD* pPointDDXZ2 = static_cast<PointDD*>(pPointTDXZ2);
			pPointDDXZ2->fY = 0;
			pPointDDXZ2->AddShift(pCamera->iXShift, pCamera->iYShift,
				pCamera->iZShift);

			PointDD* pPointDDXY1 = static_cast<PointDD*>(pPointTDXY1);
			pPointDDXY1->AddShift(pCamera->iXShift, pCamera->iYShift,
				pCamera->iZShift);
			PointDD* pPointDDXY2 = static_cast<PointDD*>(pPointTDXY2);
			pPointDDXY2->fX = 0;
			pPointDDXY2->AddShift(pCamera->iXShift, pCamera->iYShift,
				pCamera->iZShift);

			PointDD* pPointDDYY3 = static_cast<PointDD*>(pPointTDYY3);
			pPointDDYY3->fX = 0;
			pPointDDYY3->AddShift(pCamera->iXShift, pCamera->iYShift,
				pCamera->iZShift);
			PointDD* pPointDDYY2 = static_cast<PointDD*>(pPointTDYY2);
			pPointDDYY2->fY = 0;
			pPointDDYY2->AddShift(pCamera->iXShift, pCamera->iYShift,
				pCamera->iZShift);

			PointDD* pPointDDYZ1 = static_cast<PointDD*>(pPointTDYZ1);
			pPointDDYZ1->AddShift(pCamera->iXShift, pCamera->iYShift,
				pCamera->iZShift);
			PointDD* pPointDDYZ3 = static_cast<PointDD*>(pPointTDYZ3);
			pPointDDYZ3->fY = 0;
			pPointDDYZ3->AddShift(pCamera->iXShift, pCamera->iYShift,
				pCamera->iZShift);
			PointDD* pPointDDYZ2 = static_cast<PointDD*>(pPointTDYZ2);
			pPointDDYZ2->fX = 0;
			pPointDDYZ2->AddShift(pCamera->iXShift, pCamera->iYShift,
				pCamera->iZShift);

			result.push_back(pPointDDXZ1);
			result.push_back(pPointDDXY1);
			result.push_back(pPointDDYY3);
			result.push_back(pPointDDYZ3);
			result.push_back(pPointDDYZ1);
			result.push_back(pPointDDXZ1);
			result.push_back(pPointDDYZ1);

			result.push_back(pPointDDXZ);
			result.push_back(pPointDDXZ2);
			result.push_back(pPointDDXY);
			result.push_back(pPointDDXY2);
			result.push_back(pPointDDYY2);
			result.push_back(pPointDDYZ);
			result.push_back(pPointDDYZ2);
		}
		if (this->Par.iProjStyle == PROJ_DOTS) {
			PointTD* pPointTDXZ = Rotate3D(*pObjectTD->pPointsTD[i], QXZ);
			PointTD* pPointTDXY = Rotate3D(*pObjectTD->pPointsTD[i], QXY);
			PointTD* pPointTDYZ = Rotate3D(*pObjectTD->pPointsTD[i], QYZ);

			PointDD* pPointDDXZ = static_cast<PointDD*>(pPointTDXZ);
			pPointDDXZ->AddShift(pCamera->iXShift, pCamera->iYShift,
				pCamera->iZShift);
			PointDD* pPointDDXY = static_cast<PointDD*>(pPointTDXY);
			pPointDDXY->AddShift(pCamera->iXShift, pCamera->iYShift,
				pCamera->iZShift);
			PointDD* pPointDDYZ = static_cast<PointDD*>(pPointTDYZ);
			pPointDDYZ->AddShift(pCamera->iXShift, pCamera->iYShift,
				pCamera->iZShift);

			result.push_back(pPointDDXZ);
			result.push_back(pPointDDXY);
			result.push_back(pPointDDYZ);
		}
	}
	return result;
};

ObjectDD* ProjectionDD::ToObject() {
	ObjectDD* result = new ObjectDD();
	result->pPointsDD = this->pPointsDD;
	result->ObjectID = this->ObjectID;
	result->Par = this->Par;
	return result;
};

void ProjectionDD::Paint(DefCanvas* pCanvas, CameraTD* pCamera) {
}

void ProjectionDD::Paint(DefCanvas* pCanvas, CameraDD* pCamera) {
}

PointTD* ProjectionDD::Rotate3D(PointTD pPointTD) {
	PointTD Result(pPointTD.fX, pPointTD.fY, 0, pPointTD.iAction,
		pPointTD.iType, pPointTD.sText);
	return new PointTD(Result);
}

PointTD* ProjectionDD::Rotate3D(PointTD pPointTD, Quarter Quart) {
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
	PointTD Result(X, Y, 0, pPointTD.iAction, pPointTD.iType, pPointTD.sText);
	return new PointTD(Result);
}

PointTD ProjectionDD::Multiple(float mat[AXIS_COUNT][AXIS_COUNT], PointTD pPTD)
{
	float X = mat[0][0] * pPTD.fX + mat[0][1] * pPTD.fY + mat[0][2] * pPTD.fZ;
	float Y = mat[1][0] * pPTD.fX + mat[1][1] * pPTD.fY + mat[1][2] * pPTD.fZ;
	float Z = mat[2][0] * pPTD.fX + mat[2][1] * pPTD.fY + mat[2][2] * pPTD.fZ;
	PointTD Result(X, Y, Z, pPTD.iAction, pPTD.iType, pPTD.sText);
	return Result;
}

PointTD* ProjectionDD::Rotate3D(PointTD pPointTD, float fPitch, float fRoll,
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

float ProjectionDD::DegToRad(float fDeg) {
	float fRad = fDeg * Pi / 180.0;
	return tan(fRad);
};

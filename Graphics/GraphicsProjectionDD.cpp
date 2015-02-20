// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: Projection from 3D Object to 2D Object by the OCamera
//
// =============================================================================

#include "GraphicsProjectionDD.h"

ProjectionDD::ProjectionDD(ObjectTD* pObjectTD, OCamera* pCamera) {
	pPointsDD = Projection(pObjectTD, pCamera);
}

ProjectionDD::~ProjectionDD() {
	for (unsigned int i = 0; i < pPointsDD.size(); i++) {
		delete pPointsDD[i];
	}
	pPointsDD.clear();
};

std::vector<PointDD*>ProjectionDD::Projection(ObjectTD* pObjectTD,
	OCamera* pCamera) {
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

PointTD ProjectionDD::Multiple(float mat[AXIS_COUNT][AXIS_COUNT], PointTD pPTD)
{
	float X = mat[0][0] * pPTD.fX + mat[0][1] * pPTD.fY + mat[0][2] * pPTD.fZ;
	float Y = mat[1][0] * pPTD.fX + mat[1][1] * pPTD.fY + mat[1][2] * pPTD.fZ;
	float Z = mat[2][0] * pPTD.fX + mat[2][1] * pPTD.fY + mat[2][2] * pPTD.fZ;
	PointTD Result(X, Y, Z, pPTD.iAction);
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

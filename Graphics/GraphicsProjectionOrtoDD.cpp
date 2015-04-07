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

PointTD*ProjectionOrtoDD::CreatePointTD(PointTD* pPointTD, Action ACT, bool iX,
	bool iY, bool iZ) {
	PointTD* result = new PointTD(*pPointTD);
	result->SetSettings(ACT, pPointTD->iType, pPointTD->sText);
	float X = (iX ? pPointTD->fX : 0);
	float Y = (iY ? pPointTD->fY : 0);
	float Z = (iZ ? pPointTD->fZ : 0);
	result->SetPos(X, Y, Z);
	return result;
}

std::vector<PointDD*>ProjectionOrtoDD::Projection(ObjectTD* pObjectTD,
	CameraTD* pCamera) {
	std::vector<PointDD*>result;
	float fX = pCamera->iXShift;
	float fY = pCamera->iYShift;
	float fZ = pCamera->iZShift;
	float fP = DegToRad(pCamera->fPitch);
	float fR = DegToRad(pCamera->fRoll);
	float fW = DegToRad(pCamera->fYaw);
	float fA = DegToRad(pCamera->fAngle);
	if (Par.iProjStyle == PROJ_NONE) {
		for (unsigned int i = 0; i < pObjectTD->pPointsTD.size(); i++) {
			PointTD* pPointTD = Rotate3D(*pObjectTD->pPointsTD[i], fP, fR,
				fW, fA);
			PointDD* pPointDD = static_cast<PointDD*>(pPointTD);
			result.push_back(pPointDD);
		}
	}
	if (Par.iProjStyle == PROJ_LINES) {
		for (unsigned int i = 0; i < pObjectTD->pPointsTD.size(); i++) {
			if (pObjectTD->pPointsTD[i]->iType != TYPE_TEXT) {
				PointTD* pPoint = pObjectTD->pPointsTD[i];

				PointTD* pPointTD = CreatePointTD(pPoint, ACT_MOVE, pPoint->fX,
					pPoint->fY, pPoint->fZ);
				PointTD* pPointTDXY = CreatePointTD(pPoint, ACT_DRAW, 1, 1, 0);
				PointTD* pPointTDXZ = CreatePointTD(pPoint, ACT_DRAW, 1, 0, 1);
				PointTD* pPointTDZY = CreatePointTD(pPoint, ACT_DRAW, 0, 1, 1);
				PointTD* pPointTDXYX = CreatePointTD(pPoint, ACT_DRAW, 0, 1, 0);
				PointTD* pPointTDXYY = CreatePointTD(pPoint, ACT_DRAW, 1, 0, 0);
				PointTD* pPointTDXZX = CreatePointTD(pPoint, ACT_DRAW, 0, 0, 1);
				PointTD* pPointTDXZZ = CreatePointTD(pPoint, ACT_DRAW, 1, 0, 0);
				PointTD* pPointTDZYZ = CreatePointTD(pPoint, ACT_DRAW, 0, 1, 0);
				PointTD* pPointTDZYY = CreatePointTD(pPoint, ACT_DRAW, 0, 0, 1);

				PointDD* pPointDD =
					static_cast<PointDD*>(Rotate3D(*pPointTD, fP, fR, fW, fA));
				PointDD* pPointDDXY =
					static_cast<PointDD*>(Rotate3D(*pPointTDXY, fP, fR,
					fW, fA));
				PointDD* pPointDDXZ =
					static_cast<PointDD*>(Rotate3D(*pPointTDXZ, fP, fR,
					fW, fA));
				PointDD* pPointDDZY =
					static_cast<PointDD*>(Rotate3D(*pPointTDZY, fP, fR,
					fW, fA));
				PointDD* pPointDDXYX =
					static_cast<PointDD*>(Rotate3D(*pPointTDXYX, fP, fR,
					fW, fA));
				PointDD* pPointDDXYY =
					static_cast<PointDD*>(Rotate3D(*pPointTDXYY, fP, fR,
					fW, fA));
				PointDD* pPointDDXZX =
					static_cast<PointDD*>(Rotate3D(*pPointTDXZX, fP, fR,
					fW, fA));
				PointDD* pPointDDXZZ =
					static_cast<PointDD*>(Rotate3D(*pPointTDXZZ, fP, fR,
					fW, fA));
				PointDD* pPointDDZYZ =
					static_cast<PointDD*>(Rotate3D(*pPointTDZYZ, fP, fR,
					fW, fA));
				PointDD* pPointDDZYY =
					static_cast<PointDD*>(Rotate3D(*pPointTDZYY, fP, fR,
					fW, fA));

				result.push_back(pPointDD);
				result.push_back(pPointDDXY);
				result.push_back(pPointDDXYX);
				result.push_back(pPointDDXY);
				result.push_back(pPointDDXYY);
				result.push_back(pPointDD);
				result.push_back(pPointDDXZ);
				result.push_back(pPointDDXZX);
				result.push_back(pPointDDXZ);
				result.push_back(pPointDDXZZ);
				result.push_back(pPointDD);
				result.push_back(pPointDDZY);
				result.push_back(pPointDDZYZ);
				result.push_back(pPointDDZY);
				result.push_back(pPointDDZYY);
			}
		}
	}
	if (Par.iProjStyle == PROJ_DOTS) {
		for (unsigned int i = 0; i < pObjectTD->pPointsTD.size(); i++) {
			PointTD* pPoint = pObjectTD->pPointsTD[i];

			PointTD* pPointTDXZ = CreatePointTD(pPoint, ACT_NONE, 1, 0, 1);
			PointTD* pPointTDXY = CreatePointTD(pPoint, ACT_NONE, 1, 1, 0);
			PointTD* pPointTDZY = CreatePointTD(pPoint, ACT_NONE, 0, 1, 1);

			PointTD* pPointTDX = CreatePointTD(pPoint, ACT_NONE, 1, 0, 0);
			PointTD* pPointTDY = CreatePointTD(pPoint, ACT_NONE, 0, 1, 0);
			PointTD* pPointTDZ = CreatePointTD(pPoint, ACT_NONE, 0, 0, 1);

			pPointTDXZ->sText += "3";
			pPointTDXY->sText += "1";
			pPointTDZY->sText += "2";

			pPointTDX->sText += "X";
			pPointTDY->sText += "Y";
			pPointTDZ->sText += "Z";

			PointDD* pPointDDXZ =
				static_cast<PointDD*>(Rotate3D(*pPointTDXZ, fP, fR, fW, fA));
			PointDD* pPointDDXY =
				static_cast<PointDD*>(Rotate3D(*pPointTDXY, fP, fR, fW, fA));
			PointDD* pPointDDZY =
				static_cast<PointDD*>(Rotate3D(*pPointTDZY, fP, fR, fW, fA));

			PointDD* pPointDDX =
				static_cast<PointDD*>(Rotate3D(*pPointTDX, fP, fR, fW, fA));
			PointDD* pPointDDY =
				static_cast<PointDD*>(Rotate3D(*pPointTDY, fP, fR, fW, fA));
			PointDD* pPointDDZ =
				static_cast<PointDD*>(Rotate3D(*pPointTDZ, fP, fR, fW, fA));

			result.push_back(pPointDDXZ);
			result.push_back(pPointDDXY);
			result.push_back(pPointDDZY);

			result.push_back(pPointDDX);
			result.push_back(pPointDDY);
			result.push_back(pPointDDZ);
		}
	}
	AddShift(result, fX, fY, fZ);
	return result;
};

void ProjectionOrtoDD::AddShift(std::vector<PointDD*>vectorDD, float iXShift,
	float iYShift, float iZShift) {
	for (unsigned int i = 0; i < vectorDD.size(); i++) {
		bool found = false;
		for (int j = i; j >= 0; j--) {
			if ((unsigned int)j != i && vectorDD[j] == vectorDD[i])
				found = true;
		}
		if (!found)
			vectorDD[i]->AddShift(iXShift, iYShift, iZShift);
	}
}

ObjectDD* ProjectionOrtoDD::ToObject() {
	ObjectDD* result = new ObjectDD();
	result->pPointsDD = this->pPointsDD;
	result->ObjectID = this->ObjectID;
	result->Par = this->Par;
	return result;
};

void ProjectionOrtoDD::Paint(DefCanvas* pCanvas, CameraTD* pCamera) {
}

PointTD ProjectionOrtoDD::Multiple(float mat[AXIS_COUNT + 1][AXIS_COUNT + 1],
	PointTD pPTD) {
	float X = mat[0][0] * pPTD.fX + mat[0][1] * pPTD.fY + mat[0][2] * pPTD.fZ;
	float Y = mat[1][0] * pPTD.fX + mat[1][1] * pPTD.fY + mat[1][2] * pPTD.fZ;
	float Z = mat[2][0] * pPTD.fX + mat[2][1] * pPTD.fY + mat[2][2] * pPTD.fZ +
		mat[2][3];
	PointTD Result(X, Y, Z, pPTD.iAction, pPTD.iType, pPTD.sText);
	return Result;
}

PointTD* ProjectionOrtoDD::Rotate3D(PointTD pPointTD, float fPitch, float fRoll,
	float fYaw, float fAngle) {
	for (int i = AXIS_X; i < AXIS_COUNT; i++) {
		float matrix[AXIS_COUNT + 1][AXIS_COUNT + 1];
		switch (i) {
		case AXIS_X:
			matrix[0][0] = cos(fYaw + fAngle);
			matrix[0][1] = sin(fYaw);
			matrix[0][2] = 0.0;
			matrix[1][0] = -sin(fYaw + fAngle);
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
			/* case AXIS_COUNT:
			 matrix[0][0] = 1.0;
			 matrix[0][1] = 0.0;
			 matrix[0][2] = 0.0;
			 matrix[1][0] = 0.0;
			 matrix[1][1] = 1.0;
			 matrix[1][2] = 0.0;
			 matrix[2][0] = 0.0;
			 matrix[2][1] = 0.0;
			 matrix[2][2] = 0.0;
			 matrix[2][3] = -1.0 / fAngle;
			 break; */
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

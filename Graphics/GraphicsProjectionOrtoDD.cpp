// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: Projection from 3D Object to 2D Object by the OCamera
//
// =============================================================================

#include "GraphicsProjectionOrtoDD.h"
#include "GraphicsCameraDD.h"
#include "GraphicsCameraTD.h"
#include "GraphicsObjectTD.h"
#include "GraphicsPointTD.h"
#include "GraphicsPointDD.h"

ProjectionOrtoDD::ProjectionOrtoDD(ObjectTD* pObjectTD, CameraTD* pCamera) {
	pObject = pObjectTD;
	Par = pObjectTD->Par;
	ObjectID = pObjectTD->ObjectID;
	ComputeAres(pCamera);
	pPointsDD = Projection(pObjectTD, pCamera);
}

ProjectionOrtoDD::~ProjectionOrtoDD() {
	for (unsigned int i = 0; i < pPointsDD.size(); i++) {
		delete pPointsDD[i];
	}
	pPointsDD.clear();
};

PointTD*ProjectionOrtoDD::CreatePointTD(PointTD* pPointTD, Action ACT, bool iX, bool iY, bool iZ) {
	PointTD* result = new PointTD(*pPointTD);
	result->SetSettings((ACT == ACT_NONE ? pPointTD->iAction : ACT), pPointTD->iType,
		pPointTD->sText);
	float X = (iX ? pPointTD->fX : 0);
	float Y = -1 * (iY ? pPointTD->fY : 0);
	float Z = (iZ ? pPointTD->fZ : 0);
	result->SetPos(X, Y, Z);
	return result;
}

std::vector<PointDD*>ProjectionOrtoDD::Projection(ObjectTD* pObjectTD, CameraTD* pCamera) {
	std::vector<PointDD*>result;
	float fX = pCamera->iXShift;
	float fY = pCamera->iYShift;
	float fZ = pCamera->iZShift;
	if (Par.iProjStyle == PROJ_NONE) {
		for (unsigned int i = 0; i < pObjectTD->pPointsTD.size(); i++) {
			PointTD* pPoint = pObjectTD->pPointsTD[i];
			// PointTD* pPointTD = Rotate3D(*pObjectTD->pPointsTD[i], fP, fR,
			// fW, fA);
			PointTD* pPointTD = CreatePointTD(pPoint, ACT_NONE, pPoint->fX, pPoint->fY, pPoint->fZ);
			// PointDD* pPointDD = static_cast<PointDD*>(pPointTD);
			PointDD* pPointDD = static_cast<PointDD*>(Rotate3D(*pPointTD, pCamera));
			result.push_back(pPointDD);
		}
	}
	if (Par.iProjStyle == PROJ_LINES || Par.iProjStyle == PROJ_LINES_NIGGA) {
		for (unsigned int i = 0; i < pObjectTD->pPointsTD.size(); i++) {
			if (pObjectTD->pPointsTD[i]->iType != TYPE_TEXT) {
				if ((Par.iProjStyle == PROJ_LINES && pObjectTD->pPointsTD[i]->fX >=
					0 && pObjectTD->pPointsTD[i]->fY >= 0 && pObjectTD->pPointsTD[i]->fZ >= 0) ||
					(Par.iProjStyle == PROJ_LINES_NIGGA && (pObjectTD->pPointsTD[i]->fX <=
					0 || pObjectTD->pPointsTD[i]->fY <= 0 || pObjectTD->pPointsTD[i]->fZ <= 0))) {

					PointTD* pPoint = pObjectTD->pPointsTD[i];

					PointTD* pPointTD = CreatePointTD(pPoint, ACT_MOVE, pPoint->fX, pPoint->fY,
						pPoint->fZ);
					PointTD* pPointTDXY = CreatePointTD(pPoint, ACT_DRAW, 1, 1, 0);
					PointTD* pPointTDXZ = CreatePointTD(pPoint, ACT_DRAW, 1, 0, 1);
					PointTD* pPointTDZY = CreatePointTD(pPoint, ACT_DRAW, 0, 1, 1);
					PointTD* pPointTDXYX = CreatePointTD(pPoint, ACT_DRAW, 0, 1, 0);
					PointTD* pPointTDXYY = CreatePointTD(pPoint, ACT_DRAW, 1, 0, 0);
					PointTD* pPointTDXZX = CreatePointTD(pPoint, ACT_DRAW, 0, 0, 1);
					PointTD* pPointTDXZZ = CreatePointTD(pPoint, ACT_DRAW, 1, 0, 0);
					PointTD* pPointTDZYZ = CreatePointTD(pPoint, ACT_DRAW, 0, 1, 0);
					PointTD* pPointTDZYY = CreatePointTD(pPoint, ACT_DRAW, 0, 0, 1);

					PointDD* pPointDD = static_cast<PointDD*>(Rotate3D(*pPointTD, pCamera));
					PointDD* pPointDDXY = static_cast<PointDD*>(Rotate3D(*pPointTDXY, pCamera));
					PointDD* pPointDDXZ = static_cast<PointDD*>(Rotate3D(*pPointTDXZ, pCamera));
					PointDD* pPointDDZY = static_cast<PointDD*>(Rotate3D(*pPointTDZY, pCamera));
					PointDD* pPointDDXYX = static_cast<PointDD*>(Rotate3D(*pPointTDXYX, pCamera));
					PointDD* pPointDDXYY = static_cast<PointDD*>(Rotate3D(*pPointTDXYY, pCamera));
					PointDD* pPointDDXZX = static_cast<PointDD*>(Rotate3D(*pPointTDXZX, pCamera));
					PointDD* pPointDDXZZ = static_cast<PointDD*>(Rotate3D(*pPointTDXZZ, pCamera));
					PointDD* pPointDDZYZ = static_cast<PointDD*>(Rotate3D(*pPointTDZYZ, pCamera));
					PointDD* pPointDDZYY = static_cast<PointDD*>(Rotate3D(*pPointTDZYY, pCamera));

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
	}
	if (Par.iProjStyle == PROJ_DOTS || Par.iProjStyle == PROJ_DOTS_NIGGA) {
		for (unsigned int i = 0; i < pObjectTD->pPointsTD.size(); i++) {
			if ((Par.iProjStyle == PROJ_DOTS && pObjectTD->pPointsTD[i]->fX >=
				0 && pObjectTD->pPointsTD[i]->fY >= 0 && pObjectTD->pPointsTD[i]->fZ >= 0) ||
				(Par.iProjStyle == PROJ_DOTS_NIGGA && (pObjectTD->pPointsTD[i]->fX <=
				0 || pObjectTD->pPointsTD[i]->fY <= 0 || pObjectTD->pPointsTD[i]->fZ <= 0))) {

				PointTD* pPoint = pObjectTD->pPointsTD[i];

				PointTD* pPointTDXZ = CreatePointTD(pPoint, ACT_NONE, 1, 0, 1);
				PointTD* pPointTDXY = CreatePointTD(pPoint, ACT_NONE, 1, 1, 0);
				PointTD* pPointTDZY = CreatePointTD(pPoint, ACT_NONE, 0, 1, 1);

				PointTD* pPointTDX = CreatePointTD(pPoint, ACT_NONE, 1, 0, 0);
				PointTD* pPointTDY = CreatePointTD(pPoint, ACT_NONE, 0, 1, 0);
				PointTD* pPointTDZ = CreatePointTD(pPoint, ACT_NONE, 0, 0, 1);

				pPointTDXZ->sText += "2";
				pPointTDXY->sText += "1";
				pPointTDZY->sText += "3";

				pPointTDX->sText += "X";
				pPointTDY->sText += "Y";
				pPointTDZ->sText += "Z";

				PointDD* pPointDDXZ = static_cast<PointDD*>(Rotate3D(*pPointTDXZ, pCamera));
				PointDD* pPointDDXY = static_cast<PointDD*>(Rotate3D(*pPointTDXY, pCamera));
				PointDD* pPointDDZY = static_cast<PointDD*>(Rotate3D(*pPointTDZY, pCamera));

				PointDD* pPointDDX = static_cast<PointDD*>(Rotate3D(*pPointTDX, pCamera));
				PointDD* pPointDDY = static_cast<PointDD*>(Rotate3D(*pPointTDY, pCamera));
				PointDD* pPointDDZ = static_cast<PointDD*>(Rotate3D(*pPointTDZ, pCamera));

				result.push_back(pPointDDXZ);
				result.push_back(pPointDDXY);
				result.push_back(pPointDDZY);

				result.push_back(pPointDDX);
				result.push_back(pPointDDY);
				result.push_back(pPointDDZ);
			}
		}
	}
	AddShift(result, fX, fY, fZ);
	return result;
};

void ProjectionOrtoDD::AddShift(std::vector<PointDD*>vectorDD, float iXShift, float iYShift,
	float iZShift) {
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

PointTD ProjectionOrtoDD::Multiple(float mat[AXIS_COUNT + 1][AXIS_COUNT + 1], PointTD pPTD) {
	float X = mat[0][0] * pPTD.fX + mat[0][1] * pPTD.fY + mat[0][2] * pPTD.fZ;
	float Y = mat[1][0] * pPTD.fX + mat[1][1] * pPTD.fY + mat[1][2] * pPTD.fZ;
	float Z = mat[2][0] * pPTD.fX + mat[2][1] * pPTD.fY + mat[2][2] * pPTD.fZ + mat[2][3];
	PointTD Result(X, Y, Z, pPTD.iAction, pPTD.iType, pPTD.sText);
	return Result;
}

PointTD* ProjectionOrtoDD::Rotate3D(PointTD pPointTD, CameraTD* pCamera) {
	double X[N] = {pPointTD.fX, pPointTD.fY, pPointTD.fZ, 1};
	double Xm[N] = {0, 0, 0, 1};
	Multiply(X, Ares, Xm);

	if (pCamera->iMode == CAM_CENTRAL) {
		Xm[0] = Xm[0] / (fabs(Xm[3]) + inac);
		Xm[1] = Xm[1] / (fabs(Xm[3]) + inac);
	}
	else {
		Xm[0] = Xm[0];
		Xm[1] = Xm[1];
	}
	double Tm[N] = {0, 0, 0, 1};
	if (ObjectID == "LabaPoint") {
		Tm[0] = Xm[0];
		Tm[1] = Xm[1];
	}
	if (c <= inac && pCamera->iMode == CAM_ORTO)
		return new PointTD(0, 0, 0, pPointTD.iAction, pPointTD.iType, pPointTD.sText);
	else if (c / 2.0 <= pCamera->TCheck[2] && pCamera->iMode == CAM_CENTRAL)
		return new PointTD(0, 0, 0, pPointTD.iAction, pPointTD.iType, pPointTD.sText);
	else
		return new PointTD(Xm[0], Xm[1], Xm[2], pPointTD.iAction, pPointTD.iType, pPointTD.sText);   
}

float ProjectionOrtoDD::DegToRad(float fDeg) {
	float fRad = fDeg * Pi / 180.0;
	return tan(fRad);
};

// ---------------------------------------------------------------------------
void ProjectionOrtoDD::Multiply(double Matrix1[][N], double Matrix2[][N], double Matrix3[][N]) {
	double Tmp = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++)
				Tmp += Matrix1[i][k] * Matrix2[k][j];
			Matrix3[i][j] = Tmp;
			Tmp = 0;
		}
}

// -------
void ProjectionOrtoDD::Multiply(double String1[N], double Matrix[][N], double String2[N]) {
	double Tmp = 0;
	for (int j = 0; j < N; j++) {
		for (int k = 0; k < N; k++)
			Tmp += String1[k] * Matrix[k][j];
		String2[j] = Tmp;
		Tmp = 0;
	}
}

// ---------------------------------------------------------------------------
void ProjectionOrtoDD::ComputeAres(CameraTD* pCamera) {
	// Косинусы и синусы углов поворота
	double cosT, cosP, sinT, sinP;
	// Матрицы элементараных преобразований
	double Rx[N][N];
	double Ry[N][N];
	double Rz[N][N];
	double RyRx[N][N];
	float C[N] = {pCamera->fPitch, pCamera->fRoll, pCamera->fYaw, 1};

	sinT = C[0] / sqrt(C[0] * C[0] + C[2] * C[2] + 0.001);
	sinP = C[1] / sqrt(C[0] * C[0] + C[1] * C[1] + C[2] * C[2] + inac);
	cosT = sqrt(1 - sinT * sinT);
	cosP = sqrt(1 - sinP * sinP);

	Ry[0][0] = cosT;
	Ry[0][1] = 0;
	Ry[0][2] = sinT;
	Ry[0][3] = 0;
	Ry[1][0] = -sinT;
	Ry[1][1] = 0;
	Ry[1][2] = cosT;
	Ry[1][3] = 0;
	Ry[2][0] = 0;
	Ry[2][1] = 1;
	Ry[2][2] = 0;
	Ry[2][3] = 0;
	Ry[3][0] = 0;
	Ry[3][1] = 0;
	Ry[3][2] = 0;
	Ry[3][3] = 1;

	Rx[0][0] = 0;
	Rx[0][1] = cosP;
	Rx[0][2] = sinP;
	Rx[0][3] = 0;
	Rx[1][0] = 0;
	Rx[1][1] = -sinP;
	Rx[1][2] = cosP;
	Rx[1][3] = 0;
	Rx[2][0] = 1;
	Rx[2][1] = 0;
	Rx[2][2] = 0;
	Rx[2][3] = 0;
	Rx[3][0] = 0;
	Rx[3][1] = 0;
	Rx[3][2] = 0;
	Rx[3][3] = 1;
	c = sqrt(C[0] * C[0] + C[1] * C[1] + C[2] * C[2]);
	double Acentre[N][N] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, -1}, {0, 0, 0, 1}};
	Acentre[2][3] = -1 / (c + inac);

	double A[N][N] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};

	Multiply(Ry, Rx, RyRx);
	if (ObjectID == "LabaPoint") {
		double T[N] = {
			pObject->pPointsTD[0]->fX, pObject->pPointsTD[0]->fY, pObject->pPointsTD[0]->fZ, 1};
		Multiply(T, RyRx, pCamera->TCheck);
	}

	if (pCamera->iMode == CAM_CENTRAL) {
		Multiply(RyRx, Acentre, Ares);
	}
	else {
		Multiply(RyRx, A, Ares);
	}
}

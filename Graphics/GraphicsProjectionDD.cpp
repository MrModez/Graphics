#include "GraphicsProjectionDD.h"

ProjectionDD::ProjectionDD(ObjectTD* pObjectTD, OCamera* pCamera) {
	pPointsDD = Projection(pObjectTD, pCamera);
}

std::vector<PointDD*>ProjectionDD::Projection(ObjectTD* pObjectTD,
	OCamera* pCamera) {
	ObjectDD* result = new ObjectDD();
	for (int i = 0; i < pObjectTD->pPointsTD.size(); i++) {

		PointTD oPointTD(*pObjectTD->pPointsTD[i]);
		oPointTD = Rotate3D(oPointTD, DegToRad(pCamera->fPitch),
			DegToRad(pCamera->fRoll), DegToRad(pCamera->fYaw));

		PointDD* pPointDD = new PointDD();
		pPointDD->x = pCamera->iZShift * oPointTD.x + pCamera->iXShift;
		pPointDD->y = pCamera->iZShift * oPointTD.y + pCamera->iYShift;
		pPointDD->action = oPointTD.action;

		result->AddPoint(pPointDD);
	}
	return result->pPointsDD;
};

PointTD ProjectionDD::Multiple(float m[AXIS_COUNT][AXIS_COUNT], PointTD m2) {
	float X = m[0][0] * m2.x + m[0][1] * m2.y + m[0][2] * m2.z;
	float Y = m[1][0] * m2.x + m[1][1] * m2.y + m[1][2] * m2.z;
	float Z = m[2][0] * m2.x + m[2][1] * m2.y + m[2][2] * m2.z;
	PointTD Result(X, Y, Z, m2.action);
	return Result;
}

PointTD ProjectionDD::Rotate3D(PointTD oPointTD, float fPitch, float fRoll,
	float fYaw) {
	PointTD result = oPointTD;
	for (int i = AXIS_X; i < AXIS_COUNT; i++) {
		float matrix[AXIS_COUNT][AXIS_COUNT];
		switch (i) {
		case AXIS_Z:
			matrix[0][0] = 1.0;
			matrix[0][1] = 0;
			matrix[0][2] = 0;
			matrix[1][0] = 0;
			matrix[1][1] = cos(fPitch);
			matrix[1][2] = sin(fPitch);
			matrix[2][0] = 0;
			matrix[2][1] = -sin(fPitch);
			matrix[2][2] = cos(fPitch);
			break;
		case AXIS_Y:
			matrix[0][0] = cos(fRoll);
			matrix[0][1] = 0;
			matrix[0][2] = -sin(fRoll);
			matrix[1][0] = 0;
			matrix[1][1] = 1.0;
			matrix[1][2] = 0;
			matrix[2][0] = sin(fRoll);
			matrix[2][1] = 0;
			matrix[2][2] = cos(fRoll);
			break;
		case AXIS_X:
			matrix[0][0] = cos(fYaw);
			matrix[0][1] = sin(fYaw);
			matrix[0][2] = 0;
			matrix[1][0] = -sin(fYaw);
			matrix[1][1] = cos(fYaw);
			matrix[1][2] = 0;
			matrix[2][0] = 0;
			matrix[2][1] = 0;
			matrix[2][2] = 1.0;
			break;
		default:
			break;
		}
		result = Multiple(matrix, result);
	}
	return result;
}

float ProjectionDD::DegToRad(float in) {
	float a = in * Pi / 180.0;
	return tan(a);
};

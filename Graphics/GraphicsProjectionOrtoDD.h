// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: Projection from 3D Object to 2D Object by the OCamera
//
// =============================================================================

#ifndef GRAPCHICS_PROJECTIONORTODD_H_
#define GRAPCHICS_PROJECTIONORTODD_H_

#include "GraphicsShared.h"
#include "GraphicsObjectDD.h"

class ObjectTD;
class PointTD;
class PointDD;

class ProjectionOrtoDD : public ObjectDD {
public:
	ProjectionOrtoDD(ObjectTD* pObjectTD, CameraTD* pCamera);
	virtual ~ProjectionOrtoDD();

	virtual void Paint(DefCanvas* pCanvas, CameraTD* pCamera);
	PointTD*CreatePointTD(PointTD* pPointTD, Action ACT, bool iX, bool iY, bool iZ);
	std::vector<PointDD*>Projection(ObjectTD* pObjectTD, CameraTD* pCamera);
	PointTD Multiple(float m[AXIS_COUNT + 1][AXIS_COUNT + 1], PointTD m2);
	PointTD* Rotate3D(PointTD pPointTD, CameraTD* pCamera);
	ObjectDD* ToObject();
	void AddShift(std::vector<PointDD*>vectorDD, float iXShift, float iYShift, float iZShift);
	float DegToRad(float in);

	static float matrix[AXIS_COUNT][AXIS_COUNT];

	ObjectTD *pObject;
	// Косинусы и синусы углов поворота
	double cosT, cosP, sinT, sinP;
	// Матрицы элементараных преобразований
	double Rx[N][N];
	double Ry[N][N];
	double RyRx[N][N];
	// double Acentre[N][N];
	// Результирующая матрица
	double Ares[N][N];
	double c;

	void ProjectionOrtoDD::Multiply(double Matrix1[][N], double Matrix2[][N], double Matrix3[][N]);
	void ProjectionOrtoDD::Multiply(double String1[N], double Matrix[][N], double String2[N]);
	void ProjectionOrtoDD::ComputeAres(CameraTD* pCamera);

	// std::vector<PointDD*>pPointsDD;
};

#endif //GRAPCHICS_PROJECTIONORTODD_H_

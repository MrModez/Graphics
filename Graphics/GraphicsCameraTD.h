// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: Main Camera
//
// =============================================================================

#ifndef GRAPCHICS_CAMERATD_H_
#define GRAPCHICS_CAMERATD_H_

#include "GraphicsShared.h"
#include "GraphicsCameraDD.h"

class CameraTD : public CameraDD {
public:
	CameraTD();
	CameraTD(int xshift, int yshift, int zshift, float pitch, float roll,
		float yaw);

	void SetRotation(float pitch, float roll, float yaw);
	void SetPosition(int xshift, int yshift, int zshift);

	float fPitch;
	float fRoll;
	float fYaw;
};

#endif //GRAPCHICS_CAMERATD_H_

// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: Main Camera
//
// =============================================================================

#ifndef GRAPCHICS_CAMERA_H_
#define GRAPCHICS_CAMERA_H_

#include "GraphicsShared.h"

class OCamera {
public:
	OCamera(int xshift, int yshift, int zshift, float pitch, float roll,
		float yaw);

	void SetRotation(float pitch, float roll, float yaw);

	float fPitch;
	float fRoll;
	float fYaw;
	int iXShift;
	int iYShift;
	int iZShift;
};

#endif //GRAPCHICS_CAMERA_H_

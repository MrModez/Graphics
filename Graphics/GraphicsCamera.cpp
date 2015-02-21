// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: Main Camera
//
// =============================================================================

#include "GraphicsCamera.h"

OCamera::OCamera(int xshift, int yshift, int zshift, float pitch, float roll,
	float yaw) {
	fPitch = pitch;
	fRoll = roll;
	fYaw = yaw;
	iXShift = xshift;
	iYShift = yshift;
	iZShift = zshift;
}

void OCamera::SetRotation(float pitch, float roll, float yaw) {
	fPitch = pitch;
	fRoll = roll;
	fYaw = yaw;
}

void OCamera::SetPosition(int xshift, int yshift, int zshift) {
	iXShift = xshift;
	iYShift = yshift;
	iZShift = zshift;
}

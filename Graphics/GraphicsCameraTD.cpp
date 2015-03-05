// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: Main 3D Camera
//
// =============================================================================

#include "GraphicsCameraTD.h"

CameraTD::CameraTD() {
	fPitch = 0.0;
	fRoll = 0.0;
	fYaw = 0.0;
	iXShift = 0;
	iYShift = 0;
	iZShift = 0;
}

CameraTD::CameraTD(int xshift, int yshift, int zshift, float pitch, float roll,
	float yaw) {
	fPitch = pitch;
	fRoll = roll;
	fYaw = yaw;
	iXShift = xshift;
	iYShift = yshift;
	iZShift = zshift;
}

void CameraTD::SetRotation(float pitch, float roll, float yaw) {
	fPitch = pitch;
	fRoll = roll;
	fYaw = yaw;
}

void CameraTD::SetPosition(int xshift, int yshift, int zshift) {
	iXShift = xshift;
	iYShift = yshift;
	iZShift = zshift;
}

void CameraTD::SetAngle(int fangle) {
	fAngle = fangle;
}

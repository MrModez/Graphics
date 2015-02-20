#ifndef GraphicsCamera
#define GraphicsCamera

#include "GraphicsShared.h"

class OCamera {
public:
	OCamera(int xshift, int yshift, int zshift, float pitch, float roll,
		float yaw) {
		fPitch = pitch;
		fRoll = roll;
		fYaw = yaw;
		iXShift = xshift;
		iYShift = yshift;
		iZShift = zshift;
	}

	void SetRotation(float pitch, float roll, float yaw) {
		fPitch = pitch;
		fRoll = roll;
		fYaw = yaw;
	}

	float fPitch, fRoll, fYaw;
	int iXShift, iYShift, iZShift;
};

#endif

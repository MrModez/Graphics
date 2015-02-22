// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: Main 2D Camera
//
// =============================================================================

#include "GraphicsCameraDD.h"

CameraDD::CameraDD() {
	iXShift = 0;
	iYShift = 0;
	iZShift = 0;
}

CameraDD::CameraDD(int xshift, int yshift, int zshift) {
	iXShift = xshift;
	iYShift = yshift;
	iZShift = zshift;
}

void CameraDD::SetPosition(int xshift, int yshift, int zshift) {
	iXShift = xshift;
	iYShift = yshift;
	iZShift = zshift;
}

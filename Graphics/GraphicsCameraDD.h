// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: Main Camera
//
// =============================================================================

#ifndef GRAPCHICS_CAMERADD_H_
#define GRAPCHICS_CAMERADD_H_

#include "GraphicsShared.h"

class CameraDD {
public:
	CameraDD();
	CameraDD(int xshift, int yshift, int zshift);

	virtual void SetPosition(int xshift, int yshift, int zshift);

	int iXShift;
	int iYShift;
	int iZShift;
};

#endif //GRAPCHICS_CAMERADD_H_

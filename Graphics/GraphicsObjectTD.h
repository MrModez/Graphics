#ifndef GraphicsObjectTD
#define GraphicsObjectTD

#include "GraphicsShared.h"
#include "GraphicsPointTD.h"
#include "GraphicsCamera.h"

class ObjectTD : ObjectShared {
public:
	ObjectTD(std::vector<PointTD*>Object);
	ObjectTD();
	~ObjectTD();

	virtual void Paint(TDirect2DCanvas* pCanvas, OCamera* pCamera);
	void AddPoint(PointTD * Point);

	std::vector<PointTD*>pPointsTD;
};

#endif

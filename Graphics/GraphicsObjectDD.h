#ifndef GraphicsObjectDD
#define GraphicsObjectDD

#include "GraphicsShared.h"
#include "GraphicsObjectTD.h"
#include "GraphicsPointDD.h"

class ObjectDD : ObjectShared {
public:
	ObjectDD(std::vector<PointDD*>Object);
	ObjectDD();

	virtual void Paint(TDirect2DCanvas* pCanvas, OCamera* pCamera);
	void AddPoint(PointDD * Point);

	std::vector<PointDD*>pPointsDD;
};

#endif

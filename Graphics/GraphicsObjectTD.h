#ifndef GraphicsObjectTD
#define GraphicsObjectTD

#include "GraphicsShared.h"
#include "GraphicsPointTD.h"

class ObjectTD {
public:
	ObjectTD(std::vector<PointTD*>Object) {
		pPointsTD = Object;
	}

	ObjectTD() {
	}

	~ObjectTD() {
		// for (int i = pPointsTD.; i < 10; i++) {
		// }
	}

	void AddPoint(PointTD * Point) {
		pPointsTD.push_back(Point);
	}

	std::vector<PointTD*>pPointsTD;
};

#endif

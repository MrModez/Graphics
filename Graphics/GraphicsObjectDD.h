#ifndef GraphicsObjectDD
#define GraphicsObjectDD

#include "GraphicsShared.h"
#include "GraphicsObjectTD.h"
#include "GraphicsPointDD.h"

class ObjectDD {
public:
	ObjectDD(std::vector<PointDD*>Object) {
		pPointsDD = Object;
	}

	ObjectDD() {
	}

	void AddPoint(PointDD * Point) {
		pPointsDD.push_back(Point);
	}

	std::vector<PointDD*>pPointsDD;
};

#endif

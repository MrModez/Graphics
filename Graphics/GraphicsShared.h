#ifndef GraphicsShared
#define GraphicsShared

#include <vector>
#include <Direct2D.hpp>
#define Pi 3.1415926536

enum Action {
	none, move, draw
};

enum Axis {
	AxisX, AxisY, AxisZ, AxisCount
};

class OCamera;

class GraphicsBase {
public:
	GraphicsBase() {

	}
};

class ObjectShared {
public:
	ObjectShared() {

	}

	virtual void Paint(TDirect2DCanvas* pCanvas, OCamera* pCamera) {
		return;
	}

	virtual void qwe() {
	}
};

#endif

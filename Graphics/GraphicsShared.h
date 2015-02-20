#ifndef GraphicsShared
#define GraphicsShared

#include <vector>
#include <Direct2D.hpp>
#define Pi 3.1415926536

enum Action {
	ACT_NONE, ACT_MOVE, ACT_DRAW
};

enum Axis {
	AXIS_X, AXIS_Y, AXIS_Z, AXIS_COUNT
};

enum Dim {
	DIM_DD, DIM_TD
};

enum Type {
	TYPE_OBJECT, TYPE_POINT, TYPE_TEXT
};

class OCamera;

class ObjectShared {
public:
	ObjectShared() {

	}

	virtual void Paint(TCanvas* pCanvas, OCamera* pCamera) {
		return;
	}

	virtual void qwe() {
	}

};

#endif

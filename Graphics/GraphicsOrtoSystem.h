#ifndef GraphicsOrtoSystem
#define GraphicsOrtoSystem

#include "GraphicsShared.h"
#include "GraphicsCamera.h"
#include "GraphicsProjectionDD.h"
// Ortogonal System

#include "GraphicsObjectTD.h"

class OrtoSystem {
public:
	OrtoSystem() {
	};

	OrtoSystem(OCamera* Camera);
	~OrtoSystem();

	void Paint(TDirect2DCanvas* pCanvas);
	void AddObject(ObjectTD * pObject);

	OCamera* pCamera;

	std::vector<ObjectTD*>pObjectsTD;
};

#endif

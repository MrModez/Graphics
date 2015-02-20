#ifndef GraphicsShared
#define GraphicsShared

#include <vector>
#include <Direct2D.hpp>
#define Pi 3.1415926536


enum Action
{
	none, move, draw
};

enum Axis
{
	AxisX, AxisY, AxisZ, AxisCount
};

class GraphicsBase
{
public:
	GraphicsBase()
	{

	}
};

#endif

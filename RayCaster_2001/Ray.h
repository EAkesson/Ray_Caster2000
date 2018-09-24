#pragma once
#include "Definitions.h"
class Ray
{
public:

	Vertex start;
	Vertex end;

	ColorDbl currentColor = ColorDbl(0,0,0);
	float currentDistance = 2000;

	Ray();
	Ray(Vertex s, Vertex e);
	~Ray();
};


#pragma once
#include "Definitions.h"
class Ray
{
public:

	Vertex start;
	Vertex end;

	ColorDbl currentColor = ColorDbl(0,0,0);
	float currentDistance = MAXILON;
	Vertex *intersectionPoint = nullptr;

	Ray *parent = nullptr;
	Ray *reflectedRay = nullptr;
	Ray *refractedRay = nullptr;

	Ray();
	Ray(Vertex s, Vertex e);
	~Ray();
};


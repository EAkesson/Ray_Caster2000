#pragma once
#include "Definitions.h"
#include "Triangle.h"
class Ray
{
public:

	Vertex start;
	Vertex end;

	ColorDbl currentColor = ColorDbl(0,0,0);
	float currentDistance = MAXILON;
	Vertex intersectionPoint;

	Ray *parent = nullptr;
	Ray *reflectedRay = nullptr;
	Ray *refractedRay = nullptr;
	Triangle *intersectedTriangle = nullptr;

	ColorDbl surfaceCollision();

	Ray();
	Ray(Vertex s, Vertex e);
	~Ray();
};


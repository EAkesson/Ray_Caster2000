#pragma once
#include "Triangle.h"
#include "Definitions.h"

class SceneObjects
{
public:

	Triangle *triangles;


	ColorDbl rayIntersection(Ray *r);
	 SceneObjects();
	~SceneObjects();
};


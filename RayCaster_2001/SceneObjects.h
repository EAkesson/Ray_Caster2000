#pragma once
#include "Triangle.h"
#include "Definitions.h"

class SceneObjects
{
public:

	Triangle *triangles;


	void rayIntersection(Ray *r);
	 SceneObjects();
	~SceneObjects();
};


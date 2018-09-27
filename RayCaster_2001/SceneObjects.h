#pragma once
#include "Triangle.h"
#include "Definitions.h"
#include "MaterialProperties.h"

class SceneObjects
{
public:

	Triangle *triangles;
	int numOftriangels;
	MaterialProperties matProp; 

	void rayIntersection(Ray *r);
	 SceneObjects();
	~SceneObjects();
};


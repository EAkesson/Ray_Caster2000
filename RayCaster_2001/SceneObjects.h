#pragma once
#include "Triangle.h"
#include "Definitions.h"
#include "MaterialProperties.h"
class Ray;
class Triangle;

class SceneObjects
{
public:

	Triangle *triangles;
	int numOfTriangles;
	MaterialProperties matProp;

	virtual void rayIntersection(Ray *r);
	 SceneObjects();
	~SceneObjects();
};


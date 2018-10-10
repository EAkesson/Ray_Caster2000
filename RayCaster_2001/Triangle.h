#pragma once
#include "Definitions.h"
#include "SceneObjects.h"
#include "Ray.h"
class Ray;
class SceneObjects;

class Triangle
{
public:
	Vertex verticies[3];	
	Direction normal;
	SceneObjects *parent;

	bool rayIntersection(Ray *r);

	Triangle();
	Triangle(Vertex &v1, Vertex &v2, Vertex &v3, SceneObjects *sO);
	~Triangle();
};


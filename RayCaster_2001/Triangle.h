#pragma once
#include "Definitions.h"
#include "Ray.h"
#include "SceneObjects.h"

class Triangle
{
public:
	Vertex verticies[3];
	ColorDbl triangleColor;
	Direction normal;
	SceneObjects *parent;

	bool rayIntersection(Ray *r);

	Triangle();
	Triangle(Vertex &v1, Vertex &v2, Vertex &v3, ColorDbl &paint, SceneObjects* sO);
	~Triangle();
};


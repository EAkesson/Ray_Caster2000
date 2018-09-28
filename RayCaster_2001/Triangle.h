#pragma once
#include "Definitions.h"
//#include "SceneObjects.h"
#include "MaterialProperties.h"
#include "Ray.h"

class Ray; //Forward dec 

class Triangle
{
public:
	Vertex verticies[3];
	ColorDbl triangleColor;
	Direction normal;
	//SceneObjects *parent;
	MaterialProperties *parentProp;

	bool rayIntersection(Ray *r);

	Triangle();
	Triangle(Vertex &v1, Vertex &v2, Vertex &v3, ColorDbl &paint, MaterialProperties* sO);
	~Triangle();
};


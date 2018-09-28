#pragma once
#include "Triangle.h"
#include "Definitions.h"
#include "MaterialProperties.h"


class Ray; //FWD decl
class Triangle; //FWD decl

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


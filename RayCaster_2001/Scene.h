#pragma once
#include "Definitions.h"
#include "Triangle.h"
#include "Ray.h"
#include "SceneObjects.h"
class Scene
{
public:
	Triangle *sceneMesh[24];
	Tetrahedron *objects;

	ColorDbl triangleScan(Ray *r);

	void buildScene();
	Scene();
	~Scene();
};


#pragma once
#include "Definitions.h"
#include "Triangle.h"
#include "Ray.h"
#include "SceneObjects.h"
#include "Tetrahedron.h"
class Scene
{
public:

	Triangle *sceneMesh[24];
	Tetrahedron *objects;

	void triangleScan(Ray *r);

	void buildScene();
	Scene();
	~Scene();
};


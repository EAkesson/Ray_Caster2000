#pragma once
#include "Definitions.h"
#include "Triangle.h"
#include "Ray.h"
#include "SceneObjects.h"
#include "Tetrahedron.h"
#include "Enviroment.h"

class Scene
{
public:

	//Triangle *sceneMesh[24];
	SceneObjects *objects[2];

	void triangleScan(Ray *r);

	void buildScene();
	Scene();
	~Scene();
};


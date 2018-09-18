#pragma once
#include "Definitions.h"
#include "Triangle.h"
#include "Ray.h"
class Scene
{
public:
	Triangle *sceneMesh[24];

	ColorDbl triangleScan(Ray &r);

	void buildScene();
	Scene();
	~Scene();
};


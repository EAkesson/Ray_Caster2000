#pragma once
#include "Definitions.h"
#include "Ray.h"
#include "SceneObjects.h"
class SceneObjects;
class Ray;

class Scene
{
public:

	//Triangle *sceneMesh[24];
	SceneObjects *objects[10];

	void triangleScan(Ray *r); //TODO rename

	void buildScene();
	Scene();
	~Scene();
};


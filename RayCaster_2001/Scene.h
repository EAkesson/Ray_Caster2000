#pragma once
#include "Definitions.h"
#include "Ray.h"
#include "SceneObjects.h"
class SceneObjects;
class Ray;

class Scene
{
public:

	const int numberOfObjects = 11;
	//Triangle *sceneMesh[24];
	SceneObjects *objects[11];

	void triangleScan(Ray *r); //TODO rename

	void buildScene();
	Scene();
	~Scene();
};


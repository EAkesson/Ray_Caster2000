#pragma once
#include "Definitions.h"
#include "SceneObjects.h"
#include "Tetrahedron.h"
#include "Enviroment.h"

class Ray;  //FWD decl
class SceneObjects;

class Scene
{
public:

	//Triangle *sceneMesh[24];
	SceneObjects *objects[2];

	void triangleScan(Ray *r); //TODO rename

	void buildScene();
	Scene();
	~Scene();
};


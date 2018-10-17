#pragma once
#include "Definitions.h"
#include "SceneObjects.h"
class Sphere : public SceneObjects
{
public:
	
	float radius;
	Vertex center;
	Triangle *sphereFake = nullptr;
	Sphere(float radius, Vertex center, ColorDbl clo);
	~Sphere();
	void rayIntersection(Ray * r);

	glm::vec3 getNormal(Vertex center);

	/*For Icosahedron*/
	/*
	int currentIndex;
	void subdivide(Vertex v1, Vertex v2, Vertex v3, long depth);
	void drawTriangle(Vertex  v1, Vertex v2, Vertex  v3);
	*/
};


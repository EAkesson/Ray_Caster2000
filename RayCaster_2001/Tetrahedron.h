#pragma once
#include "Triangle.h"
#include "Definitions.h"
#include "SceneObjects.h"

class Tetrahedron 
{
public:
 
	Triangle triangles[4];

	Tetrahedron();
	Tetrahedron(Vertex &v1, Vertex &v2, Vertex &v3, Vertex &v4,ColorDbl &d );
	~Tetrahedron();
};


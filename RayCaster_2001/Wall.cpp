#include "Wall.h"



Wall::Wall()
{
}

Wall::Wall(Vertex &v1, Vertex &v2, Vertex &v3, Vertex &v4, ColorDbl &d) {
	numOfTriangles = 2;
	triangles = new Triangle[numOfTriangles];
	matProp.reflectivity = 0.2;
	matProp.opacity = 1;
	matProp.color = d;

	triangles[0] = Triangle(v1, v2, v3, this);
	triangles[1] = Triangle(v1, v3, v4, this);
}

Wall::~Wall()
{
}

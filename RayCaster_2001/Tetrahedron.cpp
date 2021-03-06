#include "Tetrahedron.h"



Tetrahedron::Tetrahedron()
{
}

Tetrahedron::Tetrahedron(Vertex &v1, Vertex &v2, Vertex &v3, Vertex &v4, ColorDbl &d)
{
	numOfTriangles = 4;
	triangles = new Triangle[numOfTriangles];
	matProp.opacity = 1;
	matProp.reflectivity = 0.6;
	matProp.color = d;

	triangles[0] = Triangle(v1, v3, v4, this);
	triangles[1] = Triangle(v1, v2, v3, this);
	triangles[2] = Triangle(v1, v4, v2, this);
	triangles[3] = Triangle(v2, v4, v3, this);


}


Tetrahedron::~Tetrahedron()
{
}

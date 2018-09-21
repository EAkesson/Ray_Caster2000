#include "Tetrahedron.h"



Tetrahedron::Tetrahedron()
{
}

Tetrahedron::Tetrahedron(Vertex v1, Vertex v2, Vertex v3, Vertex v4, ColorDbl d)
{
	vertecies[0] = v1;
	vertecies[1] = v2;
	vertecies[2] = v3;
	vertecies[3] = v4;

	triangles[0] = Triangle(v1, v3, v4, d);
	triangles[1] = Triangle(v1, v2, v3, d);
	triangles[2] = Triangle(v1, v4, v2, d);
	triangles[3] = Triangle(v2, v3, v4, d);

}


Tetrahedron::~Tetrahedron()
{
}

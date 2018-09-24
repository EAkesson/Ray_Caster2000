#include "Tetrahedron.h"



Tetrahedron::Tetrahedron()
{
}

Tetrahedron::Tetrahedron(Vertex &v1, Vertex &v2, Vertex &v3, Vertex &v4, ColorDbl &d)
{
	std::cout << v1.x;

	triangles[0] = Triangle(v1, v3, v4, d);
	triangles[1] = Triangle(v1, v2, v3, d);
	triangles[2] = Triangle(v1, v4, v2, d);
	triangles[3] = Triangle(v2, v3, v4, d);


}


Tetrahedron::~Tetrahedron()
{
}

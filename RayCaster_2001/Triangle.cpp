#include "Triangle.h"



Triangle::Triangle()
{
}

Triangle::Triangle(Vertex & v1, Vertex & v2, Vertex & v3, ColorDbl &paint)
{
	verticies[0] = v1;
	verticies[1] = v2;
	verticies[2] = v3;
	triangleColor = paint;
}


Triangle::~Triangle()
{
}

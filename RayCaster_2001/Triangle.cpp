#include "Triangle.h"



bool Triangle::rayIntersection(Ray * r)
{
	glm::fvec3 T = r->start - verticies[0];
	glm::fvec3 E1 = verticies[1] - verticies[0];
	glm::fvec3 E2 = verticies[2] - verticies[0];
	glm::fvec3 D = r->end - r->start;
	glm::fvec3 P = glm::cross(D, E2);
	glm::fvec3 Q = glm::cross(T, E1);

	float xIntersection = glm::dot(Q, E2) / glm::dot(P, E1);

	std::cout << "xIntersection: " << xIntersection << std::endl;
	if (xIntersection > 0) 
	{
		return true;
	}

	return false;
}

Triangle::Triangle()
{

}

Triangle::Triangle(Vertex & v1, Vertex & v2, Vertex & v3, ColorDbl &paint)
{
	verticies[0] = v1;
	verticies[1] = v2;
	verticies[2] = v3;
	triangleColor = paint;
	//TODO: Make Normal by vector multiplication
}


Triangle::~Triangle()
{

}

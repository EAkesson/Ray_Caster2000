#include "Triangle.h"



bool Triangle::rayIntersection(Ray * r)
{
	//glm::fvec3 T = r->start - verticies[0];
	//glm::fvec3 E1 = verticies[1] - verticies[0];
	//glm::fvec3 E2 = verticies[2] - verticies[0];
	//glm::fvec3 D = r->end - r->start;
	//glm::fvec3 P = glm::cross(D, E2);
	//glm::fvec3 Q = glm::cross(T, E1);

	////float xIntersection = glm::dot(Q, E2) / glm::dot(P, E1);
	//float xIntersection = glm::dot(E1, P);

	//std::cout << "xIntersection: " << xIntersection << std::endl;
	//if (xIntersection > 0) 
	//{
	//	return true;
	//}

	
	/*Vector3D vertex0 = inTriangle->vertex0;
	Vector3D vertex1 = inTriangle->vertex1;
	Vector3D vertex2 = inTriangle->vertex2;*/
	glm::fvec3 rayVector, edge1, edge2, h, s, q;
	float a, f, u, v;
	rayVector = r->end - r->start;
	edge1 = verticies[1] - verticies[0];
	edge2 = verticies[2] - verticies[0];

	h = glm::cross(rayVector, edge2);
	a = glm::dot(edge1, h);
	if (a > -EPSILON && a < EPSILON) 
	{
		//std::cout << "a too small: " << std::endl;
		return false;
	}
		

	f = 1 / a;
	s = r->start - verticies[0];
	u = f * (glm::dot(s, h));
	//std::cout << "f: " << f << "| a: " << a << "| s.x: " << verticies[0].x << "| s.y: " << verticies[0].y << "| s.z: " << verticies[0].z << "" << std::endl;
	if (u < 0.0 || u > 1.0)
	{
		//std::cout << "u too small: " << u << std::endl;
		return false;
	}

	q = glm::cross(s, edge1);
	v = f * glm::dot(rayVector, q);
	if (v < 0.0 || u + v > 1.0)
	{
		//std::cout << "v and u+v too small: " << std::endl;
		return false;
	}

	// At this stage we can compute t to find out where the intersection point is on the line.
	float t = f * glm::dot(edge2, q);
	if (t > EPSILON) // ray intersection
	{
		//std::cout << "BIG BOY" << std::endl;
		//outIntersectionPoint = rayOrigin + rayVector * t;
		return true;
	}
	else // This means that there is a line intersection but not a ray intersection.
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

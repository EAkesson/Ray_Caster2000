#include "Ray.h"

ColorDbl Ray::surfaceCollision()
{
	
	glm::fvec4 Z = glm::fvec4(intersectedTriangle->normal,0);
	glm::fvec4 I= intersectionPoint - start; //ray from camera to point
	glm::fvec4 Iort = I - (glm::dot(I, Z))*Z;

	glm::fvec4 X = Iort / Iort.length;
	glm::fvec4 Y = glm::fvec4(glm::cross(glm::fvec3(-X), glm::fvec3(Z)), 0);
	
	Vertex modIntersectionPoint = -glm::fvec4(intersectionPoint.x, intersectionPoint.y, intersectionPoint.z, -1);
	

	glm::mat4x4  M = glm::mat4(X, Y, Z, glm::fvec4(0,0,0,1)) * glm::mat4(glm::fvec4(1, 0, 0, 0), glm::fvec4(0, 1, 0, 0), glm::fvec4(0, 0, 1, 0), modIntersectionPoint);

	glm::fvec3 Ri = glm::normalize(-I);
	glm::fvec3 N = glm::normalize(Z);
	Vertex reflected =Vertex( Ri - 2.0f * N *(glm::dot(Ri, N)), 0);

	reflectedRay = new Ray(intersectionPoint, reflected);

	//cloor = reflectedRay->surfaceCollision()*importanw + refractedRay->surfaceCollision * inpofpsofjsoepifj + shadowray*DDD;
	return //color;

}

Ray::Ray()
{
}

Ray::Ray(Vertex s, Vertex e)
{
	start = s;
	end = e;
}

Ray::~Ray()
{
}

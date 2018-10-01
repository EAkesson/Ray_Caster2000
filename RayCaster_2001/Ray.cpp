#include "Ray.h"

ColorDbl Ray::surfaceCollision(Scene *scene)
{
	scene->triangleScan(this);
	//std::cout << "??????????????? " << intersectedTriangle->parent->matProp.reflectivity << std::endl;
	if (intersectedTriangle->parent->matProp.reflectivity == 1) {
		glm::fvec4 Z = glm::fvec4(intersectedTriangle->normal, 0);
		glm::fvec4 I = intersectionPoint - start; //ray from camera to point
		glm::fvec4 Iort = I - (glm::dot(I, Z))*Z;
		glm::fvec4 X = Iort / glm::length(Iort);
		glm::fvec4 Y = glm::fvec4(glm::cross(glm::fvec3(-X), glm::fvec3(Z)), 0);

		Vertex modIntersectionPoint = -glm::fvec4(intersectionPoint.x, intersectionPoint.y, intersectionPoint.z, -1);


		glm::mat4x4  M = glm::mat4(X, Y, Z, glm::fvec4(0, 0, 0, 1)) * glm::mat4(glm::fvec4(1, 0, 0, 0), glm::fvec4(0, 1, 0, 0), glm::fvec4(0, 0, 1, 0), modIntersectionPoint);

		glm::fvec3 Ri = glm::normalize(-I);
		glm::fvec3 N = glm::normalize(Z);
		Vertex reflected = Vertex(Ri - 2.0f * N *(glm::dot(Ri, N)), 0);
		//std::cout << "The t-rex is standing behind you || " << start.x << "," << start.y << "," << start.z << std::endl;
		reflectedRay = new Ray(intersectionPoint, reflected);

		//cloor = reflectedRay->surfaceCollision()*importanw + refractedRay->surfaceCollision * inpofpsofjsoepifj + shadowray*DDD;
		//return //color;
		return reflectedRay->surfaceCollision(scene);
	}
	else 
	{
		//std::cout << "DE DE DE DE DE DE ED DE EDD DE ED È?D Eopfksepifjoeijfioj" << std::endl;
		return this->currentColor;
	}
	

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

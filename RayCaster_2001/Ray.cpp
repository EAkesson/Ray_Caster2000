#include "Ray.h"

ColorDbl Ray::surfaceCollision(Scene *scene, int num)
{

	scene->triangleScan(this);

	if (intersectedTriangle->parent->matProp.isLightSource)
	{
		std::cout << "Lightsource is active";
		return this->currentColor;

	}else if (intersectedTriangle->parent->matProp.reflectivity == 1) 
	{
	
		glm::fvec3 N = glm::normalize(intersectedTriangle->normal);
		glm::fvec3 Ri = intersectionPoint - start;


		Vertex reflected = Vertex(Ri - 2.0f * N *(glm::dot(Ri, N)), 0);
		
		reflectedRay = new Ray(intersectionPoint, reflected);

		//std::cout << "The t-rex is standing behind you || " << start.x << "," << start.y << "," << start.z << std::endl;

		return reflectedRay->surfaceCollision(scene, num);
	}
	else if (intersectedTriangle->parent->matProp.reflectivity < 1)
	{
		
		glm::fvec4 Z = glm::fvec4(intersectedTriangle->normal, 0);
		glm::fvec4 I = intersectionPoint - start; //ray from camera to point
		glm::fvec4 Iort = I - (glm::dot(I, Z))*Z;
		glm::fvec4 X = Iort / glm::length(Iort);
		glm::fvec4 Y = glm::fvec4(glm::cross(glm::fvec3(-X), glm::fvec3(Z)), 0);

		Vertex modIntersectionPoint = -glm::fvec4(intersectionPoint.x, intersectionPoint.y, intersectionPoint.z, -1);

		glm::mat4x4  M = glm::mat4(X, Y, Z, glm::fvec4(0, 0, 0, 1)) * glm::mat4(glm::fvec4(1, 0, 0, 0), glm::fvec4(0, 1, 0, 0), glm::fvec4(0, 0, 1, 0), modIntersectionPoint);

		glm::fvec3 Ri = I;
		glm::fvec3 N = glm::normalize(Z);

		//shadowray
		Ray *shadowRay = new Ray(Vertex(5, 0, 5, 0) , intersectionPoint,0);

		scene->triangleScan(shadowRay);
		if (shadowRay->intersectedTriangle->parent->matProp.isLightSource)
		{
			double dt = glm::dot(glm::normalize(glm::vec3(shadowRay->end - shadowRay->start)), N);
			ColorDbl lightsource = shadowRay->intersectedTriangle->parent->
		}


		if (intersectedTriangle->parent->matProp.RussianRoulette())
		{

		}else
		{

		}
		
		return this->currentColor;
	}
	else 
	{
		std::cout << "else statement!";
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

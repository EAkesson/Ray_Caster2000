#include "Ray.h"

ColorDbl Ray::surfaceCollision(Scene *scene, int num)
{

	scene->triangleScan(this);
	//std::cout << "Color:" << intersectedTriangle->parent->matProp.color.r << "|" << intersectedTriangle->parent->matProp.color.g << "|" << intersectedTriangle->parent->matProp.color.b << std::endl;
	//std::cout << "The t-rex is standing behind you || " << this->importance << std::endl;
	
	if (intersectedTriangle->parent->matProp.isLightSource)
	{
		std::cout << "Lightsource is active";
		return intersectedTriangle->parent->matProp.color * importance;
	}

	//shadowray
	Ray *shadowRay = new Ray(this->intersectionPoint + glm::vec4((intersectedTriangle->normal*0.1f),0), Vertex(5.5, 0, 4.99, 0), 0);		//hardcoded middle of lightsource
	ColorDbl lightContribution = ColorDbl(glm::dvec3(0.0, 0.0, 0.0));				// Gets information from the shadowray later

	scene->triangleScan(shadowRay);
	if (shadowRay->intersectedTriangle != nullptr && shadowRay->intersectedTriangle->parent->matProp.isLightSource)
	{	
		glm::fvec3 N = glm::normalize(intersectedTriangle->normal);		//Dont need to norm...
		double dt = glm::dot(glm::normalize(glm::vec3(shadowRay->end - shadowRay->start)), N);
		
		lightContribution = shadowRay->intersectedTriangle->parent->matProp.color * dt * this->intersectedTriangle->parent->matProp.color;
	}

	currentColor = lightContribution;	


	if (intersectedTriangle->parent->matProp.reflectivity == 1) 
	{
		glm::fvec3 N = glm::normalize(intersectedTriangle->normal);
		glm::fvec3 Ri = intersectionPoint - start;


		Vertex reflected = Vertex(Ri - 2.0f * N *(glm::dot(Ri, N)), 0);
		
		reflectedRay = new Ray(intersectionPoint, reflected, importance);

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
		Ray *shadowRay = new Ray(this->intersectionPoint, Vertex(5, 0, 5, 0), 0);		//hardcoded middle of lightsource
		ColorDbl lightContribution = ColorDbl(glm::dvec3(0.4, 0.4, 0.4));				// Gets information from the shadowray later
		
		scene->triangleScan(shadowRay);
		if (shadowRay->intersectedTriangle != nullptr && shadowRay->intersectedTriangle->parent->matProp.isLightSource)
		{
			double dt = glm::dot(glm::normalize(glm::vec3(shadowRay->end - shadowRay->start)), N);
			lightContribution = shadowRay->intersectedTriangle->parent->matProp.color * dt * this->intersectedTriangle->parent->matProp.color;


		}		

		currentColor = lightContribution;		  // setting the new color at this particular point

		if (intersectedTriangle->parent->matProp.RussianRoulette())
		{
			float * newAngles = intersectedTriangle->parent->matProp.BRDF();

			double xLocal = cos(newAngles[0])*sin(newAngles[1]);  //assuming that r = 1
			double yLocal = sin(newAngles[0])*sin(newAngles[1]);
			double zLocal = cos(newAngles[1]);

			glm::fvec4 localCoords = glm::fvec4(xLocal, yLocal, zLocal,0);

			//calculate inverse transofrm matrix

			glm::mat4x4  MI = glm::inverse(M);

			glm::fvec4 globalCoords = MI * localCoords;

			Vertex forwardVertex = globalCoords;//Vertex(globalCoords.x*0.1, globalCoords.y*0.1, globalCoords.z*0.1,0);

			reflectedRay = new Ray(intersectionPoint, forwardVertex, importance*1.33*intersectedTriangle->parent->matProp.reflectivity); //injecting more importance since to compensate for RR (1/0.75)

			//intersectedTriangle->parent->matProp.color = lightContribution;		  // setting the new color at this particular point
			

			return currentColor + reflectedRay->surfaceCollision(scene, num)* this->importance;


		}else
		{
			return (currentColor * this->importance); // stack up importance from stack
		}
		
		
	}
	
	

}

Ray::Ray()
{
}

Ray::Ray(Vertex s, Vertex e, float in)
{
	start = s;
	end = e;
	importance = in;
}

Ray::~Ray()
{
}

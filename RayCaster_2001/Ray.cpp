#include "Ray.h"
#include <chrono>
#include <random>

Ray::Ray()
{
}

Ray::Ray(Vertex s, Vertex e, float in)
{
	start = s;
	end = e;
	importance = in;
}

ColorDbl Ray::surfaceCollision(Scene *scene, int num)
{	
	scene->triangleScan(this);
	//std::cout << "Color:" << intersectedTriangle->parent->matProp.color.r << "|" << intersectedTriangle->parent->matProp.color.g << "|" << intersectedTriangle->parent->matProp.color.b << " || " << intersectedTriangle->parent->matProp.isLightSource << std::endl;
	//std::cout << "The t-rex is standing behind you || " << this->importance << std::endl;

	if (intersectedTriangle == nullptr) { //If we dosent hit a triangle
		std::cout << "We missed a triangle" << std::endl;
		return ColorDbl(0, 0, 0);
	}
	if (intersectedTriangle->parent->matProp.isLightSource)
	{
		return intersectedTriangle->parent->matProp.color * importance;
	}
	if (intersectedTriangle->parent->matProp.reflectivity == 0) {
		return (currentColor); //???
	}
	ColorDbl directLight = this->checkDirectLightInPoint(scene);
	currentColor = directLight * this->intersectedTriangle->parent->matProp.color; //we need to take direct light times X marks the spot

	if (intersectedTriangle->parent->matProp.reflectivity == 1) 
	{		
		reflectedRay = this->createPerfectReflectedRay();
		if (num < 3) {
			//return (directLight + (reflectedRay->surfaceCollision(scene, num + 1)))/2.0;
			return (directLight/3.0 + (reflectedRay->surfaceCollision(scene, num + 1)));
		}
		else {
			std::cout << "it happend" << std::endl;
			return directLight;
		}
		
	}
	else if (intersectedTriangle->parent->matProp.reflectivity < 1)
	{
		if (intersectedTriangle->parent->matProp.RussianRoulette())
		{
			reflectedRay = this->createReflectedRay();			
			return currentColor*(1.0- intersectedTriangle->parent->matProp.reflectivity) + reflectedRay->surfaceCollision(scene, 0) * reflectedRay->importance;
		}else
		{
			return (currentColor); // stack up importance from stack
		}
	}
}

ColorDbl Ray::checkDirectLightInPoint(Scene *sc) {
	ColorDbl lightCont = ColorDbl((0, 0, 0));
	Vertex pointInLight = Vertex(5.5, 0, 4.99, 0);
	for (size_t i = 0; i < 3; i++)
	{
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::mt19937 generator(seed);  // mt19937 is a standard mersenne_twister_engine
		std::uniform_real_distribution<double> unif(4, 6);
		pointInLight.x = unif(generator);
		std::uniform_real_distribution<double> uniff(-1, 1);
		pointInLight.y = uniff(generator);
		//std::cout << pointInLight.x << "|" << pointInLight.y << "|" << pointInLight.z << std::endl;
		//get pointlight
		lightCont += shadowRay(sc, pointInLight);
	}
	
	return lightCont;
}

ColorDbl Ray::shadowRay(Scene *sc, Vertex pointInLight) {
	//shadowray
	Ray *shadowRay = new Ray(this->intersectionPoint + glm::vec4((intersectedTriangle->normal*0.1f), 0), pointInLight/*Vertex(5.5, 0, 4.99, 0)*/, 0);		//hardcoded middle of lightsource
	ColorDbl lightContribution = ColorDbl(glm::dvec3(0.0, 0.0, 0.0));				// Gets information from the shadowray later

	sc->triangleScan(shadowRay);
	if (shadowRay->intersectedTriangle != nullptr && shadowRay->intersectedTriangle->parent->matProp.isLightSource)
	{	
		
		glm::fvec3 N = intersectedTriangle->normal;		//Dont need to norm...
		double dt = glm::dot(glm::normalize(glm::vec3(shadowRay->end - shadowRay->start)), N);
		//std::cout << dt << std::endl;
		if (dt < 0) {
			dt = -1 * dt;
		}
			lightContribution = shadowRay->intersectedTriangle->parent->matProp.color * dt / 3.0;
	}

	//std::cout << shadowRay;
	delete shadowRay;
	/*std::cout << "Color: " << lightContribution.x << " | " << lightContribution.y << " | " << lightContribution.z << std::endl;*/
	
	return lightContribution;
}

Ray* Ray::createPerfectReflectedRay() {
	glm::fvec3 N = glm::normalize(intersectedTriangle->normal);
	glm::fvec3 Ri = intersectionPoint - start;
	Vertex reflected = Vertex(Ri - 2.0f * N *(glm::dot(Ri, N)), 0);	

	return  new Ray(intersectionPoint, reflected, importance);;
}

Ray* Ray::createReflectedRay() {
	float * newAngles = intersectedTriangle->parent->matProp.BRDF();
	double xLocal = cos(newAngles[0])*sin(newAngles[1]);  //assuming that r = 1
	double yLocal = sin(newAngles[0])*sin(newAngles[1]);
	double zLocal = cos(newAngles[1]);
	delete newAngles;									// garbage collection

	glm::fvec4 localCoords = glm::fvec4(xLocal, yLocal, zLocal, 0);
	glm::mat4x4  MI = getInverseTransformMatrix();
	glm::fvec4 globalCoords = MI * localCoords;
	Vertex forwardVertex = globalCoords;//Vertex(globalCoords.x*0.1, globalCoords.y*0.1, globalCoords.z*0.1,0);

	return new Ray(intersectionPoint + (globalCoords - intersectionPoint)*0.0001f, forwardVertex, this->importance*intersectedTriangle->parent->matProp.reflectivity*1.33); //injecting more importance since to compensate for RR (1/0.75)
}

glm::mat4x4 Ray::getInverseTransformMatrix() {
	return glm::inverse(getTransformMatrix()); //calculate inverse transofrm matrix
}

glm::mat4x4 Ray::getTransformMatrix() {
	glm::fvec4 Z = glm::fvec4(intersectedTriangle->normal, 0);
	glm::fvec4 I = intersectionPoint - start; //ray from camera to point
	glm::fvec4 Iort = I - (glm::dot(I, Z))*Z;
	glm::fvec4 X = glm::normalize(Iort);
	glm::fvec4 Y = glm::fvec4(glm::cross(glm::fvec3(-X), glm::fvec3(Z)), 0);
	Vertex modIntersectionPoint = glm::fvec4(-intersectionPoint.x, -intersectionPoint.y, -intersectionPoint.z, 1);
	glm::mat4x4  M = glm::mat4(X, Y, Z, glm::fvec4(0, 0, 0, 1)) * glm::mat4(glm::fvec4(1, 0, 0, 0), glm::fvec4(0, 1, 0, 0), glm::fvec4(0, 0, 1, 0), modIntersectionPoint);
	return M;
}

Ray::~Ray()
{	
	//std::cout << " | " << this << std::endl;
	delete reflectedRay;	
	delete refractedRay;
}

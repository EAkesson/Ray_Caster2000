#pragma once
#include "Definitions.h"
#include "Triangle.h"
#include "Scene.h"
class Scene;
class Triangle;

class Ray
{
public:

	Vertex start;
	Vertex end;

	ColorDbl currentColor = ColorDbl(0,0,0);
	float currentDistance = MAXILON;
	Vertex intersectionPoint;
	double importance;

	//Ray *parent = nullptr;
	Ray *reflectedRay = nullptr;
	Ray *refractedRay = nullptr;
	Triangle *intersectedTriangle = nullptr;

	Ray();
	Ray(Vertex s, Vertex e, float in);
	ColorDbl surfaceCollision(Scene *scene, int num);
	ColorDbl checkDirectLightInPoint(Scene * sc);
	ColorDbl shadowRay(Scene * sc, Vertex pointInLight);
	Ray * createPerfectReflectedRay();
	Ray* createReflectedRay();
	glm::mat4x4 getInverseTransformMatrix();

	glm::mat4x4 getTransformMatrix();
	~Ray();
};


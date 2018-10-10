#pragma once
#include "Definitions.h"
#include "SceneObjects.h"

class Light : public SceneObjects
{
public:
	Light();
	Light(Vertex &v1, Vertex &v2, Vertex &v3, Vertex &v4, ColorDbl &d, float watt);
	~Light();
};


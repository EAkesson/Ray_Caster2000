#pragma once
#include "Definitions.h"
#include "SceneObjects.h"

class light : public SceneObjects
{
public:
	light();
	light(Vertex &v1, Vertex &v2, Vertex &v3, Vertex &v4, ColorDbl &d, float &watt);
	~light();
};


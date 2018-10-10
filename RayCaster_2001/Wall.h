#pragma once

#include "Definitions.h"
#include "SceneObjects.h"

class Wall : public SceneObjects
{
public:
	Wall();
	Wall(Vertex &v1, Vertex &v2, Vertex &v3, Vertex &v4, ColorDbl &d);
	~Wall();
};


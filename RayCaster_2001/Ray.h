#pragma once
#include "Definitions.h"
class Ray
{
public:

	Vertex start;
	Vertex end;


	Ray();
	Ray(Vertex s, Vertex e);
	~Ray();
};


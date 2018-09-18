#pragma once
#include "Definitions.h"
#include "Ray.h"
class Pixel
{

public:
	ColorDbl pixelColor;
	Ray *intersector;
	
	Pixel();
	~Pixel();
};


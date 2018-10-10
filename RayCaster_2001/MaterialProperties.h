#pragma once
#include "Definitions.h"
class MaterialProperties
{
public:

	//ransparency, re ectivity, colour, 

	float opacity;
	float reflectivity;
	bool isLightSource = false;
	ColorDbl color;

	MaterialProperties(float opa, float rect);//, ColorDbl clor = ColorDbl(0,0,0), bool isLight = false);
	MaterialProperties();
	bool RussianRoulette();
	float * BRDF();
	~MaterialProperties();
};


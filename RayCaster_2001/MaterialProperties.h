#pragma once
#include "Definitions.h"
class MaterialProperties
{
public:

	//ransparency, re ectivity, colour, 

	float opacity;
	float reflectivity;
	bool isLightSource = false;
	

	MaterialProperties(float opa, float rect);
	MaterialProperties();
	bool RussianRoulette();
	float * BRDF();
	~MaterialProperties();
};


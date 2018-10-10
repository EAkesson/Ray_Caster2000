#pragma once
#include "Definitions.h"
class MaterialProperties
{
public:

	//ransparency, re ectivity, colour, 

	float opacity;
	float reflectivity;
	bool isLightSource;
	

	MaterialProperties(float opa, float rect);
	MaterialProperties();
	void RussianRoulette();
	~MaterialProperties();
};


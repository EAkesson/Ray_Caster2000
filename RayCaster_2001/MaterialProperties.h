#pragma once
#include "SceneObjects.h"
#include "Definitions.h"
class MaterialProperties
{
public:

	//ransparency, re ectivity, colour, 

	float opacity;
	float reflectivity;
	

	MaterialProperties(float opa, float rect);
	MaterialProperties();
	~MaterialProperties();
};


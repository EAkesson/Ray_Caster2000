#include "MaterialProperties.h"



MaterialProperties::MaterialProperties(float opa, float rect)
{
	//transparency = trans;
	opacity = 0; //TODO Hardcoded
	reflectivity = rect; 
}

MaterialProperties::MaterialProperties()
{
}


MaterialProperties::~MaterialProperties()
{
}

#include "MaterialProperties.h"



MaterialProperties::MaterialProperties(float opa, float rect)
{
	//transparency = trans;
	opacity = 0;
	reflectivity = rect; 
}


MaterialProperties::~MaterialProperties()
{
}

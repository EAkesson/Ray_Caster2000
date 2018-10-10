#include "MaterialProperties.h"
#include <stdlib.h>
#include <ctime>



MaterialProperties::MaterialProperties(float opa, float rect)
{
	//transparency = trans;
	opacity = 0; //TODO Hardcoded
	reflectivity = rect;

}
MaterialProperties::MaterialProperties()
{
}

bool MaterialProperties::RussianRoulette()
{
	srand(time(NULL)); // seed my random according to the time ( can be done better by using header <random>)
	
	float cutOffProb = 0.25;

	float draw = rand() / (RAND_MAX + 1.);

	if ((1 - draw) > cutOffProb)
	{
		return true;
	}
	
	return false;

}
 double * MaterialProperties::BRDF()
{
	srand(time(NULL)); // seed my random according to the time ( can be done better by using header <random>)
	double * angles = new double[2];
	angles[0] = (rand() / (RAND_MAX + 1.)) * 2 * M_PI; // generate a random number (0-1) and multiply by 2pi. ~azimuth
	angles[1] = (rand() / (RAND_MAX + 1.))*(M_PI / 2); //incline 

}

MaterialProperties::~MaterialProperties()
{
}

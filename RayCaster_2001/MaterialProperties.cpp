#include "MaterialProperties.h"
#include <stdlib.h>
#include <ctime>



MaterialProperties::MaterialProperties(float opa, float rect)
{
	//transparency = trans;
	opacity = 0; //TODO Hardcoded
	reflectivity = rect; 
	isLightSource = false;
}

MaterialProperties::MaterialProperties()
{
}

void MaterialProperties::RussianRoulette()
{
	srand(time(NULL)); // seed my random according to the time ( can be done better by using header <random>)
	
	float cutOffProb = 0.25;

	float draw = rand() / (RAND_MAX + 1.);

	if((1-draw) > cutOffProb)
		//reflect

	
	double azimut = (rand() / (RAND_MAX + 1.))*2*M_PI; // generate a random number (0-1) and multiply by 2pi.
	double incline = (rand() / (RAND_MAX + 1.))*(M_PI/2);


	

}


MaterialProperties::~MaterialProperties()
{
}

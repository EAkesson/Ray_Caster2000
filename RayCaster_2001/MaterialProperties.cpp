#include "MaterialProperties.h"
#include <stdlib.h>
#include <ctime>
#include <chrono>
#include <random>



MaterialProperties::MaterialProperties(float opa, float rect) //ColorDbl clor = ColorDbl(0, 0, 0), bool isLight = false
{
	//transparency = trans;
	opacity = 0; //TODO Hardcoded
	reflectivity = rect;
	/*color = clor;
	isLightSource = isLight;*/
}
MaterialProperties::MaterialProperties()
{
}

bool MaterialProperties::RussianRoulette()
{
	//srand(time(NULL)); // seed my random according to the time ( can be done better by using header <random>)
	
	float cutOffProb = 0.25;
	float draw;// = rand() / (RAND_MAX + 1);

	// obtain a seed from the system clock:
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed);  // mt19937 is a standard mersenne_twister_engine
	std::uniform_real_distribution<double> unif(0, 1);
	draw = unif(generator);

	//std::cout << "DRAW: " << draw << std::endl;
	if ( draw > cutOffProb)
	{
		return true;
	}
	
	return false;

}
 float * MaterialProperties::BRDF()
{
	 unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	 std::mt19937 generator(seed);  // mt19937 is a standard mersenne_twister_engine
	 
	float * angles = new float[2];
	std::uniform_real_distribution<double> unif(EPSILON, 2 * M_PI - EPSILON);
	angles[0] = unif(generator);
	std::uniform_real_distribution<double> unife(EPSILON, M_PI/2 - EPSILON);
	angles[1] = unife(generator);

	//std::cout << angles[0] << "|" << angles[1] << std::endl;
	return angles;
}

MaterialProperties::~MaterialProperties()
{
}

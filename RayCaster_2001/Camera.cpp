#include "Camera.h"
#include <fstream>
#include <chrono>
#include <random>




Camera::Camera()
{
	std::cout << "im here once" << std::endl;
	fieldImage = new Pixel[amountOfPixel];
}

void Camera::convertColorLinear(ColorDbl iMax)
{
	if (iMax.x == 0)
		iMax.x = EPSILON;
	if (iMax.y == 0)
		iMax.y = EPSILON;
	if (iMax.z == 0)
		iMax.z = EPSILON;

	std::cout << "im here once" << std::endl;

	std::ofstream img("awesomepic.ppm");
	img << "P3" << std::endl;
	img << imageSize << " " << imageSize << std::endl;
	img << "255" << std::endl;

	for (int i = 0; i < amountOfPixel; i++)
	{
			//fieldImage[i].pixelColor = ColorDbl(i^3 /(i+1), (i+i / 2 *( i+1)), (i / 3 * (i+1))); //Only to feed with fake pixel data
			
			ColorDbl temp;
			temp = fieldImage[i].pixelColor * (255.99 / iMax);
			//std::cout << iMax.x << "|" << iMax.y << "|" << iMax.z << std::endl;
			img << temp.x << " " << temp.y << " " << temp.z << std::endl;
	}

}

void Camera::convertColorExpo()
{
}

void Camera::createImage()
{
	ColorDbl iMax = { EPSILON,EPSILON,EPSILON };
	//find the maximum intensity
	for (int i = 0; i < amountOfPixel; i++)
	{
		//std::cout << glm::length(fieldImage[i].pixelColor) << " | " << glm::length(iMax) << std::endl;
		if (glm::length(fieldImage[i].pixelColor) > glm::length(iMax))
			iMax = fieldImage[i].pixelColor;
	}
	//iMax = ColorDbl(2, 2, 2);

	convertColorLinear(iMax);
}

void Camera::render(Scene scene)
{
	//float pixelSize = 0.0025;
	float pixelSize = 2/ (float)imageSize;
	float pixelMiddel = pixelSize / 2;
	float x = 0;
	float y = 1 - pixelMiddel;
	float z = 1 - pixelMiddel;
	Ray *tracer;


	for (int i = 0; i < amountOfPixel; i++)
	{
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::mt19937 generator(seed); 

		fieldImage[i].pixelColor = ColorDbl(0, 0, 0);

		ColorDbl cl = ColorDbl(0, 0, 0);

		if (superSampling)
		{
			ColorDbl sum = ColorDbl(0, 0, 0);							  //temporary array for mean value calca
			double _y, _z;

			for (int j = 0; j < sampelingRays; j++)
			{
				std::uniform_real_distribution<double> unif(-pixelMiddel, pixelMiddel);
				_y = unif(generator);
				_z = unif(generator);

				tracer = new Ray(eyePoint[activeEye], Vertex(x, y + _y, z + _z, 0), 1);

				sum += tracer->surfaceCollision(&scene, i);

				delete tracer; // garbage collection

			}
			cl = sum /sampelingRays;

		}
		else
		{

			tracer = new Ray(eyePoint[activeEye], Vertex(x, y, z, 0), 1);
	
			 cl = tracer->surfaceCollision(&scene, i);

			delete tracer; // garbage collection
		
		}

		

		 // implement mean
		fieldImage[i].pixelColor = cl;
	

		if ((i+1) % imageSize == 0 && i != 0)
		{
			y = 1 - pixelMiddel;
			z -= pixelSize;
		}
		else 
		{
			y -= pixelSize;
		}
	}
}


Camera::~Camera()
{
}

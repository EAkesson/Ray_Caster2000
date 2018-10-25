#include "Camera.h"
#include <fstream>
#include <chrono>
#include <random>
#include <string>



Camera::Camera()
{
	std::cout << "Init camera" << std::endl;
	fieldImage = new Pixel[amountOfPixel];
}

double Camera::findLargestRGB(Pixel *tempFieldImage) {

	double RGBmax = EPSILON;
	//find the maximum intensity
	for (int i = 0; i < amountOfPixel; i++)
	{
		if (tempFieldImage[i].pixelColor.r > RGBmax) {
			RGBmax = tempFieldImage[i].pixelColor.r;
		}
		if (tempFieldImage[i].pixelColor.g > RGBmax) {
			RGBmax = tempFieldImage[i].pixelColor.g;
		}
		if (tempFieldImage[i].pixelColor.b > RGBmax) {
			RGBmax = tempFieldImage[i].pixelColor.b;
		}

	}
	return RGBmax;
}

Pixel* Camera::convertColorExpo(Pixel *tempFieldImage) {
	Pixel *convertedFieldImage = new Pixel[amountOfPixel];

	for (size_t i = 0; i < amountOfPixel; i++)
	{
		convertedFieldImage[i].pixelColor = glm::sqrt(tempFieldImage[i].pixelColor);
	}

	return convertedFieldImage;
}

void Camera::createImage(int i, Pixel *tempFieldImage)
{
	std::cout << "Start to create image" << std::endl;

	if (useSquareColorCorr) {
		tempFieldImage = convertColorExpo(tempFieldImage);
	}

	double RGBmax = findLargestRGB(tempFieldImage);
	if (RGBmax == 0) {
		RGBmax = EPSILON;
	}	

	//std::cout << RGBmax << std::endl;
	//RGBmax = sqrt(2.0);
	
	std::ofstream img("awesomepic_" + std::to_string(i) + ".ppm");
	//std::cout << "hellu";
	img << "P3" << std::endl;
	img << imageSize << " " << imageSize << std::endl;
	img << "255" << std::endl;

	for (int i = 0; i < amountOfPixel; i++)
	{
		//fieldImage[i].pixelColor = ColorDbl(i^3 /(i+1), (i+i / 2 *( i+1)), (i / 3 * (i+1))); //Only to feed with fake pixel data

		ColorDbl temp;
		//temp = fieldImage[i].pixelColor * (255.99 / iMax);
		temp.r = tempFieldImage[i].pixelColor.r * (255.99 / RGBmax);
		temp.g = tempFieldImage[i].pixelColor.g * (255.99 / RGBmax);
		temp.b = tempFieldImage[i].pixelColor.b * (255.99 / RGBmax);
		//std::cout << iMax.x << "|" << iMax.y << "|" << iMax.z << std::endl;
		img << temp.r << " " << temp.g << " " << temp.b << std::endl;
	}
}

//void Camera::render(Scene scene)
//{
//	//float pixelSize = 0.0025;
//	float pixelSize = 2/ (float)imageSize;
//	float pixelMiddel = pixelSize / 2;
//	float x = 0;
//	float y = 1 - pixelMiddel;
//	float z = 1 - pixelMiddel;
//	Ray *tracer;
//
//
//	for (int i = 0; i < amountOfPixel; i++)
//	{
//		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//		std::mt19937 generator(seed); 
//
//		fieldImage[i].pixelColor = ColorDbl(0, 0, 0);
//
//		ColorDbl cl = ColorDbl(0, 0, 0);
//
//		if (superSampling)
//		{
//			ColorDbl sum = ColorDbl(0, 0, 0);							  //temporary array for mean value calca
//			double _y, _z;
//
//			for (int j = 0; j < sampelingRays; j++)
//			{
//				std::uniform_real_distribution<double> unif(-pixelMiddel, pixelMiddel);
//				_y = unif(generator);
//				_z = unif(generator);
//
//				tracer = new Ray(eyePoint[activeEye], Vertex(x, y + _y, z + _z, 0), 1);
//
//				sum += tracer->surfaceCollision(&scene, 0);
//
//				delete tracer; // garbage collection
//
//			}
//			cl = sum /sampelingRays;
//
//		}
//		else
//		{
//			tracer = new Ray(eyePoint[activeEye], Vertex(x, y, z, 0), 1);
//			cl = tracer->surfaceCollision(&scene, 0);
//			delete tracer; // garbage collection		
//		}		
//
//		 // implement mean
//		fieldImage[i].pixelColor = cl;
//	
//		if ((i+1) % imageSize == 0 && i != 0)
//		{
//			y = 1 - pixelMiddel;
//			z -= pixelSize;
//		}
//		else 
//		{
//			y -= pixelSize;
//		}
//	}
//}

void Camera::render(Scene scene)
{
	Pixel *tempFieldImage = new Pixel[amountOfPixel];
	//float pixelSize = 0.0025;
	float pixelSize = 2/ (float)imageSize;
	float pixelMiddel = pixelSize / 2;
	float x = 0;
	float y = 1 - pixelMiddel;
	float z = 1 - pixelMiddel;
	Ray *tracer;
	ColorDbl cl = ColorDbl(0, 0, 0);

	for (int i = 0; i < amountOfPixel; i++)
	{
		fieldImage[i].pixelColor = ColorDbl(0, 0, 0);
	}

	if (superSampling) 
	{
		double _y, _z;

		for (int j = 0; j < sampelingRays; j++)
		{
			unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
			std::mt19937 generator(seed);
			std::uniform_real_distribution<double> unif(-pixelMiddel, pixelMiddel);

			for (int i = 0; i < amountOfPixel; i++)
			{
				
				_y = unif(generator);
				_z = unif(generator);
				//std::cout << y << "|" << z << std::endl;
				tracer = new Ray(eyePoint[activeEye], Vertex(x, y + _y, z + _z, 0), 1);
				cl = tracer->surfaceCollision(&scene, 0);
				//std::cout << cl.r << "|" << cl.g << "|" << cl.b << std::endl;
				fieldImage[i].pixelColor += cl;
				delete tracer; // garbage collection

				if ((i + 1) % imageSize == 0 && i != 0)
				{
					y = 1 - pixelMiddel;
					z -= pixelSize;
				}
				else
				{
					y -= pixelSize;
				}
			}

			y = 1 - pixelMiddel;
			z = 1 - pixelMiddel;

			for (int i = 0; i < amountOfPixel; i++)
			{
				tempFieldImage[i].pixelColor = fieldImage[i].pixelColor / (1.0*(j + 1.0));
			}

			createImage(j + 1, tempFieldImage);
			
		}

			
	}
	else 
	{
		for (int i = 0; i < amountOfPixel; i++)
		{
			tracer = new Ray(eyePoint[activeEye], Vertex(x, y, z, 0), 1);
			cl = tracer->surfaceCollision(&scene, 0);
			delete tracer; // garbage collection
			fieldImage[i].pixelColor = cl;

			if ((i + 1) % imageSize == 0 && i != 0)
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
}


Camera::~Camera()
{
}

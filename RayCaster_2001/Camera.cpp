#include "Camera.h"
#include <fstream>


Camera::Camera()
{
}

void Camera::convertColorLinear(ColorDbl iMax)
{
	std::ofstream img("awesomepic.ppm");
	img << "P3" << std::endl;
	img << imageSize << " " << imageSize << std::endl;
	img << "255" << std::endl;

	for (int i = 0; i < imageSize; i++)
	{

		for (int j = 0; j < imageSize; j++)
		{
			//picture[i][j] = fieldImage[i][j].pixelColor * (255.99 / iMax);
			picture[i][j] = {i%255, j%255, i+j%255};
				
			img << picture[i][j].x << " " << picture[i][j].y << " " << picture[i][j].z << std::endl;
			std::cout << picture[i][j].x;
		}

	}

	system("open awesomepic.ppm");
}

void Camera::convertColorExpo()
{
}

void Camera::createImage()
{
	ColorDbl iMax = { 0,0,0 };
	//find the maximum intensity
	for (int i = 0; i < imageSize; i++)
	{

		for (int j = 0; j < imageSize; j++)
		{
			if (fieldImage[i][j].pixelColor.length > iMax.length)
				iMax = fieldImage[i][j].pixelColor;

		}

	}

	convertColorLinear(iMax);
}

void Camera::render()
{
}


Camera::~Camera()
{
}

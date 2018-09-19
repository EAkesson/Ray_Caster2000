#include "Camera.h"
#include <fstream>


Camera::Camera()
{
	std::cout << "im here once" << std::endl;
}

void Camera::convertColorLinear(ColorDbl iMax)
{

	std::cout << "im here once" << std::endl;

	std::ofstream img("awesomepic.ppm");
	img << "P3" << std::endl;
	img << imageSize << " " << imageSize << std::endl;
	img << "255" << std::endl;
	
	for (int i = 0; i < imageSize; i++)
	{
		

		for (int j = 0; j < imageSize; j++)
		{
			fieldImage[i][j].pixelColor = ColorDbl(j /(i+1), (j / 2 *( i+1)), (j / 3 * (i+1)));

			

			ColorDbl temp;
			temp = fieldImage[i][j].pixelColor * (255.99 / iMax);
			
				
			img << temp.x << " " << temp.y << " " << temp.z << std::endl;
			std::cout << temp.x;
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

// RayCaster_2001.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Camera.h"
#include <fstream>

int main()
{
;
glm::vec3 picture[255][255];

	std::ofstream img("awesomepic.ppm");
	img << "P3" << std::endl;
	img << 255 << " " << 255 << std::endl;
	img << "255" << std::endl;

	for (int i = 0; i < 255; i++)
	{

		for (int j = 0; j < 255; j++)
		{
			//picture[i][j] = fieldImage[i][j].pixelColor * (255.99 / iMax);
			picture[i][j] = { i % 255, j % 255, i + j % 255 };

			img << picture[i][j].x << " " << picture[i][j].y << " " << picture[i][j].z << std::endl;
			std::cout << picture[i][j].x;
		}

	}

	system("open awesomepic.ppm");
	
    return 0;
}


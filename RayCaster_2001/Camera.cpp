#include "Camera.h"



Camera::Camera()
{
}

void Camera::convertColorLinear()
{

}

void Camera::convertColorExpo()
{
}

void Camera::createImage()
{
	ColorDbl max = { 0,0,0 };
	//find the maximum intensity
	for (int i = 0; i < 800; i++)
	{

		for (int j = 0; j < 800; j++)
		{
			if (fieldImage[i][j].pixelColor.length > max)
				max = fieldImage[i][j].pixelColor;

		}

	}

}

void Camera::render()
{
}


Camera::~Camera()
{
}

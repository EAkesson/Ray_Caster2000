#include "Camera.h"
#include <fstream>



Camera::Camera()
{
	std::cout << "im here once" << std::endl;
	fieldImage = new Pixel[amountOfPixel];
}

void Camera::convertColorLinear(ColorDbl iMax)
{

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
				
			img << temp.x << " " << temp.y << " " << temp.z << std::endl;
	}

}

void Camera::convertColorExpo()
{
}

void Camera::createImage()
{
	ColorDbl iMax = { 0,0,0 };
	//find the maximum intensity
	for (int i = 0; i < amountOfPixel; i++)
	{
		if (fieldImage[i].pixelColor.length > iMax.length)
			iMax = fieldImage[i].pixelColor;
	}

	convertColorLinear(iMax);
}

void Camera::render(Scene scene)
{
	float pixelSize = 0.0025;
	float pixelMiddel = pixelSize / 2;
	float x = 0;
	float y = pixelMiddel;
	float z = pixelMiddel;
	Ray *tracer;


	for (int i = 0; i < amountOfPixel; i++)
	{
		tracer = new Ray(eyePoint[activeEye], Vertex(x, y, z, 0));
		fieldImage[i].intersector = tracer;
		ColorDbl cl = scene.triangleScan(tracer);
		fieldImage[i].pixelColor = cl;
		//DO stuff

		if (i % imageSize == 0 && i != 0)
		{
			y = pixelMiddel;
			z += pixelSize;
		}
		else 
		{
			y += pixelSize;
		}
	}
}


Camera::~Camera()
{
}

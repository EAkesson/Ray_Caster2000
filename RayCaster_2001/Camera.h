#pragma once
#include "Definitions.h"
#include "Pixel.h"
#include "Scene.h"
#include "Ray.h"

class Camera
{
public:

	const static int imageSize = 200;
	bool superSampling = true;
	const int sampelingRays = 4;
	bool useSquareColorCorr = true;

	const static int amountOfPixel = imageSize * imageSize;
	Vertex eyePoint[2] = { Vertex(-2.0f, 0.0f, 0.0f, 0.0f), Vertex(-1.0f, 0.0f, 0.0f, 0.0f) };
	Vertex cameraPlane[4] = { Vertex(0.0f, -1.0f, -1.0f, 0.0f), Vertex(0.0f, 1.0f, -1.0f, 0.0f),Vertex(0.0f, 1.0f, 0.0f, 1.0f), Vertex(0.0f, -1.0f, 1.0f, 0.0f) };

	int activeEye = 1; // activate eyePoint 0 by default

	Pixel *fieldImage;

	Camera();		
	double findLargestRGB();
	Pixel* convertColorExpo();	
	void createImage();
	void render(Scene scene);


	~Camera();
};


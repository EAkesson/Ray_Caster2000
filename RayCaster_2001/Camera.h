#pragma once
#include "Definitions.h"
#include "Pixel.h"
class Camera
{
public:
	const static int imageSize = 199;
	Vertex eyePoint[2] = { Vertex(-2.0f, 0.0f, 0.0f, 0.0f), Vertex(-1.0f, 0.0f, 0.0f, 0.0f) };
	Vertex cameraPlane[4] = { Vertex(0.0f, -1.0f, -1.0f, 0.0f), Vertex(0.0f, 1.0f, -1.0f, 0.0f),Vertex(0.0f, 1.0f, 0.0f, 1.0f), Vertex(0.0f, -1.0f, 1.0f, 0.0f) };
	
	int activeEye = 0; // activate eyePoint 0 by default

	Pixel fieldImage[imageSize][imageSize];

	//glm::vec3 picture[imageSize][imageSize];

	Camera();

	void convertColorLinear(ColorDbl iMax);
	void convertColorExpo();

	void createImage();
	void render();


	~Camera();
};


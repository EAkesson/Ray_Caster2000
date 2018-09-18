#pragma once
#include "Definitions.h"
#include "Pixel.h"
class Camera
{
public:
	Vertex eyePoint0;
	Vertex eyePoint1;
	int activeEye = 0; // activate eyePoint 0 by default

	Pixel fieldImage[800][800];

	Camera();

	void createImage();
	void render();


	~Camera();
};


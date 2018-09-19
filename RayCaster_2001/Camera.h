#pragma once
#include "Definitions.h"
#include "Pixel.h"
class Camera
{
public:
	Vertex eyePoint[2] = { Vertex(-2.0f, 0.0f, 0.0f, 0.0f), Vertex(-1.0f, 0.0f, 0.0f, 0.0f) };
	Vertex cameraPlane[4] = { Vertex(0.0f, -1.0f, -1.0f, 0.0f), Vertex(0.0f, 1.0f, -1.0f, 0.0f),Vertex(0.0f, 1.0f, 0.0f, 1.0f), Vertex(0.0f, -1.0f, 1.0f, 0.0f) };
	
	int activeEye = 0; // activate eyePoint 0 by default

	Pixel fieldImage[800][800];

	int picture[800][800];

	Camera();

	void convertColorLinear();
	void convertColorExpo();

	void createImage();
	void render();


	~Camera();
};


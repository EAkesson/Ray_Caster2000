// RayCaster_2001.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Camera.h"
#include <fstream>

int main()
{

	Camera cam = Camera();
	Scene scene = Scene();	
	cam.render(scene);
	//cam.createImage();
	//cam.convertColorLinear(ColorDbl(1,1,1));

	
	
    return 0;
}


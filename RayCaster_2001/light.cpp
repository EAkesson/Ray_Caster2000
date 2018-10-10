#include "Light.h"



Light::Light()
{
}

Light::Light(Vertex & v1, Vertex & v2, Vertex & v3, Vertex & v4, ColorDbl &d, float watt)
{
	
	numOfTriangles = 2;
	triangles = new Triangle[numOfTriangles];
	//matProp.opacity = 1;//?
	//matProp.reflectivity = 1;//?
	matProp.isLightSource = true;
	matProp.color = d;

	triangles[0] = Triangle(v1, v4, v2, this);
	triangles[1] = Triangle(v4, v3, v2, this);
	
   /*4---------3
     |         |
     |         |
     |         |
     1---------2*/
}


Light::~Light()
{
}

#include "light.h"



light::light()
{
}

light::light(Vertex & v1, Vertex & v2, Vertex & v3, Vertex & v4, ColorDbl & d, float & watt)
{
	
	numOfTriangles = 2;
	triangles = new Triangle[numOfTriangles];
	//matProp.opacity = 1;//?
	//matProp.reflectivity = 1;//?
	matProp.isLightSource = true;

	triangles[0] = Triangle(v1, v4, v2, d, this);
	triangles[1] = Triangle(v4, v3, v2, d, this);
	
}


light::~light()
{
}

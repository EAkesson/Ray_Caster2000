#include "PartyStructure.h"



PartyStructure::PartyStructure()
{
}

PartyStructure::PartyStructure(bool isRoof, ColorDbl &d)
{
	numOfTriangles = 6;
	triangles = new Triangle[numOfTriangles];
	matProp.reflectivity = 0.2;
	if (isRoof) {
		matProp.reflectivity = 0;
	}
	matProp.opacity = 1;
	matProp.color = d;

	if (isRoof) 
	{
		triangles[0] = Triangle(Vertex(0, -6, 5, 0), Vertex(0, 6, 5, 0), Vertex(-3, 0, 5, 0), this);
		triangles[1] = Triangle(Vertex(0, -6, 5, 0), Vertex(5, 0, 5, 0), Vertex(0, 6, 5, 0), this);
		triangles[2] = Triangle(Vertex(5, 0, 5, 0), Vertex(10, 6, 5, 0), Vertex(0, 6, 5, 0), this);
		triangles[3] = Triangle(Vertex(5, 0, 5, 0), Vertex(10, -6, 5, 0), Vertex(10, 6, 5, 0), this);
		triangles[4] = Triangle(Vertex(10, -6, 5, 0), Vertex(13, 0, 5, 0), Vertex(10, 6, 5, 0), this);
		triangles[5] = Triangle(Vertex(0, -6, 5, 0), Vertex(10, -6, 5, 0), Vertex(5, 0, 5, 0), this);
	}
	else 
	{
		triangles[0] = Triangle(Vertex(-3, 0, -5, 0), Vertex(0, 6, -5, 0), Vertex(0, -6, -5, 0), this);
		triangles[1] = Triangle(Vertex(0, 6, -5, 0), Vertex(5, 0, -5, 0), Vertex(0, -6, -5, 0), this);
		triangles[2] = Triangle(Vertex(0, 6, -5, 0), Vertex(10, 6, -5, 0), Vertex(5, 0, -5, 0), this);
		triangles[3] = Triangle(Vertex(10, 6, -5, 0), Vertex(10, -6, -5, 0), Vertex(5, 0, -5, 0), this);
		triangles[4] = Triangle(Vertex(10, 6, -5, 0), Vertex(13, 0, -5, 0), Vertex(10, -6, -5, 0), this);
		triangles[5] = Triangle(Vertex(5, 0, -5, 0), Vertex(10, -6, -5, 0), Vertex(0, -6, -5, 0), this);
	}
}

PartyStructure::~PartyStructure()
{
}

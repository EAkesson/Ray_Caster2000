#include "Enviroment.h"



Enviroment::Enviroment()
{
	triangles = new Triangle[24];
	numOftriangels = 24;
	matProp.opacity = 1;
	matProp.reflectivity = 0;

	//Bottom
	triangles[0] = Triangle(Vertex(-3, 0, -5, 0), Vertex(0, 6, -5, 0), Vertex(0, -6, -5, 0), ColorDbl(1, 1, 1), this);
	triangles[1] = Triangle(Vertex(0, 6, -5, 0), Vertex(5, 0, -5, 0), Vertex(0, -6, -5, 0), ColorDbl(1, 1, 1), this);
	triangles[2] = Triangle(Vertex(0, 6, -5, 0), Vertex(10, 6, -5, 0), Vertex(5, 0, -5, 0), ColorDbl(1, 1, 1), this);
	triangles[3] = Triangle(Vertex(10, 6, -5, 0), Vertex(10, -6, -5, 0), Vertex(5, 0, -5, 0), ColorDbl(1, 1, 1), this);
	triangles[4] = Triangle(Vertex(10, 6, -5, 0), Vertex(13, 0, -5, 0), Vertex(10, -6, -5, 0), ColorDbl(1, 1, 1), this);
	triangles[5] = Triangle(Vertex(5, 0, -5, 0), Vertex(10, -6, -5, 0), Vertex(0, -6, -5, 0), ColorDbl(1, 1, 1), this);

	//Top
	triangles[6] = Triangle(Vertex(0, -6, 5, 0), Vertex(0, 6, 5, 0), Vertex(-3, 0, 5, 0), ColorDbl(1, 1, 1), this);
	triangles[7] = Triangle(Vertex(0, -6, 5, 0), Vertex(5, 0, 5, 0), Vertex(0, 6, 5, 0), ColorDbl(1, 1, 1), this);
	triangles[8] = Triangle(Vertex(5, 0, 5, 0), Vertex(10, 6, 5, 0), Vertex(0, 6, 5, 0), ColorDbl(1, 1, 1), this);
	triangles[9] = Triangle(Vertex(5, 0, 5, 0), Vertex(10, -6, 5, 0), Vertex(10, 6, 5, 0), ColorDbl(1, 1, 1), this);
	triangles[10] = Triangle(Vertex(10, -6, 5, 0), Vertex(13, 0, 5, 0), Vertex(10, 6, 5, 0), ColorDbl(1, 1, 1), this);
	triangles[11] = Triangle(Vertex(0, -6, 5, 0), Vertex(10, -6, 5, 0), Vertex(5, 0, 5, 0), ColorDbl(1, 1, 1), this);

	//W1
	triangles[12] = Triangle(Vertex(0, -6, 5, 0), Vertex(-3, 0, 5, 0), Vertex(-3, 0, -5, 0), ColorDbl(0.1, 0.9, 0.1), this);
	triangles[13] = Triangle(Vertex(0, -6, 5, 0), Vertex(-3, 0, -5, 0), Vertex(0, -6, -5, 0), ColorDbl(0.1, 0.9, 0.1), this);
	//W2
	triangles[14] = Triangle(Vertex(10, -6, 5, 0), Vertex(0, -6, 5, 0), Vertex(0, -6, -5, 0), ColorDbl(0.6, 0.0, 0.0), this);
	triangles[15] = Triangle(Vertex(10, -6, 5, 0), Vertex(0, -6, -5, 0), Vertex(10, -6, -5, 0), ColorDbl(0.6, 0.0, 0.0), this);
	//W3
	triangles[16] = Triangle(Vertex(13, 0, 5, 0), Vertex(10, -6, 5, 0), Vertex(10, -6, -5, 0), ColorDbl(0.9, 0.0, 0.7), this);
	triangles[17] = Triangle(Vertex(13, 0, 5, 0), Vertex(10, -6, -5, 0), Vertex(13, 0, -5, 0), ColorDbl(0.9, 0.0, 0.7), this);
	//W4
	triangles[18] = Triangle(Vertex(10, 6, 5, 0), Vertex(13, 0, 5, 0), Vertex(13, 0, -5, 0), ColorDbl(0.9, 1.0, 0.1), this);
	triangles[19] = Triangle(Vertex(10, 6, 5, 0), Vertex(13, 0, -5, 0), Vertex(10, 6, -5, 0), ColorDbl(0.9, 1.0, 0.1), this);
	//W5
	triangles[20] = Triangle(Vertex(0, 6, 5, 0), Vertex(10, 6, 5, 0), Vertex(10, 6, -5, 0), ColorDbl(0.0, 1.0, 0.6), this);
	triangles[21] = Triangle(Vertex(0, 6, 5, 0), Vertex(10, 6, -5, 0), Vertex(0, 6, -5, 0), ColorDbl(0.0, 1.0, 0.6), this);
	//W6
	triangles[22] = Triangle(Vertex(-3, 0, 5, 0), Vertex(0, 6, 5, 0), Vertex(0, 6, -5, 0), ColorDbl(0.2, 0, 0.3), this);
	triangles[23] = Triangle(Vertex(-3, 0, 5, 0), Vertex(0, 6, -5, 0), Vertex(-3, 0, -5, 0), ColorDbl(0.2, 0, 0.3), this);
}


Enviroment::~Enviroment()
{

}

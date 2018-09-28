#include "Enviroment.h"


Enviroment::Enviroment()
{
	triangles = new Triangle[24];
	numOftriangels = 24;
	matProp.opacity = 1;
	matProp.reflectivity = 0;

	//Bottom
	triangles[0] = Triangle(Vertex(-3, 0, -5, 0), Vertex(0, 6, -5, 0), Vertex(0, -6, -5, 0), ColorDbl(1, 1, 1), &this->matProp);
	triangles[1] = Triangle(Vertex(0, 6, -5, 0), Vertex(5, 0, -5, 0), Vertex(0, -6, -5, 0), ColorDbl(1, 1, 1), &this->matProp);
	triangles[2] = Triangle(Vertex(0, 6, -5, 0), Vertex(10, 6, -5, 0), Vertex(5, 0, -5, 0), ColorDbl(1, 1, 1), &this->matProp);
	triangles[3] = Triangle(Vertex(10, 6, -5, 0), Vertex(10, -6, -5, 0), Vertex(5, 0, -5, 0), ColorDbl(1, 1, 1), &this->matProp);
	triangles[4] = Triangle(Vertex(10, 6, -5, 0), Vertex(13, 0, -5, 0), Vertex(10, -6, -5, 0), ColorDbl(1, 1, 1), &this->matProp);
	triangles[5] = Triangle(Vertex(5, 0, -5, 0), Vertex(10, -6, -5, 0), Vertex(0, -6, -5, 0), ColorDbl(1, 1, 1), &this->matProp);

	//Top
	triangles[6] = Triangle(Vertex(0, -6, 5, 0), Vertex(0, 6, 5, 0), Vertex(-3, 0, 5, 0), ColorDbl(1, 1, 1), &this->matProp);
	triangles[7] = Triangle(Vertex(0, -6, 5, 0), Vertex(5, 0, 5, 0), Vertex(0, 6, 5, 0), ColorDbl(1, 1, 1), &this->matProp);
	triangles[8] = Triangle(Vertex(5, 0, 5, 0), Vertex(10, 6, 5, 0), Vertex(0, 6, 5, 0), ColorDbl(1, 1, 1), &this->matProp);
	triangles[9] = Triangle(Vertex(5, 0, 5, 0), Vertex(10, -6, 5, 0), Vertex(10, 6, 5, 0), ColorDbl(1, 1, 1), &this->matProp);
	triangles[10] = Triangle(Vertex(10, -6, 5, 0), Vertex(13, 0, 5, 0), Vertex(10, 6, 5, 0), ColorDbl(1, 1, 1), &this->matProp);
	triangles[11] = Triangle(Vertex(0, -6, 5, 0), Vertex(10, -6, 5, 0), Vertex(5, 0, 5, 0), ColorDbl(1, 1, 1), &this->matProp);

	//W1
	triangles[12] = Triangle(Vertex(0, -6, 5, 0), Vertex(-3, 0, 5, 0), Vertex(-3, 0, -5, 0), ColorDbl(0.1, 0.9, 0.1), &this->matProp);
	triangles[13] = Triangle(Vertex(0, -6, 5, 0), Vertex(-3, 0, -5, 0), Vertex(0, -6, -5, 0), ColorDbl(0.1, 0.9, 0.1), &this->matProp);
	//W2
	triangles[14] = Triangle(Vertex(10, -6, 5, 0), Vertex(0, -6, 5, 0), Vertex(0, -6, -5, 0), ColorDbl(0.6, 0.0, 0.0), &this->matProp);
	triangles[15] = Triangle(Vertex(10, -6, 5, 0), Vertex(0, -6, -5, 0), Vertex(10, -6, -5, 0), ColorDbl(0.6, 0.0, 0.0), &this->matProp);
	//W3
	triangles[16] = Triangle(Vertex(13, 0, 5, 0), Vertex(10, -6, 5, 0), Vertex(10, -6, -5, 0), ColorDbl(0.9, 0.0, 0.7), &this->matProp);
	triangles[17] = Triangle(Vertex(13, 0, 5, 0), Vertex(10, -6, -5, 0), Vertex(13, 0, -5, 0), ColorDbl(0.9, 0.0, 0.7), &this->matProp);
	//W4
	triangles[18] = Triangle(Vertex(10, 6, 5, 0), Vertex(13, 0, 5, 0), Vertex(13, 0, -5, 0), ColorDbl(0.9, 1.0, 0.1), &this->matProp);
	triangles[19] = Triangle(Vertex(10, 6, 5, 0), Vertex(13, 0, -5, 0), Vertex(10, 6, -5, 0), ColorDbl(0.9, 1.0, 0.1), &this->matProp);
	//W5
	triangles[20] = Triangle(Vertex(0, 6, 5, 0), Vertex(10, 6, 5, 0), Vertex(10, 6, -5, 0), ColorDbl(0.0, 1.0, 0.6), &this->matProp);
	triangles[21] = Triangle(Vertex(0, 6, 5, 0), Vertex(10, 6, -5, 0), Vertex(0, 6, -5, 0), ColorDbl(0.0, 1.0, 0.6), &this->matProp);
	//W6
	triangles[22] = Triangle(Vertex(-3, 0, 5, 0), Vertex(0, 6, 5, 0), Vertex(0, 6, -5, 0), ColorDbl(0.2, 0, 0.3), &this->matProp);
	triangles[23] = Triangle(Vertex(-3, 0, 5, 0), Vertex(0, 6, -5, 0), Vertex(-3, 0, -5, 0), ColorDbl(0.2, 0, 0.3), &this->matProp);
}


Enviroment::~Enviroment()
{

}

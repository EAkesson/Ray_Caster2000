#include "Sphere.h"

Sphere::Sphere()
{


	numOfTriangles = 21;
	triangles = new Triangle[numOfTriangles];
	matProp.opacity = 1;
	matProp.reflectivity = 1.0;
	matProp.color = ColorDbl(0,1,0);

	/*******************Construction*******************/

	long double X = 0.525731112119133606;
	long double Z = 0.850650808352039932;
	std::cout << X << std::endl;

	Vertex v1 = Vertex(-X+5, 2, Z, 0);
	Vertex v2 = Vertex(X+5, 2, Z, 0);
	Vertex v3 = Vertex(-X+5, 2, -Z, 0);
	Vertex v4 = Vertex(X+5, 2, -Z, 0);
	Vertex v5 = Vertex(5, Z+2, X, 0);
	Vertex v6 = Vertex(5, Z+2, -X, 0);
	Vertex v7 = Vertex(5, -Z+2, X, 0);
	Vertex v8 = Vertex(5, -Z+2, -X, 0);
	Vertex v9 = Vertex(Z+5, X+2, 0, 0);
	Vertex v10 = Vertex(-Z+5, X+2, 0, 0);
	Vertex v11 = Vertex(Z+5,-X+2, 0, 0);
	Vertex v12 = Vertex(-Z+5, -X+2, 0, 0);


	triangles[0] = Triangle(v1, v5, v2, this);
	triangles[1] = Triangle(v1, v10, v5, this);
	triangles[2] = Triangle(v10, v6, v5, this);
	triangles[3] = Triangle(v5, v6, v9, this);
	triangles[4] = Triangle(v5, v9, v2, this);

	triangles[5] = Triangle(v9, v11, v2, this);
	triangles[6] = Triangle(v9, v4, v11, this);
	triangles[7] = Triangle(v6, v4, v9, this);
	triangles[8] = Triangle(v6, v3, v4, this);
	triangles[9] = Triangle(v3, v8, v4, this);

	triangles[10] = Triangle(v8, v11, v4, this);
	triangles[12] = Triangle(v8, v7, v11, this);
	triangles[13] = Triangle(v8, v12, v7, this);
	triangles[14] = Triangle(v12, v1, v7, this);
	triangles[15] = Triangle(v1, v2, v7, this);

	triangles[16] = Triangle(v7, v2, v11, this);
	triangles[17] = Triangle(v10, v1, v12, this);
	triangles[18] = Triangle(v10, v12, v3, this);
	triangles[19] = Triangle(v10, v3, v6, this);
	triangles[20] = Triangle(v8, v3, v12, this);

	/*******************Construction*******************/
}
	


Sphere::~Sphere()
{
	delete triangles;
}

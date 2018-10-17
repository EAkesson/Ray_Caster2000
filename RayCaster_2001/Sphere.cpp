#include "Sphere.h"

Sphere::Sphere(float _radius, Vertex _center)
	:radius(_radius), center(_center)
{
	
	
	matProp.opacity = 1;
	matProp.reflectivity = 1.0;
	matProp.color = ColorDbl(0,1,0);
	

	/******************* Construction of Icosahedron *******************/
	/*
	triangles = new Triangle[numOfTriangles];
	numOfTriangles = 320;
	currentIndex = 0;
	long double X = 0.525731112119133606;
	long double Z = 0.850650808352039932;

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


	for (int i = 0; i < 20; i++) {
		subdivide(triangles[i].verticies[0], triangles[i].verticies[1], triangles[i].verticies[2],2);
	}
	*/
	/*******************Construction*******************/
}
/*
void Sphere::subdivide(Vertex  v1, Vertex v2, Vertex  v3, long depth)
{
	Vertex v12, v23, v31;

	if (depth == 0) {
		std::cout << "new tri" << std::endl;
		drawTriangle(v1, v2, v3);
		return;
	}
	
		v12 = v1 + v2;
		v23 = v2 + v3;
		v31 = v3 + v1;
	
	normalize(v12);
	normalize(v23);
	normalize(v31);
	subdivide(v1, v12, v31, depth - 1);
	subdivide(v2, v23, v12, depth - 1);
	subdivide(v3, v31, v23, depth - 1);
	subdivide(v12, v23, v31, depth - 1);
}
void Sphere::drawTriangle(Vertex  v1, Vertex v2, Vertex  v3)
{
	triangles[currentIndex] = Triangle(v1, v2, v3, this);
	currentIndex++;
}
	
	*/

Sphere::~Sphere()
{
	delete triangles;
	delete sphereFake;
}

void Sphere::rayIntersection(Ray * r)
{
	//This is pretty straight forward. We just implement the equation given in the CodeOutline
	
	glm::vec3 incomingV = r->end - r->start; //direction

	incomingV = glm::normalize(incomingV);


	//We calculate the vector from the ray origin to the center of the sphere
	glm::vec3 centerV = r->start - center;

	float b = glm::dot(incomingV*2.0f, centerV);

	float d1 = -b / 2.0f;

	float c = glm::dot(centerV, centerV) - radius * radius;

	float secondPart = d1 * d1 - c;

	if (secondPart < -EPSILON) return; //complex

	float d2 = d1;

	float sd = std::sqrt(secondPart);

	d1 += sd;
	d2 -= sd;

	if (d1 > EPSILON)
	{

		Vertex intPoint = Vertex(r->start.x + d1 * incomingV.x, r->start.y + d1 * incomingV.y, r->start.z + d1 * incomingV.z, 1);

		float t = glm::distance(r->start, intPoint);

		if (r->currentDistance > t)
		{
			r->currentDistance = t;
			/*Fake a triangle*/
			sphereFake = new Triangle(Vertex(6, -1, 3, 0), Vertex(7, -2, -1, 0), Vertex(5, -2, -1, 0), this); //random values
			sphereFake->normal = getNormal(intPoint);
			r->intersectedTriangle = sphereFake;
			r->intersectionPoint = (r->start) + Vertex(incomingV, 0)*t; //NOTE: incomingV is normalized
		}
		return; //We intersect with the sphere
	}
	else if (d2 > EPSILON)
	{

		Vertex intPoint = Vertex(r->start.x + d2 * incomingV.x, r->start.y + d2 * incomingV.y, r->start.z + d2 * incomingV.z, 1);
		float t = glm::distance(r->start, intPoint);

		if (r->currentDistance > t)
		{
			r->currentDistance = t;
			/*Fake a triangle*/
			sphereFake = new Triangle(Vertex(6, -1, 3, 0), Vertex(7, -2, -1, 0), Vertex(5, -2, -1, 0), this); //random values
			sphereFake->normal = getNormal(intPoint);

			r->intersectedTriangle = sphereFake; 
			r->intersectionPoint = (r->start) + Vertex(incomingV, 0)*t; //NOTE: incomingV is normalized
		}


		return; //We intersect with the sphere
	}


	return; //We do not
}
glm::vec3 Sphere::getNormal(Vertex _center)
{
	return glm::normalize(_center - center); // nromalizing
}

#include "Scene.h"



Scene::Scene()
{

}
void Scene::buildScene()
{
	sceneMesh[0] = new Triangle(Vertex(-3, 0, 5, 0), Vertex(0, 6, -5, 0), Vertex(0, -6, -5, 0), ColorDbl(1, 1, 1));



	//W1
	sceneMesh[12] = new Triangle(Vertex(0, -6, 5, 0), Vertex(-3, 0, 5, 0), Vertex(-3, 0, -5, 0), ColorDbl(0.1, 0.9, 0.1));
	sceneMesh[13] = new Triangle(Vertex(0, -6, 5, 0), Vertex(-3, 0, -5, 0), Vertex(0, -6, -5, 0), ColorDbl(0.1, 0.9, 0.1));
	//W2
	sceneMesh[14] = new Triangle(Vertex(10, -6, 5, 0), Vertex(0, -6, 5, 0), Vertex(0, -6, -5, 0), ColorDbl(0.6, 0.0, 0.0));
	sceneMesh[15] = new Triangle(Vertex(10, -6, 5, 0), Vertex(0, -6, -5, 0), Vertex(10, -6, -5, 0), ColorDbl(0.6, 0.0, 0.0));
	//W3
	sceneMesh[16] = new Triangle(Vertex(13, 0, 5, 0), Vertex(10, -6, 5, 0), Vertex(10, -6, -5, 0), ColorDbl(0.9, 0.0, 0.7));
	sceneMesh[17] = new Triangle(Vertex(13, 0, 5, 0), Vertex(10, -6, -5, 0), Vertex(13, 0, -5, 0), ColorDbl(0.9, 0.0, 0.7));
	//W4
	sceneMesh[18] = new Triangle(Vertex(10, 6, 5, 0), Vertex(13, 0, 5, 0), Vertex(13, 0, -5, 0), ColorDbl(0.9, 1.0, 0.1));
	sceneMesh[19] = new Triangle(Vertex(10, 6, 5, 0), Vertex(13, 0, -5, 0), Vertex(10, 6, -5, 0), ColorDbl(0.9, 1.0, 0.1));
	//W5
	sceneMesh[20] = new Triangle(Vertex(0, 6, 5, 0), Vertex(10, 6, 5, 0), Vertex(10, 6, -5, 0), ColorDbl(0.0, 1.0, 0.6));
	sceneMesh[21] = new Triangle(Vertex(0, 6, 5, 0), Vertex(10, 6, -5, 0), Vertex(0, 6, -5, 0), ColorDbl(0.0, 1.0, 0.6));
	//W6
	sceneMesh[22] = new Triangle(Vertex(-3, 0, 5, 0), Vertex(0, 6, 5, 0), Vertex(0, 6, -5, 0), ColorDbl(0.2, 0, 0.3));
	sceneMesh[23] = new Triangle(Vertex(-3, 0, 5, 0), Vertex(0, 6, -5, 0), Vertex(-3, 0, -5, 0), ColorDbl(0.2, 0, 0.3));

}

Scene::~Scene()
{
}

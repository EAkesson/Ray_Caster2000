#include "Scene.h"
#include "Tetrahedron.h"
#include "Light.h"
#include "Wall.h"
#include "PartyStructure.h"

Scene::Scene()
{
	buildScene();  // set up all vertecies


}

void Scene::triangleScan(Ray *r)
{
	for each (SceneObjects *sObject in objects)
	{
		sObject->rayIntersection(r);
	}

	//if (r->currentDistance == MAXILON) { //Assuming that no object is outside the room. 
	//	for each (Triangle *tri in sceneMesh)
	//	{
	//		//TODO check all hit trinagles and choose the closest
	//		if (tri->rayIntersection(r)) {
	//			//std::cout << tri->triangleColor.x << "|" << tri->triangleColor.y << "|" << tri->triangleColor.z << std::endl;
	//			//return(tri->triangleColor);
	//			break;
	//		}
	//	}
	//}
}

void Scene::buildScene()
{
	
	objects[0] = new Wall(Vertex(0, -6, 5, 0), Vertex(-3, 0, 5, 0), Vertex(-3, 0, -5, 0), Vertex(0, -6, -5, 0), ColorDbl(0.1, 0.9, 0.1));
	objects[1] = new Wall(Vertex(10, -6, 5, 0), Vertex(0, -6, 5, 0), Vertex(0, -6, -5, 0), Vertex(10, -6, -5, 0), ColorDbl(0.6, 0.0, 0.0));
	objects[2] = new Wall(Vertex(13, 0, 5, 0), Vertex(10, -6, 5, 0), Vertex(10, -6, -5, 0), Vertex(13, 0, -5, 0), ColorDbl(0.9, 0.0, 0.7));
	objects[3] = new Wall(Vertex(10, 6, 5, 0), Vertex(13, 0, 5, 0), Vertex(13, 0, -5, 0), Vertex(10, 6, -5, 0), ColorDbl(0.9, 1.0, 0.1));
	objects[4] = new Wall(Vertex(0, 6, 5, 0), Vertex(10, 6, 5, 0), Vertex(10, 6, -5, 0), Vertex(0, 6, -5, 0), ColorDbl(0.0, 1.0, 0.6));
	objects[5] = new Wall(Vertex(-3, 0, 5, 0), Vertex(0, 6, 5, 0), Vertex(0, 6, -5, 0), Vertex(-3, 0, -5, 0), ColorDbl(0.2, 0, 0.3));
	objects[6] = new PartyStructure(true, ColorDbl(1, 1, 1));
	objects[7] = new PartyStructure(false, ColorDbl(1, 1, 1));

	//objects[8] = new Tetrahedron(Vertex(4, -1, 3, 0), Vertex(5, -2, -1, 0), Vertex(3, -2, -1, 0), Vertex(4, 0, -1, 0), ColorDbl(0.2, 0.3, 1));
	objects[8] = new Light(Vertex(4, -1, 4.99, 0), Vertex(6, -1, 4.99, 0), Vertex(6, 1, 4.99, 0), Vertex(4, 1, 4.99, 0), ColorDbl(2,2,2), 100.0f);

}

Scene::~Scene()
{
}

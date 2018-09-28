#include "Scene.h"
#include "Tetrahedron.h"
#include "Enviroment.h"

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
	
	objects[0] = new Enviroment();
	objects[1] = new Tetrahedron(Vertex(4, -1, 3, 0), Vertex(5, -2, -1, 0), Vertex(4, 0, -1, 0), Vertex(3, -2, -1, 0), ColorDbl(0.2, 0.3, 1));

}

Scene::~Scene()
{
}

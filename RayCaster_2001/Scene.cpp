#include "Scene.h"
#include "Tetrahedron.h"



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
	if (r->currentDistance == MAXILON) { //Assuming that no object is outside the room. 
		for each (Triangle *tri in sceneMesh)
		{
			//TODO check all hit trinagles and choose the closest
			if (tri->rayIntersection(r)) {
				//std::cout << tri->triangleColor.x << "|" << tri->triangleColor.y << "|" << tri->triangleColor.z << std::endl;
				//return(tri->triangleColor);
				break;
			}
		}
	}
	
}

void Scene::buildScene()
{
	//Bottom
	sceneMesh[0] = new Triangle(Vertex(-3, 0, -5, 0), Vertex(0, 6, -5, 0), Vertex(0, -6, -5, 0), ColorDbl(1, 1, 1));
	sceneMesh[1] = new Triangle(Vertex(0, 6, -5, 0), Vertex(5, 0, -5, 0), Vertex(0, -6, -5, 0), ColorDbl(1, 1, 1));
	sceneMesh[2] = new Triangle(Vertex(0, 6, -5, 0), Vertex(10, 6, -5, 0), Vertex(5, 0, -5, 0), ColorDbl(1, 1, 1));
	sceneMesh[3] = new Triangle(Vertex(10, 6, -5, 0), Vertex(10, -6, -5, 0), Vertex(5, 0, -5, 0), ColorDbl(1, 1, 1));
	sceneMesh[4] = new Triangle(Vertex(10, 6, -5, 0), Vertex(13, 0, -5, 0), Vertex(10, -6, -5, 0), ColorDbl(1, 1, 1));
	sceneMesh[5] = new Triangle(Vertex(5, 0, -5, 0), Vertex(10, -6, -5, 0), Vertex(0, -6, -5, 0), ColorDbl(1, 1, 1));

	//Top
	sceneMesh[6] = new Triangle(Vertex(0, -6, 5, 0), Vertex(0, 6, 5, 0), Vertex(-3, 0, 5, 0), ColorDbl(1, 1, 1));
	sceneMesh[7] = new Triangle(Vertex(0, -6, 5, 0), Vertex(5, 0, 5, 0), Vertex(0, 6, 5, 0), ColorDbl(1, 1, 1));
	sceneMesh[8] = new Triangle(Vertex(5, 0, 5, 0), Vertex(10, 6, 5, 0), Vertex(0, 6, 5, 0), ColorDbl(1, 1, 1));
	sceneMesh[9] = new Triangle(Vertex(5, 0, 5, 0), Vertex(10, -6, 5, 0), Vertex(10, 6, 5, 0), ColorDbl(1, 1, 1));
	sceneMesh[10] = new Triangle(Vertex(10, -6, 5, 0), Vertex(13, 0, 5, 0), Vertex(10, 6, 5, 0), ColorDbl(1, 1, 1));
	sceneMesh[11] = new Triangle(Vertex(0, -6, 5, 0), Vertex(10, -6, 5, 0), Vertex(5, 0, 5, 0), ColorDbl(1, 1, 1));

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

	objects[0] =  new Tetrahedron(Vertex(4, -1, 3, 0), Vertex(5, -2, -1, 0), Vertex(4, 0, -1, 0), Vertex(3, -2, -1, 0), ColorDbl(0.2, 0.3, 1));

}

Scene::~Scene()
{
}

#include "SceneObjects.h"
#include "Tetrahedron.h"


void SceneObjects::rayIntersection(Ray * r)
{
	for (int i = 0; i < 4; i++) {
		triangles[i].rayIntersection(r);
	}

}

SceneObjects::SceneObjects()
{
}


SceneObjects::~SceneObjects()
{
}

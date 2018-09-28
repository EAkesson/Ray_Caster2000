#include "SceneObjects.h"

void SceneObjects::rayIntersection(Ray * r)
{
	for (size_t i = 0; i < numOfTriangles; i++)
	{
		triangles[i].rayIntersection(r);
	}
}

SceneObjects::SceneObjects()
{
}


SceneObjects::~SceneObjects()
{
}

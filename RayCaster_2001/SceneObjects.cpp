#include "SceneObjects.h"
#include "Tetrahedron.h"


ColorDbl SceneObjects::rayIntersection(Ray * r)
{
	for (int i = 0; i < 4; i++) {
		if (triangles[i].rayIntersection(r)) {
			//std::cout << sceneMesh[i]->triangleColor.x << "|" << sceneMesh[i]->triangleColor.y << "|" << sceneMesh[i]->triangleColor.z << std::endl;
			//std::cout << i << std::endl;
			return(triangles[i].triangleColor);
		}
	}
	return ColorDbl(0, 0, 0);
}

SceneObjects::SceneObjects()
{
}


SceneObjects::~SceneObjects()
{
}

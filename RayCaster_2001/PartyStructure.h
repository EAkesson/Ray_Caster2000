#pragma once
#include "Definitions.h"
#include "SceneObjects.h"

class PartyStructure : public SceneObjects
{
public:
	PartyStructure();
	PartyStructure(bool isRoof, ColorDbl &d);
	~PartyStructure();
};


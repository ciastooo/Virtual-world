#pragma once
#include "Plant.h"

class Wolfberry : public Plant
{
public:
	Wolfberry(World*, int, int, bool canMove = true);
	~Wolfberry();
	bool reproduce();
	bool collision(Organism*);
};

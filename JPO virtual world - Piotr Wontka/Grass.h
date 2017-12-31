#pragma once
#include "Plant.h"

class Grass : public Plant
{
public:
	Grass(World*, int, int, bool canMove = true);
	~Grass();
	bool reproduce();
};

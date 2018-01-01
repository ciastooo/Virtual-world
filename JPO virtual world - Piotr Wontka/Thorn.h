#pragma once
#include "Plant.h"

class Thorn : public Plant
{
public:
	Thorn(World*, int, int, bool canMove = true);
	~Thorn();
	bool reproduce();
};

#pragma once
#include "Animal.h"

class Sheep : public Animal
{
public:
	Sheep(World*, int, int, bool canMove = true);
	~Sheep();
};

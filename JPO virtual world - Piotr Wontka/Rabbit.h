#pragma once
#include "Animal.h"

class Rabbit: public Animal
{
public:
	Rabbit(World*, int, int, bool canMove = true);
	~Rabbit();
	bool reproduce();
};

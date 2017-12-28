#pragma once
#include "Animal.h"

class Lion : public Animal
{
public:
	Lion(World*, int, int, bool canMove = true);
	~Lion();
	bool reproduce();
	bool collision(Organism* other);
};

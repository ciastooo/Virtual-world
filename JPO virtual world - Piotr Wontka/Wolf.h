#pragma once
#include "Animal.h"

class Wolf : public Animal
{
public:
	Wolf(World*, int, int, bool canMove = true);
	~Wolf();
	bool reproduce();
};

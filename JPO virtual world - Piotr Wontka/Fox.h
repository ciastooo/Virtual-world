#pragma once
#include "Animal.h"

class Fox : public Animal
{
public:
	Fox(World*, int, int, bool canMove = true);
	~Fox();
	bool reproduce();
	void action();
};

#pragma once
#include "Organism.h"

class Animal: public Organism
{
public:
	Animal(World*, int, int, int, int, char, bool canMove = true);
	~Animal();
	void action();
	bool collision(Organism *other);
	virtual Animal* tryReproduce();
	void draw();
};

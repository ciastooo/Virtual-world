#pragma once
#include "Organism.h"

class Animal: public Organism
{
protected:
	virtual bool tryReproduce(Organism*);
public:
	Animal(World*, int, int, int, int, char, bool canMove = true);
	~Animal();
	virtual void action();
	virtual bool collision(Organism *other);
	virtual bool reproduce() = 0;
};

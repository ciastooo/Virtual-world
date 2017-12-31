#pragma once
#include "Organism.h"

class Plant: public Organism
{
protected:
	int reproducingChance;
	virtual bool tryReproduce(Organism*);
public:
	Plant(World *world, int strength, int x, int y, char symbol, bool canMove, int reproducingChance);
	~Plant();
	virtual void action();
	virtual bool collision(Organism*);
	virtual bool reproduce() = 0;
};
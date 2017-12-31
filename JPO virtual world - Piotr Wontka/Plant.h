#pragma once
#include "Organism.h"

class Plant: Organism
{
protected:
	int reproducingChance;
public:
	Plant(World *world, int strength, int x, int y, char symbol, int reproducingChance);
	~Plant();
	virtual void action();
	virtual bool collision(Organism*);
	virtual bool reproduce(int x, int y) = 0;
};
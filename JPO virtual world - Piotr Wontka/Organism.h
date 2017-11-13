#pragma once
#include "World.h"

class Organism
{
private:
	int strength;
	int initiative;
	int x;
	int y;
	World world;
public:
	Organism(World&, int, int, int, int);
	~Organism();
	void virtual action() = 0;
	void virtual collision() = 0;
	void virtual draw() = 0;
};
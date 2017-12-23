#pragma once
class World; // forward declaration
//#include "World.h"

class Organism
{
protected:
	int strength;
	int initiative;
	int x;
	int y;
	World* world;
public:
	Organism(World*, int, int, int, int);
	~Organism();
	void virtual action() = 0;
	void virtual collision() = 0;
	void virtual draw() = 0;
	int getInitiative();
	World* getWorld();
	int getX();
	int getY();
	int getStrength();
};
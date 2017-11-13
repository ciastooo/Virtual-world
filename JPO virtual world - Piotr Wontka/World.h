#pragma once
#include "Organism.h"
#include <vector>

class World
{
private:
	int width;
	int height;
	std::vector<Organism> organisms;
public:
	World();
	World(int, int);
	~World();
	void Tick();
	void draw();
	int getWidth();
	int getheight();
};
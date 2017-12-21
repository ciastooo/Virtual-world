#pragma once
#include "Organism.h"

class World
{
private:
	int width;
	int height;
	Organism *organisms;
	int organisimsLength;
	void moveCursorTo(int x, int y);
public:
	World(int, int);
	World();
	~World();
	void Tick();
	void draw();
	int getOrganisimsCount();
};
#pragma once
#include "OrganismList.h"

class World
{
private:
	int width;
	int height;
	OrganismList *organisms;
	void moveCursorTo(int x, int y);
public:
	World(int, int);
	World();
	~World();
	void Tick();
	void draw();
};
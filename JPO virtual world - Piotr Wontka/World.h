#pragma once
#include "OrganismList.h"

class World
{
private:
	int width;
	int height;
	OrganismList *organisms;
public:
	World(int, int);
	World();
	~World();
	void Tick();
	void draw();
	int getWidth();
	int getHeight();
	void moveCursorTo(int x, int y);
	void insertOrganism(Organism*);
	Organism* getOrganismFromPosition(int x, int y);
	void exportToFile();
};
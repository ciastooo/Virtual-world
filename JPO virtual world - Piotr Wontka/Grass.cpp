#include <iostream>
#include "Grass.h"
#include "World.h"

using namespace std;

Grass::Grass(World *world, int x, int y, bool canMove) : Plant(world, 0, x, y, 'g', canMove, 50)
{
}

Grass::~Grass() {

}

bool Grass::reproduce() {
	Grass *offspring = new Grass(this->world, this->x, this->y, false);
	if (this->tryReproduce(offspring)) {
		return true;
	}
	else {
		delete offspring;
		return false;
	}
}
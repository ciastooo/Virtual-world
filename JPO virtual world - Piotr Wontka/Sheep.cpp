#include "Sheep.h"
#include "World.h"

Sheep::Sheep(World *world, int x, int y, bool canMove) : Animal(world, 4, 4, x, y, 'S', canMove)
{
}

Sheep::~Sheep() {

}

bool Sheep::reproduce() {
	Sheep *offspring = new Sheep(this->world, this->x, this->y, false);
	if (Animal::tryReproduce(offspring)) {
		return true;
	}
	else {
		delete offspring;
		return false;
	}
}

#include "Wolf.h"
#include "World.h"

Wolf::Wolf(World *world, int x, int y, bool canMove): Animal(world, 9, 5, x, y, 'W', canMove)
{
}

Wolf::~Wolf() {

}
bool Wolf::reproduce() {
	Wolf *offspring = new Wolf(this->world, this->x, this->y, false);
	if (Animal::tryReproduce(offspring)) {
		return true;
	}
	else {
		delete offspring;
		return false;
	}
}

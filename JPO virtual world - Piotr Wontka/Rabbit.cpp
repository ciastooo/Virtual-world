#include <iostream>
#include "Rabbit.h"
#include "World.h"

using namespace std;

Rabbit::Rabbit(World *world, int x, int y, bool canMove) : Animal(world, 1, 8, x, y, 'R', canMove)
{
}

Rabbit::~Rabbit() {

}

bool Rabbit::reproduce() {
	Rabbit *offspring = new Rabbit(this->world, this->x, this->y, false);
	if (this->tryReproduce(offspring)) {
		Rabbit *offspring2 = new Rabbit(this->world, this->x, this->y, false);
		if (!this->tryReproduce(offspring2)) {
			delete offspring2;
		}
		return true;
	}
	else {
		delete offspring;
		return false;
	}
}

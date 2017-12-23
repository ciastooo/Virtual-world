#include "stdafx.h"
#include "Animal.h"
#include "RandomNumber.h"
#include "World.h"

Animal::Animal(World *world, int strength, int initiative, int x, int y): Organism(world, strength, initiative, x, y)
{

}

Animal::~Animal()
{
}

void Animal::action() {
	int moveDirection = RandomNumber::getRandomNumber(1, 4);
	switch (moveDirection) {
	case 1:
		// north
		if (this->y == 1) 
		{
			this->y = this->world->getHeight();
		}
		else {
			this->y -= 1;
		}
		break;
	case 2:
		// east
		if (this->x == this->world->getWidth()) {
			this->x = 1;
		}
		else {
			this->x += 1;
		}
		break;
	case 3:
		// south
		if (this->y == this->world->getHeight()) {
			this->y = 1;
		}
		else {
			this->y += 1;
		}
		break;
	case 4:
	default:
		// west
		if (this->x == 1) {
			this->x = this->world->getWidth();
		}
		else {
			this->x -= 1;
		}
		break;
	}
}

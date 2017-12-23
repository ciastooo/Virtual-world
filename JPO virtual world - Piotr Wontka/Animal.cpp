#include <iostream>
#include "Animal.h"
#include "RandomNumber.h"
#include "World.h"

using namespace std;

Animal::Animal(World *world, int strength, int initiative, int x, int y, char symbol): Organism(world, strength, initiative, x, y, symbol)
{

}

Animal::~Animal()
{
}

void Animal::action() {
	int moveDirection = RandomNumber::getRandomNumber(1, 4);
	cout << "Zwierze: " << this->symbol<< " ";
	switch (moveDirection) {
	case 1:
		// north
		cout << "Na polnoc";
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
		cout << "Na wschod";
		if (this->x == this->world->getWidth()) {
			this->x = 1;
		}
		else {
			this->x += 1;
		}
		break;
	case 3:
		// south
		cout << "Na poludnie";
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
		cout << "Na zachod";
		if (this->x == 1) {
			this->x = this->world->getWidth();
		}
		else {
			this->x -= 1;
		}
		break;
	}
	cout << endl;
}
void Animal::draw() {
	Organism::draw();
}
#include <iostream>
#include "Lion.h"
#include "World.h"

using namespace std;

Lion::Lion(World *world, int x, int y, bool canMove): Animal(world, 11, 7, x, y, 'L', canMove)
{
}

Lion::~Lion() {

}

bool Lion::reproduce() {
	Lion *offspring = new Lion(this->world, this->x, this->y, false);
	if (this->tryReproduce(offspring)) {
		return true;
	}
	else {
		delete offspring;
		return false;
	}
}

bool Lion::collision(Organism* other) {
	if (other->getStrength() < 5) {
		cout << "Zwierzê " << other->getSymbol() << " ma mniej ni¿ 5 si³y. " << other->getSymbol() << " wycofuje siê" << endl;
		return false;
	}
	else {
		return this->Animal::collision(other);
	}
}

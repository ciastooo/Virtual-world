#include <iostream>
#include "Wolfberry.h"
#include "World.h"

using namespace std;

Wolfberry::Wolfberry(World *world, int x, int y, bool canMove) : Plant(world, 0, x, y, 'w', canMove, 25)
{
}

Wolfberry::~Wolfberry() {

}

bool Wolfberry::reproduce() {
	Wolfberry *offspring = new Wolfberry(this->world, this->x, this->y, false);
	if (this->tryReproduce(offspring)) {
		return true;
	}
	else {
		delete offspring;
		return false;
	}
}

bool Wolfberry::collision(Organism *other) {
	if(this->Plant::collision(other) && this->toDelete) {
		// I f we got here, it means that colliding organism ate Wolfberry => it dies
		cout << "Ro�lina " << this->symbol << " jest truj�ca! Zwierz� " << other->getSymbol() << " zatruwa si�" << endl;
		other->setToDelete();
		return true;
	}
	return false;
}
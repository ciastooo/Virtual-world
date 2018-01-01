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
		cout << "Roœlina " << this->symbol << " jest truj¹ca! Zwierzê " << other->getSymbol() << " zatruwa siê" << endl;
		other->setToDelete();
		return true;
	}
	return false;
}
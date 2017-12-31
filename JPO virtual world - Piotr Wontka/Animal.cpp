#include <iostream>
#include "Animal.h"
#include "RandomNumber.h"
#include "World.h"

using namespace std;

Animal::Animal(World *world, int strength, int initiative, int x, int y, char symbol, bool canMove): Organism(world, strength, initiative, x, y, symbol, canMove)
{
}

Animal::~Animal()
{
}

bool Animal::tryReproduce(Organism *child) {
	for (int x = this->x - 1; x <= this->x + 1; x += 2) {
		Organism *occupied;
		int tmpX = x;
		if (x < 1) {
			tmpX = this->world->getWidth();
		}
		else if (x > this->world->getWidth()) {
			tmpX = 1;
		}
		occupied = this->world->getOrganismFromPosition(tmpX, this->y);
		if (occupied == nullptr) {
			child->setXY(tmpX, this->y);
			this->world->insertOrganism(child);
			return true;
		}
	}
	for (int y = this->y - 1; y <= this->y + 1; y += 2) {
		Organism *occupied;
		int tmpY = y;
		if (y < 1) {
			tmpY = this->world->getHeight();
		}
		else if (y > this->world->getHeight()) {
			tmpY = 1;
		}
		occupied = this->world->getOrganismFromPosition(this->x, tmpY);
		if (occupied == nullptr) {
			child->setXY(this->x, tmpY);
			this->world->insertOrganism(child);
			return true;
		}
	}
	return false;
}

void Animal::action() {
	if (!this->canMove) {
		this->canMove = true;
		return;
	}
	int newX = this->x;
	int newY = this->y;
	int moveDirection = RandomNumber::getRandomNumber(1, 4);
	cout << "Zwierze: " << this->symbol<< " ";
	switch (moveDirection) {
	case 1:
		// north
		cout << "Na pó³noc";
		if (this->y == 1) 
		{
			newY = this->world->getHeight();
		}
		else {
			newY = this->y - 1;
		}
		break;
	case 2:
		// east
		cout << "Na wschód";
		if (this->x == this->world->getWidth()) {
			newX = 1;
		}
		else {
			newX = this->x + 1;
		}
		break;
	case 3:
		// south
		cout << "Na po³udnie";
		if (this->y == this->world->getHeight()) {
			newY = 1;
		}
		else {
			newY = this->y + 1;
		}
		break;
	case 4:
	default:
		// west
		cout << "Na zachód";
		if (this->x == 1) {
			newX = this->world->getWidth();
		}
		else {
			newX = this->x - 1;
		}
		break;
	}
	cout << endl;
	Organism *colliding = this->world->getOrganismFromPosition(newX, newY);
	if (colliding != nullptr) {

		cout << "Kolizja zwierzêcia: " << this->symbol << " z " << colliding->getSymbol() << endl;
		if (colliding->collision(this)) {
			this->x = newX;
			this->y = newY;
		}
	}
	else {
		this->x = newX;
		this->y = newY;
	}
	this->canMove = false;
}
bool Animal::collision(Organism *colliding) {
	if (colliding->getSymbol() == this->symbol) {
		Animal *collidingSameAnimal = dynamic_cast<Animal*>(colliding);
		//same organisms -> they try to multiply
		cout << "Próba reprodukcji zwerzêcia " << this->symbol << "... ";
		bool tryMultiply = this->reproduce();
		if (!tryMultiply) {
			//let's try with other Animal
			tryMultiply = collidingSameAnimal->reproduce();
		}
		if (tryMultiply) {
			cout << "Sukces!" << endl;
			return false;
		}
		else {
			cout << "Brak miejsca!" << endl;
			return false;
		}
	}
	else {
		cout << "Walka! ";
		if (this->strength > colliding->getStrength()) {
			cout << "Atakuj¹ce zwierze " << colliding->getSymbol() << " przegrywa i umiera!" << endl;
			colliding->setToDelete();
		}
		else {
			cout << "Atakuj¹ce zwierze " << colliding->getSymbol() << " wygrywa! Zwierze " << this->symbol << " umiera" << endl;
			this->toDelete = true;
		}
		return true;
	}
}

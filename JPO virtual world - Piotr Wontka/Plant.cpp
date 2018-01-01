#include "stdafx.h"
#include "Plant.h"
#include <iostream>
#include "RandomNumber.h"
#include "World.h"

using namespace std;

Plant::Plant(World *world, int strength, int x, int y, char symbol, bool canMove, int reproducingChance): Organism(world, strength, 0, x, y, symbol, canMove)
{
	this->reproducingChance = reproducingChance;
}


Plant::~Plant()
{
}

void Plant::action() {
	if (!this->canMove) {
		this->canMove = true;
		return;
	}
	cout << "Ro�lina " << this->symbol << " pr�buje si� rozmno�y�";
	int randomNumber = RandomNumber::getRandomNumber(1, 100);
	if (randomNumber > this->reproducingChance) {
		cout << " - nie uda�o si�" << endl;
	}
	else {
		this->reproduce();
	}
	this->canMove = false;
}

bool Plant::collision(Organism *other) {
	cout << other->getSymbol() << " napotyka ro�lin� " << this->symbol << endl;
	if (this->strength > other->getStrength()) {
		cout << "Zwierze " << other->getSymbol() << " rani si� na ro�linie " << this->symbol << " i ginie" << endl;
		other->setToDelete();
	}
	else {
		cout << "Zwierze " << other->getSymbol() << " zjada ro�lie " << this->symbol << endl;
		this->toDelete = true;
	}
	return true;
}

bool Plant::tryReproduce(Organism *child) {
	cout << " na ";
	int direction = RandomNumber::getRandomNumber(1, 4);
	int newY = this->y;
	int newX = this->x;
	switch (direction) {
	case 1:
		cout << "p�noc";
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
		cout << "wsch�d";
		if (this->x == this->world->getWidth()) {
			newX = 1;
		}
		else {
			newX = this->x + 1;
		}
		break;
	case 3:
		// south
		cout << "po�udnie";
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
		cout << "zach�d";
		if (this->x == 1) {
			newX = this->world->getWidth();
		}
		else {
			newX = this->x - 1;
		}
		break;
	}
	Organism *colliding = this->world->getOrganismFromPosition(newX, newY);
	if (colliding != nullptr) {
		cout << " ale to pole jest ju� zaj�te" << endl;
		return false;
	}
	else {
		cout << ". Sukces" << endl;
		child->setXY(newX, newY);
		this->world->insertOrganism(child);
		return true;
	}
}
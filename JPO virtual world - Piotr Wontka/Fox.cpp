#include <iostream>
#include "Fox.h"
#include "World.h"
#include "RandomNumber.h"

using namespace std;

Fox::Fox(World *world, int x, int y, bool canMove) : Animal(world, 3, 7, x, y, 'F', canMove)
{
}

Fox::~Fox() {

}
bool Fox::reproduce() {
	Fox *offspring = new Fox(this->world, this->x, this->y, false);
	if (Animal::tryReproduce(offspring)) {
		return true;
	}
	else {
		delete offspring;
		return false;
	}
}
void Fox::action() {
	if (!this->canMove) {
		this->canMove = true;
		return;
	}
	int newX = this->x;
	int newY = this->y;
	int moveDirection = RandomNumber::getRandomNumber(1, 4);
	switch (moveDirection) {
	case 1:
		// north
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
		if (this->x == this->world->getWidth()) {
			newX = 1;
		}
		else {
			newX = this->x + 1;
		}
		break;
	case 3:
		// south
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
		if (colliding->getStrength() > this->strength) {
			this->action();
			return;
		}
		else {
			cout << "Zwierze: " << this->symbol << " ";
			switch (moveDirection) {
			case 1:
				cout << "Na pó³noc";
				break;
			case 2:
				cout << "Na wschód";
				break;
			case 3:
				cout << "Na po³udnie";
				break;
			case 4:
			default:
				cout << "Na zachód";
				break;
			}
			cout << endl;
			cout << "Kolizja zwierzêcia: " << this->symbol << " z " << colliding->getSymbol() << endl;
			if (colliding->collision(this)) {
				this->x = newX;
				this->y = newY;
			}
		}
	}
	else {
		cout << "Zwierze: " << this->symbol << " ";
		switch (moveDirection) {
		case 1:
			cout << "Na pó³noc";
			break;
		case 2:
			cout << "Na wschód";
			break;
		case 3:
			cout << "Na po³udnie";
			break;
		case 4:
		default:
			cout << "Na zachód";
			break;
		}
		cout << endl;
		this->x = newX;
		this->y = newY;
	}
	this->canMove = false;
}
#include "stdafx.h"
#include "Organism.h"
#include "World.h"
#include "RandomNumber.h"
#include <iostream>
using namespace std;

Organism::Organism(World *world, int strength, int initiative, int x, int y, char symbol)
{
	this->world = world;
	this->strength = strength;
	this->initiative = initiative;
	this->x = x;
	this->y = y;
	this->symbol = symbol;
}

Organism::~Organism()
{
}

void Organism::action() {
	
}

bool Organism::collision(Organism* other) {
	return true;
}

void Organism::draw() {
	this->world->moveCursorTo(this->x, this->y);
	cout << this->symbol;
}

int Organism::getInitiative() {
	return this->initiative;
}
World* Organism::getWorld() {
	return this->world;
}
int Organism::getX() {
	return this->x;
}
int Organism::getY() {
	return this->y;
}
int Organism::getStrength() {
	return this->strength;
}
char Organism::getSymbol() {
	return this->symbol;
}
bool Organism::getCanMove() {
	return this->canMove;
}
void Organism::setCanMove(bool newValue) {
	this->canMove = newValue;
}
void Organism::setToDelete() {
	this->toDelete = true;
}
bool Organism::getToDelete() {
	return this->toDelete;
}
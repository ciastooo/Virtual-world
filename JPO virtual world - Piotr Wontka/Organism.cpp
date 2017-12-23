#include "stdafx.h"
#include "Organism.h"
#include "World.h"
#include "RandomNumber.h"

Organism::Organism(World *world, int strength, int initiative, int x, int y)
{
	this->world = world;
	this->strength = strength;
	this->initiative = initiative;
	this->x = x;
	this->y = y;
}

Organism::~Organism()
{
}

void Organism::action() {
	
}

void Organism::collision() {

}

void Organism::draw() {

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
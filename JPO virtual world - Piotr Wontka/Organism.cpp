#include "stdafx.h"
#include "Organism.h"
//#include "World.h"

Organism::Organism() {

}
Organism::Organism(int strength, int initiative, int x, int y, char symbol)
{
	//this->world = world;
	this->strength = strength;
	this->initiative = initiative;
	this->x = x;
	this->y = y;
	this->symbol = symbol;
}

Organism::~Organism()
{
}
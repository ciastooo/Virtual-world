#pragma once
#include "Organism.h"

class Animal: public Organism
{
public:
	Animal(World*, int, int, int, int, char);
	~Animal();
	void action();
	void draw();
};


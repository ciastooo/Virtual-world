#pragma once
#include "Organism.h"

class Animal: Organism
{
public:
	Animal(World*, int, int, int, int);
	~Animal();
	void action();
};


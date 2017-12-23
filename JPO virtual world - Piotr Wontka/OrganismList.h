#pragma once
#include "OrganismListItem.h"

class OrganismList
{
private:
	OrganismListItem *head;
public:
	OrganismList();
	~OrganismList();
	void insert(Organism*);
	void doAction();
	void drawAll();
	void remove(Organism*);
};
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
};
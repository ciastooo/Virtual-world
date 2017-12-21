#pragma once
#include "Organism.h"

class OrganismListItem {
private:
	Organism *organism;
	OrganismListItem *next;
	OrganismListItem *prev;
public:
	OrganismListItem(Organism*);
	~OrganismListItem();
	void setNext(OrganismListItem*);
	void setPrev(OrganismListItem*);
	OrganismListItem* getNext();
	OrganismListItem* getPrev();
	Organism* getOrganism();
};
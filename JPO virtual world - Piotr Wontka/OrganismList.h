#pragma once
#include "OrganismListItem.h"
#include <fstream>

using namespace std;

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
	void remove(OrganismListItem*);
	OrganismListItem* search(int x, int y);
	void refreshMove();
	void writeToFile(ofstream&);
};
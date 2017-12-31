#pragma once
class World; // forward declaration
//#include "World.h"

class Organism
{
protected:
	int strength;
	int initiative;
	int x;
	int y;
	World* world;
	char symbol;
	bool canMove;
	bool toDelete = false;
	virtual bool tryReproduce(Organism*) = 0;
public:
	Organism(World*, int strength, int initiative, int x, int y, char symbol, bool canMove);
	~Organism();
	virtual void action() = 0;
	virtual bool collision(Organism*) = 0;
	virtual void draw();
	virtual bool reproduce() = 0;
	int getInitiative();
	World* getWorld();
	int getX();
	int getY();
	void setXY(int, int);
	int getStrength();
	char getSymbol();
	bool getCanMove();
	void setCanMove(bool);
	void setToDelete();
	bool getToDelete();
};
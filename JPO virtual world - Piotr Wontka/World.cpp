#include "stdafx.h"
#include "World.h"
#include <iostream>
#include <windows.h>

using namespace std;

World::World(int width, int height)
{
	if (height > 20) {
		this->height = 20;
	}
	else if (height < 5) {
		this->height = 5;
	}
	else {
		this->height = height;
	}

	if (width > 70) {
		this->width = 70;
	} else if (width < 5) {
		this->width = 5;
	}
	else {
		this->width = width;
	}
	this->organisms = new OrganismList();
}
World::World() : height(20), width(20)
{
}
World::~World()
{
	delete organisms;
}
void World::draw() {
	for (int i = 0; i < this->width+2; i++) {
		cout << "#";
	}
	for (int i = 0; i < this->height + 1; i++) {
		cout << endl << "#";
		this->moveCursorTo(this->width + 1, i);
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i < this->width + 2; i++) {
		cout << "#";
	}
}
void World::Tick() {
	system("cls");
	this->draw();
	this->moveCursorTo(0, this->height+3);
	this->organisms->doAction();
	this->organisms->drawAll();
}
void World::moveCursorTo(int x, int y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
int World::getHeight() {
	return this->height;
}
int World::getWidth() {
	return this->width;
}
void World::insertOrganism(Organism *toInsert) {
	this->organisms->insert(toInsert);
}
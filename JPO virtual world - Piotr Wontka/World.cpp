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
}
World::World() : height(20), width(20)
{
}
World::~World()
{
	if (organisimsLength > 0) {
		delete[] organisms;
	}
}
void World::draw() {
	for (int i = 0; i < this->width+2; i++) {
		cout << "#";
	}
	for (int i = 0; i < this->height + 2; i++) {
		cout << endl << "#";
		this->moveCursorTo(this->width + 1, i);
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i < this->width + 2; i++) {
		cout << "#";
	}
	for (int i = 0; i < this->organisimsLength; i++) {
		this->organisms[i].draw();
	}
}
void World::Tick() {
	this->moveCursorTo(0, this->height+3);
	for (int i = 0; i < this->organisimsLength; i++) {
		this->organisms[i].action();
	}
}
void World::moveCursorTo(int x, int y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
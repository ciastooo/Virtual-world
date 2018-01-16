#include "stdafx.h"
#include "World.h"
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
// Animals:
#include "Wolf.h" // W
#include "Sheep.h" // S
#include "Fox.h" // F
#include "Lion.h" // L
#include "Rabbit.h" // R
// Plants:
#include "Grass.h" // g
#include "Wolfberry.h" // w
#include "Thorn.h" // t

using namespace std;

World::World(int width, int height)
{
	if (height > 40) {
		this->height = 40;
	}
	else if (height < 2) {
		this->height = 2;
	}
	else {
		this->height = height;
	}

	if (width > 40) {
		this->width = 40;
	} else if (width < 2) {
		this->width = 2;
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
	delete this->organisms;
}
void World::draw() {
	this->moveCursorTo(0, -1);
	cout << "Piotr Wontka 167951" << endl;
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
void World::drawAll() {
	this->draw();
	this->organisms->drawAll();
	this->moveCursorTo(0, this->height+3);
}
void World::Tick() {
	system("cls");
	this->draw();
	this->moveCursorTo(0, this->height + 3);
	cout << endl << "\tWpisz \"q\" aby wyjœæ; \"s\" aby wyeksportowaæ stan œwiata; " << endl;
	cout << "\t\"i\" aby zimportowaæ stan œwiata\tlub dowolny klawisz aby kontynuowaæ" << endl;
	this->organisms->doAction();
	this->organisms->refreshMove();
	this->organisms->drawAll();
	this->moveCursorTo(0, -1);
}
void World::moveCursorTo(int x, int y)
{
	COORD p = { x, y+1 };
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
Organism* World::getOrganismFromPosition(int x, int y) {
	OrganismListItem *search = this->organisms->search(x, y);
	if (search != nullptr) {
		return search->getOrganism();
	}
	else {
		return nullptr;
	}
}
void World::exportToFile() {
	system("cls");
	string fileName;
	cout << "Podaj nazwê pliku do którego ma zostaæ zapisany stan œwiata: ";
	cin >> fileName;
	ofstream file;
	file.open(fileName + ".txt");
	file << this->width << endl;
	file << this->height << endl;
	this->organisms->writeToFile(file);
	file.close();
	cout << endl << "Sukces! Plik zosta³ zapisany pod nazw¹ " << fileName << ".txt" << endl;
	getchar();
}
void World::importFromFile() {
	system("cls");
	string fileName;
	cout << "Podaj nazwê pliku do którego z którego ma zostaæ odczytany stan œwiata: ";
	cin >> fileName;
	ifstream file;
	file.open(fileName + ".txt");
	if (file.is_open()) {
		delete this->organisms;
		this->organisms = new OrganismList();
		int x, y;
		char organism;
		Organism* importingOrganism = nullptr;
		file >> x;
		file >> y;
		cout << "Œwiat o szerokoœci = " << x << "   oraz wysokoœci = " << y << endl;
		this->width = x;
		this->height = y;
		while (!file.eof()) {
			file >> organism;
			file >> x;
			file >> y;
			switch(organism) {
			case 'W':
				cout << "Wilk: ";
				importingOrganism = new Wolf(this, x, y);
				break;
			case 'S':
				cout << "Owca: ";
				importingOrganism = new Sheep(this, x, y);
				break;
			case 'F':
				cout << "Lis: ";
				importingOrganism = new Fox(this, x, y);
				break;
			case 'L':
				cout << "Lew: ";
				importingOrganism = new Lion(this, x, y);
				break;
			case 'R':
				cout << "Królik: ";
				importingOrganism = new Rabbit(this, x, y);
				break;
			case 'g':
				cout << "Trawa: ";
				importingOrganism = new Grass(this, x, y);
				break;
			case 'w':
				cout << "Wilcze jagody: ";
				importingOrganism = new Wolfberry(this, x, y);
				break;
			case 't':
			default:
				cout << "Cierñ: ";
				importingOrganism = new Thorn(this, x, y);
				break;
			}
			cout << "na pozycji x = " << x << "  y = " << y << endl;
			if (importingOrganism != nullptr) {
				this->organisms->insert(importingOrganism);
			}
		}
		cout << endl << "Sukces! Plik zosta³ odczytany" << endl;
	}
	else {
		cout << "Plik o podanej nazwie nie istnieje" << endl;
	}
	file.close();
	getchar();
}

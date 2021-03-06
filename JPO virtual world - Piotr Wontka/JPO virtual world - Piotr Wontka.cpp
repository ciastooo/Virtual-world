// JPO virtual world - Piotr Wontka.cpp
// Informatyka niestacjonarnie semstr III.
// Indeks: 167951
// Implementacja zwierząt: Wilk, Owca, (Królik), Lis, Lew
// Implementacja roślin: Trawa, Wilcze jagody, Cierń 
//

#include <iostream>
#include "World.h"
#include "RandomNumber.h"
#include "stdafx.h"
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

int main()
{
	locale locpl("Polish_Poland");
	locale::global(locpl);
	cout.imbue(locpl);
	cin.imbue(locpl);
	cout.imbue(locale(""));
	RandomNumber::init();
	int x, y;
	cout << "Podaj szerokość świata (2-40):  ";
	cin >> x;
	cout <<  "Podaj wysokość świata (2-40):  ";
	cin >> y;
	World *world = new World(x, y);
	x = world->getWidth();
	y = world->getHeight();
	char key = 'a';
	system("cls");
	world->drawAll();
	Organism *adding = nullptr;
	while (key != 'Q' && key != 'q') {
		cout << endl << "Jaki organizm chcesz dodać? (W,O,L,l,K,t,c,w)?";
		cout << endl << "Wpisz \"Q\" aby zrezygnować z dodawania organizmów" << endl;
		key = (char)_gettch();
		switch (key) {
		case 'q':
		case 'Q':
			break;
		case 33:
			break;
		case 'W':
			adding = new Wolf(world, 0, 0, false);
			break;
		case 'O':
			adding = new Sheep(world, 0, 0, false);
			break;
		case 'L':
			adding = new Lion(world, 0, 0, false);
			break;
		case 'l':
			adding = new Fox(world, 0, 0, false);
			break;
		case 'K':
			adding = new Rabbit(world, 0, 0, false);
			break;
		case 't':
			adding = new Grass(world, 0, 0, false);
			break;
		case 'w':
			adding = new Wolfberry(world, 0, 0, false);
			break;
		case 'c':
			adding = new Thorn(world, 0, 0, false);
			break;
		default:
			system("cls");
			world->drawAll();
			cout << "Wciśnięto nieznany klawisz, wpisz ponownie:  ";
			break;
		}
		if (adding != nullptr) {
			bool tryingToAdd = true;
			int tmpX, tmpY, tries = 0;
			while (tryingToAdd) {
				tmpX = RandomNumber::getRandomNumber(1, x);
				tmpY = RandomNumber::getRandomNumber(1, y);
				Organism *colliding = world->getOrganismFromPosition(tmpX, tmpY);
				if (colliding == nullptr) {
					adding->setXY(tmpX, tmpY);
					world->insertOrganism(adding);
					system("cls");
					world->drawAll();
					cout << "Organizm został umieszczony na polu x=" << tmpX << "  y=" << tmpY << endl;
					tryingToAdd = false;
					adding = nullptr;
				}
				else if(tries == 8) {
					system("cls");
					world->drawAll();
					cout << "Organizm próbowano dodać 8 razy w losowych miejsach ale natrafiano na inne organizmy" << endl;
					cout << "Być może brakuje miejsca?" << endl;
					delete adding;
					adding = nullptr;
					break;
				}
				tries++;
			}
		}
	}
	key = 'a';
	while(key != 'Q' && key != 'q') {
		world->Tick();
		key = (char)_gettch();
		if (key == 's') {
			world->exportToFile();
		}
		else if (key == 'i') {
			world->importFromFile();
			_gettch();
		}
	}


	delete world;
	return 0;
}
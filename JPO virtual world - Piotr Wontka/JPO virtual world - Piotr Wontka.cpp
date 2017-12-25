// JPO virtual world - Piotr Wontka.cpp
// Informatyka niestacjonarnie semstr III.
// Indeks: 167951
// Implementacja zwierząt: Wilk, Owca, (Nosorożec), Lis, Lew
// Implementacja roślin: Trawa, Wilcze jagody, Cierń 
//

#include <iostream>
#include "World.h"
#include "Animal.h"

using namespace std;

int main()
{
	locale locpl("Polish_Poland");
	locale::global(locpl);
	cout.imbue(locpl);
	cin.imbue(locpl);
	cout.imbue(locale(""));
	World *world = new World(10, 10);
	Animal *test = new Animal(world, 15, 15, 1, 2, 'A');
	Animal *test1 = new Animal(world, 15, 15, 1, 1, 'A');
	Animal *test2 = new Animal(world, 15, 15, 2, 1, 'A');
	Animal *test3 = new Animal(world, 15, 15, 10, 9, 'B');
	Animal *test4 = new Animal(world, 15, 15, 8, 9, 'B');
	Animal *test5 = new Animal(world, 15, 15, 9, 10, 'B');
	world->insertOrganism(test);
	world->insertOrganism(test1);
	world->insertOrganism(test2);
	world->insertOrganism(test3);
	world->insertOrganism(test4);
	world->insertOrganism(test5);
	world->draw();
	int i = 0;
	while (true)
	{
		world->Tick();
		getchar();
	}
	delete world;
	return 0;
}
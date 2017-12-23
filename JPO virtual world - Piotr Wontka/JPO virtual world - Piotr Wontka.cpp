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
	system("cls");
	World *world = new World(20, 20);
	Animal *test = new Animal(world, 10, 10, 1, 1, 'A');
	Animal *test1 = new Animal(world, 9, 9, 20, 20, 'B');
	Animal *test2 = new Animal(world, 15, 15, 10, 5, 'C');
	Animal *test3 = new Animal(world, 20, 20, 10, 1, 'D');
	world->insertOrganism(test);
	world->insertOrganism(test1);
	world->insertOrganism(test2);
	world->insertOrganism(test3);
	world->draw();
	while (true)
	{
		world->Tick();
		getchar();
	}
	return 0;
}
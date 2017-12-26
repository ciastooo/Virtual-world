#include "Sheep.h"
#include "World.h"

Sheep::Sheep(World *world, int x, int y, bool canMove) : Animal(world, 4, 4, x, y, 'S', canMove)
{
}

Sheep::~Sheep() {

}
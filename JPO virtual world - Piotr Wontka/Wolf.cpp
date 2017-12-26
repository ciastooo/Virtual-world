#include "Wolf.h"
#include "World.h"

Wolf::Wolf(World *world, int x, int y, bool canMove): Animal(world, 9, 5, x, y, 'W', canMove)
{
}

Wolf::~Wolf() {

}
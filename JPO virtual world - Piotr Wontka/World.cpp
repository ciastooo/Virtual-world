#include "stdafx.h"
#include "World.h"

World::World()
{
	this->height = 20;
	this->width = 20;
}
World::World(int height, int width)
{
	this->height = height;
	this->width = width;
}
World::~World()
{
}
#pragma once
class World
{
private:
	int width;
	int height;
public:
	World();
	World(int, int);
	~World();
	int getWidth();
	int getheight();
};


#include "Food.h"



Food::Food()
{
	pos.x = rand() % 1260;
	pos.y = rand() % 700;
	texture.loadFromFile("leaf.png");
	sprite.setTexture(texture);
	sprite.setPosition(pos.x, pos.y);
	sprite.setScale(0.5, 0.5);
}


Food::~Food()
{
}
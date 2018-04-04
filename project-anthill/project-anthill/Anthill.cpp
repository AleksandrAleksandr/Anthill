#include "Anthill.h"



Anthill::Anthill()
{
	pos.x = 1280 / 2;
	pos.y = 720 / 2;
	texture.loadFromFile("earth.jpg");
	shape.setRadius(100);
	shape.setOrigin(shape.getRadius(), shape.getRadius());
	shape.setPosition(pos.x, pos.y);
	shape.setFillColor(sf::Color::Yellow);
	shape.setTexture(&texture);
}

Anthill::~Anthill()
{
}

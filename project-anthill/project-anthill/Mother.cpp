#include "Mother.h"



Mother::Mother(Anthill* anthill_)
{
	pos.x = anthill_->pos.x;
	pos.y = anthill_->pos.y;
	//std::cout << pos.x << " " << pos.y;
	texture.loadFromFile("ant.png");
	sprite.setTexture(texture);
	sprite.setScale(0.2, 0.2);
	sprite.setOrigin(texture.getSize().x*sprite.getScale().x / 2, texture.getSize().y*sprite.getScale().y / 2);
	sprite.setPosition(pos.x-70, pos.y-70);
}

void Mother::birth()
{
	int antNumber = rand() % 2;
	for (int i = 0; i <= antNumber; i++)
	{
		Ant* newAnt = new Ant(this);
		organisms->push_back(newAnt);
		newAnt->objects = objects;
	}
}

void Mother::Update()
{
	age++;
	if (food_amount == 2)
	{
		birth();
		food_amount = 0;
	}
	
}

void Mother::death(Ant* antToDeath)
{
	auto pos = std::find(organisms->begin(), organisms->end(), antToDeath);
	if (pos != organisms->end())
	{
		organisms->erase(pos);
		antToDeath->death();
	}
	
}

Mother::~Mother()
{
}

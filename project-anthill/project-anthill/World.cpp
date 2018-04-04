#include "World.h"



World::World()
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), "Anthill");	
}

void World::init()
{
	backgr.loadFromFile("background.png");
	background.setTexture(backgr);

	anthill = new Anthill;
	mother = new Mother(anthill);
	for (int i = 0; i < 10; i++)
	{
		objects.push_back(new Food);
	}

	/*for (int i = 0; i < 2; i++)
	{
		Ant ant1(mother);
		organisms.push_back(&ant1);
		ant1.objects = &objects;
	}*/
	
}

void World::start()
{
	for (int i = 0; i < 2; i++)
	{
		Ant* newAnt = new Ant(mother);
		organisms.push_back(newAnt);
		newAnt->objects = &objects;
	}
	mother->organisms = &organisms;
	mother->objects = &objects;
	for (int i = 0; i < 1; i++)
	{
		Enemy* newEnemy = new Enemy();
		enemies.push_back(newEnemy);
		newEnemy->organisms = &organisms;
	}

	int tic = 0;
	while (window->isOpen())
	{
		tic++;
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}
		}
		window->clear();
		if (tic == 10)
		{
			Update();
			tic = 0;
		}

		Draw();
		window->display();
	}
}

void World::AddObject(Object* obj)
{
	objects.push_back(obj);
}

void World::Update()
{
	for (auto i : organisms)
	{
		i->Update();
	}
	for (auto i : enemies)
	{
		i->Update();
	}
	mother->Update();
}

void World::Draw()
{
	window->draw(background);
	window->draw(anthill->shape);
	for (auto i : organisms)
	{
		window->draw(i->sprite);
	}
	for (auto i : enemies)
	{
		window->draw(i->sprite);
	}
	window->draw(mother->sprite);
	for (auto i : objects)
	{
		window->draw(i->sprite);
	}
}

World::~World()
{
}

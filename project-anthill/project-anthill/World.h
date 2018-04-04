#pragma once
#include "Object.h"
#include "Organism.h"
#include "vector"
#include "Anthill.h"
#include "Food.h"
#include "Ant.h"
#include "Mother.h"
#include "Enemy.h"
class World
{
	int width = 1280;
	int height = 720;
	sf::Sprite background;
	sf::Texture backgr;
	sf::RenderWindow* window;
	std::vector<Object*> objects;
	Anthill* anthill;
	Mother* mother;
	std::vector<Organism*> organisms;
	std::vector<Organism*> enemies;
	void Update();
	void Draw();
public:
	World();
	~World();
	void init();
	void start();
	void AddObject(Object* obj);
};


#pragma once
#include "Organism.h"

class Enemy : public Organism
{
public:
	Enemy();
	~Enemy();
	
	int birth_time = 20;
	int lifeTime = 1200;
	sf::Clock attack_delay;
	
	sf::Vector2f direction;
	int a;
	int radius = 10;
	int tic = 0;

	float findAnt();
	void attackAnt();
	bool onAttack = false;
	Organism* target;

	void Update();
	void death();
	//std::vector<Object*> *objects;
	std::vector<Organism*> *organisms;
};


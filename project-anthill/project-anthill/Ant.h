#pragma once
#include "Organism.h"
#include "Role.h"
#include "Mother.h"
#include "Hunter.h"
#include "Warrior.h"

class Warrior;
class Hunter;

class Ant : public Organism
{
	Mother* mother;
	int birth_time = 20;
	int lifeTime = 1200;
	int type;
	Role* role;
	Hunter* hunter;
	Warrior* warrior;
	bool haveRole = false;

	sf::Vector2f direction;
	int a;
	int radius = 10;
	int tic = 0;

	float findFood();
	float goHome();

	int foodPickedUp = 0;
	//int food_amount;
	Object* target;
public:
	void AssignRole(int type_);
	Ant(Mother* mother_);
	~Ant();

	void Update();
	void death();
	std::vector<Object*> *objects;
	//std::vector<Organism*> *organisms;
};


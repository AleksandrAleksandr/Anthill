#pragma once
#include "Organism.h"
#include "Anthill.h"

class Ant;

class Mother : public Organism
{
public:
	int food_amount;
	int wood_amount;
	std::vector<Organism*> *organisms;
	std::vector<Object*> *objects;

	void Update();
	void birth();
	void death(Ant* antToDeath);

	Mother(Anthill* anthill_);
	~Mother();
};

#include "Ant.h"

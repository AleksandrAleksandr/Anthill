#pragma once
#include "Object.h"
#include "vector"
class Hunter
{
public:
	Hunter();
	~Hunter();

	static const int speed = 4;
	static const int health = 3;
	int vision = 140;
	bool foodPickedUp;
	int food_amount;
	float findFood(std::vector<Object*> *objects, int x, int y);
	float goHome(std::vector<Object*> *objects, int x, int y);
	Object* target;

};


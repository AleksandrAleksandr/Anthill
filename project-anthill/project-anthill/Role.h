#pragma once
#include "Warrior.h"
#include "Hunter.h"
#include "vector"

class Role
{
public:
	Role();
	~Role();
	
	Warrior* warrior;
	Hunter* hunter;
};


#include "Organism.h"



Organism::Organism()
{
}


Organism::~Organism()
{
}

void Organism::DecreaseHP()
{
	health--;
}

int Organism::GetHp()
{
	return health;
}

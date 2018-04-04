#include "SFML\Graphics.hpp"
#include "World.h"
#include <stdlib.h>
#include <time.h>

void main()
{
	World world;
	world.init();
	srand(time(0));
	world.start();
}
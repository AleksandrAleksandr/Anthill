#include "Hunter.h"
#include "iostream"


Hunter::Hunter()
{
	foodPickedUp = false;
	food_amount = 0;
}


Hunter::~Hunter()
{
}

/*float Hunter::findFood(std::vector<Object*> *objects, int x, int y)
{
	//std::cout << foodPickedUp << std::endl;
	int nearFood = 1800;
	for (auto i = objects->begin(); i != objects->end(); i++) {
		sf::Vector2f foodPos = (*i)->sprite.getPosition();
		if (nearFood > sqrt(pow((*i)->pos.x - x, 2) + pow((*i)->pos.y - y, 2)))
		{
			nearFood = sqrt(pow((*i)->pos.x - x, 2) + pow((*i)->pos.y - y, 2));
			target = *i;
		}
	}

	if (nearFood > vision){return 0;}

	if (nearFood < 5)
	{
		foodPickedUp = true;
		goHome(objects, x, y);
		return 0;
	}
	else
	{
		sf::Vector2f food = target->sprite.getPosition();
		if (food.x >= x)
		{
			if (food.y < y)
			{
				return -atan(abs(food.y - y) / (food.x - x)) * 180 / 3.14;
			}
			return atan(abs(food.y - y) / (food.x - x)) * 180 / 3.14;
		}
		if (food.x < x)
		{
			if (food.y < y)
			{
				return 180 + atan(abs(food.y - y) / abs(food.x - x)) * 180 / 3.14;
			}
			return 180 - atan(abs(food.y - y) / abs(food.x - x)) * 180 / 3.14;
		}
	}
}

float Hunter::goHome(std::vector<Object*> *objects, int x, int y)
{
	if (sqrt(pow(1280/2 - x, 2) + pow(720/2 - y, 2)) < 90)
	{
		auto pos = std::find(objects->begin(), objects->end(), target);
		objects->erase(pos);
		delete target;
		food_amount++;
		system("cls");
		std::cout <<"food amount: "<<food_amount << std::endl;
		foodPickedUp = false;
		return 0;
	}

	target->sprite.setPosition(x, y);

	if (1280/2 > x)
	{
		if (720/2 < y)
		{
			return -atan(abs(720/2 - y) / (1280/2 - x)) * 180 / 3.14; //3
		}
		return atan(abs(720/2 - y) / (1280/2 - x)) * 180 / 3.14; //2
	}
	if (1280/2 < x)
	{
		if (720/2 < y)
		{
			return 180 + atan(abs(720/2 - y) / abs(1280/2 - x)) * 180 / 3.14; //4
		}
		return 180 - atan(abs(720/2 - y) / abs(1280/2 - x)) * 180 / 3.14; //1
	}
}*/
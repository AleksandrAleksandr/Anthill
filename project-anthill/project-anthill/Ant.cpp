#include "Ant.h"
#include "iostream"

Ant::Ant(Mother* mother_)
{
	mother = mother_;
	pos.x = mother_->pos.x - 40;
	pos.y = mother_->pos.y+20;
	
	texture.loadFromFile("egg.png");
	sprite.setTexture(texture);
	sprite.setScale(0.2, 0.2);
	sprite.setPosition(pos.x, pos.y);
	age = 0;
	a = rand() % 360;
	direction.x = cos(a * 3.14 / 180);
	direction.y = -sin(a * 3.14 / 180);
}

void Ant::Update()
{
	if (!haveRole) 
	{
		age++;
		sprite.setScale(sprite.getScale().x + 0.005, sprite.getScale().y + 0.005);
		if (age > birth_time)
		{
			type = rand() % 2;
			AssignRole(type);
			haveRole = true;
		}
	}
	else
	{
		age++;
		if (age > lifeTime)
			mother->death(this);

		if (health == 0)
			mother->death(this);

		tic++;
		if (tic == 5) {
			//std::cout << type << std::endl;
			/*a += rand() % (radius - (-radius) + 1) + (-radius);
			direction.x = cos(a * 3.14 / 180);
			direction.y = -sin(a * 3.14 / 180);
			tic = 0;
			pos.x += direction.x * speed;
			pos.y += direction.y * speed;
			sprite.setPosition(pos.x, pos.y);*/
			//if (type == 0) std::cout << "up\n";
			tic = 0;
			double a = rand() % (radius - (-radius) + 1) + (-radius);

			double pi = 3.14;
			double new_dir;
			new_dir = (a * (pi / 180));

			float alpha = abs(atan(float(this->direction.y / this->direction.x)));

			if (this->direction.x > 0 && this->direction.y > 0)
			{
				this->direction.x = cos(alpha - new_dir); // +
				this->direction.y = sin(alpha - new_dir); // +
			}
			else if (this->direction.x < 0 && this->direction.y > 0)
			{
				this->direction.x = -cos(alpha + new_dir); // - 
				this->direction.y = sin(alpha + new_dir); // +
			}
			else if (this->direction.x > 0 && this->direction.y < 0)
			{
				this->direction.x = cos(alpha + new_dir); //
				this->direction.y = -sin(alpha + new_dir); //
			}
			else if (this->direction.x < 0 && this->direction.y < 0)
			{
				this->direction.x = -cos(alpha - new_dir); //
				this->direction.y = -sin(alpha - new_dir); //
			}
			pos.x += direction.x * speed;
			pos.y += direction.y * speed;
			this->sprite.setPosition(pos.x, pos.y);

			return;
		}

		if (type == 0) 
		{
			if (foodPickedUp == 0)
			{
				//float foodDir = hunter->findFood(objects, pos.x, pos.y);
				float foodDir = findFood();
				if (foodDir != 0)
				{
					direction.x = cos(foodDir * 3.14 / 180);
					direction.y = sin(foodDir * 3.14 / 180);
				}
			}
			else
			{
				//float homeDir = hunter->goHome(objects, pos.x, pos.y);
				float homeDir = goHome();
				//std::cout << homeDir << std::endl;
				if (homeDir != 0)
				{
					direction.x = cos(homeDir * 3.14 / 180);
					direction.y = sin(homeDir * 3.14 / 180);
				}
			}
		}

		if (pos.x > 1280 - 10 || pos.y > 720 - 10 || pos.x < 1 || pos.y < 1)
		{
			if (pos.x > 1280 - 10)
			{
				int a = rand() % (260 - 100) + 100;
				direction.x = cos(a * 3.14 / 180);
				direction.y = sin(a * 3.14 / 180);
			}
			else if (pos.x < 1)
			{
				int a = rand() % (80 + 80) + (-80);
				direction.x = cos(a * 3.14 / 180);
				direction.y = sin(a * 3.14 / 180);
			}
			else if (pos.y < 1)
			{
				int a = rand() % (170 - 10) + 10;
				direction.x = cos(a * 3.14 / 180);
				direction.y = sin(a * 3.14 / 180);
			}
			else if (pos.y > 720 - 10)
			{
				int a = rand() % (350 + 190) + 190;
				direction.x = cos(a * 3.14 / 180);
				direction.y = sin(a * 3.14 / 180);
			}
			/*direction.x = direction.x * (-1);
			direction.y = direction.y * (-1);*/
		}

		pos.x += direction.x * speed;
		pos.y += direction.y * speed;
		sprite.setPosition(pos.x, pos.y);
	}
}

float Ant::goHome()
{
	if (sqrt(pow(1280 / 2 - pos.x, 2) + pow(720 / 2 - pos.y, 2)) < 90)
	{
		auto pos = std::find(objects->begin(), objects->end(), target);
		objects->erase(pos);
		delete target;
		//food_amount++;system("cls");std::cout << "food amount: " << food_amount << std::endl;
		mother->food_amount++;
		foodPickedUp = 0;
		return 0;
	}

	target->sprite.setPosition(pos.x, pos.y);

	if (1280 / 2 > pos.x)
	{
		if (720 / 2 < pos.y)
		{
			return -atan(abs(720 / 2 - pos.y) / (1280 / 2 - pos.x)) * 180 / 3.14; //3
		}
		return atan(abs(720 / 2 - pos.y) / (1280 / 2 - pos.x)) * 180 / 3.14; //2
	}
	if (1280 / 2 < pos.x)
	{
		if (720 / 2 < pos.y)
		{
			return 180 + atan(abs(720 / 2 - pos.y) / abs(1280 / 2 - pos.x)) * 180 / 3.14; //4
		}
		return 180 - atan(abs(720 / 2 - pos.y) / abs(1280 / 2 - pos.x)) * 180 / 3.14; //1
	}
}

float Ant::findFood()
{
	//std::cout << foodPickedUp << std::endl;
	int nearFood = 1800;
	for (auto i = objects->begin(); i != objects->end(); i++) {
		sf::Vector2f foodPos = (*i)->sprite.getPosition();
		if (nearFood > sqrt(pow((*i)->pos.x - pos.x, 2) + pow((*i)->pos.y - pos.y, 2)))
		{
			nearFood = sqrt(pow((*i)->pos.x - pos.x, 2) + pow((*i)->pos.y - pos.y, 2));
			target = *i;
		}
	}

	if (nearFood > 140) { return 0; }

	if (nearFood < 5)
	{
		foodPickedUp = 1;
		goHome();
		return 0;
	}
	else
	{
		sf::Vector2f food = target->sprite.getPosition();
		if (food.x >= pos.x)
		{
			if (food.y < pos.y)
			{
				return -atan(abs(food.y - pos.y) / (food.x - pos.x)) * 180 / 3.14;
			}
			return atan(abs(food.y - pos.y) / (food.x - pos.x)) * 180 / 3.14;
		}
		if (food.x < pos.x)
		{
			if (food.y < pos.y)
			{
				return 180 + atan(abs(food.y - pos.y) / abs(food.x - pos.x)) * 180 / 3.14;
			}
			return 180 - atan(abs(food.y - pos.y) / abs(food.x - pos.x)) * 180 / 3.14;
		}
	}
}

void Ant::AssignRole(int type_)
{
	if (type_ == 0)
	{
		//hunter = new Hunter;
		//hunter->objects = objects;
		speed = Hunter::speed;
		health = Hunter::health;
		texture.loadFromFile("antRed.png");
		sprite.setTexture(texture);
		sprite.setScale(0.2, 0.2);
	}
	else
	{
		//warrior = new Warrior;
		//warrior->objects = objects;
		speed = Warrior::speed;
		health = Warrior::health;
		texture.loadFromFile("ant1.png");
		sprite.setTexture(texture);
		sprite.setScale(0.2, 0.2);
	}
}

void Ant::death()
{
	//delete this;
}

Ant::~Ant()
{
}



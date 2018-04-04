#include "Enemy.h"

Enemy::Enemy()
{
	pos.x = rand() % 1260;
	pos.y = rand() % 700;

	texture.loadFromFile("caterpillar.png");
	sprite.setTexture(texture);
	sprite.setScale(0.14, 0.14);
	sprite.setPosition(pos.x, pos.y);
	age = 0;
	speed = 5;
	a = rand() % 360;
	direction.x = cos(a * 3.14 / 180);
	direction.y = -sin(a * 3.14 / 180);
	attack_delay.restart();
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	age++;
	/*if (age > lifeTime)
		mother->death(this);

	if (health == 0)
		mother->death(this);*/

	tic++;
	// Change Direction
	if (tic == 5) {
		//std::cout << age << std::endl;
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

	// Finding and Attacking Ants
		if (onAttack == false)
		{
			float antDir = findAnt();
			if (antDir != 0)
			{
				direction.x = cos(antDir * 3.14 / 180);
				direction.y = sin(antDir * 3.14 / 180);
			}
		}
		else
		{
			if (attack_delay.getElapsedTime().asSeconds() > 2)
			{
				attackAnt();
				onAttack = false;
			}
		}

	// Check Edges
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

float Enemy::findAnt()
{
	//std::cout << foodPickedUp << std::endl;
	int nearAnt = 1800;
	for (auto i = organisms->begin(); i != organisms->end(); i++) {
		//sf::Vector2f foodPos = (*i)->sprite.getPosition();
		if (nearAnt > sqrt(pow((*i)->pos.x - pos.x, 2) + pow((*i)->pos.y - pos.y, 2)))
		{
			nearAnt = sqrt(pow((*i)->pos.x - pos.x, 2) + pow((*i)->pos.y - pos.y, 2));
			target = *i;
		}
	}

	if (nearAnt > 100) { return 0; }

	if (nearAnt < 5)
	{
		onAttack = true;
		//attackAnt();
		return 0;
	}
	else
	{
		sf::Vector2f targetAnt = target->sprite.getPosition();
		if (targetAnt.x >= pos.x)
		{
			if (targetAnt.y < pos.y)
			{
				return -atan(abs(targetAnt.y - pos.y) / (targetAnt.x - pos.x)) * 180 / 3.14;
			}
			return atan(abs(targetAnt.y - pos.y) / (targetAnt.x - pos.x)) * 180 / 3.14;
		}
		if (targetAnt.x < pos.x)
		{
			if (targetAnt.y < pos.y)
			{
				return 180 + atan(abs(targetAnt.y - pos.y) / abs(targetAnt.x - pos.x)) * 180 / 3.14;
			}
			return 180 - atan(abs(targetAnt.y - pos.y) / abs(targetAnt.x - pos.x)) * 180 / 3.14;
		}
	}
}

void Enemy::attackAnt()
{
	std::cout << "Attackk!!\n";
	target->DecreaseHP();
	if (target->GetHp() == 0)
		onAttack = false;
	attack_delay.restart();
}

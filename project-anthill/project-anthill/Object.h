#pragma once
#include "SFML\Graphics.hpp"
#include "time.h"

class Object
{
protected:
	
	sf::Texture texture;
	
public:
	sf::CircleShape shape;
	sf::Vector2i pos;
	sf::Sprite sprite;
	Object();
	~Object();
};


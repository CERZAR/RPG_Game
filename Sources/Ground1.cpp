
#include "../Headers/Ground1.h"

Ground1::Ground1(sf::Sprite* sprite, float x, float y) : MapObject::MapObject(sprite, x, y)
{
	isExist = true;
	type = GROUND;

	this->sprite.setTextureRect(sf::IntRect(0, 50, 50, 50));
	this->sprite.setPosition(rect.getPosition());
}


Ground1::~Ground1()
{
}

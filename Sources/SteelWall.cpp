
#include "../Headers/SteelWall.h"

SteelWall::SteelWall(sf::Sprite* sprite, float x, float y) : MapObject::MapObject(sprite, x, y)
{
	isExist = true;
	type = WALL;

	this->sprite.setTextureRect(sf::IntRect(50, 0, 50, 50));
	this->sprite.setPosition(rect.getPosition());
}


SteelWall::~SteelWall()
= default;

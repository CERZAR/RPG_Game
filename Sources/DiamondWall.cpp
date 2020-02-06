
#include "../Headers/DiamondWall.h"

DiamondWall::DiamondWall(sf::Sprite* sprite, float x, float y) : MapObject::MapObject(sprite, x, y)
{
	isExist = true;
	type = WALL;

	this->sprite.setTextureRect(sf::IntRect(100, 0, 50, 50));
	this->sprite.setPosition(rect.getPosition());
}


DiamondWall::~DiamondWall()
{
}

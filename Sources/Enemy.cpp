
#include "../Headers/Enemy.h"

void Enemy::initVariables()
{
	isExist = true;
	isAgro = false;
	direction = GenerateRandomInt0(4);

	text.setFont(*resContainter->pixel_font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color(230, 30, 0));
}

Enemy::Enemy(ResourcesContainer* res) : Object::Object(res)
{
}

void Enemy::update(int playerX, int playerY)
{
}

Enemy::~Enemy()
{
}

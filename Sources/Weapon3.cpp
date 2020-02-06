
#include "../Headers/Weapon3.h"


Weapon3::Weapon3(ResourcesContainer* res) : Weapon::Weapon(res)
{
	isExist = true;
	type = WEAPON;

	level = 1;
	atackSpeed = 1000;
	upgateCost = 10;
	damage = 1;
	speed = 3.f;
	lifetime = 5000000;

	rect.setSize(sf::Vector2f(56, 19));
	rect.setOutlineThickness(1.f);
	rect.setFillColor(sf::Color::Transparent);

	sprite.setTextureRect(sf::IntRect(0, 0, 40, 19));
	iconSprite = *resContainter->iconWeapon3[0];
}


Weapon3::~Weapon3()
= default;

void Weapon3::update()
{
	sprite = *resContainter->weapon3[level - 1];
	sprite.setPosition(rect.getPosition());
	iconSprite = *resContainter->iconWeapon3[level - 1];
	switch (level)
	{
	case 1:
	{
		rect.setOutlineColor(sf::Color(0, 0, 255, 155));
		break;
	}
	case 2:
	{
		rect.setOutlineColor(sf::Color(148, 0, 211, 155));
		break;
	}
	case 3:
	{
		rect.setOutlineColor(sf::Color(255, 0, 255, 155));
		break;
	}
	case 4:
	{
		rect.setOutlineColor(sf::Color(255, 140, 0, 155));
		break;
	}
	case 5:
	{
		rect.setOutlineColor(sf::Color(255, 0, 0, 155));
		break;
	}
	default:
		break;
	}
}

void Weapon3::render(sf::RenderTarget * target)
{
	target->draw(rect);
	Item::render(target);
}

void Weapon3::updateStats()
{
	switch (level)
	{
	case 2:
	{
		atackSpeed = 900;
		upgateCost = 20;
		damage = 2;
		speed = 4.f;
		lifetime = 5000000;
		break;
	}
	case 3:
	{
		atackSpeed = 800;
		upgateCost = 30;
		damage = 2;
		speed = 5.f;
		lifetime = 5000000;
		break;
	}
	case 4:
	{
		atackSpeed = 700;
		upgateCost = 40;
		damage = 3;
		speed = 5.f;
		lifetime = 5000000;
		break;
	}
	case 5:
	{
		atackSpeed = 600;
		upgateCost = -1;
		damage = 4;
		speed = 5.f;
		lifetime = 5000000;
		break;
	}
	default:
		break;
	}
}

Bullet * Weapon3::getBullet(int direction)
{
	Bullet* bullet = new Bullet3(this->damage, this->speed, direction, this->lifetime, resContainter);
	return bullet;
}


#include "../Headers/Bullet.h"

Bullet::Bullet(ResourcesContainer* res) : Object::Object(res)
{
	isExist = true;
	startTime = static_cast<float>(clock());
	lifetime = 1000;

	this->hp = 0;
	this->damage = 1;
	this->movementSpeed = 10.f;

	rect.setSize(sf::Vector2f(2, 20));
	rect.setFillColor(sf::Color::Magenta);
}

Bullet::Bullet(int damage, float speed, int direction, float lifetime, ResourcesContainer* res) : Object::Object(res)
{
	isExist = true;
	startTime = static_cast<float>(clock());

	rect.setFillColor(sf::Color::Magenta);

	this->hp = 0;
	this->damage = damage;
	this->movementSpeed = speed;
	this->direction = direction;
	this->lifetime = lifetime;
}

Bullet::~Bullet()
{
}

void Bullet::update()
{
	if (clock() - startTime >= lifetime)
		isExist = false;
}

void Bullet::render(sf::RenderTarget * target)
{
	target->draw(this->sprite);
	//target->draw(this->rect);
}

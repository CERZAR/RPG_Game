#include "../Headers/Bullet1.h"


Bullet1::Bullet1(int damage, float speed, int direction, float lifetime, ResourcesContainer* res) : Bullet::Bullet(damage, speed, direction, lifetime, res)
{
	rect.setSize(sf::Vector2f(25, 25));
}


Bullet1::~Bullet1()
{
}

void Bullet1::update()
{
	Bullet::update();

	if (this->direction == UP)
	{
		this->rect.move(0, -1 * this->movementSpeed);
		sprite = *resContainter->bullet1[counterAnimation];
		sprite.setRotation(90);
		sprite.setPosition(rect.getPosition().x + 45, rect.getPosition().y - 5);
	}
	else if (this->direction == DOWN)
	{
		this->rect.move(0, this->movementSpeed);
		sprite = *resContainter->bullet1[counterAnimation];
		sprite.setRotation(270);
		sprite.setPosition(rect.getPosition().x - 22, rect.getPosition().y + 30);
	}
	else if (this->direction == RIGHT)
	{
		this->rect.move(this->movementSpeed, 0);
		sprite = *resContainter->bullet1[counterAnimation];
		sprite.setRotation(180);
		sprite.setPosition(rect.getPosition().x + 30, rect.getPosition().y + 46);
	}
	else if (this->direction == LEFT)
	{
		this->rect.move(-1 * this->movementSpeed, 0);
		sprite = *resContainter->bullet1[counterAnimation];
		sprite.setPosition(rect.getPosition().x - 4, rect.getPosition().y - 20);
	}

	animationSlow++;
	if (animationSlow == 5)
	{
		counterAnimation++;
		animationSlow = 0;
	}

	if (counterAnimation == 5)
	{
		counterAnimation = 0;
	}
}

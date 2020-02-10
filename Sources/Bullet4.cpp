// Copyright 2019 CERZAR
#include "../Headers/Bullet4.h"

Bullet4::Bullet4(int damage, float speed, int direction, float lifetime,
                 ResourcesContainer *res)
    : Bullet::Bullet(damage, speed, direction, lifetime, res) {
  rect.setSize(sf::Vector2f(8, 8));

  sprite = *resContainter->bullet4;
  sprite.setTextureRect(sf::IntRect(0, 0, 16, 19));
}

Bullet4::~Bullet4() {}

void Bullet4::update() {
  Bullet::update();

  if (this->direction == UP) {
    this->rect.move(0, -1 * this->movementSpeed);
    this->sprite.setTextureRect(
        sf::IntRect(this->counterAnimation * 16, 0, 16, 19));
    sprite.setPosition(rect.getPosition().x - 4, rect.getPosition().y - +4);
  } else if (this->direction == DOWN) {
    this->rect.move(0, this->movementSpeed);
    this->sprite.setTextureRect(
        sf::IntRect(this->counterAnimation * 16, 0, 16, 19));
    sprite.setPosition(rect.getPosition().x - 4, rect.getPosition().y - 4);
  } else if (this->direction == RIGHT) {
    this->rect.move(this->movementSpeed, 0);
    this->sprite.setTextureRect(
        sf::IntRect(this->counterAnimation * 16, 0, 16, 19));
    sprite.setPosition(rect.getPosition().x - 5, rect.getPosition().y - 5);
  } else if (this->direction == LEFT) {
    this->rect.move(-1 * this->movementSpeed, 0);
    this->sprite.setTextureRect(
        sf::IntRect(this->counterAnimation * 16, 0, 16, 19));
    sprite.setPosition(rect.getPosition().x - 4, rect.getPosition().y - 6);
  }

  animationSlow++;
  if (animationSlow == 30) {
    counterAnimation++;
    animationSlow = 0;
  }

  if (counterAnimation == 2) {
    counterAnimation = 0;
  }
}

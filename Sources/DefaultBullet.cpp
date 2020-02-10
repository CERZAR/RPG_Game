// Copyright 2019 CERZAR
#include "../Headers/DefaultBullet.h"

DefaultBullet::DefaultBullet(int damage, float speed, int direction,
                             float lifetime, ResourcesContainer *res)
    : Bullet::Bullet(damage, speed, direction, lifetime, res) {
  rect.setSize(sf::Vector2f(10, 20));

  sprite = *resContainter->defaultBullet;
  sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
}

DefaultBullet::~DefaultBullet() {}

void DefaultBullet::update() {
  Bullet::update();

  if (this->direction == UP) {
    this->rect.move(0, -1 * this->movementSpeed);
    this->sprite.setTextureRect(
        sf::IntRect(this->counterAnimation * 64, 64 * 2, 64, 64));
    sprite.setPosition(rect.getPosition().x - 28, rect.getPosition().y - 15);
  } else if (this->direction == DOWN) {
    this->rect.move(0, this->movementSpeed);
    this->sprite.setTextureRect(
        sf::IntRect(this->counterAnimation * 64, 64 * 6, 64, 64));
    sprite.setPosition(rect.getPosition().x - 28, rect.getPosition().y - 32);
  } else if (this->direction == RIGHT) {
    this->rect.move(this->movementSpeed, 0);
    this->sprite.setTextureRect(
        sf::IntRect(this->counterAnimation * 64, 64 * 4, 64, 64));
    sprite.setPosition(rect.getPosition().x - 49, rect.getPosition().y - 20);
  } else if (this->direction == LEFT) {
    this->rect.move(-1 * this->movementSpeed, 0);
    this->sprite.setTextureRect(
        sf::IntRect(this->counterAnimation * 64, 64 * 0, 64, 64));
    sprite.setPosition(rect.getPosition().x - 7, rect.getPosition().y - 20);
  }

  animationSlow++;
  if (animationSlow == 30) {
    counterAnimation++;
    animationSlow = 0;
  }

  if (counterAnimation == 7) {
    counterAnimation = 0;
  }
}

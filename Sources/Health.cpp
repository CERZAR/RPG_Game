// Copyright 2019 CERZAR
#include "../Headers/Health.h"

Health::Health(ResourcesContainer *res) : Item::Item(res) {
  isExist = true;
  type = HEALTH;

  rect.setSize(sf::Vector2f(10, 10));
  rect.setFillColor(sf::Color::White);
  sprite.setTextureRect(sf::IntRect(0, 0, 40, 40));
}

Health::~Health() {}

void Health::update() {
  sprite = *resContainter->item_health[counterAnimation];
  sprite.setPosition(rect.getPosition().x - 15, rect.getPosition().y - 15);

  animationSlow++;
  if (animationSlow == 7) {
    counterAnimation++;
    animationSlow = 0;
  }

  if (counterAnimation == 8) {
    counterAnimation = 1;
  }
}

// Copyright 2019 CERZAR
#include "../Headers/Energy.h"

Energy::Energy(ResourcesContainer *res) : Item::Item(res) {
  isExist = true;
  type = ENERGY;

  rect.setSize(sf::Vector2f(10, 10));
  rect.setFillColor(sf::Color::White);
  sprite.setTextureRect(sf::IntRect(0, 0, 40, 40));
}

Energy::~Energy() {}

void Energy::update() {
  sprite = *resContainter->item_energy[counterAnimation];
  sprite.setPosition(rect.getPosition().x - 15, rect.getPosition().y - 15);

  animationSlow++;
  if (animationSlow == 7) {
    counterAnimation++;
    animationSlow = 0;
  }

  if (counterAnimation == 10) {
    counterAnimation = 1;
  }
}

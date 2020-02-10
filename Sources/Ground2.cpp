// Copyright 2019 CERZAR
#include "../Headers/Ground2.h"

Ground2::Ground2(sf::Sprite *sprite, float x, float y)
    : MapObject::MapObject(sprite, x, y) {
  isExist = true;
  type = GROUND;

  this->sprite.setTextureRect(sf::IntRect(50, 50, 50, 50));
  this->sprite.setPosition(rect.getPosition());
}

Ground2::~Ground2() {}

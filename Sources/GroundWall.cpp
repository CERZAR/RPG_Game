// Copyright 2019 CERZAR
#include "../Headers/GroundWall.h"

GroundWall::GroundWall(sf::Sprite *sprite, float x, float y)
    : MapObject::MapObject(sprite, x, y) {
  isExist = true;
  type = WALL;

  this->sprite.setTextureRect(sf::IntRect(150, 0, 50, 50));
  this->sprite.setPosition(rect.getPosition());
}

GroundWall::~GroundWall() {}


#include "../Headers/Ground3.h"

Ground3::Ground3(sf::Sprite *sprite, float x, float y)
    : MapObject::MapObject(sprite, x, y) {
  isExist = true;
  type = GROUND;

  this->sprite.setTextureRect(sf::IntRect(100, 50, 50, 50));
  this->sprite.setPosition(rect.getPosition());
}

Ground3::~Ground3() {}

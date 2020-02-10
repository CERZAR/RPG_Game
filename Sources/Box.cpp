#include "../Headers/Box.h"

Box::Box(sf::Sprite *sprite, float x, float y)
    : MapObject::MapObject(sprite, x, y) {
  isExist = true;
  type = BOX;
  hp = 3;

  rect.setFillColor(sf::Color::Yellow);

  this->sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
  this->sprite.setPosition(rect.getPosition());
}

Box::~Box() = default;

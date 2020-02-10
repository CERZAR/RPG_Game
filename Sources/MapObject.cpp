
#include "../Headers/MapObject.h"

MapObject::MapObject(sf::Sprite *sprite, float x, float y) {
  this->sprite = *sprite;
  rect.setPosition(x, y);
  rect.setSize(sf::Vector2f(50, 50));
}

MapObject::~MapObject() {}

void MapObject::redner(sf::RenderTarget *target) {
  // target->draw(sprite);
  target->draw(rect);
}


#include "../Headers/Weapon.h"

Weapon::Weapon(ResourcesContainer *res) : Item::Item(res) {}

Weapon::~Weapon() = default;

void Weapon::update() {}

void Weapon::setPosition(sf::Vector2f pos) {
  rect.setPosition(pos);
  sprite.setPosition(rect.getPosition());
}

sf::Sprite Weapon::getIcon() { return iconSprite; }

void Weapon::updateOutline() {
  switch (level) {
  case 1: {
    rect.setOutlineColor(sf::Color(0, 0, 255, 155));
    break;
  }
  case 2: {
    rect.setOutlineColor(sf::Color(148, 0, 211, 155));
    break;
  }
  case 3: {
    rect.setOutlineColor(sf::Color(255, 0, 255, 155));
    break;
  }
  case 4: {
    rect.setOutlineColor(sf::Color(255, 140, 0, 155));
    break;
  }
  case 5: {
    rect.setOutlineColor(sf::Color(255, 0, 0, 155));
    break;
  }
  default:
    break;
  }
}

void Weapon::updateLevel() {
  if (level < 5)
    level++;
}

Bullet *Weapon::getBullet(int direction) {
  Bullet *bullet = new DefaultBullet(2, 10.f, direction, 1000, resContainter);
  return bullet;
}

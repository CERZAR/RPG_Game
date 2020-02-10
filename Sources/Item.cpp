
#include "../Headers/Item.h"

Item::Item(ResourcesContainer *res) { this->resContainter = res; }

Item::~Item() {}

void Item::render(sf::RenderTarget *target) {
  target->draw(this->sprite);
  // target->draw(this->rect);
}

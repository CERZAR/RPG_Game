
#include "../Headers/CollisionText.h"

CollisionText::CollisionText(std::string text, std::string font_path, int size,
                             float lifetime)
    : textDisplay::textDisplay(text, font_path, size, lifetime) {
  this->transparency = 255;
}

CollisionText::~CollisionText() {}

void CollisionText::update() {
  text.move(0, -1.5f);
  color.a -= 1;
  text.setFillColor(color);
  if (color.a == 0)
    isExist = false;
}

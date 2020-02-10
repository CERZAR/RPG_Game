#ifndef BOX_H
#define BOX_H

#include "MapObject.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Box : public MapObject {
public:
  Box(sf::Sprite *sprite, float x, float y);

  virtual ~Box();
};

#endif // BOX_H

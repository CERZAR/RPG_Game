#ifndef ITEM
#define ITEM

#include "../Headers/ResourcesContainer.h"
#include "Random.h"
#include "ResourcesContainer.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

enum { COIN, HEALTH, ENERGY, WEAPON, BOOSTER };

class Item {
protected:
  ResourcesContainer *resContainter;

public:
  // Variables
  bool isExist;
  int type;
  sf::Texture texture;
  sf::RectangleShape rect;
  sf::Sprite sprite;

  // Functions
  Item(ResourcesContainer *res);

  virtual ~Item();

  virtual void update() = 0;

  virtual void render(sf::RenderTarget *target);
};

#endif // ITEM

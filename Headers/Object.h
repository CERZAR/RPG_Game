#ifndef OBJECT_H
#define OBJECT_H

#include "../Headers/ResourcesContainer.h"
#include "Random.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

class Object {
protected:
  // Directions
  enum { UP, DOWN, RIGHT, LEFT };
  ResourcesContainer *resContainter;
  // virtual void initVariables() = 0;
  // virtual void initStats() = 0;
public:
  // Variables
  bool isExist;
  int direction;
  sf::Texture texture;
  sf::RectangleShape rect;
  sf::Sprite sprite;
  sf::Text text;
  // Stats
  int maxHP;
  int hp;
  int damage;
  float movementSpeed;

  // Functions
  Object(ResourcesContainer *res);

  virtual ~Object();

  virtual void update(){};

  virtual void render(sf::RenderTarget *target);
};

#endif // OBJECT_H

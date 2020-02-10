/**
 * @file Weapon3.h
 * @brief A file containing a description of the weapon3 class
 */
#pragma once

#include "../Headers/Bullet3.h"
#include "Weapon.h"

/**
 * @brief weapon3 class
 */
class Weapon3 : public Weapon {
public:
  Weapon3(ResourcesContainer *res);

  virtual ~Weapon3();

  void update();

  void render(sf::RenderTarget *target);

  void updateStats();

  Bullet *getBullet(int direction);
};

/**
 * @file DefaultWeapon.h
 * @brief A file containing a description of the default weapon class
 */
#ifndef DEFAULTWEAPON_H
#define DEFAULTWEAPON_H

#include "DefaultBullet.h"
#include "Weapon.h"

/**
 * @brief default weapon class
 */
class DefaultWeapon : public Weapon {
public:
  DefaultWeapon(ResourcesContainer *res);

  virtual ~DefaultWeapon();

  void update();

  void render(sf::RenderTarget *target);

  void updateStats();

  Bullet *getBullet(int direction);
};

#endif // DEFAULTWEAPON_H

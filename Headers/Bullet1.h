#pragma once

#include "Bullet.h"

class Bullet1 : public Bullet {
public:
  Bullet1(int damage, float speed, int direction, float lifetime,
          ResourcesContainer *res);

  virtual ~Bullet1();

  void update();
};

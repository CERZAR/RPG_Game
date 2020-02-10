#pragma once

#include "Bullet.h"

class Bullet4 : public Bullet {
public:
  Bullet4(int damage, float speed, int direction, float lifetime,
          ResourcesContainer *res);

  virtual ~Bullet4();

  void update();
};

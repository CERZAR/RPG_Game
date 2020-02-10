#pragma once

#include "Item.h"

class Health : public Item {
private:
  // Variables
  int counterAnimation = 1;
  int animationSlow = 0;

public:
  Health(ResourcesContainer *res);

  virtual ~Health();

  void update();
};

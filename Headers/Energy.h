#pragma once

#include "Item.h"

class Energy : public Item {
  // Variables
  int counterAnimation = 1;
  int animationSlow = 0;

public:
  Energy(ResourcesContainer *res);

  virtual ~Energy();

  void update();
};

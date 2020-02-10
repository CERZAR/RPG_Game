#ifndef COINS
#define COINS

#include "Item.h"

class Coin : public Item {
private:
  // Variables
  int counterAnimation = 1;
  int animationSlow = 0;

public:
  Coin(ResourcesContainer *res);

  virtual ~Coin();

  void update();
};

#endif // COINS

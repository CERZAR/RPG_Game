#ifndef BULLET_H
#define BULLET_H

#include "Object.h"

class Bullet : public Object {
protected:
  // Variables
  float startTime;
  int counterAnimation = 0;
  int animationSlow = 0;

public:
  // Variables
  float lifetime;
  bool isPlayerBullet;

  // Functions
  Bullet(ResourcesContainer *res);

  Bullet(int damage, float speed, int direction, float lifetime,
         ResourcesContainer *res);

  virtual ~Bullet();

  virtual void update();

  void render(sf::RenderTarget *target);
};

#endif // BULLET_H

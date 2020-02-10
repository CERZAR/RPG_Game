#ifndef GROUND1_H
#define GROUND1_H

#include "MapObject.h"

class Ground1 : public MapObject {
public:
  Ground1(sf::Sprite *sprite, float x, float y);

  virtual ~Ground1();
};

#endif // GROUND1_H

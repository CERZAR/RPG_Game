#ifndef GROUNDWALL_H
#define GROUNDWALL_H

#include "MapObject.h"

class GroundWall : public MapObject {
public:
  GroundWall(sf::Sprite *sprite, float x, float y);

  virtual ~GroundWall();
};

#endif // GROUNDWALL_H

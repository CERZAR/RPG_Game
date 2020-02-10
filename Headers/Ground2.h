#ifndef GROUND2_H
#define GROUND2_H

#include "MapObject.h"

class Ground2 : public MapObject {
public:
  Ground2(sf::Sprite *sprite, float x, float y);

  ~Ground2() override;
};

#endif // GROUND2_H

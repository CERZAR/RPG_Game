#ifndef DIAMONDWALL_H
#define DIAMONDWALL_H

#include "MapObject.h"

class DiamondWall :
        public MapObject {
public:
    DiamondWall(sf::Sprite *sprite, float x, float y);

    virtual ~DiamondWall();
};

#endif //DIAMONDWALL_H

#ifndef GROUND3_H
#define GROUND3_H

#include "MapObject.h"

class Ground3 :
        public MapObject {
public:
    Ground3(sf::Sprite *sprite, float x, float y);

    virtual ~Ground3();
};

#endif //GROUND3_H

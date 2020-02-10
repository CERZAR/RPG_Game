#pragma once

#include "Bullet.h"

class Bullet2 :
        public Bullet {
public:
    Bullet2(int damage, float speed, int direction, float lifetime,
            ResourcesContainer *res);

    virtual ~Bullet2();

    void update();
};


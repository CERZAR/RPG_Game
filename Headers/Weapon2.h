/**
 * @file Weapon2.h
 * @brief A file containing a description of the weapon2 class
 */
#pragma once

#include "Weapon.h"
#include "../Headers/Bullet2.h"

/**
 * @brief weapon2 class
 */
class Weapon2 :
        public Weapon {
public:
    Weapon2(ResourcesContainer *res);

    virtual ~Weapon2();

    void update();

    void render(sf::RenderTarget *target);

    void updateStats();

    Bullet *getBullet(int direction);
};


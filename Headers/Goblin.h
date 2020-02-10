#pragma once

#include "Enemy.h"

class Goblin :
        public Enemy {
private:
    // Functions
    void initVariables();

    void initStats();

public:
    Goblin(ResourcesContainer *res);

    virtual ~Goblin();

    void update();

    void render(sf::RenderTarget *target);
};


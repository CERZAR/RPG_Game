#ifndef GREENJELLY_H
#define GREENJELLY_H

#include "Enemy.h"

class GreenJelly :
        public Enemy {
private:
    // Functions
    void initVariables();

    void initStats();

public:
    GreenJelly(ResourcesContainer *res);

    virtual ~GreenJelly();

    void update(int playerX, int playerY);

    void render(sf::RenderTarget *target);
};


#endif //GREENJELLY_H

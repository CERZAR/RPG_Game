/**
 * @file Weapon.h
 * @brief A file containing a description of the weapon class
 */
#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
#include "../Headers/DefaultBullet.h"

/**
 * @brief weapon class
 */
class Weapon :
        public Item {
public:
    int level{};
    int atackSpeed{};
    int upgateCost{};
    // bulet variables
    int damage{};
    float speed{};
    float lifetime{};

    sf::Sprite iconSprite;

    Weapon(ResourcesContainer *res);

    virtual ~Weapon();

    virtual void update();

    void setPosition(sf::Vector2f pos);

    sf::Sprite getIcon();

    void updateOutline();

    void updateLevel();

    virtual Bullet *getBullet(int direction);

    virtual void updateStats() {};
};


#endif //WEAPON_H

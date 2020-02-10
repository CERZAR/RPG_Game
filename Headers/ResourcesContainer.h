/**
 * @file resourcesContainer.h
 * @brief A file containing a description of the ResourcesContainer class
 */
#ifndef RESOURCESCONTAINER_H
#define RESOURCESCONTAINER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

/**
 * @brief resourcesContainer class
 */
class ResourcesContainer {
public:
    sf::Texture *texture; ///< texture

    sf::Font *pixel_font; ///< font for texts
    sf::Sprite *icon; ///< sprite for player icon
    // Enemis
    sf::Sprite *greenJelly;      ///< sprite for greenjelly
    sf::Sprite *enemiesSheet1;      ///< sprite enemy
    // Items
    std::vector<sf::Sprite *> item_coin;          ///< sprite for player icon
    std::vector<sf::Sprite *> item_health;      ///< sprite for player icon
    std::vector<sf::Sprite *> item_energy;      ///< sprite for player icon
    // Weapons
    std::vector<sf::Sprite *> defaultWeapon;          ///< sprite for defaul weapon
    std::vector<sf::Sprite *> weapon1;              ///< sprite for weapon1
    std::vector<sf::Sprite *> weapon2;              ///< sprite for weapon2
    std::vector<sf::Sprite *> weapon3;              ///< sprite for weapon3
    std::vector<sf::Sprite *> weapon4;              ///< sprite for weapon4
    // Weapons icon for backpack
    std::vector<sf::Sprite *> iconDefaultWeapon;      ///< sprite for default weapon icon
    std::vector<sf::Sprite *> iconWeapon1;          ///< sprite for weapon1 icon
    std::vector<sf::Sprite *> iconWeapon2;          ///< sprite for weapon2 icon
    std::vector<sf::Sprite *> iconWeapon3;          ///< sprite for weapon3 icon
    std::vector<sf::Sprite *> iconWeapon4;          ///< sprite for weapon4 icon
    // Bullets
    sf::Sprite *defaultBullet;                      ///< sprite for default bullet
    std::vector<sf::Sprite *> bullet1;              ///< sprite for bullet for weapon1
    std::vector<sf::Sprite *> bullet2;              ///< sprite for bullet for weapon2
    std::vector<sf::Sprite *> bullet3;              ///< sprite for bullet for weapon3
    sf::Sprite *bullet4; ///< bullet for weapon4
    ResourcesContainer();

    virtual ~ResourcesContainer();
};

#endif //RESOURCESCONTAINER_H
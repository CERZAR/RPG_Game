/**
 * @file resourcesContainer.h
 * @brief A file containing a description of the backpack class
 */
#pragma once

#include "../Headers/ResourcesContainer.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

/**
 * @brief backpack class
 */
class Backpack {
private:
  Player *player{};
  ResourcesContainer *resContainter;
  float x{};
  float y{};
  int counter{};
  std::vector<sf::Text *>::const_iterator backpackText_iter;
  std::vector<sf::Text *> backpackTextArray;
  std::vector<sf::Shape *>::const_iterator backpackShape_iter;
  std::vector<sf::Shape *> backpackShapeArray;

  sf::Sprite icon;
  sf::Sprite *iconCurrentWeapon{};
  sf::Sprite *iconSecondWeapon{};

public:
  /**
   * @brief Method updatating pressings
   */
  static void updatePress();

  explicit Backpack(ResourcesContainer *res);

  virtual ~Backpack();

  /**
   * @brief Method setting backpack position
   */
  void setPosition(float x, float y);

  /**
   * @brief Method updateing backpack
   */
  void update(Player *player);

  /**
   * @brief Method rendering backpack
   */
  void render(sf::RenderTarget *target);
};

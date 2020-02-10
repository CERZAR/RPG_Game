// Copyright 2019 CERZAR
#include "../Headers/Map.h"

void Map::init_map_vector() {}

Map::Map(ResourcesContainer *pContainer) {
  tilesTexture.loadFromFile("../Resources/tiles.png");
  sprite.setTexture(tilesTexture);

  randomBox = -1;
}

Map::~Map() {}

void Map::createMap() {
  for (auto i = 0; i < int_vector.size(); i++) {
    for (auto j = 0; j < int_vector.size(); j++) {
      randomBox = GenerateRandomInt(100);
      switch (int_vector[j][i]) {
      case 0: {
        if (randomBox < 7)
          vector.push_back(new Box(&sprite,
                                   static_cast<float>(startX + i * tileSize),
                                   static_cast<float>(startY + j * tileSize)));
        groundVector.push_back(
            new Ground1(&sprite, static_cast<float>(startX + i * tileSize),
                        static_cast<float>(startY + j * tileSize)));
        break;
      }
      case 1: {
        if (randomBox < 18)
          vector.push_back(new Box(&sprite,
                                   static_cast<float>(startX + i * tileSize),
                                   static_cast<float>(startY + j * tileSize)));
        groundVector.push_back(
            new Ground2(&sprite, static_cast<float>(startX + i * tileSize),
                        static_cast<float>(startY + j * tileSize)));
        break;
      }
      case 2: {
        if (randomBox < 4)
          vector.push_back(new Box(&sprite,
                                   static_cast<float>(startX + i * tileSize),
                                   static_cast<float>(startY + j * tileSize)));
        groundVector.push_back(
            new Ground3(&sprite, static_cast<float>(startX + i * tileSize),
                        static_cast<float>(startY + j * tileSize)));
        break;
      }
      case 3: {
        groundVector.push_back(
            new Ground3(&sprite, static_cast<float>(startX + i * tileSize),
                        static_cast<float>(startY + j * tileSize)));
        vector.push_back(new Box(&sprite,
                                 static_cast<float>(startX + i * tileSize),
                                 static_cast<float>(startY + j * tileSize)));
        break;
      }
      case 4: {
        vector.push_back(
            new SteelWall(&sprite, static_cast<float>(startX + i * tileSize),
                          static_cast<float>(startY + j * tileSize)));
        break;
      }
      case 5: {
        vector.push_back(
            new DiamondWall(&sprite, static_cast<float>(startX + i * tileSize),
                            static_cast<float>(startY + j * tileSize)));
        break;
      }
      case 6: {
        vector.push_back(
            new GroundWall(&sprite, static_cast<float>(startX + i * tileSize),
                           static_cast<float>(startY + j * tileSize)));
        break;
      }
      case 7: {
        groundVector.push_back(
            new Ground3(&sprite, static_cast<float>(startX + i * tileSize),
                        static_cast<float>(startY + j * tileSize)));
        break;
      }
      default:
        break;
      }
    }
  }
  startX += tileSize;
  startY += tileSize;
  endX =
      static_cast<int>(vector[(int)vector.size() - 1]->rect.getPosition().x) -
      tileSize;
  endY = static_cast<int>(vector[vector.size() - 1]->rect.getPosition().y) -
         tileSize;
}

bool Map::checkCollision(sf::RectangleShape rect) {
  counter = 0;
  for (iter = vector.begin(); iter != vector.end(); iter++) {
    if ((vector[counter]->type == WALL || vector[counter]->type == BOX) &&
        (vector[counter]->rect.getGlobalBounds().intersects(
            rect.getGlobalBounds()))) {
      return true;
    }
    counter++;
  }
  return false;
}

void Map::checkPlayerCollision(Object *target) {
  counter = 0;
  for (iter = vector.begin(); iter != vector.end(); iter++) {
    if ((vector[counter]->type == WALL || vector[counter]->type == BOX) &&
        (vector[counter]->rect.getGlobalBounds().intersects(
            target->rect.getGlobalBounds()))) {
      // Bottom collision
      if (target->rect.getGlobalBounds().top <
              vector[counter]->rect.getGlobalBounds().top &&
          target->rect.getGlobalBounds().top +
                  target->rect.getGlobalBounds().height <
              vector[counter]->rect.getGlobalBounds().top +
                  vector[counter]->rect.getGlobalBounds().height &&
          target->rect.getGlobalBounds().left <
              vector[counter]->rect.getGlobalBounds().left +
                  vector[counter]->rect.getGlobalBounds().width &&
          target->rect.getGlobalBounds().left +
                  target->rect.getGlobalBounds().width >
              vector[counter]->rect.getGlobalBounds().left) {
        // std::cout << "Bottom collision\n";
        // std::cout << target->direction << "\n";
        if (target->direction == DOWN)
          target->rect.setPosition(target->rect.getGlobalBounds().left,
                                   vector[counter]->rect.getGlobalBounds().top -
                                       target->rect.getGlobalBounds().height);
        else if (target->direction == RIGHT)
          target->rect.setPosition(
              vector[counter]->rect.getGlobalBounds().left -
                  target->rect.getGlobalBounds().width,
              target->rect.getGlobalBounds().top);
        else if (target->direction == LEFT)
          target->rect.setPosition(
              vector[counter]->rect.getGlobalBounds().left +
                  vector[counter]->rect.getGlobalBounds().width,
              target->rect.getGlobalBounds().top);
        else if (target->direction == -3 || target->direction == -4) {
          target->rect.setPosition(target->rect.getGlobalBounds().left,
                                   vector[counter]->rect.getGlobalBounds().top -
                                       target->rect.getGlobalBounds().height);
        }
      }
      // Top collision
      if (target->rect.getGlobalBounds().top >
              vector[counter]->rect.getGlobalBounds().top &&
          target->rect.getGlobalBounds().top +
                  target->rect.getGlobalBounds().height >
              vector[counter]->rect.getGlobalBounds().top +
                  vector[counter]->rect.getGlobalBounds().height &&
          target->rect.getGlobalBounds().left <
              vector[counter]->rect.getGlobalBounds().left +
                  vector[counter]->rect.getGlobalBounds().width &&
          target->rect.getGlobalBounds().left +
                  target->rect.getGlobalBounds().width >
              vector[counter]->rect.getGlobalBounds().left) {
        // std::cout << "Top collision\n";
        // std::cout << target->direction << "\n";
        if (target->direction == UP)
          target->rect.setPosition(
              target->rect.getGlobalBounds().left,
              vector[counter]->rect.getGlobalBounds().top +
                  vector[counter]->rect.getGlobalBounds().height);
        else if (target->direction == RIGHT)
          target->rect.setPosition(
              vector[counter]->rect.getGlobalBounds().left -
                  target->rect.getGlobalBounds().width,
              target->rect.getGlobalBounds().top);
        else if (target->direction == LEFT)
          target->rect.setPosition(
              vector[counter]->rect.getGlobalBounds().left +
                  vector[counter]->rect.getGlobalBounds().width,
              target->rect.getGlobalBounds().top);
        else if (target->direction == -1 || target->direction == -2) {
          target->rect.setPosition(
              target->rect.getGlobalBounds().left,
              vector[counter]->rect.getGlobalBounds().top +
                  vector[counter]->rect.getGlobalBounds().height);
        }
      }
      // Right collision
      if (target->rect.getGlobalBounds().left <
              vector[counter]->rect.getGlobalBounds().left &&
          target->rect.getGlobalBounds().left +
                  target->rect.getGlobalBounds().width <
              vector[counter]->rect.getGlobalBounds().left +
                  vector[counter]->rect.getGlobalBounds().width &&
          target->rect.getGlobalBounds().top <
              vector[counter]->rect.getGlobalBounds().top +
                  vector[counter]->rect.getGlobalBounds().height &&
          target->rect.getGlobalBounds().top +
                  target->rect.getGlobalBounds().height >
              vector[counter]->rect.getGlobalBounds().top) {
        // std::cout << "RIGHT collision\n";
        // std::cout << target->direction << "\n";
        target->rect.setPosition(vector[counter]->rect.getGlobalBounds().left -
                                     target->rect.getGlobalBounds().width,
                                 target->rect.getGlobalBounds().top);
      }
      // Left collision
      if (target->rect.getGlobalBounds().left >
              vector[counter]->rect.getGlobalBounds().left &&
          target->rect.getGlobalBounds().left +
                  target->rect.getGlobalBounds().width >
              vector[counter]->rect.getGlobalBounds().left +
                  vector[counter]->rect.getGlobalBounds().width &&
          target->rect.getGlobalBounds().top <
              vector[counter]->rect.getGlobalBounds().top +
                  vector[counter]->rect.getGlobalBounds().height &&
          target->rect.getGlobalBounds().top +
                  target->rect.getGlobalBounds().height >
              vector[counter]->rect.getGlobalBounds().top) {
        // std::cout << "LEFT collision\n";
        // std::cout << target->direction << "\n";
        target->rect.setPosition(
            vector[counter]->rect.getGlobalBounds().left +
                vector[counter]->rect.getGlobalBounds().width,
            target->rect.getGlobalBounds().top);
      }
    }
    counter++;
  }
}

void Map::checkEnemyCollision(Object *target) {
  counter = 0;
  for (iter = vector.begin(); iter != vector.end(); iter++) {
    if (target->rect.getGlobalBounds().intersects(
            vector[counter]->rect.getGlobalBounds())) {
      if (target->direction == UP) {
        target->direction = 5;
        target->rect.move(0, target->movementSpeed);
      }
      if (target->direction == DOWN) {
        target->direction = 5;
        target->rect.move(0, -target->movementSpeed);
      }
      if (target->direction == RIGHT) {
        target->direction = 5;
        target->rect.move(-target->movementSpeed, 0);
      }
      if (target->direction == LEFT) {
        target->direction = 5;
        target->rect.move(target->movementSpeed, 0);
      }
    }
    counter++;
  }
}

void Map::checkBulletCollision(Object *target) {
  counter = 0;
  for (iter = vector.begin(); iter != vector.end(); iter++) {
    if (target->rect.getGlobalBounds().intersects(
            vector[counter]->rect.getGlobalBounds())) {
      if (vector[counter]->type == BOX) {
        vector[counter]->hp--;
        target->isExist = false;
        if (vector[counter]->hp <= 0) {
          vector[counter]->isExist = false;
        }
      } else if (vector[counter]->type == WALL)
        target->isExist = false;
    }
    counter++;
  }
}

void Map::update() {
  counter = 0;
  for (iter = vector.begin(); iter != vector.end(); iter++) {
    if (!vector[counter]->isExist) {
      vector.erase(iter);
      break;
    }
    counter++;
  }
}

void Map::render(sf::RenderTarget *target) {
  counter = 0;
  for (iter = vector.begin(); iter != vector.end(); iter++) {
    target->draw(vector[counter]->sprite);
    counter++;
  }
}

void Map::renderGround(sf::RenderTarget *target) {
  counter = 0;
  for (iter = groundVector.begin(); iter != groundVector.end(); iter++) {
    target->draw(groundVector[counter]->sprite);
    counter++;
  }
}

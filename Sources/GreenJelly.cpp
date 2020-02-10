
#include "../Headers/GreenJelly.h"

void GreenJelly::initVariables() {
  Enemy::initVariables();
  distanceLength = 150;

  this->rect.setSize(sf::Vector2f(41, 35));
  this->rect.setFillColor(sf::Color::Green);

  sprite = *resContainter->greenJelly;
}

void GreenJelly::initStats() {
  getExp = 2;
  maxHP = 5;
  hp = maxHP;
  damage = 4;
  movementSpeed = 1.15f;
}

GreenJelly::GreenJelly(ResourcesContainer *res) : Enemy::Enemy(res) {
  initVariables();
  initStats();
}

GreenJelly::~GreenJelly() {}

void GreenJelly::update(int playerX, int playerY) {
  sprite.setPosition(rect.getPosition());
  if (hp <= 0)
    isExist = false;

  if (!isAgro) {
    if (direction == UP) {
      this->rect.move(0, -1 * this->movementSpeed);
      this->sprite.setTextureRect(
          sf::IntRect(this->animationCounter * 60, 0, 60, 37));
    } else if (direction == DOWN) {
      this->rect.move(0, this->movementSpeed);
      this->sprite.setTextureRect(
          sf::IntRect(this->animationCounter * 60, 0, 60, 37));
    } else if (direction == RIGHT) {
      this->rect.move(this->movementSpeed, 0);
      this->sprite.setTextureRect(
          sf::IntRect(this->animationCounter * 60, 0, 60, 37));
    } else if (direction == LEFT) {
      this->rect.move(-1 * this->movementSpeed, 0);
      this->sprite.setTextureRect(
          sf::IntRect(this->animationCounter * 60, 0, 60, 37));
    } else {
      // No move
    }

    this->animationSlow++;

    if (this->animationSlow == 20) {
      this->animationCounter++;
      this->animationSlow = 0;
    }

    if (this->animationCounter == 2)
      this->animationCounter = 0;

    this->distanceCounter++;
    if (this->distanceCounter >= this->distanceLength) {
      direction = GenerateRandomInt0(40);
      this->distanceCounter = 0;
    }
  } else {
    // Player to right
    if (playerX > rect.getPosition().x) {
      this->rect.move(this->movementSpeed, 0);
      this->sprite.setTextureRect(
          sf::IntRect(this->animationCounter * 60, 0, 60, 37));
    }
    // Player to left
    if (playerX < rect.getPosition().x) {
      this->rect.move(-1 * this->movementSpeed, 0);
      this->sprite.setTextureRect(
          sf::IntRect(this->animationCounter * 60, 0, 60, 37));
    }
    // Player to top
    if (playerY < rect.getPosition().y) {
      this->rect.move(0, -1 * this->movementSpeed);
      this->sprite.setTextureRect(
          sf::IntRect(this->animationCounter * 60, 0, 60, 37));
    }
    // Player to bot
    if (playerY > rect.getPosition().y) {
      this->rect.move(0, this->movementSpeed);
      this->sprite.setTextureRect(
          sf::IntRect(this->animationCounter * 60, 0, 60, 37));
    }

    this->animationCounter++;

    if (this->animationCounter == 2)
      this->animationCounter = 0;
  }

  // Update hp display
  text.setString(std::to_string(this->hp) + "/" + std::to_string(this->maxHP));
  text.setPosition(rect.getPosition().x + 2, rect.getPosition().y + 33);
}

void GreenJelly::render(sf::RenderTarget *target) {
  target->draw(this->sprite);
  target->draw(this->text);
}

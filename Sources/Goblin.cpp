
#include "../Headers/Goblin.h"


void Goblin::initVariables() {
    Enemy::initVariables();
    distanceLength = 150;

    this->rect.setSize(sf::Vector2f(32, 32));
    this->rect.setFillColor(sf::Color::Green);

    sprite = *resContainter->enemiesSheet1;
}

void Goblin::initStats() {
    maxHP = 10;
    hp = maxHP;
    damage = 6;
    movementSpeed = 2.f;
}

Goblin::Goblin(ResourcesContainer *res) : Enemy::Enemy(res) {
    initVariables();
    initStats();
}


Goblin::~Goblin() {
}

void Goblin::update() {
    sprite.setPosition(rect.getPosition());
    if (hp <= 0)
        isExist = false;

    if (direction == UP) {
        this->rect.move(0, -1 * this->movementSpeed);
        this->sprite.setTextureRect(
                sf::IntRect(this->animationCounter * 32, 0, 32, 32));
    } else if (direction == DOWN) {
        this->rect.move(0, this->movementSpeed);
        this->sprite.setTextureRect(
                sf::IntRect(this->animationCounter * 32, 0, 32, 32));
    } else if (direction == RIGHT) {
        this->rect.move(this->movementSpeed, 0);
        this->sprite.setTextureRect(
                sf::IntRect(this->animationCounter * 32, 0, 32, 32));
    } else if (direction == LEFT) {
        this->rect.move(-1 * this->movementSpeed, 0);
        this->sprite.setTextureRect(
                sf::IntRect(this->animationCounter * 32, 0, 32, 32));
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
        direction = GenerateRandomInt0(4);
        this->distanceCounter = 0;
    }

    // Update hp display
    text.setString(
            std::to_string(this->hp) + "/" + std::to_string(this->maxHP));
    text.setPosition(rect.getPosition().x + 2, rect.getPosition().y + 33);
}

void Goblin::render(sf::RenderTarget *target) {
    target->draw(this->sprite);
    target->draw(this->text);
}

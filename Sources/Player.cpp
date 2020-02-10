
#include "../Headers/Player.h"


void Player::initVariables() {
    isExist = true;
    currentWeapon = new DefaultWeapon(resContainter);
    haveSecondWeapon = false;

    direction = DOWN;
    rect.setSize(sf::Vector2f(31, 42));
    rect.setFillColor(sf::Color(0, 0, 255, 200));

    texture.loadFromFile("../Resources/players.png");
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 48, 48));
}

void Player::initStats() {
    level = 1;
    updateStats();
    hp = maxHP;
    mp = maxMP;
    coins = 0;
    exp = 0;
}

Player::Player(ResourcesContainer *res) : Object::Object(res) {
    initVariables();
    initStats();
}


Player::~Player() {
    delete currentWeapon;
}

void Player::update() {
    if (exp >= needExp) {
        level++;
        exp -= needExp;
        updateStats();
    }
    sprite.setPosition(rect.getPosition().x - 8, rect.getPosition().y - 6);

    if (direction == UP) {
        this->sprite.setTextureRect(sf::IntRect(48, 48 * 3, 48, 48));
    }
    if (direction == DOWN) {
        this->sprite.setTextureRect(sf::IntRect(48, 48 * 0, 48, 48));
    }
    if (direction == RIGHT) {
        this->sprite.setTextureRect(sf::IntRect(48, 48 * 2, 48, 48));
    }
    if (direction == LEFT) {
        this->sprite.setTextureRect(sf::IntRect(48, 48 * 1, 48, 48));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
        sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->rect.move(this->movementSpeed / 2, -1 * this->movementSpeed / 2);
        this->sprite.setTextureRect(
                sf::IntRect(this->counterWalking * 48, 48 * 3, 48, 48));
        direction = -1;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
               sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->rect.move(-1 * this->movementSpeed / 2,
                        -1 * this->movementSpeed / 2);
        this->sprite.setTextureRect(
                sf::IntRect(this->counterWalking * 48, 48 * 3, 48, 48));
        direction = -2;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
               sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->rect.move(this->movementSpeed / 2, this->movementSpeed / 2);
        this->sprite.setTextureRect(
                sf::IntRect(this->counterWalking * 48, 48 * 0, 48, 48));
        direction = -3;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
               sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->rect.move(-1 * this->movementSpeed / 2, this->movementSpeed / 2);
        this->sprite.setTextureRect(
                sf::IntRect(this->counterWalking * 48, 48 * 0, 48, 48));
        direction = -4;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
               sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        this->rect.move(0, -1 * this->movementSpeed);
        this->sprite.setTextureRect(
                sf::IntRect(this->counterWalking * 48, 48 * 3, 48, 48));
        direction = UP;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
               sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->rect.move(0, this->movementSpeed);
        this->sprite.setTextureRect(
                sf::IntRect(this->counterWalking * 48, 48 * 0, 48, 48));
        direction = DOWN;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
               sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->rect.move(this->movementSpeed, 0);
        this->sprite.setTextureRect(
                sf::IntRect(this->counterWalking * 48, 48 * 2, 48, 48));
        direction = RIGHT;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
               sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->rect.move(-1 * this->movementSpeed, 0);
        this->sprite.setTextureRect(
                sf::IntRect(this->counterWalking * 48, 48 * 1, 48, 48));
        direction = LEFT;
    }

    this->slowWalk++;

    if (this->slowWalk == 20) {
        this->counterWalking++;
        this->slowWalk = 0;
    }

    if (this->counterWalking == 2)
        this->counterWalking = 0;
}

void Player::updateStats() {
    switch (level) {
        case 1: {
            maxHP = 10;
            maxMP = 10;
            needExp = 4;
            damage = 1;
            movementSpeed = 1.f;
            break;
        }
        case 2: {
            maxHP = 11;
            hp = maxHP;
            maxMP = 15;
            mp = maxMP;
            needExp = 8;
            movementSpeed = 1.4f;
            break;
        }
        case 3: {
            maxHP = 12;
            hp = maxHP;
            maxMP = 20;
            mp = maxMP;
            needExp = 10;
            movementSpeed = 1.6f;
            break;
        }
        case 4: {
            maxHP = 13;
            hp = maxHP;
            maxMP = 25;
            mp = maxMP;
            needExp = 20;
            movementSpeed = 1.8f;
            break;
        }
        case 5: {
            maxHP = 14;
            hp = maxHP;
            maxMP = 30;
            mp = maxMP;
            needExp = 30;
            damage = 2;
            movementSpeed = 2.f;
            break;
        }
        case 6: {
            maxHP = 15;
            hp = maxHP;
            maxMP = 35;
            mp = maxMP;
            needExp = 40;
            movementSpeed = 2.2f;
            break;
        }
        case 7: {
            maxHP = 16;
            hp = maxHP;
            maxMP = 45;
            mp = maxMP;
            needExp = 50;
            movementSpeed = 2.4f;
            break;
        }
        case 8: {
            maxHP = 17;
            hp = maxHP;
            maxMP = 50;
            mp = maxMP;
            needExp = 60;
            movementSpeed = 2.6f;
            break;
        }
        case 9: {
            maxHP = 18;
            hp = maxHP;
            maxMP = 70;
            mp = maxMP;
            needExp = 70;
            movementSpeed = 2.8f;
            break;
        }
        case 10: {
            maxHP = 20;
            hp = maxHP;
            maxMP = 100;
            mp = maxMP;
            needExp = 20;
            damage = 3;
            movementSpeed = 3.f;
            break;
        }
        default: {
            maxHP += 1;
            hp = maxHP;
            maxMP += 5;
            mp = maxMP;
            needExp = 20;
            damage = 3;
            movementSpeed += 0.05f;
            break;
        }
    }
}

void Player::takeSecondWeapon(Weapon *pWeapon) {
    haveSecondWeapon = true;
    this->secondWeapon = pWeapon;
}

Weapon *Player::throwSecondWeapon() {
    haveSecondWeapon = false;
    return secondWeapon;
}



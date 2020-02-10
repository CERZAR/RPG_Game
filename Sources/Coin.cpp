
#include "../Headers/Coin.h"

Coin::Coin(ResourcesContainer *res) : Item::Item(res) {
    isExist = true;
    type = COIN;

    rect.setSize(sf::Vector2f(10, 10));
    rect.setFillColor(sf::Color::White);
    sprite.setTextureRect(sf::IntRect(0, 0, 40, 40));
}


Coin::~Coin() {
}

void Coin::update() {
    sprite = *resContainter->item_coin[counterAnimation];
    sprite.setPosition(rect.getPosition().x - 15, rect.getPosition().y - 15);

    animationSlow++;
    if (animationSlow == 7) {
        counterAnimation++;
        animationSlow = 0;
    }

    if (counterAnimation == 10) {
        counterAnimation = 1;
    }
}


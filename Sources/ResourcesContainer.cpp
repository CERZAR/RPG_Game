
#include "../Headers/ResourcesContainer.h"

ResourcesContainer::ResourcesContainer() {
  // Load font
  pixel_font = new sf::Font;
  pixel_font->loadFromFile("../Resources/pixel_font.ttf");

  // Load icon_player
  icon = new sf::Sprite;
  texture = new sf::Texture;
  texture->loadFromFile("../Resources/icon.png");
  icon->setTexture(*texture);

  // Load enemies texture
  // green jelly
  greenJelly = new sf::Sprite;
  texture = new sf::Texture;
  texture->loadFromFile("../Resources/enemies/enemySprite.png");
  greenJelly->setTexture(*texture);
  // greenJelly->setTextureRect(sf::IntRect(0, 0, 60, 37));
  // goblin
  enemiesSheet1 = new sf::Sprite;
  texture = new sf::Texture;
  texture->loadFromFile("../Resources/enemies/enemySprite1.png");
  enemiesSheet1->setTexture(*texture);

  // Load coins textures
  for (int i = 1; i <= 10; i++) {
    auto *pTexture = new sf::Texture;
    auto *sprite = new sf::Sprite;
    pTexture->loadFromFile("../Resources/items/coin/" + std::to_string(i) +
                           ".png");
    sprite->setTexture(*pTexture);
    item_coin.push_back(sprite);
  }

  // Load heath textures
  for (int i = 1; i <= 8; i++) {
    auto *pTexture = new sf::Texture;
    auto *sprite = new sf::Sprite;
    pTexture->loadFromFile("../Resources/items/health/" + std::to_string(i) +
                           ".png");
    sprite->setTexture(*pTexture);
    item_health.push_back(sprite);
  }

  // Load energy textures
  for (int i = 1; i <= 10; i++) {
    auto *pTexture = new sf::Texture;
    auto *sprite = new sf::Sprite;
    pTexture->loadFromFile("../Resources/items/energy/" + std::to_string(i) +
                           ".png");
    sprite->setTexture(*pTexture);
    item_energy.push_back(sprite);
  }

  // Load weapons textures
  for (int i = 1; i <= 5; i++) {
    auto *pTexture = new sf::Texture;
    auto sprite = new sf::Sprite;
    pTexture->loadFromFile("../Resources/items/weapons/default_weapon/" +
                           std::to_string(i) + ".png");
    sprite->setTexture(*pTexture);
    defaultWeapon.push_back(sprite);
  }
  for (int i = 1; i <= 5; i++) {
    auto *pTexture = new sf::Texture;
    auto sprite = new sf::Sprite;
    pTexture->loadFromFile("../Resources/items/weapons/weapon1/" +
                           std::to_string(i) + ".png");
    sprite->setTexture(*pTexture);
    weapon1.push_back(sprite);
  }
  for (int i = 1; i <= 5; i++) {
    auto *pTexture = new sf::Texture;
    auto *sprite = new sf::Sprite;
    pTexture->loadFromFile("../Resources/items/weapons/weapon2/" +
                           std::to_string(i) + ".png");
    sprite->setTexture(*pTexture);
    weapon2.push_back(sprite);
  }
  for (int i = 1; i <= 5; i++) {
    auto *pTexture = new sf::Texture;
    auto *sprite = new sf::Sprite;
    pTexture->loadFromFile("../Resources/items/weapons/weapon3/" +
                           std::to_string(i) + ".png");
    sprite->setTexture(*pTexture);
    weapon3.push_back(sprite);
  }
  for (int i = 1; i <= 5; i++) {
    auto *pTexture = new sf::Texture;
    auto *sprite = new sf::Sprite;
    pTexture->loadFromFile("../Resources/items/weapons/weapon4/" +
                           std::to_string(i) + ".png");
    sprite->setTexture(*pTexture);
    weapon4.push_back(sprite);
  }
  // Load weapons icons for backpack
  for (int i = 1; i <= 5; i++) {
    auto *pTexture = new sf::Texture;
    auto *sprite = new sf::Sprite;
    pTexture->loadFromFile("../Resources/items/weapons/default_weapon/icon" +
                           std::to_string(i) + ".png");
    sprite->setTexture(*pTexture);
    iconDefaultWeapon.push_back(sprite);
  }
  for (int i = 1; i <= 5; i++) {
    auto *pTexture = new sf::Texture;
    auto *sprite = new sf::Sprite;
    pTexture->loadFromFile("../Resources/items/weapons/weapon1/icon" +
                           std::to_string(i) + ".png");
    sprite->setTexture(*pTexture);
    iconWeapon1.push_back(sprite);
  }
  for (int i = 1; i <= 5; i++) {
    auto *pTexture = new sf::Texture;
    auto *sprite = new sf::Sprite;
    pTexture->loadFromFile("../Resources/items/weapons/weapon2/icon" +
                           std::to_string(i) + ".png");
    sprite->setTexture(*pTexture);
    iconWeapon2.push_back(sprite);
  }
  for (int i = 1; i <= 5; i++) {
    auto *pTexture = new sf::Texture;
    auto *sprite = new sf::Sprite;
    pTexture->loadFromFile("../Resources/items/weapons/weapon3/icon" +
                           std::to_string(i) + ".png");
    sprite->setTexture(*pTexture);
    iconWeapon3.push_back(sprite);
  }
  for (int i = 1; i <= 5; i++) {
    auto *pTexture = new sf::Texture;
    auto *sprite = new sf::Sprite;
    pTexture->loadFromFile("../Resources/items/weapons/weapon4/icon" +
                           std::to_string(i) + ".png");
    sprite->setTexture(*pTexture);
    iconWeapon4.push_back(sprite);
  }

  // Load bullets
  // default bullet
  defaultBullet = new sf::Sprite;
  texture = new sf::Texture;
  texture->loadFromFile("../Resources/fireball.png");
  defaultBullet->setTexture(*texture);
  // bullet1
  for (int i = 1; i <= 6; i++) {
    auto *pTexture = new sf::Texture;
    auto *sprite = new sf::Sprite;
    pTexture->loadFromFile("../Resources/items/weapons/weapon1/bullet1/" +
                           std::to_string(i) + ".png");
    sprite->setTexture(*pTexture);
    bullet1.push_back(sprite);
  }
  // bullet2
  for (int i = 1; i <= 6; i++) {
    auto *pTexture = new sf::Texture;
    auto *sprite = new sf::Sprite;
    pTexture->loadFromFile("../Resources/items/weapons/weapon2/bullet2/" +
                           std::to_string(i) + ".png");
    sprite->setTexture(*pTexture);
    bullet2.push_back(sprite);
  }
  // bullet3
  for (int i = 1; i <= 6; i++) {
    auto *pTexture = new sf::Texture;
    auto *sprite = new sf::Sprite;
    pTexture->loadFromFile("../Resources/items/weapons/weapon3/bullet3/" +
                           std::to_string(i) + ".png");
    sprite->setTexture(*pTexture);
    bullet3.push_back(sprite);
  }
  // bullet4
  bullet4 = new sf::Sprite;
  texture = new sf::Texture;
  texture->loadFromFile("../Resources/items/weapons/weapon4/bullet.png");
  bullet4->setTexture(*texture);
}

ResourcesContainer::~ResourcesContainer() {
  // Deleting font
  delete pixel_font;
  // Deleting coins textures
  for (auto &i : item_coin) {
    delete i;
  }
  // Deleting health textures
  for (auto &i : item_health) {
    delete i;
  }
  // Deleting energy textures
  for (auto &i : item_energy) {
    delete i;
  }
  // Deleting weapons textures
  for (auto &i : defaultWeapon) {
    delete i;
  }
  for (auto &i : weapon1) {
    delete i;
  }
  for (auto &i : weapon3) {
    delete i;
  }
  for (auto &i : weapon2) {
    delete i;
  }
  for (auto &i : weapon4) {
    delete i;
  }
  // Deleting weapons icons for backpack
  for (auto &i : iconDefaultWeapon) {
    delete i;
  }
  for (auto &i : iconWeapon1) {
    delete i;
  }
  for (auto &i : iconWeapon3) {
    delete i;
  }
  for (auto &i : iconWeapon2) {
    delete i;
  }
  for (auto &i : iconWeapon4) {
    delete i;
  }
}

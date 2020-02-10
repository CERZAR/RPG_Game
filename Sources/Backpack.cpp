#include "../Headers/Backpack.h"

void Backpack::updatePress() {}

Backpack::Backpack(ResourcesContainer *res) {
  this->resContainter = res;

  sf::RectangleShape *rectShape;

  // rect 0
  rectShape = new sf::RectangleShape;
  rectShape->setSize(sf::Vector2f(1000, 500));
  rectShape->setFillColor(sf::Color(128, 128, 128));
  rectShape->setOutlineColor(sf::Color::White);
  rectShape->setOutlineThickness(3);
  backpackShapeArray.push_back(rectShape);

  // rect 1
  rectShape = new sf::RectangleShape;
  rectShape->setSize(sf::Vector2f(3, 500));
  rectShape->setFillColor(sf::Color::White);
  backpackShapeArray.push_back(rectShape);

  // rect 2
  rectShape = new sf::RectangleShape;
  rectShape->setSize(sf::Vector2f(600, 3));
  rectShape->setFillColor(sf::Color::White);
  backpackShapeArray.push_back(rectShape);

  // rect 3
  sf::CircleShape *circleShape = new sf::CircleShape;
  circleShape->setRadius(20);
  circleShape->setPointCount(5);
  circleShape->setFillColor(sf::Color::White);
  circleShape->setOutlineColor(sf::Color::Magenta);
  circleShape->setOutlineThickness(3);
  backpackShapeArray.push_back(circleShape);

  // rect 4
  rectShape = new sf::RectangleShape;
  rectShape->setSize(sf::Vector2f(400, 3));
  rectShape->setFillColor(sf::Color::White);
  backpackShapeArray.push_back(rectShape);

  // rect 5
  rectShape = new sf::RectangleShape;
  rectShape->setSize(sf::Vector2f(82, 100));
  rectShape->setFillColor(sf::Color::White);
  backpackShapeArray.push_back(rectShape);
  icon = *resContainter->icon;

  // rect 6
  rectShape = new sf::RectangleShape;
  rectShape->setSize(sf::Vector2f(400, 128));
  rectShape->setFillColor(sf::Color::White);
  rectShape->setOutlineThickness(4);
  backpackShapeArray.push_back(rectShape);

  // rect 7
  rectShape = new sf::RectangleShape;
  rectShape->setSize(sf::Vector2f(100, 40));
  rectShape->setFillColor(sf::Color::White);
  backpackShapeArray.push_back(rectShape);

  // rect 8
  rectShape = new sf::RectangleShape;
  rectShape->setSize(sf::Vector2f(400, 128));
  rectShape->setFillColor(sf::Color::White);
  backpackShapeArray.push_back(rectShape);

  // rect 9
  rectShape = new sf::RectangleShape;
  rectShape->setSize(sf::Vector2f(100, 40));
  rectShape->setFillColor(sf::Color::White);
  backpackShapeArray.push_back(rectShape);

  // rect 10
  rectShape = new sf::RectangleShape;
  rectShape->setSize(sf::Vector2f(100, 40));
  rectShape->setFillColor(sf::Color::White);
  backpackShapeArray.push_back(rectShape);

  // rect 11
  rectShape = new sf::RectangleShape;
  rectShape->setSize(sf::Vector2f(100, 40));
  rectShape->setFillColor(sf::Color::White);
  backpackShapeArray.push_back(rectShape);

  // text 0
  sf::Text *text = new sf::Text;
  ;
  text->setFont(*res->pixel_font);
  text->setCharacterSize(30);
  text->setString("PLAYER");
  text->setFillColor(sf::Color::White);
  backpackTextArray.push_back(text);

  // text 1 lvl
  text = new sf::Text;
  ;
  text->setFont(*res->pixel_font);
  text->setCharacterSize(30);
  text->setFillColor(sf::Color::Magenta);
  backpackTextArray.push_back(text);

  // text 2 hp
  text = new sf::Text;
  ;
  text->setFont(*res->pixel_font);
  text->setCharacterSize(25);
  text->setFillColor(sf::Color::Red);
  backpackTextArray.push_back(text);

  // text 3 mp
  text = new sf::Text;
  ;
  text->setFont(*res->pixel_font);
  text->setCharacterSize(25);
  text->setFillColor(sf::Color(30, 144, 255));
  backpackTextArray.push_back(text);

  // text 4 exp
  text = new sf::Text;
  ;
  text->setFont(*res->pixel_font);
  text->setCharacterSize(25);
  text->setFillColor(sf::Color::Cyan);
  backpackTextArray.push_back(text);

  // text 5 gold
  text = new sf::Text;
  ;
  text->setFont(*res->pixel_font);
  text->setCharacterSize(25);
  text->setFillColor(sf::Color::Yellow);
  backpackTextArray.push_back(text);

  // text 6 current weapon
  text = new sf::Text;
  ;
  text->setFont(*res->pixel_font);
  text->setCharacterSize(40);
  text->setString("Current weapon:");
  text->setFillColor(sf::Color::White);
  backpackTextArray.push_back(text);

  // text 7 second weapon
  text = new sf::Text;
  ;
  text->setFont(*res->pixel_font);
  text->setCharacterSize(40);
  text->setString("Second weapon:");
  text->setFillColor(sf::Color::White);
  backpackTextArray.push_back(text);

  // text 8 current weapon - upgate
  text = new sf::Text;
  ;
  text->setFont(*res->pixel_font);
  text->setCharacterSize(20);
  text->setString("Upgrate\n  (1)");
  text->setFillColor(sf::Color::Black);
  backpackTextArray.push_back(text);

  // text 9 second weapon - upgrate
  text = new sf::Text;
  ;
  text->setFont(*res->pixel_font);
  text->setCharacterSize(20);
  text->setString("Upgrate\n  (2)");
  text->setFillColor(sf::Color::Black);
  backpackTextArray.push_back(text);

  // text 10 second weapon - equip
  text = new sf::Text;
  ;
  text->setFont(*res->pixel_font);
  text->setCharacterSize(20);
  text->setString("Equip\n (3)");
  text->setFillColor(sf::Color::Black);
  backpackTextArray.push_back(text);

  // text 11 second weapon - upgrate
  text = new sf::Text;
  ;
  text->setFont(*res->pixel_font);
  text->setCharacterSize(20);
  text->setString("Throw\n (4)");
  text->setFillColor(sf::Color::Black);
  backpackTextArray.push_back(text);

  // text 12 current info - lvl
  text = new sf::Text;
  ;
  text->setFont(*res->pixel_font);
  text->setCharacterSize(18);
  text->setFillColor(sf::Color::White);
  backpackTextArray.push_back(text);

  // text 13 current info - damage
  text = new sf::Text;
  ;
  text->setFont(*res->pixel_font);
  text->setCharacterSize(18);
  text->setFillColor(sf::Color::White);
  backpackTextArray.push_back(text);

  // text 14 current info - atack speed
  text = new sf::Text;
  ;
  text->setFont(*res->pixel_font);
  text->setCharacterSize(17);
  text->setFillColor(sf::Color::White);
  backpackTextArray.push_back(text);

  // text 15 current info - speed
  text = new sf::Text;
  ;
  text->setFont(*res->pixel_font);
  text->setCharacterSize(18);
  text->setFillColor(sf::Color::White);
  backpackTextArray.push_back(text);

  // text 16 current info - flight time
  text = new sf::Text;
  ;
  text->setFont(*res->pixel_font);
  text->setCharacterSize(18);
  text->setFillColor(sf::Color::White);
  backpackTextArray.push_back(text);

  // text 17 current info - Upgrate cost
  text = new sf::Text;
  ;
  text->setFont(*res->pixel_font);
  text->setCharacterSize(18);
  text->setFillColor(sf::Color::White);
  backpackTextArray.push_back(text);

  // text 18 second info - lvl
  text = new sf::Text;
  ;
  text->setFont(*res->pixel_font);
  text->setCharacterSize(18);
  text->setFillColor(sf::Color::White);
  backpackTextArray.push_back(text);

  // text 19 second info - damage
  text = new sf::Text;
  ;
  text->setFont(*res->pixel_font);
  text->setCharacterSize(18);
  text->setFillColor(sf::Color::White);
  backpackTextArray.push_back(text);

  // text 20 second info - atack speed
  text = new sf::Text;
  ;
  text->setFont(*res->pixel_font);
  text->setCharacterSize(17);
  text->setFillColor(sf::Color::White);
  backpackTextArray.push_back(text);

  // text 21 second info - speed
  text = new sf::Text;
  ;
  text->setFont(*res->pixel_font);
  text->setCharacterSize(18);
  text->setFillColor(sf::Color::White);
  backpackTextArray.push_back(text);

  // text 22 second info - flight time
  text = new sf::Text;
  ;
  text->setFont(*res->pixel_font);
  text->setCharacterSize(18);
  text->setFillColor(sf::Color::White);
  backpackTextArray.push_back(text);

  // text 23 second info - Upgrate cost
  text = new sf::Text;
  ;
  text->setFont(*res->pixel_font);
  text->setCharacterSize(18);
  text->setFillColor(sf::Color::White);
  backpackTextArray.push_back(text);
}

Backpack::~Backpack() {
  for (size_t i = 0; i < backpackShapeArray.size(); i++) {
    delete backpackShapeArray[i];
  }
}

void Backpack::setPosition(float x, float y) {
  this->x = x - 500;
  this->y = y - 250;
}

void Backpack::update(Player *player) {
  this->player = player;
  backpackShapeArray[0]->setPosition(x, y);
  backpackShapeArray[1]->setPosition(x + 400, y);
  backpackShapeArray[2]->setPosition(x + 400, y + 250);
  backpackShapeArray[3]->setPosition(x + 220, y + 20);
  backpackShapeArray[4]->setPosition(x, y + 70);
  backpackShapeArray[5]->setPosition(x + 50, y + 100);
  backpackShapeArray[6]->setPosition(x + 410, y + 70);
  player->currentWeapon->updateOutline();
  backpackShapeArray[6]->setOutlineColor(
      player->currentWeapon->rect.getOutlineColor());
  backpackShapeArray[7]->setPosition(x + 410, y + 206);
  backpackShapeArray[8]->setPosition(x + 410, y + 320);
  backpackShapeArray[8]->setOutlineThickness(0);
  backpackShapeArray[9]->setPosition(x + 410, y + 456);
  backpackShapeArray[10]->setPosition(x + 560, y + 456);
  backpackShapeArray[11]->setPosition(x + 710, y + 456);
  icon.setPosition(x + 50, y + 100);
  iconCurrentWeapon = &player->currentWeapon->iconSprite;
  iconCurrentWeapon->setPosition(x + 410, y + 70);
  if (player->haveSecondWeapon == true) {
    backpackShapeArray[8]->setOutlineThickness(4);
    player->secondWeapon->updateOutline();
    backpackShapeArray[8]->setOutlineColor(
        player->secondWeapon->rect.getOutlineColor());
    iconSecondWeapon = &player->secondWeapon->iconSprite;
    iconSecondWeapon->setPosition(x + 410, y + 320);
  }

  backpackTextArray[0]->setPosition(x + 100, y + 20);
  if (player->level >= 10) {
    backpackTextArray[1]->setPosition(x + 228, y + 27);
    backpackTextArray[1]->setCharacterSize(20);
    backpackTextArray[1]->setString(std::to_string(player->level));
  } else {
    backpackTextArray[1]->setPosition(x + 232, y + 20);
    backpackTextArray[1]->setCharacterSize(30);
    backpackTextArray[1]->setString(std::to_string(player->level));
  }
  backpackTextArray[2]->setPosition(x + 152, y + 95);
  backpackTextArray[2]->setString("HP: " + std::to_string(player->hp) + "/" +
                                  std::to_string(player->maxHP));
  backpackTextArray[3]->setPosition(x + 152, y + 120);
  backpackTextArray[3]->setString("MP: " + std::to_string(player->mp) + "/" +
                                  std::to_string(player->maxMP));
  backpackTextArray[4]->setPosition(x + 152, y + 145);
  backpackTextArray[4]->setString("EXP: " + std::to_string(player->exp) + "/" +
                                  std::to_string(player->needExp));
  backpackTextArray[5]->setPosition(x + 152, y + 170);
  backpackTextArray[5]->setString("GOLD: " + std::to_string(player->coins));
  backpackTextArray[6]->setPosition(x + 420, y + 10);
  backpackTextArray[7]->setPosition(x + 420, y + 260);
  backpackTextArray[8]->setPosition(x + 420, y + 202);
  backpackTextArray[9]->setPosition(x + 420, y + 452);
  backpackTextArray[10]->setPosition(x + 580, y + 452);
  backpackTextArray[11]->setPosition(x + 728, y + 452);

  if (player->haveSecondWeapon == true) {
    backpackTextArray[12]->setPosition(x + 820, y + 315);
    backpackTextArray[12]->setString(
        "LVL: " + std::to_string(player->currentWeapon->level));
    backpackTextArray[13]->setPosition(x + 820, y + 340);
    backpackTextArray[13]->setString(
        "DAMAGE: " + std::to_string(player->currentWeapon->damage));
    backpackTextArray[14]->setPosition(x + 820, y + 365);
    backpackTextArray[14]->setString(
        "ATACK SPEED: " + std::to_string(player->currentWeapon->atackSpeed));
    backpackTextArray[15]->setPosition(x + 820, y + 390);
    backpackTextArray[15]->setString(
        "BULLET SPEED: " + std::to_string((int)player->currentWeapon->speed));
    backpackTextArray[16]->setPosition(x + 820, y + 415);
    backpackTextArray[16]->setString(
        "FLIGHT TIME: " +
        std::to_string((int)player->currentWeapon->lifetime / 1000));
    backpackTextArray[17]->setPosition(x + 820, y + 440);
    if (player->currentWeapon->level == 5) {
      backpackTextArray[17]->setCharacterSize(17);
      backpackTextArray[17]->setString("UPGRATE COST: MAX");
    } else
      backpackTextArray[17]->setString(
          "UPGRATE COST: " + std::to_string(player->currentWeapon->upgateCost));
  }

  backpackTextArray[18]->setPosition(x + 820, y + 65);
  backpackTextArray[18]->setString(
      "LVL: " + std::to_string(player->currentWeapon->level));
  backpackTextArray[19]->setPosition(x + 820, y + 90);
  backpackTextArray[19]->setString(
      "DAMAGE: " + std::to_string(player->currentWeapon->damage));
  backpackTextArray[20]->setPosition(x + 820, y + 115);
  backpackTextArray[20]->setString(
      "ATACK SPEED: " + std::to_string(player->currentWeapon->atackSpeed));
  backpackTextArray[21]->setPosition(x + 820, y + 140);
  backpackTextArray[21]->setString(
      "BULLET SPEED: " + std::to_string((int)player->currentWeapon->speed));
  backpackTextArray[22]->setPosition(x + 820, y + 165);
  backpackTextArray[22]->setString(
      "FLIGHT TIME: " +
      std::to_string((int)player->currentWeapon->lifetime / 1000));
  backpackTextArray[23]->setPosition(x + 820, y + 190);
  if (player->currentWeapon->level == 5) {
    backpackTextArray[23]->setCharacterSize(17);
    backpackTextArray[23]->setString("UPGRATE COST: MAX");
  } else
    backpackTextArray[23]->setString(
        "UPGRATE COST: " + std::to_string(player->currentWeapon->upgateCost));
}

void Backpack::render(sf::RenderTarget *target) {
  counter = 0;
  for (backpackShape_iter = backpackShapeArray.begin();
       backpackShape_iter != backpackShapeArray.end(); backpackShape_iter++) {
    target->draw(*backpackShapeArray[counter]);
    counter++;
  }

  counter = 0;
  for (backpackText_iter = backpackTextArray.begin();
       backpackText_iter != backpackTextArray.end(); backpackText_iter++) {
    target->draw(*backpackTextArray[counter]);
    counter++;
  }
  target->draw(icon);

  target->draw(*iconCurrentWeapon);
  if (player->haveSecondWeapon == true)
    target->draw(*iconSecondWeapon);
}

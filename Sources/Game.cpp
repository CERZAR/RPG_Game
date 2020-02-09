#include "../Headers/Game.h"

void Game::initVariables()
{

	this->window = nullptr;
	player = new Player(resContainter);
	player->updateStats();
	gameState = GAME;
	player->rect.setPosition(1500, 1300);

	Coin* coin = new Coin(resContainter);
	coin->rect.setPosition(250, 250);
	itemsArray.push_back(coin);

	Health* heal = new Health(resContainter);
	heal->rect.setPosition(350, 250);
	itemsArray.push_back(heal);

	Energy* energy = new Energy(resContainter);
	energy->rect.setPosition(450, 250);
	itemsArray.push_back(energy);

	DefaultWeapon* weapondef = new DefaultWeapon(resContainter);
	weapondef->rect.setPosition(500, 300);
	weapondef->update();
	weaponArray.push_back(weapondef);

	weapondef = new DefaultWeapon(resContainter);
	weapondef->rect.setPosition(600, 300);
	weapondef->level = 2;
	weapondef->update();
	weaponArray.push_back(weapondef);

	weapondef = new DefaultWeapon(resContainter);
	weapondef->rect.setPosition(700, 300);
	weapondef->level = 3;
	weapondef->update();
	weaponArray.push_back(weapondef);

	weapondef = new DefaultWeapon(resContainter);
	weapondef->rect.setPosition(800, 300);
	weapondef->level = 4;
	weapondef->update();
	weaponArray.push_back(weapondef);

	weapondef = new DefaultWeapon(resContainter);
	weapondef->rect.setPosition(900, 300);
	weapondef->level = 5;
	weapondef->update();
	weaponArray.push_back(weapondef);

	Weapon1* weapon = new Weapon1(resContainter);
	weapon->rect.setPosition(500, 350);
	weapon->update();
	weaponArray.push_back(weapon);

	weapon = new Weapon1(resContainter);
	weapon->rect.setPosition(600, 350);
	weapon->level = 2;
	weapon->update();
	weaponArray.push_back(weapon);

	weapon = new Weapon1(resContainter);
	weapon->rect.setPosition(700, 350);
	weapon->level = 3;
	weapon->update();
	weaponArray.push_back(weapon);

	weapon = new Weapon1(resContainter);
	weapon->rect.setPosition(800, 350);
	weapon->level = 4;
	weapon->update();
	weaponArray.push_back(weapon);

	weapon = new Weapon1(resContainter);
	weapon->rect.setPosition(900, 350);
	weapon->level = 5;
	weapon->update();
	weaponArray.push_back(weapon);

	Weapon2* weapon2 = new Weapon2(resContainter);
	weapon2->rect.setPosition(500, 400);
	weapon2->update();
	weaponArray.push_back(weapon2);

	weapon2 = new Weapon2(resContainter);
	weapon2->rect.setPosition(600, 400);
	weapon2->level = 2;
	weapon2->update();
	weaponArray.push_back(weapon2);

	weapon2 = new Weapon2(resContainter);
	weapon2->rect.setPosition(700, 400);
	weapon2->level = 3;
	weapon2->update();
	weaponArray.push_back(weapon2);

	weapon2 = new Weapon2(resContainter);
	weapon2->rect.setPosition(800, 400);
	weapon2->level = 4;
	weapon2->update();
	weaponArray.push_back(weapon2);

	weapon2 = new Weapon2(resContainter);
	weapon2->rect.setPosition(900, 400);
	weapon2->level = 5;
	weapon2->update();
	weaponArray.push_back(weapon2);

	Weapon3* weapon3 = new Weapon3(resContainter);
	weapon3->rect.setPosition(500, 450);
	weapon3->update();
	weaponArray.push_back(weapon3);

	weapon3 = new Weapon3(resContainter);
	weapon3->rect.setPosition(600, 450);
	weapon3->level = 2;
	weapon3->update();
	weaponArray.push_back(weapon3);

	weapon3 = new Weapon3(resContainter);
	weapon3->rect.setPosition(700, 450);
	weapon3->level = 3;
	weapon3->update();
	weaponArray.push_back(weapon3);

	weapon3 = new Weapon3(resContainter);
	weapon3->rect.setPosition(800, 450);
	weapon3->level = 4;
	weapon3->update();
	weaponArray.push_back(weapon3);

	weapon3 = new Weapon3(resContainter);
	weapon3->rect.setPosition(900, 450);
	weapon3->level = 5;
	weapon3->update();
	weaponArray.push_back(weapon3);

	Weapon4* weapon4 = new Weapon4(resContainter);
	weapon4->rect.setPosition(500, 500);
	weapon4->update();
	weaponArray.push_back(weapon4);

	weapon4 = new Weapon4(resContainter);
	weapon4->rect.setPosition(600, 500);
	weapon4->level = 2;
	weapon4->update();
	weaponArray.push_back(weapon4);

	weapon4 = new Weapon4(resContainter);
	weapon4->rect.setPosition(700, 500);
	weapon4->level = 3;
	weapon4->update();
	weaponArray.push_back(weapon4);

	weapon4 = new Weapon4(resContainter);
	weapon4->rect.setPosition(800, 500);
	weapon4->level = 4;
	weapon4->update();
	weaponArray.push_back(weapon4);

	weapon4 = new Weapon4(resContainter);
	weapon4->rect.setPosition(900, 500);
	weapon4->level = 5;
	weapon4->update();
	weaponArray.push_back(weapon4);

	map.createMap();

	// Generate enemies
	for (int i = 1; i < 61; i++)
	{
		Enemy* enemy = new GreenJelly(resContainter);
		while (true)
		{
			enemy->rect.setPosition(GenerateRandomFloat(static_cast<float>(map.startX), static_cast<float>(map.endX)), GenerateRandomFloat(static_cast<float>(map.startY), static_cast<float>(map.endY)));
			if (!map.checkCollision(enemy->rect))
				break;
		}
		enemiesArray.push_back(enemy);
	}
}

void Game::initWindow()
{
	//this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Game", sf::Style::Fullscreen);
	this->window = new sf::RenderWindow(sf::VideoMode(1360, 768), "Game", sf::Style::Close);
	window->setFramerateLimit(120);

	playerView.setSize(sf::Vector2f(static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y)));
	playerView.setCenter(sf::Vector2f(static_cast<float>(window->getSize().x / 2), static_cast<float>(window->getSize().y / 2)));
	playerView.zoom(0.95f);
}

void Game::initGUI()
{
	// Init GUI
	font = *resContainter->pixel_font;

	hp_text.setFont(font);
	hp_text.setCharacterSize(20);
	hp_text.setFillColor(sf::Color::Red);
	gold_text.setFont(font);
	gold_text.setCharacterSize(20);
	gold_text.setFillColor(sf::Color::Yellow);
	mp_text.setFont(font);
	mp_text.setCharacterSize(20);
	mp_text.setFillColor(sf::Color(30, 144, 255));
	lvl_text.setFont(font);
	lvl_text.setCharacterSize(20);
	lvl_text.setFillColor(sf::Color::Magenta);
	exp_text.setFont(font);
	exp_text.setCharacterSize(20);
	exp_text.setFillColor(sf::Color::Cyan);
}

void Game::initPauseState()
{
	pause_rect.setSize(sf::Vector2f(static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y)));
	pause_rect.setFillColor(sf::Color(0, 0, 0, 180));

	pause_text.setFont(font);
	pause_text.setCharacterSize(50);
	pause_text.setFillColor(sf::Color::White);
	pause_text.setString("Game is paused");
}

void Game::initBackpackState()
{
	backpack = new Backpack(resContainter);
}

Game::Game() : map(nullptr) {
	initVariables();
	initWindow();
	initGUI();
	initPauseState();
	initBackpackState();
}

Game::~Game()
{
	counter = 0;
	for (bullet_iter = bulletsArray.begin(); bullet_iter != bulletsArray.end(); bullet_iter++)
	{
		delete bulletsArray[counter];
		counter++;
	}

	counter = 0;
	for (enemy_iter = enemiesArray.begin(); enemy_iter != enemiesArray.end(); enemy_iter++)
	{
		delete enemiesArray[counter];
		counter++;
	}

	counter = 0;
	for (text_iter = textsArray.begin(); text_iter != textsArray.end(); text_iter++)
	{
		delete textsArray[counter];
		counter++;
	}

	counter = 0;
	for (item_iter = itemsArray.begin(); item_iter != itemsArray.end(); item_iter++)
	{
		delete itemsArray[counter];
		counter++;
	}

	counter = 0;
	for (weapon_iter = weaponArray.begin(); weapon_iter != weaponArray.end(); weapon_iter++)
	{
		delete weaponArray[counter];
		counter++;
	}

	delete this->window;
}

void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window->close();
		if (this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::P)
		{
			if (gameState == PAUSE) gameState = GAME;
			else gameState = PAUSE;
		}
		if (this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::B)
		{
			if (gameState == BACKPACK) gameState = GAME;
			else gameState = BACKPACK;
		}
	}
}

void Game::updateGUI()
{
	hp_text.setString("HP: " + std::to_string(player->hp) + "/" + std::to_string(player->maxHP));
	hp_text.setPosition(player->rect.getPosition().x - window->getSize().x / 2 + window->getSize().x / 36, player->rect.getPosition().y - window->getSize().y / 2 + 21);
	mp_text.setString("MP: " + std::to_string(player->mp) + "/" + std::to_string(player->maxMP));
	mp_text.setPosition(player->rect.getPosition().x - window->getSize().x / 2 + window->getSize().x / 36, player->rect.getPosition().y - window->getSize().y / 2 + 41);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
	{
		gold_text.setString("Gold: " + std::to_string(player->coins));
		gold_text.setPosition(player->rect.getPosition().x - window->getSize().x / 2 + window->getSize().x / 36, player->rect.getPosition().y - window->getSize().y / 2 + 61);
		lvl_text.setString("Level: " + std::to_string(player->level));
		lvl_text.setPosition(player->rect.getPosition().x - window->getSize().x / 2 + window->getSize().x / 36, player->rect.getPosition().y - window->getSize().y / 2 + 81);
		exp_text.setString("Exp: " + std::to_string(player->exp) + "/" + std::to_string(player->needExp));
		exp_text.setPosition(player->rect.getPosition().x - window->getSize().x / 2 + window->getSize().x / 36, player->rect.getPosition().y - window->getSize().y / 2 + 101);
	}
}

void Game::updatePressings()
{
	// Update mouse scroll (zoom +/-)
	if (this->event.type == sf::Event::MouseWheelScrolled)
	{
		if (event.mouseWheelScroll.delta > 0)
		{
			if (zoom >= -100)
			{
				zoom -= 1;
				playerView.zoom(0.995f);
			}
		}
		else
		{
			if (zoom < 100)
			{
				zoom += 1;
				playerView.zoom(1.005f);
			}
		}
	}

	// Update middle mouse press (default zoom)
	if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
	{
		zoom = 0;
		playerView.setSize(sf::Vector2f(static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y)));
		playerView.zoom(0.95f);
	}

	// Update space press (Atack)
	if (bullets_timer.asMilliseconds() >= player->currentWeapon->atackSpeed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player->direction >= 0 && player->mp > 0)
		{
			player->mp--;
			if (player->currentWeapon->level == 5)
			{
				Bullet* bullet = player->currentWeapon->getBullet(UP);
				bullet->rect.setPosition(player->rect.getPosition().x + player->rect.getSize().x / 2 - bullet->rect.getSize().x / 2,
					player->rect.getPosition().y + player->rect.getSize().y / 2 - bullet->rect.getSize().y / 2);
				bullet->isPlayerBullet = true;
				bulletsArray.push_back(bullet);
				bullet = player->currentWeapon->getBullet(DOWN);
				bullet->rect.setPosition(player->rect.getPosition().x + player->rect.getSize().x / 2 - bullet->rect.getSize().x / 2,
					player->rect.getPosition().y + player->rect.getSize().y / 2 - bullet->rect.getSize().y / 2);
				bullet->isPlayerBullet = true;
				bulletsArray.push_back(bullet);
				bullet = player->currentWeapon->getBullet(RIGHT);
				bullet->rect.setPosition(player->rect.getPosition().x + player->rect.getSize().x / 2 - bullet->rect.getSize().x / 2,
					player->rect.getPosition().y + player->rect.getSize().y / 2 - bullet->rect.getSize().y / 2);
				bullet->isPlayerBullet = true;
				bulletsArray.push_back(bullet);
				bullet = player->currentWeapon->getBullet(LEFT);
				bullet->rect.setPosition(player->rect.getPosition().x + player->rect.getSize().x / 2 - bullet->rect.getSize().x / 2,
					player->rect.getPosition().y + player->rect.getSize().y / 2 - bullet->rect.getSize().y / 2);
				bullet->isPlayerBullet = true;
				bulletsArray.push_back(bullet);
			}
			else if (player->currentWeapon->level == 4)
			{
				if (player->direction == UP || player->direction == DOWN)
				{
					Bullet* bullet = player->currentWeapon->getBullet(UP);
					bullet->rect.setPosition(player->rect.getPosition().x + player->rect.getSize().x / 2 - bullet->rect.getSize().x / 2,
						player->rect.getPosition().y + player->rect.getSize().y / 2 - bullet->rect.getSize().y / 2);
					bullet->isPlayerBullet = true;
					bulletsArray.push_back(bullet);
					bullet = player->currentWeapon->getBullet(DOWN);
					bullet->rect.setPosition(player->rect.getPosition().x + player->rect.getSize().x / 2 - bullet->rect.getSize().x / 2,
						player->rect.getPosition().y + player->rect.getSize().y / 2 - bullet->rect.getSize().y / 2);
					bullet->isPlayerBullet = true;
					bulletsArray.push_back(bullet);
				}
				else
				{
					Bullet* bullet = player->currentWeapon->getBullet(RIGHT);
					bullet->rect.setPosition(player->rect.getPosition().x + player->rect.getSize().x / 2 - bullet->rect.getSize().x / 2,
						player->rect.getPosition().y + player->rect.getSize().y / 2 - bullet->rect.getSize().y / 2);
					bullet->isPlayerBullet = true;
					bulletsArray.push_back(bullet);
					bullet = player->currentWeapon->getBullet(LEFT);
					bullet->rect.setPosition(player->rect.getPosition().x + player->rect.getSize().x / 2 - bullet->rect.getSize().x / 2,
						player->rect.getPosition().y + player->rect.getSize().y / 2 - bullet->rect.getSize().y / 2);
					bullet->isPlayerBullet = true;
					bulletsArray.push_back(bullet);
				}
			}
			else
			{
				Bullet* bullet = player->currentWeapon->getBullet(player->direction);
				bullet->rect.setPosition(player->rect.getPosition().x + player->rect.getSize().x / 2 - bullet->rect.getSize().x / 2,
					player->rect.getPosition().y + player->rect.getSize().y / 2 - bullet->rect.getSize().y / 2);
				bullet->isPlayerBullet = true;
				bulletsArray.push_back(bullet);
			}
			bullets_clocker.restart();
		}
	}

	// Delete this later
	if (bullets_timer.asMilliseconds() >= 1)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			GreenJelly* enemy = new GreenJelly(resContainter);
			enemy->rect.setPosition(static_cast<float>(GenerateRandomInt(window->getSize().x)), static_cast<float>(GenerateRandomInt(window->getSize().y)));
			enemiesArray.push_back(enemy);
			bullets_clocker.restart();
			counter++;
		}
	}
}

void Game::updateCollisions()
{
	// Enemy & bullets collision
	counter = 0;
	for (bullet_iter = bulletsArray.begin(); bullet_iter != bulletsArray.end(); bullet_iter++)
	{
		counter1 = 0;
		for (enemy_iter = enemiesArray.begin(); enemy_iter != enemiesArray.end(); enemy_iter++)
		{
			if (bulletsArray[counter]->rect.getGlobalBounds().intersects(enemiesArray[counter1]->rect.getGlobalBounds()) &&
                bulletsArray[counter]->isPlayerBullet)
			{
				if (bulletsArray[counter]->isPlayerBullet && !enemiesArray[counter1]->isAgro)
				{
					enemiesArray[counter1]->isAgro = true;
					enemiesArray[counter1]->movementSpeed *= 1.5;
				}
				CollisionText* text = new CollisionText("-" + std::to_string(bulletsArray[counter]->damage),
					"pixel_font", 24, 6000);
				text->text.setPosition(enemiesArray[counter1]->rect.getPosition().x,
					enemiesArray[counter1]->rect.getPosition().y);
				text->color = sf::Color(255, 36, 0, 255);
				textsArray.push_back(text);
				enemiesArray[counter1]->hp -= bulletsArray[counter]->damage;
				bulletsArray[counter]->isExist = false;
			}
			counter1++;
		}
		counter++;
	}

	// Enemies & map collision
	counter = 0;
	for (enemy_iter = enemiesArray.begin(); enemy_iter != enemiesArray.end(); enemy_iter++)
	{
		map.checkEnemyCollision(enemiesArray[counter]);
		counter++;
	}

	// Enemies & map collision
	counter = 0;
	for (bullet_iter = bulletsArray.begin(); bullet_iter != bulletsArray.end(); bullet_iter++)
	{
		map.checkBulletCollision(bulletsArray[counter]);
		counter++;
	}

	// Player & enemies collision
	counter = 0;
	for (enemy_iter = enemiesArray.begin(); enemy_iter != enemiesArray.end(); enemy_iter++)
	{
		if (player_enemy_collision_timer.asMilliseconds() >= 1000) // update every 1 sec
		{
			if (player->rect.getGlobalBounds().intersects(enemiesArray[counter]->rect.getGlobalBounds()))
			{
				if (!enemiesArray[counter]->isAgro)
				{
					enemiesArray[counter]->isAgro = true;
					enemiesArray[counter]->movementSpeed *= 1.5;
				}
				CollisionText* text = new CollisionText("-" + std::to_string(enemiesArray[counter]->damage),
					"pixel_font", 30, 6000);
				text->text.setPosition(player->rect.getPosition().x, player->rect.getPosition().y);
				text->color = sf::Color(255, 36, 0, 255);
				textsArray.push_back(text);
				player->hp -= enemiesArray[counter]->damage;

				CollisionText* text1 = new CollisionText("-" + std::to_string(player->damage),
					"pixel_font", 24, 6000);
				text1->text.setPosition(enemiesArray[counter]->rect.getPosition().x,
					enemiesArray[counter]->rect.getPosition().y);
				text1->color = sf::Color(255, 36, 0, 255);
				textsArray.push_back(text1);
				enemiesArray[counter]->hp -= player->damage;
				player_enemy_collision_clocker.restart();
			}
			counter++;
		}
	}

	// Player & coins collision
	counter = 0;
	for (item_iter = itemsArray.begin(); item_iter != itemsArray.end(); item_iter++)
	{
		if (player->rect.getGlobalBounds().intersects(itemsArray[counter]->rect.getGlobalBounds()) &&
			itemsArray[counter]->type == COIN)
		{
			player->coins += 5;
			itemsArray[counter]->isExist = false;
		}
		counter++;
	}

	// Player & health collision
	counter = 0;
	for (item_iter = itemsArray.begin(); item_iter != itemsArray.end(); item_iter++)
	{
		if (player->rect.getGlobalBounds().intersects(itemsArray[counter]->rect.getGlobalBounds()) &&
			itemsArray[counter]->type == HEALTH)
		{
			if (player->hp < player->maxHP) player->hp += 1;
			itemsArray[counter]->isExist = false;
		}
		counter++;
	}

	// Player & energy collision
	counter = 0;
	for (item_iter = itemsArray.begin(); item_iter != itemsArray.end(); item_iter++)
	{
		if (player->rect.getGlobalBounds().intersects(itemsArray[counter]->rect.getGlobalBounds()) &&
			itemsArray[counter]->type == ENERGY)
		{
			if (player->mp < player->maxMP) player->mp += 5;
			itemsArray[counter]->isExist = false;
		}
		counter++;
	}

	// Player & weapons collision
	counter = 0;
	for (weapon_iter = weaponArray.begin(); weapon_iter != weaponArray.end(); weapon_iter++)
	{
		if (player->rect.getGlobalBounds().intersects(weaponArray[counter]->rect.getGlobalBounds()) &&
			weaponArray[counter]->type == WEAPON)
		{
			weaponArray[counter]->rect.setOutlineColor(sf::Color::White);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !player->haveSecondWeapon)
			{
				player->takeSecondWeapon(weaponArray[counter]);
				weaponArray[counter]->isExist = false;
			}
		}
		counter++;
	}

	// Player & map collision
	map.checkPlayerCollision(player);
}

void Game::deleteNonexistent()
{
	// Deleting enemies
	counter = 0;
	for (enemy_iter = enemiesArray.begin(); enemy_iter != enemiesArray.end(); enemy_iter++)
	{
		if (!enemiesArray[counter]->isExist)
		{
			player->exp += enemiesArray[counter]->getExp;
			//int random = GenerateRandomInt(10);
			//if (random >= 1 && random <= 3) // 30% - coin
			//{
				Coin* coin = new Coin(resContainter);
				coin->rect.setPosition(enemiesArray[counter]->rect.getPosition());
				itemsArray.push_back(coin);
			//}
			enemiesArray.erase(enemy_iter);
			break;
		}
		counter++;
	}

	// Deleting bullets
	counter = 0;
	for (bullet_iter = bulletsArray.begin(); bullet_iter != bulletsArray.end(); bullet_iter++)
	{
		if (!bulletsArray[counter]->isExist)
		{
			bulletsArray.erase(bullet_iter);
			break;
		}
		counter++;
	}

	// Deleting texts
	counter = 0;
	for (text_iter = textsArray.begin(); text_iter != textsArray.end(); text_iter++)
	{
		if (!textsArray[counter]->isExist)
		{
			textsArray.erase(text_iter);
			break;
		}
		counter++;
	}

	// Deleting items
	counter = 0;
	for (item_iter = itemsArray.begin(); item_iter != itemsArray.end(); item_iter++)
	{
		if (!itemsArray[counter]->isExist)
		{
			itemsArray.erase(item_iter);
			break;
		}
		counter++;
	}

	// Deleting weapons
	counter = 0;
	for (weapon_iter = weaponArray.begin(); weapon_iter != weaponArray.end(); weapon_iter++)
	{
		if (!weaponArray[counter]->isExist)
		{
			weaponArray.erase(weapon_iter);
			break;
		}
		counter++;
	}
}

void Game::renderGUI()
{
	window->draw(hp_text);
	window->draw(mp_text);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
	{
		window->draw(gold_text);
		window->draw(lvl_text);
		window->draw(exp_text);
	}
}

void Game::backpackState()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		this->window->close();
	timer = clocker.getElapsedTime();
	backpack->setPosition(player->rect.getPosition().x, player->rect.getPosition().y);
	backpack->update(player);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) && player->haveSecondWeapon)
	{
		Weapon* weapon = player->throwSecondWeapon();
		weapon->rect.setPosition(player->rect.getPosition().x, player->rect.getPosition().y);
		weapon->update();
		weapon->isExist = true;
		weaponArray.push_back(weapon);
	}
	if (timer.asMilliseconds() >= 500)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && player->haveSecondWeapon)
		{
			Weapon* temp_weapon = player->currentWeapon;
			player->currentWeapon = player->secondWeapon;
			player->secondWeapon = temp_weapon;
			player->currentWeapon->updateStats();
			clocker.restart();
		}
	}
	if (timer.asMilliseconds() >= 500)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && player->haveSecondWeapon)
		{
			if (player->coins >= player->secondWeapon->upgateCost && player->secondWeapon->level < 5)
			{
				player->coins -= player->secondWeapon->upgateCost;
				player->secondWeapon->updateLevel();
				player->secondWeapon->updateStats();
				player->secondWeapon->update();
				clocker.restart();
			}
		}
	}
	if (timer.asMilliseconds() >= 500)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			if (player->coins >= player->currentWeapon->upgateCost && player->currentWeapon->level < 5)
			{
				player->coins -= player->currentWeapon->upgateCost;
				player->currentWeapon->updateLevel();
				player->currentWeapon->updateStats();
				player->currentWeapon->update();
				clocker.restart();
			}
		}
	}
	pause_rect.setPosition(player->rect.getPosition().x - window->getSize().x / 2, player->rect.getPosition().y - window->getSize().y / 2);
	window->draw(pause_rect);
	backpack->render(window);
	this->window->display();
}

void Game::pauseState()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		this->window->close();
	pause_text.setPosition(player->rect.getPosition().x - window->getSize().x / 16, player->rect.getPosition().y - window->getSize().y / 16);
	window->draw(pause_rect);
	window->draw(pause_text);
	this->window->display();
}

void Game::update()
{
	bullets_timer = bullets_clocker.getElapsedTime();
	player_enemy_collision_timer = player_enemy_collision_clocker.getElapsedTime();
	timer = clocker.getElapsedTime();

	// Update

	// Update map
	map.update();

	// Update player
	this->player->update();

	// Update pressings
	updatePressings();

	// Update bullets
	counter = 0;
	for (bullet_iter = bulletsArray.begin(); bullet_iter != bulletsArray.end(); bullet_iter++)
	{
		bulletsArray[counter]->update();
		counter++;
	}

	// Update enemies
	counter = 0;
	for (enemy_iter = enemiesArray.begin(); enemy_iter != enemiesArray.end(); enemy_iter++)
	{
		enemiesArray[counter]->update(static_cast<int>(player->rect.getPosition().x), static_cast<int>(player->rect.getPosition().y));
		counter++;
	}

	// Update items
	counter = 0;
	for (item_iter = itemsArray.begin(); item_iter != itemsArray.end(); item_iter++)
	{
		itemsArray[counter]->update();
		counter++;
	}

	// Update weapons
	counter = 0;
	for (weapon_iter = weaponArray.begin(); weapon_iter != weaponArray.end(); weapon_iter++)
	{
		weaponArray[counter]->updateOutline();
		counter++;
	}

	// Update text
	counter = 0;
	for (text_iter = textsArray.begin(); text_iter != textsArray.end(); text_iter++)
	{
		textsArray[counter]->update();
		counter++;
	}

	// Update gui
	updateGUI();

	// Update collisions
	updateCollisions();

	// Delete
	deleteNonexistent();
}

void Game::render()
{
	this->window->clear();

	// Render

	// Render map
	map.renderGround(this->window);
	map.render(this->window);

	// Render items
	counter = 0;
	for (item_iter = itemsArray.begin(); item_iter != itemsArray.end(); item_iter++)
	{
		itemsArray[counter]->render(this->window);
		counter++;
	}

	// Render weapons
	counter = 0;
	for (weapon_iter = weaponArray.begin(); weapon_iter != weaponArray.end(); weapon_iter++)
	{
		weaponArray[counter]->render(this->window);
		counter++;
	}

	// Render bullets
	counter = 0;
	for (bullet_iter = bulletsArray.begin(); bullet_iter != bulletsArray.end(); bullet_iter++)
	{
		bulletsArray[counter]->render(this->window);
		counter++;
	}

	// Render enemies
	counter = 0;
	for (enemy_iter = enemiesArray.begin(); enemy_iter != enemiesArray.end(); enemy_iter++)
	{
		enemiesArray[counter]->render(this->window);
		counter++;
	}

	// Render player
	this->player->render(this->window);

	// Render player_view
	playerView.setCenter(player->rect.getPosition());
	window->setView(playerView);

	// Render text
	counter = 0;
	for (text_iter = textsArray.begin(); text_iter != textsArray.end(); text_iter++)
	{
		textsArray[counter]->render(this->window);
		counter++;
	}

	// Render gui
	renderGUI();

	if (gameState == GAME) this->window->display();
}

void Game::run()
{
	// The game loop 
	while (this->window->isOpen())
	{
		this->updateSFMLEvents();
		if (gameState == GAME) update();
		render();
		if (gameState == PAUSE) pauseState();
		if (gameState == BACKPACK) backpackState();
	}
}



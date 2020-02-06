/**
 * @file Game.h
 * @brief A file containing a description of the main class of the game
 */
#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Random.h"
#include "CollisionText.h"
#include "Map.h"
#include "ResourcesContainer.h"
// Enemies
#include "GreenJelly.h"
#include "Goblin.h"
// Items
#include "Coin.h"
#include "Health.h"
#include "Energy.h"
// Weapons
#include "DefaultWeapon.h"
#include "Weapon1.h"
#include "Weapon2.h"
#include "Weapon3.h"
#include "Weapon4.h"
// Bullets
#include "DefaultBullet.h"

#include "Backpack.h"

enum { GAME, PAUSE, BACKPACK, SHOP }; ///< all game states
/**
 * @brief Main game class
 */
class Game
{
private:
	// All variables
	ResourcesContainer* resContainter = new ResourcesContainer; ///< resorces container (include all textures and fonts)

	sf::RenderWindow* window; ///< Main window
	sf::Event event; ///< sfml events
	int gameState; ///< game states. 1 - GAME 2 - PAUSE 3 - BACKPACK 4 - SHOP

	Player* player; ///< Player
	Map map; ///< Map
	sf::View playerView; ///< current player's view
	int zoom = 0; ///< limitation for zoom view

	std::vector<Bullet*>::const_iterator bullet_iter; ///< iterator for bullets vector
	std::vector<Bullet*> bulletsArray; ///< vector contains all bullet objects

	std::vector<Enemy*>::const_iterator enemy_iter; ///< iterator for enemies vector
	std::vector<Enemy*> enemiesArray; ///< vector contains all enemies objects

	std::vector<textDisplay*>::const_iterator text_iter; ///< iterator for text vector
	std::vector<textDisplay*> textsArray; ///< vector contains all texts

	std::vector<Item*>::const_iterator item_iter; ///< iterator for weapon item vector
	std::vector<Item*> itemsArray; ///< vector contains all item objects

	std::vector<Weapon*>::const_iterator weapon_iter; ///< iterator for weapon vector
	std::vector<Weapon*> weaponArray; ///< vector contains all weapon objects

	sf::Clock bullets_clocker; ///< clocker for updating player atack
	sf::Clock player_enemy_collision_clocker; ///< clocker for updating player and enemies collisions
	sf::Time bullets_timer; ///< timer for updating player atack
	sf::Time player_enemy_collision_timer; ///< timer for updating player and enemies collisions
	sf::Time timer; ///< just usual timer
	sf::Clock clocker; ///< just usual clocker
	int counter; ///< counter for any
	int counter1; ///< counter for any
	// GUI
	sf::Font font; ///< text font

	sf::Text hp_text; ///< player's hp_text
	sf::Text gold_text; ///< player's gold_text

	sf::Text mp_text; ///< player's mp_text
	sf::Text lvl_text; ///< player's lvl_text
	sf::Text exp_text; ///< player's exp_text

	// Initialization function

	/**
	 * @brief Method initiallizing all variables
	 */
	void initVariables();
	/**
	 * @brief Method initiallizing game window
	 */
	void initWindow();
	/**
	 * @brief Method initiallizing game GUI
	 */
	void initGUI();
	/**
	 * @brief Method initiallizing pause state
	 */
	void initPauseState();
	/**
	 * @brief Method initiallizing backpack State
	 */
	void initBackpackState();

	// Functions
	/**
	 * @brief Method updating all game processes 
	 */
	void update();
	/**
	 * @brief Method rendering(drawing) all game objects
	 */
	void render();

	// Update functions
	/**
	 * @brief Method updateing all sfml events (such as button pressing, closing window, etc)
	 */
	void updateSFMLEvents();
	/**
	 * @brief Method updateing GUI
	 */
	void updateGUI();
	/**
	 * @brief Method updateing all keyboard and mouse buttons pressings
	 */
	void updatePressings();
	/**
	 * @brief Method updateing all object collisions
	 */
	void updateCollisions();
	/**
	 * @brief Method deleting all objects that was destroyed at this cycle(frame)
	 */
	void deleteNonexistent();

	// Render functions
		/**
	 * @brief Method rendering(drawing) GUI
	 */
	void renderGUI();

	// Game states
	/**
	 * @brief Method describing backpack state
	 */
	void backpackState();
	Backpack* backpack; ///< backpack
	/**
	 * @brief Method describing pause state
	 */
	void pauseState();
	sf::Text pause_text; ///< pause text
	sf::RectangleShape pause_rect; ///< dimming area during pause
public:
	// Functions
	Game();
	virtual ~Game();

	/**
	 * @brief Method runnig the game
	 */
	void run();
};

#endif //GAME_H

/**
 * @file Weapon4.h
 * @brief A file containing a description of the weapon4 class
 */
#ifndef WEAPON4_H
#define WEAPON4_H
#include "Weapon.h"
#include "../Headers/Bullet4.h"
 /**
  * @brief weapon4 class
  */
class Weapon4 :
	public Weapon
{
public:
	Weapon4(ResourcesContainer* res);
	virtual ~Weapon4();
	void update();
	void render(sf::RenderTarget* target);
	void updateStats();
	Bullet* getBullet(int direction);
};

#endif //WEAPON4_H

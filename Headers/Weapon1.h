/**
 * @file Weapon1.h
 * @brief A file containing a description of the weapon1 class
 */
#ifndef WEAPON1_H
#define WEAPON1_H

#include "Weapon.h"
#include "../Headers/Bullet1.h"
 /**
  * @brief weapon1 class
  */
class Weapon1 :
	public Weapon
{
public:
	Weapon1(ResourcesContainer* res);
	virtual ~Weapon1();
	void update();
	void render(sf::RenderTarget* target);
	void updateStats();
	Bullet* getBullet(int direction);
};

#endif //WEAPON1_H
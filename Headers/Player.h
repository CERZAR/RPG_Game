#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"
#include "../Headers/DefaultWeapon.h"
#include "Weapon1.h"
#include "Weapon2.h"
#include "Weapon3.h"
#include "Weapon4.h"

class Player : public Object
{
private:
	// Variables
	int counterWalking = 0;
	int slowWalk = 0;
	// Functions
	void initVariables();
	void initStats();
public:
	// Variables
	Weapon* currentWeapon;
	Weapon* secondWeapon;
	int level;
	int coins;
	int needExp;
	int exp;
	int maxMP;
	int mp;
	bool haveSecondWeapon;
	// Functions
	Player(ResourcesContainer* res);
	virtual ~Player();
	void update();
	void updateStats();
	void takeSecondWeapon(Weapon* pWeapon);
	Weapon* throwSecondWeapon();
};

#endif //PLAYER_H

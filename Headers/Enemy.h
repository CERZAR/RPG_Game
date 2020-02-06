#ifndef ENEMY_H
#define ENEMY_H

#include "Object.h"

class Enemy :
	public Object
{
protected:
	int distanceLength;
	int distanceCounter = 0;
	int animationCounter = 0;
	int animationSlow = 0;
	void initVariables();
public:
	bool isAgro;
	int getExp;
	Enemy(ResourcesContainer* res);
	virtual void update(int playerX, int playerY);
	virtual ~Enemy();
};

#endif //ENEMY_H

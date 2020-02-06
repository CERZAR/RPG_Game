#pragma once
#include "Bullet.h"
class Bullet3 :
	public Bullet
{
public:
	Bullet3(int damage, float speed, int direction, float lifetime, ResourcesContainer* res);
	virtual ~Bullet3();
	void update();
};


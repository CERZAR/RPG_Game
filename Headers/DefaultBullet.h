#pragma once
#include "Bullet.h"
class DefaultBullet :
	public Bullet
{
public:
	DefaultBullet(int damage, float speed, int direction, float lifetime, ResourcesContainer* res);
	virtual ~DefaultBullet();
	void update();
};


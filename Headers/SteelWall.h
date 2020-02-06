#ifndef STEELWALL_H
#define STEELWALL_H

#include "MapObject.h"
class SteelWall :
	public MapObject
{
public:
	SteelWall(sf::Sprite* sprite, float x, float y);
	virtual ~SteelWall();
};

#endif //STEELWALL_H

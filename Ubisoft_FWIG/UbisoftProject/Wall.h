#pragma once

#include "AABB.h"
#include "Obstacle.h"
class CSimpleSprite;

class Wall : public Obstacle
{
public:
	Wall(float posX, float posY);
	virtual ~Wall();
	virtual void deplacementBox(int direction);
	virtual int areColliding(const AABB& box1, const AABB& box2);


protected:
	
};

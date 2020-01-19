#pragma once

#include "AABB.h"
#include "Obstacle.h"
class CSimpleSprite;

class Box : public Obstacle
{
public: 
	Box(float posX, float posY);
	virtual ~Box();
	virtual void deplacementBox(int direction);
	virtual int areColliding(const AABB& box1, const AABB& box2);

};


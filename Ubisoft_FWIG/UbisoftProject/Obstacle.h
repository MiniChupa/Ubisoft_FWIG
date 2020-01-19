#pragma once

#include "AABB.h"


class CSimpleSprite;
class Obstacle
{

public:
	Obstacle();
	virtual ~Obstacle();

	void Render();
	void Update();
	//void DebugRender();
	const AABB& GetAABB() const { return m_box; };
	virtual void deplacementBox(int direction) = 0;
	virtual int areColliding(const AABB& box1, const AABB& box2) = 0;

protected:
	AABB m_box;
	CSimpleSprite* m_sprite;

	void UpdateAABB();

};


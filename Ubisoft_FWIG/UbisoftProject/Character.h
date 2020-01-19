#pragma once

#include "AABB.h"
class CSimpleSprite;

class Character
{
public:
	Character();
	~Character();

	void Update(float deltaTime);
	void Render();
	//void DebugRender();
	void SetOldPosition();
	const AABB& GetAABB() const { return m_box; };

	
	

private:

	CSimpleSprite* m_sprite;
	float ancienX, ancienY;
	AABB m_box;
	void UpdateAABB();

};


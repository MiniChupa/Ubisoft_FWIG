#include "Wall.h"
#include "stdafx.h"
#include "app.h"

Wall::Wall(float posX, float posY)
{
	m_sprite = App::CreateSprite(".\\Data\\wall.bmp");
	m_sprite->SetPosition(posX, posY);
	m_sprite->SetScale(1.0f);
}

Wall::~Wall()
{
	delete m_sprite;
}

void Wall::deplacementBox(int direction)
{
	return;
}

int Wall::areColliding(const AABB& box1, const AABB& box2)
{
	return 0;
}




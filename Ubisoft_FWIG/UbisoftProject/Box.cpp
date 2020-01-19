
#include "Box.h"
#include "stdafx.h"
#include "app.h"

Box::Box(float posX, float posY)
{
	m_sprite = App::CreateSprite(".\\Data\\box.bmp");
	m_sprite->SetPosition(posX, posY);
	m_sprite->SetScale(1.0f);
}

Box::~Box()
{
	delete m_sprite;
}

int Box::areColliding(const AABB& box1, const AABB& box2)
{
	if (box1.x2 >= box2.x1 &&
		box1.x2 <= box2.x2 &&
		box1.y2 < box2.y2 && 
		box1.y1 > box2.y1)
	{
		return 1; //déplacement droite
	}

	if (box1.x1 <= box2.x2 && 
		box1.x2 >= box2.x2 &&
		box1.y2 < box2.y2 &&
		box1.y1 > box2.y1)
	{

		return 2; //deplacement gauche
	}

	if (box1.y2 >= box2.y2 && 
		box1.y1 <= box2.y2 && 
		box1.x1 > box2.x1 &&
		box1.x2 < box2.x2)
	{
		return 3; //deplacement bas
	}

	if (box1.y2 >= box2.y1 && 
		box1.y1 <= box2.y1 &&
		box1.x1 > box2.x1 && 
		box1.x2 < box2.x2)
	{
		return 4; //deplacement haut
	}
}


void Box::deplacementBox(int direction)
{
	float x, y;
	float deplacement = 64;
	if (direction == 1)
	{
		m_sprite->GetPosition(x, y);
		x += deplacement;
		m_sprite->SetPosition(x, y);
	}
	if (direction == 2)
	{
		m_sprite->GetPosition(x, y);
		x -= deplacement;
		m_sprite->SetPosition(x, y);
	}
	if (direction == 3)
	{
		m_sprite->GetPosition(x, y);
		y -= deplacement;
		m_sprite->SetPosition(x, y);
	}
	if (direction == 4)
	{
		m_sprite->GetPosition(x, y);
		y += deplacement;
		m_sprite->SetPosition(x, y);
	}

	UpdateAABB();
}

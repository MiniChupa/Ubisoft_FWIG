#include "stdafx.h"
#include "Character.h"

#include "app.h"

Character::Character()
{
	m_sprite = App::CreateSprite(".\\Data\\pokemon.bmp");
	m_sprite->SetPosition(192.0f, 448.0f);
	m_sprite->SetScale(1.0f);
}

Character::~Character()
{
	delete m_sprite;
}

void Character::Update(float deltaTime)
{
	const float SPEED = .15f;

	float deplacement = SPEED * deltaTime;
	if (App::GetController().GetLeftThumbStickX() > 0.5f)
	{
		float x, y;
		m_sprite->GetPosition(x, y);
		ancienX = x;
		ancienY = y;
		x += deplacement;
		m_sprite->SetPosition(x, y);
		if (!App::IsSoundPlaying(".\\Data\\footstep.wav"))
		{
			App::StartSound(".\\Data\\footstep.wav");
		}
	}
	else if (App::GetController().GetLeftThumbStickX() < -0.5f)
	{
		float x, y;
		m_sprite->GetPosition(x, y);
		ancienX = x;
		ancienY = y;
		x -= deplacement;
		m_sprite->SetPosition(x, y);
		if (!App::IsSoundPlaying(".\\Data\\footstep.wav"))
		{
			App::StartSound(".\\Data\\footstep.wav");
		}
	}
	else if (App::GetController().GetLeftThumbStickY() > 0.5f)
	{
		float x, y;
		m_sprite->GetPosition(x, y);
		ancienX = x;
		ancienY = y;
		y += deplacement;
		m_sprite->SetPosition(x, y);
		if (!App::IsSoundPlaying(".\\Data\\footstep.wav"))
		{
			App::StartSound(".\\Data\\footstep.wav");
		}
	}
	else if (App::GetController().GetLeftThumbStickY() < -0.5f)
	{
		float x, y;
		m_sprite->GetPosition(x, y);
		ancienX = x;
		ancienY = y;
		y -= deplacement;
		m_sprite->SetPosition(x, y);
		if (!App::IsSoundPlaying(".\\Data\\footstep.wav"))
		{
			App::StartSound(".\\Data\\footstep.wav");
		}
	}
	
	UpdateAABB();
}

void Character::UpdateAABB()
{
	
	float x = 0.f;
	float y = 0.f;
	float width = m_sprite->GetWidth();
	float height = m_sprite->GetHeight();
	m_sprite->GetPosition(x, y);

	m_box.x1 = x - width * 0.5f;
	m_box.y1 = y - height * 0.5f;
	m_box.x2 = x + width * 0.5f;
	m_box.y2 = y + height * 0.5f;

}

/*void Character::DebugRender()
{
	float x = 0.f;
	float y = 0.f;
	m_sprite->GetPosition(x, y);
	float width = m_sprite->GetWidth();
	float height = m_sprite->GetHeight();

	float xMinPos = x - width * 0.5f;
	float yMinPos = y - height * 0.5f;
	float xMaxPos = x + width * 0.5f;
	float yMaxPos = y + height * 0.5f;

	App::DrawLine(xMinPos, yMinPos, xMaxPos, yMinPos, 1.f, 1.f, 0.f);
	App::DrawLine(xMaxPos, yMinPos, xMaxPos, yMaxPos, 1.f, 1.f, 0.f);
	App::DrawLine(xMaxPos, yMaxPos, xMinPos, yMaxPos, 1.f, 1.f, 0.f);
	App::DrawLine(xMinPos, yMaxPos, xMinPos, yMinPos, 1.f, 1.f, 0.f);
}*/

void Character::SetOldPosition()
{
	m_sprite->SetPosition(ancienX, ancienY);
}

void Character::Render()
{
	m_sprite->Draw();
	//DebugRender();
}




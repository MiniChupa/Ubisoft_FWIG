#include "Obstacle.h"
#include "stdafx.h"
#include "app.h"

Obstacle::Obstacle()
{
	m_sprite = nullptr;
}

Obstacle::~Obstacle()
{
	delete m_sprite;
}

void Obstacle::Update()
{
	UpdateAABB();
}

void Obstacle::UpdateAABB()
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

void Obstacle::Render()
{
	m_sprite->Draw();
	//DebugRender();

}

/*void Obstacle::DebugRender()
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
#include "stdafx.h"
#include "Door.h"

#include "app.h"

Door::Door(float xCenterPos, float yCenterPos, float width, float height) : m_rColor(0.0f), m_gColor(1.0f), m_bColor(1.0f)
{
	m_box.x1 = xCenterPos - width * 0.5f;
	m_box.x2 = xCenterPos + width * 0.5f;
	m_box.y1 = yCenterPos - height * 0.5f;
	m_box.y2 = yCenterPos + height * 0.5f;
}

Door::~Door()
{
}

void Door::Update(float deltaTime)
{
	float colorDelta = 0.2f * deltaTime / 1000.0f;

	m_rColor = fmodf(m_rColor + colorDelta, 1.f);
	m_gColor = fmodf(m_gColor + colorDelta, 1.f);
	m_bColor = fmodf(m_bColor + colorDelta, 1.f);
}

void Door::Render()
{
	
	App::DrawLine(m_box.x1, m_box.y1, m_box.x2, m_box.y1, m_rColor, m_gColor, m_bColor);
	App::DrawLine(m_box.x2, m_box.y1, m_box.x2, m_box.y2, m_rColor, m_gColor, m_bColor);
	App::DrawLine(m_box.x2, m_box.y2, m_box.x1, m_box.y2, m_rColor, m_gColor, m_bColor);
	App::DrawLine(m_box.x1, m_box.y2, m_box.x1, m_box.y1, m_rColor, m_gColor, m_bColor);
}


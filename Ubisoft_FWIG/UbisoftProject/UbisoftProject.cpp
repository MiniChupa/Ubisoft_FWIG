#include "stdafx.h"
#include <Windows.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <string>

#include "app.h"
#include "AppSettings.h"
#include "Character.h"
#include "Box.h"
#include "Wall.h"
#include "Obstacle.h"
#include "AABB.h"
#include "Door.h"

#include <vector>

using namespace std;


const int TAILLE_IMG = 64;
const int NB_CASE_X = APP_VIRTUAL_WIDTH / TAILLE_IMG;
const int NB_CASE_Y = APP_VIRTUAL_HEIGHT / TAILLE_IMG;

Character* m_character = nullptr;
Door* m_door = nullptr;
Box* m_box = nullptr;
int i, j = 0;

vector < vector <Obstacle*>> mapVisu;

int mapTerrainBase[NB_CASE_Y][NB_CASE_X] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
										0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
										0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
										0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,
										0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,
										0,1,0,0,0,0,0,1,1,1,1,1,0,0,0,1,
										0,1,0,0,0,0,0,2,0,0,0,0,0,0,0,1,
										0,1,0,0,0,0,0,1,1,1,1,1,0,0,0,1,
										0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,
										0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,
										0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
										0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int mapTerrain[NB_CASE_Y][NB_CASE_X];

enum GameState
{
	RUNNING,
	WIN
};

GameState globalState = RUNNING;

void Init()
{
	globalState == RUNNING;
	m_character = new Character();
	m_door = new Door(894, 384, 64, 64);
	App::StartSound(".\\Data\\ambiance.wav",true);
	for (i = 0; i < NB_CASE_Y; i++)
	{
		for (j = 0; j < NB_CASE_X; j++)
		{
			mapTerrain[i][j] = mapTerrainBase[i][j];
		}
	}

	for (i = 0; i < NB_CASE_Y; i++)
	{
		vector <Obstacle*> row;
		for (j = 0; j < NB_CASE_X; j++)
		{
			switch (mapTerrain[i][j]) {
			case 0: row.push_back(nullptr);
					break;
			case 1: row.push_back(new Wall(j*TAILLE_IMG, i*TAILLE_IMG));
					row[j]->Update();
					break;
			case 2: row.push_back(nullptr);
					m_box = new Box(j * TAILLE_IMG, i * TAILLE_IMG);
					break;
			}

		}
		mapVisu.push_back(row);
	}
}

void Update(float deltaTime)
{
	
	m_character->Update(deltaTime);
	m_door->Update(deltaTime);
	m_box->Update();

	int deplacement = 0;

	if (globalState == RUNNING)
	{
		if (areColliding(m_character->GetAABB(), m_door->GetAABB()))
		{
			App::StartSound(".\\Data\\victory.wav");
			globalState = WIN;
		}

		for (i = 0; i < NB_CASE_Y; i++)
		{
			for (j = 0; j < NB_CASE_X; j++)
			{
				if (mapVisu[i][j] != nullptr)
				{
					if (areColliding(m_character->GetAABB(), mapVisu[i][j]->GetAABB()))
					{
						m_character->SetOldPosition();
					}
				}

				if (mapTerrain[i][j] == 2)
				{
					deplacement = m_box->areColliding(m_character->GetAABB(), m_box->GetAABB());
					if (deplacement == 1) //droite
					{
						if (mapTerrain[i][j + 1] == 1)
						{
							deplacement = 0;
							mapTerrain[i][j] = 2;
							if (areColliding(m_character->GetAABB(), m_box->GetAABB()))
							{
								m_character->SetOldPosition();
							}
						}
						else {
							m_box->deplacementBox(deplacement);
							App::StartSound(".\\Data\\box_friction.wav");
							mapTerrain[i][j] = 0;
							mapTerrain[i][j + 1] = 2;
						}
					}
					if (deplacement == 2) //gauche
					{
						if (mapTerrain[i][j - 1] == 1)
						{
							deplacement = 0;
							mapTerrain[i][j] = 2;
							if (areColliding(m_character->GetAABB(), m_box->GetAABB()))
							{
								m_character->SetOldPosition();
							}
						}
						else {
							m_box->deplacementBox(deplacement);
							App::StartSound(".\\Data\\box_friction.wav");
							mapTerrain[i][j] = 0;
							mapTerrain[i][j - 1] = 2;
						}
					}
					if (deplacement == 3) //bas
					{
						if (mapTerrain[i-1][j] == 1)
						{
							deplacement = 0;
							mapTerrain[i][j] = 2;
							if (areColliding(m_character->GetAABB(), m_box->GetAABB()))
							{
								m_character->SetOldPosition();
							}
						}
						else {
							m_box->deplacementBox(deplacement);
							App::StartSound(".\\Data\\box_friction.wav");
							mapTerrain[i][j] = 0;
							mapTerrain[i-1][j] = 2;
						}
					}
					if (deplacement == 4) //haut
					{
						if (mapTerrain[i+1][j] == 1)
						{
							deplacement = 0;
							mapTerrain[i][j] = 2;
							if (areColliding(m_character->GetAABB(), m_box->GetAABB()))
							{
								m_character->SetOldPosition();
							}
						}
						else {
							m_box->deplacementBox(deplacement);
							App::StartSound(".\\Data\\box_friction.wav");
							mapTerrain[i][j] = 0;
							mapTerrain[i+1][j] = 2;
						}
					}
				}	
				
			}
		}
		
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_B, true))
	{
		
		exit(0);
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_X, true))
	{
		Init();
		globalState = RUNNING;
	}
}

void Render()
{
	m_door->Render();
	m_character->Render();
	m_box->Render();
	App::Print(10, 700, "X to restart, B to quit");
	for (i = 0; i < NB_CASE_Y; i++)
	{
		for (j = 0; j < NB_CASE_X; j++)
		{
			if (mapVisu[i][j] != nullptr)
			{
				mapVisu[i][j]->Render();
			}
		}
	}

	if (globalState == WIN)
	{
		App::Print(520, 370, "FREEDOM !", 1.0f, 1.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24);
		
	}
}

void Shutdown()
{
	delete m_character;
}

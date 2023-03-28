#include "GameScreenLevel1.h"
#include "Texture2D.h"
#include "Collisions.h"
#include "PowBlock.h"
#include <iostream>

GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel();
}

GameScreenLevel1::~GameScreenLevel1()
{
	delete m_background_texture;
	m_background_texture = nullptr;

	delete my_character_mario;
	my_character_mario = nullptr;

	delete my_character_luigi;
	my_character_luigi = nullptr;

	delete m_pow_block;
	m_pow_block = nullptr;

	m_enemies.clear();
}

void GameScreenLevel1::Render()
{
	for (int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies[i]->Render();
	}

	m_background_texture->Render(Vector2D(0, m_background_yPos), SDL_FLIP_NONE);
	my_character_mario->Render();
	my_character_luigi->Render();
	m_pow_block->Render();
}

void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{
	if (m_screenshake)
	{
		m_shake_time -= deltaTime;
		m_wobble++;
		m_background_yPos = sin(m_wobble);
		m_background_yPos *= 3.0f;

		if (m_shake_time <= 0.0f)
		{
			m_screenshake = false;
			m_background_yPos = 0.0f;
		}
	}

	my_character_mario->Update(deltaTime, e);
	my_character_luigi->Update(deltaTime, e);
	UpdatePowBlock();
	UpdateEnemies(deltaTime, e);

	/*if (Collisions::Instance()->Circle(my_character_mario, my_character_luigi))
	{
		cout << "Circle hit!" << endl;
	}
	if (Collisions::Instance()->Box(my_character_mario->GetCollisionBox(), my_character_luigi->GetCollisionBox()))
	{
		cout << "Box hit!" << endl;
 	}
	if (Collisions::Instance()->Circle2(my_character_mario->GetCollisionCircle(), my_character_luigi->GetCollisionCircle()))
	{
		cout << "Cricle2 hit!" << endl;
	}*/
}

void GameScreenLevel1::UpdatePowBlock()
{
	if (Collisions::Instance()->Box(my_character_mario->GetCollisionBox(), m_pow_block->GetCollisionBox()))
	{
		if (m_pow_block->IsAvailable())
		{
			if (my_character_mario->IsJumping())
			{
				cout << "Character POW Collision" << endl;
				DoScreenShake();
				m_pow_block->TakeHit();
				my_character_mario->CancelJump();
			}
		}
	}
}

void GameScreenLevel1::SetLevelMap()
{
	int map[MAP_HEIGHT][MAP_WIDTH] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0},
		{1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	if (m_level_map != nullptr)
	{
		delete m_level_map;
	}
	m_level_map = new LevelMap(map);
}

bool GameScreenLevel1::SetUpLevel()
{
	SetLevelMap();

	my_character_mario = new CharacterMario(m_renderer, "Images/Mario.png", Vector2D(64, 330), m_level_map);
	my_character_luigi = new CharacterLuigi(m_renderer, "Images/Luigi.png", Vector2D(104, 330), m_level_map);

	m_pow_block = new PowBlock(m_renderer, m_level_map);
	m_screenshake = false;
	m_background_yPos = 0.0f;

	m_background_texture = new Texture2D(m_renderer);

	if (!m_background_texture->LoadFromFile("Images/BackgroundMB.png"))
	{
		std::cout << "Failed to load background texture!" << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}

void GameScreenLevel1::DoScreenShake()
{
	m_screenshake = true;
	m_shake_time = SHAKE_DURATION;
	m_wobble = 0.0f;
}

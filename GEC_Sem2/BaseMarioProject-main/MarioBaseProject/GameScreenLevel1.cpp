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

	delete m_coin_sound;
	m_coin_sound = nullptr;

	m_enemies.clear();

	m_coins.clear();
}

void GameScreenLevel1::Render()
{
	for (int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies[i]->Render();
	}

	for (int i = 0; i < m_coins.size(); i++)
	{
		m_coins[i]->Render();
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

	koopaCountdown -= deltaTime;
	if (koopaCountdown <= 0.0f)
	{
		CreateKoopa(Vector2D(150, 32), FACING_RIGHT, KOOPA_SPEED);
		koopaCountdown = 8.0f;
	}

	coinCountdown -= deltaTime;
	if (coinCountdown <= 0.0f)
	{
		CreateCoin(Vector2D(247, 16));
		coinCountdown = 15.0f;
	}

	my_character_mario->Update(deltaTime, e);
	my_character_luigi->Update(deltaTime, e);
	UpdatePowBlock();
	UpdateEnemies(deltaTime, e);
	UpdateCoins(deltaTime);

	m_camera.x = my_character_mario->GetPosition().x;
	if (m_camera.x < 0)
	{
		m_camera.x = 0;
	}
	if (m_camera.x > LEVEL_WIDTH - m_camera.w)
	{
		m_camera.x = LEVEL_WIDTH - m_camera.w;
	}

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
				std::cout << "POW Block Hit" << std::endl;
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
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0},
		{1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
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

	m_coin_sound = new SoundEffect("SoundFx/Coin.mp3");

	m_pow_block = new PowBlock(m_renderer, m_level_map);

	CreateKoopa(Vector2D(150, 32), FACING_RIGHT, KOOPA_SPEED);
	CreateKoopa(Vector2D(325, 32), FACING_RIGHT, KOOPA_SPEED);

	CreateCoin(Vector2D(247, 16));

	points = 0;

	m_screenshake = false;
	m_background_yPos = 0.0f;

	koopaCountdown = 8.0f;
	coinCountdown = 15.0f;

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

	for (unsigned int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies[i]->TakeDamage();
	}
}

void GameScreenLevel1::UpdateEnemies(float deltaTime, SDL_Event e)
{
	if (!m_enemies.empty())
	{
		int enemyIndexToDelete = -1;
		for (unsigned int i = 0; i < m_enemies.size(); i++)
		{
			// check if off screen to left/right
			if (m_enemies[i]->GetPosition().x < (float)(-m_enemies[i]->GetCollisionBox().width * 0.5f) || m_enemies[i]->GetPosition().x > SCREEN_WIDTH - (float)(m_enemies[i]->GetCollisionBox().width * 0.55f))
			{
				m_enemies[i]->FlipDirection();
			}
			// check if at the bottom
			if (m_enemies[i]->GetPosition().y > 400.0f)
			{
				m_enemies[i]->SetAlive(false);
			}

			m_enemies[i]->Update(deltaTime, e);

			//check for player collision
			if ((m_enemies[i]->GetPosition().y > 300.0f || m_enemies[i]->GetPosition().y <= 64.0f) && (m_enemies[i]->GetPosition().x < 64.0f || m_enemies[i]->GetPosition().x > SCREEN_WIDTH - 96.0f))
			{
				// ignore if behind pipe
			}
			else
			{
				if (Collisions::Instance()->Circle(m_enemies[i], my_character_mario))
				{
					if (m_enemies[i]->GetInjured())
					{
						m_enemies[i]->SetAlive(false);
					}
					else
					{
						//kill mario
					}
				}
			}
			
			if (!m_enemies[i]->GetAlive())
			{
				enemyIndexToDelete = i;
			}
		}
		
		if (enemyIndexToDelete != -1)
		{
			m_enemies.erase(m_enemies.begin() + enemyIndexToDelete);
		}
	}
}

void GameScreenLevel1::CreateKoopa(Vector2D position, FACING direction, float speed)
{
	CharacterKoopa* koopa = new CharacterKoopa(m_renderer, "Images/Koopa.png", m_level_map, position, direction, speed);
	m_enemies.push_back(koopa);
}

void GameScreenLevel1::CreateCoin(Vector2D position)
{
	CharacterCoin* coin = new CharacterCoin(m_renderer, "Images/Coin.png", position, m_level_map);
	m_coins.push_back(coin);
}

void GameScreenLevel1::UpdateCoins(float deltaTime)
{
	if (!m_coins.empty())
	{
		int coinIndexToDelete = -1;

		for (int i = 0; i < m_coins.size(); i++)
		{
			if (Collisions::Instance()->Circle(m_coins[i], my_character_mario))
			{
				m_coins[i]->SetAlive(false);
				m_coin_sound->Play(0);
			}

			m_coins[i]->Update(deltaTime);

			if (!m_coins[i]->GetAlive())
			{
				coinIndexToDelete = i;
			}
		}


		if (coinIndexToDelete != -1)
		{
			m_coins.erase(m_coins.begin() + coinIndexToDelete);
		}
	}
}

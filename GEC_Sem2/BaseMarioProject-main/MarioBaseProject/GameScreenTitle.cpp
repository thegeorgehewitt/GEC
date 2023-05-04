#include "GameScreenTitle.h"
#include "Texture2D.h"
#include <iostream>

GameScreenTitle::GameScreenTitle(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel();
}

GameScreenTitle::~GameScreenTitle()
{
	delete m_background_texture;
	m_background_texture = nullptr;
}

void GameScreenTitle::Render()
{
	m_background_texture->Render(Vector2D(), SDL_FLIP_NONE);
}

void GameScreenTitle::Update(float deltaTime, SDL_Event e) {}

bool GameScreenTitle::SetUpLevel()
{
	m_background_texture = new Texture2D(m_renderer);
	if (!m_background_texture->LoadFromFile("Images/TitleScreen.png"))
	{
		std::cout << "Failed to load background texture!" << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}
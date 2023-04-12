#include "GameScreenManager.h"
#include "GameScreen.h"
#include "GameScreenLevel1.h"
#include "GameScreenTitle.h"

GameScreenManager::GameScreenManager(SDL_Renderer* renderer, SCREENS startScreen) 
{
	m_renderer = renderer;
	m_current_screen = nullptr;
	ChangeScreen(startScreen);
}
GameScreenManager::~GameScreenManager()
{
	m_renderer = nullptr;
	delete m_current_screen;
	m_current_screen = nullptr;
}

void GameScreenManager::Render()
{
	m_current_screen->Render();
}

void GameScreenManager::Update(float deltaTime, SDL_Event e)
{
	m_current_screen->Update(deltaTime, e);
}

void GameScreenManager::ChangeScreen(SCREENS new_screen)
{
	if (m_current_screen != nullptr)
	{
		delete m_current_screen;
	}

	GameScreenLevel1* tempScreen;
	GameScreenTitle* tempScreen2;

	switch (new_screen)
	{
	case SCREEN_LEVEL1:
		std::cout << "new gamescreenlevel1 created" << std::endl;
		tempScreen = new GameScreenLevel1(m_renderer);
		m_current_screen = (GameScreen*)tempScreen;
		tempScreen = nullptr;
		break;
	case SCREEN_INTRO:
		tempScreen2 = new GameScreenTitle(m_renderer);
		m_current_screen = (GameScreen*)tempScreen2;
		tempScreen2 = nullptr;
		break;
	default:;
	}
}

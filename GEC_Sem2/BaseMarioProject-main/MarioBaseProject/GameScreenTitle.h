#pragma once
#ifndef _GAMESCREENTITLE_H
#define _GAMESCREENTITLE_H

#include "GameScreen.h"
#include "Commons.h"

class Texture2D;

class GameScreenTitle : GameScreen
{
private:
	Texture2D* m_background_texture;

	bool SetUpLevel();
public:
	GameScreenTitle(SDL_Renderer* renderer);
	~GameScreenTitle();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;
};

#endif _GAMESCREENTITLE_H


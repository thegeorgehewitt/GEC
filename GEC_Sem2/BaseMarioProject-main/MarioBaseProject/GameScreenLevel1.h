#pragma once
#ifndef _GAMESCREENLEVEL1_H
#define _GAMESCREENLEVEL1_H

#include "GameScreen.h"
#include "Commons.h"

class GameScreenLevel1 : GameScreen
{
	class Texture2D;
public:
	SDL_Renderer* renderer;
/*protected:
	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();*/
};

#endif _GAMESCREENLEVEL1_H
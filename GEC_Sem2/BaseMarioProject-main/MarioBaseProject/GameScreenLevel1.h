#pragma once
#ifndef _GAMESCREENLEVEL1_H
#define _GAMESCREENLEVEL1_H

#include "GameScreen.h"
#include "Commons.h"
#include "Character.h"
#include "CharacterMario.h"
#include "CharacterLuigi.h"
#include "LevelMap.h"

class Texture2D;
class Character;
class PowBlock;

class GameScreenLevel1 : GameScreen
{
private:
	Texture2D* m_background_texture;
	Character* my_character_mario;
	Character* my_character_luigi;
	LevelMap* m_level_map;
	PowBlock* m_pow_block;

	void SetLevelMap();
	bool SetUpLevel();
public:
	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;
	void UpdatePowBlock();
};

#endif _GAMESCREENLEVEL1_H
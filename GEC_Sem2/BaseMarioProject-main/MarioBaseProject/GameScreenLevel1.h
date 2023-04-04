#pragma once
#ifndef _GAMESCREENLEVEL1_H
#define _GAMESCREENLEVEL1_H

#include "GameScreen.h"
#include "Commons.h"
#include "Character.h"
#include "CharacterMario.h"
#include "CharacterLuigi.h"
#include "CharacterKoopa.h"
#include "LevelMap.h"
#include "CharacterCoin.h"
#include "SoundEffect.h"
#include <vector>

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
	SoundEffect* m_coin_sound;

	bool m_screenshake;
	float m_shake_time;
	float m_wobble;
	float m_background_yPos;
	float koopaCountdown;
	float coinCountdown;
	float points;
	vector<CharacterKoopa*> m_enemies;
	vector<CharacterCoin*> m_coins;

	void SetLevelMap();
	bool SetUpLevel();
	void DoScreenShake();
	void UpdateEnemies(float deltaTime, SDL_Event e);
	void CreateKoopa(Vector2D position, FACING direction, float speed);
	void CreateCoin(Vector2D position);
	void UpdateCoins(float deltaTime);
public:
	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;
	void UpdatePowBlock();
};

#endif _GAMESCREENLEVEL1_H
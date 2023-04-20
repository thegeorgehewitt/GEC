#pragma once
#ifndef _CHARACTERCOIN_H
#define _CHARACTERCOIN_H

#include "Character.h"

class CharacterCoin : public Character
{
public:
	CharacterCoin(SDL_Renderer* renderer, string imagePath, Vector2D start_position, LevelMap* map);
	~CharacterCoin();

	void Update(float deltaTime);
	void Render(SDL_Rect camera_rect);

	float m_frame_delay;
private:
	float m_single_sprite_w;
	float m_single_sprite_h;
	float m_current_frame;
};

#endif _CHARACTERCOIN_H
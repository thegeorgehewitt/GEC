#pragma once
#ifndef _CHARACTERLUIGI_H
#define _CHARACTERLUIGI_H

#include "Character.h"

class CharacterLuigi : public Character
{
public:
	CharacterLuigi(SDL_Renderer* renderer, string imagePath, Vector2D start_position);
	void Update(float deltaTime, SDL_Event e);
private:
	FACING m_facing_direction;
};

#endif _CHARACTERLUIGI_H
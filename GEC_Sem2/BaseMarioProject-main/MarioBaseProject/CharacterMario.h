#pragma once
#ifndef _CHARACTERMARIO_H
#define _CHARACTERMARIO_H

#include "Character.h"
#include "SoundEffect.h"

class CharacterMario : public Character
{
public:
	CharacterMario(SDL_Renderer* renderer, string imagePath, Vector2D start_position, LevelMap* map);
	
	void Update(float deltaTime, SDL_Event e);
	void Jump(float deltaTime);
private:
	FACING m_facing_direction;
	SoundEffect* m_jump_sound;
};

#endif _CHARACTERMARIO_H
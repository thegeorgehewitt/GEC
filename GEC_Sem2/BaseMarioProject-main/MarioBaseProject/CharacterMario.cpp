#include "CharacterMario.h"

//CharacterMario::CharacterMario(SLD_Renderer* renderer, string imagePath, Vector2D start_position) : Character(renderer, imagePath, start_position)
//{
//}
//
//CharacterMario::~CharacterMario()
//{
//
//}

void CharacterMario::Update(float deltaTime, SDL_Event e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_RIGHT:
			m_moving_right = true;
			break;
		case SDLK_LEFT:
			m_moving_left = true;
			break;
		case SDLK_UP:
			if (m_can_jump)
			{
				Jump(deltaTime);
				m_can_jump = false;
			}
		}
		break;

	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_RIGHT:
			if (e.key.repeat == 0)
			{
				m_moving_right = false;
			}
			break;
		case SDLK_LEFT:
			if (e.key.repeat == 0)
			{
				m_moving_left = false;
			}
			break;
		}
		break;
	}

	Character::Update(deltaTime, e)
}
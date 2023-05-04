#include "CharacterKoopa.h"

CharacterKoopa::CharacterKoopa(SDL_Renderer* renderer, string imagePath, LevelMap* map, Vector2D start_position, FACING start_facing, float movement_speed) : Character(renderer, imagePath, start_position, map)
{
	m_facing_direction = start_facing;
	m_movement_speed = movement_speed;
	m_position = start_position;
	m_injured = false;
	m_injured_time = 0.0f;

	m_single_sprite_w = m_texture->GetWidth() / 2;
	m_single_sprite_h = m_texture->GetHeight();
}

void CharacterKoopa::TakeDamage()
{
	m_injured = true;
	m_injured_time = INJURED_TIME;
	Jump();
}

void CharacterKoopa::Jump()
{
	if (!m_jumping)
	{
		m_jump_force = INITIAL_JUMP_FORCE_SMALL;
		m_jumping = true;
		m_can_jump = false;
	}
}


void CharacterKoopa::FlipRightwayUp()
{
	if (m_facing_direction = FACING_LEFT)
	{
		m_facing_direction = FACING_RIGHT;
	}
	else
	{
		m_facing_direction = FACING_LEFT;
	}

	m_jumping = false;

	Jump();
}

void CharacterKoopa::Render(SDL_Rect camera_rect)
{
	//left pos of sprite we want to draw
	int left = 0.0f;

	if (m_injured)
	{
		left = m_single_sprite_w;
	}

	SDL_Rect portion_of_sprite = { left, 0, m_single_sprite_w, m_single_sprite_h };

	SDL_Rect destRect = { (int)(m_position.x) - camera_rect.x, (int)(m_position.y) - camera_rect.y, m_single_sprite_w, m_single_sprite_h };

	if (m_facing_direction == FACING_RIGHT)
	{
		m_texture->Render(portion_of_sprite, destRect, SDL_FLIP_NONE);
	}
	else
	{
		m_texture->Render(portion_of_sprite, destRect, SDL_FLIP_HORIZONTAL);
	}
}

void CharacterKoopa::Update(float deltaTime, SDL_Event e)
{
	Character::Update(deltaTime, e);

	if (!m_injured)
	{
		if (m_facing_direction == FACING_LEFT)
		{
			m_moving_left = true;
			m_moving_right = false;
		}
		else if (m_facing_direction == FACING_RIGHT)
		{
			m_moving_left = false;
			m_moving_right = true;
		}
	}
	else
	{
		m_moving_right = false;
		m_moving_left = false;

		m_injured_time -= deltaTime;

		if (m_injured_time <= 0.0)
		{
			FlipRightwayUp();
			m_injured = false;
		}
	}

	if (m_position.x <= 0 && m_position.y < 300)
	{
		m_facing_direction == FACING_RIGHT;
		m_moving_left = false;
		m_moving_right = true;
	}

	if (m_position.x >= LEVEL_WIDTH && m_position.y < 300)
	{
		m_facing_direction == FACING_LEFT;
		m_moving_left = true;
		m_moving_right = false;
	}

}

void CharacterKoopa::FlipDirection()
{
	if (m_facing_direction = FACING_LEFT)
	{
		m_facing_direction = FACING_RIGHT;
	}
	else
	{
		m_facing_direction = FACING_LEFT;
	}
}

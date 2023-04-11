#pragma once
#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <SDL.h>
#include <iostream>
#include "Commons.h"
#include "Texture2D.h"
#include "LevelMap.h"
#include <string>

using namespace std;

class Texture2D;

class Character
{
private:
protected:
	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;
	LevelMap* m_current_level_map;
	bool m_moving_left;
	bool m_moving_right;
	bool m_can_jump;
	bool m_jumping;
	bool m_alive;
	float m_jump_force;
	float m_collision_radius;
	float m_movement_speed;
	FACING m_facing_direction;
	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);
	virtual void AddGravity(float deltaTime);
	virtual void Jump(float deltaTime);

	SDL_Rect src_rect;
	SDL_Rect dest_rect;
public:
	Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position, LevelMap* map);
	~Character();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	void SetPosition(Vector2D new_position);
	Vector2D GetPosition();
	float GetCollisionRadius();
	Rect2D GetCollisionBox() { return Rect2D(m_position.x, m_position.y, m_texture->GetWidth(), m_texture->GetHeight()); }
	Circle2D GetCollisionCircle() { return Circle2D(m_position.x, m_position.y, m_texture->GetWidth()); }
	void CancelJump() { m_jumping = false; }
	bool IsJumping() { if (m_jumping) { return true; } else { return false; } }
	void SetAlive(bool IsAlive) { m_alive = IsAlive; }
	bool GetAlive() { return m_alive; }
};

#endif _CHARACTER_H
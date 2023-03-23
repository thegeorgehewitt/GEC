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
	FACING m_facing_direction;
protected:
	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;
	LevelMap* m_current_level_map;
	bool m_moving_left;
	bool m_moving_right;
	bool m_can_jump;
	bool m_jumping;
	float m_jump_force;
	float m_collision_radius;
	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);
	virtual void AddGravity(float deltaTime);
	virtual void Jump(float deltaTime);
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
};

#endif _CHARACTER_H
#pragma once
#ifndef _SOUNDEFFECT_H
#define _SOUNDEFFECT_H

#include <iostream>
#include <string>
#include <SDL_mixer.h>

class SoundEffect
{
public:
	SoundEffect(std::string soundPath);
	~SoundEffect();

	void Play(int looping);
	bool Load(std::string soundPath);
	void Free();
private:
	Mix_Chunk* m_sound;
};

#endif _SOUNDEFFECT_H
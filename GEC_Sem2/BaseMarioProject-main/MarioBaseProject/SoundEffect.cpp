#include "SoundEffect.h"

SoundEffect::SoundEffect(std::string soundPath)
{
	m_sound = nullptr;

	Load(soundPath);
}

SoundEffect::~SoundEffect()
{
	Free();
}

void SoundEffect::Play(int loops)
{
	Mix_PlayChannel(-1, m_sound, loops);
}

bool SoundEffect::Load(std::string soundPath)
{
	Free();

	m_sound = Mix_LoadWAV(soundPath.c_str());
	if (m_sound == nullptr)
	{
		std::cout << "Failed to load jump sound effect. Error: " << Mix_GetError() << std::endl;
		return false;
	}

	return true;
}

void SoundEffect::Free()
{
	Mix_FreeChunk(m_sound);
	m_sound = nullptr;
}

#pragma once
#ifndef _TEXTRENDERER_H
#define _TEXTRENDERER_H

#include <SDL.h>
#include <string>
#include <SDL_ttf.h>
using namespace std;

class TextRenderer
{
public:
	TextRenderer(SDL_Renderer* renderer);
	~TextRenderer();

	void Render(int x, int y);
	bool LoadFont(const string& path, float fontSize, const string message, SDL_Color colour);

private:
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	mutable SDL_Rect text_rect;
	TTF_Font* font;
};

#endif _TEXTRENDERER_H
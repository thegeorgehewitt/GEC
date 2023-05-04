#include "TextRenderer.h"
#include <iostream>

TextRenderer::TextRenderer(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}

TextRenderer::~TextRenderer()
{
	m_renderer = nullptr;
}

void TextRenderer::Render(int x, int y)
{
	text_rect->x = x;
	text_rect->y = y;

	SDL_RenderCopy(m_renderer, m_texture, nullptr, text_rect);
}

bool TextRenderer::LoadFont(const std::string path, float fontSize, const std::string message, SDL_Color colour)
{
	font = TTF_OpenFont(path.c_str(), fontSize);
	if (!font)
	{
		cout << "Font could not be loaded." << endl;
		return false;
	}
	else
	{
		SDL_Surface* text_surface = TTF_RenderText_Solid(font, message.c_str(), colour);
		if (!text_surface)
		{
			cout << "Surface could not be loaded." << endl;
			return false;
		}
		else
		{
			m_texture = SDL_CreateTextureFromSurface(m_renderer, text_surface);
			if (!m_texture)
			{
				cout << "Texture could not be loaded." << endl;
				return false;
			}

			SDL_FreeSurface(text_surface);
			TTF_CloseFont(font);

			SDL_QueryTexture(m_texture, nullptr, nullptr, &text_rect->w, &text_rect->h);

			return m_texture;
		}
	}


}
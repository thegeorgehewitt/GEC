//Be grateful for humble beginnings, because the next level will always require so much more of you

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "constants.h"

#include <iostream>
using namespace std;

//Globals
SDL_Window* g_window = nullptr;
SDL_Renderer* g_renderer = nullptr;
SDL_Texture* g_texture = nullptr;

//Function prototypes
bool InitSDL();
void CloseSDL();
bool Update();
void Render(float angle);
SDL_Texture* LoadTextureFromFile(string path);
void FreeTexture();
float ChangeAngle();

int main(int argc, char* args[])
{
	float angle = 0;

	//check if sdl was setup correctly
	if (InitSDL())
	{
		bool quit = false;

		// Game Loop
		while (!quit)
		{
			Render(angle);
			quit = Update();
			angle += ChangeAngle();
		}
	}

	CloseSDL();

	return 0;
}

bool InitSDL()
{
	//Setup SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL did not initialise. Error: " << SDL_GetError();
		return false;
	}
	else
	{
		//setup passed so create window
		g_window = SDL_CreateWindow("Games Engine Creation",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);

		//did the window get created?
		if (g_window == nullptr)
		{
			//window failed
			cout << "Window was not created. Error: " << SDL_GetError();
			return false;
		}

		g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);

		if (g_renderer != nullptr)
		{
			int imageFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imageFlags) & imageFlags))
			{
				cout << "SDL_Image could not intialise. Error: " << IMG_GetError();
				return false;
			}
		}
		else
		{
			cout << "Renderer could not initialise. Error: " << SDL_GetError();
			return false;
		}

		//Load the background texture
		g_texture = LoadTextureFromFile("Images/test.bmp");
		if (g_texture == nullptr)
		{
			return false;
		}
	}

	return true;
}
void CloseSDL()
{
	//release the window
	SDL_DestroyWindow(g_window);
	g_window = nullptr;

	//clear the texture
	FreeTexture();
	//release the renderer
	SDL_DestroyRenderer(g_renderer);
	g_renderer = nullptr;

	//quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

bool Update()
{
	//Event Handler
	SDL_Event e;

	//get events
	SDL_PollEvent(&e);

	//handle events
	switch (e.type)
	{
	case SDL_QUIT:
		return true;
		break;
	case SDL_MOUSEBUTTONDOWN:
		return true;
		break;
	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_q:
			return true;
			break;
		}	
	}

	return false;
}

void Render(float angle)
{
	//Clear the screen
	SDL_SetRenderDrawColor(g_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(g_renderer);

	//Set where to render the texture
	SDL_Rect renderLocation = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };

	//Render to screen
	SDL_RenderCopyEx(g_renderer, g_texture, NULL, &renderLocation, angle, NULL, SDL_FLIP_NONE);

	//Update the screeb
	SDL_RenderPresent(g_renderer);
}

SDL_Texture* LoadTextureFromFile(string path)
{
	//Remove memory used for prev texture
	FreeTexture();

	SDL_Texture* p_texture = nullptr;

	//Load the image
	SDL_Surface* p_surface = IMG_Load(path.c_str());
	if (p_surface != nullptr)
	{
		//Create the texture from the pixels on the surface
		p_texture = SDL_CreateTextureFromSurface(g_renderer, p_surface);
		if (p_texture == nullptr)
		{
			cout << "Unable to create texture from surface. Error: " << SDL_GetError();
		}

		//Remove the loaded surface
		SDL_FreeSurface(p_surface);
	}
	else
	{
		cout << "Unable to create texture from surface. Error: " << IMG_GetError();
	}

	return p_texture;
}

void FreeTexture()
{
	//Check if texture exists before removing it
	if (g_texture != nullptr)
	{
		SDL_DestroyTexture(g_texture);
		g_texture = nullptr;
	}
}

float ChangeAngle()
{
	SDL_Event(event);

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_KEYUP:
		switch (event.key.keysym.sym)
		{
		case SDLK_RIGHT:
			return 5;
			break;
		case SDLK_LEFT:
			return -5;
			break;
		}
	}

	return 0;
}
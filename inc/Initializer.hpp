#pragma once
#include "load_media.hpp"
#include <vector>
#include "utils.h"

class Initializer
{
public:
	bool init_SDL(SDL_Window **window,SDL_Surface **window_surface,SDL_Renderer **renderer,int *screen_height,int *screen_width);

	SDL_Window *init_window(int screen_height,int screen_width);

	SDL_Surface *init_window_surface(SDL_Window *window);

	void close(SDL_Window *window, SDL_Renderer *renderer/*,std::vector<SDL_Texture *> texture*/);
};
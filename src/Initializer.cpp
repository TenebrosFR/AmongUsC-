#include "Initializer.hpp"

bool Initializer::init_SDL(SDL_Window **window, SDL_Surface **window_surface,SDL_Renderer **renderer,int *screen_height,int *screen_width)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "SDL could not initialize. SDL_Error: " << SDL_GetError() << '\n';
		return false;
	}
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM); 
    *screen_width = DM.w-100;
    *screen_height = DM.h-100;
	*window = init_window(*screen_height,*screen_width);
	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(*renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	*window_surface = init_window_surface(*window);
	return !(*window == NULL) && !(*window_surface == NULL) ;
}

SDL_Window *Initializer::init_window(int screen_height,int screen_width)
{
	SDL_Window *window;

	if ((window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN)) == NULL)
	{
		std::cerr << "Window could not be created. SDL_Error: " << SDL_GetError() << '\n';
		return NULL;
	}
	return window;
}

SDL_Surface *Initializer::init_window_surface(SDL_Window *window)
{
	SDL_Surface *surface;

	if ((surface = SDL_GetWindowSurface(window)) == NULL)
	{
		std::cerr << "Window surface could not be created. SDL_Error: " << SDL_GetError() << '\n';
		return NULL;
	}
	return surface;
}

void Initializer::close(SDL_Window *window, SDL_Renderer *renderer/*,std::vector<SDL_Texture *> texture*/)
{
	// for (std::vector<SDL_Texture *>::iterator it = texture.begin(); it != texture.end(); ++it)
	// {
	// 	SDL_DestroyTexture(*it);
	// 	*it = NULL;
	// }
	SDL_DestroyWindow(window);
	window = NULL;
	if (renderer != NULL)
	{
		SDL_DestroyRenderer(renderer);
		renderer = NULL;
	}
	SDL_Quit();
}
#include "load_media.hpp"
#include <vector>
#include "utils.h"
class Initializer
{
public:
	bool init_SDL(SDL_Window **window, /*std::vector<SDL_Texture *> *texture,*/ SDL_Surface **window_surface,SDL_Renderer **renderer,int screen_height,int screen_width)
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			std::cerr << "SDL could not initialize. SDL_Error: " << SDL_GetError() << '\n';
			return false;
		}
		*window = init_window(screen_height,screen_width);
		*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
		SDL_SetRenderDrawColor(*renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		*window_surface = init_window_surface(*window);
		// (*texture)[SPACE] = load_media_texture("ratio.bmp",*renderer ,true);
		// (*texture)[UP] = load_media_texture("up.bmp",*renderer ,true);
		// (*texture)[DOWN] = load_media_texture("down.bmp",*renderer ,true);
		// (*texture)[RIGHT] = load_media_texture("right.bmp",*renderer ,true);
		// (*texture)[LEFT] = load_media_texture("left.bmp",*renderer ,true);
		//&& !((*texture)[UP] == NULL) && !((*texture)[DOWN] == NULL) && !((*texture)[RIGHT] == NULL) && !((*texture)[LEFT] == NULL)
		return !(*window == NULL) && !(*window_surface == NULL) ;
	}

	SDL_Window *init_window(int screen_height,int screen_width)
	{
		SDL_Window *window;

		if ((window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN)) == NULL)
		{
			std::cerr << "Window could not be created. SDL_Error: " << SDL_GetError() << '\n';
			return NULL;
		}
		return window;
	}

	SDL_Surface *init_window_surface(SDL_Window *window)
	{
		SDL_Surface *surface;

		if ((surface = SDL_GetWindowSurface(window)) == NULL)
		{
			std::cerr << "Window surface could not be created. SDL_Error: " << SDL_GetError() << '\n';
			return NULL;
		}
		return surface;
	}

	void close(SDL_Window *window, SDL_Renderer *renderer/*,std::vector<SDL_Texture *> texture*/)
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
};
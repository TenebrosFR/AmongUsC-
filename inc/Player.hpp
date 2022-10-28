#include "load_media.hpp"
#include "utils.h"
#include "Props.hpp"
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <string> 
#include "Props.hpp"

class Player : Props
{
    public :
        SDL_Texture* idle;
        std::vector<SDL_Texture *> movement;
        direction currentDirection = RIGHT;

        Player(SDL_Renderer *renderer);

        Player();	
        
        void UpdateTexture() override ;
};
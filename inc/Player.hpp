#pragma once
#include "utils.h"
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <string> 
#include "Props.hpp"

class Player : Props
{
    public :
        TextureWithSize idle;
        std::vector<TextureWithSize> movement;
        direction currentDirection = RIGHT;
        Player(SDL_Renderer *renderer);

        Player();	
        
        void UpdateTexture() override ;

        void test();
};
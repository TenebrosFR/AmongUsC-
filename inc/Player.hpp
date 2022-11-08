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
        Position currentPosition = Position(0,0);
        int speed;
        int currentSprite;
        direction currentDirection = RIGHT;
        Player(SDL_Renderer *renderer);

        Player();	
        
        
        TextureWithSize GetCurrentTexture();

        void UpdatePosition(direction dir);
};
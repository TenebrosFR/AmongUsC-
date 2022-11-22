#pragma once
#include "utils.h"
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <string> 
#include "Props.hpp"

class Map : Props
{
    public :
        TextureWithSize img;
        Position currentPosition = Position(0,0);
        double speed;
        Map(SDL_Renderer *renderer);        
        Map();
        ~Map();
        TextureWithSize GetCurrentTexture();

        void UpdatePosition(DoubleDirection givenDirection,double deltaSpeed,Position cameraPosition);
};
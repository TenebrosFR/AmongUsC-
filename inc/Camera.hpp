#pragma once
#include "utils.h"
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <string> 
#include "Props.hpp"

class Camera : Props
{
    public :
        TextureWithSize img;
        Position currentPosition = Position(0,0);
        double speed;
        Camera(SDL_Renderer *renderer);        
        Camera();
        ~Camera();
        TextureWithSize GetCurrentTexture();

        void UpdatePosition(DoubleDirection givenDirection,double deltaSpeed,Position cameraPosition);
};
#pragma once
#include "Initializer.hpp"
#include "Data.hpp"
#include <SDL.h>
#include <SDL_image.h>

class GameManager : Data,Initializer
{
public:
    

    GameManager();

    void whilePlaying();

    void updateWindow(SDL_Rect rect);
    
    int Start();
};
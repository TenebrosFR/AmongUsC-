#pragma once
#include "Initializer.hpp"
#include "Data.hpp"
#include <SDL.h>
#include <SDL_image.h>

class GameManager : Data,Initializer
{
    private:
        bool isFullscreen=false;

    public:
        GameManager();

        void whilePlaying();

        void InputManager(const Uint8* state);

        void updateWindow(SDL_Rect rect);
        
        int Start();
};
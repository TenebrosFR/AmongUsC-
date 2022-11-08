#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "utils.h"

class Text{
    private:
        SDL_Texture *texture;
        SDL_Rect rect;

    public:
        Text(const char* _sentence, int size, int x, int y, SDL_Renderer *&renderer);
        void UpdateText(SDL_Renderer *&renderer);
        Text(){};
};
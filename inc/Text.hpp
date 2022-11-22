#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "utils.h"

class Text{
    private:
        SDL_Texture *texture;

    public:
        Text(const char* _sentence, int size, int x, int y, SDL_Renderer *&renderer, SDL_Rect rect);
        inline SDL_Texture* getTexture(){return texture;};
};
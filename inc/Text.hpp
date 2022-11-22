#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "utils.h"

class Text{
    private:
        SDL_Texture *texture;
        SDL_Rect rectText;
        const char* sentence;
        int x, y,size;
        SDL_Color color;

    public:
        Text();
        Text(const char* _sentence, int _size, int _x, int _y, SDL_Renderer *&renderer, SDL_Color _color);
        void ChangeText(const char* _sentence, int _x, int _y, SDL_Renderer *&renderer, SDL_Color _color);

        inline SDL_Texture* getTexture(){return texture;};
        inline SDL_Rect* getRect(){return &rectText;};
        inline const char* getText(){return sentence;};
        inline int getX(){return x;};
        inline int getY(){return y;};
        inline SDL_Color getColor(){return color;};
};
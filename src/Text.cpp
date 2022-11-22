#include "Text.hpp"

Text::Text(const char* _sentence, int _size, int _x, int _y, SDL_Renderer *&renderer, SDL_Color _color){
    size=_size;
    ChangeText(_sentence,_x,_y, renderer,_color);
}

Text::Text(){};

void Text::ChangeText(const char* _sentence, int _x, int _y, SDL_Renderer *&renderer, SDL_Color _color){
    color = _color;
    x=_x;
    y=_y;
    sentence = _sentence;
    TTF_Init();
    TTF_Font * font = TTF_OpenFont("./Assets/font/zenzai.ttf", size);
    int text_width;
    int text_height;
    SDL_Surface *surface = TTF_RenderText_Solid(font,sentence, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    text_height = surface->h;
    text_width = surface->w;
    rectText = {x, y,text_width,text_height};
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
};
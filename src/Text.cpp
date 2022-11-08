#include "Text.hpp"

Text::Text(const char* _sentence, int size, int x, int y, SDL_Renderer *&renderer){
    TTF_Init();
    TTF_Font * font = TTF_OpenFont("arial.ttf", size);
    int text_width;
    int text_height;
    SDL_Surface *surface = TTF_RenderText_Solid(font," _sentence", {255, 255, 255});
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    int textW, textH;
    SDL_QueryTexture(texture, NULL, NULL, &textW, &textH);
    rect= {x, y,150,150};
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
}

void Text::UpdateText(SDL_Renderer *&renderer){
    SDL_RenderCopyEx(renderer,texture,NULL,&rect,0,NULL,SDL_FLIP_NONE);
}
#pragma once
#include <vector>
#include "load_media.hpp"
enum direction
{
    UP,
    DOWN,
    RIGHT,
    LEFT,
    SPACE
};
//TEXTURES
typedef std::pair<int,int> Dimension;
typedef std::pair<SDL_Texture*,Dimension> TextureWithSize;
int* getTextureWidth(TextureWithSize *texture){
    return &( (*texture).second.first );
};
int* getTextureHeight(TextureWithSize *texture){
    return &( (*texture).second.second );
};
TextureWithSize CreateTextureWithSizeFromMedia(std::string file_name, SDL_Renderer *renderer, bool color_key){
    TextureWithSize frame;
    frame.first = load_media_texture(file_name,renderer,true);
    SDL_QueryTexture(frame.first,NULL,NULL,getTextureWidth(&frame),getTextureHeight(&frame));
    return frame;
}
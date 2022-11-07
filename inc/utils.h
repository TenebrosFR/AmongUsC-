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

//FONCTION
int* getTextureWidth(TextureWithSize *texture);
int* getTextureHeight(TextureWithSize *texture);
TextureWithSize CreateTextureWithSizeFromMedia(std::string file_name, SDL_Renderer *renderer, bool color_key);
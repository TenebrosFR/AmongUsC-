#pragma once
#include <vector>
#include <utility>
#include "load_media.hpp"
#define X_COORDINATE first
#define Y_COORDINATE second
#define TEXTURE_WIDTH second.first
#define TEXTURE_HEIGHT second.second

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
TextureWithSize CreateTextureWithSizeFromMedia(std::string file_name, SDL_Renderer *renderer, bool color_key);

//
typedef std::pair<int,int> Position;

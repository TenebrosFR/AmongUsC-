#pragma once
#include <vector>
#include <utility>
#include "load_media.hpp"
#define X_COORDINATE first
#define Y_COORDINATE second
#define VERTICAL_DIRECTION first
#define HORIZONTAL_DIRECTION second
#define TEXTURE_WIDTH second.first
#define TEXTURE_HEIGHT second.second

enum direction
{
    UP,
    DOWN,
    RIGHT,
    LEFT,
    SPACE,
    NONE
};
//TEXTURES
typedef std::pair<int,int> Dimension;
typedef std::pair<SDL_Texture*,Dimension> TextureWithSize;
typedef std::pair<direction, direction> DoubleDirection;
//FONCTION
TextureWithSize CreateTextureWithSizeFromMedia(std::string file_name, SDL_Renderer *renderer, bool color_key);

//
typedef std::pair<int,int> Position;

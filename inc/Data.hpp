#pragma once
#include <vector>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Player.hpp"

class Data
{
    public :
        //FPS
        Uint64 fps_lasttime = SDL_GetTicks64();
        Uint64 fps_current;
        Uint64 fps_frames = 0;
        //
        int screen_width;
        int screen_height;
        SDL_Rect rect ;
        //sdl
        SDL_Window *window = NULL;
        // std::vector<SDL_Texture *> texture;
        // SDL_Texture *texture_to_render = NULL;
        SDL_Surface *window_surface = NULL;
        SDL_Renderer *renderer = NULL;
        //events
        SDL_Event e;
        //elements
        int offset = 0;
        Player CurrentPlayer ;
        direction newDirection;
        bool quit = false;
        int speed = 100;
        Uint64 time;
        Uint64 clock;
        double shift;
        //constructor
        Data();
};
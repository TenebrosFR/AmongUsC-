#pragma once
#include <vector>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Player.hpp"
#include <chrono>
// #include "Text.hpp"

class Data
{
    public :
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
        //player
        SDL_RendererFlip rotate ;
        Player CurrentPlayer ;
        DoubleDirection newDirection;
        bool quit = false;
        int speed = 100;
        //Time
        //Uint64 time;
        double shift;
        //Uint64 clock;
        std::chrono::time_point<std::chrono::high_resolution_clock> clock_chrono;
        //Text
        // Text text;
        // SDL_Rect rectText;
        //constructor
        Data();
};
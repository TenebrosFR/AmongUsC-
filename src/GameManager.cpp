#include "GameManager.hpp"
#include "Initializer.hpp"
#include "load_media.hpp"
#include "Data.hpp"
#include <vector>
#include <string>


GameManager::GameManager(){
    //If No error to load sdl
    if (!init_SDL(&window/*,&texture*/,&window_surface,&renderer,screen_height,screen_width)) return;
    //create current player
    Players[0] = Player(renderer);
    //start game
    Start();
}

void GameManager::whilePlaying(){
    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_q:
                    xCoordinate--;
                    break;
                case SDLK_d:
                    xCoordinate++;
                    break;
                case SDLK_s:
                    yCoordinate++;
                    break;
                case SDLK_z:
                    yCoordinate--;
                    break;
                }
            }
            // if(texture_to_render!=NULL)
            updateWindow(rect);
        }
    }
}
void GameManager::updateWindow(SDL_Rect rect){
    //clear screen
    SDL_RenderClear(renderer);
    //render sprite SDL_RenderCopyEx(renderer,texture_to_render,NULL,&rect,NULL,NULL,SDL_FLIP_NONE);
    for (Player CurrentPlayer : Players) {
        if(CurrentPlayer.idle==NULL) continue;
        rect = {xCoordinate, yCoordinate, screen_width/(*(CurrentPlayer.idle)->w), screen_height};
        SDL_RenderCopyEx(renderer,Players->idle,NULL,&rect,0,NULL,SDL_FLIP_NONE);
    }
    //update new frame
    SDL_RenderPresent(renderer);
}
int GameManager::Start()
{       
    whilePlaying();
    close(window, NULL/*,texture*/);
    return 0;
}
#include "GameManager.hpp"
#include "GameManager.hpp"
#define FPS_INTERVAL 1 //seconds.

GameManager::GameManager(){
    //If No error to load sdl
    if (!init_SDL(&window,&window_surface,&renderer,&screen_height,&screen_width)) return;
    //create current player
    Players[0] = Player(renderer);
    //start game
    Start();
}

void GameManager::whilePlaying(){
    while (!quit)
    {	
        //Calcul FPS
        if (fps_lasttime < SDL_GetTicks64() - FPS_INTERVAL*1000)
            {
                fps_lasttime = SDL_GetTicks64();
                fps_current = fps_frames;
                fps_frames = 0;
            }
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
        }
        std::string sFps = std::to_string(fps_current);
        SDL_SetWindowTitle(window,sFps.c_str());
        updateWindow(rect);
            fps_frames++;
    }
}
void GameManager::updateWindow(SDL_Rect rect){
    //clear screen
    SDL_RenderClear(renderer);
    //render sprite SDL_RenderCopyEx(renderer,texture_to_render,NULL,&rect,NULL,NULL,SDL_FLIP_NONE);
    for (Player CurrentPlayer : Players) {
        if(CurrentPlayer.idle.first==NULL) continue;
        rect = {xCoordinate, yCoordinate, screen_width / *(getTextureWidth(&CurrentPlayer.idle)), screen_width / *(getTextureHeight(&CurrentPlayer.idle))};
        SDL_RenderCopyEx(renderer,CurrentPlayer.idle.first,NULL,&rect,0,NULL,SDL_FLIP_NONE);
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
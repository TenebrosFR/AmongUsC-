#include "GameManager.hpp"
#define FPS_INTERVAL 1 //seconds.

GameManager::GameManager(){
    std::cout<<SDL_GetError()<<std::endl;
    //If No error to load sdl
    if (!init_SDL(&window,&window_surface,&renderer,&screen_height,&screen_width)) return;

    //set l'icon de la page
    SDL_Surface* icon = IMG_Load("./Assets/img/icon.png");
    SDL_SetWindowIcon(window,icon);

    //create current player
    CurrentPlayer = Player(renderer);
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
                    newDirection = LEFT;
                    break;
                case SDLK_d:
                    xCoordinate++;
                    newDirection = RIGHT;
                    break;
                case SDLK_s:
                    yCoordinate++;
                    break;
                case SDLK_z:
                    yCoordinate--;
                    break;
                case SDLK_f:
                    (!isFullscreen?SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN):SDL_SetWindowFullscreen(window, 0));
                    isFullscreen=!isFullscreen;
                    break;
                }
            }
        }
        std::string sFps = std::to_string(fps_current);
        SDL_SetWindowTitle(window,("FPS = "+sFps).c_str());
        updateWindow(rect);
            fps_frames++;
    }
}
void GameManager::updateWindow(SDL_Rect rect){
    //clear screen
    SDL_RenderClear(renderer);
    CurrentPlayer.UpdatePosition(newDirection);
    rect = {CurrentPlayer.currentPosition.X_COORDINATE, CurrentPlayer.currentPosition.Y_COORDINATE, screen_width / *(getTextureWidth(&CurrentPlayer.idle))/*(CurrentPlayer.GetCurrentTexture().TEXTURE_WIDTH)*/, screen_width / (CurrentPlayer.GetCurrentTexture().TEXTURE_HEIGHT)};
    /*SDL_RenderCopyEx(renderer,CurrentPlayer.GetCurrentTexture().first,NULL,&rect,0,NULL,(newDirection == LEFT) ? SDL_FLIP_VERTICAL : SDL_FLIP_NONE);*/
    
    //update new frame
    SDL_RenderPresent(renderer);
}
int GameManager::Start()
{       
    whilePlaying();
    close(window, NULL/*,texture*/);
    return 0;
}
#include "GameManager.hpp"
#define FPS_INTERVAL 1 // seconds.

GameManager::GameManager()
{
    // If No error to load sdl
    if (!init_SDL(&window, &window_surface, &renderer, &screen_height, &screen_width))
        return;

    // set l'icon de la page
    SDL_Surface *icon = IMG_Load("./Assets/img/icon.png");
    SDL_SetWindowIcon(window, icon);
    // create current player
    CurrentPlayer = Player(renderer);
    MyMap = Map(renderer);
    //create text
    SDL_Color color{167, 66, 211, 255};
    text=Text("Hello world",24,screen_width-250,50,renderer, color);
    // start game
    Start();
}

void GameManager::whilePlaying()
{
    while (!quit)
    {
        // time
        // time = SDL_GetTicks64() - clock;
        

        // clock = SDL_GetTicks64();
        
        std::chrono::time_point<std::chrono::high_resolution_clock> current_time;
        current_time= std::chrono::high_resolution_clock::now();
        double time = std::chrono::duration_cast<std::chrono::nanoseconds>(current_time-clock_chrono).count() / 1000000.;
        clock_chrono = current_time;

        shift = (double)CurrentPlayer.speed *time;
        newDirection = std::make_pair(NONE, NONE);

        // events
        SDL_PumpEvents();
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        InputManager(state);
        //
        std::string sFps = std::to_string(1000./time);
        SDL_SetWindowTitle(window, ("FPS = " + sFps).c_str());

        text.ChangeText(("FPS = " + sFps).c_str(),text.getX(),text.getY(),renderer,text.getColor());
        static Uint64 clock = SDL_GetTicks64(); 
        
        updateWindow(rect);

        
    }
};
void GameManager::InputManager(const Uint8 *state)
{
    if (state[SDL_SCANCODE_ESCAPE])
        quit = true;
    // Choose horizontal direction
    if (state[SDL_SCANCODE_A])
        newDirection.HORIZONTAL_DIRECTION = LEFT;
    else if (state[SDL_SCANCODE_D])
        newDirection.HORIZONTAL_DIRECTION = RIGHT;
    // Choose vertical direction
    if (state[SDL_SCANCODE_S])
        newDirection.VERTICAL_DIRECTION = UP;
    else if (state[SDL_SCANCODE_W])
        newDirection.VERTICAL_DIRECTION = DOWN;
    // fullscreen
    if (state[SDL_SCANCODE_F])
    {
        (!isFullscreen ? SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN) : SDL_SetWindowFullscreen(window, 0));
        isFullscreen = !isFullscreen;
    }
};
void GameManager::updateWindow(SDL_Rect rect)
{
    // clear screen
    SDL_RenderClear(renderer);
    //Update Camera Position
    MyCam.UpdatePosition(newDirection,shift,Position(0,0));
    CurrentPlayer.UpdatePosition(newDirection,shift,MyCam.currentPosition);
    //map
    rect = {(int)(MyMap.currentPosition.X_COORDINATE-MyCam.currentPosition.X_COORDINATE), (int)(MyMap.currentPosition.Y_COORDINATE-MyCam.currentPosition.Y_COORDINATE), (MyMap.GetCurrentTexture().TEXTURE_WIDTH), (MyMap.GetCurrentTexture().TEXTURE_HEIGHT)};
    SDL_RenderCopyEx(renderer, MyMap.img.first, NULL, &rect, 0, NULL, SDL_FLIP_NONE);
    //player
    rect = { (screen_width/2)-CurrentPlayer.GetCurrentTexture().TEXTURE_WIDTH,(screen_height/2)-CurrentPlayer.GetCurrentTexture().TEXTURE_HEIGHT, (CurrentPlayer.GetCurrentTexture().TEXTURE_WIDTH)*2, (CurrentPlayer.GetCurrentTexture().TEXTURE_HEIGHT)*2};
    SDL_RenderCopyEx(renderer, CurrentPlayer.GetCurrentTexture().first, NULL, &rect, 0, NULL, rotate);
    if(newDirection.HORIZONTAL_DIRECTION != NONE)   rotate =  newDirection.HORIZONTAL_DIRECTION == LEFT ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    SDL_RenderCopyEx(renderer, text.getTexture(), NULL, text.getRect(), 0, NULL, SDL_FLIP_NONE);
    // update new frame
    SDL_RenderPresent(renderer);
}
int GameManager::Start()
{
    whilePlaying();
    close(window, NULL /*,texture*/);
    return 0;
}